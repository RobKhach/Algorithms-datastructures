class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int size = nums.size();
        int max = nums[0];
        int min = nums[0];

        for(int i = 1; i < size; ++i){
            if(nums[i] > max){
                max = nums[i];
            }

            if(nums[i] < min){
                min = nums[i];
            }
        }
                    //1000000000
        if((max < 1000000) && (min > -1000000)){ //2147483647

        std::cout << "Hello from counting sort " << std::endl;
        int shift = (min < 0) ? -min : 0;
        int range = max + shift + 1;

        int count[range];
        for(int i = 0; i < range; ++i){
            count[i] = 0;
        }

        for(int i = 0; i < size; ++i){
            ++count[nums[i] + shift];
            std::cout << count[nums[i] + shift] << " ";

        }

        for(int i = 0; i < range; ++i){
            if(count[i] > 1){
                return true;
            }
        }

        return false;
        }else{
            std::cout << "HI";
            for(int i = 0; i < size; ++i){
                for(int j = i + 1; j < size; ++j){
                    if(nums[i] == nums[j]){
                        return true;
                    }
                }
            }

        return false;
        }
    
     }
};
