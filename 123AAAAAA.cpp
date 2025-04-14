#include <bits/stdc++.h>
using namespace std;

#define maxn 105


int n;
int a[maxn][maxn] = {};
int rev[maxn][maxn] = {};
bool vis[maxn] = {};

void DFS(int u, int graph[][maxn]) {
    vis[u] = true;
    for(int v = 1; v <= n; v++) {
        if(!vis[v] && graph[u][v]) {
            DFS(v, graph);
        }
    }
}

int check() {
    memset(vis, false, sizeof(vis));
    DFS(1, a);
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) return 0;
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            rev[j][i] = a[i][j];
        }
    }
    
    memset(vis, false, sizeof(vis));
    DFS(1, rev);
    for (int i = 1; i <= n; i++)
        if (!vis[i]) return 2;

    return 1;
}

int main() {
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    cout << check() << endl;
    
    return 0;
}