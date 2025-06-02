#include <bits/stdc++.h>
using namespace std;

#define maxn 105
typedef long long ll;

int n, s, t;
vector<int> dske[maxn];
vector<int> parent(maxn, -1);
int a[maxn][maxn] = {};

void Dijkstra() {
    queue<pair<int, int>> qe;
    qe.push({s, 0});
    vector<int> dp(maxn, INT_MAX);
    dp[s] = 0;

    while(!qe.empty()) {
        auto [u, w] = qe.front(); qe.pop();

        if(w > dp[u]) continue;

        for(int v : dske[u]) {
            if(dp[v] > dp[u] + a[u][v]) {
                dp[v] = dp[u] + a[u][v];
                parent[v] = u;
                qe.push({v, dp[v]});
            }
        }
    }

    if(dp[t] == INT_MAX) {
        cout << 0 << endl;
        return;
    }
    else cout << dp[t] << endl;
    
    vector<int> res;
    do {
        res.push_back(t);
        t = parent[t];
    } while(t != -1);
    
    reverse(res.begin(), res.end());
    for(int x : res) cout << x << " ";
}

int main() {
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);
    cin >> n >> s >> t;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if(a[i][j] > 0 && a[i][j] <= 50) dske[i].push_back(j);
        }
    }

    Dijkstra();
    
    return 0;
}