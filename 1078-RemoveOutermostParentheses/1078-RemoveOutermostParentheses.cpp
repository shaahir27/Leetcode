// Last updated: 8/3/2026, 11:21:49 PM
class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        string ans = "";

        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                count += 1;

                if(count == 1) continue;
                ans.push_back(s[i]);
            }
            else if(s[i] == ')'){
                count -= 1;

                if(count == 0) continue;
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};