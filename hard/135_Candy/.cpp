class Solution {
public:
    int candy(vector<int>& rating) {
        int n = rating.size();
        if (n ==1 ) return 1;
        int total = 0;
        vector <int> crit(n,1);
        if (rating[0] > rating[1]) crit[0] = 2;
        for ( int i = 1; i < n; i ++) {
            if (rating[i] > rating[i-1]) {
                crit[i] = crit[i-1] + 1;
            }
        }
        total += crit[n-1];
        for (int i = n - 2; i >= 0; i--) {
            if(rating[i] > rating[i + 1]) {
                crit[i] =max(crit[i +1] + 1,crit[i]);
            }
            total += crit[i];
        }
        return total;
    }
};
