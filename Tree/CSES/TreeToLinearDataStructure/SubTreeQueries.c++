
// | Purpose      | Array Used              | Explanation                                      |
// | ------------ | ----------------------- | ------------------------------------------------ |
// | Flatten Tree | `flat[]`                | Stores the value of each node in DFS entry order |
// | Update       | `in[node]`              | Update at this index in flat & seg tree          |
// | Query        | `in[node]`, `out[node]` | Query range in seg tree for subtree              |
// | Segment Tree | Over `flat[]`           | Works on the linearized version                  |


#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MAXN = 200005;

vector<int> tree[MAXN];
int in[MAXN], out[MAXN], flat[MAXN], timer = 0;
ll seg[4 * MAXN];
int value[MAXN];

void dfs(int node, int parent) {
    in[node] = ++timer;
    flat[timer] = value[node];
    for (int child : tree[node]) {
        if (child != parent)
            dfs(child, node);
    }
    out[node] = timer;
}

void build(int id, int l, int r) {
    if (l == r) {
        seg[id] = flat[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}

void update(int id, int l, int r, int pos, int val) {
    if (l == r) {
        seg[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) update(id * 2, l, mid, pos, val);
    else update(id * 2 + 1, mid + 1, r, pos, val);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}

ll query(int id, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return 0;
    if (ql <= l && r <= qr) return seg[id];
    int mid = (l + r) / 2;
    return query(id * 2, l, mid, ql, qr) +
           query(id * 2 + 1, mid + 1, r, ql, qr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i)
        cin >> value[i];

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1, 0); // root is node 1

    build(1, 1, n); // Build segment tree on flat[1..n]

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int s, x;
            cin >> s >> x;
            update(1, 1, n, in[s], x);
        } else if (type == 2) {
            int s;
            cin >> s;
            cout << query(1, 1, n, in[s], out[s]) << "\n";
        }
    }

    return 0;
}

}
