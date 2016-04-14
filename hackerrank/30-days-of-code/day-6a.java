public class Solution {

    private static String isFunny(char[] s){
        boolean funny = true;
        for(int i = 1, j = s.length - 1;
            i < s.length;
            i++, j--){
            if( Math.abs(s[i] - s[i-1]) != Math.abs(s[j] - s[j-1])){
                funny = false;
                break;
            }
        }
        return (funny) ? "Funny" : "Not Funny";
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int testCases = scan.nextInt();
        for(int i = 0; i < testCases; i++){
            System.out.println(
                isFunny( scan.next().toCharArray() )
            );
        }
        scan.close();
    }
}