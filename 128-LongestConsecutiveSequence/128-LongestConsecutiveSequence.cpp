// Last updated: 8/3/2026, 11:37:23 PM
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();

        if(n == 0) return 0;
        if(n == 1) return 1;
        
        int maxi = INT_MIN;

        unordered_set<int> st;

        for(int i=0; i<n; i++){
            st.insert(nums[i]);
        }

        for(auto it : st){
            if(st.find(it - 1) == st.end()){
                int count = 1;
                int x = it;

                while(st.find(x+1) != st.end()){
                    count ++;
                    x++;
                }

                maxi = max(count, maxi);
            }
        }

        return maxi;
    }
};