vector<vector<pair<int, int>>> listt(int m, vector<vector<int>>& edges, vector<vector<pair<int,int>>>& adjList) {
    for(int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int x = edges[i][2];
        adjList[u].push_back({x, v});
        adjList[v].push_back({x, u});
    }
    return adjList;      
}

vector<int> shortestReach(int n, int m, vector<vector<int>> edges, int s) {
    vector<vector<pair<int, int>>> adjList(n + 1);
    adjList = listt(m, edges, adjList);
    
    vector<int> path(n + 1, 1e9);
    path[s] = 0;    
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    pq.push({0, s}); // {weight, node}
    
    while(!pq.empty()) {
        int curWeight = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();
        for(auto itr : adjList[curNode]) {
            int newWeight = itr.first;
            int newNode = itr.second;
            if (newWeight + curWeight < path[newNode]) {
                path[newNode] = newWeight + curWeight;
                pq.push({path[newNode], newNode});
            }
        }
    }
    for(int i = 0; i < n + 1; i++) {
        if (path[i] == 1e9)
            path[i] = -1;
    }
    path.erase(path.begin() + s);
    path.erase(path.begin());
    
    for(int i = 0; i < n + 1; i++) cout << path[i] << " ";
    
    return path;
}
