#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 贪心算法1：负载均衡策略
int greedy_load_balance(int machine_m, int job_n, vector<int> &times);
// 贪心算法2：递降贪心策略
int greedy_decrease(int machine_m, int job_n, vector<int> &times);
// 最优解算法：回溯法
void backtracking(int machine_m, int job_n, vector<int> &times, vector<int> &sum_times, int &ans, int depth);
int backtracking_main(int machine_m, int job_n, vector<int> &times);
