#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
const int N = 5e4 + 9, p1 = 277, mod1 = 1e9 + 7, p2 = 277, mod2 = 1e9 + 9;
int power(long long n, long long k, int mod){
    int ans = 1 % mod; n %= mod;
    if (n < 0)  n += mod;
    while (k){
        if (k & 1)  ans = (long long)ans * n % mod;
        n = (long long)n * n % mod;
        k >>= 1;
    } return ans;
}
int ip1, ip2;
pair<int, int> pw[N], ipw[N];
void prec(){
    pw[0] = {1, 1};
    for (int i = 1; i < N; i++){
        pw[i].F = 1LL * pw[i - 1].F * p1 % mod1;
        pw[i].S = 1LL * pw[i - 1].S * p2 % mod2;
    }
    ip1 = power(p1, mod1 - 2, mod1);
    ip2 = power(p2, mod2 - 2, mod2);
    ipw[0] = {1, 1};
    for (int i = 1; i < N; i++){
        ipw[i].F = 1LL * ipw[i - 1].F * ip1 % mod1;
        ipw[i].S = 1LL * ipw[i - 1].S * ip2 % mod2;
    }
}

pair<int, int> string_hash(string s)
{
    int n = s.size();
    pair<int, int> hs({0, 0});
    for (int i = 0; i < n; i++)
    {
        hs.F += 1LL * s[i] * pw[i].F % mod1;
        hs.F %= mod1;
        hs.S += 1LL * s[i] * pw[i].S % mod2;
        hs.S %= mod2;
    }
    return hs;
}

pair<int, int> pref[N];
void build(string s)
{
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        pref[i].F = 1LL * s[i] * pw[i].F % mod1;
        if (i)
            pref[i].F = (pref[i].F + pref[i - 1].F) % mod1;
        pref[i].S = 1LL * s[i] * pw[i].S % mod2;
        if (i)
            pref[i].S = (pref[i].S + pref[i - 1].S) % mod2;
    }
}

pair<int, int> get_hash(int i, int j)
{
    assert(i <= j);
    pair<int, int> hs({0, 0});
    hs.F = pref[j].F;
    if (i)
        hs.F = (hs.F - pref[i - 1].F + mod1) % mod1;
    hs.F = 1LL * hs.F * ipw[i].F % mod1;
    hs.S = pref[j].S;
    if (i)
        hs.S = (hs.S - pref[i - 1].S + mod2) % mod2;
    hs.S = 1LL * hs.S * ipw[i].S % mod2;
    return hs;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    prec();
    string a, b;
    cin >> a >> b;
    build(a);
    int ans = 0, n = a.size(), m = b.size();
    auto hash_b = string_hash(b);
    for (int i = 0; i + m - 1 < n; i++)
        ans += get_hash(i, i + m - 1) == hash_b;
    cout << ans << '\n';
}
