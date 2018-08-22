#include <bits/stdc++.h>

#define PI 3.14159265358979323846
#define EPS 1e-6
#define INF 1000000000

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define RFOR(i, a, b) for(int i=int(a)-1; i>=int(b); i--)
#define FORC(cont, it) for(typeof((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define RFORC(cont, it) for(typeof((cont).rbegin()) it = (cont).rbegin(); it != (cont).rend(); it++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

#define MAXN 1000000
#define MOD 1000000007

struct Hora {
    int h, m, s, t;

    Hora() { t = h = m = s = 0; }

    Hora(int hh, int mm, int ss) : h(hh), m(mm), s(ss) {
        simplify();
    }

    Hora(string ss) {
        int f1 = ss.find(":");
        h = atoi(ss.substr(0, f1).c_str());

        int f2 = ss.find(":", f1+1);
        if (f2 != -1) {
            m = atoi(ss.substr(f1+1, f2-f1).c_str());
            s = atoi(ss.substr(f2+1).c_str());
        }
        else {
            m = atoi(ss.substr(f1+1).c_str());
            s = 0;
        }

        simplify();
    }

    Hora operator +(const Hora &r) const {
        Hora ret;

        ret.h = h + r.h;
        ret.m = m + r.m;
        ret.s = s + r.s;

        ret.simplify();

        return ret;
    }

    Hora operator -(const Hora &r) const {
        Hora ret;

        ret.h = h - r.h;
        ret.m = m - r.m;
        ret.s = s - r.s;

        ret.simplify();

        return ret;
    }

    bool operator <(const Hora &r) const {
        return t < r.t;
    }

    bool operator ==(const Hora &r) const {
        return t == r.t;
    }

    void simplify() {
        t = 3600 * h + 60 * m + s;
        t = (t + 86400) % 86400;

        int tt = t;
        h = tt / 3600;
        tt %= 3600;
        m = tt / 60;
        s = tt % 60;
    }

    string to_str() {
        string ret = "";

        if (h < 10) ret = "0";
        ret += std::to_string(h) + ":";

        if (m < 10) ret += "0";
        ret += std::to_string(m) + ":";

        if (s < 10) ret += "0";
        ret += std::to_string(s);

        return ret;
    }

    string to_str(const bool b) {
        string ret = "";

        if (h < 10) ret = "0";
        ret += to_string(h) + ":";

        if (m < 10) ret += "0";
        ret += to_string(m);

        return ret;
    }
};

int main() { _
    Hora h1, h2;
    string s1, s2;

    while(cin >> s1 >> s2) {
        h1 = Hora(s1);
        h2 = Hora(s2);

        cout << (h1 - h2).to_str() << endl;
    }

    return 0;
}


