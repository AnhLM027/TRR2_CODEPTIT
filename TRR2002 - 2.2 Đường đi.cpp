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


int n, st, en, cnt = 0;
int a[maxn][maxn] = {}, path[maxn] = {};
bool vis[maxn] = {};

void DFS(int u, int d) {
    if(d > 2) return;

    if(d == 2 && u == en) {
        cnt++;
        return;
    }

    vis[u] = true;
    for(int v = 1; v <= n; v++) {
        if(!vis[v] && a[u][v]) {
            DFS(v, d + 1);
        }
    }
    vis[u] = false;
}

bool ok = false;
vector<int> res;

void BFS() {
    queue<pair<int, vector<int>>> qe;
    qe.push({st, {st}});
    
    while(!qe.empty()) {
        pair<int, vector<int>> top = qe.front(); qe.pop();
        int u = top.first;
        vector<int> vi = top.second;
        
        if(u == en) {
            res = vi;
            return;
        }
        vis[u] = true;
        for(int v = 1; v <= n; v++) {
            if(!vis[v] && a[u][v]) {
                vi.push_back(v);
                qe.push({v, vi});
                vi.pop_back();
            }
        }
    }
}

int main() {
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    int k; cin >> k;
    cin >> n >> st >> en;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    if(k == 1) {
        DFS(st, 0);
        cout << cnt << endl;
    }
    else {
        BFS();
        if(res.size() == 0) cout << "0" << endl;
        else {
            for(int x : res) cout << x << " ";
        }
    }
    return 0;
}