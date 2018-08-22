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

int n, m;

vi edge[MAXN];
int disc[MAXN], low[MAXN], belongs[MAXN];
bool v[MAXN];
stack<int> st;
int ttime, comp;

void SCCUtil(int u) {
    disc[u] = low[u] = ttime ++;
    st.push(u);
    v[u] = true;

    FOR(i, 0, edge[u].size()) {
        int to = edge[u][i];

        if (disc[to] == -1)
            SCCUtil(to);

        if (v[to])
            low[u]  = min(low[u], low[to]);
    }

    if (low[u] == disc[u]) {
        comp ++;
        while (1) {
            int t = st.top();
            st.pop();
            belongs[t] = comp;
            v[t] = false;

            if (t == u) break;
        }
    }
}

void SSC() {
    ttime = comp = 0;
    memset(disc, -1, sizeof(disc));
    memset(low, -1, sizeof(low));
    memset(v, 0, sizeof(v));

    FOR(i, 0, n)
        if (disc[i] == -1)
            SCCUtil(i);
}



int main() {
    int a, b;
    while (cin >> n >> m) {
        FOR(i, 0, MAXN) edge[i].clear();
        FOR(i, 0, m) {
            cin >> a >> b;
            edge[a].pb(b);
        }
        SSC();
        cout << endl;
        FOR(i, 0, n)    cout << i << " " << belongs[i] << endl;
        cout << endl << endl;
    }

    return 0;
}
