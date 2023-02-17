#include <bits/stdc++.h>
using namespace std;
#define deb(x)       cout << #x << "=" << x << endl
#define deb2(x, y)   cout << #x << "=" << x << "," << #y << "=" << y << endl
#define ll long long
const ll mx=1e5;
ll seg[mx*4],lazy[mx*4],a[mx+4];

void build(ll cur,ll left,ll right){
    if(left == right){
        seg[cur] = a[left];
        return;
    }
    ll mid = (left + right)/2;
    build(cur*2,left,mid);
    build(cur*2+1,mid+1,right);
    seg[cur] = seg[cur*2] + seg[cur*2+1];
}

void pushDown(ll cur,ll left,ll right){
    seg[cur] += (right+1-left) * lazy[cur];
    if(left != right){
        lazy[cur*2] += lazy[cur];
        lazy[cur*2+1] += lazy[cur];
    }
    lazy[cur] = 0;
}

void update(ll cur,ll left,ll right,ll l, ll r,ll val){
    if(lazy[cur] != 0) pushDown(cur,left,right);
    if(l>right || left>r) return;
    if(l<=left && r>=right){
        lazy[cur]+=val;
        pushDown(cur,left,right);
        return;
    }
    ll mid = (left + right)/2;
    update(cur*2,left,mid,l,r,val);
    update(cur*2+1,mid+1,right,l,r,val);
    seg[cur] = seg[cur*2] + seg[cur*2+1];
}

ll query(int cur,int left,int right, int l,int r){
    if(l>right || r<left) return 0;
    if(lazy[cur]!=0) pushDown(cur,left,right);
    if(left >=l && right<=r) return seg[cur];

    int mid = (left + right)/2;
    ll p1 = query(cur*2,left,mid,l,r);
    ll p2 = query(cur*2+1,mid+1,right,l,r);
    return p1+p2;
}

void print(){
    for(int i=1;i<=24;i++) cout<<setw(2)<<i<<" ";
    cout<<endl;
    for(int i=1;i<=24;i++) cout<<setw(2)<<seg[i]<<" ";
    cout<<endl;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    #endif
    int t;cin>>t;
    int n,q;
    int k,x,y;
    ll val;
    int c=1;
    while(t--){
        cout<<"Case"<<" "<<c++<<':'<<endl;
        cin>>n>>q;
        while(q--){
            cin>>k;
            if(k==0){
                cin>>x>>y>>val;
                update(1,1,n,x+1,y+1,val);
            }
            else{
                cin>>x>>y;
                cout<<query(1,1,n,x+1,y+1)<<endl;
            }
        }


        memset(seg,0,sizeof(seg));
        memset(lazy,0,sizeof(lazy));
        memset(a,0,sizeof(a));
    }

    return 0;


}
