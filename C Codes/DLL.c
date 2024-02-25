#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char ssn[10];
  char name[10];
  char dept[10];
  char desg[10];
  char ph[10];
  float sal;
} EMPLOYEE;

struct node {
  char ssn[10];
  char name[10];
  char dept[10];
  char desg[10];
  char ph[10];
  float sal;
  struct node *llink;
  struct node *rlink;
};

typedef struct node *NODE;

NODE getnode() {
  NODE x;
  x = (NODE)malloc(sizeof(struct node));
  if (x == NULL) {
    printf("Not enough memory\n");
    exit(0);
  }
  return x;
}

void display(NODE head) {
  NODE cur;
  if (head->rlink == head) {
    printf("Empty\n");
    return;
  }
  printf("SSN NAME DEPT DESGIN PHONE SAL\n");
  cur = head->rlink;
  while (cur != head) {
    printf("%-10s%-10s%-10s%-10s%-14s%f\n", cur->ssn, cur->name, cur->dept,
           cur->desg, cur->ph, cur->sal);
    cur = cur->rlink;
  }
}

int count_node(NODE head) {
  NODE cur;
  int count;
  if (head->rlink == head)
    return 0;
  cur = head->rlink;
  count = 0;
  while (cur != head) {
    count++;
    cur = cur->rlink;
  }
  return count;
}

NODE insert_rear(EMPLOYEE emp, NODE head) {
  NODE last, temp;
  temp = getnode();
  strcpy(temp->ssn, emp.ssn);
  strcpy(temp->name, emp.name);
  strcpy(temp->dept, emp.dept);
  strcpy(temp->desg, emp.desg);
  strcpy(temp->ph, emp.ph);
  temp->sal = emp.sal;
  // Get the address of the last node
  last = head->llink;
  // Insert the node at the end
  last->rlink = temp;
  temp->llink = last;
  temp->rlink = head;
  head->llink = temp;
  return head;
}

NODE insert_front(EMPLOYEE emp, NODE head) {
  NODE temp, first;
  temp = getnode();
  strcpy(temp->ssn, emp.ssn);
  strcpy(temp->name, emp.name);
  strcpy(temp->dept, emp.dept);
  strcpy(temp->desg, emp.desg);
  strcpy(temp->ph, emp.ph);
  temp->sal = emp.sal;
  // Get the address of the first node
  first = head->rlink;
  // Insert the node between head and first node
  temp->rlink = first;
  first->llink = temp;
  head->rlink = temp;
  temp->llink = head;
  return head;
}

NODE delete_rear(NODE head) {
  NODE last, prev;
  // Check for empty list
  if (head->rlink == head) {
    printf("List is empty\n");
    return head;
  }
  // Obtain the address of the last node
  last = head->llink;
  // Obtain address of the last but one node
  prev = last->llink;
  // Make last but one node as the last node
  prev->rlink = head;
  head->llink = prev;
  printf("Item deleted = %s\n", last->ssn);
  free(last);
  return head;
}

NODE delete_front(NODE head) {
  NODE first, second;
  // Check for empty list
  if (head->rlink == head) {
    printf("List is empty\n");
    return head;
  }
  first = head->rlink; // Get the first node
  second = first->rlink; // Get the second node
  // Make second node as the first node
  head->rlink = second;
  second->llink = head;
  printf("Item deleted = %s\n", first->ssn);
  free(first);
  return head;
}

void read_employee_details(EMPLOYEE *emp) {
  printf("SSN : ");
  scanf("%s", emp->ssn);
  printf("Name : ");
  scanf("%s", emp->name);
  printf("Deptment : ");
  scanf("%s", emp->dept);
  printf("Designation : ");
  scanf("%s", emp->desg);
  printf("Phone : ");
  scanf("%s", emp->ph);
  printf("Salary : ");
  scanf("%f", &emp->sal);
}

int main() {
  int choice, count;
  NODE head;
  EMPLOYEE emp;
  head = getnode();
  head->rlink = head->llink = head;
  for (;;) {
    printf("1:Insert Front 2:Insert Rear\n");
    printf("3:Delete Front 4:Delete Rear\n");
    printf("5:Display 6:Count 7: Exit : ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      read_employee_details(&emp);
      head = insert_front(emp, head);
      break;
    case 2:
      read_employee_details(&emp);
      head = insert_rear(emp, head);
      break;
    case 3:
      head = delete_front(head);
      break;
    case 4:
      head = delete_rear(head);
      break;
    case 5:
      display(head);
      break;
    case 6:
      count = count_node(head);
      printf("Number of nodes = %d\n", count);
      break;
    default:
      exit(0);
    }
  }
  return 0; // added return statement
}
