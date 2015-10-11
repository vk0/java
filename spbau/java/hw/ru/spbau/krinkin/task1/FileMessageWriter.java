package ru.spbau.krinkin.task1;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.FileNotFoundException;

import ru.spbau.krinkin.task1.MessageWriter;
import ru.spbau.krinkin.task1.Message;

/**
 * class FileMessageWriter allows to write messages ({@link ru.spbau.krinkin.task1.Message Message}) into a file
 *
 * @author Mike Krinkin, SPbAU 
 * @version 1.0
 */
public class FileMessageWriter implements MessageWriter {
	private BufferedWriter m_writer = null;
	
	/**
	 * class constructor
	 *
	 * @param fileName name of a file for writingjavadoc see
	 * @throws FileNotFoundException
	 * @throws IOException
	 */
	public FileMessageWriter(String fileName) throws FileNotFoundException, IOException {
		m_writer = new BufferedWriter(new FileWriter(fileName));
	}
	
	/**
	 * method write {@link ru.spbau.krinkin.task1.Message Message} to a file
	 *
	 * @param msg {@link ru.spbau.krinkin.task1.Message Message}
	 * @throws IOException
	 */
	public void writeMessage(Message msg) throws IOException {
		int count = msg.getLines().size();
		m_writer.write(String.valueOf(count));
		m_writer.newLine();
		for (String str : msg.getLines()) {
			m_writer.write(str);
			m_writer.newLine();
		}
		m_writer.flush();
	}

	/**
	 * method close the output stream
	 *
	 * @throws IOException
	 */	
	public void close() throws IOException {
		m_writer.close();
		m_writer = null;
	}
}