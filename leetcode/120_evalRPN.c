/***********************************************************************
 * @file 120_evalRPN.c
     120_EVALRPN
 * @brief   source file
 * @history
 * Date       Version Author    description
 * ========== ======= ========= =======================================
 * 2021-07-07 V1.0    zhoutao   Create
 *
 * @Copyright (C)  2021  .cdWFVCEL. all right reserved
***********************************************************************/
int my_isdigtal(char input)
{
    char temp = input - '0';
    if (temp <= 9 || temp >= 0) {
        return 1;
    }
    return 0;
}

int evalRPN(char ** tokens, int tokensSize){
    int stack[tokensSize];
    int top = 0;

    for (int i = 0; i < tokensSize; i++) {
        char *taken = tokens[i];
        if (my_isdigtal(taken[0])) {
            stack[top++] = atoi(taken);
        } else {
            int num1 = stack[--top];
            int num2 = stack[--top];
            switch (taken[0]) {
                case '+':
                    stack[top++] = num1 + num2;
                    break;
                case '-':
                    stack[top++] = num2 - num1;
                    break;
                case '*':
                    stack[top++] = num2 * num1;
                    break;
                case '/':
                    stack[top++] = num2 / num1;
                    break;
            }
        }
    }
    return stack[0];
}