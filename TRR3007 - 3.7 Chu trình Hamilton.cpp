#include <bits/stdc++.h>
using namespace std;

#define maxn 105

vector<vector<int>> a(maxn, vector<int>(maxn));
set<int> Ke[maxn];
int vis[maxn], X[maxn];

int V, u, cnt = 0;

void Hamilton(int i) {
    for(int j : Ke[X[i - 1]]){
        if(!vis[j]) {
            vis[j] = true;
            X[i] = j;
            
            // for(int x : path) cout << x << " ";
            // cout << endl;

            if(i == V) {
                if(Ke[X[i]].count(u)) {
                    cnt++;
                    for(int i = 1; i <= V; i++) cout << X[i] << " ";
                    cout << u << endl;
                }
            }
            else if(i <= V) Hamilton(i + 1);

            vis[j] = false;
        }
    }
}

int main() {
    freopen("CT.INP", "r", stdin);
	freopen("CT.OUT", "w", stdout);
    cin >> V >> u;
    
    for(int i = 1; i <= V; i++) {
        for(int j = 1; j <= V; j++) {
            cin >> a[i][j];
            if(a[i][j]) Ke[i].insert(j);
        }
    }
    
    X[1] = u;
    vis[u] = true;
    Hamilton(2);
    
    cout << cnt << endl;
    return 0;
}