#include <bits/stdc++.h>

#define PI 3.14159265358979323846
#define EPS 1e-6
#define INF 1000000000

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define RFOR(i, a, b) for(int i=int(a)-1; i>=int(b); i--)
#define FORC(cont, it) for(decltype((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define RFORC(cont, it) for(decltype((cont).rbegin()) it = (cont).rbegin(); it != (cont).rend(); it++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAXN 1000005
#define MOD 1000000007

int lps[MAXN];
vi v;

void computeLPSArray(string pat, int M) {
    int len = 0;
    int i = 1;
    lps[0] = 0;
    while (i < M) {
        if (pat[i] == pat[len])
            lps[i ++] = ++ len;
        else {
            if (len != 0)   len = lps[len - 1];
            else            lps[i ++] = 0;
        }
    }
}
void KMPSearch(string pat, string txt) {
    int M = pat.length();
    int N = txt.length();
    int i = 0;
    int j = 0;

    computeLPSArray(pat, M);

    while (i < N) {
        if (pat[j] == txt[i]) {
            j ++;
            i ++;
        }

        if (j == M) {
            v.pb(i - j);
            j = lps[j - 1];
        }
        else if (i < N && pat[j] != txt[i]) {
            if (j != 0)     j = lps[j - 1];
            else            i = i + 1;
        }
    }
}

int main() {
    string txt = "ABABDABACDABABCABAB";
    string pat = "AB";
    KMPSearch(pat, txt);

    FOR(i, 0, v.size())
        cout << v[i] << " \n"[i==v.size()-1];

    return 0;
}
