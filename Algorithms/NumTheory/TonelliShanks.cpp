#include "bits/stdc++.h"
#define FI first.first
#define SE first.second
#define TH second
#define fi first
#define se second
#define th second

using namespace std;

template<typename T>
string to_string(const vector<T>& vc, int w) {
	if(vc.empty()) return "";
	if(w + 1 == vc.size()) return to_string(vc[w]);
	return to_string(vc[w]) + "," + to_string(vc, w + 1);
}

template<typename T>
string to_string(const vector<T>& vc) {
	return "{" + to_string(vc, 0) + "}";
}

void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

class DebugStream {}LOG;
template <typename T>DebugStream &operator<<(DebugStream &s, const T&) { return s; }
#ifdef DEBUG
#define LOG clog
#endif

typedef long long ll;
typedef pair<ll, ll> ii;
typedef long double ld;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int maxN = 5e5 + 9, maxV = 1e6 + 9, MOD = 1e9 + 7, SQ = 335, lg = 20, bs = 29;

// BEGIN: Tonelli-Shanks algorithm
ll pow_mod(ll x, ll n, ll p) {
  if (n == 0) return 1;
  if (n & 1)
    return (pow_mod(x, n-1, p) * x) % p;
  x = pow_mod(x, n/2, p);
  return (x * x) % p;
}

/* Takes as input an odd prime p and n < p and returns r
 * such that r * r = n [mod p]. */
ll tonelli_shanks(ll n, ll p) {
  ll s = 0;
  ll q = p - 1;
  while ((q & 1) == 0) { q /= 2; ++s; }
  if (s == 1) {
    ll r = pow_mod(n, (p+1)/4, p);
    if ((r * r) % p == n) return r;
    return 0;
  }
  // Find the first quadratic non-residue z by brute-force search
  ll z = 1;
  while (pow_mod(++z, (p-1)/2, p) != p - 1);
  ll c = pow_mod(z, q, p);
  ll r = pow_mod(n, (q+1)/2, p);
  ll t = pow_mod(n, q, p);
  ll m = s;
  while (t != 1) {
    ll tt = t;
    ll i = 0;
    while (tt != 1) {
      tt = (tt * tt) % p;
      ++i;
      if (i == m) return 0;
    }
    ll b = pow_mod(c, pow_mod(2, m-i-1, p-1), p);
    ll b2 = (b * b) % p;
    r = (r * b) % p;
    t = (t * b2) % p;
    c = b2;
    m = i;
  }
  if ((r * r) % p == n) return r;
  return 0;
}
// ENDS: Tonelli-Shanks algorithm

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	#ifdef DEBUG
	freopen("input.txt", "r", stdin);
	#endif

  
}

