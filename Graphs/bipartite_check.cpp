#include <bits/stdc++.h>
using namespace std;
const int N=(int) 1e7;
vector<int> adj[N];
int color[N];

bool bipartite_check(int u) {
    for (int v: adj[u]) {
        if (color[v] == -1) {
            color[v] = 1 ^ color[u];
            if (!bipartite_check(v)) return false;
        } else if (color[v] == color[u]) {
            return false;
        }
    }
    return true;
}
int main(){
    memset(color,-1, sizeof(color));
    color[0]=0;
    bool valid=bipartite_check(0);
    return 0;
}
