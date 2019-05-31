#include <bits/stdc++.h>

using namespace std;
const int N = (int) 1e7;
vector<int> adj[N];
bool vis[N], art_point[N];
int parent[N], dfs_num[N], dfs_low[N];
int n, cnt, root, root_children;

void dfs(int u) {
    dfs_num[u] = dfs_low[u] = ++cnt;   //update dfs low & dfs num
    for (int v: adj[u]) {
        if (!dfs_num[v]) {    //not visited
            parent[v] = u;
            if (u == root) {  //special case
                root_children++;
            }
            dfs(v);
            if (dfs_low[v] >= dfs_num[u]) {
                art_point[u] = true;
            }
            if (dfs_low[v] > dfs_num[u]) {
                printf("Bridge between %d %d", u, v);
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]); //update dfs low of u during backtracking
        } else {
            if (parent[u] != v) {  //cycle
                dfs_low[u] = min(dfs_low[u], dfs_num[v]);
            }
        }
    }
}

void artpoints_and_bridges() {
    for (int i = 0; i < n; i++) {
        if (!dfs_num[i]) {
            root = i;
            root_children = 0;
            dfs(i);
            if (root_children <= 1)
                art_point[root] = false;
        }
    }
}

int main() {
    n = cnt = root = root_children = 0;
    memset(vis, 0, sizeof(vis));
    memset(art_point, 0, sizeof(art_point));
    memset(parent, 0, sizeof(parent));
    memset(dfs_low, 0, sizeof(dfs_low));
    memset(dfs_num, 0, sizeof(dfs_num));
    artpoints_and_bridges();

    return 0;
}
