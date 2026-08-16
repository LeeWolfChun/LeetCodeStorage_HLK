#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void fill(vector<vector<int>>& image, int sr, int sc, int color, int originalColor)
    {
        if(sr<0||sr>=image.size()||sc<0||sc>=image[0].size()||image[sr][sc]!=originalColor)
        {
            return;
        }

        image[sr][sc]=color;
        
        fill(image, sr-1, sc, color, originalColor);
        fill(image, sr+1, sc, color, originalColor);
        fill(image, sr, sc-1, color, originalColor);
        fill(image, sr, sc+1, color, originalColor);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int originalColor= image[sr][sc];

        if(originalColor==color)
        {
            return image;
        }
        fill(image,sr,sc,color,originalColor);
        return image;
    }
};