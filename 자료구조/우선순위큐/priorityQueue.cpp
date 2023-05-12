#include <iostream>
#include <vector>

typedef int element;
using namespace std;

class priorityQueue{
    private:
        vector<element> heap;
        int heap_size;
    public:
        priorityQueue(){
            heap_size = 0;
        }
        
        bool empty(){
            if(heap_size)return false;
            else return true;
        }

        int size(){
            return heap_size;
        }
        element top(){
            return heap[1];
        }

        void push(element data){
            int parent, child;
        
            parent = (heap_size - 1) / 2;
            child = heap_size;
            heap.push_back(data);
            while(child > 0 && heap[parent] < heap[child]){
                element tmp = heap[parent];
                heap[parent] = heap[child];
                heap[child] = tmp;

                child = parent;
                parent = (child - 1) / 2;
            }
            ++heap_size;
        }

        void pop(){
            if(empty())return;
            int parent, child;
            heap[0] = heap[--heap_size];

            parent = 0; 
            child = 1;

            while(child <= heap_size){
                if(child < heap_size && heap[child] < heap[child+1])child++;

                if(heap[parent] >= heap[child])break;
                else{
                    element tmp = heap[parent];
                    heap[parent] = heap[child];
                    heap[child] = tmp;
                }
                parent = child;
                child = parent * 2 + 1;
            }
        }
        void print(){
            cout << "[";
            for(int i = 0; i < heap_size; i++)cout << heap[i] << " ";
            cout << "]\n";
        }
};

int main(){
    priorityQueue* heap = new priorityQueue();
    
    heap->push(10);
    heap->print();

    heap->push(20);
    heap->print();

    heap->push(50);
    heap->print();

    heap->push(30);
    heap->print();

    heap->push(40);
    heap->print();

    heap->push(0);
    heap->print();


    heap->pop();
    heap->print();

    heap->pop();
    heap->print();
}
