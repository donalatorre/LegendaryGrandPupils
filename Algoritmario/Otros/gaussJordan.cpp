#include <bits/stdc++.h>

#define PI 3.14159265358979323846
#define EPS 1e-6
#define INF 1000000000

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define RFOR(i, a, b) for(int i=int(a)-1; i>=int(b); i--)
#define FORC(it, cont) for(auto it = (cont).begin(); it != (cont).end(); it++)
#define RFORC(it, cont) for(auto it = (cont).rbegin(); it != (cont).rend(); it++)
#define pb push_back

#define sz(c) ((int)c.size())
#define print(v) cout << #v" = " << v << endl
#define printArr(arr, a, b) FOR(i, a, b) cout << #arr << "[" << i << "] = " << arr[i] << endl
#define zero(v) memset(v, 0, sizeof(v))
#define uno(v) memset(v, 1, sizeof(v))
#define unoneg(v) memset(v, -1, sizeof(v))
#define toIntA(c) (c - 'A')
#define toInta(c) (c - 'a')
#define toInt0(c) (c - '0')
#define toCharA(i) (char)(i + 'a')
#define toChara(i) (char)(i + 'A')
#define toChar0(i) (char)(i + '0')


using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef __int128 bigInt;

#define MAXN 10
#define MOD 1000000007

// Regresa el vector con los valores de cada variable.
// Si no es posible obtener solucion, regresa un vector vacio.
vector<double> gaussJordan(vector<vector<double> > v) {
    int n = v.size();
    double val;
    FOR(i, 0, n) {
        if (v[i][i] == 0) {
            bool b = 1;
            FOR(j, i+1, n) {
                if (v[i][j] != 0) {
                    swap(v[i], v[j]);
                    b = 0;
                    break;
                }
            }
            if (b) return vector<double>();
        }

        val = v[i][i];
        FOR(j, i, n+1) {
            v[i][j] /= val;
        }

        FOR(k, 0, n) {
            if (i == k)     continue;
            val = -v[k][i];
            FOR(j, i, n+1) {
                v[k][j] += v[i][j] * val;
            }
        }
    }

    vector<double> vd(n);
    FOR(i, 0, n)    vd[i] = v[i][n];
    return vd;
}

int main() { _
    vector<double> v(4);
    vector<vector<double> > vv;
    v[0] = 1;
    v[1] = 1;
    v[2] = 1;
    v[3] = 5;
    vv.pb(v);

    v[0] = 2;
    v[1] = 3;
    v[2] = 5;
    v[3] = 8;
    vv.pb(v);

    v[0] = 4;
    v[1] = 0;
    v[2] = 5;
    v[3] = 2;
    vv.pb(v);

    FOR(i, 0, 3) {
        FOR(j, 0, 4)
            cout << vv[i][j] << " ";
        cout << endl;
    }
    cout << endl << endl;

    vector<double> vd = gaussJordan(vv);
    printArr(vd, 0, 3);

    return 0;
}
