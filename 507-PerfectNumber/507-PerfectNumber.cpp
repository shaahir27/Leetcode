// Last updated: 8/3/2026, 11:22:04 PM
class Solution {
public:
    bool checkPerfectNumber(int num) {

        if(num==1) return false;

        int sum = 1;

        for(int i=2; i*i<num; i++){
            if(num%i == 0){
                sum += (i + num/i);
            }
        }

        if(num == sum) return true;
        else return false;
        
    }
};