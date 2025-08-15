// count_subtrees.cpp
// Count connected subtrees of size <= K in a tree.
// Author: ChatGPT
// Compile: g++ -std=c++17 -O2 -Wall -Wextra -o count_subtrees count_subtrees.cpp

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1'000'000'007;

int N, K;
vector<vector<int>> adj;

// f[v][s] = number of connected subtrees of size exactly s that include v
// and are contained in S(v) with v as topmost node.
vector<vector<ll>> f;
vector<int> subsz;

// Postorder DFS to fill f and subsz
void dfs(int v, int p) {
    subsz[v] = 1;

    // We'll compute f[v] after merging children by using dpChildren (children-only counts).
    // Initialize f[v] to zeros (size K+1 since we need indices 1..K)
    f[v].assign(K + 1, 0);

    // dpChildren[j] = number of ways to pick exactly j nodes from processed children (children-only).
    // Start with zero children processed -> 0 nodes chosen in one way.
    vector<ll> dpChildren(1);
    dpChildren[0] = 1;

    // process every child
    for (int u : adj[v]) {
        if (u == p) continue;
        dfs(u, v);

        // update subtree size of v
        subsz[v] += subsz[u];

        // child can contribute at most childMax nodes to the children-only count.
        // We never need more than K-1 nodes from children combined, so cap at K-1.
        int childMax = min(K - 1, subsz[u]); // subsz[u] is size of child's subtree

        // waysChild[t] = number of ways child u contributes exactly t nodes
        // waysChild[0] = 1 (choose nothing from u)
        vector<ll> waysChild(childMax + 1, 0);
        waysChild[0] = 1;
        for (int t = 1; t <= childMax; ++t) {
            // f[u][t] was computed in child's DFS: number of connected sets of size t
            // that include u and lie within S(u) with u topmost.
            waysChild[t] = f[u][t];
        }

        // Convolve dpChildren with waysChild, cap at K-1
        int oldMax = (int)dpChildren.size() - 1;
        int newMax = min(K - 1, oldMax + childMax);
        vector<ll> newDp(newMax + 1, 0);

        for (int a = 0; a <= oldMax; ++a) {
            if (dpChildren[a] == 0) continue;
            for (int b = 0; b <= childMax; ++b) {
                int j = a + b;
                if (j > newMax) break;
                newDp[j] = (newDp[j] + dpChildren[a] * waysChild[b]) % MOD;
            }
        }

        dpChildren.swap(newDp);
    }

    // After processing all children:
    // dpChildren[j] = ways children contribute exactly j nodes (j in [0..K-1]).
    // Total subtree size s = 1 (v itself) + j
    // So f[v][s] = dpChildren[s-1] for s >= 1.
    for (int s = 1; s <= K; ++s) {
        int j = s - 1;
        if (j < (int)dpChildren.size()) f[v][s] = dpChildren[j];
        else f[v][s] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> N >> K)) return 0;
    adj.assign(N + 1, {});
    for (int i = 0; i < N - 1; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (K <= 0) { // trivial: no positive-size subtree
        cout << 0 << "\n";
        return 0;
    }

    f.assign(N + 1, vector<ll>());
    subsz.assign(N + 1, 0);

    // root at 1
    dfs(1, 0);

    // sum counts for all nodes and sizes 1..K
    ll ans = 0;
    for (int v = 1; v <= N; ++v) {
        for (int s = 1; s <= K && s <= N; ++s) {
            ans += f[v][s];
            if (ans >= MOD) ans -= MOD;
        }
    }

    cout << ans % MOD << "\n";
    return 0;
}
