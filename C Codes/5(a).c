#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <ctype.h>

double compute(double operand1, char operator, double operand2) { 
 switch (operator) { 
 case '+': return operand1 + operand2; 
 case '-': return operand1 - operand2; 
 case '*': return operand1 * operand2; 
 case '/': return operand1 / operand2; 
 case '%': return fmod(operand1, operand2); 
 case '^': return pow(operand1, operand2); 
 default: 
 exit(0); 
 } 
} 

double evaluate(char postfix[]) { 
 int i, top = -1; 
 double stack[20], operand1, operand2; 
 char num[5];
 int j = 0;
 for (i = 0; postfix[i] != '\0'; i++) { 
 if (isdigit(postfix[i])) { 
 num[j++] = postfix[i];
 } else if(postfix[i] == ' ' && j != 0) {
 num[j] = '\0';
 stack[++top] = atof(num);
 j = 0;
 } else if(postfix[i] != ' ') {
 operand2 = stack[top--]; 
 operand1 = stack[top--]; 
 stack[++top] = compute(operand1, postfix[i], operand2); 
 }
 } 
 return stack[top--]; 
} 

int main() { 
 char postfix[50]; 
 double result; 
 printf("Enter Postfix expression: "); 
 fgets(postfix, 50, stdin);
 result = evaluate(postfix); 
 printf("Result = %lf\n", result); 
 return 0; 
}
