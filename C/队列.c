typedef struct Node{
    QueneElemType data;
    struct Node *next;
}LinkQueueNode;
typedef struct{
    LinkQueueNode *front;
    LinkQueueNode *rear;
}LinkQueue;

int initQueue(LinkQueue *Q){

}