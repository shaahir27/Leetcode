// Last updated: 8/3/2026, 11:37:29 PM
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = m-1;
        int right = n-1;
        int index = m+n-1;


        while(right>=0){
            if(left>=0 && nums1[left] > nums2[right]){
                nums1[index] = nums1[left];
                left--;
                index--;
            }
            else{
                nums1[index] = nums2[right];
                right--;
                index--;
            }
        }
    }
};