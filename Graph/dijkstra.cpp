#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << "," << #y << "=" << y << endl
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

#define mxN 100000
#define INF 1e18

vector<pair<long long, int>> edge[mxN + 5];
long long cost[mxN + 5];

void dijkstra(int start, int node)
{
    for (int i = 0; i <= node; ++i)
        cost[i] = INF;
    cost[start] = 0;
    priority_queue<pair<ll, int>> pq;
    pq.push({0, start});
    while (!pq.empty())
    {
        // u parent
        // v child
        ll u_wt = -pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (cost[u] < u_wt)
            continue;
        for (auto it : edge[u])
        {
            ll v_wt = it.first;
            int v = it.second;
            if (cost[v] > u_wt + v_wt)
            {
                cost[v] = u_wt + v_wt;
                pq.push({-cost[v], v});
            }
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    int u, v;
    long long taka;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v >> taka;
        edge[u].push_back({taka, v});
    }
    dijkstra(1, n);
    for (int i = 1; i <= n; ++i)
    {
        cout << cost[i] << ' ';
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int t;cin>>t;
    // int c = 1;
    // while(t--){
    // cout<<"Case "<<c++<<": ";
    solve();
    //}
    return 0;
}
