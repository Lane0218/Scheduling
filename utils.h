#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;

// 打印帮助信息
void printHelp();
// 处理命令行参数
int parse_args(int argc, char *argv[], int &machine_m, int &job_n);
// 生成测试样本
void generate_samples(int job_n, vector<int> &times);