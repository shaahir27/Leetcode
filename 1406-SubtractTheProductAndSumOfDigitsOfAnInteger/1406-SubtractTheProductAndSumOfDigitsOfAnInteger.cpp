// Last updated: 8/3/2026, 11:21:37 PM
class Solution {
public:
    int subtractProductAndSum(int n) {
        
        int pro = 1;
        int sum = 0;

        int div = 1;

        while(n>=div){
            int digit = n%(div*10)/div;
            pro *= digit;
            sum += digit;

            div *=10;
        }

        int ans = pro - sum;
        return ans;
    }
};