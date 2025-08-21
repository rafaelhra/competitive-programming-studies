#include <bits/stdc++.h>

#define pb push_back
#define end '\n'
#define _ ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

typedef long long ll;

int n;
ll cnt0 = 0;
ll cnt1 = 0;
vector<vector<int>> adj; // adj[i] := sao os nos vizinho de i
vector<int> color;

void bfs(int v) {
    for (int u : adj[v]) {
        if (color[u] == -1) {
            if (color[v] == 1) {
                color[u] = 0;
                cnt0++;
            } else { 
                color[u] = 1;
                cnt1++;
            }
            bfs(u);
        } 
    }
}

int main() { _
    cin >> n;

    adj.resize(n);
    color.resize(n);
    for (int i = 0; i < n; i++) color[i] = -1;

    int u, v;

    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    color[0] = 0;
    cnt0++;
    bfs(0);

    cout << cnt0 * cnt1 - (n - 1) << endl;

    return 0;
}