#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Edge {
    int src, dest, weight;
};
struct DisjointSet {
    vector<int> parent;
    DisjointSet(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int findRoot(int i) {
        if (parent[i] == i) return i;
        return parent[i] = findRoot(parent[i]);
    }
    void unionSets(int u, int v) {
        int rootU = findRoot(u);
        int rootV = findRoot(v);
        if (rootU != rootV) parent[rootU] = rootV;
    }
};
bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}
void runKruskal(int numBuildings, vector<Edge>edges) {
    sort(edges.begin(), edges.end(), compareEdges);
    DisjointSet dsu(numBuildings);
    int totalCost = 0;
   int edgeCount = 0;
    cout << "\n--- Building the Minimum Spanning Tree ---\n";
    cout << "Selected Edge\t\tWeight\t\tRunning Total Cost\n";
    cout << "--------------------------------------------------\n";
    for (const auto& edge : edges) {
        int rootSrc = dsu.findRoot(edge.src);
        int rootDest = dsu.findRoot(edge.dest);
        if (rootSrc != rootDest) {
            totalCost += edge.weight;
            edgeCount++;
            cout << "Bldg " << edge.src << " <---> Bldg " << edge.dest 
                 << "\t  $" << edge.weight << "\t\t  $" << totalCost << "\n";
            dsu.unionSets(rootSrc, rootDest);
        }
        if (edgeCount == numBuildings - 1) break;
    }
    cout << "--------------------------------------------------\n";
    if (edgeCount == numBuildings - 1) {
        cout << "Success: A valid Spanning Tree has been formed!\n";
        cout << "Final Optimal Cost: $" << totalCost << "\n";
    } else {
        cout << "CRITICAL WARNING: The graph is DISCONNECTED!\n";
        cout << "Only " << edgeCount << " connections out of " << (numBuildings - 1) 
             << " needed were formed. A complete spanning tree cannot be created.\n";
    }
}
int main() {
    int numBuildings, numEdges;
    cout << "Enter the number of buildings: ";
    cin >> numBuildings;
    cout << "Enter the number of candidate cable connections: ";
    cin >> numEdges;
    vector<Edge> edges(numEdges);
    cout << "Enter edges format (Source_ID Destination_ID Cost):\n";
    for (int i = 0; i < numEdges; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }
    cout << "\n>>> INITIAL RUN <<<";
    runKruskal(numBuildings, edges);
    cout << "\n>>> UPDATE EDGE COST <<<";
    int updateSrc, updateDest, newWeight;
    cout << "\nEnter Source and Destination of edge to update: ";
    cin >> updateSrc >> updateDest;
    cout << "Enter the new installation cost: ";
    cin >> newWeight;
    bool found = false;
    for (int i = 0; i < numEdges; i++) {
        if ((edges[i].src == updateSrc && edges[i].dest == updateDest) || 
            (edges[i].src == updateDest && edges[i].dest == updateSrc)) {
            edges[i].weight = newWeight;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Edge not found! Appending as a new alternative routing choice.\n";
        edges.push_back({updateSrc, updateDest, newWeight});
    }
    cout << "\n>>> RE-RUN AFTER COST MODIFICATION <<<";
    runKruskal(numBuildings, edges);
   return 0;
}
