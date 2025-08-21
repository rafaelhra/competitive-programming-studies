#include <bits/stdc++.h>

#define pb push_back
#define end '\n'
#define _ ios_base::sync_with_stdio(false);cin.tie(0);

typedef long long ll;

using namespace std;

int main() { _
    int n;
    cin >> n;

    ll sum = 0;
    int x;
    bool existe_impar = false;

    while (n--) {
        cin >> x;
        sum += x;
        if (x % 2 == 1) existe_impar = true;
    }

    if (sum % 2 == 1) {
        cout << "First" << endl;
    } else {
        if (existe_impar) cout << "First" << endl;
        else cout << "Second" << endl;
    }

    return 0;
}