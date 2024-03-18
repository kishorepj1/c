#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node {
    int c;
    int px;
    int py;
    int pz;
    struct node *link;
};

typedef struct node * NODE;

float evaluate(float x, float y, float z, NODE head) {
    float sum;
    NODE cur;
    sum = 0;
    cur = head->link;
    while (cur != head) {
        sum = sum + cur->c * pow(x, cur->px) * pow(y,cur->py) * pow(z, cur->pz);
        cur = cur->link;
    }
    return sum;
}

void print_polynomial(NODE head) {
    NODE p;
    for (p = head->link; p != head; p = p->link) {
        if (p->c > 0)
            printf("+%dx^%dy^%dz^%d ", p->c, p->px, p->py, p->pz);
        else
            printf("%dx^%dy^%dz^%d ", p->c, p->px, p->py, p->pz);
    }
    printf("\n");
}

NODE getnode() {
    NODE x;
    x = (NODE) malloc(sizeof(struct node));
    if (x == NULL) {
        printf("Not enough memory\n");
        exit(0);
    }
    return x;
}

NODE insert_rear(int c, int px, int py, int pz, NODE head) {
    NODE cur, temp;
    temp = getnode();
    temp->c = c;
    temp->px = px;
    temp->py = py;
    temp->pz = pz;
    cur = head->link;
    while (cur->link != head) {
        cur = cur->link;
    }
    cur->link = temp;
    temp->link = head;
    return head;
}

NODE read_polynomial() {
    NODE head;
    int c, px, py, pz;
    head = getnode();
    head->link = head;
    for(;;) {
        scanf("%d", &c);
        if (c == 0) break;
        scanf("%d", &px);
        scanf("%d", &py);
        scanf("%d", &pz);
        head = insert_rear(c, px, py, pz, head);
    }
    return head;
}

NODE add_2_polynomials(NODE h1, NODE h2) {
    int sum;
    NODE p, q, h3;
    h3 = getnode();
    h3->link = h3;
    for (p = h1->link; p != h1; p = p->link) {
        for (q = h2->link; q != h2; q = q->link) {
            if (p->px == q->px && p->py == q->py && p->pz == q->pz) {
                sum = p->c + q->c;
                q->c = 0;
                if (sum != 0) h3 = insert_rear(sum, p->px, p->py, p->pz, h3);
                break;
            }
        }
        if (q == h2) h3 = insert_rear(p->c, p->px, p->py, p->pz, h3);
    }
    for (q = h2->link; q != h2; q = q->link) {
        if (q->c == 0) continue;
        h3 = insert_rear(q->c, q->px, q->py, q->pz,h3);
    }
    return h3;
}

void free_memory(NODE head) {
    NODE cur, temp;
    cur = head->link;
    while (cur != head) {
        temp = cur;
        cur = cur->link;
        free(temp);
    }
    free(head);
}

int main() {
    NODE h1, h2, h3;
    int choice;
    float x, y, z, sum;
    for(;;) {
        printf("1:Add 2:Evaluate 3:Exit : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter first polynomial : ");
                h1 = read_polynomial();
                printf("Enter second polynomial : ");
                h2 = read_polynomial();
                printf("Poly1: ");
                print_polynomial(h1);
                printf("Poly2: ");
                print_polynomial(h2);
                h3 = add_2_polynomials(h1, h2);
                printf("Poly3: ");
                print_polynomial(h3);
                free_memory(h1);
                free_memory(h2);
                free_memory(h3);
                break;
            case 2:
                printf("Enter a polynomial");
                h1 = read_polynomial();
                printf("Enter x y and z : ");
                scanf("%f %f %f", &x, &y, &z);
                sum = evaluate(x, y, z, h1);
                printf("Result = %f\n", sum);
                free_memory(h1);
                break;
            default:
                exit(0);
        }
    }
    return 0;
}
