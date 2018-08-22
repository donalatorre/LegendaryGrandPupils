#include <bits/stdc++.h>

#define PI 3.141592653589793
#define EPS 0.000000001
#define INF 1000000000

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define FORC(cont, it) for(typeof((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAXN 10
#define MOD 1000000007

int mil[MAXN];

string fill(char c, int n) {
    string s;
    while (n--) s += c;
    return s;
}

string toRoman(ll n, int nivel) {
    if (n == 0) return "";
    if (n < 4) return fill('I', n);
    if (n < 6) return fill('I', 5 - n) + "V";
    if (n < 9) return string("V") + fill('I', n - 5);
    if (n < 11) return fill('I', 10 - n) + "X";
    if (n < 40) return fill('X', n / 10) + toRoman(n % 10, nivel);
    if (n < 60) return fill('X', 5 - n / 10) + 'L' + toRoman(n % 10, nivel);
    if (n < 90) return string("L") + fill('X', n / 10 - 5 ) + toRoman(n % 10, nivel);
    if (n < 110) return fill('X', 10 - n / 10) + "C" + toRoman(n % 10, nivel);
    if (n < 400) return fill('C', n / 100) + toRoman(n % 100, nivel);
    if (n < 600) return fill('C', 5 - n / 100) + 'D' + toRoman(n % 100, nivel);
    if (n < 900) return string("D" ) + fill('C', n / 100 - 5) + toRoman(n % 10, nivel);
    if (n < 1100) return fill('C', 10 - n / 100) + "M" + toRoman(n % 100, nivel);
    if (n < 4000) return fill('M', n / 1000) + toRoman(n % 1000, nivel);

    string ret = toRoman(n / 1000, nivel + 1);
    string ret2 = toRoman(n % 1000, nivel);
    mil[nivel] = ret.length();
    if (ret2 == "")    return ret;
    return ret + " " + toRoman(n % 1000, nivel);
}

string toRoman(ll n) {
    string ret = toRoman(n, 0);
    for(int i = 0; mil[i]; i ++) {
        ret = fill('_', mil[i]) + "\n" + ret;
    }

    return ret;
}

int main() { _
    ll n;
    while (cin >> n) {
        cout << toRoman(n) << endl;
    }
    return 0;
}
