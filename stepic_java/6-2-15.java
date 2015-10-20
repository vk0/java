// Напишите программу, которая прочитает из System.in последовательность целых чисел, разделенных пробелами, затем удалит из них все числа, стоящие на четных позициях, и затем выведет получившуюся последовательность в обратном порядке в System.out.

// Все числа влезают в int. Позиции чисел в последовательности нумеруются с нуля.

// В этом задании надо написать программу целиком, включая import'ы, декларацию класса Main и метода main.

// Sample Input:
// 1 2 3 4 5 6 7
// Sample Output:
// 6 4 2

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        // String[] arr;
        String line;
        while (( line = reader.readLine()) != null ) {
            String[] arr = line.split(" ");
            List<String> list = new ArrayList<>(Arrays.asList(arr));
            List<String> res = new ArrayList<>();

            for (int i = 1; i < list.size(); i=i+2) {
                res.add(list.get(i));
            }

            for (int i = res.size()-1; i >= 0; i--) {
                System.out.print(res.get(i) + " ");
            }
        }
    }
}
