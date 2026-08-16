#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>qRotten;
        int freshfruit=0;
        //DÒ CAM HƯ
        for( int r=0; r<grid.size();r++)
        {
            for( int c=0; c<grid[0].size();c++)
            {
                if(grid[r][c]==2)
                {
                    qRotten.push({r,c});
                }
                else if(grid[r][c]==1)
                {
                    freshfruit++;
                }
            }
        }
        //VÒNG LẶP
        int time=0;
        bool finish;
        while(!qRotten.empty())
        {
            //TÍNH THEO TẦNG THỜI GIAN
            int timelevel=qRotten.size();
            finish=true;
            for( int i=0; i<timelevel;i++)
            {
                int r=qRotten.front().first;
                int c=qRotten.front().second;
                qRotten.pop();
                if(r+1<grid.size()&&grid[r+1][c]==1)
                {
                    grid[r+1][c]=2;
                    qRotten.push({r+1,c});
                    freshfruit--;
                    finish=false;
                }
                if(r-1>=0&&grid[r-1][c]==1)
                {
                    grid[r-1][c]=2;
                    qRotten.push({r-1,c});
                    freshfruit--;
                    finish=false;
                }
                if(c+1<grid[0].size()&&grid[r][c+1]==1)
                {
                    grid[r][c+1]=2;
                    qRotten.push({r,c+1});
                    freshfruit--;
                    finish=false;
                }
                if(c-1>=0&&grid[r][c-1]==1)
                {
                    grid[r][c-1]=2;
                    qRotten.push({r,c-1});
                    freshfruit--;
                    finish=false;
                }
            }
            if(finish)
            {
                break;
            }
            else 
            {
                time++;
            }
        }
        return (freshfruit==0)?time:-1;
    }
};