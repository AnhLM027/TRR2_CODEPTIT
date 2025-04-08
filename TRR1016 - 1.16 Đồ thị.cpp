#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <fstream>
using namespace std;

int main() {
    fstream cin("DT.INP", ios::in);
    fstream cout("DT.OUT", ios::out);
    int k, V, E; cin >> k >> V >> E;
    
    unordered_map<int, int> vao, ra;
    vector<set<int>> dske(V + 1);

    for(int i = 1; i <= E; i++) {
        int x, y; cin >> x >> y;
        ra[x]++;
        vao[y]++;
        dske[x].insert(y);
    }

    if(k == 1) {
        for(int i = 1; i <= V; i++) cout << vao[i] << " " << ra[i] << endl;
    }
    else {
        cout << V << endl;
        for(int i = 1; i <= V; i++) {
            cout << dske[i].size() << " ";
            for(int x : dske[i]) cout << x << " ";
            cout << endl;
        }
    }
}