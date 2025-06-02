#include <bits/stdc++.h>
using namespace std;

#define maxn 105
typedef long long ll;

int n, s, t;
vector<pair<int, int>> dsc;
vector<int> parent(maxn, -1);
int a[maxn][maxn] = {};

void Bellman_Ford() {
    vector<int> dp(maxn, INT_MAX);

    dp[s] = 0;

    for(int i = 1; i <= n - 1; i++) {
        for(auto [u, v] : dsc) {
            if(dp[u] != INT_MAX && dp[v] > dp[u] + a[u][v]) {
                dp[v] = dp[u] + a[u][v];
                parent[v] = u;
            }
        }
    }

    for(auto [u, v] : dsc) {
        if(dp[u] != INT_MAX && dp[v] > dp[u] + a[u][v]) {
            cout << "-1" << endl;
            return;
        }
    }
    
    if(dp[t] == INT_MAX) {
        cout << "0" << endl;
        return;
    } else cout << dp[t] << endl;
    
    vector<int> res;
    do {
        res.push_back(t);
        t = parent[t];
    } while(t != -1);
    
    reverse(res.begin(), res.end());
    for(int x : res) cout << x << " ";
}

int main() {
    freopen("BN.INP", "r", stdin);
    freopen("BN.OUT", "w", stdout);
    cin >> n >> s >> t;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if(a[i][j] != 0 && a[i][j] <= 50) dsc.push_back({i, j});
        }
    }
    
    Bellman_Ford();
    
    return 0;
}