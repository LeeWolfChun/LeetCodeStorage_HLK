#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        // 1. Base case: out of bounds hoặc không phải '1' → return 

        if(r<0||r>=grid.size()||c<0||c>=grid[0].size()||grid[r][c]=='0')
        {
            return;
        }

        // 2. Đánh dấu đã thăm
        
        grid[r][c]='0';

        // 3. DFS 4 hướng: trên, dưới, trái, phải
        dfs(grid,r,c-1);
        dfs(grid,r,c+1);
        dfs(grid,r-1,c);
        dfs(grid,r+1,c);
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        
        // Duyệt từng ô

        for(int i=0; i< grid.size();i++)
        {
            for( int j=0; j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                    dfs(grid,i,j);
                }
            }
        }
        return count;
    }
};