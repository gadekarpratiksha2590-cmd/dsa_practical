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
        for (int i = 0; i < n; i++) {
            parent[i] = i; 
        }
    }
    int findRoot(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = findRoot(parent[i]); 
    }
    void unionSets(int u, int v) {
        int rootU = findRoot(u);
        int rootV = findRoot(v);
        if (rootU != rootV) {
            parent[rootU] = rootV;
        }
    }
};
bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
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
    sort(edges.begin(), edges.end(), compareEdges);
    DisjointSet dsu(numBuildings);
    vector<Edge> mstEdges;
    int totalMinimumCost = 0;
    for (int i = 0; i < numEdges; i++) {
        int rootSrc = dsu.findRoot(edges[i].src);
        int rootDest = dsu.findRoot(edges[i].dest);
        if (rootSrc != rootDest) {
            mstEdges.push_back(edges[i]);
            totalMinimumCost += edges[i].weight;
            dsu.unionSets(rootSrc, rootDest);
        }
        
        if (mstEdges.size() == numBuildings - 1) {
            break;
        }
    }
    cout << "\n--- Optimal Campus Cable Layout (MST) ---\n";
    for (size_t i = 0; i < mstEdges.size(); i++) {
        cout << "Building " << mstEdges[i].src << " <---> Building " 
             << mstEdges[i].dest << " | Cost: " << mstEdges[i].weight<<"\n";
    }
    cout << "-----------------------------------------\n";
    cout << "Total Minimum Installation Cost: $" << totalMinimumCost << "\n";

    return 0;
}
