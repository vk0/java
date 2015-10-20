package ru.csc.java2014.testing;

public class CalculatorImpl implements Calculator {

    @Override
    public double calculate(String expression) {
        throw new UnsupportedOperationException();
    }


//    @Override
//    public double calculate(String expression) {
//        ScriptEngine scriptEngine = new ScriptEngineManager().getEngineByName("nashorn");
//        try {
//            defineMathFunctions(scriptEngine);
//            return ((Number) scriptEngine.eval(expression)).doubleValue();
//        } catch (ScriptException e) {
//            throw new IllegalArgumentException("Failed to evaluate expression", e);
//        }
//    }
//
//    private static void defineMathFunctions(ScriptEngine scriptEngine) throws ScriptException {
//        for (String function : new String[] {"sin", "cos", "sqrt"}) {
//            scriptEngine.eval("function " + function + "(x) { return Java.type('java.lang.Math')." + function + "(x); }");
//        }
//    }
}
