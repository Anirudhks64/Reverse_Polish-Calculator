//
// Created by Anirudh on 30/03/21.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "rpn.h"
#include "node.h"
#include "stack.h"
#include "errors.h"

/*Returns NULL when called
 * Used to return NULL to main when error encountered in any functions*/
char* if_error(){
    return NULL;
}// if_error



// Helper function for exponentiation using recursion (Same one written in P-SET 1)
double recursivePower(double value_1, double value_2) {
    if (value_2 != 0) {
        return (value_1 * recursivePower(value_1, value_2 - 1));
    }// end if
    else{
        return 1;
    }//end else
}// end of recursivePower



//returns 1 if the given token is a number and returns 0 if the given token is not a number
int isNumber(char* given_token){
    int count = 0;

    for(int i = 0; i < strlen(given_token); i++){
        if(given_token[i] >= '0' && given_token[i] <= '9'){
            count++;
        }// if
        else{
            return 0;
        }//else
    }// for
    return 1;
}// isNumber






// Evaluates the given expression and returns the result
double evaluate(char* expression, int* status){

    int error_value = error_checking(expression);
    if(error_value != 1){
        exit(1);
    }// if

    clearStack();
    int counter = 0;
    double result = 0;
    char result_as_string[9];
    char* tokenized_string = strtok(expression, " ");

    node* placeholder = NULL;
    node* placeholder_1 = NULL;

    while(tokenized_string != NULL){

        switch (*tokenized_string) {

            case '+':
                createNode(OPERATOR, tokenized_string);
                double val_Add_1 = pop()->contents.value;
                double val_Add_2 = pop()->contents.value;

                result = val_Add_1 + val_Add_2;
                sprintf(result_as_string, "%f", result);
                //printf("%s\n",result_as_string);
                placeholder_1 = createNode(NUMBER, result_as_string);
                push(placeholder_1);
                break;

            case '-':

                createNode(OPERATOR, tokenized_string);
                double val_Sub_1 = pop()->contents.value;;
                double val_Sub_2 = pop()->contents.value;;
                result = val_Sub_2 - val_Sub_1;
                sprintf(result_as_string, "%lf", result);
                placeholder_1 = createNode(NUMBER, result_as_string);

                push(placeholder_1);
                break;

            case '*':

                createNode(OPERATOR, tokenized_string);
                double val_Mul_1 = pop()->contents.value;;
                double val_Mul_2 = pop()->contents.value;;
                result = val_Mul_1 * val_Mul_2;
                sprintf(result_as_string, "%lf", result);
                placeholder_1 = createNode(NUMBER, result_as_string);
                push(placeholder_1);
                break;


            case '/':

                createNode(OPERATOR, tokenized_string);
                double val_Div_1 = pop()->contents.value;

                // Error handling
                if(val_Div_1 == 0){
                    printf("Cannot divide by value 0\n");
                    *status = -1;
                    exit(1);
                }//if

                double val_Div_2 = pop()->contents.value;

                result = (val_Div_2 / val_Div_1);
                sprintf(result_as_string, "%lf", result);
                placeholder_1 = createNode(NUMBER, result_as_string);
                push(placeholder_1);
                break;


            case '^':

                createNode(OPERATOR, tokenized_string);
                double val_Exp_1 = pop()->contents.value;
                double val_Exp_2 = pop()->contents.value;
                result = recursivePower(val_Exp_2, val_Exp_1);
                sprintf(result_as_string, "%lf", result);
                placeholder_1 = createNode(NUMBER, result_as_string);
                push(placeholder_1);
                break;

            default:
                placeholder_1 = createNode(NUMBER, tokenized_string);
                push(placeholder_1);
                //printf("%s\n",tokenized_string);

        }// switch

        tokenized_string = strtok(NULL, " ");

    }// while

    if(result == 0){
        printf("The String is Empty\n");
    }// if
    return result;

}//evaluate





/*returns postfix notation of passed string*/
char* converter(char expression[100]){

    /* invalid_elements_check, returns 0 if there are any invalid elements
     * present in the array passed, otherwise passes a 1. Function written in
     * the errors.c file
    */
    int checker = invalid_elements_check(expression);
    if(checker == 0){
        //printf("\nThere are invalid elements in the expression\n");
        return NULL;
    }// if

    clearStack();
    char *storage;
    storage = malloc (sizeof (char) * strlen(expression));
    /*Checking to see if malloc returns a NULL*/
    if(storage == NULL){
        //printf("ERROR: Storage value not assigned");
        return NULL;
    }// if


    char converted_string[100] = {0};
    char placeholder_char[2] = {0};
    char empty_space[1] = " ";
    char copied_string[strlen(expression)];

/*Copies the expression into another string copied_string*/
    strcpy(copied_string, expression);

    char* element_in_string = strtok(copied_string, " ");

    while(element_in_string != NULL) {

        /* Calling Helper function written in rpn.c
         * isNumber() returns 1 if the element_in_string is a number
         * and 0 if the element_in_string is an something else*/
        int val = isNumber(element_in_string);

        /* Enters the if statement in case the token is a number */
        if (val == 1) {

            placeholder_char[0] = *element_in_string;
            strncat(converted_string, element_in_string, strlen(element_in_string));
            strncat(converted_string, empty_space, 1);
        }//if

            /* It enters the if statement in case the token is an operator*/
        else if (*element_in_string == '^' ||
                 *element_in_string == '*' ||
                 *element_in_string == '/' ||
                 *element_in_string == '+' ||
                 *element_in_string == '-') {

            node *curr_token = createNode(OPERATOR, element_in_string);


            /* while ((there is an operator at the top of the operator stack)
              and ((the operator at the top of the operator stack has greater
                  precedence)
                  or (the operator at the top of the operator stack has equal
                        precedence and the token is left associative))
              and (the operator at the top of the operator stack is not a
                  left parenthesis)):*/

            if (peek() == NULL) {
                push(curr_token);
            }// if
            else {

                while (peek()!= NULL && ((peek()->type == OPERATOR && peek()->precedence > curr_token->precedence) ||
                        peek()->precedence == curr_token->precedence && ((curr_token->contents.operator == '-')
                                                                         || (curr_token->contents.operator == '/')
                                                                         || (curr_token->contents.operator == '+')
                                                                         || (curr_token->contents.operator == '*')
                                                                         || (curr_token->contents.operator == '^')
                        )) && (peek()->contents.operator != '(')) {

                    /*pop operators from the operator stack onto the output queue.*/
                    strncat(converted_string, &pop()->contents.operator, 1);
                    strncat(converted_string, empty_space, 1);
                }// while


                /*Otherwise, push it onto the operator stack */
                push(curr_token);
            }// else

        }// else if 1

        else if (*element_in_string == '(') {
            /*Creates a node for the left parenthesis and pushes it onto the stack*/
            node *curr_token = createNode(OPERATOR, element_in_string);
            push(curr_token);
        }// else if 2

        else if (*element_in_string == ')') {
            int counter = 0;
            int elements_in_stack = counting();
            while (peek()->contents.operator != '(') {
                strncat(converted_string, &pop()->contents.operator, 1);
                strncat(converted_string, empty_space, 1);
                counter++;
                if (counter == elements_in_stack) {
                    //printf("ERROR: Mismatched Parenthesis");
                    /*This function will return NULL if there were mismatched parenthesis
                     * which will then be handled in main.c.
                     * Written at the top of rpn.c*/

                    return NULL;
                }// if
            }// while
            if (peek()->contents.operator == '(') {
                pop(); //
            }// if
        }// else if 3
        element_in_string = strtok(NULL, " ");
    }// while


    while (peek() != NULL) {
        print_stack();

        if (peek()->contents.operator == '(') {
            //printf("ERROR: Mismatched Parenthesis");
            return NULL;
        }// if


        placeholder_char[0] = pop()->contents.operator;
        strncat(converted_string,  placeholder_char, 1);
        strncat(converted_string, empty_space, 1);


    }// while

    strcpy(storage, converted_string);
    return storage;


}// converter




