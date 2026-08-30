class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minIndex = 0;
        int maxIndex = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[minIndex]) {
                minIndex = i;
            }

            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }

        int removeFromFront = max(minIndex, maxIndex) + 1;
        int removeFromBack = nums.size() - min(minIndex, maxIndex);
        int removeFromBothSides = min(
            minIndex + 1 + (nums.size() - maxIndex),
            maxIndex + 1 + (nums.size() - minIndex)
        );
        return min(removeFromFront, min(removeFromBack, removeFromBothSides));
    }
};