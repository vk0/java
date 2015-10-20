package ru.csc.java2014.testing.demo1;

import org.junit.Ignore;
import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class StringTest {

    @Test
    public void substring_should_count_chars_from_0() {
        assertEquals('H', "Hello".charAt(0));
    }


    @Test(expected = StringIndexOutOfBoundsException.class)
    public void substring_should_throw_exception_for_invalid_index() {
        "".substring(1);
    }


    @Test(timeout = 1000L) @Ignore
    public void should_finish_in_1_second() throws Exception {
        Thread.sleep(2000L);
    }
}
