#include <bits/stdc++.h>

#define endl '\n'
#define _ ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main() { _
    int n;
    cin >> n;

    vector<string> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];

    sort(vec.begin(), vec.end(), [](string a, string b){
        if (a.size() != b.size()) return a.size() > b.size();
        return a + b > b + a;
    });

    string aux = {};
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 3; k++){
                if (i == j || j == k || i == k) continue;
                aux = max(aux, vec[i] + vec[j] + vec[k]);
            }
        }
    }

    // string a = vec[0];
    // string b = vec[1];
    // string c = vec[2];

    // string ans = max(a + b + c, a + c + b);
    // ans = max(ans, b + c + a);
    // ans = max(ans, c + a + b);
    // ans = max(ans, c + b + a);
    // ans = max(ans, b + a + c);

    cout << aux << endl;

    return 0;
}