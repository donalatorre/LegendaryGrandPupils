#include <bits/stdc++.h>

#define PI 3.14159265358979323846
#define EPS 1e-6
#define INF 1000000000

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

#define MAXN 10
#define MOD 1000000007

struct DSU {
    int bel[MAXN];
    vi s[MAXN];

    void reset() {
        FOR(i, 0, MAXN)
            bel[i] = 0, s[i].clear();
    }

    void unir(int a, int b) {
        if (a > b)  swap(a, b);

        FOR(i, 0, s[a].size()) {
            s[b].pb(s[a][i]);
            bel[a] = b;
        }
        s[a].clear();
    }

    int belongs(int x) {
        return bel[x];
    }
};

struct DSU2 {
    int numSets = 0;
    int setSize[MAXN];
    int parent[MAXN];
    int rank[MAXN];

    UnionFind(int n) {
        numSets = n;
        FOR(i, 0, n)    parent[i] = i, setSize[i] = rank[i] = 0;
    }

    void make_set(int i) {
        parent[i] = i;
        rank[i] = 0;
    }

    int find_set(int i) {
        if (i != parent[i])
            parent[i] = find_set(parent[i]);
        return parent[i];
    }

    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            numSets--;
            int x = find_set(i), y = find_set(j);

            if (rank[x] > rank[y]) {
                parent[y] = x;
                setSize[x] += setSize[y];
            }
            else {
                parent[x] = y;
                setSize[y] += setSize[x];

                if (rank[x] == rank[y])     rank[y]++;
            }
        }
    }

    bool isSameSet(int i, int j) {
        return find_set(i) == find_set(j);
    }
};

int main() { _
    auto a = 1;
    return 0;
}

