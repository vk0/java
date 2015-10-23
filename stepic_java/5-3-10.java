// Какими байтами представляется символ 'Ы' в кодировке UTF-8? Введите десятичные значения байт через пробел, например, 10 34 254.

// Python
// bytes = [ord(c) for c in "Ы"]
// print(bytes)

// s = 'Ы'
// b = bytearray(s)
// for i in b:
//     print i

import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        byte[] bytes = "Ы".getBytes();
        for (int i = 0; i < bytes.length; i++) {
            System.out.println(Byte.toUnsignedInt(bytes[i]));
        }

    }
}