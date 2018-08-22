//
//  main.cpp
//  How many trees
//
//  Created by AdÃÂ¡n LÃÂ³pez Alatorre on 10/27/17.
//  Copyright ÃÂ© 2017 AdÃÂ¡n LÃÂ³pez Alatorre. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <fstream>
#include <deque>
#include <set>
#include <iomanip>
#include <cmath>
#include <climits>
#include <stack>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
#define FIRST first.first
#define SECOND first.second
#define THIRD second
const int maxN = 1e5, MOD = 1E9 + 7;
int HEIGHT, n;
ll d[maxN], t[maxN << 1];

void apply(int p, ll value) {
    t[p] = value;
    if (p < n) d[p] = value;
}

void build(int p) {
    while (p > 1) p >>= 1, t[p] = max(max(t[p<<1], t[p<<1|1]), d[p]);
}

void push(int p) {
    for (int s = HEIGHT; s > 0; --s) {
        int i = p >> s;
        if (d[i] != 0) {
            apply(i<<1, d[i]);
            apply(i<<1|1, d[i]);
            d[i] = 0;
        }
    }
}

void change(int l, int r, ll value) {
    l += n, r += n;
    int l0 = l, r0 = r;
    for (; l < r; l >>= 1, r >>= 1) {
        if (l&1) apply(l++, value);
        if (r&1) apply(--r, value);
    }
    build(l0);
    build(r0 - 1);
}

ll query(int l, int r) {
    l += n, r += n;
    push(l);
    push(r - 1);
    ll res = LLONG_MIN;
    for (; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = max(res, t[l++]);
        if (r&1) res = max(t[--r], res);
    }
    return res;
}