## Program
#include <iostream>
#include <vector>
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

struct TreeStats {
    int zeroChildCount = 0;
    int twoChildCount = 0;
    int firstViolatingNode = -1; 
};

void validateTreeHelper(Node* root, TreeStats& stats) {
    if (root == nullptr) {
        return;
    }

    if (root->left == nullptr && root->right == nullptr) {
        stats.zeroChildCount++;
        return;
    }

    if (root->left != nullptr && root->right != nullptr) {
        stats.twoChildCount++;
        validateTreeHelper(root->left, stats);
        validateTreeHelper(root->right, stats);
        return;
    }

    if (stats.firstViolatingNode == -1) {
        stats.firstViolatingNode = root->data; 
    }

    if (root->left != nullptr) {
        validateTreeHelper(root->left, stats);
    } else {
        validateTreeHelper(root->right, stats);
    }
}

void runValidationTest(string testName, Node* root) {
    cout << "--- " << testName << " ---" << endl;

    if (root == nullptr) {
        cout << "Result: Valid Full Binary Tree (Edge Case: Empty Tree)" << endl;
        cout << "Nodes with 0 children: 0" << endl;
        cout << "Nodes with 2 children: 0" << endl;
        cout << "-------------------------------------------\n" << endl;
        return;
    }

    TreeStats stats;
    validateTreeHelper(root, stats);

    if (stats.firstViolatingNode == -1) {
        cout << "Result: The tree is a VALID Full Binary Tree." << endl;
    } else {
        cout << "Result: The tree is NOT a Full Binary Tree." << endl;
        cout << "First Violating Node ID (has 1 child): " << stats.firstViolatingNode << endl;
    }

    cout << "Nodes with 0 children (Leaves): " << stats.zeroChildCount << endl;
    cout << "Nodes with 2 children (Internal): " << stats.twoChildCount << endl;
    cout << "-------------------------------------------\n" << endl;
}

int main() {
    Node* emptyTree = nullptr;
    runValidationTest("Test A: Empty Tree", emptyTree);

    Node* singleNodeTree = new Node(10);
    runValidationTest("Test B: Single-Node Tree", singleNodeTree);

    Node* validTree = new Node(1);
    validTree->left = new Node(2);
    validTree->right = new Node(3);
    validTree->left->left = new Node(4);
    validTree->left->right = new Node(5);
    runValidationTest("Test 1: Valid Full Binary Tree", validTree);

    Node* irregularTree = new Node(50);
    irregularTree->left = new Node(30);
    irregularTree->right = new Node(70);
    irregularTree->right->left = new Node(60);
    irregularTree->right->right = new Node(80);
    irregularTree->left->left = new Node(20);

    irregularTree->left->left->right = new Node(25); 

    runValidationTest("Test 2: Irregular/Invalid Binary Tree", irregularTree);

    return 0;
}
