#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int destination) {
        unodered_map <int,vector<int>> adj;
        for(const auto& edge:edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        queue <int> q;
        q.push(start);
        unordered_set<int> visited;
        visited.insert(start);

        while(!p.empty())
        {
            int node=q.pop();
            if(node == destination)
            {
                return true;
            }
            for(auto neighbor : adj[node])
            {
                if(!visited.count(neighbor))
                {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
        return false;
    }
};