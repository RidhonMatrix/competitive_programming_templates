int lcp(int i, int j, int x, int y) { // O(log n)
int l = 1, r = min(j - i + 1, y - x + 1), ans = 0;
while (l <= r) {
int mid = l + r >> 1;
if (get_hash(i, i + mid - 1) == get_hash(x, x + mid - 1)) {
ans = mid;
l = mid + 1;
}
else {
r = mid - 1;
}
}
return ans;
}

///Find the largest substring that occurs more
than k times


int n;
int max_oc(int len) {
map<pair<int, int>, int> mp;
for (int i = 0; i + len - 1 < n; i++) {
mp[get_hash(i, i + len - 1)]++;
}
int ans = 0;
for (auto [x, y]: mp) {
ans = max(ans, y);
}
return ans;
}
int32_t main() {
ios_base::sync_with_stdio(0);
cin.tie(0);
prec();
string s; cin >> s;
build(s);
int k; cin >> k;
n = s.size();
int l = 1, r = s.size(), ans = -1;
while (l <= r) {
int mid = (l + r) >> 1;
if (max_oc(mid) >= k) {
ans = mid;
l = mid + 1;
}
else {
r = mid - 1;
}
}
cout << ans << '\n';
return 0;
}
