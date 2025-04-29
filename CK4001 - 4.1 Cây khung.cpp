#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
#include <fstream>
#include <algorithm>
using namespace std;

#define maxn 105


int n, st;
int a[maxn][maxn] = {};
bool vis[maxn] = {};
set<int> ke[maxn];
vector<vector<int>> res;

void DFS(int u) {
    vis[u] = true;
    for(int v : ke[u]) {
        if(!vis[v]) {
            res.push_back({u, v});
            DFS(v);
        }
    }
}

void BFS() {
    for(bool& b : vis) b = false;

    queue<int> qe;
    qe.push(st);
    
    vis[st] = true;
    
    while(!qe.empty()) {
        int u = qe.front(); qe.pop();
        for(int v : ke[u]) {
            if(!vis[v]) {
                res.push_back({u, v});
                vis[v] = true;
                qe.push(v); 
            }
        }
    }
}

int main() {
    // freopen("CK.INP", "r", stdin);
    // freopen("CK.OUT", "w", stdout);
    int k; cin >> k >> n >> st;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if(a[i][j]) {
                ke[i].insert(j);
            }
        }
    }
    
    if(k == 1) DFS(st);
    else BFS();

    if(res.size() == n - 1) {
        cout << res.size() << endl;
        for(vector<int> v : res) cout << v[0] << " " << v[1] << endl;
    }
    else cout << "0" << endl;
    
    return 0;
}