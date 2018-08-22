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
#include <fstream>
#include <climits>
#include <cmath>
#define fi first
#define se second
#define FI first.first
#define SE first.second
#define TH second
#define MAXN maxN

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef set<ii>::iterator iter;

const int maxN = 1e5 + 3, MOD = 1e9 + 7, AL = 10;

ll fc[maxN][2];

ll perm(int *bu){
    ll den = 1, tot = 0, imp = 0;
    for(int i = 0; i < AL; i++){
        //cout << bu[i] << ' ';
        imp += bu[i] & 1;
        den = den * fc[bu[i] >> 1][1] % MOD;
        tot += bu[i] >> 1;
    }
    //cout  << '\n';
    if(imp > 1) return 0;
    return fc[tot][0] * den % MOD;
}

struct Node{
    int ca, pri, bu[AL], cnt;
    Node *l, *r;
    bool rev;
    Node(int ca): ca(ca), l(NULL), r(NULL), rev(false){
        memset(bu, 0, sizeof(bu)), pri = (rand() << 15) + rand();
    }
};
typedef Node* pnode;

int cnt(pnode nd){
    return nd? nd->cnt: 0;
}

void upd(pnode nd){
    if(!nd) return;
    nd->cnt = 1 + cnt(nd->l) + cnt(nd->r);
    
    for(int i = 0; i < AL; i++)
        nd->bu[i] = (nd->l? nd->l->bu[i]: 0) + (nd->r? nd->r->bu[i]: 0);
    nd->bu[nd->ca]++;
}

void apply(pnode nd){
    if(nd) nd->rev ^= 1;
}

void push(pnode nd){
    if(nd && nd->rev)
        swap(nd->l, nd->r), apply(nd-> l), apply(nd -> r), nd->rev = 0;
}

void split(pnode t, pnode &l, pnode &r, int key, int add){
    if(!t)
        return void(l = r = NULL);
    push(t);
    int mykey = add + cnt(t->l) + 1;
    if(mykey <= key)
        split(t->r, t->r, r, key, mykey), l = t;
    else
        split(t->l, l, t->l, key, add), r = t;
    upd(t);
}

void merge(pnode &t, pnode l, pnode r){
    push(l), push(r);
    if(!l || !r)
        t = l? l: r;
    else if(l->pri > r->pri)
        merge(l->r, l->r, r), t = l;
    else
        merge(r->l, l, r->l), t = r;
    upd(t);
}

void insert(pnode &t, pnode it){
    if(!t)
        t = it;
    else if(it->pri > t->pri)
        it->l = t, t = it;
    else
        insert(t->r, it);
    upd(t);
}

int n, m;
string st;

ll fastPow(ll a, ll b){
    ll ret = 1;
    while(b){
        if(b & 1)
            ret = ret * a % MOD;
        a = a * a % MOD, b >>= 1;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    srand(8000000);
    
    fc[0][0] = fc[0][1] = 1;
    for(ll i = 1; i < maxN; i++)
        fc[i][0] = fc[i - 1][0] * i % MOD, fc[i][1] = fastPow(fc[i][0], MOD - 2);
    
    cin >> n >> m >> st;
    
    pnode head = NULL;
    for(char c: st) insert(head, new Node(c - 'a'));
    
    while(m--){
        int ty, l, r;
        cin >> ty >> l >> r;
        pnode two, thr;
        split(head, head, two, l - 1, 0);
        split(two, two, thr, r - l + 1, 0);
        if(ty == 1)
            apply(two);
        else
            cout << perm(two->bu) << '\n';
        merge(head, head, two);
        merge(head, head, thr);
    }
    
}

