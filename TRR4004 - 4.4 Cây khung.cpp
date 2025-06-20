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

int n, st;
int a[maxn][maxn] = {};
int vis[maxn] = {};
vector<pair<int, int>> adj[maxn];


void Prim() {
    vector<vector<int>> res;
    
    int d = 0;
    vis[st] = true;

    while(res.size() < n - 1) {
        int min_w = INF;
        int x, y;
        for(int i = 1; i <= n; i++) {
            if(vis[i]) {
                for(pair<int, int> pi : adj[i]) {
                    int j = pi.first, w = pi.second;
                    if(!vis[j] && w < min_w) {
                        min_w = w;
                        x = i, y = j;
                    }
                }
            }
        }
        
        res.push_back({min(x, y), max(x, y), min_w});
        d += min_w;
        vis[y] = true;
    }
    cout << d << endl;
    for(vector<int> v : res) {
        cout << v[0] << " " << v[1] << " " << a[v[0]][v[1]] << endl;
    }
}

int main(){
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    cin >> n >> st;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int val; cin >> val;
            if(val > 0) {
                a[i][j] = val;
                adj[i].push_back({j, val});
                adj[j].push_back({i, val});
            }
        }
    }
    
    Prim();
    return 0;
}