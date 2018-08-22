#define ll long long

#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)

#define MOD 1000000007

/** return a^x mod p **/
ll modPow(ll a, ll x, ll p) {
    ll res = 1;
    while (x > 0) {
        if (x & 1)
            res = (res * a) % p;
        a = (a * a) % p;
        x >>= 1;
    }
    return res;
}

/** return modular multiplicative of: a mod p, assuming p is prime **/
ll modInverse(ll a, ll p) {
    return modPow(a, p - 2, p);
}

/** return C(n,k) mod p, assuming p is prime **/
ll modBinomial(ll n, ll k) {
    ll numerator = 1; // n*(n-1)* ... * (n-k+1)
    FOR(i, 0, k)
        numerator = (numerator * (n - i)) % MOD;

    ll denominator = 1; // k!
    FOR (i, 1, k+1)
        denominator = (denominator * i) % MOD;

    ll res = modInverse(denominator, MOD);
    res = (res * numerator) % MOD;
    return res;
}

int main(){

}
