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

#define MAXN 10005
#define MOD 1000000007

int graph[MAXN][MAXN];
int dist[MAXN][MAXN];

void floydWarshall(int n) { // O(n^3)
    FOR(i, 0, n) FOR(j, 0, n) dist[i][j] = graph[i][j];

    FOR(k, 0, n) {
        FOR(i, 0, n) {
            FOR(j, 0, n) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    FOR(i, 0, MAXN) FOR(j, 0, MAXN) dist[i][j] = INF;

    int n, m;
    cin >> n >> m;
    FOR(i, 0, m) {
        cin >> a >> b >> c;
        graph[a][b] = c;
    }

    floydWarshall(n);
    return 0;
}
