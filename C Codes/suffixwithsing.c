#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double compute(double operand1, char operator, double operand2) {
  switch (operator) {
  case '+':
    return operand1 + operand2;
  case '-':
    return operand1 - operand2;
  case '*':
    return operand1 * operand2;
  case '/':
    return operand1 / operand2;
  case '%':
    return fmod(operand1, operand2);
  case '^':
    return pow(operand1, operand2);
  default:
    exit(0);
  }
}

double evaluate(char postfix[]) {
  int i, top = -1;
  double stack[20], operand1, operand2;
  for (i = 0; postfix[i] != '\0'; i++) {
    if (postfix[i] >= '0' && postfix[i] <= '9') {
      stack[++top] = postfix[i] - '0';
    } else {
      operand2 = stack[top--];
      operand1 = stack[top--];
      stack[++top] = compute(operand1, postfix[i], operand2);
    }
  }
  return stack[top--];
}

int main() {
  char postfix[20];
  double result;
  printf("Enter Postfix expression: ");
  scanf("%s", postfix);
  result = evaluate(postfix);
  printf("Result = %lf\n", result);
  return 0;
}
