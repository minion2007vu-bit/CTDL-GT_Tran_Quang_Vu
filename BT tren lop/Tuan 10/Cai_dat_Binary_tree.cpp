#include<stdio.h>
#include<stdlib.h>


typedef struct Node{
    int data;
    struct Node *lp;
    struct Node *rp;
} Node;

Node *create_Node(int value){
    Node * temp = (Node*) malloc(sizeof(Node));
    temp -> data = value;
    temp -> lp = NULL;
    temp -> rp = NULL;
    return temp;
}

void insert_BT(Node** root, int* arr, int n, int index){
    if( index < n){
        *root = create_Node(arr[index]);
        insert_BT(&(*root)->lp, arr, n, 2*index + 1);
        insert_BT(&(*root)->rp, arr, n, 2*index + 2);
    }
}

void show(Node* root){
    if (root == NULL) return;
    printf("%d", root -> data);
    show(root -> lp);
    show(root -> rp);
}

void show_inOrder(Node *root){
    if (root == NULL) return;
    show (root -> lp);
    printf("%d", root -> data);
    show(root -> rp);
} 

int sumBT(Node* root) {
    if (root == NULL) return 0;

    return root->data + sumBT(root->lp) + sumBT(root->rp);
}

int heightBT(Node* root, int count){
    heightBT(root -> lp, count);
    heightBT(root -> rp, count);
    count++;
}

int main(){
    Node* bt;
    int a[7] = {11, 2, 3, 4, 25, 6, 7};
    insert_BT(&bt, a, 7, 0);
    printf("Tong cac phan tu cua cay la: %d", sumBT(bt));
    printf("Chieu cao cua cay la: %d", heightBT(bt, 0));

}
