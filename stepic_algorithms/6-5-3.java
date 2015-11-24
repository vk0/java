import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

    class Item implements Comparable<Item> {
        int cost;
        int weight;

        public Item(int cost, int weight) {
            this.cost = cost;
            this.weight = weight;
        }
        @Override
        public String toString() {
            return "Item{" + "cost=" + cost + ", weight" + weight + '}';
        }
        @Override
        public int compareTo(Item o) {
            long r1 = (long) cost * o.weight;
            long r2 = (long) o.cost * weight;
            return -Long.compare(r1, r2);
        }
    }
    private void run() {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int W = input.nextInt();
        Item[] items = new Item[n];
        for (int i = 0; i < n; i++) {
            items[i] = new Item(input.nextInt(), input.nextInt());
        }
        Arrays.sort(items);
        double result = 0;
        for (Item item : items) {
            if (item.weight <= W) {
                result += item.cost;
                W -= item.weight;
            } else {
                result += (double)item.cost * W / item.weight;
                break;
            }
        }
        System.out.println(result);
    }

    public static void main(String[] args) {
        long startTime = System.currentTimeMillis();
        new Main().run();
        long finishTime = System.currentTimeMillis();
        System.out.println(finishTime - startTime + " ms");
    }
}