// Напишите АВЛ-дерево.
// Дана последовательность команд добавления или удаления натуральных чисел в АВЛ-дерево. Команда добавления числа A задается положительным числом A, команда удаления числа A задается отрицательным числом “-A”. Требуется вывести высоту АВЛ-дерева после выполнения всех команд.

// Предполагается, что во входных данных нет ситуации, при которой добавляется элемент А, уже присутствующий в дереве.

// Sample Input:

// 2 4 6 -2

// Sample Output:

// 2

#include <iostream>
#include <cstdio>
#include <stack>

struct CNode {
    int Key;
    int Height;
    CNode* Left;
    CNode* Right;

    CNode(int key) : Key(key), Height(1), Left(0), Right(0) {}
};

int Height(CNode *node) {
    return (node == NULL) ? 0 : node->Height;
}

int BalanceFactor(CNode *node) {
    return Height(node->Right) - Height(node->Left);
}

void FixHeight(CNode *node) {
    int HL = Height(node->Left);
    int HR = Height(node->Right);

    node->Height = (HL > HR) ? HL + 1 : HR + 1;
}

CNode* RotateRight(CNode *p) {
    CNode *new_node = p->Left;

    p->Left = new_node->Right;
    new_node->Right = p;

    FixHeight(p);
    FixHeight(new_node);

    return new_node;
}

CNode* RotateLeft(CNode *p) {
    CNode *new_node = p->Right;

    p->Right = new_node->Left;
    new_node->Left = p;

    FixHeight(p);
    FixHeight(new_node);

    return new_node;
}

CNode* Balance(CNode *p) {
    FixHeight(p);

    if (BalanceFactor(p) < -1) {
        if (BalanceFactor(p->Left) > 0) {
            p->Left = RotateLeft(p->Left);
        }

        return RotateRight(p);
    } else if (BalanceFactor(p) > 1) {
        if (BalanceFactor(p->Right) < 0) {
            p->Right = RotateRight(p->Right);
        }

        return RotateLeft(p);
    }

    return p;
}

CNode* Insert(CNode *p, int key) {
    if (p == NULL) {
        return new CNode(key);
    }

    if (key < p->Key) {
        p->Left = Insert(p->Left, key);
    } else {
        p->Right = Insert(p->Right, key);
    }

    return Balance(p);
}

CNode* FindMin(CNode *p) {
    return (p->Left == NULL) ? p : FindMin(p->Left);
}

CNode* RemoveMin(CNode *p) {
    if (p->Left == 0) {
        return p->Right;
    }

    p->Left = RemoveMin(p->Left);

    return Balance(p);
}

CNode* Remove(CNode *p, int key) {
    if (p == 0) return 0;

    if (key == p->Key) {
        CNode* left = p->Left;
        CNode* right = p->Right;
        delete p;
        if (right == 0) return left;
        CNode* min = FindMin(right);
        min->Right = RemoveMin(right);
        min->Left = left;
        return Balance(min);
    }

    if (key < p->Key) {
        p->Left = Remove(p->Left, key);
    } else {
        p->Right = Remove(p->Right, key);
    }

    return Balance(p);
}

void Delete(CNode *node) {
    if (!node) return;

    Delete(node->Left);
    Delete(node->Right);

    delete node;
}

int main() {
    CNode* root = 0;

    while (true) {
        int key = 0;
        std::cin >> key;

        if( std::cin.eof() ) {
            break;
        }

        if( key >= 0 ) {
            root = Insert(root, key);
        } else {
            root = Remove(root, -key);
        }
    }

    std::cout << Height(root);

    Delete(root);

    return 0;
}
