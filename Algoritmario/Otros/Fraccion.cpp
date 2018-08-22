#include <bits/stdc++.h>

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
typedef vector<vi> vvi;


struct Fraction {
    ll num, den;

    Fraction() {num = den = 1;}

    Fraction(ll numm, ll denn) : num(numm), den(denn) {
        simplify();
    }

    void simplify() {
        bool signo = false;
        if (num < 0)    signo = !signo;
        if (den < 0)    signo = !signo;
        ll g = __gcd(num, den);
        if (g) {
            num /= g;
            den /= g;
        }
        if (signo)  num = -num;
    }

    Fraction operator + (const Fraction &r) const {
        Fraction ret;
        ret.num = num*r.den + r.num*den;
        ret.den = r.den*den;
        ret.simplify();
        return ret;
    }

    Fraction operator + (const ll &r) const {
        Fraction ret;
        ret.num = num + r*den;
        ret.den = den;
        return ret;
    }

    Fraction operator - (const Fraction &r) const {
        Fraction ret;
        ret.num = num*r.den - r.num*den;
        ret.den = r.den*den;
        ret.simplify();
        return ret;
    }

    Fraction operator - (const ll &r) const {
        Fraction ret;
        ret.num = num - r * den;
        ret.den = den;
        return ret;
    }

    Fraction operator * (const Fraction &r) const {
        Fraction ret;
        ret.num = num*r.num;
        ret.den = den*r.den;
        ret.simplify();
        return ret;
    }

    Fraction operator * (const ll &r) const {
        Fraction ret;
        ret.num = num*r;
        ret.den = den;
        ret.simplify();
        return ret;
    }

    Fraction operator / (const Fraction &r) const {
        Fraction ret;
        ret.num = num*r.den;
        ret.den = den*r.num;
        ret.simplify();
        return ret;
    }

    Fraction operator / (const ll &r) const {
        Fraction ret;
        ret.num = num;
        ret.den = den*r;
        ret.simplify();
        return ret;
    }

    Fraction pow(int n) const {
        Fraction ret(1, 1);
        Fraction x(num, den);
        while (n) {
            if (n & 1) ret = ret * x;
            x = x * x;
            n >>= 1;
        }
        return ret;
    }

    bool operator <(const Fraction &r) const {
        return num * r.den < den * r.num;
    }

    bool operator ==(const Fraction &r) const {
        return num == r. num && den == r.den;
    }

    string to_str() {
        return to_string(num) + "/" + to_string(den);
    }
};

int main() { _
    Fraction f;
    while(cin >> f.num >> f.den) {
        f.simplify();
        cout << f.num << "/" << f.den << endl;
    }

    return 0;
}
