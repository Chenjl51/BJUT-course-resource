#include <stdio.h>
#include <stdlib.h>

// 定义单链表节点结构
typedef struct node {
    int data;
    struct node *next;
} NODE;

// 查找最小值节点并进行删除
int MIN(NODE *L) 
{
    if (L == NULL || L->next == NULL)
    {
        return 0;  // 链表为空，返回0
    }

    NODE *min_node = L->next;  // 假设第一个节点是最小值节点
    NODE *prev_min = L;  // 保存最小值节点的前驱节点
    NODE *current = L->next;  // 当前节点指针
    NODE *prev = L;  // 当前节点的前驱节点

    // 遍历链表找最小节点
    while (current != NULL) 
    {
        if (current->data < min_node->data) 
        {
            min_node = current;
            prev_min = prev;  // 更新最小节点的前驱
        }
        prev = current;
        current = current->next;
    }

    // 判断最小值是否为奇数
    if (min_node->data % 2 == 1) 
    {
        // 删除最小值结点
        prev_min->next = min_node->next;
        free(min_node);
        return 1;  // 如果最小值是奇数，删除节点，返回1
    } 
    else 
    {
        return 2;  // 如果最小值是偶数，返回2
    }
}

// 辅助函数：创建链表，用户输入数据
NODE* create_list(int n) 
{
    if (n <= 0) return NULL;

    NODE *head = (NODE*)malloc(sizeof(NODE));
    head->next = NULL;  // 头结点的next指针为空

    NODE *last = head;
    int i;
    for (i = 1; i <= n; i++) 
    {
        NODE *new_node = (NODE*)malloc(sizeof(NODE));
        printf("Enter data for node %d: ", i);
        scanf("%d", &new_node->data);
        new_node->next = NULL;  // 新节点的next指针为空
        last->next = new_node;  // 上一个节点指向新节点
        last = new_node;  // 更新last指针
    }

    return head;
}

// 辅助函数：打印链表
void print_list(NODE *head) 
{
    if (head == NULL || head->next == NULL) 
    {
        printf("List is empty.\n");
        return;
    }

    NODE *current = head->next;  // 跳过头结点
    while (current != NULL) 
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() 
{
    int n;
    printf("Enter the number of nodes in the list: ");
    scanf("%d", &n);

    NODE *head = create_list(n);  // 创建链表

    printf("Original List:\n");
    print_list(head);

    int result = MIN(head);
    if (result == 0) 
    {
        printf("The list is empty.\n");
    } 
    else if (result == 1) 
    {
        printf("Deleted the node with the smallest odd value.\n");
    }
    else 
    {
        printf("The smallest value is even, no deletion performed.\n");
    }

    printf("Updated List:\n");
    print_list(head);

    return 0;
}
