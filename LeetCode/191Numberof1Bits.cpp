class Solution {
public:
    int hammingWeight(int n) {
        char bit;
        int count = 0;

        while(n != 0){

           bit = n % 2;
           n /= 2;

           if(bit == 1){
            ++count;
           }
 
        }

        return count;
    }
};