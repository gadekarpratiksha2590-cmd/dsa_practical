## Program 
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

bool isFullBinaryTree(Node* root) {

    if (root == nullptr) {
        return true;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return true;
    }

    if (root->left && root->right) {
        return isFullBinaryTree(root->left) && isFullBinaryTree(root->right);
    }

    return false;
}

int main() {
    /* 
          1
        /   \
       2     3
      / \
     4   5
     Valid Full Binary Tree Example
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    if (isFullBinaryTree(root)) {
        cout << "The tree is a Full Binary Tree." << endl;
    } else {
        cout << "The tree is NOT a Full Binary Tree." << endl;
    }

    /* 
          1
        /   \
       2     3
      / 
     4   
     Invalid Full Binary Tree Example (Node 2 has only 1 child)
    */
    Node* invalidRoot = new Node(1);
    invalidRoot->left = new Node(2);
    invalidRoot->right = new Node(3);
    invalidRoot->left->left = new Node(4); 

    if (isFullBinaryTree(invalidRoot)) {
        cout << "The invalidRoot tree is a Full Binary Tree." << endl;
    } else {
        cout << "The invalidRoot tree is NOT a Full Binary Tree." << endl;
    }

    return 0;
}
