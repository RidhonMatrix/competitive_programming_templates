vector<int>edge[2005];
bool vis[2005];
bool col[2005];
 
bool dfs(int v,bool c){
    vis[v]=true;
    col[v]=c;
    for(int i=0;i<edge[v].size();i++){
        int child=edge[v][i];
        if(vis[child]==0){
 
            bool res = dfs(child,c^1);
            if(res==false) return false;
        }
        else{
            if(col[v]==col[child]){
                return false;
            }
        }
    }
    return true;
}
 
void solve(){
    int n,e;
    cin>>n>>e;
    int u,v;
 
    for(int i=1;i<=n;i++) edge[i].clear(), vis[i]=false;
 
    for0(e){
        cin>>u>>v;
        edge[u].pb(v);
        edge[v].pb(u);
    }
 
 
    mem(vis,false);
    mem(col,false);
    bool flag=true;
 
    for(int i=1;i<=n;i++){
        if(vis[i]==false){
            if(dfs(i,0)==false){
                flag=false;
            }
        }
    }
 
 
    if(flag){
        cout<<"bipartite"<<endl;
    }else cout<<"not bipartite"<<endl;
}
