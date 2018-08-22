#include <bits/stdc++.h>

#define PI 3.14159265358979323846
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

int mat[MAXN][MAXN];

void giraMat(int k, int n) {
    k %= 4;

    FOR(p, 0, k) {
        FOR(i, 0, n/2) {
            FOR(j, i, n - i - 1) {
                ii p1(i, j);
                ii p2(j, n - i - 1);
                ii p3(n - i - 1, n - j - 1);
                ii p4(n - j - 1, i);

                int aux = mat[p1.first][p1.second];
                mat[p1.first][p1.second] = mat[p4.first][p4.second];
                mat[p4.first][p4.second] = mat[p3.first][p3.second];
                mat[p3.first][p3.second] = mat[p2.first][p2.second];
                mat[p2.first][p2.second] = aux;
            }
        }
    }
}

int main() { _
    int cant = 1;
    FOR(i, 0, MAXN) FOR(j, 0, MAXN) {
        mat[i][j] = cant;
        cant ++;
    }

    giraMat(6, MAXN);

    FOR(i, 0, MAXN) FOR(j, 0, MAXN)
        cout << mat[i][j] << "\t\n"[j == MAXN-1];
    return 0;
}

