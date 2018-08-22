#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <fstream>
#include <stack>
#include <cmath>
#include <map>
#include <iomanip>
#define FIRST first.first
#define SECOND first.second
#define THIRD second

using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef long long ll;
typedef vector<ll> vd;
typedef vector<vd> Matrix;
const int maxN = 1e6;

iii sa[maxN], aux[maxN];
int inv[maxN], lcp[maxN + 1], values[maxN + 1], n;
string st;

#define a(i) (fir? sa[i].FIRST: sa[i].SECOND)

void radiixSort(bool fir){
    memset(values, 0, sizeof(values));
    for(int i = 0; i < n; i++)
        values[a(i) + 1]++;
    for(int i = 1; i <= n; i++)
        values[i] += values[i - 1];
    for(int i = n - 1; i >= 0; i--)
        aux[--values[a(i) + 1]] = sa[i];
    for(int i = 0; i < n; i++)
        sa[i] = aux[i];
}

void createSuffixArray(){
    for(int i = 0; i < n; i++)
        sa[i] = iii(ii(st[i], 0), i);
    sort(sa, sa + n);
    for(int cnt = 1; cnt <= n; cnt <<= 1){
        for(int i = 0, j = 0; i < n; i = j)
            for(ii cur = sa[i].first; j < n && sa[j].first == cur; j++)
                sa[j].FIRST = inv[sa[j].THIRD] = i;
        for(int i = 0; i < n; i++)
            sa[i].SECOND = (sa[i].THIRD + cnt < n)? sa[inv[sa[i].THIRD + cnt]].FIRST: -1;
        radiixSort(false);
        radiixSort(true);
    }
}

void createLCPArray(){
    for(int i = 0; i < n; i++)
        inv[sa[i].THIRD] = i;
    for(int i = 0, k = 0; i < n; i++, k? k--: k){
        if(inv[i] + 1 == n){
            k = lcp[n - 1] = 0;
            continue;
        }
        int cur = sa[inv[i]].THIRD, next = sa[inv[i] + 1].THIRD;
        for(; max(cur, next) + k < n && st[cur + k] == st[next + k]; k++);
        lcp[inv[i] + 1] = k;
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> st;
    createSuffixArray();
    createLCPArray();
}