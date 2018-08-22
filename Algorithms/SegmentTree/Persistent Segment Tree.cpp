//
//  main.cpp
//  c
//
//  Created by Adán López Alatorre on 9/12/17.
//  Copyright © 2017 Adán López Alatorre. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <map>

using namespace std;

typedef pair<int, int> ii;

const int maxN = 1e6;

struct Node{
    Node *l, *r;
    int count;
    Node(int count, Node *l, Node *r):count(count), l(l), r(r){}
    Node * insert(int, int, int);
};
Node * segTrees[maxN + 1];

Node * Node::insert(int left, int right, int pos){
    if(pos < left || pos >= right)
        return this;
    if(left + 1 == right)
        return new Node(count + 1, segTrees[0], segTrees[0]);
    int m = (left + right) >> 1;
    return new Node(count + 1, l -> insert(left, m, pos), r -> insert(m, right, pos));
}
int solve(Node * last, Node * first, int left, int right, int k){
    if(left + 1 == right)
        return left;
    int m = (left + right) >> 1, dif = last -> l -> count - first -> l -> count;
    if(dif < k)
        return solve(last -> r, first -> r, m, right, k - dif);
    return solve(last -> l, first -> l, left, m, k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q, x, y, k, arr[maxN], vals[maxN];
    segTrees[0] = new Node(0, NULL, NULL);
    segTrees[0] -> l = segTrees[0] -> r = segTrees[0];
    while(cin >> n >> q){
        map<int, int> myMap;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            myMap[arr[i]];
        }
        int valSize = 0;
        for(map<int, int>::iterator it = myMap.begin(); it != myMap.end(); it++){
            it -> second = valSize;
            vals[valSize++] = it -> first;
        }
        for(int i = 1; i <= n; i++)
            segTrees[i] = segTrees[i - 1] -> insert(0, valSize, myMap[arr[i - 1]]);
        while(q--){
            cin >> x >> y >> k;
            cout << vals[solve(segTrees[y], segTrees[x - 1], 0, valSize, k)] << '\n';
        }
    }
}
