package ru.spbau.krinkin.task1;

import java.io.IOException;

import ru.spbau.krinkin.task1.MessageWriter;
import ru.spbau.krinkin.task1.Message;

/**
 * class ConsoleMessageWriter implements interface {@link ru.spbau.krinkin.task1.MessageWriter MessageWriter}, it
 * writes lines of  {@link ru.spbau.krinkin.task1.Message Message} in System.out
 *
 * @author Mike Krinkin, SPbAU 
 * @version 1.0
 */
public class ConsoleMessageWriter implements MessageWriter {
	private int m_counter = 1;

	private void printMessage(Message msg) {
		System.out.println("Message " + m_counter);
		int num = 1;
		for (String str : msg.getLines()) {
			System.out.println(String.valueOf(m_counter) + "." +
						String.valueOf(num++) + ". " + str);
		}
	}
	
	/**
	 * method write {@link ru.spbau.krinkin.task1.Message Message} in System.out
	 *
	 * @param msg {@link ru.spbau.krinkin.task1.Message Message}
	 * @throws IOException
	 */
	public void writeMessage(Message msg) throws IOException {
		printMessage(msg);
		m_counter++;
	}
	
	/**
	 * method drops message counter
	 *
	 * @throws IOException
	 */
	public void close() throws IOException {
		m_counter = 1;
	}
}