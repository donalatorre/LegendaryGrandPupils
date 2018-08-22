#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef unsigned long long ull;

ull BitCount(ull u) {
     ull uCount = u - ((u >> 1) & 033333333333) - ((u >> 2) & 011111111111);
     return ((uCount + (uCount >> 3)) & 030707070707) % 63;
}

ull flipBits(ull n, int k) {
    ull mask = (1 << k) - 1;
    return ~n & mask;
}

ull flipBits(ull n) {
    return ~n;
}

ull differentBits(ull a, ull b) {
    return BitCount(a ^ b);
}

void getEvenOddBits(ull n) {
    // Para ui, hacerlo con 8 A's o 5's
    ull evenBits = n & 0xAAAAAAAAAAAAAAAA;
    ull oddBits = n & 0x5555555555555555;
}

ull rotateBits(ull n, int d) {
    // d negative for left rotation, positive for right.
    d %= 64;
    return (n >> d) | (n << (64 - d));
}

string toBinary(ull n) {
    string s = "";
    while(n) {
        if (n & 1)  s = "1" + s;
        else        s = "0" + s;
        n >>= 1;
    }
    return s;
}

ui getSetBitsFromOneToN(ull n){
    ui two = 2, ans = 0;
    ull N = n;
    while(n) {
        ans += (N / two) * (two >> 1);
        if ((N & (two - 1)) > (two >> 1) - 1)
            ans += (N & (two - 1)) - (two >> 1) + 1;
        two <<= 1;
        n >>= 1;
    }
    return ans;
}

int main() {
    ull n;
    cin >> n;
    cout << getSetBitsFromOneToN(n) << endl;
    return 0;
}
