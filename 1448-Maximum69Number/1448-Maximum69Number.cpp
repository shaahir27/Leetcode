// Last updated: 8/3/2026, 11:21:33 PM
class Solution {
public:
    int maximum69Number (int num) {
        int add = 0;
        int div = 1;

        while(num >= div){
            int digit = (num%(div*10))/div;
            
            if(digit == 6){
                add = 3*div;
            }
            div = div * 10;
        }
        num += add;
            
        return num;
    }
};