#include <bits/stdc++.h>
using namespace std;
const int N=(int) 1e7;
vector<int> adj[N];
bool vis[N];
int n;
void dfs(int u){
    for (int v:adj[u]){
        if(!vis[v]) dfs(v);
    }
}

int main(){
    memset(vis,0, sizeof(vis));
    for (int i = 0; i <n ; ++i) {   //preTraversal:
        if(!vis[i]) dfs(i);         //for non-connected graphs, Spanning Forest
    }
    return 0;
}
