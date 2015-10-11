import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.regex.Pattern;

/**
 * User: Dmitriy Bandurin
 * Date: 12.12.11
 */
public class UpCont {
    public static void main(String[] args) throws IOException {
        final InputStreamReader in = new InputStreamReader(System.in);
        final BufferedReader bufferedReader = new BufferedReader(in);
        final int numOfElemetns = Integer.valueOf(bufferedReader.readLine());
        Pattern spliter = Pattern.compile(" ");
        final String input = bufferedReader.readLine();
        String[] elements = spliter.split(input);
        int[] array = new int[numOfElemetns];
        int[] max = new int[numOfElemetns];
        int[] links = new int[numOfElemetns];
        max[0] = 1;
        links[0] = -1;
        int maxLength = max[0];
        int maxLink = 0;
        array[0] = Integer.parseInt(elements[0]);

        for(int i = 1 ;i < numOfElemetns; i++){
            final int currentValue = Integer.parseInt(elements[i]);
            array[i] = currentValue;
            int maxPrevious = 0;
            int link = -1;
            for(int j = 0; j < i; j++){
                if(array[j] < currentValue && maxPrevious < max[j]){
                    maxPrevious = max[j];
                    link = j;
                }
            }

            links[i] = link;
            max[i] = maxPrevious + 1;
            if(max[i] > maxLength){
                maxLength = max[i];
                maxLink = i;
            }
        }

        int[] countinue = new int[maxLength];
        int index = maxLength;

        while(maxLink != -1){
            countinue[--index] = array[maxLink];
            maxLink = links[maxLink];
        }

        for(int i = 0; i < countinue.length; i++){
            System.out.print(countinue[i]);
            if(i != countinue.length - 1){
                System.out.print(" ");
            }
        }
    }
}
