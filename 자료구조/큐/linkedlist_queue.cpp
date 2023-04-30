#include <iostream>

typedef int element;
typedef struct QueueNode{
    element data;
    QueueNode *link;
}QueueNode;

typedef struct{
    QueueNode * front, *rear;
}linkedQueue;

void init(linkedQueue *q){
    q->front = q->rear = nullptr;
}

bool is_full(linkedQueue *q){
    return false;
}
bool is_empty(linkedQueue *q){
    return q->front == nullptr;
}

void enqueue(linkedQueue *q, element data){
    QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
    
    if(temp == nullptr){
        std::cerr << "Memory Allocation Error\n";
        return;
    }
    temp->data = data;
    temp->link = nullptr;
    if(is_empty(q)){
        q->front = temp;
        q->rear = temp;
    }else{
        q->rear->link = temp;
        q->rear = temp;
    }
}

element dequeue(linkedQueue *q){
    if(is_empty(q)){
        std::cerr << "Queue is empty\n";
        exit(-1);
    }
    QueueNode *temp = q->front;
    element data = temp->data;

    q->front = q->front->link;
    if(q->front == nullptr)q->rear = nullptr;
    free(temp);
    return data;
}

element peek(linkedQueue *q){
    if(is_empty(q)){
        std::cerr << "Queue is empty\n";
        exit(-1);
    }
    return q->front->data;
}

int main(){
    linkedQueue q;

    init(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    std::cout << dequeue(&q) << "\n";                       // 1
    std::cout << dequeue(&q) << "\n";                       // 2
    std::cout << peek(&q) << "\n";                          // 3
    std::cout << dequeue(&q) << "\n";                       // 3
    std::cout << std::boolalpha << is_empty(&q) << "\n";    // true
}