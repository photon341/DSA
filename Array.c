#include<stdio.h>
#define Maxsize 100

int Size=0;
int Arr[Maxsize];

void insert();
void insertAtPosition(int data, int posi);
void display();
void sort();
void delete();
void deleteAtPosition(int posi);
void search();
void sorting(int type);

int main(){
    while (1){
        int choice;
        printf("\nChoose What to do: \n");
        printf("\n0.To Exit\n1.Insert into the Array\n2.Delete From the Array\n3.Display the Array\n4.Sort the Array\n5.Search the Element in the Array");
        printf("\nEnter your Choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 0:
            return 0;
            break;
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;

        case 3:
            display();
            break;
        case 4:
            sort();
            break;
        case 5:
            search();
            break;
        default:
            printf("please Enter above option!!");
            break;
        }
        display();
    }
    return 0;
}

void insertAtPosition(int data, int posi){
    if(posi < 0 || posi > Size){
        printf("Invalid Position!! Try Again\n");
        insert();
        return;
    }else{
        for (int i = Size; i > posi; i--)
        {
            Arr[i] = Arr[i - 1];
        }

    }
    Arr[posi] = data;
    (Size)++;
    printf("Element inserted successfully");
    return;
}

void insert(){
    if(Size >= Maxsize){
        printf("Array is Full");
        return;
    }
    
    int c, data, posi;
    insert:
    printf("\nChoose where to Insert the Element");
    printf("\n0.To Go Back\n1.Insert at the begining of the array\n2.Insert at the End of the array\n3.Insert at the any position of the array\n");
    printf("Enter your Choice: ");
    scanf("%d", &c);
    if(c != 0){
        printf("Enter Data to Insert: ");
        scanf("%d",&data);
    }
    switch (c){
    case 0:
        return;
        break;
    case 1:
        insertAtPosition(data, 0);
        break;
    case 2:
        insertAtPosition(data, Size);
        break;
    case 3:        
        printf("Enter the Position: ");
        scanf("%d",&posi);
        insertAtPosition(data, posi-1);
        break;
    default:
        printf("\nplease Enter above option!!\n");
        goto insert;
        break;
    }
    return;
}

void deleteAtPosition(int posi){
    if(posi < 0 || posi >= Size){
        printf("Invalid Position!! Try Again");
        delete();
        return;
    }

    for (int i = posi; i < Size - i; i++){
        Arr[i] = Arr[i+1];
    }
    (Size--);
    printf("Element deleted Successfully");
    return;
}

void delete(){
    if(Size == 0){
        printf("Array is empty");
        return;
    }
    
    int c, posi;
    Delete:
    printf("\nChoose from where to delete the Element");
    printf("\n0.To Go Back\n1.Delete at the begining of the array\n2.Delete at the End of the array\n3.Delete at the any position of the array\n");
    printf("\nEnter your Choice: ");
    scanf("%d", &c);
    switch (c){
    case 0:
        return;
        break;
    case 1:
        deleteAtPosition(0);
        break;
    case 2:
        deleteAtPosition(Size-1);
        break;
    case 3:        
        printf("\nEnter the Position: ");
        scanf("%d",&posi);
        deleteAtPosition(posi-1);
        break;
    default:
        printf("\nplease Enter above option!!\n");
        goto Delete;
        break;
    }
    return;
}

void search(){
    
    if(Size==0){
        printf("Array is Empty!! Please Insert Elements");
        return;
    }
    int element, low, mid, high;
    printf("\nEnter the element you want to search: ");
    scanf("%d", &element);
    low = 0;
    high = Size - 1;
    mid = (low+high)/2;

    while(low <= high){
        if(Arr[mid] == element){
            printf("\n%d is at position %d", element, mid+1);
            return;
        }else if (Arr[mid] < element)
        {
            low = mid + 1;
        }else{
            high = mid - 1;
        }
        mid = (low+high)/2;
    }
    printf("%d is not in the array\n", element);
    return;
}

void display(){
    if(Size == 0){
        printf("\n\nArray is Empty");
        return;
    }

    printf("\n\nArray Elments: ");
    for (int i = 0; i < Size; i++)
    {
        printf("%d ", Arr[i]);
    }
    printf("\n");
}

void sorting(int type){
    int i, j, temp;

    if( type == 1 || type == 2){
        for(i=0; i < Size; i++){
            for(j=i+1; j < Size;j++){
                if((type == 1 && Arr[i] > Arr[j]) || (type == 2 && Arr[i] < Arr[j])){
                    temp = Arr[i];
                    Arr[i] = Arr[j];
                    Arr[j] = temp;
                }
            }
        }
        return;
    }
    for(i=0;i<Size/2;i++){
        temp = Arr[i];
        Arr[i] = Arr[Size-i-1];
        Arr[Size - i -1] = temp;
    }
    return;
}

void sort(){
    int c;
    sort:
    printf("\nChoose in which Order to sort or Reverse the Array:");
    printf("\n0.To Go Back\n1.Ascending\n2.Descending\n3.Reverse");
    printf("\nEnter your Choice: ");
    scanf("%d", &c);
    switch (c){
    case 0:
        return;
        break;
    case 1:
        sorting(1);
        break;
    case 2:
        sorting(2);
        break;
    case 3:        
        sorting(3);
        break;
    default:
        printf("\nplease Enter above option!!\n");
        goto sort;
        break;
    }
    return;
}