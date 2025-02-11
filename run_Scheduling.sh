#!/bin/bash

# 用于自动化测试获得不同规模下的数据

# 定义输出文件名
OUTPUT_FILE="output.txt"

# 以追加模式写入输出文件
>> "$OUTPUT_FILE"

# 小规模：循环执行Scheduling程序，固定n为10，m从2开始，每次增加1，直到10
for (( m=2; m<10; m+=1 ))
do
    ./Scheduling -m "$m" -n 10 >> "$OUTPUT_FILE"
done

# for (( m=2; m<10; m+=1 ))
# do
#     for (( n=m+1; n<11; n+=1 ))
#     do
#         ./Scheduling -m "$m" -n "$n" >> "$OUTPUT_FILE"
#     done
# done

# for (( n=4; n<21; n+=1 ))
# do
#     ./Scheduling -m 3 -n "$n" >> "$OUTPUT_FILE"
# done

# for (( m=2; m<10; m+=1 ))
# do
#     ./Scheduling -m "$m" -n 10 >> "$OUTPUT_FILE"
# done

# for (( n=50; n<=2000; n+=10 ))
# do
#     ./Scheduling -m 50 -n "$n" >> "$OUTPUT_FILE"
# done