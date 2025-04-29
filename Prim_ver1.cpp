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

#define endl "\n"
#define maxn 105
typedef long long ll;

const int INF = 1e9;

int n, start;
int a[maxn][maxn] = {};
vector<int> key(maxn, INF), parent(maxn, -1), updTime(maxn, INF);
int vis[maxn] = {};

void Prim() {
    
    vector<pair<int, int>> res;
    int timer = 0;
    
    key[start] = 0;
    updTime[start] = timer++;

    // Lặp n lần, vì đồ thị có n đỉnh (sử dụng các chỉ số từ 1 đến n)
    for (int count = 1; count <= n; count++) {
        int u = -1, minKey = INF, minUpd = INF;
        for (int v = 1; v <= n; v++) {
            if (!vis[v] && (key[v] < minKey || (key[v] == minKey && updTime[v] < minUpd))) {
                minKey = key[v];
                minUpd = updTime[v];
                u = v;
            }
        }
        
        if (u == -1) break;
        
        vis[u] = true;
        if (parent[u] != -1) res.push_back({parent[u], u});
        
        for (int v = 1; v <= n; v++) {
            if (a[u][v] > 0 && !vis[v]) {
                if (a[u][v] < key[v] || (a[u][v] == key[v] && u < parent[v])) {
                    key[v] = a[u][v];
                    parent[v] = u;
                    updTime[v] = timer++;
                }
            }
        }
    }

    int totalWeight = 0;
    for (int i = 1; i <= n; i++) {
        if (parent[i] != -1) {
            totalWeight += a[i][parent[i]];
        }
    }

    cout << "dH = " << totalWeight << "\n";
    for (pair<int, int> edge : res) {
        cout << edge.first << "   " << edge.second << endl;
    }
}

int main(){
    cin >> n >> start;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    
    Prim();
    return 0;
}