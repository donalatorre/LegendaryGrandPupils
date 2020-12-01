//  Copyright © 2020 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 200005
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
#define what_is(x) cerr << #x << " is " << x << endl;
#define pii pair < int , int >
#define fi first
#define se second
using namespace std;
typedef long long ll;
 
struct node {
    ll rl, rr, mx, p;
    node *l, *r;
};
 
const ll INF = 1e15;
typedef node * pnode;
ll idx = 0;
node memo[60*MAX];
pnode root;
ll N, Q;
vector<pii>res;

ll mx(pnode x) { return x == NULL ? -INF :  x->mx; }
 
void upd(pnode x) {
    if(! x)
        return;
    x->mx = max(mx(x->l), mx(x->r));
    x->mx = max(x->mx, x->rr);
}
 
void split(pnode n, ll k, pnode & l, pnode & r) {
    if(! n)
        l = r = NULL;
    else if(k < n->rl) // es mayor
        split(n->l, k, l, n->l), r = n;
    else
        split(n->r, k, n->r, r), l = n;
    
    upd(l);
    upd(r);
}
 
void merge(pnode & n , pnode l , pnode r) {
    if( ! l or ! r )
        n = l ? l : r;
    else if(l->p > r->p)
        merge(l->r, l->r, r), n = l;
    else
        merge(r->l, l, r->l), n = r;
    upd(n);
}
 
pnode newRange(ll l, ll r) {
    pnode n = & memo[idx++];
    n->p = rand();
    n->rl = l;
    n->rr = r;
    n->mx = n->rr;
    return n;
}
 
void insert( pnode & n , ll rl, ll rr) {
    pnode l, r, x;
    split(n, rl, l, r);
    x = newRange(rl, rr);
    merge(n, l, x);
    merge(n, n, r);
}

bool intersect(int l1, int r1, int l2, int r2) {
    return !(r1 < l2 or r2 < l1);
}

void find(pnode & n, ll rl, ll rr) {
    if(! n)
        return;
    if(rl > n->mx)
       return;
    if(intersect(rl, rr, n->rl, n->rr))
        res.push_back({n->rl, n->rr});
    
    find(n->l, rl, rr);

    if(rr < n->rl)
        return;

    find(n->r, rl, rr);
}

void print(pnode & n) {
    if(!n)
        return;
    print(n->l);
    cout << n->rl << ", " << n->rr << " " << n->mx << "\n";
    print(n->r);
}

 
int main()
{    
    /* #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
    #endif */
    optimiza_io
    cin >> N >> Q;
    for(int i = 1; i <= N; i ++) {
        int l, r;
        cin >> l >> r;
        insert(root, l, r);
    }

    while(Q --) {
        int l, r;
        cin >> l >> r;
        cout << "Qry " << l << ", " << r << ":\n";
        find(root, l, r);
        for(auto v : res)
            cout << v.fi << " " << v.se << "\n";
        res.clear();
    }
    return 0;
}
