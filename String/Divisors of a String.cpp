#include<bits/stdc++.h>
using namespace std;
int32_t main() {
ios_base::sync_with_stdio(0);
cin.tie(0);
string s; cin >> s;
int ans = 0;
int n = s.size();
for (int len = 1; len <= n / 2; len++) {
bool ok = true;
for (int i = 0; i + len - 1 < n; i += len) {
ok &= get_hash(i, i + len - 1) == get_hash(0, len - 1);
}
ans += ok;
}
return 0;
}
