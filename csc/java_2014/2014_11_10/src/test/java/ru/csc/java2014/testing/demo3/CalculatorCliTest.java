package ru.csc.java2014.testing.demo3;

import org.junit.Before;
import org.junit.Test;
import org.mockito.Mockito;

import java.io.StringReader;

import static org.junit.Assert.*;
import static org.mockito.Mockito.*;

public class CalculatorCliTest {

    private Calculator calculatorMock;
    private CalculatorCli calculatorCli;

    @Before
    public void setUp() {
        calculatorMock = Mockito.mock(Calculator.class);
        calculatorCli = new CalculatorCli(calculatorMock);
    }

    @Test
    public void empty_expressions_must_be_skipped() {
        calculatorCli.runInteractiveSession(new StringReader(";\n;   ;;;\t\n;"));

        Mockito.verifyZeroInteractions(calculatorMock);
    }


    @Test
    public void each_expression_separated_by_semicolon_must_be_evaluated() {
        calculatorCli.runInteractiveSession(new StringReader("1;2;3;"));

        verify(calculatorMock).calculate("1");
        verify(calculatorMock).calculate("2");
        verify(calculatorMock).calculate("3");
        verifyNoMoreInteractions(calculatorMock);
    }


    @Test
    public void each_expression_separated_by_semicolon_must_be_evaluated_2() {
        when(calculatorMock.calculate("1")).thenReturn(1d);
        when(calculatorMock.calculate("2")).thenReturn(2d);
        when(calculatorMock.calculate("3")).thenReturn(3d);

        calculatorCli.runInteractiveSession(new StringReader("1;2;3;"));
        verify(calculatorMock).calculate("1");
        verify(calculatorMock).calculate("2");
        verify(calculatorMock).calculate("3");
        verifyNoMoreInteractions(calculatorMock);
    }
}
