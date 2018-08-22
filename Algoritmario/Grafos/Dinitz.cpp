/*
    Revisar detenidamente el codigo
    A pesar de ser la implementacion de Indy, es necesario entender bien el codigo
*/

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

#define MAXN 1000
#define MOD 1000000007

int n, m, src, dest;
int dist[MAXN], q[MAXN], work[MAXN];

struct Edge {
    int to, rev;
    int f = 0, cap;

    Edge() {}
    Edge(int t, int r, int c) :
        to(t), rev(r), cap(c) {}
};
vector<Edge> graph[MAXN];

void addEdge(int s, int t, int cap) {
    graph[s].pb(Edge(t, graph[t].size(), cap));
    graph[t].pb(Edge(s, graph[s].size() - 1, 0));
}

bool dinitz_bfs() {
    memset(dist, -1, sizeof(dist));
    dist[src] = 0;
    int qt = 0;
    q[qt++] = src;
    FOR(qh, 0, qt) {
        int u = q[qh];
        FOR(j, 0, graph[u].size()) {
            Edge &e = graph[u][j];
            int v = e.to;
            if (dist[v] < 0 && e.f < e.cap) {
                dist[v] = dist[u] + 1;
                q[qt++] = v;
            }
        }
    }
    return dist[dest] >= 0;
}

int dinitz_dfs(int u, int f) {
    if (u == dest)  return f;

    for (int &i = work[u]; i < (int) graph[u].size(); i++) {
        Edge &e = graph[u][i];
        if (e.cap <= e.f)   continue;
        int v = e.to;
        if (dist[v] == dist[u] + 1) {
            int df = dinitz_dfs(v, min(f, e.cap - e.f));
            if (df > 0) {
                e.f += df;
                graph[v][e.rev].f -= df;
                return df;
            }
        }
    }
    return 0;
}

int maxFlow() {
    int result = 0;
    while (dinitz_bfs()) {
        memset(work, 0, sizeof(work));
        while (int delta = dinitz_dfs(src, INT_MAX))
            result += delta;
    }
    return result;
}


int main() { _
    int n, m, a, b, c;
    cin >> n >> m >> src >> dest;
    FOR(i, 0, m) {
        cin >> a >> b >> c;
        graph[a].pb(Edge(b, graph[b].size(), c));
        graph[b].pb(Edge(a, graph[a].size(), c));
    }
    cout << maxFlow() << endl;
    return 0;
}

