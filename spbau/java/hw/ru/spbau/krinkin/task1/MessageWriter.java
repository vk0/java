package ru.spbau.krinkin.task1;

import java.io.IOException;

import ru.spbau.krinkin.task1.Message;

/**
 * interface MessageWriter declare {@link ru.spbau.krinkin.task1.Message Message} output
 *
 * @author Mike Krinkin, SPbAU 
 * @version 1.0
 */
public abstract interface MessageWriter {
	/**
	 * put {@link ru.spbau.krinkin.task1.Message Message} into output stream
	 *
	 * @param msg
	 * @throws IOException method may throws IOException in implementation
	 */
	public void writeMessage(Message msg) throws IOException;
	
	/**
	 * method flush and close output stream
	 * 
	 * @throws IOException method may throws IOException in implementation
	 */
	public void close() throws IOException;
}