#include <iostream>
using namespace std;

template <typename T>
struct BinaryTreeNode {
    T data;
    shared_ptr<BinaryTreeNode<T>> left, right;
};

typedef shared_ptr<BinaryTreeNode<int>> Node;

void PreOrderTraversal(Node &root){
    if (root) {
        cout << root->data << endl;
        PreOrderTraversal(root->left);
        PreOrderTraversal(root->right);
    }
}

void PostOrderTraversal(Node &root){
    if (root) {
        PostOrderTraversal(root->left);
        PostOrderTraversal(root->right);
        cout << root->data << endl;
    }
}

void InOrderTraversal(Node &root){
    if (root) {
        InOrderTraversal(root->left);
        cout << root->data << endl;
        InOrderTraversal(root->right);
    }
}

int height(Node &root){
    return !root ? 0 : 1  + max(height(root->left), height(root->right));
}


void sumBST(Node &root, int L, int R, int &ans){
    if (root==NULL) return;
    int x = root->data;
    if (L<=x && x>=R) ans += x;
    if (L<x) sumBST(root->left, L, R, ans);
    if (R>x) sumBST(root->right, L, R, ans);
}

int rangeSumBST(Node &root, int L, int R){
    int ans = 0;
    sumBST(root, L, R, ans); 
    return ans;
}

Node trimBST(Node root, int L, int R){
    if (!root) return root;
    if (root->data>R) return trimBST(root->left, L, R);
    if (root->data<L) return trimBST(root->right, L, R); 
    root->left=trimBST(root->left,L,R);
    root->right=trimBST(root->right,L,R);
    return root;
}

int main(){
    return 0;
}