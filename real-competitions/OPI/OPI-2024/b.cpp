#include <bits/stdc++.h>

#define pb push_back
#define endl '\n'
#define _ ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

// N := numero
// K := base
// exiba o numero de digitos de N na base K

// N = a0 * K^0 + a1 * K^1 + a2 * K^2 + ...

int main() { _
    int n, k;
    cin >> n >> k;

    int ans = 0;

    while (n != 0) {
        ans++;
        n = n / k;
    }

    cout << ans << endl;

    return 0;
}