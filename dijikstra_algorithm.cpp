class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<int>distance(V,1e9);
        vector<vector<pair<int,int>>>adjacency_list(V);
        for(auto edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            int dist=edge[2];
            adjacency_list[u].push_back({v,dist});
            adjacency_list[v].push_back({u,dist});
        }
        priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
        >PQ;
        PQ.push({0,src});
        distance[src]=0;
        while(!PQ.empty())
        {
            int dist=PQ.top().first;
            int node=PQ.top().second;
            PQ.pop();
            for(auto neighbour:adjacency_list[node])
            {
                int adjnode=neighbour.first;
                int adjdist=neighbour.second;
                if(dist+adjdist<distance[adjnode])
                {
                    distance[adjnode]=dist+adjdist;
                    PQ.push({distance[adjnode],adjnode});
                }
            }
        }
        return distance;
    }
};
