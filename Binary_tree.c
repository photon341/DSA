#include<stdio.h>
#include<stdlib.h>

struct BinaryTree
{
    int data;
    struct BinaryTree * left;
    struct BinaryTree * right;
}*root;

void swap(struct BinaryTree* node, struct BinaryTree *temp);
struct BinaryTree*  Max();
struct BinaryTree* Min();
struct BinaryTree* find_deepest();
struct BinaryTree* delete_deepest();
void post_order(struct BinaryTree* node);
struct BinaryTree* Find(struct BinaryTree* node, int data);
void pre_order(struct BinaryTree* node);
void In_order(struct BinaryTree* node);
struct BinaryTree* heapify(struct BinaryTree* node);
// struct BinaryTree* heap_sort(struct BinaryTree* node);
void insert(int data);
struct BinaryTree* delete(struct BinaryTree* node, int data);
void display(struct BinaryTree* node);

int main(){
    root = (struct BinaryTree*)malloc(sizeof(struct BinaryTree));
    int data, n, choice;
    printf("ENTER Number node in the Binary Tree: ");
    scanf("%d", &n);
    printf("Enter Data into the Binary Tree: ");
    scanf("%d", &data);
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    for(int i = 1; i < n; i++){
        scanf("%d", &data);
        insert(data);
    }
    printf("Binary Tree:");
    display(root);
    printf("\n\nChoose What to do: \n");
    printf("\n0.To Exit\n1.Insert into the Binary Tree\n2.Delete From the Binary Tree\n3.Post Order\n4.Pre Order\n5.Inorder\n");
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
            insert(data);
            printf("Binary Tree: ");
            display(root);
            break;
        
        case 2:
            printf("Enter Data you want to Delete: ");
            scanf("%d",&data);
            delete(root, data);
            printf("Binary Tree: ");
            display(root);
            break;
        case 3:
            printf("Post Order: ");
            post_order(root);
            break;
        
        case 4:
            printf("Pre Order: ");
            pre_order(root);
            break;
        case 5:
            printf("InOrder: ");
            In_order(root);
            break;
        
        default:
        printf("please Enter above option!!");
            break;
        }
    }
    return 0;

}
void insert(int data){
    struct BinaryTree *temp, *newnode;
    temp = root;
    newnode = (struct BinaryTree*)malloc(sizeof(struct BinaryTree));
    while(temp != NULL){
        if(data <= temp->data){
            if(temp->left == NULL){
                temp->left = newnode;
                newnode->data = data;    
                newnode->left = NULL;
                newnode->right = NULL;
                temp = newnode;

            }
            temp = temp->left;
        }else{
            if(temp->right == NULL){
                temp->right = newnode;
                newnode->data = data;
                newnode->left = NULL;
                newnode->right = NULL;
                temp = newnode;                    
            }
            temp = temp->right;
        }
    }
}


void display(struct BinaryTree* node){
     if(node == NULL){
        return;
    }
    display(node->left);
    printf("\t%d", node->data);
    display(node->right);
    
}
void post_order(struct BinaryTree* node){
    if(node == NULL){
        return;
    }
    post_order(node->left);
    post_order(node->right);
    printf("\t%d",node->data);
}

void pre_order(struct BinaryTree* node){
    if(node == NULL){
        return;
    }
    printf("\t%d",node->data);
    pre_order(node->left);
    pre_order(node->right);
}

void In_order(struct BinaryTree* node){
     if(node == NULL){
        return;
    }
    In_order(node->left);
    printf("\t%d", node->data);
    In_order(node->right);
    
}
struct BinaryTree* Find(struct BinaryTree* node, int data){
    if(node == NULL){
        return NULL;
    }
    if(data > node->data){
        return Find(node->left,data);
    }else if(data > node->data){
        return Find(node->right,data);
    }else{
        return node;
    }
}

struct BinaryTree* delete(struct BinaryTree* node, int data){
    struct BinaryTree *temp;
    temp = node;
    // temp_data = root;
    int d = find_deepest(root)->data;
    while(temp->data != data){
        if(temp->data < data){
            if(temp->right != NULL)
            temp = temp->right;
        }else{
            if(temp->left != NULL)
            temp = temp->left;
        }
    }
    if(temp->data == data){
        delete_deepest();
        temp->data = d;
        return temp;
    }
    heapify(root);
    return temp;

} 
struct BinaryTree* Min(){
    struct BinaryTree *temp, *Min; 
    temp = root;
    int min = temp->data;
    while(temp != NULL){
        if(temp->data <= min ){
            min = temp->data;
            Min = temp;
        }
        temp = temp->left;
    }
    return Min;
    
}

struct BinaryTree* Max(){
    struct BinaryTree *temp, *Max;
    temp = root;
    int max = temp->data;
    while(temp != NULL){
        if(temp->data >= max ){
            max = temp->data;
            Max = temp; 
        }
        temp = temp->right;
    }
    return Max;
    
}

struct BinaryTree* delete_deepest(){
    struct BinaryTree *node, *del;
    node = root;
    while(node->left != NULL || node->right != NULL){
        if(node->left){
            if(node->left == find_deepest(root)){
                del = node->left;
                node->left = NULL;
                free(del);
                return NULL;
            }
            node = node->left;
        }else if(node->right){
            if(node->right == find_deepest(root)){
                del = node->right;
                node->right = NULL;
                free(del);
                return NULL;
            }
            node = node->right;
        }
    }
    return NULL;
}

struct BinaryTree* find_deepest(){
    struct BinaryTree* node;
    node = root;
    while(node->left != NULL || node->right != NULL){
        if(node->left){
            node = node->left;
        }else if(node->right){
            node = node->right;
        }
    }
    return node;
}

struct BinaryTree* heapify(struct BinaryTree* node){
    struct BinaryTree *temp;
    // if(node->left != NULL &&  node->right != NULL){
    //     return NULL;
    // }
    if(node->left != NULL){
        temp = node->left;
        if(node->data < temp->data){
            swap(node, temp);
        }
        heapify(temp);
    }else if(node->right != NULL){
        temp = node->right;
        if(node->data > temp->data){            
            swap(node, temp);
        }
        heapify(node->right);
    }
    return NULL;
}

// struct BinaryTree* heap_sort(struct BinaryTree* node){
//     // struct BinaryTree *temp;
//     int i;
//     int arr[] = {};
//     while(node != NULL){
//         arr[i] = node->data;
//         node = delete(node, node->data);
//         heapify(node);
//         i++;
//     }
//     i = 0;
//     printf("d");
//     while(arr[i] != NULL){
//         printf("%d",arr[i]);
//         i++;
//     }
//     return NULL;
// }

void swap(struct BinaryTree* node, struct BinaryTree *temp){
    int swap;
    swap = node->data;
    node->data = temp->data;
    temp->data = swap;
}
