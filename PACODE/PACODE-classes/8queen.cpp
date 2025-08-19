/**
* @file 8queen.cpp
*
* Created on 2025-08-01 at 16:08:44
* @author GabrielCampelo
*/

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n;
int cnt = 0;

void add(int i, int j, vector<bool> &dig1, vector<bool> &dig2, vector<bool> &linhas) {
    linhas[i] = true;
    dig1[i - j + n - 1] = true;
    dig2[i + j] = true;
}

void rem(int i, int j, vector<bool> &dig1, vector<bool> &dig2, vector<bool> &linhas) {
    linhas[i] = false;
    dig1[i - j + n - 1] = false;
    dig2[i + j] = false;
}

void backtracking(int j, vector<bool> &dig1, vector<bool> &dig2, vector<bool> &linhas) {
    if (j == n) {
        cnt++;
    }
    
    // j < 8 => colocar a rainha na coluna j
    for (int i = 0; i < n; i++) {
        if (linhas[i] == false && dig1[i - j + n - 1] == false && dig2[i + j] == false) {
            add(i, j, dig1, dig2, linhas);
            backtracking(j + 1, dig1, dig2, linhas);
            rem(i, j, dig1, dig2, linhas);
        }
    }
}

int main() { _
    cin >> n;

    vector<bool> dig1(2 * n - 1); // dig1[k] = true, entao esta ocupada
    vector<bool> dig2(2 * n - 1); // dig2[k] = true, entao esta ocupada
    vector<bool> linhas(n); // linhas[i] = true, entao esta ocupada  
    
    backtracking(0, dig1, dig2, linhas);

    cout << cnt << endl;

    return 0;
}