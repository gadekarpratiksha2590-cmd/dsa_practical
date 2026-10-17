### Supply Chain Logistical Tracking Algorithm

---

#### A. Forward Queue Operations (Enqueue - Add Checkpoint)
*   **Step 1:** **Allocate Memory:** Create a new dynamic block node containing data fields (`location`, `custodian`, `timestamp`) along with a `next` pointer.
*   **Step 2:** **Initialize Pointer:** Set the `next` pointer of this new node to `NULL`.
*   **Step 3:** **Check Initial State:** Evaluate if the Queue is currently empty (`Rear == NULL`).
    *   **Step 3a:** If **True**, set both the `Front` and `Rear` pointers to the new node.
    *   **Step 3b:** If **False**, link the current `Rear->next` to the new node, and then update the `Rear` pointer to point to the new node.
*   **Step 4:** **Complete Operation:** Exit the Enqueue sequence.

---

#### B. Forward Journey Auditing (Display Queue)
*   **Step 1:** **Verify Existence:** Check if the `Front` pointer is equal to `NULL`.
    *   **Step 1a:** If **True**, display the error message: `"No active forward journey path records found."` and skip directly to **Step 4**.
*   **Step 2:** **Initialize Traversal:** Declare a temporary tracking pointer named `temp` and point it to the current `Front` position.
*   **Step 3:** **Loop Evaluation:** While `temp` is not equal to `NULL`, execute the following actions:
    *   **Step 3a:** Display the checkpoint details stored within the `temp` node.
    *   **Step 3b:** Advance the pointer by setting `temp = temp->next`.
*   **Step 4:** **Complete Operation:** Terminate the display routine.

---

#### C. Reverse Recall Action (Transfer Front of Queue to Stack - Push)
*   **Step 1:** **Evaluate Forward Track:** Initiate the Dequeue process by checking if `Front == NULL` (Queue is empty). If it is empty, abort the action.
*   **Step 2:** **Extract & Remove:** Extract the checkpoint information from the node at `Front`, then update the queue pointer by setting `Front = Front->next`. If `Front` becomes `NULL`, set `Rear = NULL` as well.
*   **Step 3:** **Allocate Stack Node:** Store the newly dequeued checkpoint information into a fresh Stack node memory allocation.
*   **Step 4:** **Link to Stack:** Set the `next` pointer of this `newStackNode` to point to the current `Top` node of the stack (`newStackNode->next = Top`).
*   **Step 5:** **Update Stack Reference:** Reassign the `Top` pointer to look at the newly added stack element (`Top = newStackNode`).
*   **Step 6:** **Complete Operation:** Exit the transfer phase.

---

#### D. Reverse Logistics Audit (Display Stack / Pop Tracing)
*   **Step 1:** **Loop Execution:** While the `Top` stack pointer is not equal to `NULL`, execute the following structural steps:
    *   **Step 1a:** Print the current checkpoint details resting at the `Top` of the stack (representing the most recent destination reached prior to the rollback trigger).
    *   **Step 1b:** Execute a Pop step by shifting the stack pointer downwards: `Top = Top->next` (clearing out the node to mimic tracking progress back down the supply chain toward the original factory origin).
*   **Step 2:** **Complete Operation:** End the log loop once all nodes are cleared out.
*
