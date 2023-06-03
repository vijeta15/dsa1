#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
void swap(struct Node* a, struct Node* b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}


void bubbleSort(struct Node* head, int n)
{
    struct Node* current;
    struct Node* index = NULL;
    int i;

    if (head == NULL)
        return;

    for (i = 0; i < n - 1; i++) {
        current = head;
        while (current->next != index) {
            if (current->data > current->next->data) {
                swap(current, current->next);
            }
            current = current->next;
        }
        index = current;
    }
}

void insert(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void printList(struct Node* node)
{
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main()
{
    struct Node* head = NULL;
    int n, i, num,lo,up;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
     printf("enter lo\n");
    scanf("%d",&lo);
     printf("enter up\n");
    scanf("%d",&up);
    for (i = 0; i < n; i++) {

         num=(rand()%(up-lo+1))+lo;
        insert(&head, num);
    }

    printf("Original Linked list: \n");
    printList(head);

    bubbleSort(head, n);

    printf("Sorted Linked list: \n");
    printList(head);

    return 0;
}
