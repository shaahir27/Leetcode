// Last updated: 8/14/2026, 10:06:53 PM
1class Solution {
2public:
3    int findKthPositive(vector<int>& arr, int k) {
4
5        int low = 0;
6        int high = arr.size()-1;
7
8        while(low <= high){
9            int mid = low + (high-low)/2;
10
11            int missing = arr[mid] - (mid + 1);
12
13            if(k > missing){
14                low = mid+1;
15            }
16            else{
17                high = mid-1;
18            }
19        }
20        
21        return low + k; // k + high + 1
22        /*
23        for(int i=0; i<arr.size(); i++){
24            if(arr[i] <= k) k++;
25            else break;
26        }
27
28        return k;        
29        */
30    }
31};