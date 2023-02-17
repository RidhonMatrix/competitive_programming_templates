int par[100005];
 
void make_set(int v){
    par[v]=v;
}
 
int find(int r){
    if(par[r]==r) return r;
    par[r]=find(par[r]);
    return par[r];
}
 
void union1(int a,int b){
    int u=find(a);
    int v=find(b);
    if(u==v) return;
    else par[u]=v;
}
 
void solve(){
    int n,m;cin>>n>>m;
    string str;
    for(int i=1;i<=n;i++){
        make_set(i);
    }
    int a,b;
    while(m--){
        cin>>str>>a>>b;
        if(str=="union"){
            union1(a,b);
        }else{
            if(find(a)==find(b)){
                cout<<"YES"<<endl;
            }else cout<<"NO"<<endl;
        }
    }
}


///////////////
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

ll par[100005];
ll Size[100005];
void make_set(int v)
{
    par[v] = v;
    Size[v] = 1;
}

int find(int r)
{
    if (par[r] == r)
        return r;
    par[r] = find(par[r]);
    return par[r];
}

// void union1(int a, int b)
// {
//     int u = find(a); // leader
//     int v = find(b);
//     if (u == v)
//         return;
//     else
//     {
//         // par[v] = u;
//         if (Size[u] > Size[v])
//         {
//             par[v] = u;
//             Size[u] += Size[v];
//         }
//         else
//         {
//             par[u] = v;
//             Size[v] += Size[u];
//         }
//     }
// }

void union1(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (Size[a] < Size[b])
            swap(a, b);
        par[b] = a;
        Size[a] += Size[b];
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        make_set(i);
    int x, y;
    ll mxSize = 1, mxCmp = n;
    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y;
        // deb2(x, y);
        // deb2(find(x), find(y));
        if (find(x) != find(y))
            mxCmp--;
        union1(x, y);
        // deb2(Size[find(x)], Size[find(y)]);
        mxSize = max(max(Size[find(x)], mxSize), Size[find(y)]);
        cout << mxCmp << ' ' << mxSize << ' ' << endl;
    }
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










