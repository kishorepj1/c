#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *llink;
    struct node *rlink;
};

typedef struct node *NODE;

NODE getnode() {
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    if(x == NULL) {
        printf("Not enough memory\n");
        exit(0);
    }
    return x;
}

int search(int item, NODE root) {
    NODE cur;
    if (root == NULL) return 0;
    cur = root;
    while (cur != NULL) {
        if (item == cur->info) return 1;
        if (item < cur->info)
            cur = cur->llink;
        else
            cur = cur->rlink;
    }
    return 0;
}

NODE insert(int item, NODE root) {
    NODE temp, cur, prev;
    temp = getnode();
    temp->info = item;
    temp->llink = temp->rlink = NULL;
    if (root == NULL) return temp;
    cur = root;
    while (cur != NULL) {
        prev = cur;
        if (item < cur->info)
            cur = cur->llink;
        else
            cur = cur->rlink;
    }
    if (item < prev->info)
        prev->llink = temp;
    else
        prev->rlink = temp;
    return root;
}

void preorder(NODE root) {
    if (root == NULL) return;
    printf("%d ",root->info);
    preorder(root->llink);
    preorder(root->rlink);
}

void inorder(NODE root) {
    if (root == NULL) return;
    inorder(root->llink);
    printf("%d ",root->info);
    inorder(root->rlink);
}

void postorder(NODE root) {
    if (root == NULL) return;
    postorder(root->llink);
    postorder(root->rlink);
    printf("%d ",root->info);
}

void free_tree(NODE root) {
    if (root == NULL) return;
    free_tree(root->llink);
    free_tree(root->rlink);
    free(root);
}

int main() {
    int item, choice, flag;
    NODE root;
    root = NULL;
    for(;;) {
        printf("1:Insert 2:Preorder\n");
        printf("3:Inorder 4:Postorder\n");
        printf("5:Search 6:Exit : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the item : ");
                scanf("%d", &item);
                root = insert(item, root);
                break;
            case 2:
                if (root == NULL) {
                    printf("Empty");
                    break;
                }
                printf("Preorder : ");
                preorder(root);
                printf("\n");
                break;
            case 3:
                if (root == NULL) {
                    printf("Empty");
                    break;
                }
                printf("inorder : ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                if (root == NULL) {
                    printf("Empty");
                    break;
                }
                printf("postorder : ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Enter the item to be searched : ");
                scanf("%d", &item);
                flag = search(item, root);
                if (flag == 0)
                    printf("Item not found\n");
                else
                    printf("Item found\n");
                break;
            default:
                free_tree(root);
                exit(0);
        }
    }
    return 0;
}
