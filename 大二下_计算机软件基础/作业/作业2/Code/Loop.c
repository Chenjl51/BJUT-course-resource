#include <stdio.h>
#include <stdlib.h>

// 定义循环链表节点结构
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 删除节点p的前驱节点的函数
Node* deletePredecessor(Node* head, Node* p) 
{
    if (head == NULL || p == NULL || head->next == NULL) 
    {
        return p;
    }

    Node* current = head;
    Node* prev = NULL;

    // 找到节点p
    while (current != p && current->next != head) 
    {
        prev = current;
        current = current->next;
    }

    // 如果找到了节点p
    if (current == p) 
    {
        Node* pred = head;
        Node* pred_prev = NULL;
        // 找到p的前驱节点
        while (pred->next != p) 
        {
            pred_prev = pred;
            pred = pred->next;
        }
        // 修改指针，删除前驱节点
        if (pred_prev != NULL) 
        {
            pred_prev->next = pred->next;
            free(pred);
        }
    }

    return p;
}

// 创建循环链表的函数，接收用户输入
Node* createCircularList(int n) 
{
    if (n <= 0) return NULL;

    Node* head = (Node*)malloc(sizeof(Node));
    printf("Please enter the data for the 1st node: ");
    scanf("%d", &head->data);
    Node* tail = head;

    int i;
    for (i = 2; i <= n; i++) 
    {
        Node* newNode = (Node*)malloc(sizeof(Node));
        printf("Please enter the data for the %dth node: ", i);
        scanf("%d", &newNode->data);
        tail->next = newNode;
        tail = newNode;
    }

    tail->next = head;  // 使链表成为循环链表

    return head;
}

// 辅助函数：打印循环链表
void printCircularList(Node* p) 
{
    Node* start = p;
    printf("Circular List: ");
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != start);
    printf("\n");
}

int main() 
{
    int n;
    printf("Please enter the number of nodes in the circular linked list: ");
    scanf("%d", &n);

    Node* head = createCircularList(n);
    printCircularList(head);

    Node* targetNode = NULL;
    int targetData;
    printf("Please enter the data of the node whose predecessor node you want to delete: ");
    scanf("%d", &targetData);

    Node* current = head;
    do {
        if (current->data == targetData) 
        {
            targetNode = current;
            break;
        }
        current = current->next;
    } while (current != head);

    if (targetNode != NULL) 
    {
        targetNode = deletePredecessor(head, targetNode);
        printCircularList(head);
    } else 
    {
        printf("The node with the specified data was not found.\n");
    }

    return 0;
}
