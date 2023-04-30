#include <iostream>

typedef int element;
typedef struct DqeueNode{
    element data;
    DqeueNode *front, *rear;
}DqeueNode;

typedef struct{
    DqeueNode *head, *tail;
}linkedDqeue;

void init(linkedDqeue *dq){
    dq->head = dq->tail = nullptr;
}
DqeueNode *create_node(DqeueNode *front, DqeueNode *rear, element data){
    DqeueNode *temp = (DqeueNode *)malloc(sizeof(DqeueNode));
    if(temp == nullptr){
        std::cerr << "Memory Allocation Error\n";
        exit(-1);
    }
    temp->data = data;

    temp->front = front;
    temp->rear = rear;
    return temp;
}

bool is_full(linkedDqeue *dq){
    return false;
}
bool is_empty(linkedDqeue *dq){
    return dq->head == nullptr;
}

void add_front(linkedDqeue *dq, element data){
    DqeueNode * newNode = create_node(nullptr, dq->head, data);
    
    if(is_empty(dq)){
        dq->tail = newNode;
    }else{
        dq->head->front = newNode;
    }
    dq->head = newNode;
}
void add_rear(linkedDqeue *dq, element data){
    DqeueNode * newNode = create_node(dq->tail, nullptr, data);
    
    if(is_empty(dq)){
        dq->head = newNode;
    }else{
        dq->tail->rear = newNode;
    }
    dq->tail = newNode;
}

element delete_front(linkedDqeue *dq){
    if(is_empty(dq)){
        std::cerr << "Dqeue is empty\n";
        exit(-1);
    }
    DqeueNode * temp = dq->head;
    element data = temp->data;


    dq->head = dq->head->rear;

    if(dq->head == nullptr)dq->tail = nullptr;
    else dq->head->front = nullptr;

    free(temp);
    return data;
}

element delete_rear(linkedDqeue *dq){
    if(is_empty(dq)){
        std::cerr << "Dqeue is empty\n";
        exit(-1);
    }
    DqeueNode * temp = dq->tail;
    element data = temp->data;


    dq->tail = dq->tail->front;

    if(dq->tail == nullptr)dq->head = nullptr;
    else dq->tail->rear = nullptr;
    
    free(temp);
    return data;
}
element get_front(linkedDqeue *dq){
    return dq->head->data;
}

element get_rear(linkedDqeue *dq){
    return dq->tail->data;
}
int main(){
    linkedDqeue dq;

    init(&dq);
    add_front(&dq, 1);
    add_rear(&dq, 3);
    add_rear(&dq, 2);

    std::cout << delete_front(&dq) << "\n";     // 1
    std::cout << delete_rear(&dq) << "\n";                       // 2
    std::cout << get_front(&dq) << "\n";                          // 3
    std::cout << get_rear(&dq) << "\n";                       // 3
    std::cout << delete_front(&dq) << "\n";                       // 1
    std::cout << std::boolalpha << is_empty(&dq) << "\n";    // true
}