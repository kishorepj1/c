#include <stdio.h>

void Transfer(int n, char source, char temp, char dest) {
  if (n == 0)
    return;

  Transfer(n - 1, source, dest, temp);

  printf("Move disk %d from %c to %c\n", n, source, dest);

  Transfer(n - 1, temp, source, dest);
}

int main() { // changed void to int
  int n;

  printf("Enter number of disks : ");
  scanf("%d", &n);

  Transfer(n, 'A', 'B', 'C');

  return 0; // added return statement
}
