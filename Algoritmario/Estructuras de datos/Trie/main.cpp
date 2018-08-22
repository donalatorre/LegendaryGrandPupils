#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <utility>
#include <vector>

#define PI 3.141592653589793
#define EPS 0.000000001
#define INF 1000000000

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define FORC(cont, it) for(typeof((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#include "nodeT.h"
#include "trie.h"

bool compare(const int &a, const int &b){
    return a<b;
}

int main(){ _
    trie t;

    t.addWord("assoc");
    t.addWord("also");
    t.addWord("also");
    t.addWord("tree");
    t.addWord("trie");
    t.addWord("algo");
    t.addWord("all");
    t.addWord("chefe");
    t.addWord("alsoo");
    t.addWord("alsooo");
    t.addWord("alsoooo");
    t.addWord("chefe");
    t.addWord("chefesaurio");
    t.addWord("chefesauriorex");

    cout << t.countPrefixes("a") << endl;
    cout << t.countWords("also") << endl;
    cout << t.countPrefixes("also") << endl;
    cout << t.countWords("chefe") << endl;
    cout << t.countPrefixes("chefe") << endl;
    cout << t.getCantPalabras() << endl;
    cout << t.countWords() << endl;

    return 0;
}

