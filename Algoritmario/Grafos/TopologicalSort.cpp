#include <bits/stdc++.h>

#define PI 3.141592653589793
#define EPS 0.000000001
#define INF 1000000000

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

#define MAXN 10005
#define MOD 1000000007

vi edges[MAXN];
stack<int> s;
bool v[MAXN];

void topologicalSortUtil(int act) {
    v[act] = 1;

    FOR(i, 0, edges[act].size())
        if (!v[edges[act][i]])  topologicalSortUtil(edges[act][i]);

    s.push(act);
}

void topologicalSort(int n) {
    memset(v, 0, sizeof(v));

    FOR(i, 0, n)
        if (!v[i])  topologicalSortUtil(i);

    while (!s.empty()) {
        int a = s.top();
        s.pop();
        cout << a << " \n"[s.empty()];
    }
}

int main() {
    int n, m;
    int a, b;
    while (cin >> n >> m) {
        FOR(i, 0, MAXN)     edges[i].clear();

        FOR(i, 0, m) {
            cin >> a >> b;
            edges[a].pb(b);
        }

        topologicalSort(n);
    }

    return 0;
}

