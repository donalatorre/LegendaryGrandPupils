#include <iostream>
#include <vector>
#include <string.h>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <sstream>
#include <stack>
#include <iomanip>
#include <climits>
#include <complex>
#include <cmath>
#define fi first
#define se second
#define th second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef multiset<ll, greater<ll>>::iterator iit;
typedef pair<iit, iit> pvi;
typedef complex<double> cd;

const int maxN = 1e4 + 3, MOD = 1e9 + 9, LG = 21;
//NOTE: maxN>2^LG must be held, remember maxN is twice ur biggest polynom

int he[maxN], par[maxN], ind[maxN], cs[maxN], heavy[maxN], head[maxN], n, T[maxN << 1];
vector<int> adj[maxN];
ii ed[maxN];

int dfs(int nd){
    int ret = 1, heaS = 0, cr;
    for(int sn: adj[nd]) if(sn != par[nd]){
        par[sn] = nd, he[sn] = he[nd] + 1, cr = dfs(sn), ret += cr;
        if(heaS < cr) heaS = cr, heavy[nd] = sn;
    }
    return ret;
}

void setPaths(){
    memset(heavy, -1, sizeof(heavy)), par[0] = -1, he[0] = 0, dfs(0);
    for(int i = 0, ct = 0; i < n; i++)
        if(par[i] == -1 || heavy[par[i]] != i)
            for(int j = i; j != -1; j = heavy[j])
                head[j] = i, ind[j] = ct++;
}

int query(int l, int r){
    int ret = 0;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1){
        if(l & 1) ret = max(ret, T[l++]);
        if(r & 1) ret = max(ret, T[--r]);
    }
    return ret;
}

void update(int w, int x){
    w += n, T[w] = x;
    while(w > 1)
        w >>= 1, T[w] = max(T[w << 1], T[w << 1 | 1]);
}

int ans(int u, int v){
    int ret = 0;
    for(; head[u] != head[v]; v = par[head[v]]){
        if(he[head[u]] > he[head[v]]) swap(u, v);
        ret = max(ret, query(ind[head[v]], ind[v] + 1));
    }
    if(he[u] > he[v]) swap(u, v);
    return max(ret, query(ind[u] + 1, ind[v] + 1));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        
        for(int i = 0; i < n; i++) adj[i].clear();
        
        for(int i = 1, u, v; i < n; i++){
            cin >> u >> v >> cs[i];
            u--, v--;
            adj[u].push_back(v), adj[v].push_back(u);
            ed[i] = ii(u, v);
        }
        
        setPaths();
        
        for(int i = 1; i < n; i++){
            if(he[ed[i].fi] < he[ed[i].se]) swap(ed[i].fi, ed[i].se);
            update(ind[ed[i].fi], cs[i]);
        }
        
        while(true){
            string inp;
            int a, b;
            cin >> inp;
            if(inp == "DONE") break;
            cin >> a >> b;
            if(inp == "CHANGE"){
                update(ind[ed[a].fi], b);
            }
            else{
                cout << ans(--a, --b) << '\n';
            }
        }
        
    }
    
}
