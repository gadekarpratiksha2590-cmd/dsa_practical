## Problem Statement
Given a binary tree, write a C++ program to validate if it is a Full Binary Tree (where every node has either 0 or 2 children). The program must perform at least two validation tests on different tree structures
## Approach

A binary tree is a Full Binary Tree if every node has either 0 or 2 children. The program uses a recursive function to traverse the tree: if a node is null, it returns true; if a node has exactly one child, it returns false; otherwise, it recursively checks both its left and right subtrees.
## Complexity Analysis
• Time Complexity: \(\mathcal{O}(N)\), where N is the total number of nodes in the binary tree. The program visits every node exactly once to verify its children.

• Space Complexity: \(\mathcal{O}(H)\), where H is the height of the tree. This space is consumed by the recursive call stack. In the worst-case scenario of a skewed tree, it becomes \(\mathcal{O}(N)\), while for a balanced tree, it is \(\mathcal{O}(\log N)\).
## Conclusion
• Diagnostic Capabilities: The modified implementation no longer just yields a plain boolean value; it isolates structural defects by exposing the precise node value causing the anomaly. 
• Edge Case Resilience: Validations confirmed that empty strings and single-node structures naturally yield valid configurations as they pass the zero-child requirement constraint. • Analytical Clarity: Through explicit counters, the application transparently details tree structural weights, facilitating easier visual mapping between binary definitions and actual memory footprints.
