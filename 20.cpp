#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char>value;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{')
            {
                value.push(s[i]);
            }
            else
            {
                if(s[i]==')')
                {
                    if(value.empty()||value.top()!='(')return false;
                    value.pop();
                }
                else if(s[i]==']')
                {
                    if(value.empty()||value.top()!='[')return false;
                    value.pop();
                }
                else
                {
                    if(value.empty()||value.top()!='{')return false;
                    value.pop();
                }
            }
        }
        return value.empty();
    }
};