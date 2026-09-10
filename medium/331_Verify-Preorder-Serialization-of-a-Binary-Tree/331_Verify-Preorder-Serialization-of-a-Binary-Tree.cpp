#include <iostream>
using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        string token;
        int slot = 1;
        while (getline(ss,token,',')) {
            if(slot <= 0 || token == "") {
                return false;
            } else if (token == "#" ) {
                slot--;
            } else {
                slot++;
            }
        }
        return  slot == 0 ? true : false;
    } 
};