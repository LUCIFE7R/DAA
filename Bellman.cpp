#include <bits/stdc++.h>
using namespace std;

void Bellman(vector<vector<int>> &Graph, vector<int> &dist, int N, int V, int src){
    dist[src] = 0;
    for(int i =0;i<V-1;i++){
        for(int j =0;j<N;j++){
            int u = Graph[j][0];
            int v = Graph[j][1];
            int wt = Graph[j][2];
            if((dist[u]!=1e9) && ((dist[u]+wt)<dist[v])){
                dist[v] = dist[u] +wt;
            }
        }
    }
}

int main() {
    vector<vector<int>> Graph{{0, 1, 6}, {0, 2, 4}, {0, 3, 5}, {1, 4, -1}, {2, 1, -2}, {2, 4, 3}, {4, 5, 3}, {3, 5, -1}, {3, 4, -2}};
    int N = Graph.size();
    int V = 6;
    vector<int> dist(V,1e9);
    Bellman(Graph, dist, N, V, 0);
    cout<<"Shortest"<<"  "<<"Edge\n";
    for(int i =0;i<V;i++){
        cout<<dist[i]<<"\t "<<i<<"\n";
    }
    cout<<endl;
    return 0;
}