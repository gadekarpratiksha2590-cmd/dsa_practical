# Supply Chain Tracker Algorithms

## Node Structure Initialization
1. Define a structure or class `Block` containing data fields (`location`, `custodian`, `timestamp`, `isVerified`) and a pointer `next` pointing to the next block.

---

## Insert Block (At End)
1. Create a new node and populate its data fields.
2. Set the `next` pointer of the new node to `NULL`.
3. If the list (`Head`) is empty, make the new node the `Head`.
4. Otherwise, traverse the list using a temporary pointer until the last node is reached (where `temp->next == NULL`).
5. Link the last node's `next` pointer to the new node.

---

## Track Journey (Display List)
1. If the list (`Head`) is empty, display *"No journey records found."*
2. Otherwise, initialize a `temp` pointer to `Head`.
3. Loop through the list while `temp` is not `NULL`.
4. Print the product details at each node (`Location` \(\rightarrow\) `Custodian` \(\rightarrow\) `Time` \(\rightarrow\) `Status`).
5. Move `temp` to `temp->next`.

---

## Verify Product (Search)
1. Initialize a `temp` pointer to `Head`.
2. Accept a search keyword (e.g., location or custodian name) from the user.
3. Traverse the list, matching the keyword with node records.
4. If a match is found, display the block details and set a flag.
5. If the end of the list is reached without a match, print *"Tamper warning or invalid block!"*
  
