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

const int maxN = 50 + 9, MOD = 1e9 + 7, INF = 2e7;

int n, m, a[maxN][maxN];

/*
 
 HUNGARIAN ALGORITHM
 
 -efficiency O(n ^ 2 * m)
 -input matrix a[1..n][1..m] ONE BASED!
 -n <= m
 -need to fix an INF value!
 -it can handle negative values :O
 -returns MINIMUM cost (just *= -1 to change it to maximum cost)
 
 Such an incredible implementation demands credit for the author. Thanks again, Andrei Lopatin, we remember your genious every time we look at this beautiful piece of code!
 
 "This implementation was actually developed by Andrei Lopatin several years ago. It is distinguished by an amazing brevity: the whole algorithm is placed in 30 lines of code ."
 
 */

int hungarian(){
    vector<int> u (n+1), v (m+1), p (m+1), way (m+1);
    for (int i=1; i<=n; ++i) {
        p[0] = i;
        int j0 = 0;
        vector<int> minv (m+1, INF);
        vector<char> used (m+1, false);
        do {
            used[j0] = true;
            int i0 = p[j0],  delta = INF,  j1;
            for (int j=1; j<=m; ++j)
                if (!used[j]) {
                    int cur = a[i0][j]-u[i0]-v[j];
                    if (cur < minv[j])
                        minv[j] = cur,  way[j] = j0;
                    if (minv[j] < delta)
                        delta = minv[j],  j1 = j;
                }
            for (int j=0; j<=m; ++j)
                if (used[j])
                    u[p[j]] += delta,  v[j] -= delta;
                else
                    minv[j] -= delta;
            j0 = j1;
        } while (p[j0] != 0);
        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }
    
    /*
     Recovery of the answer in a more usual form, i.e. finding for each row the i = 1 \ ldots nnumber of the column selected in it ans [i]is done as follows:*/
    vector<int> ans (n+1);
    for (int j=1; j<=m; ++j)
        ans[p[j]] = j;
    
    /*
     
     The value of the matching found can simply be taken as the potential of the zero column (taken with the opposite sign). In fact, how easy it is to trace the code -v [0]contains a sum of all quantities delta, i.e. total potential change. Although at each potential change several values ​​could change at once u [i]and v [j], the total change in the potential value is exactly the same delta, since as long as there is no increasing chain, the number of reachable rows is exactly one more than the number of reachable columns (only the current row idoes not have a pair in the form of a visited column )*/
    
    return -v[0];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
    
    cout << hungarian();
    
}

