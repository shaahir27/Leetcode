// Last updated: 8/3/2026, 11:37:27 PM
class Solution {
public:
    vector<int> generateRow(int rowNum){
        vector<int> row;
        row.push_back(1);

        int ans = 1;

        for(int i=1; i<rowNum; i++){
            ans = ans*(rowNum - i)/i;
            row.push_back(ans);
        }
        return row;
    }

    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> Pascal;
        
        for(int i=1; i<=numRows; i++){
            vector<int> row = generateRow(i);
            Pascal.push_back(row);
        }

        return Pascal;
    }
};