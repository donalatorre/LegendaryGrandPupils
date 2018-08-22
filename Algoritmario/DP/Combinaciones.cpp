#include <bits/stdc++.h>

#define MOD 1000000007
#define MAXN 1005
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)

using namespace std;

typedef long long ll;

ll fact[MAXN], inv[MAXN], pascal[MAXN][MAXN];

ll ppow(ll n, ll p) {
	ll ret = 1;
	while (p) {
		if (p & 1) ret = (ret*n) % MOD;
		n = (n*n) % MOD;
		p>>=1;
	}
	return ret;
}

void generaFact() {
    fact[0] = 1;
    FOR(i, 1, MAXN)
        fact[i] = (fact[i-1] * i) % MOD;

    inv[MAXN-1] = ppow(fact[MAXN-1], MOD - 2);
    for(int i = MAXN-1; i>0; i--)
        inv[i-1] = inv[i] * i % MOD;
}

ll NK(ll n, ll k) {
	return fact[n] * inv[k] % MOD * inv[n-k] % MOD;
}

// pascal i,j corresponde a la formula de combinatoria i!/(j!*(i-j)!), AKA. (N, K)
void trianguloPascal() {
    pascal[0][0] = 1;
	FOR(i, 1, MAXN) {
		pascal[i][0] = 1;
		FOR(j, 1, i+1) {
			pascal[i][j] = (pascal[i - 1][j - 1] + pascal[i - 1][j]) % MOD;
		}
	}
}

int main(){
    ll n, k;
    generaFact();
    trianguloPascal();
    while (scanf("%lld %lld", &n, &k) != EOF) {
        printf("%lld\n", NK(n, k));
        printf("%lld\n", pascal[n][k]);
    }

    return 0;
}


