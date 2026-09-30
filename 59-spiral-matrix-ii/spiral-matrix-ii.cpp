
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> mat(n, vector<int>(n));

        int left = 0;
        int right = n - 1;
        int top = 0;
        int bottom = n - 1;

        int k = 1;

        while (left <= right && top <= bottom) {

            // Top: left -> right
            for (int col = left; col <= right; col++) {
                mat[top][col] = k++;
            }
            top++;

            // Right: top -> bottom
            for (int row = top; row <= bottom; row++) {
                mat[row][right] = k++;
            }
            right--;

            // Bottom: right -> left
            for (int col = right; col >= left; col--) {
                mat[bottom][col] = k++;
            }
            bottom--;

            // Left: bottom -> top
            for (int row = bottom; row >= top; row--) {
                mat[row][left] = k++;
            }
            left++;
        }

        return mat;
    }
};