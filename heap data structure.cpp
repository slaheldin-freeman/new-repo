#include <iostream>
using namespace std;
struct gammal {
    int num;
    gammal* left, * right;
    gammal(int n) {
        num = n;
        left = NULL;
        right = NULL;
    }
};
int count(gammal* g) {
    if (g == NULL)
        return 0;
    int x = 1 + count(g->left);
    int y = 1 + count(g->right);
    if (x < y)
        return x;
    return y;
}
gammal* insert(gammal* g, int n) {
    if (g == NULL)
        return g = new gammal(n);
    int x = count(g->left);
    int y = count(g->right);
    if (x < y)
        g->left = insert(g->left, n);
    else
        g->right = insert(g->right, n);
    return g;
}
void show(gammal* g, int p) {
    if (g == NULL)
        return;
    cout << p << " --> " << g->num << endl;
    show(g->left, g->num);
    show(g->right, g->num);
}
bool checkBinary(gammal* g) {
    if (g == NULL)
        return true;
    if (g->left == NULL && g->right == NULL)
        return true;
    if (g->left != NULL && g->right != NULL)
        return checkBinary(g->left) && checkBinary(g->right);
    return false;
}
bool checkMinHeap(gammal* g) {
    if (g == NULL)
        return true;
    if (g->left == NULL && g->right == NULL)
        return true;
    if (g->left->num >= g->num && g->right->num >= g->num)
        return checkMinHeap(g->left) && checkMinHeap(g->right);
    return false;
}
bool checkMaxHeap(gammal* g) {
    if (g == NULL)
        return true;
    if (g->left == NULL && g->right == NULL)
        return true;
    if (g->left->num <= g->num && g->right->num <= g->num)
        return checkMaxHeap(g->left) && checkMaxHeap(g->right);
    return false;
}
int main() {
    gammal* g = NULL;
    int n;
    do {
        cout << "Enter a number: ";
        cin >> n;
        if (n)
            g = insert(g, n);
    } while (n);
    show(g, 0);
    if (checkBinary(g))
        cout << "Complete Binary" << endl;
    if (checkMinHeap(g))
        cout << "Min-Heap" << endl;
    if (checkMaxHeap(g))
        cout << "Max-Heap" << endl;
}
