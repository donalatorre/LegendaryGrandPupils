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
typedef vector<vi> vvi;

#define MAXN 25

int N;
int dptsp[MAXN][1 << MAXN], costViajero[MAXN][MAXN];
int maskInicial;

// Calcula costos de todos los nodos a todos los nodos.
void floyd() {
	FOR(k, 0, N) {
		FOR(i, 0, N) {
			FOR(j, 0, N) {
				costViajero[i][j] = min(costViajero[i][j], costViajero[i][k] + costViajero[k][j]);
			}
		}
	}
}

// Bits prendidos significa ciudad que aun no se visita.
int tsp(int n, int mask) {
	if (!mask) return 0;
	int &c = dptsp[n][mask];
	if (~c) return c;
	c = INF;
	FOR(i, 0, N) {
		if (mask & 1 << i) {
			c = min(c, tsp(i, mask ^ 1 << i) + costViajero[n][i]);
		}
	}
	return c;
}

int main() {
    int ans;

    floyd();
    maskInicial = (1 << N) - 1, ans = INF;
	FOR(i, 0, N) {
		ans = min(ans, tsp(i, maskInicial ^ 1 << i));
	}

    return 0;
}
