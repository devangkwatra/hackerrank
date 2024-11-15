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
        if (curWeight > path[curNode]) continue;        // ---> important as it avoids stale entries, paths which already have a better weight are not processed with the older greater weights.
        for(auto itr : adjList[curNode]) {
            int newWeight = itr.first;
            int newNode = itr.second;
            if (newWeight + curWeight < path[newNode]) {
                path[newNode] = newWeight + curWeight;
                pq.push({path[newNode], newNode});
            }
        }
    }
    for(auto& itr : path) {
        if (itr == 1e9)
            itr = -1;
    }
    path.erase(path.begin() + s);
    path.erase(path.begin());
    
    return path;
}
