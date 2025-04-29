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
int dp[maxn] = {};
set<int> ke[maxn];
vector<vector<int>> res;
int parent[maxn] = {0};

void Dijkstra() {
    for(int i = 0; i <= maxn; i++) dp[i] = 1e9;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    
    pq.push({0, st});
    dp[st] = 0;
    
    while(!pq.empty()) {
        pair<int, int> pi = pq.top(); pq.pop();
        int w = pi.first;
        int u = pi.second;
        
        //cout << u << " " << w << " " << dp[u] << endl;
        if(w > dp[u]) continue;
        
        for(int v : ke[u]) {
            if(dp[v] > dp[u] + a[u][v]) {
                dp[v] = dp[u] + a[u][v];
                parent[v] = u;
                pq.push({dp[v], v});
            }
        }
    }
}

int main() {
    cin >> n >> st;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if(a[i][j]) {
                ke[i].insert(j);
            }
        }
    }

    Dijkstra();
    for(int v = 1; v <= n; v++) {
        cout << "K/c " << st << " -> " << v << " = ";
        
        if((dp[v] == 1e9)) {
            cout << "INF" << endl;
            continue;
        }

        int u = v;
        cout << dp[v] << ";        " << u << " <- ";
        
        while(u != st) {
            u = parent[u];
            if(u == st) break;
            cout << u << " <- ";
        }
        cout << st << endl;
    }

    return 0;
}