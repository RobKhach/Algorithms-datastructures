class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result(m + n);
        int i = 0, j = 0, k = 0;
        while(i < m && j < n){
            if(nums1[i] <= nums2[j]){
                result[k] = nums1[i];
                ++i;
            }else{
                result[k] = nums2[j];
                ++j;
            }
            ++k;
        }

        while(i < m){
            result[k] = nums1[i];
            ++i;
            ++k;
        }

        while(j < n){
            result[k] = nums2[j];
            ++j;
            ++k;
        }

        for(int i = 0; i < m + n; ++i){
            nums1[i] = result[i];
        }

    }
};