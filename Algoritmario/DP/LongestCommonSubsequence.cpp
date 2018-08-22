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

#define MAXN 1000005
#define MOD 1000000007

/* Returns length of LCS for X[0..n-1], Y[0..m-1] */
int lcs(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();
    int L[n + 1][m + 1];
    memset(L, 0, sizeof(L));

    /* Following steps build L[n+1][m+1] in bottom up fashion. Note
    that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
    FOR(i, 1, n+1) {
        FOR(j, 1, m+1) {
            if (s1[i-1] == s2[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }

    /* L[n][m] contains length of LCS for X[0..n-1] and Y[0..m-1] */
    return L[n][m];
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << lcs(s1, s2) << endl;
}
