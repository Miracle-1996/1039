class Solution {
public:
    int rob(vector<int>& nums) {
        int n = (int)nums.size();
        vector<vector<int>> f(n + 1, vector<int>(2, 0));
        f[1][0] = 0; f[1][1] = nums[0];
        for (int k = 2; k <= n; ++k) {
            f[k][0] = max(f[k - 1][0], f[k - 1][1]);
            f[k][1] = f[k - 1][0] + nums[k - 1];
        }
        return max(f[n][0], f[n][1]);

        // vector<int> g(n + 1);
        // g[1] = nums[0];
        // for (int k = 2; k <= n; ++k) g[k] = max(g[k - 1], g[k - 2] + nums[k - 1]);
        // return g[n];

        // int res = nums[0];
        // int val1 = nums[0], val2 = 0;
        // for (int k = 2; k <= n; ++k) {
        //     res = max(val1, val2 + nums[k - 1]);
        //     val2 = val1; val1 = res;
        // }
        // return res;
    }
};
// type: dp

/* tips */
/*
    f[n][0]:从前n个房间中选没有两间相邻的房屋,且选第n个房间的所有方案的最大值
    f[n][1]:从前n个房间中选没有两间相邻的房屋,且不选第n个房间的所有方案的最大值
    根据第n个元素选或不选进行分类 -> 状态转移方程
    初始值 -> 递推关系 -> 空间优化
    vector<vector<int>> f(n + 1, vector<int>(2, 0));
    vector<int> g(n + 1);
    val1, val2;
*/

/* editorial */
/*
*/

/* question */
/*
*/