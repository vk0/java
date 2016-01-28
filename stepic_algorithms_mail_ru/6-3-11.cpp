// В одной военной части решили построить в одну шеренгу по росту. Т.к. часть была далеко не образцовая, то солдаты часто приходили не вовремя, а то их и вовсе приходилось выгонять из шеренги за плохо начищенные сапоги. Однако солдаты в процессе прихода и ухода должны были всегда быть выстроены по росту – сначала самые высокие, а в конце – самые низкие. За расстановку солдат отвечал прапорщик, который заметил интересную особенность – все солдаты в части разного роста. Ваша задача состоит в том, чтобы помочь прапорщику правильно расставлять солдат, а именно для каждого приходящего солдата указывать, перед каким солдатом в строе он должен становится. Требуемая скорость выполнения команды - O(logn).

// Формат входных данных.

// Первая строка содержит число N – количество команд (1 ≤ N ≤ 30 000). В каждой следующей строке содержится описание команды: число 1 и X если солдат приходит в строй (X – рост солдата, натуральное число до 100 000 включительно) и число 2 и Y если солдата, стоящим в строе на месте Y надо удалить из строя. Солдаты в строе нумеруются с нуля.

// Формат выходных данных.
// На каждую команду 1 (добавление в строй) вы должны выводить число K – номер позиции, на которую должен встать этот солдат (все стоящие за ним двигаются назад).

// Sample Input:

// 5
// 1 100
// 1 200
// 1 50
// 2 1
// 1 150

// Sample Output:

// 0 0 2 1

#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>

struct CNode {
    int Key;
    int Height;
    int Nodes;
    CNode *Left;
    CNode *Right;

    CNode(int key) : Key(key), Height(1), Nodes(1), Left(0), Right(0) {}
};

int Height(CNode *node) {
    return (node == NULL) ? 0 : node->Height;
}

int Nodes(CNode *node) {
    return (node == NULL) ? 0 : node->Nodes;
}

int BalanceFactor(CNode *node) {
    return Height(node->Right) - Height(node->Left);
}

void FixHeight(CNode *node) {
    int HL = Height(node->Left);
    int HR = Height(node->Right);

    node->Height = (HL > HR) ? HL + 1 : HR + 1;
}

void FixNodes(CNode *node) {
    int nodes_left = Nodes(node->Left);
    int nodes_right = Nodes(node->Right);

    node->Nodes = nodes_left + nodes_right + 1;
}

CNode* RotateRight(CNode *p) {
    CNode *new_node = p->Left;

    p->Left = new_node->Right;
    new_node->Right = p;

    FixNodes(p);
    FixNodes(new_node);

    FixHeight(p);
    FixHeight(new_node);

    return new_node;
}

CNode* RotateLeft(CNode *p) {
    CNode *new_node = p->Right;

    p->Right = new_node->Left;
    new_node->Left = p;

    FixNodes(p);
    FixNodes(new_node);

    FixHeight(p);
    FixHeight(new_node);

    return new_node;
}

CNode* Balance(CNode *p) {
    FixHeight(p);

    if (BalanceFactor(p) == -2) {
        if (BalanceFactor(p->Left) > 0) {
            p->Left = RotateLeft(p->Left);
        }

        return RotateRight(p);
    } else if (BalanceFactor(p) == 2) {
        if (BalanceFactor(p->Right) < 0) {
            p->Right = RotateRight(p->Right);
        }

        return RotateLeft(p);
    }

    return p;
}

CNode* Insert(CNode *p, int key, int &position) {
    if (p == NULL) {
        return new CNode(key);
    }

    ++(p->Nodes);

    if (key < p->Key) {
        position += Nodes(p->Right) + 1;
        p->Left = Insert(p->Left, key, position);
    } else {
        p->Right = Insert(p->Right, key, position);
    }

    return Balance(p);
}

CNode* FindMin(CNode *p) {
    return (p->Left == NULL) ? p : FindMin(p->Left);
}

CNode* RemoveMin(CNode *p) {
    if (p->Left == NULL) {
        return p->Right;
    }

    p->Left = RemoveMin(p->Left);
    --p->Nodes;

    return Balance(p);
}

CNode* Remove(CNode *p, int position) {
    if (p == NULL) return NULL;
    if (position >= p->Nodes) return p;

    int current = 0;
    std::stack<CNode *> nodes;

    while (true) {
        int nodes_right = Nodes(p->Right);

        if (position - current > nodes_right) {
            nodes.push(p);
            p = p->Left;
            current += nodes_right + 1;
        } else if (position - current < nodes_right) {
            if (p->Right != NULL) {
                nodes.push(p);
                p = p->Right;
            } else {
                break;
            }
        } else {
            CNode *left = p->Left;
            CNode *right = p->Right;
            int key = p->Key;

            delete p;

            if (right == NULL) {
                if (left == NULL) {
                    if (!nodes.empty()) {
                        p = nodes.top();
                        nodes.pop();

                        if (p->Key > key) {
                            p->Left = NULL;
                        } else {
                            p->Right = NULL;
                        }

                        --p->Nodes;
                    } else {
                        return NULL;
                    }
                } else {
                    p = left;
                }
            } else {
                CNode* min = FindMin(right);
                min->Right = RemoveMin(right);
                min->Left = left;
                FixNodes(min);
                p = Balance(min);
            }

            break;
        }
    }

    while (!nodes.empty()) {
        CNode *node = nodes.top();
        --node->Nodes;

        if (node->Key > p->Key) {
            node->Left = p;
        } else {
            node->Right = p;
        }

        p = Balance(node);
        nodes.pop();
    }

    return p;
}

void Delete(CNode *node) {
    if (!node) return;

    Delete(node->Left);
    Delete(node->Right);

    delete node;
}

int main() {
    int n;

    std::cin >> n;

    CNode* root = NULL;
    std::vector<int> result;

    int type, value, position;

    for (int i = 0; i < n; ++i) {
        std::cin >> type;

        if (type == 1) {
            position = 0;

            std::cin >> value;

            root = Insert(root, value, position);
            result.push_back(position);
        } else if (type == 2) {
            std::cin >> value;
            root = Remove(root, value);
        }
    }

    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }

    Delete(root);

    return 0;
}
