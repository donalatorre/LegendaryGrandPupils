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

#define MAXN 10
#define MOD 1000000007

vii graph[MAXN];
stack<int> s;
bool v[MAXN];
int dist[MAXN], n, m;

void topologicalSortUtil(int act) {
    v[act] = 1;

    FOR(i, 0, graph[act].size())
        if (!v[graph[act][i].second])  topologicalSortUtil(graph[act][i].second);

    s.push(act);
}

void longestPath(int source) {
    memset(v, 0, sizeof(v));

    FOR(i, 0, n)
        if (!v[i])  topologicalSortUtil(i);

    fill(dist, dist + n, -INF);
    dist[source] = 0;

    while (! s.empty()) {
        int u = s.top();
        s.pop();

        if (dist[u] != -INF) {
            FOR(i, 0, graph[u].size()) {
                dist[graph[u][i].second] = max(dist[graph[u][i].second], dist[u] + graph[u][i].first);
            }
        }
    }

    FOR(i, 0, n)
        if (dist[i] == -INF)    cout << "INF" << endl;
        else                    cout << dist[i] << endl;
}


int main() { _
    int a, b, c;
    while(cin >> n >> m) {
        FOR(i, 0, m) {
            cin >> a >> b >> c;
            graph[a].pb(ii(c, b));
        }

        int source;
        cin >> source;
        longestPath(source);
    }

    return 0;
}

