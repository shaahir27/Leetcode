// Last updated: 8/3/2026, 11:21:41 PM
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> ans;
        int greater = -1;
       for( int i = arr.size()-1; i>=0; i--)
       {
           ans.push_back(greater);
           greater = max(greater, arr[i]);
       }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};