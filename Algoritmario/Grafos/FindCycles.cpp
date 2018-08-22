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

#define maxN 100005

vi edges[maxN];
bool cur[maxN], visit[maxN];
stack<int> ans;

int findCycle(int n) {
	if (cur[n])     return n;
	if (visit[n])   return -1;

	cur[n] = true;
	visit[n] = true;

	FOR(i, 0, edges[n].size()) {
	    if(ans.size())  break;

	    int v = findCycle(edges[n][i]);
		if (v != -1) {
            cur[n] = false;
            ans.push(n);
            if(v == n) {
                return -1;
            }
            return v;
        }
	}
	cur[n] = false;
	return -1;
}

int main() {
	int n, m, a, b;
	while (cin >> n >> m) {
        memset(cur, false, sizeof(cur));
        memset(visit, false, sizeof(visit));

        FOR(i, 0, m) {
            cin >> a >> b;
            edges[a].pb(b);
        }

        FOR(i, 0, n) {
            findCycle(i);
        }

        if(! ans.empty()) {
            cout << "YES\n";
            while(! ans.empty()) {
                int val = ans.top();
                ans.pop();
                cout << val << " \n"[ans.empty()];
            }
        }
        else {
            cout << "NO\n";
        }
	}
	return 0;
}
