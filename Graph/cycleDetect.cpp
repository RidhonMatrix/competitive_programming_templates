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
