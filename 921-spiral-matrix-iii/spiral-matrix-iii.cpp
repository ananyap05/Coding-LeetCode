class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> directions =  {
                                            {0, 1},  //EAST
                                            {1, 0},  //SOUTH
                                            {0, -1}, //WEST
                                            {-1, 0}  //NORTH
                                          };
        
        vector<vector<int>> result;  
        int step = 0; //how much steps to move
        int dir  = 0; //Which direction

        result.push_back({rStart, cStart});

        while (result.size() < rows * cols) {
            //When we move EAST or WEST, we need to increase our steps by 1
            if (dir == 0 || dir == 2) step++;

            for (int i = 0; i < step; i++) {
                rStart += directions[dir][0];
                cStart += directions[dir][1];

                if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) // check valid
                    result.push_back({rStart, cStart});
            }

            dir = (dir + 1) % 4; // turn to next direction
        }
        return result;
    }
};