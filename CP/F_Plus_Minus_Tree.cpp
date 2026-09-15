#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

struct Func {
    long long min_val;
    long long left_shift;
    long long right_shift;
    multiset<long long> L; // Max-heap behavior via rbegin()
    multiset<long long> R; // Min-heap behavior via begin()

    Func() {
        min_val = 0;
        left_shift = 0;
        right_shift = 0;
    }
};

int n;
vector<int> a;
vector<vector<int>> adj;
vector<int> sz;

// Precompute subtree sizes
void get_sz(int u, int p) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v != p) {
            get_sz(v, u);
            sz[u] += sz[v];
        }
    }
}

// Balance the left and right slope sets while updating min_val
void balance(Func& f) {
    while (!f.L.empty() && !f.R.empty()) {
        long long max_L = *f.L.rbegin() + f.left_shift;
        long long min_R = *f.R.begin() + f.right_shift;
        if (max_L > min_R) {
            f.min_val += (max_L - min_R);
            f.L.erase(--f.L.end());
            f.R.erase(f.R.begin());
            f.L.insert(min_R - f.left_shift);
            f.R.insert(max_L - f.right_shift);
        } else {
            break;
        }
    }
}

Func dfs(int u, int p) {
    Func cur;

    for (int v : adj[u]) {
        if (v == p) continue;
        Func child = dfs(v, u);
        
        // Small-to-Large merging optimization
        if (cur.L.size() + cur.R.size() < child.L.size() + child.R.size()) {
            swap(cur, child);
        }
        
        cur.min_val += child.min_val;
        for (long long x : child.L) {
            cur.L.insert(x + child.left_shift - cur.left_shift);
        }
        for (long long x : child.R) {
            cur.R.insert(x + child.right_shift - cur.right_shift);
        }
        balance(cur);
    }

    // 1. Incorporate the choice of a[u] (Shifts)
    if (a[u] == 1) {
        cur.left_shift += 1;
        cur.right_shift += 1;
    } else if (a[u] == -1) {
        cur.left_shift -= 1;
        cur.right_shift -= 1;
    } else { // a[u] == 0
        cur.left_shift -= 1;
        cur.right_shift += 1;
    }

    // 2. Add absolute cost contribution |S_u|
    if (sz[u] % 2 != 0) {
        cur.min_val += 1; // Baseline minimum for odd parity grid
        cur.L.insert(-1 - cur.left_shift);
        cur.R.insert(1 - cur.right_shift);
    } else {
        cur.L.insert(0 - cur.left_shift);
        cur.R.insert(0 - cur.right_shift);
    }
    
    balance(cur);
    return cur;
}

void solve() {
    cin >> n;
    a.resize(n + 1);
    adj.assign(n + 1, vector<int>());
    sz.resize(n + 1);
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    get_sz(1, 0);
    Func root_f = dfs(1, 0);
    cout << root_f.min_val << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
