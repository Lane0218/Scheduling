#include "algorithm.h"

// 贪心算法1：负载均衡策略
int greedy_load_balance(int machine_m, int job_n, vector<int> &times)
{
    vector<int> sum_times(machine_m, 0);
    for (int i = 0; i < job_n; i++)
    {
        int min_index = 0;
        for (int j = 1; j < machine_m; j++)
        {
            if (sum_times[j] < sum_times[min_index])
                min_index = j;
        }
        sum_times[min_index] += times[i];
    }
    // for (int i = 0; i < machine_m; i++)
    //     cout << sum_times[i] << "\t";
    // cout << "\n";
    return *max_element(sum_times.begin(), sum_times.end());
}
// 贪心算法2：递降贪心策略
int greedy_decrease(int machine_m, int job_n, vector<int> &times)
{
    vector<int> times_tmp(times.begin(), times.end());
    sort(times_tmp.begin(), times_tmp.end(), greater<int>());

    return greedy_load_balance(machine_m, job_n, times_tmp);
}
// 最优解算法：回溯法
void backtracking(int machine_m, int job_n, vector<int> &times, vector<int> &sum_times, int &ans, int depth)
{
    if (depth == job_n)
    {
        int tmp_ans = *max_element(sum_times.begin(), sum_times.end());
        ans = min(tmp_ans, ans);
        return;
    }
    for (int i = 0; i < machine_m; i++)
    {
        sum_times[i] += times[depth];
        if (sum_times[i] < ans)
            backtracking(machine_m, job_n, times, sum_times, ans, depth + 1);
        sum_times[i] -= times[depth];
    }
}
int backtracking_main(int machine_m, int job_n, vector<int> &times)
{
    int ans = 0x7fffffff;
    vector<int> sum_times(machine_m, 0);
    backtracking(machine_m, job_n, times, sum_times, ans, 0);

    return ans;
}