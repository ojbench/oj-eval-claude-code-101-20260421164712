#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b, c, d, e, f;
    if (!(cin >> a >> b >> c >> d >> e >> f)) return 0;

    long long T = a * b * c; // seconds per day
    long long K = a * b + a + 1;

    long long t0 = d + e * a + f * a * b; // current seconds since start of day
    t0 %= T;

    long long m = min({a, b, c});
    long long best = LLONG_MAX;

    // Find strictly next alignment time (> current)
    for (long long x = 0; x < m; ++x) {
        long long r = ( (__int128)x * K ) % T; // residue within day when S=M=H=x
        long long delta = (r - t0 + T) % T;
        if (delta == 0) delta = T; // strictly next occurrence
        if (delta < best) best = delta;
    }

    cout << best << '\n';
    return 0;
}
