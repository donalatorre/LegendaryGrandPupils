#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll root(ll x) {
	ll l = 0, r = 1e9 + 1;
	while (l < r - 1) {
		ll m = (l + r) / 2;
		if (m * m > x)
			r = m;
		else
			l = m;
	}
	return l;
}

int main(){
	
	cout << root(1234*1234) << endl;
	cout << root(64) << endl;
	cout << root(8) << endl;

	return 0;
}