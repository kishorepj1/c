#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  char usn[25];
  char name[25];
  char programme[25];
  char phone[12];
  int sem;
  struct node *link;
};

typedef struct node *NODE;

NODE getnode() {
  NODE x;

  x = (NODE)malloc(sizeof(struct node));

  if (x == NULL) {
    printf("not enough memory");
    exit(0);
  }

  return x;
}

NODE insert_front(char usn[], char name[], char programme[], char phone[], int sem,
                  NODE first) {
  NODE temp;

  temp = getnode();

  strcpy(temp->usn, usn);
  strcpy(temp->name, name);
  strcpy(temp->programme, programme);
  strcpy(temp->phone, phone);
  temp->sem = sem;

  temp->link = first;

  return temp;
}

NODE insert_rear(char usn[], char name[], char programme[], char phone[], int sem,
                 NODE first) {
  NODE temp, cur;

  temp = getnode();

  strcpy(temp->usn, usn);
  strcpy(temp->name, name);
  strcpy(temp->programme, programme);
  strcpy(temp->phone, phone);
  temp->sem = sem;

  temp->link = NULL;

  if (first == NULL)
    return temp;

  cur = first;
  while (cur->link != NULL) {
    cur = cur->link;
  }

  cur->link = temp;

  return first;
}

NODE delete_rear(NODE first) {
  NODE prev, cur;

  if (first == NULL) {
    printf("Student list is empty\n");

    return NULL;
  }

  if (first->link == NULL) {
    printf("The student with usn %s is deleted\n ", first->usn);
    free(first);

    return NULL;
  }

  cur = first;
  while (cur->link != NULL) {
    prev = cur;
    cur = cur->link;
  }

  prev->link = NULL;

  printf("The student with usn %s is deleted\n", cur->usn);
  free(cur);

  return first;
}

NODE delete_front(NODE first) {
  NODE prev, cur;

  if (first == NULL) {
    printf("students list is empty\n");

    return NULL;
  }

  if (first->link == NULL) {
    printf("The student with usn %s is deleted\n", first->usn);
    free(first);
    return NULL;
  }

  cur = first->link;

  printf(" The student with usn %s is deleted\n", first->usn);
  free(first);

  return cur;
}

void display(NODE first) {
  NODE cur;

  printf("Student list\n");

  printf("usn name programme phone sem");

  if (first == NULL) {
    printf("empty");

    return;
  }

  cur = first;

  while (cur != NULL) {
    printf("\n%s", cur->usn);
    printf("%10s", cur->name);
    printf("%10s", cur->programme);
    printf("%10s", cur->phone);
    printf("%10d", cur->sem);

    cur = cur->link;
  }

  printf("\n");
}

int main() { // changed void to int
  char usn[25], name[25], programme[25], phone[12];
  int choice, sem;
  NODE first;

  for (;;) {
    printf("\n\n 1:Front insert 2:rear insert\n");
    printf("3:Front delete 4:rear delete\n"); // corrected the menu
    printf("5: Display 6:exit\n");
    printf("Enter your choice");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("USN: ");
      scanf("%s", usn);
      printf("Name: ");
      scanf("%s", name);
      printf("programme: ");
      scanf("%s", programme);
      printf("phone: ");
      scanf("%s", phone);
      printf("sem: ");
      scanf("%d", &sem);

      first = insert_front(usn, name, programme, phone, sem, first);
      break;

    case 2:
      printf("USN : ");
      scanf("%s", usn);
      printf("Name : ");
      scanf("%s", name);
      printf("Progrm : ");
      scanf("%s", programme);
      printf("Phone : ");
      scanf("%s", phone);
      printf("Sem : ");
      scanf("%d", &sem);
      first = insert_rear(usn, name, programme, phone, sem, first);
      break;

    case 3:

      first = delete_front(first);
      break;

    case 4:

      first = delete_rear(first);
      break;

    case 5:
      display(first);
      break;

    default:
      exit(0);
    }
  }

  return 0; // added return statement
}
