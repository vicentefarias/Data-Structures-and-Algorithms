#include <iostream>
#include <memory>
using namespace std;
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

// Function to create a sample BST
Node createSampleBST() {
    Node root = make_shared<BinaryTreeNode<int>>(BinaryTreeNode<int>{10, nullptr, nullptr});
    root->left = make_shared<BinaryTreeNode<int>>(BinaryTreeNode<int>{5, nullptr, nullptr});
    root->right = make_shared<BinaryTreeNode<int>>(BinaryTreeNode<int>{15, nullptr, nullptr});
    root->left->left = make_shared<BinaryTreeNode<int>>(BinaryTreeNode<int>{3, nullptr, nullptr});
    root->left->right = make_shared<BinaryTreeNode<int>>(BinaryTreeNode<int>{7, nullptr, nullptr});
    root->right->right = make_shared<BinaryTreeNode<int>>(BinaryTreeNode<int>{18, nullptr, nullptr});
    return root;
}

// Function to test PreOrderTraversal, PostOrderTraversal, and InOrderTraversal
void testTraversals(Node &root) {
    cout << "Pre-order traversal:" << endl;
    PreOrderTraversal(root);

    cout << "Post-order traversal:" << endl;
    PostOrderTraversal(root);

    cout << "In-order traversal:" << endl;
    InOrderTraversal(root);
}

// Function to test height of the tree
void testHeight(Node &root) {
    int treeHeight = height(root);
    cout << "Height of the tree: " << treeHeight << endl;
}

// Function to test rangeSumBST
void testRangeSumBST(Node &root) {
    int L = 5, R = 15;
    int sum = rangeSumBST(root, L, R);
    cout << "Sum of values in the BST between " << L << " and " << R << ": " << sum << endl;
}

// Function to test trimBST
void testTrimBST(Node &root) {
    int L = 5, R = 15;
    Node trimmedRoot = trimBST(root, L, R);
    cout << "In-order traversal of the trimmed BST between " << L << " and " << R << ":" << endl;
    InOrderTraversal(trimmedRoot);
}

int main() {
    Node root = createSampleBST();

    // Test traversals
    testTraversals(root);

    // Test height
    testHeight(root);

    // Test rangeSumBST
    testRangeSumBST(root);

    // Test trimBST
    testTrimBST(root);

    return 0;
}
