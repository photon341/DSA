#include<stdio.h>
#include<stdlib.h>

#define SIZE 100

struct QUEUE{
    int Item[SIZE];
    int rear;
    int front;
}*Line;

void enQueue(int data);

void deQueue();

void Display();

int main(){
    int n, data, choice;
    Line = (struct QUEUE *)malloc(sizeof(struct QUEUE));
    Line->front = Line->rear = -1;
    printf("Enter No. elements into the Queue: ");
    scanf("%d", &n);
    printf("Enter Data into the Queue: ");
    for(int i=0;i<n;i++){
        scanf("%d",&data);
        enQueue(data);
    }
    printf("\n\nQueue: ");
    Display();
    printf("\n\nChoose What to do: \n");
    printf("\n0.To Exit\n1.Insert\n2.Delete\n3.Display");
    while (1){
        printf("\nEnter your Chocie: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 0:
            exit(1);
            break;
        case 1:
            printf("Enter Data to insert: ");
            scanf("%d",&data);
            enQueue(data);
            printf("\nQueue: ");
            Display();
            break;
        
        case 2:
            deQueue();
            printf("Queue: ");
            Display();
            break;
        case 3:
            printf("Queue: ");
            Display();
            break;
        default:
            printf("please Enter above option!!");
            break;
        }
    }
    return 0;
}

void enQueue(int data){
    if(Line->rear == SIZE -1){
        printf("\nQueue is Full!!");
    }else{
        if(Line->front == -1)
            Line->front = 0;
        Line->rear++;
        Line->Item[Line->rear] = data;
        printf("\nInserted -> %d\n",data);
    }
}

void deQueue() {
  if (Line->front == -1)
    printf("\nQueue is Empty!!");
  else {
    printf("\nDeleted : %d\n", Line->Item[Line->front]);
    Line->front++;
    if (Line->front > Line->rear)
      Line->front = Line->rear = -1;
  }
}

void Display(){
  if (Line->rear == -1)
    printf("\nNothing to Show!!!");
  else {
    int i;
     for (i = Line->rear; i >= Line->front; i--){
      printf("%d  ", Line->Item[i]);
    }
    printf("\n");
  }
}
