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

const int maxN = 1e3 + 3, MOD = 1e9 + 9, LG = 21;
//NOTE: maxN>2^LG must be held, remember maxN is twice ur biggest polynom
/*
 HAB
 G C
 FED*/
const int dr[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
const string chr = "ECAGDHBF";

string mat[maxN], dic[maxN], ans[maxN];
int n, m, w;
bool v[maxN][maxN];

vector<ii> ini[8];

bool ins(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

void findInits(int d, int r, int c){
    int x = r - dr[d][0], y = c - dr[d][1];
    
    v[r][c] = 1;
    
    if(!ins(x, y)) ini[d].push_back(ii(r, c));
    else if(!v[x][y]) findInits(d, x, y);
}

int tr[maxN * maxN][26], dp[maxN * maxN], lf[maxN * maxN], tc, fWord[maxN * maxN], lastInd[maxN], sz[maxN];

int ins(int par, char c){
    if(tr[par][c - 'A']) return tr[par][c - 'A'];
    int k, ret = tr[par][c - 'A'] = tc++;
    
    for(k = dp[par]; k && !tr[k][c - 'A']; k = dp[k]);
    
    if(k != par) k = tr[k][c - 'A'];
    
    if(fWord[k] != -1)
        lf[ret] = k;
    else
        lf[ret] = lf[k];
    
    dp[ret] = k;
    
    return ret;
}

string bld(int sz, int r, int c, int u){
    r -= dr[u][0] * sz, c -= dr[u][1] * sz;
    return to_string(r) + " " + to_string(c) + " " + chr[u];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m >> w;
        
        queue<int> q;
        
        for(int i = 0; i < n; i++) cin >> mat[i];
        for(int i = 0; i < w; i++) {
            cin >> dic[i];
            sz[i] = int(dic[i].size());
            reverse(dic[i].begin(), dic[i].end());
            q.push(i);
        }
        
        for(int u = 0; u < 8; u++){
            memset(v, 0, sizeof(v)), ini[u].clear();
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    if(!v[i][j])
                        findInits(u, i, j);
        }
        
        memset(tr, 0, tc * sizeof(tr[0])), memset(fWord, -1, sizeof(fWord));
        memset(lastInd, 0, sizeof(lastInd));
        tc = 1;
        
        while(q.size()){
            int c = q.front(); q.pop();
            
            lastInd[c] = ins(lastInd[c], dic[c].back());
            
            //cout << c << ' ' << dic[c].back() << '\n';
            
            dic[c].pop_back();
            
            if(!dic[c].empty())
                q.push(c);
            else
                fWord[lastInd[c]] = c;
        }
        
        //for(int i = 0; i < 26; i++) cout << tr[0][i] << ' '; cout << '\n';
        map<int, string> myMap;
        
        for(int u = 0; u < 8; u++){
            for(ii el: ini[u]){
                int c = 0;
                
                for(; ins(el.fi, el.se); el.fi += dr[u][0], el.se += dr[u][1]){
                    while(c && !tr[c][mat[el.fi][el.se] - 'A'])
                        c = dp[c];
                    c = tr[c][mat[el.fi][el.se] - 'A'];
                    
                    //cout << c << '\n';
                    
                    for(int i = c; i; i = lf[i])
                        if(fWord[i] != -1)
                            myMap[i] = bld(sz[fWord[i]]-1, el.fi, el.se, u);
                }
                
            }
        }
        
        for(int i = 0; i < w; i++)
            cout << myMap[lastInd[i]] << '\n';
        cout << '\n';
        
    }
    
}
