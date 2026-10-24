## Algorithm

• Step 1: Define an Edge structure containing src, dest, and weight (installation cost).

• Step 2: Accept inputs for the total number of campus buildings (\(V\)) and planned connection paths (\(E\)).

• Step 3: Create a reusable function runKruskal that accepts the network data:

-- Sort all available edges in ascending order based on cost.
  
-- Initialize the Disjoint Set Union (DSU) structure where every building points to itself.
  
-- Loop through each sorted edge. Use path compression (findRoot) to check if the source and destination buildings share a root parent.
  
-- If parents match, skip the connection to prevent a redundant wiring loop (cycle).
  
-- If parents differ, merge the components (unionSets), add the edge to the MST array, and print the edge information alongside the running total cost.
  
-- After evaluating all candidate paths, check if the total collected edges equal exactly \(V - 1\). If they do not, report that the graph is disconnected and a spanning tree cannot be formed.
  
• Step 4: Execute the runKruskal function for the baseline network configuration.

• Step 5: Prompt the user to modify an existing cable layout (select source, destination, and input a new weight value).

• Step 6: Locate the target edge in the master list, update its value, and invoke runKruskal a second time to witness how the network shifts dynamically.
