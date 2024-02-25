#include <stdio.h>
#include <string.h>

int F(char symbol) {
  switch (symbol) {
  case '#':
    return -1;

  case '+':
  case '-':
    return 2;

  case '*':
  case '/':
  case '%':
    return 4;

  case '^':
  case '$':
    return 5;

  case '(':
    return 0;

  default:
    return 8;
  }
}

int G(char symbol) {
  switch (symbol) {
  case ')':
    return 0;

  case '+':
  case '-':
    return 1;

  case '*':
  case '/':
  case '%':
    return 3;

  case '^':
  case '$':
    return 6;

  case '(':
    return 7;

  default:
    return 9;
  }
}

void infix_2_postfix(char infix[], char postfix[]) {
  int i, j = 0, top = -1;
  char s[20];

  s[++top] = '#';
  for (i = 0; infix[i] != '\0'; i++) {
    while (F(s[top]) > G(infix[i]))
      postfix[j++] = s[top--];

    if (F(s[top]) != G(infix[i]))
      s[++top] = infix[i];
    else
      s[top--];
  }

  while (s[top] != '#') {
    postfix[j++] = s[top--];
  }

  postfix[j] = '\0';
}

int main() {
  char infix[20], postfix[20];

  printf("Infix :");
  scanf("%[^\n]", infix);

  infix_2_postfix(infix, postfix);

  printf("Postfix:");
  printf("%s\n", postfix);

  return 0; // added return statement
}
