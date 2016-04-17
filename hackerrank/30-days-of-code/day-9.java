// Base Case: n≡1n≡1, return 11.
// Recursive Case: n≥1n≥1, return n×factorial(n−1)n×factorial(n−1).
// Each recursive call deals with smaller and smaller cases until we get to n≡1n≡1. Then the program starts passing the returnreturn value for each level of recursion back through the call stack.

// For example, if n=4n=4:
// 4×return←−−−− (3×return←−−−− (2×return←−−−− (1) ) )=4×3×2×1=24
// 4×return← (3×return← (2×return← (1) ) )=4×3×2×1=24

public class Solution {

    public static int factorial(int n){
        return (n > 1) ? n * factorial(n-1) : 1;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        scan.close();
        System.out.println(factorial(n));
    }
}