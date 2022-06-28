int bfs(){
    vector<int> d(N,INF);
    d[1] = 0;
    deque<int> q;
    q.push_back(1);
    while(!q.empty()){
        int v = q.front();
        q.pop_front();
        for(auto child : g[v]){
            int u = child.first;
            int w = child.second;
            if(d[v] + w < d[u]){
                d[u] = d[v] + w;
                if(w == 1)
                    q.push_back(u);
                else
                    q.push_front(u);
            }
        }
    }
    return d[n] == INF ? -1 : d[n];
}
