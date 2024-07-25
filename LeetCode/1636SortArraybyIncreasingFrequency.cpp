class Solution {
public:
    
    static bool custom_comparator(std::pair<int, int>& a, std::pair<int, int>& b){
            if (a.second == b.second)
                return a.first > b.first;
            return a.second < b.second;   
        }

    vector<int> frequencySort(vector<int>& nums) {
        
        int size = nums.size();
        std::map<int, int> count;

        for(int i = 0; i < size; ++i){
            ++count[nums[i]];
        }

        std::vector<std::pair<int, int>> freq(count.begin(), count.end());

        std::sort(freq.begin(), freq.end(), Solution::custom_comparator);

        vector<int> result(size);

        int k = 0;
        for(auto& pair : freq){
            while(pair.second != 0){
                result[k++] = pair.first;
                --pair.second;
            }
        }

        return result;

    }
};