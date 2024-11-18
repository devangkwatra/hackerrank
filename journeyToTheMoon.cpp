void dfs(int i, vector<int>& vis, vector<vector<int>>& adjList, vector<int>& country) {
    vis[i] = 1;
    country.push_back(i);
    for(auto itr : adjList[i]) {
        if (!vis[itr]) {
            dfs(itr, vis, adjList, country);
        }
    }
}


long long journeyToMoon(int n, vector<vector<int>> astronaut) {
    int p = astronaut.size();
    vector<vector<int>> adjList(n);
    vector<int> sizes;
    vector<vector<int>> all;
    vector<int> vis(n, 0);
    for(int i = 0; i < p; i++) {
        int u = astronaut[i][0];
        int v = astronaut[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);       
    }
    
    for(int i = 0; i < n; i++) {
        vector<int> country;
        if (!vis[i]) {
            dfs(i, vis, adjList, country);
        }
        int temp = country.size();
        sizes.push_back(temp);
        all.push_back(country);
    }
    long long ans = 0;
long long totalSum = 0;
int sizesS = sizes.size();

for (int i = 0; i < sizesS; i++) {
    totalSum += sizes[i];
}

for (int i = 0; i < sizesS; i++) {
    totalSum -= sizes[i];
    ans += sizes[i] * totalSum;
}
    return ans;
}
