// aabcccccaaa должна превратиться в а2b1с5аЗ
// http://tproger.ru/problems/string-compression/

public String compressBad(String str) {
    String mystr = "";
    char last = str.charAt(0);
    int count = 1;
    for (int i = 1; i < str.length(); i++) {
        if (str.charAt(i) == last) { // Находим повторяющийся символ
            count++;
        } else {    // Вставляем счетчик символа и обновляем последний символ
            mystr += last + count;
            last = str.charAt(i);
            count = 1;
        }
    }
    return mystr + last + count;
}