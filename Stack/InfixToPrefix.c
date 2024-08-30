#include <stdio.h>
#include <string.h>
#define max 50
char stack[max];
int top = -1;

//function declaration 
void push(char);
char pop();
int isempty();
int isoperand(char);
int isoperator(char);
int precedence(char);
int main()
{
    char infix[max] , prefix[max] , ch , temp;
    int i = 0 , j = 0 ;
    printf("Enter a infix Expresion : ");
    gets(infix);
    strrev(infix);
    push(')');

    while (!(isempty()))
    {
        ch = infix[i];
        if(isoperand(ch))
            prefix[j++] = ch;
        else if(ch == ')')
            push(ch);
        else if(isoperator(ch))
        {
            while (precedence(ch) < precedence(stack[top]) && stack[top] != ')')
                prefix[j++] = pop();
            push(ch);
        }
        else
        {
            while (stack[top] != ')')
                prefix[j++] = pop();
            temp = pop();
            
        }
        i++;
    }
    prefix[j] = '\0';
    strrev(prefix);
    printf("Prefix expresion : ");
    puts(prefix);
    
    return 0 ;
}

//push operation 
void push(char ch)
{
    if(top == max-1)
        return;
    stack[++top] = ch;
}
//checking for operand
int isoperand(char ch)
{
    if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
        return 1;
    return 0 ;
}
//pop opertion 
char pop()
{
    if(top == -1)
        return 0;
    return stack[top--]; 
}
//precedence check

int precedence(char ch)
{
    if(ch == '^')
        return 3;
    else if(ch == '*' || ch == '/' || ch== '%')
        return 2;
    else if(ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

//checking empty stack

int isempty()
{
    if(top == -1)
        return 1;
    return 0 ;
}
// operator check
int isoperator(char ch)
{
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%')
        return 1;
    return 0;
}