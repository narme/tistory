#include <iostream>

#define MAX_QUEUE_SIZE 3

typedef int element;
typedef struct {
    element queue[MAX_QUEUE_SIZE];
    int front, rear;
}Queue;

void init(Queue *q){
    q->front = q->rear = -1;
}

bool is_full(Queue *q){
    return q->rear == MAX_QUEUE_SIZE -1;
}
bool is_empty(Queue *q){
    return q->front == q->rear;
}

void enqueue(Queue *q, element e){
    if(is_full(q)){
        std::cerr << "Queue is full\n";
    }
    q->queue[++q->rear] = e;
}

element dequeue(Queue *q){
    if(is_empty(q)){
        std::cerr << "Queue is empty\n";
    }
    return q->queue[++q->front];
}

element peek(Queue *q){
    if(is_empty(q)){
        std::cerr << "Queue is empty\n";
    }
    return q->queue[q->front + 1];
}

int main(){
    Queue q;

    init(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    std::cout << std::boolalpha << is_full(&q) << "\n";     // true
    std::cout << dequeue(&q) << "\n";                       // 1
    std::cout << dequeue(&q) << "\n";                       // 2
    std::cout << peek(&q) << "\n";                          // 3
    std::cout << dequeue(&q) << "\n";                       // 3
    std::cout << std::boolalpha << is_empty(&q) << "\n";    // true
}