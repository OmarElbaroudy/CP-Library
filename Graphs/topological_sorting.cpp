#include <bits/stdc++.h>

using namespace std;
const int N = (int) 1e7;
vector<int> adj[N], sorted_array;
stack<int> st;
bool vis[N];
int parent[N];

int n;

//if not DAG algorithms will fail!

void toposort_dfs(int u) {
    for (int v:adj[u]) {
        if (!vis[v]) {
            vis[v] = 1;
            toposort_dfs(v);
        }
    }
    st.push(u);
}

void toposort_bfs() {
    for (int i = 0; i < n; i++) {    //constructing parent array
        for (int v:adj[i]) {
            parent[v]++;
        }
    }
    queue<int> roots; //PriorityQueue for smallest lexiographical sorting kahn's algorithm
    for (int i = 0; i < n; i++) {
        if (!parent[i]) roots.push(i);
    }
    while (!roots.empty()) {
        int u = roots.front();
        roots.pop();
        sorted_array.push_back(u);
        for (int v: adj[u]) {
            if (--parent[v] == 0)
                roots.push(v);
        }
    }
}

int main() {
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; ++i) { //preTraversal for dfs algorithm
        if (!vis[i]) {
            toposort_dfs(i);
            st.push(i);
        }
    }
    memset(parent, 0, sizeof(parent));
    toposort_bfs();
    return 0;
}
