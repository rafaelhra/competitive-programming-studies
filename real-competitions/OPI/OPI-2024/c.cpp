#include <bits/stdc++.h>

#define pb push_back
#define end '\n'
#define _ ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main() { _
    int n;
    cin >> n;

    map<string, int> mp;

    int mx = 0; // o maior numero de votos
    string voto;

    for (int i = 0; i < n; i++) {
        cin >> voto;

        mp[voto]++;
        if (mp[voto] > mx) {
            mx = mp[voto];
        }
    }

    for (auto nome : mp) {
        if (nome.second == mx) cout << nome.first << endl;
    }

    return 0;
}