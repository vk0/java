package ru.spbau.krinkin.task1;

import java.io.IOException;

/**
 * class IllegalMessageFormatException extends IOException, throws by {@link ru.spbau.krinkin.task1.FileMessageReader FileMessageReader}
 *
 * @author Mike Krinkin, SPbAU 
 * @version 1.0
 */
public class IllegalMessageFormatException extends IOException {
	/**
	 * class constructor
	 *
	 * @param msg describes file format error
	 */
	public IllegalMessageFormatException(String msg) {
		super(msg);
	}
}