# Full Binary Tree Validation
## Problem Statement 
Full Binary Tree Validation Write a C++ program to determine whether a given binary tree is a full binary Tree which every nede has either zene or two children
## Approach

To validate a full binary tree, we can use a recursive Depth-First Search (DFS) approach. We evaluate the tree node by node based on three logical rules:
1. Empty Tree Base Case: If the current node is NULL, it is technically a valid full binary tree.
2. Leaf Node Base Case: If a node has no children (both left and right are NULL), it satisfies the condition (0 children). Return true.
3. Internal Node Check: If a node has both children (left and right are NOT NULL), we must recursively check if both the left subtree and the right subtree are also full binary trees.
If a node has only one child (one is NULL and the other is not), the condition is broken, and we return false.
## Complexity analysis
Complexity Analysis

• Time Complexity: \(\mathcal{O}(N)\), where \(N\) is the total number of nodes in the binary tree. The algorithm visits each node exactly once.

• Space Complexity: \(\mathcal{O}(H)\), where \(H\) is the height of the tree. This space is used by the recursive call stack. In the worst-case scenario (a highly skewed tree), the complexity can become \(\mathcal{O}(N)\).
## Conclusion 
Structural Strictness: A full binary tree strictly disallows nodes with a single child. 
Efficiency: The recursive traversal visits each node exactly once, delivering an efficient (O(N)) runtime. 
Practical Use: This validation is vital in Huffman Coding and binary heap structural checks where complete or full node division properties must be enforced.
