#include "utils.h"
#include "algorithm.h"
// 打印帮助信息
void printHelp()
{
    cout << "Usage: Scheduling [options]" << endl;
    cout << "Options:" << endl;
    cout << "  -h, -help       Display this help message and exit." << endl;
    cout << "  -m, -machine    Specify the number of machines." << endl;
    cout << "  -n, -job        Specify the number of jobs." << endl;
}
// 处理命令行参数
int parse_args(int argc, char *argv[], int &machine_m, int &job_n)
{
    // 返回0代表用户输入了帮助指令，返回1代表解析失败，返回2代表解析成功
    // 在main函数中可以根据返回值来做不同的处理，若返回0或1，则退出程序，若返回2，则继续执行算法

    // 遍历参数
    for (int i = 1; i < argc; i++)
    {
        string arg = argv[i];

        if (arg == "-h" || arg == "-help")
        {
            // 如果请求了帮助，则不再处理其他参数，直接结束程序
            printHelp();
            return 0;
        }
        else if (arg == "-m" || arg == "-machine")
        {
            if (i + 1 < argc)
                machine_m = stoi(argv[++i]); // 将字符串转换为整数
            else
            {
                cerr << "Error: -m option requires an argument." << endl;
                return 1;
            }
        }
        else if (arg == "-n" || arg == "-job")
        {
            if (i + 1 < argc)
                job_n = stoi(argv[++i]); // 将字符串转换为整数
            else
            {
                cerr << "Error: -n option requires an argument." << endl;
                return 1;
            }
        }
        else
        {
            cerr << "Error: Unknown option: " << arg << endl;
            return 1;
        }
    }
    return 2;
}

// 生成测试样本
void generate_samples(int job_n, vector<int> &times)
{
    // default_random_engine e(time(nullptr));
    // // 随机数分布对象
    // uniform_int_distribution<signed> u(2, 100);

    random_device rd; // 非确定性随机数生成器
    mt19937 e(rd());  // 使用 random_device 的输出作为种子
    uniform_int_distribution<signed> u(2, 100);

    for (int i = 0; i < job_n; i++)
    {
        times[i] = u(e);
    }

    // 用于固定测试样例，便于debug
    // times = {81, 40, 26, 4, 65, 98, 53, 71, 15};
    // times = {10, 10, 10, 10, 10, 10, 30};
    // times = {92, 55, 4, 83, 66, 53, 53, 77, 97, 72};

    // 用于打印随机生成的样本，便于debug
    // cout << "Times:\t";
    // for (int i = 0; i < job_n; i++)
    //     cout << times[i] << "\t";
    // cout << endl;
}