## Algorithm

• Step 1: Define an Edge structure containing a source building, destination building, and the cable installation cost (weight).

• Step 2: Read the number of buildings (\(V\)) and the list of all candidate cable connections (\(E\)).

• Step 3: Sort all candidate edges in ascending order based on their installation cost.

• Step 4: Initialize a Disjoint Set Union (DSU) structure where each building initially belongs to its own independent set.

• Step 5: Iterate through the sorted edges. For each edge connecting building \(A\) and building \(B\):

-- Find the root parent of \(A\) and the root parent of \(B\).

-- If the parents are different, adding this edge will not form a cycle. Go to Step 6.

-- If the parents are the same, skip this edge to avoid a cycle.

• Step 6: Include the edge in the Minimum Spanning Tree (MST), combine the sets of \(A\) and \(B\) (Union), and add the edge weight to the total cost counter.

• Step 7: Repeat until the MST contains exactly \(V - 1\) edges or all candidate edges have been evaluated.

• Step 8: Display the selected network connections and the final minimum installation cost.
