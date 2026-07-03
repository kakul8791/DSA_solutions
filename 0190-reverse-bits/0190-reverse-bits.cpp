class Solution {
public:
    int reverseBits(int n) {
        unsigned int ans = 0;
        unsigned int num = n;

        for (int i = 0; i < 32; i++) {
            ans = ans << 1;        // answer mein next bit ke liye jagah
            ans = ans | (num & 1); // n ka last bit add karo
            num = num >> 1;        // n ka last bit hatao
        }

        return ans;
    }
};