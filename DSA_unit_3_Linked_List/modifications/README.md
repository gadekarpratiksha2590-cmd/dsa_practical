## Problem Statement
Design and implement a dynamic Supply Chain Journey Tracker and Recall System using Stack and Queue data structures in C++. 
• The Forward Journey Tracker (Queue): High-value products (like organic medicines or luxury electronics) transition forward from manufacturing through checkpoints sequentially. These verification states must be recorded in a First-In, First-Out (FIFO) order using a Queue. 
• The Reverse Recall System (Stack): In case of contamination, defect, or safety hazards, a product must be rolled back or traced in reverse custody from its current position back to its origin. This reverse-tracking sequence must follow a Last-In, First-Out (LIFO) structural rollback using a Stack.
## Approach
This system uses a Queue (FIFO) to log forward logistics checkpoints chronologically from manufacturing to delivery, ensuring an accurate tracking timeline. In case of contamination, a Stack (LIFO) handles reverse logistics by immediately backtracking custody from the most recent location back to the origin point.Dynamic memory allocation links these operations seamlessly to ensure secure, real-time tracking and rapid hazard containment.
## Complexity analysis
Time Complexity
• Add Checkpoint (Enqueue): \(O(1)\)
	• Reason: Nodes are appended directly at the rear pointer, taking constant time regardless of list size.
• Audit Journey (Queue Traversal): \(O(n)\)
	• Reason: The system must visit all \(n\) nodes sequentially from front to rear to print the full history.
• Trigger Recall (Dequeue \(\rightarrow \) Push): \(O(1)\)
	• Reason: It shifts a node from the front of the queue to the top of the stack by updating immediate pointer addresses.
• Execute Traceback Plan (Pop Summary): \(O(n)\)
	• Reason: It pops and deletes every single node one by one until the stack is entirely cleared back to the source origin.
Space Complexity
• Total Memory Footprint: \(O(n)\)
	• Reason: Memory allocation scales strictly linearly with the number of checkpoints (\(n\)) created dynamically in the system.


## Conclusion
By refactoring the single linked list into Stacks and Queues, real-world asset safety verification is significantly enhanced. The chronological distribution path maps perfectly onto the Queue (FIFO) structure, while emergency containment routines leverage the Stack (LIFO) model to unwind hands-on operations directly back to structural raw entry origins.
