#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;

vector<int> bellman_ford(vector<vector<int>>& adj, int src) {
    vector<int> dist(n + 1, INT_MAX);
    dist[src] = 0;

    // Relax all edges n-1 times
    for (int k = 1; k <= n - 1; k++) {
        for (int u = 1; u <= n; u++) {
            for (int v = 1; v <= n; v++) {
                if (adj[u][v] != INT_MAX && dist[u] != INT_MAX) {
                    dist[v] = min(dist[v], dist[u] + adj[u][v]);
                }
            }
        }
    }

    // Check for negative weight cycle
    bool cycle = false;
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
            if (adj[u][v] != INT_MAX && dist[u] != INT_MAX) {
                if (dist[u] + adj[u][v] < dist[v]) {
                    cycle = true;
                }
            }
        }
    }

    if (cycle) {
        cout << "Negative cycle found. Distances may not be correct.\n";
    }

    return dist;
}

int32_t main() {
    n = 4;
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, INT_MAX));

    // Sample graph
    adj[1][2] = 4;
    adj[1][3] = 5;
    adj[2][4] = 3;
    adj[3][4] = -10;

    vector<int> dist = bellman_ford(adj, 1);

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX)
            cout << "Node " << i << ": INF\n";
        else
            cout << "Node " << i << ": " << dist[i] << "\n";
    }

    return 0;
}
