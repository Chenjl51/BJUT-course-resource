// 编写一个算法，实现将十进制数转换为8进制的结果输出。其转换过程如下
// （其中N为十进制数，d为要转换的进制数）N = (N div d)×d + N mod d
//(其中：div 为整除运算，mod 为求余运算）例如：（1348)10 = (2504)8

#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>

void decimal_to_octal(int N)
{
    if (N == 0)
    {
        printf("0");
        return;
    }

    int octal[32]; // 数组用来存储八进制的每一位
    int i = 0;

    // 将N转换为八进制
    while (N > 0)
    {
        octal[i] = N % 8; // 取余数
        N = N / 8;        // 更新N为商
        i++;
    }

    // 输出八进制数，从最后一位开始
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", octal[j]);
    }
}

int main()
{
    int decimal_number;

    // 输入十进制数
    printf("请输入一个十进制数: ");
    scanf("%d", &decimal_number);

    printf("十进制数 %d 转换为八进制是: ", decimal_number);
    decimal_to_octal(decimal_number); // 转换并输出
    printf("\n");

    return 0;
}