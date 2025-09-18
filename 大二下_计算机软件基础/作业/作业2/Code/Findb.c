#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int data;
    struct node *next;
} NODE;

// 链表的创建
NODE *ListCreate(int n, int a[]) 
{
    int i;
    NODE *h, *x, *y;
    h = (NODE *)malloc(sizeof(NODE));  // 创建一个头节点
    if (h == NULL) 
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    h->next = NULL;  // 头节点的next指向NULL，实际的数据链从头节点开始

    y = h;  // 设置头节点为y
    for (i = 0; i < n; i++) 
    {  // 从a数组中插入数据
        x = (NODE *)malloc(sizeof(NODE));
        if (x == NULL)
        {
            printf("Memory allocation failed.\n");
            exit(1);
        }
        x->data = a[i];
        x->next = NULL;
        y->next = x;  // 将当前节点插入到链表尾部
        y = x;  // 移动到当前插入的节点
    }
    return h;
}

// 寻找数据a的前驱节点
NODE *Locate(NODE *head, int a) 
{
    NODE *p = head;
    while (p != NULL && p->next != NULL && p->next->data != a) 
    {  // 寻找a的前驱节点
        p = p->next;
    }
    return p;  // 返回前驱节点
}

// 插入数据b到链表中，如果找到数据a，在a之前插入b；如果没有找到a，插入到链表尾部
int insert(NODE *head, int a, int b) 
{
    NODE *p, *s;
    p = Locate(head, a);  // 找到a的前驱节点
    s = (NODE *)malloc(sizeof(NODE));
    if (s == NULL) 
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    s->data = b;

    if (p != NULL && p->next != NULL && p->next->data == a) 
    {  // 找到了数据a
        s->next = p->next;
        p->next = s;
    } else 
    {  // 没有找到数据a，插入到链表尾部
        p = head;
        while (p->next != NULL) 
        {
            p = p->next;
        }
        p->next = s;
        s->next = NULL;
    }
    return 1;
}

// 打印链表
void PrintList(NODE *head) 
{
    NODE *p = head->next;  // 跳过头节点
    while (p != NULL) 
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() 
{
    int a, b, n, i;
    NODE *head;
    
    // 输入链表长度
    printf("Please input the length of the list: ");
    scanf("%d", &n);
    int c[100];
    
    // 输入链表数据
    printf("Please input the elements of the list: ");
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &c[i]);
    }

    // 创建链表并赋值给head
    head = ListCreate(n, c);

    // 输入要插入的数据a和b
    printf("Please input data a: ");
    scanf("%d", &a);
    printf("Please input data b: ");
    scanf("%d", &b);

    // 执行插入操作
    insert(head, a, b);

    // 打印链表
    printf("After insert: ");
    PrintList(head);

    return 0;
}
