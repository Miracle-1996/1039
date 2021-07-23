class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = (int)nums.size();
        int64_t even = nums[0], odd = 0;
        for (int k = 2; k <= n; ++k) {
            even = max(even, odd + nums[k - 1]);
            odd  = max(odd, even - nums[k - 1]);
        }
        return max(odd, even);
        // vector<vector<int64_t>> f(n + 1, vector<int64_t>(2, 0));
        // f[1][0] = nums[0]; f[1][1] = 0;
        // for (int k = 2; k <= n; ++k) {
        //     f[k][0] = max(f[k - 1][0], f[k - 1][1] + nums[k - 1]);
        //     f[k][1] = max(f[k - 1][1], f[k - 1][0] - nums[k - 1]);
        // }
        // return max(f[n][0], f[n][1]);
    }
};
// type: dp

/* tips */
/*
    f[n][0]:从前n个元素中选,其中子序列长度是偶数的所有方案的最大值
    f[n][1]:从前n个元素中选,其中子序列长度是奇数的所有方案的最大值
    根据第n个元素选或不选进行分类 -> 状态转移方程
    初始值 -> 递推关系 -> 空间优化
    初始化一个f[n][2]vector的写法:
    vector<vector<int64_t>> f(n + 1, vector<int64_t>(2, 0));
*/

/* editorial */
/*
*/

/* question */
/*
*/