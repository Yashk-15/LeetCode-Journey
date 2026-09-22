class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        int maxOnes = 0;
        int maxRow = 0;

        for (int i = 0; i < rows; i++) {
            int ones = 0;

            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 1)
                    ones++;
            }

            if (ones > maxOnes) {
                maxOnes = ones;
                maxRow = i;
            }
        }

        return {maxRow, maxOnes};
    }
};