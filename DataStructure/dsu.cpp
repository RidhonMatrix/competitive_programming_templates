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
