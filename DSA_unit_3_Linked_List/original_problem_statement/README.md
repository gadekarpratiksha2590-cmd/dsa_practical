## Problem Statement 
Design and implement a Singly Linked List in C++ to simulate a Supply Chain Journey Tracker (Mini-Blockchain). The system tracks a high-value product (such as organic medicine or luxury electronics) from its manufacturing origin to the final customer. Each state transition is recorded as a "Block" (node) in the chain containing data like location, timestamp, custodian name, and verification state.
## Approach
- Data Integrity Simulation: Because it's a singly linked list, you can only move forward in time. 
- You cannot change a past block without altering pointers, effectively mimicking blockchain immutability.
- Memory Management: The custom destructor cleans up heap allocation sequentially (delete current), ensuring zero memory leaks when the simulation stops.
## Time Complexity
- Insertion at Beginning: O(1) — Fast initialization.
- Insertion at End / Searching: O(N) — Linear operations proportional to journey length.


## Conclusion:
Using a dynamic Singly Linked List, a decentralized-style product journey tracker was successfully engineered. Dynamic node insertion handles continuous real-time ledger updates, while sequential traversal allows verification audits across any step of the supply chain network seamlessly.
