/*Rat in Maze
Given a square binary matrix maze[][] containing values 0 and 1, find all possible paths for a rat to travel from the top-left cell
to the bottom-right cell. The rat can move in four directions: up(U), down(D), left(L), and right(R).

1 represents an open cell through which the rat can move.
0 represents a blocked cell that cannot be traversed.
The rat can move only through open cells and cannot visit the same cell more than once in a path. Return all valid paths as strings 
consisting of 'U', 'D', 'L', and 'R', representing the sequence of moves taken by the rat.

Note: Return the paths in lexicographically increasing order. If no valid path exists, return an empty list.

Examples:

Input: maze[][] = [[1, 0, 0, 0], [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1]]
Output: ["DDRDRR", "DRDDRR"]
Explanation: There are two valid paths from the source cell (0, 0) to the destination cell (3, 3).

Input: maze[][] = [[1, 0], [1, 0]]
Output: []
Explanation: No path exists as the destination cell (1, 1) is blocked.
Constraints:

2 ≤ mat.size() ≤ 5
0 ≤ mat[i][j] ≤ 1
mat[i].size() = mat.size()
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    void findPaths(int row, int col, vector<vector<int>>& maze, int n, vector<string>& ans, string& currentPath, vector<vector<int>>& visited) {
        if (row == n - 1 && col == n - 1) {
            ans.push_back(currentPath);
            return;
        }

        string dir = "DLRU";
        int dr[] = {1, 0, 0, -1};
        int dc[] = {0, -1, 1, 0};

        visited[row][col] = 1;

        for (int i = 0; i < 4; i++) {
            int nextRow = row + dr[i];
            int nextCol = col + dc[i];

            if (nextRow >= 0 && nextCol >= 0 && nextRow < n && nextCol < n && !visited[nextRow][nextCol] && maze[nextRow][nextCol] == 1) {
                currentPath.push_back(dir[i]);
                findPaths(nextRow, nextCol, maze, n, ans, currentPath, visited);
                currentPath.pop_back();
            }
        }

        visited[row][col] = 0;
    }

public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string> ans;
        if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0) {
            return ans;
        }
        vector<vector<int>> visited(n, vector<int>(n, 0));
        string currentPath = "";
        findPaths(0, 0, maze, n, ans, currentPath, visited);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> maze = {
        {1, 0, 0, 0}, 
        {1, 1, 0, 1}, 
        {1, 1, 0, 0}, 
        {0, 1, 1, 1}
    };

    vector<string> result = sol.ratInMaze(maze);

    cout << "Paths found: ";
    for (const string& path : result) {
        cout << path << " ";
    }
    cout << endl;

    return 0;
}