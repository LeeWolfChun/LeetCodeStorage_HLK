#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
         double sumK=0;
        int n=arr.size();
        int result=0;
        for(int i=0;i<k; i++)
            sumK+=arr[i];
        for(int i=k; i<n;i++)
        {
            if(sumK/(double)k>=threshold)
                result++;
            sumK+=arr[i];
            sumK-=arr[i-k];
        }
        if(sumK/(double)k>=threshold)
            result++;
        return result;
    }
};