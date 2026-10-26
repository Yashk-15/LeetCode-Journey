class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int sum = 1, i = 1;
        int peak = 1, down = 0;

        while (i < n) {
            if (ratings[i] == ratings[i - 1]) {
                sum++;
                i++;
                peak = 1;
                down = 0;
                continue;
            }

            peak = 1;
            while (i < n && ratings[i] > ratings[i - 1]) {
                peak++;
                sum += peak;
                i++;
            }

            down = 0;
            while (i < n && ratings[i] < ratings[i - 1]) {
                down++;
                sum += down;
                i++;
            }

            sum += max(0, down - peak + 1);
        }

        return sum;
    }
};