//
//  main.cpp
//  dpp
//
//  Created by Adán López Alatorre on 10/1/17.
//  Copyright © 2017 Adán López Alatorre. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <climits>
#include <stack>
#include <vector>
#include <set>
#include <sstream>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ii, ll> iii;
#define FIRST first.first
#define SECOND first.second
#define THIRD second
typedef vector<ll> vi;
typedef vector<ii> vii;

#define MAXN 100000
#define MOD 1000000007

vii edges[MAXN];// first = cost, second = where
ii arr[MAXN];// shortest paths to all nodes will be stored here
ll n; // size of graph

void dijkstra(ll from, ll to) {
    for(int i = 0; i < n; i++) arr[i].first = INT_MAX;
    priority_queue<iii, vector<iii>, greater<iii> > pq;
    pq.push(iii(ii(0, -1), from));
    while(!pq.empty()){
        iii cur = pq.top();
        pq.pop();
        if(arr[cur.THIRD].first == INT_MAX)
            arr[cur.THIRD] = cur.first;
        else
            continue;
        for(int i = 0; i < edges[cur.THIRD].size(); i++){
            ll cost = edges[cur.THIRD][i].first,
            where = edges[cur.THIRD][i].second;
            if(arr[where].first == INT_MAX)
                pq.push(iii(ii(cur.FIRST + cost, cur.THIRD), where));
        }
    }
}