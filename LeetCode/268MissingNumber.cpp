class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int sum = size * (size + 1)/2;
        int real_sum = 0;
        for(int i = 0; i < size; ++i){
            real_sum += nums[i];
        }

        return sum - real_sum;
    }
};