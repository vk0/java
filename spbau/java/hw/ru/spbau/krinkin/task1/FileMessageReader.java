package ru.spbau.krinkin.task1;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileNotFoundException;
import java.io.IOException;

import ru.spbau.krinkin.task1.Message;
import ru.spbau.krinkin.task1.IllegalMessageFormatException;

/**
 * class FileMessageReader reads {@link ru.spbau.krinkin.task1.Message Message} from a specified file
 *
 * @author Mike Krinkin, SPbAU 
 * @version 1.0
 */
public class FileMessageReader {
	private BufferedReader m_reader = null;

	/**
	 * FileMessageReader class constructor, open file for reading
	 *
	 * @param fileName name of File
	 * @throws FileNotFoundException
	 */	
	public FileMessageReader(String fileName) throws FileNotFoundException {
		m_reader = new BufferedReader(new FileReader(fileName));
	}
	
	/**
	 * method read a {@link ru.spbau.krinkin.task1.Message Message} from a file
	 *
	 * @return The {@link ru.spbau.krinkin.task1.Message Message} was read from a file
	 * @throws IllegalMessageFormatException bad file format exception
	 * @throws IOException
	 */
	public Message readMessage() throws IllegalMessageFormatException, IOException {
		String line = m_reader.readLine();
		Message msg = null;
		
		try {
			if (line != null) {
				int nLines = Integer.parseInt(line);
				msg = new Message();
			
				for (int i = 0; i < nLines; i++) {
					line = m_reader.readLine();
					if (line != null) {
						msg.append(line);
					} else {
						close();
						throw new IllegalMessageFormatException(
								"Expected " + nLines + " lines, but only "
								+ i + " lines exists");
					}
				}
			}
		} catch (NumberFormatException e) {
			close();
			throw new IllegalMessageFormatException(
				"Number expected, but \"" + line + "\" exists");
		}
		
		return msg;
	}
	
	/**
	 * method close the input stream
	 *
	 * @throws IOException
	 */
	public void close() throws IOException {
		m_reader.close();
		m_reader = null;
	}
}