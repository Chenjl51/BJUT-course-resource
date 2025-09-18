#include <stdio.h>
#include <stdlib.h>

// 定义顺序表元素结构体
typedef struct {
    int data;  // 存储数据
    int index; // 存储元素的索引
} Node;

int main() 
{
    int n;
    printf("Please input the number of the elements:");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("The number of the elements must go over zero!\n");
        return 1;
    }

    // 动态分配内存创建顺序表（顺序表即数组）
    Node *table = (Node *)malloc(n * sizeof(Node));
    if (table == NULL)
    {
        printf("Fail to devide the register!\n");
        return 1;
    }

    int i;
    // 输入元素并填充顺序表
    for (i = 0; i < n; i++) 
    {
        printf("Please input element%d:", i + 1);
        scanf("%d", &(table[i].data));
        table[i].index = i;  // 记录每个元素的索引（位置）
    }

    // 查找最大值和最小值及其位置
    int max = table[0].data;
    int min = table[0].data;
    int maxIndex = table[0].index;
    int minIndex = table[0].index;

    for (i = 1; i < n; i++) 
    {
        if (table[i].data > max) 
        {
            max = table[i].data;
            maxIndex = table[i].index;
        }
        if (table[i].data < min)
        {
            min = table[i].data;
            minIndex = table[i].index;
        }
    }

    // 输出结果
    printf("Max: %d, Address: %d\n", max, maxIndex + 1);
    printf("Min: %d, Address: %d\n", min, minIndex + 1);

    // 释放动态分配的内存
    free(table);

    return 0;
}
