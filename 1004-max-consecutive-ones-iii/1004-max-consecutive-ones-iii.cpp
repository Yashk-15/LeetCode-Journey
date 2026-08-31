class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxlength = 0;
        int left = 0;
        int right = 0;
        int zeroes = 0;

        while (right < nums.size()) {
            if (nums[right] == 0) {
                zeroes++;
            }
            while (zeroes > k) {
                if (nums[left] == 0) {
                    zeroes--;
                }
                left++;
            }
            int length = right - left + 1;

            maxlength = max(maxlength, length);
            right++;
        }
        return maxlength;
    }
};