package ru.spbau.krinkin.task1;

import java.util.ArrayList;
import java.util.List;
import java.util.Collections;


/**
 * class Message - list of String lines.
 *
 * @author Mike Krinkin, SPbAU 
 * @version 1.0
 */
public class Message {
	private List<String> m_lines = new ArrayList<String>();

	/**
	 * method adds String line to a Message
	 *
	 * @param line new String line
	 */
	public void append(String line) {
		m_lines.add(line);
	}

	/**
	 * method appends another Messages to the end of a Message
	 *
	 * @param msg appended Message
	 */
	public void append(Message msg) {
		m_lines.addAll(msg.getLines());
	}

	/**
	 * method return List<String> representation of a Message
	 *
	 * @return unmodifiable List of String lines, that a Message contains
	 */
	public List<String> getLines() {
		return Collections.unmodifiableList(m_lines);
	}
}
