#include <bits/stdc++.h>
using namespace std;

int findPar(int x, vector<int> &par) {
    if(par[x] == x) return x;
    return par[x] = findPar(par[x], par);
}

void unionSet(int a, int b, vector<int> &par, vector<int> &rank) {
    int pa = findPar(a, par);
    int pb = findPar(b, par);

    if(pa == pb) return;

    if(rank[pa] < rank[pb]) {
        par[pa] = pb;
    }
    else if(rank[pb] < rank[pa]) {
        par[pb] = pa;
    }
    else {
        par[pb] = pa;
        rank[pa]++;
    }
}

int spanningTree(int V, vector<vector<int>>& edges) {

    sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b){
        return a[2] < b[2];
    });

    vector<int> par(V), rank(V, 0);

    for(int i = 0; i < V; i++)
        par[i] = i;

    int ans = 0;

    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        if(findPar(u, par) != findPar(v, par)) {
            ans += w;
            unionSet(u, v, par, rank);
        }
    }

    return ans;
}