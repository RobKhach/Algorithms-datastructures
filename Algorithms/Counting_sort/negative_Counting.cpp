class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
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

        // for(int i = 0; i < size; ++i){
        //     for(int j = 1; j < size; ++j){
        //         if(nums[i] == nums[j]){
        //             return true;
        //         }
        //     }
        // }

        // return false;

    //     int max = 0;
    //     for(int i = 0; i < nums.size(); ++i){
    //         if(nums[i] > max){
    //             max = nums[i];
    //         }
    //     }

    //     int* count = new int[max + 1]();

    //     for(int i = 0; i < size; ++i){
    //         ++count[nums[i]];
    //     }

    //     for(int i = 0; i < max + 1; ++i){
    //         if(count[i] > 1){
    //             delete[] count;
    //             return true;
    //         }
    //     }
    //     delete[] count;
    //     return false;
     }
};
