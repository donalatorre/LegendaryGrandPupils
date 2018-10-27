

//GCD FREQUENCY COUNTER WITH INC-EXC BY ADANCITO

//WHAT DOES THIS ALGORITHM DO?
/*
 
 imagine that for every ordered pair (i, j), 0 <= i, j <= maxN, we did
 res[gcd(i, j)] += one[i] * two[j]
 
 this algorithm calculates the final value of res in O(nlgn)
 
 remember to call precalculations() at the beginning of the program
 
 */

#include <iostream>
#include <string.h>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
const int maxN = 1e5 + 8, MOD = 1e9 + 7;

typedef long long ll;
typedef pair<int, int> ii;

struct FastVec{
    int repo[maxN * 30];//where the actual information is stored
    int *arrs[maxN], size[maxN];
};

vector<int> divs[maxN], sons[maxN], prs;
int root[maxN], key[maxN], n, m;

ll curDiv;
ll one[maxN], two[maxN], res[maxN];

ll consider(int x, int prime){
    ll ret = 0;
    for(int div: divs[x]){
        ret = (ret + MOD + key[div] * one[div * curDiv * prime]) % MOD;
    }
    return ret;
}

void dfs(ll x, ll ways, int w){
    for(int el: sons[x]){
        if(curDiv * el >= maxN) break;
        res[curDiv] = (res[curDiv] +
                       two[curDiv * el] * (one[curDiv] + MOD - ways)) % MOD;
    }
    
    for(int i = w; x * curDiv * prs[i] < maxN - 6; i++){
        dfs(x * prs[i], (ways + consider(x, prs[i])) % MOD, i + 1);
    }
}

void precalculations(){
    for(int i = 1; i < maxN; i++) root[i] = key[i] = 1;
    
    for(int i = 1, pr; i < maxN; i++){
        pr = 0;
        if(divs[i].size() == 1) prs.push_back(i), pr = 1;
        for(int j = i; j < maxN; j += i){
            divs[j].push_back(i);
            if(pr)
                root[j] *= i, key[j] *= -1;
        }
    }
    
    for(int i = 1; i < maxN; i++) sons[root[i]].push_back(i);
}

void solve(){
    for(curDiv = 1; curDiv < maxN; curDiv++){
        dfs(1, 0, 0);
    }
}

void callAlgorithm(){
    
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    clock_t begin = clock();
    
    precalculations();
    
    
    
}
