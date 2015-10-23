/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package iotest;

import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.regex.PatternSyntaxException;

/**
 * Пример простейшей программы с вводом и выводом
 * @author Михаил Глухих
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        try {
            PrintStream fout = new PrintStream("out.txt", "CP1251");
            PrintStream fout866 = new PrintStream("out866.txt", "CP866");
            PrintStream out866 = new PrintStream(System.out, true, "CP866");
            // Запись русских строк
            fout.println("Здравствуй, мир!");
            fout.println("Вывод русских строк в JAVA");
            fout866.println("Здравствуй, мир!");
            fout866.println("Вывод русских строк в JAVA");
            out866.println("Здравствуй, мир!");
            out866.println("Вывод русских строк в JAVA");

            // Создание "читателя" для ввода в другой кодировке
            InputStreamReader reader = new InputStreamReader(System.in, "CP866");


            // Запрос
            out866.println("Введите целые числа, разделенные пробелами");
            // Ввод символьного массива
            char[] buf = new char[50];
            // В symNum попадает число прочитанных символов (-1 при ошибке)
            int symNum = reader.read(buf);
            // Преобразование символьного массива в строку
            // с получением подстроки из символов 0..symNum-1 (substring)
            // и удалением первых и последних специальных символов (trim)
            String str = new String(buf).substring(0, symNum).trim();
            out866.println("Введена строка: " + str);

            Scanner sc = new Scanner(str);
            // Подсчет суммы чисел
            int sum = 0;
            while (sc.hasNextInt()) {
                int num = sc.nextInt();
                out866.println("Введено число: " + num);
                sum = sum + num;
            }
            out866.println("Сумма всех введенных чисел: " + sum);

            StringTokenizer tokenizer = new StringTokenizer(str, " \t");
            // Подсчет суммы чисел
            sum = 0;
            while (tokenizer.hasMoreElements()) {
                String substr = tokenizer.nextToken();
                // Проверка, есть ли в строке хоть что-нибудь
                if (substr.length() == 0) {
                    out866.println("Пустая подстрока");
                    continue;
                }
                // Преобразование строки в число (parseInt)
                int num = 0;
                try {
                    num = Integer.parseInt(substr);
                    out866.println("Введено число: " + num);
                } catch (NumberFormatException e) {
                    out866.println("Введено НЕ число: " + substr);
                }
                sum = sum + num;
            }
            out866.println("Сумма всех введенных чисел: " + sum);

            // Разбиение строки на подстроки, разделенные пробелами
            String[] splitted;
            try {
                splitted = str.split(" ");
            } catch (PatternSyntaxException e) {
                // Если разбиение не получилось
                out866.println("Неверный формат ввода!");
                return;
            }
            out866.println("Всего найдено " + splitted.length + " подстрок\n");
            sum = 0;
            // Перебор элементов массива splitted
            for (String substr: splitted) {
                // Проверка, есть ли в строке хоть что-нибудь
                if (substr.length() == 0) {
                    out866.println("Пустая подстрока");
                    continue;
                }
                // Преобразование строки в число (parseInt)
                int num = 0;
                try {
                    num = Integer.parseInt(substr);
                    out866.println("Введено число: " + num);
                } catch (NumberFormatException e) {
                    out866.println("Введено НЕ число: " + substr);
                }
                sum = sum + num;
            }
            out866.println("Сумма всех введенных чисел: " + sum);
        } catch (IOException e) {
            // Отлов исключений I/O
            System.out.println("Exception: " + e);
        }        
    }
}
