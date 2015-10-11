import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Pattern;

/**
 * User: Dmitriy Bandurin
 * Date: 13.12.11
 */
public class Graph {
    public static void main(String[] args) throws IOException {
        final InputStreamReader in = new InputStreamReader(System.in);
        final BufferedReader bufferedReader = new BufferedReader(in);
        final String s = bufferedReader.readLine();
        Pattern spliter = Pattern.compile(" ");
        String[] elements = spliter.split(s);
        int numOfVIP = Integer.parseInt(elements[0]);
        int numOfPair = Integer.parseInt(elements[1]);
        VIP[] vips = new VIP[numOfVIP + 1];
        for (int i = 1; i <= numOfVIP; i++) {
            vips[i] = new VIP(i);
        }

        for(int i = 0; i < numOfPair; i++){
            final String input = bufferedReader.readLine();
            final String[] pair = spliter.split(input);
            final int firstVip = Integer.valueOf(pair[0]);
            final int secondVip = Integer.valueOf(pair[1]);
            vips[firstVip].addEnemy(vips[secondVip]);
            vips[secondVip].addEnemy(vips[firstVip]);
        }

        boolean isPossible = true;
        for(int i = 1; i <= numOfVIP && isPossible; i++){
            final VIP vip = vips[i];
            if(vip.table == 0){
                isPossible = vip.determineTable(1);
            }
        }

        if(isPossible) {
            System.out.println("YES");
            int c = 0;
            for(int i = 1; i <= numOfVIP; i++){
                if(vips[i].table == 1){
                    if(c == 1) {
                        System.out.print(" ");
                    } else {
                        c = 1;
                    }
                    System.out.print(vips[i].number);
                }
            }
        } else {
            System.out.println("NO");
        }
    }
}

class VIP {
    int table = 0;
    List<VIP> enemys = new ArrayList<VIP>();
    int number;

    VIP(int number) {
        this.number = number;
    }

    void addEnemy(VIP enemyVip){
        enemys.add(enemyVip);
    }

    public boolean determineTable(int table) {
        boolean isPossible = true;
        if(this.table == 0) {
            this.table = table;
            if (!enemys.isEmpty()) {
                for (int i = 0; i < enemys.size() && isPossible; i++) {
                    isPossible = enemys.get(i).determineTable(this.table == 1 ? 2 : 1);
                }
            }
        } else if(this.table != table){
            isPossible = false;
        }

        return isPossible;
    }
}
