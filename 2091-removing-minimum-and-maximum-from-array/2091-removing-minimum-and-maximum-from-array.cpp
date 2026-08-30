class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minIndex = 0;
        int maxIndex = 0;

        for(int i = 0; i<nums.size(); i++){
            if( nums[i] < nums[minIndex]) minIndex = i;
            if(nums[i] > nums[maxIndex]) maxIndex = i;
        }
        int left = min(minIndex, maxIndex);
        int right = max(minIndex, maxIndex);

        int front = right + 1;
        int back = nums.size() - left;
        int both = (left + 1) + (nums.size() - right);

        return min(front, min(back,both));
    }
};