#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

typedef long long ll;

double c;

double f(double x) {
    return x * x + sqrt(x) - c;
}

int main() { 
    cin >> c;

    double l = 0, r = 1e5;
    double m;
 
    for (int i = 0; i < 100; i++) {
        m = (l + r) / 2;
        if (f(m) > 0) r = m;
        else l = m;
    }

    cout << fixed << setprecision(15) << l << endl;


    return 0;
}