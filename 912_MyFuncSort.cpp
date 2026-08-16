#include <iostream>
using namespace std;
class Solution {
public:
    /*void heapify(vector<int>&nums,int n, int i)
    {
        int l=2*i+1, r=2*i+2;
        int largest=i;
        if(l<n&&nums[l]>nums[largest])
        {
            largest=l;
        }
        if(r<n&&nums[r]>nums[largest])
        {
            largest=r;
        }
        if(largest!=i)
        {
            swap(nums[i],nums[largest]);
            heapify(nums,largest);
        }
    }*/
    void heapify(vector<int>&nums,int i,int n)
    {
        int largest=i;
        while(true)
        {
            int l=i*2+1, r=i*2+2;
            if(l<n&&nums[l]>nums[largest])
            {
                largest=l;
            }
            if(r<n&&nums[r]>nums[largest])
            {
                largest=r;
            }
            if(largest==i)
            {
                break;
            }            
            swap(nums[largest],nums[i]);
            i=largest;
        }
    }
    vector<int> sortArray(vector<int>& nums) 
    {
        int n=nums.size();
        for(int i=n/2-1; i>=0;i--)
        {
            heapify(nums,n,i);
        }
        for(int i=n-1;i>=0; i--)
        {
            swap(nums[0],nums[i]);
            heapify(nums,0,i);
        }
        return nums;
    }
};