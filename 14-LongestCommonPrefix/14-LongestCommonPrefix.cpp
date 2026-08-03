// Last updated: 8/3/2026, 11:38:25 PM
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string common = "";
        sort(strs.begin(), strs.end());

        int n = strs.size();

        string first_element = strs[0];
        string last_element = strs[n-1];



        for(int i = 0; i<min(first_element.size(), last_element.size()); i++){
            if(first_element[i] == last_element[i]){
                common += first_element[i];
            }
            else{
                break;
            }
        }

        return common;

    }
};