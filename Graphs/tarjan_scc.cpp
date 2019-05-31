#include <bits/stdc++.h>

using namespace std;
const int N = (int) 1e7;
vector<int> adj[N];
bool in_scc[N];
int parent[N], dfs_num[N], dfs_low[N];
int n, cnt, scc;
stack<int> st;

void tarjan_scc(int u) {
    dfs_num[u] = dfs_low[u] = ++cnt;
    st.push(u);
    for (int v:adj[u]) {
        if (!dfs_num[v])
            tarjan_scc(v);
        if (!in_scc[v])  //not taken in another component
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    if (dfs_num[u] == dfs_low[u]) {    //scc found
        scc++;
        while (true) {
            int v = st.top();
            st.pop();
            in_scc[v] = true;
            if (v == u) break; //reached head of the cycle
        }
    }

}

void tarjan_scc() {
    for (int i = 0; i < n; ++i) {
        if (!dfs_num[i])    //preTraversal
            tarjan_scc(i);
    }
}

int main() {
    n = cnt = scc = 0;
    memset(in_scc, 0, sizeof(parent));
    memset(dfs_low, 0, sizeof(dfs_low));
    memset(dfs_num, 0, sizeof(dfs_num));
    tarjan_scc();
    return 0;
}

