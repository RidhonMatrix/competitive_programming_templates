///bfs
bool detect(int v, int vis[], vector<int> adj[]){
        vis[v] = 1;
        
        queue<pair<int,int>> q;
        q.push({v,-1});
        while(!q.empty()){
            int node = q.front().first;
            int par  = q.front().second;
            q.pop();
            for(int i = 0; i < adj[node].size(); ++i){
                int child = adj[node][i];
                if(!vis[child]){
                    vis[child] = 1;
                    q.push({child,node});
                }
                else if(par != child){
                        return true;
                }
            }
        }
        return false;
}

//dfs
bool dfs(int v, int vis[], vector<int> adj[], int par){
        vis[v] = true;
        
        for(int i = 0; i < adj[v].size(); ++i){
            int child = adj[v][i];
            if(!vis[child]){
                if(dfs(child,vis,adj,v)) return true;
            }
            else if(par != child){
                return true;
            }
        }
        return false;
}

//cycle in directed graph

stack<int> st;
 
bool cycleCheck(int v, vector<int> adj[], int vis[], int pathVis[])
{
    st.push(v);
    vis[v] = 1;
    pathVis[v] = 1;
    for (auto child : adj[v])
    {
        if (!vis[child])
        {
            if (cycleCheck(child, adj, vis, pathVis) == true)
                return true;
        }
        else if (pathVis[child])
        {
            st.push(child);
            return true;
        }
    }
    st.pop();
    pathVis[v] = 0;
    return false;
}
 
void solve()
{
    int n, m;
    cin >> n >> m;
 
    vector<int> adj[m + 5];
    int vis[n + 5] = {0};
    int pathVis[n + 5] = {0};
 
    int x, y;
    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y;
        adj[x].push_back(y);
    }
    bool path = false;
    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i])
        {
            if (cycleCheck(i, adj, vis, pathVis) == true)
            {
                path = true;
                break;
            }
        }
    }
    vector<int> ans;
    if (path)
    {
        int tmp = st.top();
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
            if (ans.back() == tmp and ans.size() != 1)
                break;
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); ++i)
            cout << ans[i] << ' ';
        cout << endl;
    }
    else
        cout << "IMPOSSIBLE" << '\n';
}
