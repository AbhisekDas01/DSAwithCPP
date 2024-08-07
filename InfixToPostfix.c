#include <stdio.h>
#include <string.h>
#define max 50
char stack[max];
int top = -1;

void push(char);
char pop();
int isempty();
int isoperand(char);
int isoperator(char);
int precedence(char);

int main()
{
    char infix[max] , postfix[max] , ch ,temp;
    int i = 0 , j = 0 , len ;
    printf("Enter a Infix Expresion : ");
    scanf("%s" , infix);
    len = strlen(infix);
    infix[len] = ')';
    infix[len+1] = '\0';
    push('(');

    //conversion expresion 
    while(!(isempty()))
    {
        ch = infix[i];
        if(isoperand(ch))
            postfix[j++] = ch;
        else if(ch == '(')
            push(ch);
        else if(isoperator(ch))
        {
            while (precedence(ch) <= precedence(stack[top]) && stack[top] != '(')
                postfix[j++] = pop();
            push(ch);
        }
        else
        {
            while (stack[top] != '(')
                postfix[j++] = pop();
            temp = pop();
        }
        i++;
    }
    postfix[j] = '\0';
    printf("Postfix Expresion : ");
    puts(postfix);
    return 0;
}
//push operation 
void push(char ch)
{
    if(top == max-1)
        return;
    else
        stack[++top] = ch;
}

//checking empty stack

int isempty()
{
    if(top == -1)
        return 1;
    return 0 ;
}

//checking for operand
int isoperand(char ch)
{
    if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
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

char pop()
{
    if(top == -1)
        return 0;
    else
        return stack[top--];
}