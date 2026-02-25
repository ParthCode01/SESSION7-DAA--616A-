#include <bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>>& edges) {

    vector<vector<pair<int,int>>> g(V);

    for(int i = 0; i < edges.size(); i++) {
        int a = edges[i][0];
        int b = edges[i][1];
        int c = edges[i][2];

        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    vector<int> vis(V, 0);

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > q;

    q.push({0, 0});

    int ans = 0;

    while(!q.empty()) {

        int wt = q.top().first;
        int nd = q.top().second;
        q.pop();

        if(vis[nd]) continue;

        vis[nd] = 1;
        ans += wt;

        for(auto x : g[nd]) {
            int v = x.first;
            int w = x.second;

            if(!vis[v]) {
                q.push({w, v});
            }
        }
    }

    return ans;
}