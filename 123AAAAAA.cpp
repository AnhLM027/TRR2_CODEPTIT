#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main() {
	int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        string st, en; cin >> st >> en;

        vector<string> a(n);
        for(string& s : a) cin >> s;

        unordered_set<string> se(a.begin(), a.end());
        if(!se.count(en)) {
            cout << "-1" << endl;
            continue;
        }
        
        queue<pair<string, int>> qe;
        qe.push({st, 1});
        
        unordered_set<string> used;
        used.insert(st);
        
        int ans = 0;

        while(!qe.empty()) {
            auto [s, cnt] = qe.front(); qe.pop();

            if(s == en) {
                ans = cnt;
                break;
            }

            for(int i = 0; i < s.size(); i++) {
                string t = s;
                for(int c = 'A'; c <= 'Z'; c++) {
                    t[i] = c;
                    if(se.count(t) && !used.count(t)) {
                        qe.push({t, cnt + 1});
                        used.insert(t);
                    }
                }
            }
        }

        cout << ans << endl;
    }
	return 0;
}