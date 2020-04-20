#include <bits/stdc++.h>
using namespace std;
template <bool Directed, typename TEdge, bool Index> struct graph {
    using EType = TEdge;
    vector<TEdge> edges;
    vector<vector<int>> adj;
    graph(int n) : adj(n + Index) {}
    graph(int n, int m) : graph(n) { edges.reserve(m << not Directed); }
    TEdge& operator()(int e) { return edges[e]; }
    vector<int>& operator[](int u) { return adj[u]; }
    int size() { return adj.size() - Index; }
    void add_edge(const TEdge& e) {
        adj[e.u].push_back(edges.size());
        edges.push_back(e);
        if(not Directed) {
            adj[e.v].push_back(edges.size());
            edges.push_back(e.reverse());
        }
    }
};
