## Full Binary Tree Validation Algorithm
Follow these sequential execution steps to validate if a binary tree adheres to the constraints of a Full Binary Tree (where every node has either (0) or (2) children).

Step 1: Initiation Start the validation process by passing the root node of the binary tree to the validation function.

Step 2: Base Case (Empty Tree) Check if the current node is NULL. If it is NULL, return true (an empty tree is structurally considered a valid full binary tree).

Step 3: Base Case (Leaf Node) Check if the current node is a leaf node. If both the left child and right child are NULL, return true.

Step 4: Recursive Verification (Two Children) If both the left child and right child exist, recursively call the verification routine across both structural subtrees:

Step 4 a: Evaluate the status of the left child.
Step 4 b: Evaluate the status of the right child.
Step 4 c: Return true if both recursive evaluations return true; otherwise, evaluate to false.
Step 5: Trap Violation (Single-Child Case) If the node fails the structural conditions outlined in Steps 2, 3, and 4, it implies the node possesses exactly one child. Return false.

Step 6: Termination End execution operations and bubble up the final boolean outcome to the main driver pipeline.
