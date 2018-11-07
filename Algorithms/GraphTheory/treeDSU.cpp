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
#include <cmath>
#include <climits>
#include <complex>
#include <cmath>
#define fi first
#define se second
#define th second
#define FI first
#define SE second.first
#define TH second.second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long double ld;
typedef complex<double> cd;

const int maxN = 1e5 + 9, MOD = 1e9 + 7, INF = 2e7;

int n, comp[maxN], k, edges[maxN][2], sz[maxN], bg[maxN], answer[maxN], comps;
vector<int> adj[maxN];

void precalc(int nd){
    //In this function, we calculate size and index of biggest child, sz and bg, resp
    sz[nd] = 1;
    bg[nd] = -1;
    for(int sn: adj[nd]){
        precalc(sn);
        if(bg[nd] == -1 || sz[bg[nd]] < sz[sn]) bg[nd] = sn;
        sz[nd] += sz[sn];
    }
}

//THESE TWO FUNCTIONS DEPEND ON THE OPERATION OF THE PROBLEM. IN THIS EXAMPLE, IT IS ABOUT NODE DSU
int find(int u){
    if(comp[u] == u) return u;
    return comp[u] = find(comp[u]);
}

void unite(int u, int v){
    comp[u] = find(v);
    comps--;
}

void consider(int nd){
    //CONSIDERING OPERATION OF NODE ND
    if(find(edges[nd][0]) != find(edges[nd][1]))
        unite(find(edges[nd][0]), find(edges[nd][1]));
    //CONSIDERING OPERATION OF NODE ND
}

void bruta(int nd){
    consider(nd);
    for(int sn: adj[nd])
        bruta(sn);
}

void limpia(int nd){
    
    //UNCONSIDERING OPERATION OF NODE ND
    comp[edges[nd][0]] = edges[nd][0];
    comp[edges[nd][1]] = edges[nd][1];
    //UNCONSIDERING OPERATION OF NODE ND
    
    for(int sn: adj[nd])
        limpia(sn);
}

void dfs(int nd, bool keep){
    //WHERE WE ACTUALLY CALCULATE THE ANSWER.
    
    //SOLVE RECURSIVELY O(NLGN) FOR ALL CHILDREN EXCEPT BIGGEST NODES, DELETING AFTERWARDS
    for(int sn: adj[nd])
        if(sn != bg[nd])
            dfs(sn, 0);
    
    //SOVE REC. FOR BIGGEST NODES O(NLGN), NOT DELETING AFTERWARDS
    if(bg[nd] != -1) dfs(bg[nd], 1);
    
    //RECONSIDER CHILDREN IN O(N)
    for(int sn: adj[nd])
        if(sn != bg[nd])
            bruta(sn);
    
    //CONSIDER THIS NODE
    consider(nd);
    
    answer[nd] = comps;
    
    //IF DELETION IS REQUESTED, DELETE. NOTE LIMPIA(ND) IS THE KEY, COMPS = K IS SPECIFICALLY ABOUT THE PROBLEM
    if(!keep) limpia(nd), comps = k;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> k;
    
    for(int i = 1, pa; i < n; i++){
        cin >> pa;
        pa--;
        adj[pa].push_back(i);
    }
    
    for(int i = 0; i < k; i++)
        comp[i] = i;
    
    comps = k;
    
    for(int i = 0, u, v; i < n; i++){
        cin >> u >> v;
        u--;
        v--;
        if(u == -1) u = v = k;
        else edges[i][0] = u, edges[i][1] = v;
        
    }
    
    precalc(0);
    
    dfs(0, 1);
    
    for(int i = 0; i < n; i++) cout << answer[i] << '\n';
    
}

