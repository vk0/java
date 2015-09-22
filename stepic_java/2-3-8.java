public class Main {
    public static void main(String[] args) {
        String a1 = "A" + ('\t' + '\u0003'); //A12
        String a2 = 'A' + '1' + "2"; // 1142
        String a3 = 'A' + "12"; //A12
        String a4 = "A" + 12; //12
    }
}