#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} SeqList;

int i;

// 初始化顺序表
void initSeqList(SeqList *list, int capacity) 
{
    list->data = (int *)malloc(sizeof(int) * capacity);
    list->size = 0;
    list->capacity = capacity;
}

// 扩展顺序表的容量
void expandSeqList(SeqList *list) 
{
    list->capacity *= 2;
    list->data = (int *)realloc(list->data, sizeof(int) * list->capacity);
}

// 向顺序表添加元素
void insertSeqList(SeqList *list, int value)
 {
    if (list->size >= list->capacity) 
    {
        expandSeqList(list);
    }
    list->data[list->size++] = value;
}

// 删除顺序表中相同的元素
void removeDuplicates(SeqList *list)
 {
    if (list->size <= 1) return;  // 如果顺序表为空或只有一个元素，直接返回

    int newSize = 1;  // 新的顺序表大小，至少有一个元素
    for (i = 1; i < list->size; ++i) 
    {
        int j;
        for (j = 0; j < newSize; ++j)
        {
            if (list->data[i] == list->data[j])
            {
                break;  // 找到相同的元素，不再加入新顺序表
            }
        }
        if (j == newSize) 
        {
            list->data[newSize++] = list->data[i];  // 没有找到重复元素，加入新顺序表
        }
    }
    list->size = newSize;
}

// 打印顺序表
void printSeqList(SeqList *list) 
{
    for (i = 0; i < list->size; ++i) 
    {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

// 释放顺序表内存
void freeSeqList(SeqList *list) 
{
    free(list->data);
}

int main() 
{
    SeqList list;
    initSeqList(&list, 10);

    // 向顺序表插入一些数据
    insertSeqList(&list, 1);
    insertSeqList(&list, 2);
    insertSeqList(&list, 3);
    insertSeqList(&list, 2);
    insertSeqList(&list, 4);
    insertSeqList(&list, 3);
    insertSeqList(&list, 5);

    printf("Original list:\n");
    printSeqList(&list);

    // 删除重复元素
    removeDuplicates(&list);

    printf("List after removing duplicates:\n");
    printSeqList(&list);

    // 释放顺序表内存
    freeSeqList(&list);

    return 0;
}