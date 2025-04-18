#include <bits/stdc++.h>
using namespace std;

#define maxn 105


int n, E = 0;
int a[maxn][maxn] = {};
bool vis[maxn] = {};

void DFS(int u) {
    vis[u] = true;
    for (int v = 1; v <= n; v++) {
        if (!vis[v] && a[u][v]) {
            DFS(v);
        }
    }
}

void checkTplt(int u) {
    vis[u] = true;
    for (int v = 1; v <= n; v++) {
        if (!vis[v] && (a[u][v] || a[v][u])) {
            checkTplt(v);
        }
    }
}

int check() {
    memset(vis, 0, sizeof(vis));
    bool flag = true;
    
    for (int u = 1; u <= n; u++) {
        DFS(u);
        for(int v = 1; v <= n; v++){
            if(vis[v] == 0){
                flag = false;
                break;
            }
        }
        memset(vis, 0, sizeof(vis));
    }

    if(flag) return 1;

    checkTplt(1);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) return 0;
    }

    return 2;
}

int main() {
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    cout << check() << endl;
    
    return 0;
}