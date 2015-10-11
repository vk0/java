package ru.spbau.krinkin.task1;

import java.io.IOException;

import ru.spbau.krinkin.task1.ConsoleMessageWriter;
import ru.spbau.krinkin.task1.Message;

/**
 * class ComressingMessageWriter implements {@link ru.spbau.krinkin.task1.MessageWriter MessageWriter}.
 * It compress two messages in one {@link ru.spbau.krinkin.task1.Message Message} then outputs it with
 * specified {@link ru.spbau.krinkin.task1.MessageWriter MessageWriter}
 *
 * @author Mike Krinkin, SPbAU 
 * @version 1.0
 */
public class CompressingMessageWriter implements MessageWriter {
	private Message m_lastMessage = null;
	private MessageWriter m_writer = null;
	
	public CompressingMessageWriter(MessageWriter writer) throws NullPointerException {
		if (writer == null) {
			throw new NullPointerException("writer must be not null");
		}
		m_writer = writer;
	}

	/**
	 * method merges pairs of {@link ru.spbau.krinkin.task1.Message Message} and then writes it using
	 * specified {@link ru.spbau.krinkin.task1.MessageWriter MessageWriter}
	 *
	 * @param msg {@link ru.spbau.krinkin.task1.Message Message}
	 * @throws IOException
	 */
	public void writeMessage(Message msg) throws IOException {
		if (m_lastMessage != null) {
			m_lastMessage.append(msg);
			m_writer.writeMessage(m_lastMessage);
			m_lastMessage = null;
		} else {
			m_lastMessage = msg;
		}
	}
	
	/**
	 * method flush last {@link ru.spbau.krinkin.task1.Message Message} and drops message counter
	 * (see {@link ru.spbau.krinkin.task1.ConsoleMessageWriter ConsoleMessageWriter})
	 *
	 * @throws IOException
	 */
	public void close() throws IOException {
		if (m_lastMessage != null) {
			m_writer.writeMessage(m_lastMessage);
		}
		m_writer.close();
	}
}