public class HelloJNI {  // Save as HelloJNI.java
   static {
      System.loadLibrary("hello"); // Load native library hello.dll (Windows) or libhello.so (Unixes)
                                   //  at runtime
                                   // This library contains a native method called sayHello()
   }
 
   // Declare an instance native method sayHello() which receives no parameter and returns void
   private native void sayHello();
 
   // private native double[] filterGreater(double threshold, double[] values);

   // private native float test(float threshold, float values);

   // private native int[] addArray(int[] a, int[] b);

   // private native boolean[] maskGreater(int threshold, int[] values);

   // private native int[] customAddArray(int[] a, int[] b);

   // Test Driver
   // public static void main(String[] args) {
   //    //new HelloJNI().sayHello();  // Create an instance and invoke the native method

   //    int num = 150;
   //    double threshold = 50;
   //    double[] values = new double[num];

   //    for (int i = 0; i < num; i++) {
   //       values[i] = i;
   //    }

   //    double[] result = new HelloJNI().filterGreater(threshold, values);
   //    float f = new HelloJNI().test((float)1.0f, (float)6.3f);
   //    System.out.println(f);

   //    // System.out.println("filtered values are: ");

   //    // for (int i = 0; i < result.length; i++) {
   //    //    System.out.println(result[i]);
   //    // }

   //    // int length = 100;
      
   //    // int[] a = new int[length];
   //    // int[] b = new int[length];

   //    // for (int i = 0; i < length; i++) {
   //    //    a[i]= i;
   //    //    b[i] = i;
   //    // }

   //    // int[] result = new HelloJNI().customAddArray(a, b);

   //    // for (int i = 0; i < length; i++) {
   //    //    System.out.println(result[i]); 
   //    // }


   //    //mask test
   //    // int length = 100;
   //    // int threshold = 50;

   //    // int[] a = new int[length];

   //    // for (int i = 0; i < length; i++) {
   //    //    a[i]= i;
   //    // }

   //    // boolean[] result = new HelloJNI().maskGreater(threshold, a);

   //    // for (int i = 0; i < length; i++) {
   //    //    System.out.println(result[i]);
   //    // }


   // }
}