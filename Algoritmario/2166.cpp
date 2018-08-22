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
typedef vector<ii> vii;

#define MAXN 10
#define MOD 1000000007

int main() { _
	int t, n, k, x;
	cin >> t;

	while(t--){
		cin >> n >> k;
		int ans = 0;
		vector<int> pers;
		FOR(i, 0, n){
			cin >> x;
			pers.push_back(x);
		}

		sort(pers.begin(), pers.end(), greater<int>());

		FOR(i, 0, n){
			if(pers[i] >= pers[k-1] && pers[i] > 0) ans++;
		}

		cout << ans << endl;
	}
    return 0;
}
