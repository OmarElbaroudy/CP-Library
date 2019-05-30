#include <bits/stdc++.h>
using namespace std;
const int N=(int) 1e7;
vector<int> adj[N];
int dist[N];
int n;
void bfs(int u){
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int cur=q.front(); q.pop();
        for(int v:adj[cur]){
            if(dist[v]==-1){
                dist[v]=dist[cur]+1;
                q.push(v);
            }
        }
    }
}

int main(){
    memset(dist,-1, sizeof(dist));
    for (int i = 0; i <n ; ++i) {   //preTraversal:
        if(dist[i]==-1){
            dist[i]=0;
            bfs(i);         //for non-connected graphs, Spanning Forest
        }
    }
    return 0;
}
