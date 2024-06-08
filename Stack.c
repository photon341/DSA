#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

int STACK[SIZE];

int TOP=-1;
void Push(int data);
void Pop();
void Display();

int main(){
    int n, data, choice;
    printf("Enter No. elements into the stack: ");
    scanf("%d", &n);
    printf("Enter Data into the stack: ");
    for(int i=0;i<n;i++){
        scanf("%d",&data);
        Push(data);
    }
    printf("\n\nStack: \n");
    Display();
    printf("\n\nChoose What to do: \n");
    printf("\n0.To Exit\n1.Push\n2.Pop\n3.Display");
    while (1){
        printf("\nEnter your Chocie: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 0:
            exit(1);
            break;
        case 1:
            printf("Enter Data to Push: ");
            scanf("%d",&data);
            Push(data);
            printf("\nStack : \n");
            Display();
            break;
        
        case 2:
            Pop();
            printf("Stack: \n");
            Display();
            break;
        case 3:
            printf("Stack: \n");
            Display();
            break;
        default:
            printf("please Enter above option!!");
            break;
        }
    }
    return 0;
}

void Push(int data){
    if(TOP == 100-1){
        printf("Not space to store!!");
    }else{
        TOP++;
        STACK[TOP] = data;
    }
}
void Pop(){
    if(TOP == -1){
        printf("Nothing to delete!!\n");
    }else{
        TOP--;
    }    
}
void Display(){
    if(TOP == -1){
        printf("There is Nothing to Show!!");
    }else{
        for(int i=TOP;i>=0;i--){
            printf("%d\n",STACK[i]);
        }
    }
}
