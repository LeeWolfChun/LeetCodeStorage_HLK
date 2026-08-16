#include <iostream>
#include <stack>
#include <vector>
#include <cmath>

using namespace std;

class MinStack {
    private:
        stack<int>st;
        stack<int>min_st;
    public:
        MinStack() {};
        void push(int val) 
        {
            st.push(val);
            if(min_st.empty()||min_st.top()>=val)
            {
                min_st.push(val);
            }
        }
        void pop() 
        {
            
            if(min_st.top()==st.top())
            {
                min_st.pop();
            }
            st.pop();
        }
    
        int top() 
        {
            return st.top();
        }

        int getMin() 
        {
            return min_st.top();
        }
};