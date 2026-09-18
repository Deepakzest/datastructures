class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int,vector<pair<int,int>>>adjacency_list;
            for(auto it:edges)
            {
                adjacency_list[it[0]].push_back({it[1],it[2]});
                adjacency_list[it[1]].push_back({it[0],it[2]});
            }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>PQ;//min heap
        vector<bool>visited(V+1,false);
        PQ.push({0,0});
        int mst=0;
        while(!PQ.empty())
        {
            auto it=PQ.top();
            PQ.pop();
            int weight=it.first;
            int node=it.second;
            if(visited[node])continue;
            visited[node]=true;
            mst+=weight;
            for(auto it:adjacency_list[node])
            {
                int adjnode=it.first;
                int adjwt=it.second;
                if(!visited[adjnode])
                {
                    PQ.push({adjwt,adjnode});
                }
            }
        }
        return mst;
    }
};
