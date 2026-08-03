// Last updated: 8/3/2026, 11:21:28 PM
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int score = 0;
        vector<int> num = {a, b, c};
        sort(num.begin(), num.end());

        while(num[1] != 0 && num[2] != 0){
            
            if(num[0] != 0 && num[2] >= num[1]){
                num[0] --;
                num[2] --;
                score ++;
            }
            else if(num[0] != 0 && num[1] > num[2]){
                num[0] --;
                num[1] --;
                score ++;
            }
            else{
                num[1] --;
                num[2] --;
                score ++;
            }
        }
        return score;
    }
};