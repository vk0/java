// Задача на программирование: декодирование Хаффмана


// Восстановите строку по её коду и беспрефиксному коду символов.

// В первой строке входного файла заданы два целых числа k и l через пробел — количество различных букв, встречающихся в строке, и размер получившейся закодированной строки, соответственно. В следующих k строках записаны коды букв в формате "letter: code". Ни один код не является префиксом другого. Буквы могут быть перечислены в любом порядке. В качестве букв могут встречаться лишь строчные буквы латинского алфавита; каждая из этих букв встречается в строке хотя бы один раз. Наконец, в последней строке записана закодированная строка. Исходная строка и коды всех букв непусты. Заданный код таков, что закодированная строка имеет минимальный возможный размер.

// В первой строке выходного файла выведите строку s. Она должна состоять из строчных букв латинского алфавита. Гарантируется, что длина правильного ответа не превосходит 104 символов.



// Sample Input 1:

// 1 1
// a: 0
// 0

// Sample Output 1:

// a


// Sample Input 2:

// 4 14
// a: 0
// b: 10
// c: 110
// d: 111
// 01001100100111

// Sample Output 2:

// abacabad

import java.util.*;

class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int num_symbols = sc.nextInt();
        int len_encoding = sc.nextInt();

        HashMap<String, Character> codewords = new HashMap<String, Character>();
        for(int i = 0; i < num_symbols; i++){
            char letter = sc.next().charAt(0);
            String codeword = sc.next();
            codewords.put(codeword, letter);
        }

        String encoded = sc.next();
        String unencoded = new String();
        String word = new String();
        for(int i = 0; i < encoded.length(); i++){
            word += encoded.charAt(i);
            if(codewords.containsKey(word)){
                unencoded += codewords.get(word);
                word = new String();
            }
        }
        System.out.println(unencoded);
    }
}