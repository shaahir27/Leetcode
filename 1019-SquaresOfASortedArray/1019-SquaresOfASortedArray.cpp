// Last updated: 8/3/2026, 11:21:51 PM
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int index = right;

        vector <int> temp(index+1);

        while(left <= right){
            long long lsquare = 1LL * nums[left]  * nums[left];
            long long rsquare = 1LL * nums[right] * nums[right];

            if(lsquare > rsquare){
                temp[index] = lsquare;
                left++;
                index--;
            }
            else{
                temp[index]= rsquare;
                right--;
                index--;
            }
        }

        return temp;
    }
};