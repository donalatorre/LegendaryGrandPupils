#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define MOD 1000000007

typedef long long ll;
const long double PHI ((1.0 + sqrt(5.0)) / 2.0);

ll O1(ll n) {
    return (ll)(floor(pow(PHI, n) / sqrt(5.0) + 0.5));
}

void mult(ll F[2][2], ll M[2][2]) {
    ll x =  (F[0][0] * M[0][0]) % MOD + (F[0][1] * M[1][0]) % MOD;
    ll y =  (F[0][0] * M[0][1]) % MOD + (F[0][1] * M[1][1]) % MOD;
    ll z =  (F[1][0] * M[0][0]) % MOD + (F[1][1] * M[1][0]) % MOD;
    ll w =  (F[1][0] * M[0][1]) % MOD + (F[1][1] * M[1][1]) % MOD;
    F[0][0] = x % MOD;
    F[0][1] = y % MOD;
    F[1][0] = z % MOD;
    F[1][1] = w % MOD;
}

void power(ll F[2][2], ll n) {
    if (n == 0 || n == 1) return;

    ll M[2][2] = {{1, 1}, {1, 0}};
    power(F, n / 2);
    mult(F, F);

    if (n % 2)
        mult(F, M);
}

ll OlnMat(ll n) {
    if (n == 0) return 0;

    ll F[2][2] = {{1,1},{1,0}};
    power(F, n - 1);

    return F[0][0];
}

/** Suma de los primeros n numeros de fibo **/
ll fiboSuma(ll n) {
    return (MOD + OlnMat(n + 2) - 1) % MOD;
}

ll On(ll n) {
    if (n == 1) return 0;

    ll a = 0, b = 1, c = 1;

    FOR(i, 2, n) {
        c = b + a;
        a = b;
        b = c;
    }
    return c;
}

ll fibo(ll n) {
    if (n < 72)     return O1(n);
    if (n < 150)    return On(n);

    return OlnMat(n);
}

int main(){
    ll n;
    cin >> n;
    cout << fibo(n) << endl;
}

