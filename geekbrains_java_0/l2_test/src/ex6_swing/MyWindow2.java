package ex6_swing;

import javax.swing.*;
import java.awt.*;

/**
 * Created by igor on 24.05.15.
 */
// awt -> swing -> javaFX

public class MyWindow2 extends JFrame {
    static JTextArea textArea;

    public MyWindow2() throws HeadlessException {
        setSize(400, 300);
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        setTitle("Java Dive");

        textArea = new JTextArea();
        add(textArea);
        for (int i = 0; i < 20; i++) {
            textArea.append("just do it... \n");
        }

        add(new JButton("go"), BorderLayout.SOUTH);

        setVisible(true);
    }
}

//Изучаем Java, HeadFirst Java, Сьерра, Бейтс
//        Хорстманн
//        Шилдт
//Философия Java
