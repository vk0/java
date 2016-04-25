Terms you'll find helpful in completing today's challenge are outlined below, along with sample Java code (where appropriate).

Propagating Exceptions
If an exception is not caught by the method that threw it, the program's control is transferred back (propagated) to the calling method (i.e.: whatever called the method that threw the exception). This can be good if you have designed your program to handle exceptions at a high level, but bad if you never write code to catch the exception in the calling methods that the exception is being propagated to. The example method below throws an exception of type Exception, which propagates back to the calling method (main), where a catch block catches it and prints a message:
class PropagatedException {

    void example() throws Exception{
        throw new Exception("This exception will always be thrown.");
    }

    public static void main(String[] args) {
        PropagatedException p = new PropagatedException();
        try{
            p.example();
        }
        catch(Exception e){
            System.err.println( e.getClass().getSimpleName() + ": " + e.getMessage() );
        }
    }
}
The above code throws a java.lang.Exception and prints:
Exception: This exception will always be thrown.

Confused? Check out yesterday's introduction to Exceptions.