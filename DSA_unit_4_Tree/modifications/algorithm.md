## Full Binary Tree Validation Algorithm
Step 1: Start the validation process. Initialize leafCount = 0, twoChildCount = 0, and violatingNode = -1 (to signify no violation found yet).

Step 2: Check if the tree is empty (root is NULL). If it is NULL, print that it is a valid Full Binary Tree with 0 nodes, and skip to Step 7.

Step 3: Traverse the tree using a recursive or level-order helper function starting from the root. For the current node:
Step 3 a: If the node is NULL, return to the parent call.
Step 3 b: If both left and right children are NULL (0 children), increment leafCount.
Step 3 c: If both left and right children exist (2 children), increment twoChildCount and continue traversing both subtrees.
Step 3 d: If only one child exists (left is NULL and right is not, or vice versa), check if violatingNode is still -1. If it is, store the current node's value into violatingNode to flag the first violation. Then, continue traversing the remaining child.

Step 4: Evaluate the final validation flag. If violatingNode == -1, mark the tree status as Valid, otherwise mark it as Invalid.

Step 5: Print the metrics collected for the tree: total leaf nodes, total 2-child nodes, and the violating node ID if applicable.

Step 6: Repeat Steps 1–5 for subsequent test cases (e.g., Test Case 1: Valid Full Tree, Test Case 2: Irregular Tree, Edge Cases: Single-Node, Empty Tree).

Step 7: End the program execution.
