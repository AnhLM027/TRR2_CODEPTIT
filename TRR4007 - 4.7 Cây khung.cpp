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
typedef long long ll;

class edge {
public:
    int x, y, w;
};

int n, E;
vector<edge> dsc;

class DSU {
public:
    int parent[maxn];
    int sz[maxn];

    DSU() {
        for(int i = 1; i < maxn; i++) {
            parent[i] = -1;
            sz[i] = 1;
        }
    }
    
    int Find(int u) {
        if(parent[u] == -1) return u;
        return parent[u] = Find(parent[u]);
    }

    bool Union(int u, int v) {
        u = Find(u);
        v = Find(v);

        if(u == v) return false;
        else {
            if(sz[u] >= sz[v]) {
                sz[u] += sz[v];
                parent[v] = u;
            }
            else {
                sz[v] += sz[u];
                parent[u] = v;
            }
            return true;
        }
    }
};

void Kruskal() {
    DSU dsu;
    ll ans = 0;
    vector<edge> res;
    for(int i = 0; i < dsc.size(); i++) {
        if(res.size() == n - 1) break;

        edge E = dsc[i];
        if(dsu.Union(E.x, E.y)) {
            res.push_back(E);
            ans += E.w;
        }
    }

    if(res.size() < n - 1) {
        cout << "0" << endl;
    }
    else {
        cout << ans << endl;
        for(edge E : res) {
            cout << E.x << " " << E.y << " " << E.w << endl;
        }
    }
}

int main() {
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    cin >> n >> E;
    for(int i = 1; i <= E; i++) {
        int x, y, z; cin >> x >> y >> z;
        dsc.push_back({x, y, z});
    }

    sort(dsc.begin(), dsc.end(), [](edge a, edge b) -> bool {
        if(a.w == b.w && a.x == b.x) return a.y < b.y;
        else if(a.w == b.w) return a.x < b.x;
        return a.w < b.w;
    });

    Kruskal();

    return 0;
}