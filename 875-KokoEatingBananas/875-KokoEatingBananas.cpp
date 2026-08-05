// Last updated: 8/5/2026, 10:21:44 PM
1class Solution {
2private:
3    long long findHour(vector<int>& piles, int hour){
4        long long totalHour = 0;
5
6        for(int i=0; i<piles.size(); i++){
7            totalHour += ceil((double)piles[i] / hour);
8        }
9        
10        return totalHour;
11    }
12
13    int maxElement(vector<int>& piles){
14        int n = piles.size();
15        int max = piles[0];
16
17        for(int i=1; i<n; i++){
18            if(piles[i] > max){
19                max = piles[i];
20            }
21        }
22
23        return max;
24    }
25
26public:
27    int minEatingSpeed(vector<int>& piles, int h) {
28        int range = maxElement(piles);
29
30        int low = 1;
31        int high = range;
32
33        while(low<=high){
34            int mid = low + (high-low)/2;
35
36            long long totalHour = findHour(piles, mid);
37
38            if(totalHour <= h){
39                high = mid-1;
40            }
41            else{
42                low = mid+1;
43            }
44        }
45
46        return low;
47    }
48};