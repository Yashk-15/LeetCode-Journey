class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int left = 0;
        int right = 0;
        int maxlength = 0;

        unordered_map<int, int> mpp;

        while (right < fruits.size()) {

            mpp[fruits[right]]++;

            while (mpp.size() > 2) {

                mpp[fruits[left]]--;

                if (mpp[fruits[left]] == 0) {
                    mpp.erase(fruits[left]);
                }

                left++;
            }

            maxlength = max(maxlength, right - left + 1);

            right++;
        }

        return maxlength;
    }
};