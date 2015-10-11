import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * User: Dmitriy Bandurin
 * Date: 12.12.11
 */
public class BalancedTree {
    public static void main(String[] args) throws IOException {
        InputStreamReader in = new InputStreamReader(System.in);
        BufferedReader bufferedReader = new BufferedReader(in);
        char[] temp = new char[1024];
        int readCount;
        StringBuilder builder = new StringBuilder();
        while ((readCount = bufferedReader.read(temp)) != -1) {
            builder.append(temp, 0, readCount);
        }
        final String nodes = builder.toString();
        StringTokenizer tokenizer = new StringTokenizer(nodes);
        if (tokenizer.hasMoreTokens()) {
            Node tree = new Node(null, Integer.parseInt(tokenizer.nextToken()));

            while (tokenizer.hasMoreTokens()) {
                final int value = Integer.parseInt(tokenizer.nextToken());
                if (value != 0) {
                    tree.add(value);
                } else {
                    break;
                }
            }
            System.out.println(tree.balanced ? "YES" : "NO");
        } else {
            System.out.println(0);
        }

    }
}

class Counter {
    static int count = 0;
}

class Node {
    public Node parent;
    public Node left;
    public Node right;
    public int height;
    public int value;
    public boolean balanced;

    Node(Node parent, int value) {
        this.parent = parent;
        this.value = value;
        this.balanced = true;
        Counter.count++;
        if (value == 0) {
            this.height = 0;
        } else {
            this.height = 1;
        }
    }

    public void add(int value) {
        if (this.value == value) {
            return;
        }

        if (value > this.value) {
            if (this.right != null) {
                this.right.add(value);
            } else {
                this.right = new Node(this, value);
                this.update();
            }
        } else {
            if (this.left != null) {
                this.left.add(value);
            } else {
                this.left = new Node(this, value);
                this.update();
            }
        }
    }

    private void update() {
        int lHeight = this.left != null ? this.left.height : 0;
        int rHeight = this.right != null ? this.right.height : 0;
        boolean lBalanced = this.left == null || this.left.balanced;
        boolean rBalanced = this.right == null || this.right.balanced;

        this.height = Math.max(lHeight, rHeight) + 1;
        this.balanced = lBalanced && rBalanced && (Math.max(lHeight, rHeight) - Math.min(lHeight, rHeight)) < 2;
        if (this.parent != null) {
            this.parent.update();
        }
    }
}