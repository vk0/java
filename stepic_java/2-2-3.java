// Реализуйте метод, который возвращает букву, стоящую в таблице UNICODE после символа "\\" (обратный слэш) на расстоянии a:
// В качестве примера написано заведомо неправильное выражение. Исправьте его.
// Sample Input 1:
// 32
// Sample Output 1:
// |
// Sample Input 2:
// 12
// Sample Output 2:
// h
public char charExpression(int a) {
    int slash = '\\';
    int sum = slash + a;
    char find = (char) sum;
    return find;
}