#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int c;
        scanf("%lld", &c);
        int a = 0, b = 0;
        int ind = -1;
        for (int i = 0; i < 32; i++) {
            if (c & (1 << i)) {
                ind = i;
            }
        }
        for (int i = 0; i <= ind; i++) {
            if (c & (1 << i)) {
                if (i == ind) a += (1 << i);
                else b += (1 << i);
            } else {
                a += (1 << i);
                b += (1 << i);
            }
        }
        printf("%lld\n", a * b);
    }
}
