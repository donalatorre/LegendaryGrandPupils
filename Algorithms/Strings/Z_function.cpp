#include <bits/stdc++.h>
using namespace std;
#define io ios_base::sync_with_stdio(0);cin.tie(0);
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)

// Devuelve el arreglo Z
vector<int> z_function(string &s){
    int L = 0, R = 0,  n = s.length();
    vector<int> z(n);
     for(int i = 1; i < n; i++){
        if(i <= R)
            z[i] = min(z[i-L], R - i + 1);
        while(i + z[i] < n && s[i + z[i]] == s[z[i]])
            z[i]++;
        if(i + z[i] - 1 > R){
            L = i;
            R = i + z[i] - 1;
        }
    }
    return z;
}

int main(){ io
    string A, B;
    cin >> A >> B;
    string z_Arg = B + '$' + A;
    vector<int> z = z_function(z_Arg);
}
