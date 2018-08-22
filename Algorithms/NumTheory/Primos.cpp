#include <bits/stdc++.h>

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define pb push_back
#define MAXN 1000000

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

vi primes;


// ********************************  IS PRIME()   *****************************************
//Para TODOS los primos

ll mulmod(ll a, ll b, ll c) { // returns (a * b) % c, and minimize overflow
	ll x = 0, y = a % c;
	while (b) {
		if (b & 1) x = (x + y) % c;
		y = (y<<1) % c;
		b >>= 1;
	}
	return x % c;
}

ll fastPow(ll x, ll n, ll c) { // returns (a ** b) % c, and minimize overflow
	ll ret = 1;
	while (n) {
		if (n & 1) ret = mulmod(ret, x, c);
		x = mulmod(x, x, c);
		n >>= 1;
	}
	return ret;
}

// Miller-Rabin primality test
bool miller(ll n, ll d){
    ll a = 2 + rand() % (n - 4);
    ll x = fastPow(a, d, n);
    if(x == 1 || x == n - 1)
        return true;
    while(d < n - 1){
        x = mulmod(x, x, n);
        if(x == 1)
            return false;
        if(x == n - 1)
            return true;
        d <<= 1;
    }
    return false;
}

const int k = 7;
bool isPrime(ll n){
    if(n == 3 || n == 2)
        return true;
    if(n == 1 || n % 2 == 0)
        return false;
    ll d = n - 1;
    while(d % 2 == 0)
        d >>= 1;
    for(int i = 0; i < k; i++){
        if(!miller(n, d))
            return false;
    }
    return true;
}

// ****************************************************************************************


// ********************************  GET PRIME FACTORS()   ********************************
/**
 Devuele los factores primos de un numero. No olvidar hacer unique para quitar repetidos
 int tamano = unique(factors.begin(), factors.end()) - factors.begin();
**/

ll A, B;
vl factors;

ll f(ll x, ll n) {
    return (mulmod(x, (x + A), n) + B) % n;
}

void pollardRho(ll n) {
    if (n == 1) return;
    if (millerRabin(n)) {
        factors.pb(n);
        return;
    }
    ll d = n, x, y;
    while(d == n) {
        d = 1;
        x = y = 2;
        A = 2 + rand() % (n - 2);
        B = 2 + rand() % (n - 2);

        while (d == 1) {
            x = f(x, n);
            y = f(f(y, n), n);
            d = __gcd(abs(x - y), n);
        }
    }

	if (n / d != d)
        pollardRho(n / d);
	pollardRho(d);
}
// ****************************************************************************************

// ******************************** Criba de Eratosthenes *********************************
void Eratosthenes(){
    bool isPrime[MAXN];
    memset(isPrime, 0, sizeof(isPrime));
	FOR(i, 2, MAXN) {
	    if (!isPrime[i]) {
            primes.pb(i);
            for (int j = 2; j*i < MAXN; j++) {
                isPrime[i*j] = true;
            }
	    }
	}
}
// ****************************************************************************************


// ******************************** Criba de Eratosthenes O(N) ****************************
int pc = 0, f[MAXN], primess[MAXN / 10];

void EratosthenesON(){
	FOR(i, 2, MAXN) {
		if (! f[i]) primes[pc++] = i, f[i] = i;
		for (int j = 0; j < pc && 1LL*i*primes[j] < MAXN && primes[j] <= f[i]; j++)
            f[i*primes[j]] = primes[j];
	}
}
// ****************************************************************************************

// ******************************** Criba de Atkin ****************************************
void Atkin() {
    ll sqrtArraySize = sqrt(MAXN);
    ll n;

    bool isPrime[MAXN];
    memset(isPrime, false, sizeof(isPrime));

    ll pp[MAXN];
    FOR(i, 0, sqrtArraySize + 5)    pp[i] = i * i;

    FOR(i, 1, sqrtArraySize + 1) {
        FOR(j, 1, sqrtArraySize + 1) {
            n = 4 * pp[i] + pp[j];

            if (n <= MAXN && (n % 12 == 1 || n % 12 == 5))
                isPrime[n] = !isPrime[n];

            n = 3 * pp[i] + pp[j];

            if (n <= MAXN && (n % 12 == 7))
                isPrime[n] = !isPrime[n];

            if (i > j) {
                n = 3 * pp[i] - pp[j];
                if(n <= MAXN && n % 12 == 11)
                    isPrime[n] = !isPrime[n];
            }
        }
    }

    FOR(i, 5, sqrtArraySize + 1) {
        if (isPrime[i]) {
            ll omit = pp[i];

            for (ll j = omit; j <= MAXN; j += omit) {
                isPrime[j] = false;
            }
        }
    }

    if (MAXN >= 2) {
        primes.pb(2);
        if (MAXN >= 3) {
            primes.pb(3);
        }
    }

    FOR(i, 2, MAXN) {
		if (isPrime[i]) {
			primes.pb(i);
		}
	}
}
// ****************************************************************************************


// ********************************  NEXT PRIME()   ***************************************
//Return the smallest prime greater than or equal to n.
ll nextPrime(ll n) {
    if (n == 2) {
        return 2;
    }
    n |= 1;//make sure n is odd
    if (n == 1) {
        return 2;
    }

    if (millerRabin(n)) {
        return n;
    }

    // prepare entry in the +2, +4 loop:
    // n should not be a multiple of 3
    int rem = n % 3;
    if (0 == rem) { // if n % 3 == 0
        n += 2; // n % 3 == 2
    } else if (1 == rem) { // if n % 3 == 1
        // if (millerRabin(n)) return n;
        n += 4; // n % 3 == 2
    }
    while (true) { // this loop skips all multiple of 3
        if (millerRabin(n)) {
            return n;
        }
        n += 2; // n % 3 == 1
        if (millerRabin(n)) {
            return n;
        }
        n += 4; // n % 3 == 2
    }
}
// ****************************************************************************************

vii getFactorsOfN(int n) {
	vii fac;
	int t = N;
	int last = -1;
	while (f[t] != -1) {
		if (f[t] == last)   fac[fac.size() - 1].second ++;
		else                fac.push_back(ii(f[t], 1));
		last = f[t];
		t /= f[t];
	}
}


// *******************************************
// REGRESA PINCHE CANTIDAD DE COPRIMOS DE N
// Para sacar la puta suma de coprimos es n*phi(n) / 2
int eulerTotient(int n, vii fac) {
	FOR(i, 0, fac.size())
        n = n / fac[i].first * (fac[i].first - 1);
	return n;
}

int main(){

    return 0;
}
