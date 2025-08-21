/**
* @file bicolorings.cpp
*
* Created on 2024-09-27 at 09:15:15
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

/*
B - branco
P - preto

PBBPBPBB???
BPBBPPBB???

Usando dp[coluna][comp][ultima cor da linha 1][ultima cor da linha 2], temos:
Resposta(n, k) = dp[n]/[k][0][0] + dp[n][k][1][0] + dp[n][k][0][1] + dp[n][k][1][1]

Assim, teremos n * 2n * 2 * 2 = 8 * n² estados
Como n <= 1000, O(n²) passa no tempo

Ainda, podemos simplificar:

dp[colunas][comp][ultimas cores sao iguais?]

*/

#define MAX_N 1000
#define MAX_K 2000
#define MOD 998244353

ll dp[MAX_N + 1][MAX_K + 1][2]; 

int main() { _
    int n, k;
    cin >> n >> k;

    // caso  com 1 coluna
    dp[1][1][1] = 2;
    dp[1][2][0] = 2;

    for (int i = 2; i <= n; i++) {

        int lim = min(2 * i, k);
        for (int j = 1; j <= lim; j++) {
            /*
            P?  B?  P?  B? 
            P?  B?  B?  P?
            */
            
            dp[i][j][0] += dp[i - 1][j][0];                  // veio de -0 comp
            dp[i][j][0] += 2 * dp[i - 1][j - 1][1];          // veio de -1 comp
            if (j >= 2) dp[i][j][0] += dp[i - 1][j - 2][0];  // veio de -2 comp
            dp[i][j][0] %= MOD;

            dp[i][j][1] += 2 * dp[i - 1][j][0] + dp[i - 1][j][1]; // veio de -0 comp
            dp[i][j][1] += dp[i - 1][j - 1][1];                   // veio de -1 comp
            dp[i][j][1] %= MOD;
        }

    } 

    cout << (dp[n][k][0] + dp[n][k][1]) % MOD << endl;
    
    return 0;
}