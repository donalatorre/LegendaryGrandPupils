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

const int maxN = 2.1e6 + 3, MOD = 1e9 + 7, LG = 21;
//NOTE: maxN>2^LG must be held, remember maxN is twice ur biggest polynom

cd ur[maxN], res[maxN], ors[maxN], cf[maxN];
//assumes sz and step are 2-powers
void FFT(int cfs, int step, int his, int rs, int sz, cd *res){
    if(cfs == 1)
        for(int i = 0; i < sz; i++) res[i] = cf[his];
    else{
        
        FFT(ceil(cfs/2.0), step+1, his, rs<<1, sz>>1, res);
        FFT(cfs>>1, step+1, 1 << step | his, rs<<1, sz>>1, res + (sz>>1));
        
        for(int i = 0, m = sz >> 1; i < m; i++){
            cd cr = res[i];
            res[i] = cr + res[i + m] * ur[i * rs];
            res[i + m] = cr + res[i + m] * ur[(i + m) * rs];
        }
    }
}

void mu(const vector<ll> &a, const vector<ll> &b, vector<ll> &ans){
    int sz = 1<<int(ceil(log2(a.size() + b.size() - 1)));
    
    for(int i = 0; i < a.size(); i++) cf[i] = a[i];
    FFT((int)a.size(), 0, 0, (1<<LG)/sz, sz, res);
    
    for(int i = 0; i < b.size(); i++) cf[i] = b[i];
    FFT((int)b.size(), 0, 0, (1<<LG)/sz, sz, ors);
    
    for(int i = 0; i < sz; i++) cf[i] = conj(res[i] * ors[i]);
    FFT(sz, 0, 0, (1<<LG)/sz, sz, res);
    
    
    
    for(int i = 0; i < a.size() + b.size() - 1; i++)
        ans.push_back(ll(round(res[i].real() / sz)));
    
}

string st;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    ur[0] = 1, ur[1] = polar(1.0, M_PI * 2 / (1 << LG));
    
    for(int i = 2; i < (1 << LG); i++)
        ur[i] = ur[i - 1] * ur[1];
    
    cin >> st;
    
    vector<ll> a, b, ans;
    for(int i = 0; i < st.size(); i++)
        a.push_back((st[i] == 'B')? 1: 0);
    for(int i = int(st.size() - 1); i >= 0; i--)
        b.push_back((st[i] == 'A')? 1: 0);
    
    mu(a, b, ans);
    for(int i = int(st.size() - 2); i >= 0; i--) cout << ans[i] << '\n';
    
}
//1010
//1010

//coefficients can be handled with an integer for how many, and a pair of ints: step and history, which will tell the index of the coefficient in the base case (the only time it will be used)
//now, for the unity roots, use formula x * 2 % sz to get square simply, in this way we can keep only one array of unity roots.
//for m current unity roots, when we squere them, all indices will have at least one zero to left more in binary notation. So we just need to calculate squares of the upper side of argand's diagram. So its new size will be a power of two and the step unity will be twice bigger.
//args: cfs(how many coefficients), step(for coef), history(parities defined), rootstep(size of unity root step), rootam(amount of roots to consider)
//so process is simple now:
//base case: return coefficient rootam times
//regular case: rec(ceil(n/2), step+1, history, rootstep*2, next2pow(rootam))
//              rec(floor(n/2), step+1, 1<< st|history, rootstep*2, next2pow(rootam))

//now where should we store them?
//create array that will store evaluations. So add new parameter Foo *pl, where we will store results of shit. When we call recursively, store at end all even- coef evals. Then put in current and forget, so use same place for unevens
