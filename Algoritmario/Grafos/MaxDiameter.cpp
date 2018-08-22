#include <bits/stdc++.h>

#define PI 3.14159265358979323846
#define EPS 1e-6
#define INF 1000000000

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

#define MAXN 10
#define MOD 1000000007

// v es visitados localmente.
// v2 es todos los que ya he visitado (para grafos no totalmente conectados)
bool v[MAXN], v2[MAXN];
vi edges[MAXN];

ii bfs(int x, bool b) {
    queue<ii> q;
    q.push(ii(x, 0));

    v[x] = !b;
    v2[x] |= !b;
    ii last;
    while(! q.empty()) {
        last = q.front();
        q.pop();

        FOR(i, 0, edges[last.first].size()) {
            if (v[edges[last.first][i]] == b) {
                q.push(ii(edges[last.first][i], last.second + 1));
                v[edges[last.first][i]] = !b;
                v2[edges[last.first][i]] |= !b;
            }
        }
    }

    return last;
}

int maxDiameter(int x) {
    ii ret = bfs(x, false);
    return bfs(ret.first, true).second;
}

int main() {
    return 0;
}
