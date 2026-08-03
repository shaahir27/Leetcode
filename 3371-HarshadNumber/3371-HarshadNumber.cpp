// Last updated: 8/3/2026, 11:21:14 PM
class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {

        int sum = 0;
        int div = 1;

        while(x>=div){
            int digit = x%(div*10)/div;

            sum += digit;

            div *= 10;
        }

        if(x%sum == 0){
            return sum;
        }
        else return -1;
        
    }
};