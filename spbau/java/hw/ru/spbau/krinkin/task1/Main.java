package ru.spbau.krinkin.task1;

import java.io.IOException;
import java.io.FileNotFoundException;

import ru.spbau.krinkin.task1.CompressingMessageWriter;
import ru.spbau.krinkin.task1.FileMessageReader;
import ru.spbau.krinkin.task1.Message;
import ru.spbau.krinkin.task1.IllegalMessageFormatException;

/**
 * Main program file. Program compress messages ({@link ru.spbau.krinkin.task1.Message Message}) from a file specified
 * in first argument and output to the System.out or a file specified in second argument
 *
 * @author Mike Krinkin, SPbAU 
 * @version 1.0
 */
public class Main {
	/**
	 * program entry point
	 *
	 * @param args command line parameters
	 * @throws IOException may throws IOException caused by input or output stream closing
	 */
	public static void main(String[] args) throws IOException {
		if (args.length == 0) {
			System.out.println("usage: program <input file name> [<output file name>]");
			System.exit(1);
		}
		
		FileMessageReader reader = null;
		MessageWriter writer = null;
		try {
			reader = new FileMessageReader(args[0]);
			if (args.length > 1) {
				writer = new CompressingMessageWriter(new FileMessageWriter(args[1]));
			} else {
				writer = new CompressingMessageWriter(new ConsoleMessageWriter());
			}
			
			Message msg = null;
			while ((msg = reader.readMessage()) != null) {
				writer.writeMessage(msg);
			}
		} catch (NullPointerException e) {
			// it can be happen only if operator new returns null
			e.printStackTrace(System.err);
		} catch (IllegalMessageFormatException e) {
			System.err.println("wrong format of file: " + args[0]);
			e.printStackTrace(System.err);
		} catch (FileNotFoundException e) {
			System.err.println("Input or output file not found or not available");
			e.printStackTrace(System.err);
		} catch (IOException e) {
			// it can be happen almost every IO operation, but it is rarely
			e.printStackTrace(System.err);
		} finally {
			reader.close();
			writer.close();
		}
	}
}