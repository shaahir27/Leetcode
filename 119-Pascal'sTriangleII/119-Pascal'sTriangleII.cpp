// Last updated: 11/16/2026, 9:34:14 PM
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);

        for (int i = 2; i <= rowIndex; i++)
            for (int j = i - 1; j >= 1; j--)
                row[j] += row[j - 1];

        return row;
    }
};