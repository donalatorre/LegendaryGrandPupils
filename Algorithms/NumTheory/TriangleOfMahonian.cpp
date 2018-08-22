#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define MOD 1000000007

using namespace std;

typedef long long ll;

#define MAXN 35
#define MAXM 5005

ll arr[MAXN][MAXM];

int main() {
    memset(arr, 0, sizeof(arr));
    arr[0][0]=1;
    arr[1][0]=1;

    FOR(i, 0, MAXN) {
        int m = 0;
        while(m < 5000 && arr[i][m] != 0) {
            FOR(j, 0, i+1) {
                arr[i+1][j+m] += arr[i][m];
            }
            m ++;
        }
    }

    return 0;
}
