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

#define MAXN 10005
#define MOD 1000000007

int n, m;
int matchL[MAXN], matchR[MAXN];
vi edge[MAXN];
bool v[MAXN];

bool dfs(int from) {
    if (v[from])   return 0;
    v[from] = 1;

    FOR(i, 0, edge[from].size()) {
        int to = edge[from][i];

        if (matchR[to] == -1 || dfs(matchR[to])) {
            matchL[from] = to;
            matchR[to] = from;
            return 1;
        }
    }
    return 0;
}

ll MBM() {
    ll ans = 0;
    bool b = 1;

    memset(matchL, -1, sizeof(matchL));
    memset(matchR, -1, sizeof(matchR));

    while (b) {
        b = 0;
        memset(v, 0, sizeof(v));
        FOR(i, 0, n) {
            if (matchL[i] == -1 && dfs(i)) {
                ans ++;
                b = 1;
            }
        }
    }
    return ans;
}

int main() { _
    int a, b;
    cin >> n >> m;
    FOR(i, 0, m) {
        cin >> a >> b;
        edge[a].pb(b);
    }
    cout << MBM() << endl;

    return 0;
}


