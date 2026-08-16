#include <iostream>
#include <stack>
using namespace std;
class MyQueue {
    private:
        stack <int> stin;
        stack <int> stout;
    public:
        MyQueue() {}
    
        void push(int x) {
            stin.push(x);
        }
    
        int pop() {
            if(!stout.empty())
            {
                int result=stout.top();
                stout.pop();
                return result;
            }
            while(!stin.empty())
            {
                int val=stin.top();
                stin.pop();
                stout.push(val);
            }
            int result=stout.top();
            stout.pop();
            return result;
        }

        int peek() {
            if(!stout.empty())
            {

                return stout.top();
            }
            while(!stin.empty())
            {
                int val=stin.top();
                stin.pop();
                stout.push(val);
            }
            return stout.top();
        }

        bool empty() {
            if(stin.empty()&&stout.empty())
            {
                return true;
            }
            else 
            {
                return false;
            }
        }
};