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

int n;

struct Vector{
    ll x, y;
    Vector(ll a, ll b): x(a), y(b){}
    Vector(const Vector &ot): x(ot.x), y(ot.y){}
    Vector(){}
    ll operator*(const Vector &ot){
        return x * ot.x + y * ot.y;
    }
    ll operator%(const Vector &ot){
        return x * ot.y - y * ot.x;
    }
};

Vector operator-(const Vector &a, const Vector &b){
    return Vector(a.x - b.x, a.y - b.y);
}

ll sq(ll a){return a * a;}

ll euc(const Vector &a, const Vector &b){
    return sq(a.x - b.x) + sq(a.y - b.y);
}

Vector arr[maxN];

bool operator<(const Vector &p, const Vector &q){
    Vector a = p, b = q;
    a = a - arr[0], b = b - arr[0];
    return a % b > 0 || (a % b == 0 && a * (b - a) > 0);
}

vector<Vector> getHull(){
    stack<Vector> st;
    for(int i = 0; i < min(n, 2); i++) st.push(arr[i]);
    
    for(int i = 2; i < n; i++){
        Vector cr = st.top(); st.pop();
        
        while(st.size() && (arr[i] - cr) % (cr - st.top()) >= 0){
            cr = st.top(); st.pop();
        }
        
        st.push(cr), st.push(arr[i]);
    }
    vector<Vector> ret(st.size());
    for(int i = int(ret.size()) - 1; i >= 0; i--, st.pop()) ret[i] = st.top();
    return ret;
}

ll getmax(const vector<Vector> &vc){
    ll ret = 0;
    
    for(int i = 0, j = min(int(vc.size() - 1), 1); i < j; i++){
        for(;; j = (j + 1) % vc.size()){
            ret = max(ret, euc(vc[i], vc[j]));
            if((vc[i + 1] - vc[i]) % (vc[(j + 1) % vc.size()] - vc[j]) <= 0) break;
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> arr[i].x >> arr[i].y;
        for(int i = 1; i < n; i++)
            if(arr[i].y < arr[0].y || (arr[i].y == arr[0].y && arr[i].x < arr[0].x))
                swap(arr[0], arr[i]);
        sort(arr + 1, arr + n);
        
        vector<Vector> hull = getHull();
        
        cout << getmax(hull) << '\n';
        
    }
    
}
