// If you wanted to be more specific, you could throw an IllegalArgumentException exception instead of an Exception exception. Because Exception is a superclass of IllegalArgumentException, it will catch an IllegalArgumentException exception.

class Calculator{
    public int power(int n, int p) throws IllegalArgumentException{
        if(n < 0 || p < 0){
            throw new IllegalArgumentException("n and p should be non-negative");
        }
        return (int)Math.pow(n,p);
    }
}

// class Calculator{
//     public int power(int n, int p) throws Exception{
//         if(n < 0 || p < 0){
//             throw new Exception("n and p should be non-negative");
//         }
//         return (int)Math.pow(n,p);
//     }
// }