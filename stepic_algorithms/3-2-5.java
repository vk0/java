// Задача на программирование: кодирование Хаффмана


// По данной непустой строке s длины не более 104, состоящей из строчных букв латинского алфавита, постройте оптимальный беспрефиксный код. В первой строке выведите количество различных букв k, встречающихся в строке, и размер получившейся закодированной строки. В следующих k строках запишите коды букв в формате "letter: code". В последней строке выведите закодированную строку.



// Sample Input 1:

// a

// Sample Output 1:

// 1 1
// a: 0
// 0


// Sample Input 2:

// abacabad

// Sample Output 2:

// 4 14
// a: 0
// b: 10
// c: 110
// d: 111
// 01001100100111


import java.util.*;

class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String s = sc.next();

        int[] freqs = new int[256];
        for(int i = 0; i < s.length(); i++)
            freqs[(int)s.charAt(i)]++;

        HuffmanTree tree = new HuffmanTree(freqs);
        String encoded = "";
        for(int i = 0; i < s.length(); i++)
            encoded += tree.leaves.get(s.charAt(i)).code;

        System.out.println(tree.inOrderLeaves.size() + " " + encoded.length());
        while(!tree.inOrderLeaves.isEmpty()){
            TreeNode leaf = tree.inOrderLeaves.poll();
            System.out.println(leaf.character + ": " + leaf.code);
        }
        System.out.println(encoded);
    }
}

class HuffmanTree {
    TreeNode root;
    HashMap<Character, TreeNode> leaves;
    LinkedList<TreeNode> inOrderLeaves;

    public HuffmanTree(int[] freqs){
        //System.out.println("Building Tree");
        this.leaves = new HashMap<Character, TreeNode>();
        this.inOrderLeaves = new LinkedList<TreeNode>();

        PriorityQueue<TreeNode> pq
                = new PriorityQueue<TreeNode>(11, new TreeNodeComp());

        for(int i = 0; i < freqs.length; i++){
            if(freqs[i] != 0){
                TreeNode node = new TreeNode((char)i, freqs[i]);
                //System.out.println("adding " + node.character + " with frequency " + node.freq + " to leaves");
                leaves.put(node.character, node);
                inOrderLeaves.add(node);
                pq.add(node);
            }
        }


        if(pq.size() == 1){
            TreeNode node = pq.poll();
            node.code = "0";
            this.root = node;
            return;
        }

        while(pq.size() > 1) {
            //System.out.println("\nmore than 1 node on the PriorityQueue");
            TreeNode node1 = pq.poll();
            TreeNode node2 = pq.poll();
            //System.out.println("popped off " + node1.character +
            //  " with frequency " + node1.freq + " and " + node2.character +
            //  " with frequency " + node2.freq);

            TreeNode newNode = new TreeNode(node1.character, node1.freq + node2.freq);
            newNode.c0 = node1;
            newNode.c1 = node2;
            node1.parent = newNode;
            node2.parent = newNode;

            //System.out.println("adding newNode with character = " +
            //  newNode.character + " and frequency " + newNode.freq +
            //  " to the queue");
            pq.add(newNode);
        }
        this.root = pq.poll();
        //System.out.println("root is " + root.character + " with frequency " + root.freq);

        for(TreeNode node : inOrderLeaves)
            node.code = getCode(node.character);
    }

    public String getCode(char c){
        //System.out.println("\nentered getCode for character " + c);
        if(leaves.get(c) == null)
            return null;

        String code = "";
        TreeNode node = leaves.get(c);
        while(node != root){
            //System.out.println("Current node " + node.character + " is not the root");
            if(node == node.parent.c0)
                code = "0" + code;
            if(node == node.parent.c1)
                code = "1" + code;
            node = node.parent;
        }
        return code;
    }
}

class TreeNode {
    char character;
    int freq;
    String code;
    TreeNode parent;
    TreeNode c0;
    TreeNode c1;

    public TreeNode(char character, int freq){
        this.character = character;
        this.freq = freq;
        String code = new String();
        c0 = null;
        c1 = null;
        parent = null;
    }
}

class TreeNodeComp implements Comparator<TreeNode>{
    public int compare(TreeNode a, TreeNode b){
        return a.freq - b.freq;
    }
}