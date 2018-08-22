//CENTROID DECOMPOSITION BY ADANCITO

//NOTES:
/*
 -The consider() method contains an algorithm specifically thought of to count pairs in trees which fulfill a certain characteristic (for further details go to method). However, since this method will be called for all centroids, it can be changed to anything the problem needs to do.
 -If consider()'s efficiency is O(F(n)), then the overall complexity is O(F(n) * lgn).
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string.h>


using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int maxN = 5e5 + 6;

vector<int> adj[maxN];
int n, sz[maxN], arr[maxN];

bool dead[maxN];

void precalc(int nd, int an){
    sz[nd] = 1;
    for(int sn: adj[nd]){
        if(sn != an && !dead[sn]){
            precalc(sn, nd);
            sz[nd] += sz[sn];
        }
    }
}

int getCentroid(int nd, int an, int tot){
    for(int sn: adj[nd]){
        if(sn != an && !dead[sn] && sz[sn] * 2 > tot){
            return getCentroid(sn, nd, tot);
        }
    }
    return nd;
}

ll ans = 0;

int arr1[maxN], arr2[maxN], curs, ots;

void dfs(int nd, int an, int lev){
    // example:
    while(curs <= lev) arr2[curs++] = 0;
    arr2[lev]++;
    //bucket in arr2[lev] whatever nd represents. Afterwards, just do the same with children
    
    for(int sn: adj[nd]){
        if(sn != an && !dead[sn]){
            dfs(sn, nd, lev);
        }
    }
    
}

void mergeVec(){
    //Accumulating arrays to keep the consider() method linear
    while(ots < curs) arr1[ots++] = 0;
    for(int i = 0; i < curs; i++){
        arr1[i] += arr2[i];
    }
}

/*
 The most popular CD problem type is pair-counting in trees. This sample is a basic technique that uses bucketing and accumulating. Today, we will count pairs of trees whose path length is odd.
 */
void consider(int nd){
    
    //ots is the size for arr1, curs is the size for arr2
    
    for(int sn: adj[nd]){
        if(!dead[sn]){
            curs = 0;
            dfs(sn, nd, 0);
            
            //example:
            
            for(int j = 0; j < curs; j++){
                ans += ll(arr1[j]) * arr2[j];
            }
            //iterate through arr2, and multiply by frequency in arr1 at the bucket place it corresponds
            
            mergeVec();
            
        }
    }
}

void solve(int nd){
    precalc(nd, -1);
    nd = getCentroid(nd, -1, sz[nd]);
    
    consider(nd);
    dead[nd] = 1;
    
    for(int sn: adj[nd]){
        if(!dead[sn]){
            solve(sn);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v, u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    solve(0);
    
}
