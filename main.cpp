#include "utils.h"
#include "algorithm.h"

int main(int argc, char *argv[])
{
    // 初始化变量
    int machine_m = 0; // 机器个数
    int job_n = 0;     // 任务个数

    // 解析参数
    int state = parse_args(argc, argv, machine_m, job_n);
    // 如果解析参数失败或输入了帮助指令，直接返回
    if (state == 0 || state == 1)
        return state;

    // 打印参数
    cout << "machine (m): " << machine_m << "\t";
    cout << "job (n): " << job_n << endl;

    int repeat = 5;
    int ans1_sum = 0, ans2_sum = 0, ans3_sum = 0;

    // 此部分代码用于寻找递降贪心策略的最差输入
    // vector<int> best_times(job_n, 0);
    // double best_k2 = 0;
    for (int i = 0; i < repeat; i++)
    {
        vector<int> times(job_n, 0);
        // 生成一组随机样本
        generate_samples(job_n, times);
        // 分别运行三种算法，输出结果
        int ans1 = greedy_load_balance(machine_m, job_n, times);
        int ans2 = greedy_decrease(machine_m, job_n, times);
        int ans3 = backtracking_main(machine_m, job_n, times);

        // 此部分代码用于寻找递降贪心策略的最差输入
        // double k2 = double(ans2) / ans3;
        // if (k2 > best_k2)
        // {
        //     best_k2 = k2;
        //     best_times = times;
        // }

        ans1_sum += ans1;
        ans2_sum += ans2;
        ans3_sum += ans3;
    }

    // 此部分代码用于寻找递降贪心策略的最差输入
    // cout << "Theoretical Optimal k2:\t" << 1.5 - 0.5 / machine_m << "\n";
    // cout << "Best k2:\t" << best_k2 << "\n";
    // for (int i = 0; i < job_n; i++)
    //     cout << best_times[i] << "\t";
    // cout << endl;

    cout << "Greedy Load Balance (Ans1):\t" << double(ans1_sum) / repeat << "\n";
    cout << "Greedy Decrease (Ans2):\t" << double(ans2_sum) / repeat << "\n";
    cout << "Backtracking (Ans3):\t" << double(ans3_sum) / repeat << "\n";
    cout << "k1 (Ans1/Ans3): " << double(ans1_sum) / double(ans3_sum) << "\n";
    cout << "k2 (Ans2/Ans3): " << double(ans2_sum) / double(ans3_sum) << "\n\n";

    return 0;
}