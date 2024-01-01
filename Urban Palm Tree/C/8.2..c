#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct Queue {
    struct ListNode *front;
    struct ListNode *rear;
    int size; int len;
};

struct Queue *createQueue(int len) {
    struct Queue *Q;
    Q = malloc(sizeof(struct Queue));
    Q->front = Q->rear = NULL;
    Q->size = 0;
    Q->len = len;
    return Q;
}
int isEmpty(struct Queue *Q) {
    return (Q->size == 0);
}
int isFull(struct Queue *Q) {
    return (Q->size == Q->len);
}
void enQueue(struct Queue *Q, int data) {
    if(isFull(Q)) {
        printf("Queue Overflow!!");
        exit(1);
    }
    struct ListNode *temp;
    temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    temp->data = data;
    temp->next = NULL;
    Q->size++;
    if(Q->rear == NULL)
        Q->front = Q->rear = temp;
    else {
        Q->rear->next = temp;
        Q->rear = temp;
    }
}

void deQueue(struct Queue *Q) {
    if(isEmpty(Q)) {
        printf("Queue Underflow!!");
        exit(1);
    }
    struct ListNode *temp;
    temp = Q->front;
    Q->front = Q->front->next;
    if(Q->front==NULL)
        Q->rear = NULL;
    printf("Dequeued Element is: %d\n", temp->data);
    Q->size--;
    free(temp);
}

void dispQueue(struct Queue *Q) {
    struct ListNode *temp = Q->front;
    if(isEmpty(Q)) {
        printf("Queue is Empty!!");
        return;
    }
    printf("\nQueue is:\n");
    while(temp!=NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}

void deleteQueue(struct Queue *Q) {
    struct ListNode *temp;
    while(Q->front) {
        temp = Q->front;
        Q->front = Q->front->next;
        free(temp);
    }
    free(Q);
}

int main() {
    int i, len;
    printf("Enter Queue length: ");
    scanf("%d", &len);
    struct Queue *Q = createQueue(len);
    for(i=1; i<=len; i++)
        enQueue(Q, i);

    dispQueue(Q);

    for(i=1; i<=len; i++)
        deQueue(Q);

    deleteQueue(Q);
    return 0;
}