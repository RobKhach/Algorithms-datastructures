class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        int half = size / 2;

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
        //2147483647
        if(max < 1000000 && min > -1000000){
        std::cout << "Hello from counting sort " << std::endl;
        int shift = (min < 0) ? -min : 0;
        int range = max + shift + 1;

        int count[range];
        for(int i = 0; i < range; ++i){
            count[i] = 0;
        }

        for(int i = 0; i < size; ++i){
            ++count[nums[i] + shift];
            // std::cout << count[nums[i] + shift] << " ";

        }

        for(int i = 0; i < range; ++i){
            if(count[i] > half){
                std::cout << count[i] << " ";
                return i - shift;
            }
        }

        throw std::runtime_error("Majority element not found");
        }else{

            std::map<int, int> count;

            for(int i = 0; i < size; ++i){
                ++count[nums[i]];
                std::cout << count[nums[i]];
            }

            for(int i = 0; i < size; ++i){
                if(count[nums[i]] > half){
                    return nums[i];
                }
            }
            
            throw std::runtime_error("Majority element not found");

        }

    }
};