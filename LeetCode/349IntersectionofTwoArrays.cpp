class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        std::vector<int> inter;
        int size1 = nums1.size();
        int size2 = nums2.size();

        for(int i = 0; i < size1; ++i){
            for(int j = 0; j < size2; ++j){
                if(nums1[i] == nums2[j]){
                    inter.push_back(nums1[i]);
                }
            }
        }

        std::sort(inter.begin(), inter.end());
        auto last = std::unique(inter.begin(), inter.end());
        inter.erase(last, inter.end());
        
        return inter;
        

    }
};