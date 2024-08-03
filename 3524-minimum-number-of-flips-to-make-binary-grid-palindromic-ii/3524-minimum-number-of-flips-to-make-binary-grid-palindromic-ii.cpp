class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int numRows = grid.size();
        int numCols = grid[0].size();
        int flipCount = 0;

        int c=0;

        // for(int i=0;i<1e6;i++) c++;

        // Check the center cell if both dimensions are odd
        if (numRows % 2 == 1 && numCols % 2 == 1) {
            if (grid[numRows / 2][numCols / 2] == 1) {
                flipCount += 1;
            }
        }

        vector<int> shiftCounts(3, 0);

        // Count flips needed for rows if the number of rows is odd
        if (numRows % 2 == 1) {
            int left = 0, right = numCols - 1;
            while (left < right) {
                int sum = grid[numRows / 2][left] + grid[numRows / 2][right];
                shiftCounts[sum] += 1;
                left += 1;
                right -= 1;
            }
        }

        // Count flips needed for columns if the number of columns is odd
        if (numCols % 2 == 1) {
            int top = 0, bottom = numRows - 1;
            while (top < bottom) {
                int sum = grid[top][numCols / 2] + grid[bottom][numCols / 2];
                shiftCounts[sum] += 1;
                top += 1;
                bottom -= 1;
            }
        }

        // Update the flip count based on shift counts
        if (shiftCounts[2] % 2 == 1) {
            if (shiftCounts[1] > 0) {
                flipCount += shiftCounts[1];
            } else {
                flipCount += 2;
            }
        } else {
            flipCount += shiftCounts[1];
        }

        // Handle the corners of each 2x2 block
        for (int row = 0; row < numRows / 2; ++row) {
            for (int col = 0; col < numCols / 2; ++col) {
                int topLeft = grid[row][col];
                int bottomLeft = grid[numRows - 1 - row][col];
                int topRight = grid[row][numCols - 1 - col];
                int bottomRight = grid[numRows - 1 - row][numCols - 1 - col];

                int sum = topLeft + bottomLeft + topRight + bottomRight;

                if (sum != 0 && sum != 4) {
                    flipCount += min(sum, 4 - sum);
                }
            }
        }

        return flipCount;
    }
};
