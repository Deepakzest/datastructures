class Solution {
public:
    
    bool Bipartite(int start,vector<vector<int>>& graph,vector<int>&coloured) {
        queue<int>q;
        q.push(start);
        coloured[start]=0;//red
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto neighbour:graph[node])
            {
                if(coloured[neighbour]==-1)
                {
                    coloured[neighbour]=!coloured[node];//stores the other colour
                    q.push(neighbour);
                }
                else if(coloured[neighbour]==coloured[node])
                {
                    return false;
                }
            
            }
        }
        return true;
        
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int>coloured(graph.size(),-1);
        for(int i=0;i<v;i++)
        {
            if(coloured[i]==-1)
            {
                if(!Bipartite(i,graph,coloured))
                {
                    return false;
                }
                
            }
        }
        return true;
        
       
    }
};
