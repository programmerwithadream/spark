// Save as "HelloJNI.cpp"
#include <jni.h>       // JNI header provided by JDK
#include <iostream>    // C++ standard IO header
#include "HelloJNI.h"  // Generated
// #include <vector>

// #include <sycl/sycl.hpp>
// #include <array>
// #include <string>
// #if FPGA || FPGA_EMULATOR
// #include <sycl/ext/intel/fpga_extensions.hpp>
// #endif


// using namespace sycl;

// Create an exception handler for asynchronous SYCL exceptions
// static auto exception_handler = [](sycl::exception_list e_list) {
//   for (std::exception_ptr const &e : e_list) {
//     try {
//       std::rethrow_exception(e);
//     }
//     catch (std::exception const &e) {
// #if _DEBUG
//       std::cout << "Failure" << std::endl;
// #endif
//       std::terminate();
//     }
//   }
// };

// Implementation of the native method sayHello()
JNIEXPORT void JNICALL Java_HelloJNI_sayHello(JNIEnv *env, jobject thisObj) {
	std::cout << "Hello World from C++!" << std::endl;
   return;
}


// JNIEXPORT jdoubleArray JNICALL Java_HelloJNI_filterGreater(JNIEnv *env, jobject thisObj, jdouble threshold, jdoubleArray values) {
//    jsize length = env->GetArrayLength(values);

//    std::cout << length;

//    jdouble *Cvalues = env->GetDoubleArrayElements(values, NULL);
//    if (NULL == Cvalues) return NULL;

//    std::vector<jdouble> resultVector;

//    for (int i = 0; i < length; i++) {
//       if (Cvalues[i] > threshold) {
//          resultVector.push_back(Cvalues[i]);
//       }
//    }

//    jdouble* Cresults = &resultVector[0];

//    jdoubleArray jResults = env->NewDoubleArray(resultVector.size());
//    if (NULL == jResults) return NULL;
//    env->SetDoubleArrayRegion(jResults, 0, resultVector.size(), Cresults);

//    std::cout << resultVector.size();

//    return jResults;
// }
// JNIEXPORT jfloat JNICALL Java_HelloJNI_test(JNIEnv *env, jobject thisObj, jfloat threshold, jfloat values) {
//    float f = values + 1.0f;
//    printf("%f\n", f);
//    return f;
// }

// JNIEXPORT jintArray JNICALL Java_HelloJNI_addArray(JNIEnv *env, jobject thisObj, jintArray ja, jintArray jb) {

//    #if FPGA_EMULATOR
//   // Intel extension: FPGA emulator selector on systems without FPGA card.
//   ext::intel::fpga_emulator_selector d_selector;
// #elif FPGA
//   // Intel extension: FPGA selector on systems with FPGA card.
//   ext::intel::fpga_selector d_selector;
// #else
//   // The default device selector will select the most performant device.
//   auto d_selector{default_selector_v};
// #endif




//    jsize lengthA = env->GetArrayLength(ja);
//    jsize lengthB = env->GetArrayLength(jb);

//    // jint *aArray = env->GetIntArrayElements(a, NULL);
//    // jint *bArray = env->GetIntArrayElements(b, NULL);

//    if (lengthA != lengthB) {
//       //throw exception();
//    }

//    if (lengthA == 0) {
//       return NULL;
//    }




//    jintArray results = env->NewIntArray(lengthA);


//     queue q(d_selector, exception_handler);

//     // Print out the device information used for the kernel code.
//     std::cout << "Running on device: "
//               << q.get_device().get_info<info::device::name>() << "\n";
//     std::cout << "Array size: " << lengthA << "\n";

//     // Create arrays with "array_size" to store input and output data. Allocate
//     // unified shared memory so that both CPU and device can access them.
//     std::cout << "malloc\n";
//     int *a =            malloc_shared<int>(lengthA, q);
//     int *b =            malloc_shared<int>(lengthA, q);
//     int *sum_parallel = malloc_shared<int>(lengthA, q);


//     std::cout << "check nullptr\n";
//     if ((a == nullptr) || (b == nullptr) ||
//         (sum_parallel == nullptr)) {
//       if (a != nullptr) free(a, q);
//       if (b != nullptr) free(b, q);
//       if (sum_parallel != nullptr) free(sum_parallel, q);

//       std::cout << "Shared memory allocation failure.\n";
//     }

//     // Initialize input arrays with values from 0 to array_size - 1
//     std::cout << "GetInt\n";
//     jint o_a[lengthA];
//     jint o_b[lengthA];
//     env->GetIntArrayRegion(ja, 0, lengthA, o_a);
//     env->GetIntArrayRegion(jb, 0, lengthA, o_b);

    
//    // a = o_a;
//    // b = o_b;
//     for (int i=0; i<lengthA; i++) {
//       a[i] = static_cast<int>(o_a[i]);
//       b[i] = static_cast<int>(o_b[i]);
//     }
       


//     std::cout << "before parallel_for\n";
//    auto e = q.parallel_for(range<1>(lengthA), [=](auto i){sum_parallel[i] = a[i] + b[i];});
//    e.wait();
//     std::cout << "after parallel_for\n";

//    jint j_sum[lengthA];
//    for (int i=0; i<lengthA; i++) {
//       j_sum[i] = static_cast<jint>(sum_parallel[i]);
//    }
//    env->SetIntArrayRegion(results, 0, lengthA, j_sum);
//     std::cout << "SetInt\n";


//    return results;






//    // jint sum[lengthA];

//    // for (int i = 0; i < lengthA; i++) {
//    //    sum[i] = aArray[i] + bArray[i];
//    // } 

//    // jintArray results = env->NewIntArray(sizeof(sum));
//    // env->SetIntArrayRegion(results, 0, sizeof(sum), sum);

//    // return results;
// }

// // JNIEXPORT jboolArray JNICALL Java_HelloJNI_maskGreater(JNIEnv *env, jobject thisObj, jintArray jThreshold, jintArray ja) {
// //    #if FPGA_EMULATOR
// //   // Intel extension: FPGA emulator selector on systems without FPGA card.
// //   ext::intel::fpga_emulator_selector d_selector;
// //    #elif FPGA
// //   // Intel extension: FPGA selector on systems with FPGA card.
// //   ext::intel::fpga_selector d_selector;
// //    #else
// //   // The default device selector will select the most performant device.
// //   auto d_selector{default_selector_v};
// //    #endif

// //    jsize lengthA = env->GetArrayLength(ja);

// //    queue q(d_selector, exception_handler);

// //    // Print out the device information used for the kernel code.
// //    std::cout << "Running on device: "
// //              << q.get_device().get_info<info::device::name>() << "\n";
// //    std::cout << "Array size: " << lengthA << "\n";

// //    // Create arrays with "array_size" to store input and output data. Allocate
// //    // unified shared memory so that both CPU and device can access them.
// //    std::cout << "malloc\n";
// //    int *threshold = malloc_shared<int>(1, q);
// //    int *a = malloc_shared<int>(lengthA, q);
// //    bool *mask_parallel = malloc_shared<bool>(lengthA, q);

// //    jint o_t[1];
// //    jint 0_a[lengthA];
// //    env->GetIntArrayRegion(jThreshold, 0, 1, o_t);
// //    env->GetIntArrayRegion(ja, 0, lengthA, o_a);

// //    threshold[0] = o_t[0];

// //    for (int i=0; i<lengthA; i++) {
// //       a[i] = static_cast<int>(o_a[i]);
// //    }

// //    auto e = q.parallel_for(range<1>(lengthA), [=](auto i){mask_parallel[i] = a[i] > threshold[0] ? true : false;});
// //    e.wait();

// //    jbool j_mask[lengthA];
// //    for (int i=0; i<lengthA; i++) {
// //       j_mask[i] = static_cast<jbool>(mask_parallel[i]);
// //    }

// //    jboolArray results = env->NewBoolArray(lengthA);

// //    env->SetIntArrayRegion(results, 0, lengthA, j_mask);

// //    return results;
// // }




// int customAdd(int a, int b) {
//    int c = a + b;
//    return c;
// }

// struct customInt{
//    int myNum;
// };

// JNIEXPORT jintArray JNICALL Java_HelloJNI_customAddArray(JNIEnv *env, jobject thisObj, jintArray ja, jintArray jb) {

//    #if FPGA_EMULATOR
//   // Intel extension: FPGA emulator selector on systems without FPGA card.
//   ext::intel::fpga_emulator_selector d_selector;
// #elif FPGA
//   // Intel extension: FPGA selector on systems with FPGA card.
//   ext::intel::fpga_selector d_selector;
// #else
//   // The default device selector will select the most performant device.
//   auto d_selector{default_selector_v};
// #endif




//    jsize lengthA = env->GetArrayLength(ja);
//    jsize lengthB = env->GetArrayLength(jb);

//    // jint *aArray = env->GetIntArrayElements(a, NULL);
//    // jint *bArray = env->GetIntArrayElements(b, NULL);

//    if (lengthA != lengthB) {
//       //throw exception();
//    }

//    if (lengthA == 0) {
//       return NULL;
//    }




//    jintArray results = env->NewIntArray(lengthA);


//     queue q(d_selector, exception_handler);

//     // Print out the device information used for the kernel code.
//     std::cout << "Running on device: "
//               << q.get_device().get_info<info::device::name>() << "\n";
//     std::cout << "Array size: " << lengthA << "\n";

//     // Create arrays with "array_size" to store input and output data. Allocate
//     // unified shared memory so that both CPU and device can access them.
//     std::cout << "malloc\n";
//     customInt *a =            malloc_shared<customInt>(lengthA, q);
//     customInt *b =            malloc_shared<customInt>(lengthA, q);
//     int *sum_parallel = malloc_shared<int>(lengthA, q);


//     std::cout << "check nullptr\n";
//     if ((a == nullptr) || (b == nullptr) ||
//         (sum_parallel == nullptr)) {
//       if (a != nullptr) free(a, q);
//       if (b != nullptr) free(b, q);
//       if (sum_parallel != nullptr) free(sum_parallel, q);

//       std::cout << "Shared memory allocation failure.\n";
//     }

//     // Initialize input arrays with values from 0 to array_size - 1
//     std::cout << "GetInt\n";
//     jint o_a[lengthA];
//     jint o_b[lengthA];
//     env->GetIntArrayRegion(ja, 0, lengthA, o_a);
//     env->GetIntArrayRegion(jb, 0, lengthA, o_b);

    
//    // a = o_a;
//    // b = o_b;
//     for (int i=0; i<lengthA; i++) {
//       a[i].myNum = static_cast<int>(o_a[i]);
//       b[i].myNum = static_cast<int>(o_b[i]);
//     }
       

//     std::cout << "before parallel_for\n";
//    auto e = q.parallel_for(range<1>(lengthA), [=](auto i){
//       customInt custom_c;

//       custom_c.myNum = customAdd(a[i].myNum, b[i].myNum);

//       sum_parallel[i] = custom_c.myNum;
//       });
//    e.wait();
//     std::cout << "after parallel_for\n";

//    jint j_sum[lengthA];
//    for (int i=0; i<lengthA; i++) {
//       j_sum[i] = static_cast<jint>(sum_parallel[i]);
//    }
//    env->SetIntArrayRegion(results, 0, lengthA, j_sum);
//     std::cout << "SetInt\n";


//    return results;
// }


// // JNIEXPORT jintArray JNICALL Java_HelloJNI_filterGreater(JNIEnv *env, jobject thisObj, jintArray jThreshold, jintArray ja) {
// //    #if FPGA_EMULATOR
// //   // Intel extension: FPGA emulator selector on systems without FPGA card.
// //   ext::intel::fpga_emulator_selector d_selector;
// //    #elif FPGA
// //   // Intel extension: FPGA selector on systems with FPGA card.
// //   ext::intel::fpga_selector d_selector;
// //    #else
// //   // The default device selector will select the most performant device.
// //   auto d_selector{default_selector_v};
// //    #endif

// //    jsize lengthA = env->GetArrayLength(ja);

// //    queue q(d_selector, exception_handler);

// //    // Print out the device information used for the kernel code.
// //    std::cout << "Running on device: "
// //              << q.get_device().get_info<info::device::name>() << "\n";
// //    std::cout << "Array size: " << lengthA << "\n";

// //    // Create arrays with "array_size" to store input and output data. Allocate
// //    // unified shared memory so that both CPU and device can access them.
// //    std::cout << "malloc\n";
// //    int *threshold = malloc_shared<int>(1, q);
// //    int *a = malloc_shared<int>(lengthA, q);
   

// //    jint o_t[1];
// //    jint o_a[lengthA];
// //    env->GetIntArrayRegion(jThreshold, 0, 1, o_t);
// //    env->GetIntArrayRegion(ja, 0, lengthA, o_a);

// //    threshold[0] = o_t[0];

// //    for (int i=0; i<lengthA; i++) {
// //       a[i] = static_cast<int>(o_a[i]);
// //    }

// //    std::concurrent_vector<int> v(q);

// //    auto e = q.parallel_for(range<1>(lengthA), [=](auto i){
// //       if (a[i] > threshold[0]) {
// //          v.push_back(a[i]);
// //       }
// //    });
// //    e.wait();

// //    jint j_result[v.size()];
// //    for (int i=0; i<v.size(); i++) {
// //       j_result[i] = static_cast<jint>(v[i]);
// //    }

// //    jintArray results = env->NewIntArray(v.size());

// //    env->SetIntArrayRegion(results, 0, v.size(), j_result);

// //    return results;
// // }


// JNIEXPORT jdoubleArray JNICALL Java_HelloJNI_filterGreater(JNIEnv *env, jobject thisObj, jdouble threshold, jdoubleArray values) {
//    jsize length = env->GetArrayLength(values);

//    std::cout << length;

//    jdouble *Cvalues = env->GetDoubleArrayElements(values, NULL);
//    if (NULL == Cvalues) return NULL;

//    std::vector<jdouble> resultVector;

//    // Calculate the number of elements that satisfy the threshold condition
//    size_t count = 0;
//    for (int i = 0; i < length; i++) {
//       if (Cvalues[i] > threshold) {
//          count++;
//       }
//    }

//    // Allocate a buffer to store the results
//    std::unique_ptr<jdouble[]> resultBuffer(new jdouble[count]);

//    // Store the results in the buffer
//    size_t index = 0;
//    for (int i = 0; i < length; i++) {
//       if (Cvalues[i] > threshold) {
//          resultBuffer[index++] = Cvalues[i];
//       }
//    }

//    jdoubleArray jResults = env->NewDoubleArray(count);
//    if (NULL == jResults) return NULL;
//    env->SetDoubleArrayRegion(jResults, 0, count, resultBuffer.get());

//    std::cout << count;

//    return jResults;
// }