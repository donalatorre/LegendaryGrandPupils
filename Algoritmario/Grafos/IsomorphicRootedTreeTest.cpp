//  Copyright © 2017 Adán López Alatorre. All rights reserved.
//

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
#include <cmath>
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef multiset<ll, greater<ll>>::iterator iit;
typedef pair<iit, iit> pvi;

const int maxN = 1e5 + 3, maxV = 1e6;

int n, rta, rtb, mla, mlb;

struct El{
    int uu;
    vector<int> vc;
    El(int uu): uu(uu), vc(vector<int>()){}
    bool operator!=(const El &ot) const{
        return vc != ot.vc;
    }
    bool operator<(const El &ot) const{
        return vc < ot.vc;
    }
};
bool notequal(const vector<El> &a, const vector<El> &b){
    if(a.size() != b.size()) return true;
    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i]) return true;
    }
    return false;
}
vector<int> one[maxN], two[maxN];
vector<El> vcs[2][maxN];
int le[maxN];

void getinp(vector<int> *adj, int &rt){
    for(int i = 0, pa; i < n; i++){
        cin >> pa;
        if(!pa) rt = i;
        else adj[--pa].push_back(i);
    }
}

void dfs(vector<int> *adj, vector<El> *vcc, int nd, int ct, int &bes){
    bes = max(bes, ct);
    for(int sn: adj[nd]){
        vcc[ct + 1].push_back(El(int(vcc[ct].size() - 1)));
        dfs(adj, vcc, sn, ct + 1, bes);
    }
}

bool isom(){
    for(int r = max(mla, mlb); r >= 0; r--){
        for(int u = 0; u < 2; u++) sort(vcs[u][r].begin(), vcs[u][r].end());
        //cout << "good " << r << '\n';
        if(notequal(vcs[0][r], vcs[1][r])) return false;
        for(int u = 0; u < 2 && r; u++){
            for(int i = 0, j = 0; i < vcs[u][r].size(); i = j){
                for(;j<vcs[u][r].size() && vcs[u][r][i].vc == vcs[u][r][j].vc; j++){
                    int uu = vcs[u][r][j].uu;
                    vcs[u][r - 1][uu].vc.push_back(i);
                }
            }
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int t;
    cin >> t;
    
    while(t--){
        cin >> n;
        
        mlb = mla = 0;
        for(int i = 0; i < n; i++)
            one[i].clear(), two[i].clear(), vcs[0][i].clear(), vcs[1][i].clear();
        
        getinp(one, rta), getinp(two, rtb);
        
        vcs[0][0].push_back(El(-1));
        vcs[1][0].push_back(El(-1));
        dfs(one, vcs[0], rta, 0, mla), dfs(two, vcs[1], rtb, 0, mlb);
        
        cout << isom() << '\n';
        
    }
    
}

