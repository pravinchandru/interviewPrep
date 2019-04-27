//
//  DataStructures.cpp
//  
//
//  Created by Pravin Chandru on 7/6/14.
//
//

#include "DataStructures.h"


using namespace std;

void CircularQueue::enqueue(int element)
{
    if(front == -1 && rear == -1){
        front=0;
        rear =0;
    } else if(rear == CQUEUE_SIZE -1)
    {
        rear=0;
    } else if((front == 0 && rear == CQUEUE_SIZE-1) || front == rear+1)
    {
        cout << "cq full" <<endl;
        return;
    } else
        rear++;
    
    cQueue[rear]=element;
}

void CircularQueue::dequeue(int& elementToDelete )
{
    
    if(front==-1 && rear==-1 ){
        cout << "queue empty" << endl;
        return;
    } else if (front == CQUEUE_SIZE -1) {
        elementToDelete = cQueue[front];
        front =0;
    } else if (front == 0 && rear == 0) {
        elementToDelete = cQueue[front];
        front=-1;
        rear =-1;
    } else if (front == rear) {
        elementToDelete = cQueue[front];
        front=-1;
        rear =-1;
    } else {
        elementToDelete = cQueue[front];
        front++;
    }
    
    
}
void CircularQueue::display()
{
    if(front==-1 && rear==-1 ){
        cout << "queue empty" << endl;
        return;
    } else if ( front > rear)
    {
        for (int i=0; i <= rear; i++) {
            cout << " item :" << cQueue[i]<<endl;
        }
        
        for (int i=front; i <= CQUEUE_SIZE -1; i++) {
            cout << " item :" << cQueue[i]<<endl;
        }
    } else
        for (int i=front; i <= rear; i++)
            cout << " item :" << cQueue[i] << endl;
    
    
}


int main()
{
    
    CircularQueue cQ;
    
    cQ.enqueue(1);
    
    cQ.enqueue(5);
    
    cQ.enqueue(3);
    
    cQ.display();
    
    int elementToDelete;
    cQ.dequeue(elementToDelete);
    
    cout << "element deleted" << elementToDelete << endl;
    
    cQ.display();
    
    cQ.dequeue(elementToDelete);
    
    cout << "element deleted" << elementToDelete << endl;
    
    cQ.display();
    
    cQ.dequeue(elementToDelete);
    
    cout << "element deleted" << elementToDelete << endl;
    
    cQ.display();
    
    cQ.dequeue(elementToDelete);
    
    cout << "element deleted" << elementToDelete << endl;
    
    cQ.display();
    

    
}