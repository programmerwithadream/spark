FROM ubuntu:22.04 AS build

WORKDIR /root

# Update apt dependencies and install required dependencies
ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update \
    && apt-get upgrade -y \
    && apt-get install -y openjdk-8-jdk scala curl

# Build the custom Apache Spark
COPY . .
ENV MAVEN_OPTS="-Xss64m -Xmx2g -XX:ReservedCodeCacheSize=1g"
RUN ./dev/make-distribution.sh --name custom-spark

FROM ubuntu:22.04

COPY --from=build /root/dist /opt/spark

CMD ["tail", "-f", "/dev/null"]