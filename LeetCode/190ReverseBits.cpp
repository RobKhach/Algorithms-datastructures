class Solution {
public:
    uint32_t reverseBits(uint32_t n) {


        std::bitset<32> bits(n);

        std::string rev_bits = bits.to_string();
        std::reverse(rev_bits.begin(), rev_bits.end());

        uint32_t reversed = std::bitset<32>(rev_bits).to_ulong();

        return reversed;

    }
};