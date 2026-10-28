// Last updated: 10/28/2026, 11:22:03 PM
1class Solution {
2public:
3    long long subArrayRanges(vector<int>& nums) {
4        long long sum = 0;
5
6        for(int i=0; i<nums.size(); i++){
7            int highest = nums[i];
8            int lowest = nums[i];
9            for(int j=i; j<nums.size(); j++){
10                if(highest < nums[j]) highest = nums[j];
11                if(lowest > nums[j]) lowest = nums[j];
12
13                sum += (highest - lowest);
14            }
15        }
16
17        return sum;
18    }
19};
20
21
22/*
23Brute force
24
25class Solution {
26public:
27    long long subArrayRanges(vector<int>& nums) {
28        long long sum = 0;
29
30        for(int i=0; i<nums.size(); i++){
31            int highest = nums[i];
32            int lowest = nums[i];
33            for(int j=i; j<nums.size(); j++){
34                if(highest < nums[j]) highest = nums[j];
35                if(lowest > nums[j]) lowest = nums[j];
36
37                sum += (highest - lowest);
38            }
39        }
40
41        return sum;
42    }
43};
44*/