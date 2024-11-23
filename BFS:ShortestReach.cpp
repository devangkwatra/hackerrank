vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    vector<vector<int>> adjList(n + 1);
    for(int i = 0; i < m; i++) {
        adjList[edges[i][0]].push_back(edges[i][1]);
        adjList[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> data(n + 1, -1);
    data[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(auto itr : adjList[node]) {
            if (data[itr] == -1) {
                q.push(itr);
                data[itr] = data[node] + 6;
            }
        }
    }
    data.erase(data.begin() + s);
    data.erase(data.begin());
    return data;
}
