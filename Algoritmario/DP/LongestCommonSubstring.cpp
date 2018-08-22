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

/* Returns length of longest common substring of X[0..n-1] and Y[0..m-1] */
// Create a table to store lengths of longest common suffixes of
// substrings.   Notethat LCSuff[i][j] contains length of longest
// common suffix of X[0..i-1] and Y[0..j-1]. The first row and
// first column entries have no logical meaning, they are used only
// for simplicity of program
int LCSubStr(string X, string Y) {
    int n = X.length();
    int m = Y.length();

    int lcs[n+1][m+1];
    memset(lcs, 0, sizeof(lcs));
    int result = 0;  // To store length of the longest common substring

    /* Following steps build lcs[n+1][m+1] in bottom up fashion. */
    FOR(i, 1, n+1) {
        FOR(j, 1, m+1) {
            if (X[i-1] == Y[j-1]) {
                lcs[i][j] = lcs[i-1][j-1] + 1;
                result = max(result, lcs[i][j]);
            }
            else {
                lcs[i][j] = 0;
            }
        }
    }

    return result;
}

int main() {
    string X, Y;
    cin >> X >> Y;
    cout << LCSubStr(X, Y) << endl;

    return 0;
}
