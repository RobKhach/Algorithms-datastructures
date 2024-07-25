class Solution {
public:
    string sortSentence(string s) {

        int size = s.size();
        string result;
        result.reserve(size);

        char word_index = '1';

        for(int i = 0; i < size; ++i){
            if(s[i] == word_index ){

                int j = i;
                while(s[j] != ' ' && j > 0){
                    --j;
                }
               
                while(s[j] != word_index){
                    if(s[j] == ' '){
                        ++j;
                    }
                    result.push_back(s[j]);
                    ++j;
                }

                ++word_index;
                result.push_back(' ');
                i = -1;
            }
        }

        result.pop_back();
        std::cout << result;

        return result;
    }
};