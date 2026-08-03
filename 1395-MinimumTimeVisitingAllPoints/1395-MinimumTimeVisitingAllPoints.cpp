// Last updated: 8/3/2026, 11:21:38 PM
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {

        int time = 0;
        int n = points.size();
        
        for (int i = 0; i<n-1; i++)
        {
            int x_co_ordinates = abs(points[i][0] - points[i+1][0]);
            int y_co_ordinates = abs(points[i][1] - points[i+1][1]);

            int number_of_diagnol_moves = min(x_co_ordinates, y_co_ordinates);
            int remaining_moves = abs(x_co_ordinates - y_co_ordinates);
            time = time + remaining_moves + number_of_diagnol_moves;
        }

        return time;
    }
};