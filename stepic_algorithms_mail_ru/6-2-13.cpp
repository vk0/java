// Дано число N<106 и последовательность пар целых чисел из [−231..231] длиной N.

// Постройте декартово дерево из N узлов, характеризующихся парами чисел {Xi,Yi}.

// Каждая пара чисел {Xi,Yi} определяет ключ Xi и приоритет Yi в декартовом дереве.

// Добавление узла в декартово дерево выполняйте второй более эффективной версией алгоритма:

// При добавлении узла (x, y) выполняйте спуск по ключу до узла P с меньшим приоритетом. Затем разбейте найденное поддерево по ключу x так, чтобы в первом поддереве все ключи меньше x, а во втором больше или равны x. Получившиеся два дерева сделайте дочерними для нового узла (x, y). Новый узел вставьте на место узла P.

// Построите также наивное дерево поиска по ключам Xi.

// Вычислите разницу глубин наивного дерева поиска и декартового дерева.

// Sample Input:

// 10
// 5 11
// 18 8
// 25 7
// 50 12
// 30 30
// 15 15
// 20 10
// 22 5
// 40 20
// 45 9

// Sample Output:

// 2

#include <iostream>
#include <stack>

template <typename data_t> struct tree_node_t {
    data_t data;
    tree_node_t *left;
    tree_node_t *right;

    tree_node_t(data_t _data) : data(_data), left(NULL), right(NULL) { }

    tree_node_t* find(data_t data) {
        tree_node_t *current_node = this;

        while (current_node != NULL) {
            if (current_node->data > data) {
                if (current_node->left != NULL) {
                    current_node = current_node->left;
                } else {
                    return current_node;
                }
            } else if (current_node->data < data) {
                if (current_node->right != NULL) {
                    current_node = current_node->right;
                } else {
                    return current_node;
                }
            } else {
                return current_node;
            }
        }

        return NULL;
    }

    template <typename func_t>
    void traverse(func_t &foo) {
        std::stack<tree_node_t *> s;
        tree_node_t *node = this;

        for (;;) {
            foo(node);

            if (node->left != NULL) {
                if (node->right != NULL) s.push(node->right);
                node = node->left;
            } else if (node->right != NULL) {
                node = node->right;
            } else {
                if (!s.size()) break;

                node = s.top();
                s.pop();
            }
        }

        std::cout << std::endl;
    }
};

template <typename data_t> struct tree_t {
    tree_node_t<data_t> *root;

    tree_t() : root(NULL) { }

    void add(data_t data) {
        tree_node_t<data_t> *node = root->find(data);

        if (node == NULL) {
            root = new tree_node_t<data_t>(data);
        } else if (node->data >= data) {
            node->left = new tree_node_t<data_t>(data);
        } else {
            node->right = new tree_node_t<data_t>(data);
        }
    }

    template <typename func_t>
    void traverse(func_t &foo) {
        if (root == NULL) return;

        root->traverse<func_t>(foo);
    }
};

struct treap_node_t {
    int key;
    int priority;
    treap_node_t* left;
    treap_node_t* right;

    treap_node_t(int key, int priority) : key(key), priority(priority), left(NULL), right(NULL) { }
};

struct treap_t {
    treap_node_t *root;

    treap_t() : root(NULL) { }
};

treap_node_t* merge(treap_node_t *left, treap_node_t *right) {
    if (left == NULL || right == NULL) {
        return (left == NULL) ? right : left;
    }

    if (left->priority > right->priority) {
        left->right = merge(left->right, right);
        return left;
    } else {
        right->left = merge(left, right->left);
        return right;
    }
}

void split(treap_node_t *currentNode, int key, treap_node_t *&left, treap_node_t *&right) {
    if (currentNode == NULL) {
        left = NULL;
        right = NULL;
    } else if (currentNode->key <= key) {
        split(currentNode->right, key, currentNode->right, right);
        left = currentNode;
    } else {
        split(currentNode->left, key, left, currentNode->left);
        right = currentNode;
    }
}

void add(treap_node_t *&root, int key, int priority) {
    treap_node_t *node = new treap_node_t(key, priority);
    treap_node_t *splitLeft = NULL;
    treap_node_t *splitRight = NULL;
    split(root, key, splitLeft, splitRight);
    root = merge(merge(splitLeft, node), splitRight);
}

treap_node_t* delete_node(treap_node_t *root, int key) {
    treap_node_t *splitLeft = NULL;
    treap_node_t *splitRight = NULL;
    split(root, key - 1, splitLeft, splitRight);
    treap_node_t *splitRightLeft = NULL;
    treap_node_t *splitRightRight = NULL;
    split(splitRight, key, splitRightLeft, splitRightRight);
    delete splitRightLeft;
    return merge(splitLeft, splitRightRight);
}

template <typename node_t>
int depth_recursive(node_t *node, int &max_depth, int current_depth = 1) {
    if (node == NULL) return 0;

    if (current_depth > max_depth) max_depth = current_depth;
    if (node->left != NULL) depth_recursive(node, max_depth, current_depth + 1);
    if (node->right != NULL) depth_recursive(node, max_depth, current_depth + 1);

    return max_depth;
}

template <typename node_t>
int depth(node_t *node) {
    if (node == NULL) return 0;

    std::stack<node_t *> s;
    std::stack<int> depths;

    int current_depth = 0;
    int max_depth = 0;

    for (;;) {
        ++current_depth;

        if (node->left != NULL) {
            if (node->right != NULL) { s.push(node->right); depths.push(current_depth); }
            node = node->left;
        } else if (node->right != NULL) {
            node = node->right;
        } else {
            if (current_depth > max_depth) max_depth = current_depth;
            if (!s.size()) break;

            node = s.top();
            s.pop();

            current_depth = depths.top();
            depths.pop();
        }
    }

    return max_depth;
}

int main() {
    size_t n;

    std::cin >> n;

    tree_t<int> tree;
    treap_t treap;

    for (size_t i = 0; i < n; ++i) {
        int key, priority;

        std::cin >> key >> priority;

        tree.add(key);
        add(treap.root, key, priority);
    }

    std::cout << (depth(tree.root) - depth(treap.root));
}
