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

#define MAXN 100005
#define MOD 1000000007

struct TwoSAT{
    int n;
    vector<int> G[MAXN*2];
    int S[MAXN*2], c;
    bool mark[MAXN*2];

    bool dfs(int x){
        if(mark[x^1]) return false;
        if(mark[x]) return true;
        mark[x] = true;
        S[c++] = x;

        FOR(i, 0, G[x].size())
            if(!dfs(G[x][i])) return false;
        return true;
    }

    void init(int n){
        this->n = n;
        FOR(i, 0, 2*n) G[i].clear();
        memset(mark, 0, sizeof(mark));
    }

    /*
     * Each clause is in the form x or y
     * x is abs(x) - 1 and xval is x < 0 ? 1 : 0
     */
    void add_clause(int x, int xval, int y, int yval){
        x = x*2 + xval;
        y = y*2 + yval;
        G[x^1].push_back(y);
        G[y^1].push_back(x);
    }

    bool solve(){
        for(int i = 0; i < 2*n; i += 2){
	        if(!mark[i] && !mark[i+1]){
	            c = 0;
	            if(!dfs(i)){
	                while(c > 0) mark[S[--c]] = false;
	                if(!dfs(i + 1)) return false;
	            }
	        }
    	}
        return true;
    }
}TS;

int main(){
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF){
        TS.init(n);
        // scan m clauses
        FOR(i, 0, m){
            int a, b;
            scanf("%d %d", &a, &b);
            TS.add_clause(abs(a) - 1, a < 0 ? 1 : 0, abs(b) - 1, b < 0 ? 1 : 0);
        }
        printf("%d\n", TS.solve()? 1 : 0);
    }
    return 0;
}
