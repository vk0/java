import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.regex.Pattern;

/**
 * User: luckyman
 */
public class Report {
    public static void main(String[] args) throws IOException {
        InputStreamReader in = new InputStreamReader(System.in);

        BufferedReader bufferedReader = new BufferedReader(in);

        Integer count = Integer.valueOf(bufferedReader.readLine());
        ReportInfo[] info = new ReportInfo[count];
        Pattern spliter = Pattern.compile(" ");
        for (int i = 1; i<=count; i++) {
            String reportInfoString = bufferedReader.readLine();
            String[] split = spliter.split(reportInfoString, 2);
            info[i - 1] = new ReportInfo(i, Integer.valueOf(split[0]), Integer.valueOf(split[1]));
        }
        Arrays.sort(info);
        int currentTime = info[0].stopTime;
        System.out.print(info[0].number + " ");
        for (int mainReportIndex = 1 ;mainReportIndex < count ; mainReportIndex++) {
            ReportInfo reportInfo = info[mainReportIndex];
            if(reportInfo.startTime >= currentTime){
                currentTime = reportInfo.stopTime;
                System.out.print(info[mainReportIndex].number + " ");
            }
        }
    }
}

class ReportInfo implements Comparable{
    public int number;
    public int startTime;
    public int stopTime;

    ReportInfo(int number, int startTime, int stopTime) {
        this.number = number;
        this.startTime = startTime;
        this.stopTime = stopTime;
    }


    public int compareTo(Object o) {
        return stopTime - ((ReportInfo)o).stopTime;
    }
}
