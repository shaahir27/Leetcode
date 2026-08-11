// Last updated: 8/11/2026, 10:02:18 PM
1class Solution {
2private:
3    bool verification(vector<int>& weights, int days, int capacity){
4        int totalDays = 1;
5        int load = 0;
6
7
8        for(int i=0; i<weights.size(); i++){
9            load += weights[i];
10            if(load > capacity){
11                totalDays += 1;
12                load = weights[i];
13            }
14        }
15
16        if(totalDays <= days) return true;
17        else return false;
18    }
19
20    int sumWeight(vector<int>& weights){
21        int sum  = 0;
22
23        for(int i=0; i<weights.size(); i++){
24            sum += weights[i];
25        }
26
27        return sum;
28    }
29public:
30    int shipWithinDays(vector<int>& weights, int days) {
31        
32        int low = *max_element(weights.begin(), weights.end());
33        int high = sumWeight(weights);
34
35        while(low<=high){
36            int mid = low + (high - low)/2;
37
38            if(verification(weights, days, mid)){
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