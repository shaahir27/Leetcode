// Last updated: 8/3/2026, 11:22:00 PM
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int sum = 0;
        int count = 0;

        unordered_map<int, int> prevSum;

        for(int i=0; i<nums.size(); i++){
            sum += nums[i];

            if(sum == k){
                count++;
            }

            int rem = sum - k;

            if(prevSum.find(rem) != prevSum.end()){
                count += prevSum[rem];
            }

            prevSum[sum]++;
        }

        return count;

        /*
        for(int i=0; i<nums.size(); i++){

            for(int j=i; j<nums.size(); j++){
                sum += nums[j];
                if(sum == k){
                    count += 1;
                    break;
                }
                else if(sum > k){
                    break;
                }
            } 

            sum = 0;

        }

        return count;

        */
    }
};