import java.io.FileNotFoundException;
import java.io.InputStream;
import java.math.BigInteger;
import java.util.LinkedList;
import java.util.Scanner;

/**
 * User: luckyman
 */
public class Polish {

    public static void main(String[] args) throws FileNotFoundException {
        InputStream in = System.in;
        Scanner sc = new Scanner(in);
        LinkedList<BigInteger> stack = new LinkedList<BigInteger>();
        String line = sc.nextLine();
        String[] tokens = line.split(" ");
        for (String token : tokens) {
            BigInteger result;
            if("+".equals(token)){
                result = stack.pop().add(stack.pop());
            } else if("-".equals(token)){
                result = stack.pop().subtract(stack.pop()).negate();
            } else if("*".equals(token)){
                result = stack.pop().multiply(stack.pop());
            } else {
                result = new BigInteger(token);
            }
            stack.push(result);
        }
        System.out.println(stack.pop());
    }
}


