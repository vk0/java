// Реализуйте метод, возвращающий ответ на вопрос: правда ли, что a + b = c?
// Погрешность вычислений – 0.0001 (1E-4)
// В качестве примера написано заведомо неправильное выражение. Исправьте его.
// Sample Input:
// 0.1 0.2 0.3
// Sample Output:
// true

public boolean doubleExpression(double a, double b, double c) {
    return ((a+b)-((a+b)%0.0000000000000001)==c);

}

// public boolean doubleExpression(double a, double b, double c) {
//     double ep = 0.0001;
//     return ((a+b) - c < ep);
//     return ((a+b)-((a+b)%0.0000000000000001)==c);

// }

// 4 TEST
// import java.math.*;
// public class Main {
//     public static void main(String[] args) {
//         double a = 0.1;
//         double b = 0.2;
//         double c = 0.3;
//         boolean z;
//         z = (((a+b)-(a+b)%0.0000000000000001)==c);
//         System.out.println(z);
//         }
// }