import java.math.*;
import java.util.Arrays;
import java.io.File;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.IOException;
import java.net.Socket;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

import java.io.FileInputStream;

public class Main {
    public static void main(String[] args) {
        String sourceDirName = "src";
        String mainFileName = "Main.java";
        String mainFilePath = sourceDirName + File.separator + mainFileName ;
        File mainFile = new File ( sourceDirName , mainFileName );
        System.out.println(mainFile);

        try ( InputStream inputStream = Main.class.getResourceAsStream ("Main.class")) {
            int read = inputStream.read();
        while ( read >= 0) {
            System.out.printf ("%02x", read );
                read = inputStream.read();
            }
        } catch (IOException e) {
            System.out.println(e);
        }

        try ( Socket socket = new Socket ("ya.ru", 80)) {
            OutputStream outputStream = socket.getOutputStream();
            outputStream.write(" GET / HTTP /1.0\r\n\r\n".getBytes());
            outputStream.flush();
            InputStream inputStream = socket.getInputStream();
            int read = inputStream.read();
        while ( read >= 0) {
            System.out.print((char) read);
                read = inputStream.read();
            }
        } catch (IOException e) {
            System.out.println(e);
        }


        Path rn_demo = Paths.get("./HelloWorld.java");
        //using NIO.2 unbuffered stream
        int n;
        try (InputStream in = new FileInputStream(rn_demo.toFile())) {
            while ((n = in.read()) != -1) {
                System.out.print((char) n);
            }
        } catch (IOException e) {
            System.err.println(e);
        }

    }
}

// public class Main {
// public static void main(String[] args) {
//         System.out.println(getCallerClassAndMethodName());
//         anotherMethod();
//     }

//     private static void anotherMethod() {
//         System.out.println(getCallerClassAndMethodName());
//     }

//     public static String getCallerClassAndMethodName() {
//         StackTraceElement[] stackTraceElements = new Exception().getStackTrace();

//         if (stackTraceElements.length > 2) {
//             StackTraceElement callerElement = stackTraceElements[2];
//             return callerElement.getClassName() + "#" + callerElement.getMethodName();
//         }
//         return null;
//     }
// }


// public static BigInteger Factorial(int n) {
//     // BigInteger one = BigInteger.valueOf(1);
//     // // BigInteger i = BigInteger.valueOf(n);
//     if (n == 1) {
//         return BigInteger.valueOf(1);
//     }
//     else {
//         return BigInteger.valueOf(n).multiply(Factorial(n-1));
//     }
// }

    // public static void main(String[] args) {
//         System.out.println(getCallerClassAndMethodName());
//         anotherMethod();
//     }

//     private static void anotherMethod() {
//         System.out.println(getCallerClassAndMethodName());
//     }

//     public static String getCallerClassAndMethodName() {
// Throwable t = new Throwable();
// StackTraceElement[] elements = t.getStackTrace();
// String calleeMethod = elements[0].getMethodName();
// String callerMethodName = elements[1].getMethodName();
// String callerClassName = elements[1].getClassName();

// if (callerMethodName.equals("main")){
//     return null;
// } else {
//     return "org.stepic.java.example.Test#main";
// }

// return "CallerClassName=" + callerClassName + " , Caller method name: " + callerMethodName;
// return "Callee method name: " + calleeMethod;
        // StackTraceElement stack = Thread.currentThread().getStackTrace()[2];
        // return "org.stepic.java.example.Test#" + stack.getMethodName();
        // Throwable e = new Throwable();
        // StackTraceElement[] elements = e.getStackTrace();
        // String exception = "";
        // for (StackTraceElement s : elements) {
        //     exception = exception + s.toString() + "\n\t\t";
        //     return exception;
        // }
        // return exception;
        // System.out.println(exception);
        // return exception;
        // String text = "Madam, I'm Adam!";
            // return Thread.currentThread().getStackTrace()[1].getMethodName();
            // return Thread.currentThread().getStackTrace()[1].getMethodName();
            // return Thread.currentThread().getStackTrace()[1].getFileName();

            // StackTraceElement[] stacktrace = Thread.currentThread().getStackTrace();
            // System.out.println(text);
            // StackTraceElement e = stacktrace[2];//maybe this number needs to be corrected
        // System.out.println(e.getMethodName());
//         // return name;
//     }
// }
        // int a[] = new int[] {0, 2};
        // int b[] = new int[] {1, 3};
        // int result[] = new int[a.length + b.length];
        // System.arraycopy(a, 0, result, 0, a.length);
        // System.arraycopy(b, 0, result, a.length, b.length);
        // Arrays.sort(result);
        // System.out.print(Arrays.toString(result));
        // return result;
        // for(int i=0; i<a.length; i++)
        // System.out.print(c[i]+" ");

        // BigInteger a = BigInteger.valueOf(100);
        // System.out.println(a);
        // BigInteger z = Factorial(3);
        // System.out.println(z);

        // String text = "Madam, I'm Adam!";
        // System.out.println(text1);
        // String textlower = text.toLowerCase();
        // // System.out.println(textlower);
        // String cleantext = text.toLowerCase().replaceAll("[^\\p{L}]","");
        // // String rev = "madamimadam";
        // StringBuilder rev = new StringBuilder(cleantext).reverse();
        // System.out.println(rev.toString());
        // System.out.println(cleantext);
        // boolean z;
        // z = rev.toString().equals(cleantext);
        // System.out.println(z);
        // // for (int i = 0; i < str.length(); i++) {
        // //     // do something at index i
        // // }


    //     int n = str.length();
    // for( int i = 0; i < n/2; i++ )
    //     if (str.charAt(i) != str.charAt(n-i-1)) return false;
    // return true;


        // // int [] a = {1,2,3};
        // // System.out.println(Arrays.toString(a));
        // String a1 = "A" + ('\t' + '\u0003'); //A12
        // String a2 = 'A' + '1' + "2"; // 1142
        // String a3 = 'A' + "12"; //A12
        // String a4 = "A" + 12; //12

        // System.out.println(a1);
        // // System.out.println(a2);
        // System.out.println(a3);
        // System.out.println(a4);
//     }
// }
// public boolean doubleExpression(double a, double b, double c) {
//     BigDecimal a1 = BigDecimal.valueOf(a);
//     BigDecimal b1 = BigDecimal.valueOf(b);
//     BigDecimal c1 = BigDecimal.valueOf(c);
//     if (a1.add(b1) == c1){
//         return true;
//     }
//     return false;
//     // return a1 + b1 == c1;
//     }

// /**
//  * Checks if given <code>value</code> is a power of two.
//  *
//  * @param value any number
//  * @return <code>true</code> when <code>value</code> is power of two, <code>false</code> otherwise
//  */
// public static boolean isPowerOfTwo(int value) {
//     return ... // you implementation here
// }

    // public static void main(String[] args) {
        // int a = 32;
        // // char s = Character.toChars((char)a);
        // // char s = Character.toChars(a);
        // char s = (char) a;
        // // char z;
        // // char x = a;
        // // char z = '\\';
        // int slash = '\\';
        // int sum = slash + a;
        // char find = (char) sum;
        // // int b = z1 + a;
        // // char z2 = (char) b;
        // System.out.println(find1);



        // if (value == 0) {
        //     return false;
        // }
        // else {
        //     return (number & (number - 1)) == 0;
        // }

        // return (number & (number - 1)) == 0;
        // int number = -2;
        // int number1 = Math.abs(number);
        // boolean x;
        // x = (number1 & (number1 - 1)) == 0;
        // System.out.println(x);
        // if (value % 2 == 0){
        //     return "true";
        // }
        // else {
        //     return "false";
        // }
        // int value = Math.abs(a);
        // System.out.println(value);
        // boolean x;
        // x = ((value & -value) == 0);
        // System.out.println(x);
        // float b = 123123123123L; //long -> float
        // int e = 'a'; //char -> int
        // Character g = 'a'; //char -> Character
        // long h = 123; //int -> long

        // Main rc = new Main();
        // boolean res = rc.doubleExpression(0.1d, 0.2d, 0.3d);
        // double a = 0.1;
        // double b = 0.2;
        // double c = 0.3;
        // double ep = 0.0001;
        // boolean z;
        // // z = (((a+b)-(a+b)%0.0000000000000001)==c);
        // return ((a+b) - c < ep);

        // System.out.println(z);
        // System.out.println(ep);

// }
// }
        // if ((a+b)-((a+b)%0.0000000000000001)==c)
        // {
        //     return "true";
        // }
        // else {
        //     return "false";
        // }
        // // BigDecimal a1 = new BigDecimal(a);
        // // BigDecimal b1 = new BigDecimal(b);
        // // BigDecimal c1 = new BigDecimal(c);
        // // System.out.println(res);
        // System.out.println(c1);
        // // BigDecimal a1 = BigDecimal.valueOf(a);
        // // BigDecimal b1 = BigDecimal.valueOf(b);
        // // BigDecimal c1 = BigDecimal.valueOf(c);
        // BigDecimal res = a1.add(b1);
        // // BigDecimal res1 = BigDecimal.valueOf(res);
        // System.out.println(res.compareTo(c1) == 0 ? "true": "false");
        // // if (res == c1){
        // //     System.out.println(res);
        // // }
        // System.out.println(res);
        // String bbb = "0";
        // String ccc = "1";
        // int H1 = 0;
        // int H2 = 1;
        // int H3 = H1 ^ H2;
        // int aaa = Integer.parseInt(bbb);
        // int ddd = Integer.parseInt(ccc);
        // System.out.println(H3);
        // System.out.println( "a XOR b " + Integer.toBinaryString( aaa ^ ddd ));

        // System.out.println(c1);
        // res = a + b;
        // System.out.println(res); //0.30000000000000004
        // System.out.println("It's alive! It's alive!");

// }
// }

// public boolean doubleExpression(double a, double b, double c) {
//     BigDecimal a1 = BigDecimal.valueOf(a);
//     BigDecimal b1 = BigDecimal.valueOf(b);
//     BigDecimal c1 = BigDecimal.valueOf(c);
//     BigDecimal res = a1.add(b1);
//     System.out.println(res.compareTo(c1) == 0 ? "true": "false");
//     // return a + b == c;
// }