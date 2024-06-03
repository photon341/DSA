#include<stdio.h>
#include<stdlib.h>
struct node {
int data; 
struct node *next;
}*head;

int  COUNT = 0;
void createList(int n);
void insertNodeAtBeginning(int data);
void insert_at_pos(int data, int pos);
void insert_at_end(int data);
void displayList();
void delete_at_beg();
void delete_at_pos(int pos);
void delete_at_last();

int main(){
    int n, data, choice, posi;

    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    COUNT = n; 
    createList(n);
    printf("Data in the list: ");
    displayList();
    printf("\n\nChoose What to do: \n");
    printf("\n0.To Exit\n1.Insert into the Linked List\n2.Delete From the Linked List\n3.Display the List");
    while (1){
        printf("\nEnter your Choose: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 0:
            exit(1);
            break;
        case 1:
            printf("Enter Data to Insert: ");
            scanf("%d",&data);
            printf("Enter the Position: ");
            scanf("%d",&posi);
            insert_at_pos(data, posi);
            printf("\nList : ");
            displayList();
            break;
        
        case 2:
            printf("Enter the position of the Node you want to delete: ");
            scanf("%d",&posi);
            delete_at_pos(posi);
            printf("List : ");
            displayList();
            break;
        case 3:
            printf("List : ");
            displayList();
            break;
        default:
            printf("please Enter above option!!");
            break;
        }
    }
    return 0;
}


void createList(int n){
    struct node *newNode, *temp;
    int data, i;
    head = (struct node *)malloc(sizeof(struct node));
    if(head == NULL){
        printf("Unable to allocate memory.");
    }
    else{
        printf("Enter the data of node 1: ");
        scanf("%d", &data);
        head->data = data;
        head->next = NULL;
        temp = head;
        for(i=2; i<=n; i++){
            newNode = (struct node *)malloc(sizeof(struct node));
            if(newNode == NULL){
                printf("Unable to allocate memory.");
                break;
            }else{
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);
                newNode->data = data; 
                newNode->next = NULL; 
                temp->next = newNode;
                temp = temp->next;
            }
        }
        printf("\nSINGLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}
void insertNodeAtBeginning(int data){
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("Unable to allocate memory.");
    }
    else{
        newNode->data = data;
        newNode->next = head;
        head = newNode;
        printf("DATA INSERTED SUCCESSFULLY\n");
        COUNT++;
    }

}
void displayList(){
    struct node *temp;
    if(head == NULL){
        printf("List is empty");
    }else{
        temp = head;
        while(temp != NULL){
            printf("%d\t", temp->data);
            temp = temp->next;
        }
    }
    printf("\n");
}
void insert_at_end(int data){
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    if(head == NULL){
        head = newnode;
    }else{
        temp = head;
        while(temp->next != NULL)
        temp = temp->next;
    }
    temp ->next = newnode;
    newnode->data = data;
    newnode->next = NULL; 
    COUNT++;
}
void delete_at_last(){
    struct node *temp, *prev;
    if(head == NULL){
        printf(" Empty List: ");
        return ;
    }else{
        temp = head;
        prev = head;
        while(temp->next != NULL){
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
        printf("Node deleted\n");
        COUNT--;
    }
}
void delete_at_beg(){
    struct node *temp;
    if(head == NULL){
        printf("No nodes are exist.");
        return ;
    }else{
        temp = head;
            head = temp->next;
            free(temp);
        printf("Node deleted\n");
        COUNT--;
    }
}
void insert_at_pos(int data, int pos){
    struct node *newnode , *temp, *perv;
    newnode = (struct node *)malloc(sizeof(struct node));    
    temp = head;
    if(head == NULL){
        head = newnode;
    }else if (pos <= 1){
        insertNodeAtBeginning(data);
    }else if (pos >= COUNT+1){
        insert_at_end(data);
    }else{
        for (int i = 1; i < pos; i++)
        {
            perv = temp;
            temp = temp->next;
        }
        newnode->data = data;
        newnode->next = temp;
        perv->next = newnode;
        printf("Node inserted");
        COUNT++;
    }

}
void delete_at_pos(int pos){
    struct node *temp, *prev;
    temp = head;
    if(head == NULL){
        printf("No nodes are exist.");
        return ;
    }else if(pos == 1){
        delete_at_beg();
    }
    else if(pos < 1 || pos > COUNT){
        printf("Invalid position");
    }else{
        for (int i = 1; i < pos; i++)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        printf("Node is Deleted");
        free(temp); 
        COUNT--;
    }
}
