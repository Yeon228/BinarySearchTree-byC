#include <stdio.h>
#include <malloc.h>
typedef struct node{
    int val;
    struct Node* left;
    struct Node* right;
}Node;

void preorder(Node* p);
void postorder(Node* p);
void inorder(Node* p);
Node* makeNode(int val, Node* p);


int main() {
    setbuf(stdout,0);
    Node* root = NULL;
    while(1){
        printf("1 : add, 2 : preorder, 3 : inorder, 4 : postorder, 0 : exit\n");
        int n;
        scanf("%d", &n);

        if(n == 0)break;
        else if(n == 1){
            int val;
            scanf("%d", &val);
            root = makeNode(val,root);
        }
        else if(n == 2){
            preorder(root);
            printf("\n");
        }
        else if(n == 3){
            inorder(root);
            printf("\n");
        }
        else if(n == 4){
            postorder(root);
            printf("\n");
        }
        else printf("This is wrong option please repeat input\n");
    }
}
void preorder(Node* p){
    printf("%d ,", p->val);
    if(p->left !=NULL)preorder(p->left);
    if(p->right !=NULL)preorder(p->right);
}
void postorder(Node* p){
    if(p->left !=NULL)preorder(p->left);
    if(p->right !=NULL)preorder(p->right);
    printf("%d ,", p->val);
}
void inorder(Node* p){
    if(p->left !=NULL)preorder(p->left);
    printf("%d ,", p->val);
    if(p->right !=NULL)preorder(p->right);
}
Node* makeNode(int val, Node* p){
    if(p==NULL){
        p = (Node*) malloc(sizeof (Node));
        p->val = val;
        p->right = NULL;
        p->left = NULL;
        return p;
    }
    else if(p->val > val){
        p-> left = makeNode(val, (Node *) p->left);
        return p;
    }
    else{
        p-> right = makeNode(val, (Node *) p->right);
        return p;
    }
}
