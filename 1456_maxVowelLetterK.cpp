#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int maxVowel=0;
        int maximum=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
                maxVowel++;
            if(i>=k)
            {
                if(s[i-k]=='a'||s[i-k]=='e'||s[i-k]=='i'||s[i-k]=='o'||s[i-k]=='u')
                {
                    if(maxVowel>=1)
                        maxVowel--;
                }
            }
            maximum=max(maximum,maxVowel);
        }
        return maximum;
    }
};