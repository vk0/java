// Дано число N<106 и последовательность целых чисел из отрезка [−231..231] длиной N.

// Требуется построить бинарное дерево, заданное наивным порядком вставки.

// Т.е., при добавлении очередного числа K в дерево с корнем root, если root→Key ≤ K, то узел K добавляется в правое поддерево root; иначе в левое поддерево root.

// Выведите элементы в порядке post-order (снизу вверх), разделяя их пробелами.

// Sample Input:

// 3
// 2 1 3

// Sample Output:

// 1 2 3

#include <iostream>
#include <queue>
#include <stack>

struct BinaryNode
{
    int data;
    BinaryNode* left; // NULL, если нет.
    BinaryNode* right; // NULL, если нет.
};

void initBinaryNode(BinaryNode&, int);     // Инициализация элемента

typedef BinaryNode* pBinaryNode;            // Для передачи указателя по ссылке
void insertBinaryTree(pBinaryNode&, int);  // Вставка элемента в дерево

void traverseDFSDownUp(BinaryNode*);        // Обход снизу вверх
void traverseDFSUpDown(BinaryNode*);        // Обход сверху вниз
void traverseDFSLeftRight(BinaryNode*);     // Обход слева направо
void traverseBFS(BinaryNode*);              // Обход в ширину
void traverseDownUpWithoutRecursion(BinaryNode*); // Обход снизу вверх nonrecursion

int main()
{
    // N - количество элементов в дереве
    size_t N;
    std::cin >> N;

    // buf - число для добавления
    int buf;
    std::cin >> buf;

    // Зададим корень
    BinaryNode* node;
    node = new BinaryNode;
    initBinaryNode(*node, buf);

    // Вводим оставшиеся значения и добавляем в дерево
    for (size_t i = 1; i < N; ++i)
    {
        std::cin >> buf;
        insertBinaryTree(node, buf);
    }

    // Вывод дерева
   traverseDFSDownUp(node);
   //traverseDFSLeftRight(node);
//    traverseDFSUpDown(node);
//    traverseBFS(node);
    //traverseDownUpWithoutRecursion(node);

    return 0;
}

void initBinaryNode(BinaryNode& in, int data)
{
    in.data = data;
    in.left = NULL;
    in.right = NULL;
}

void insertBinaryTree(pBinaryNode& in, int data)
{
    // Рекурсивная вставка элемента в бинарное дерево заданное
    // наивным порядком вставки.

    if (in == NULL)
    {
        in = new BinaryNode;
        initBinaryNode(*in, data);
        return;
    }

    // Если новый ключ >= ,то помещаем его в правое поддерево, иначе в левое
    if (data >= in->data)
        insertBinaryTree(in->right, data);
    else
        insertBinaryTree(in->left, data);
}

void traverseDFSDownUp(BinaryNode* root)
{
    // Вывод элементов методом снизу вверх,
    // т.е. вначале посещаются левое и правое поддеревья, а затем узел.

    if (root == NULL)
        return;

    traverseDFSDownUp(root->left);
    traverseDFSDownUp(root->right);
    std::cout << root->data << " ";
}

void traverseDFSUpDown(BinaryNode* root)
{
    // вывод элементов методом сверху вниз,
    // т.е. вначале посещается узел, затем левое и правые поддеревья.

    if (root == NULL)
        return;

    std::cout << root->data << " ";
    traverseDFSUpDown(root->left);
    traverseDFSUpDown(root->right);
}

void traverseDFSLeftRight(BinaryNode* root)
{
    // Вывод элементов методом слева направо,
    // т.е. вначале посещается левое поддерево, затем узел и правое поддерево.

    if (root == NULL)
        return;

    traverseDFSLeftRight(root->left);
    std::cout << root->data << " ";
    traverseDFSLeftRight(root->right);
}

void traverseBFS(BinaryNode* root)
{
    // Вывод элементов методом обхода в ширину,
    // т.е. обходом вершин дерева по уровням (слоям), начиная от корня.

    std::queue<BinaryNode*> q;
    q.push(root);
    while(!q.empty())
    {
        BinaryNode* node = q.front();
        q.pop();

        std::cout << node->data << " ";

        if( node->left != NULL )
            q.push(node->left);

        if( node->right != NULL )
            q.push(node->right);
    }
}

void traverseDownUpWithoutRecursion(BinaryNode* root)
{
    // вывод элементов методом сверху вниз,
    // т.е. вначале посещается узел, затем левое и правые поддеревья.

    std::stack<BinaryNode*> one;
    std::stack<BinaryNode*> two;

    one.push(root);
    while(!one.empty())
    {
        BinaryNode* node = one.top();
        one.pop();
        two.push(node);

        if(node->left != NULL)
            one.push(node->left);

        if(node->right != NULL)
            one.push(node->right);
    }

    while(!two.empty())
    {
        std::cout << two.top()->data << " ";
        two.pop();
    }
}
