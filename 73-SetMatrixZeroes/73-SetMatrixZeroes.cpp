// Last updated: 8/3/2026, 11:37:38 PM
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        // cols = matrix[0][..];
        // rows = matrix[..][0];

        int col0 = 1;

        int m = matrix.size();
        int n = matrix[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){

                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;

                    if(j == 0){
                        col0 = 0;
                    }
                    else {
                        matrix[0][j] = 0;
                    }
                }
            }
        }

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){

                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        if(matrix[0][0] == 0){
            for(int j=0; j<n; j++){
                matrix[0][j] = 0;
            }
            
        }

        if(col0 == 0){
            for(int i=0; i<m; i++){
                matrix[i][0] = 0;
            }
        }
    }
};