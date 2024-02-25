#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int queue[10], front = 0, rear = -1, count = 0;

void insert_rear(int item) {
  if (count == MAX) {
    printf("Q overflow\n");
    return;
  }

  rear = (rear + 1) % MAX;
  queue[rear] = item;

  count++;
}

void delete_front() {
  if (count == 0) {
    printf("Q underFlow\n");
    return;
  }

  printf("Item deleted = %d\n", queue[front]);
  front = (front + 1) % MAX;

  count--;
}

void display() {
  int i, temp;

  if (count == 0) {
    printf("Q is empty\n");
    return;
  }

  printf("Queue : ");
  temp = front;
  for (i = 1; i <= count; i++) {
    printf("%d ", queue[temp]);
    temp = (temp + 1) % MAX;
  }

  printf("\n");
}

int main() { // changed void to int
  int item, choice;

  for (;;) {
    printf("1: insert 2:Delete 3:Display 4:Exit : ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter the item : ");
      scanf("%d", &item);
      insert_rear(item);
      break;

    case 2:
      delete_front();
      break;

    case 3:
      display();
      break;

    default:
      exit(0);
    }
  }

  return 0; // added return statement
}
