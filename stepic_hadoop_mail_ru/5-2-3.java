// Реализуйте алгоритм Дейкстры поиска кратчайшего пути в графе.

// Входные данные: В первой строке указаны два числа: число вершин и число ребер графа. Далее идут строки с описанием ребер. Их количество равно числу ребер. В каждой строке указаны 3 числа: исходящая вершина, входящая вершина, вес ребра. В последней строке указаны 2 номера вершины: начальная и конечная вершина, кратчайший путь между которыми нужно найти.

// Выходные данные: минимальное расстояние между заданными вершинами. Если пути нет, то нужно вернуть -1.

// Пример:

// [Image: https://ucarecdn.com/56a66a36-361d-4b6b-836f-9a18e751eddd/]

// Sample Input:

// 4 8
// 1 2 6
// 1 3 2
// 1 4 10
// 2 4 4
// 3 1 5
// 3 2 3
// 3 4 8
// 4 2 1
// 1 4

// Sample Output:

// 9

import java.util.*;

class Vertex implements Comparable<Vertex> {
    public final String name;
    public final List<Edge> adjacencies = new LinkedList<>();
    public double minDistance = Double.POSITIVE_INFINITY;
    public Vertex previous;

    public Vertex(String name) {
        this.name = name;
    }

    @Override
    public int compareTo(Vertex other) {
        return Double.compare(minDistance, other.minDistance);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        Vertex vertex = (Vertex) o;

        return name.equals(vertex.name);
    }

    @Override
    public int hashCode() {
        return name.hashCode();
    }

    @Override
    public String toString() {
        return name;
    }
}

class Edge {
    public final Vertex target;
    public final double weight;

    public Edge(Vertex target, double weight) {
        this.target = target;
        this.weight = weight;
    }
}

public class Main {

    public static void computePaths(Vertex source) {
        source.minDistance = 0;
        PriorityQueue<Vertex> vertexQueue = new PriorityQueue<>();
        vertexQueue.add(source);

        while (!vertexQueue.isEmpty()) {
            Vertex u = vertexQueue.poll();

            for (Edge e : u.adjacencies) {
                Vertex v = e.target;
                double weight = e.weight;
                double distanceThroughU = u.minDistance + weight;
                if (distanceThroughU < v.minDistance) {
                    vertexQueue.remove(v);

                    v.minDistance = distanceThroughU;
                    v.previous = u;
                    vertexQueue.add(v);
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] tokens = scanner.nextLine().split(" ");
        int verticesNumber = Integer.parseInt(tokens[0]);
        int edgesNumber = Integer.parseInt(tokens[1]);

        Map<String, Vertex> vertices = new HashMap<>(verticesNumber);

        for (int i = 0; i < edgesNumber; i++) {
            tokens = scanner.nextLine().split(" ");

            Vertex vertexOut;
            if (vertices.containsKey(tokens[0])) {
                vertexOut = vertices.get(tokens[0]);
            } else {
                vertexOut = new Vertex(tokens[0]);
                vertices.put(tokens[0], vertexOut);
            }

            Vertex vertexIn;
            if (vertices.containsKey(tokens[1])) {
                vertexIn = vertices.get(tokens[1]);
            } else {
                vertexIn = new Vertex(tokens[1]);
                vertices.put(tokens[1], vertexIn);
            }

            int weight = Integer.parseInt(tokens[2]);

            vertexOut.adjacencies.add(new Edge(vertexIn, weight));
        }

        tokens = scanner.nextLine().split(" ");
        Vertex source = vertices.get(tokens[0]);
        Vertex target = vertices.get(tokens[1]);

        int result = -1;

        if (source != null && target != null)  {
            computePaths(source);

            if (target.minDistance != Double.POSITIVE_INFINITY) {
                result = (int) target.minDistance;
            }
        }

        System.out.println(result);
    }
}