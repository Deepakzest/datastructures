class DisjointSet{
  public:
  vector<int>rank;
  vector<int>parent;
  DisjointSet(int V)
  {
      rank.resize(V+1);
      parent.resize(V+1);
      for(int i=0;i<=V;i++)
      {
          parent[i]=i;
      }
  }
  int findparent(int node)
  {
      if(parent[node]==node)
      {
          return node;
      }
      return parent[node]=findparent(parent[node]);
  }
  void unionbyrank(int u,int v)
  {
      int parent_of_u=findparent(u);
      int parent_of_v=findparent(v);
      if(parent_of_u==parent_of_v)
      {
          return;
      }
      if(rank[parent_of_u]==rank[parent_of_v])
      {
          parent[parent_of_u]=parent_of_v;
          rank[parent_of_v]++;
      }
      else if(rank[parent_of_u]>rank[parent_of_v])
      {
          parent[parent_of_v]=parent_of_u;
      }
      else
      {
          parent[parent_of_u]=parent_of_v;
      }
  }
};

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<pair<int,pair<int,int>>>datastructure;
        for(auto it:edges)
        {
            datastructure.push_back({it[2],{it[0],it[1]}});
        }
        DisjointSet set(V);
        int mst=0;
        sort(datastructure.begin(),datastructure.end());
        for(auto it:datastructure)
        {
            int u=it.second.first;
            int v=it.second.second;
            int dist=it.first;
            if(set.findparent(u)!=set.findparent(v))
            {
                mst+=dist;
                set.unionbyrank(u,v);
            }
        }
        return mst;
        // code here
        
    }
};
