#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct
{
    int front;          // 队头指针
    int rear;           // 队尾指针
    int quelen;         // 队列的当前长度
    ElemType sequ[100]; // 存储队列元素的数组
} sequeue;

// 初始化循环队列
void init(sequeue *sq, int MAXSIZE)
{
    sq->front = sq->rear = 0;
    sq->quelen = 0; // 初始队列为空
}

// 入队操作
int Insert(sequeue *sq, ElemType x, int MAXSIZE)
{
    // 判断队列是否满
    if ((sq->rear + 1) % MAXSIZE == sq->front)
    {
        printf("队列已满，无法插入元素!\n");
        return 0; // 入队失败
    }
    sq->sequ[sq->rear] = x;              // 将元素插入队尾
    sq->rear = (sq->rear + 1) % MAXSIZE; // 更新队尾指针
    sq->quelen++;                        // 队列长度加1
    return 1;                            // 入队成功
}

// 出队操作
int delete(sequeue *sq, int *x, int MAXSIZE)
{
    // 判断队列是否为空
    if (sq->front == sq->rear)
    {
        printf("队列为空，无法出队!\n");
        return 0; // 出队失败
    }
    *x = sq->sequ[sq->front];              // 获取队头元素
    sq->front = (sq->front + 1) % MAXSIZE; // 更新队头指针
    sq->quelen--;                          // 队列长度减1
    return 1;                              // 出队成功
}

// 打印队列内容
void printQueue(sequeue *sq, int MAXSIZE)
{
    if (sq->front == sq->rear) // 队列为空
    {
        printf("队列为空!\n");
        return;
    }

    int i = sq->front;
    printf("队列中的元素是：");
    while (i != sq->rear)
    {
        printf("%d ", sq->sequ[i]);
        i = (i + 1) % MAXSIZE;
    }
    printf("\n");
}

int main()
{
    int MAXSIZE, quelen, rear;

    // 输入队列最大容量
    printf("请输入队列的最大容量: ");
    scanf("%d", &MAXSIZE);

    // 创建并初始化队列
    sequeue sq;
    init(&sq, MAXSIZE);

    // 用户输入队列信息
    printf("请输入当前队列中的元素个数: ");
    scanf("%d", &quelen);
    sq.quelen = quelen;

    // 设置当前队列尾的位置
    printf("请输入队列末尾元素的位置（0到MAXSIZE-1之间的整数）: ");
    scanf("%d", &rear);
    sq.rear = rear;

    // 设置队列头的位置
    sq.front = (rear - quelen + MAXSIZE) % MAXSIZE;

    // 用户输入每个元素
    printf("请输入队列中的元素：\n");
    for (int i = 0; i < quelen; i++)
    {
        printf("请输入第 %d 个元素: ", i + 1);
        scanf("%d", &sq.sequ[(sq.front + i) % MAXSIZE]);
    }

    // 打印队列当前状态
    printQueue(&sq, MAXSIZE);

    // 示例：执行入队操作
    int x;
    printf("请输入一个要入队的元素: ");
    scanf("%d", &x);
    if (Insert(&sq, x, MAXSIZE))
    {
        printf("入队成功!\n");
    }

    // 打印队列状态
    printQueue(&sq, MAXSIZE);

    // 示例：执行出队操作
    int y;
    if (delete (&sq, &y, MAXSIZE))
    {
        printf("出队元素: %d\n", y);
    }

    // 打印队列状态
    printQueue(&sq, MAXSIZE);

    return 0;
}