#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 5
int top = -1;
int stack[10];

void push(int item) {
  if (top == STACK_SIZE - 1) {
    printf("Overflow of stack\n");
    return;
  }
  top++;
  stack[top] = item;
}

void pop() {
  if (top == -1) {
    printf("Stack underflow\n");
    return;
  }

  printf("Item deleted = %d\n", stack[top]);
  top = top - 1;
}

void display() {
  int i;

  if (top == -1) {
    printf("Stack is empty\n");
    return;
  }

  printf("Stack: ");
  for (i = 0; i <= top; i++)
    printf("%d ", stack[i]);

  printf("\n");
}

void palindrome(char str[]) {
  int i;

  for (i = 0; str[i] != '\0'; i++) {
    stack[++top] = str[i];
  }

  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] == stack[top--])
      continue;
    printf("%s: Not a palindrome\n", str);
    return;
  }

  printf("%s: Palindrome\n", str);
}

int main() {
  int item, choice;
  char str[10];

  for (;;) {
    printf("1: Insert 2: Delete 3: Display 4:Palindrome 5: Exit : ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter the item: ");
      scanf("%d", &item);
      push(item);
      break;

    case 2:
      pop();
      break;

    case 3:
      display();
      break;

    case 4:
      printf("Enter the string: ");
      scanf(" %[^\n]", str);
      palindrome(str);
      break;

    default:
      exit(0);
    }
  }
}
