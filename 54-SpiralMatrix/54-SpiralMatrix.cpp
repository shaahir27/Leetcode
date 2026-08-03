// Last updated: 8/3/2026, 11:37:43 PM
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        int top = 0, bottom = m-1;
        int left = 0, right = n-1;

        vector<int> ans;

        while(top<=bottom && left<=right){
            
            // left -> right
            for(int i=left; i<=right; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;

            //top to bottom
            for(int i=top; i<=bottom; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            
            if(top<=bottom){

                //right -> left
                for(int i=right; i>=left; i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            
            if(left<=right){

                //bottom to top
                for(int i=bottom; i>=top; i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        
        return ans;
        
    }
};