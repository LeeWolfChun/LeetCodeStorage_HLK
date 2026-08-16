#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack <int>queueDay;
        int n=temperatures.size();
        vector<int>result(n);
        for(int i=0; i<n; i++)
        {
            while (!queueDay.empty()
            &&temperatures[i]>temperatures[queueDay.top()])
            {
                int dayResult=queueDay.top();
                queueDay.pop();
                result[dayResult]=i-dayResult;
            }
            queueDay.push(i);
        }
        return result;
    }
};