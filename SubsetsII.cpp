/*90. Subsets II
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.
 
Example 1:
Input: nums = [1,2,2]Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:
Input: nums = [0]Output: [[],[0]]
 
Constraints:
- 1 <= nums.length <= 10
- -10 <= nums[i] <= 10
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        sort(nums.begin(), nums.end());
        backtrack(0, nums, path, res);
        return res;
    }

private:
    void backtrack(int start, vector<int>& nums, vector<int>& path, vector<vector<int>>& res) {
        res.push_back(path);
        for (int i = start; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            path.push_back(nums[i]);
            backtrack(i + 1, nums, path, res);
            path.pop_back();
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 2};
    vector<vector<int>> result1 = sol.subsetsWithDup(nums1);
    
    cout << "Input: [1, 2, 2]\nOutput: [";
    for (size_t i = 0; i < result1.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < result1[i].size(); ++j) {
            cout << result1[i][j] << (j + 1 < result1[i].size() ? "," : "");
        }
        cout << "]" << (i + 1 < result1.size() ? "," : "");
    }
    cout << "]\n";

    return 0;
}