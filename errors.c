//
// Created by Anirudh on 02/04/21.
//

#include "errors.h"
#include "string.h"
#include "stdio.h"
#include <stdlib.h>


char errors[5][50] = {
        "Your Calculation was successful",
        "ALERT: Null Pointer",
        "ALERT: Too Many Operands",
        "ALERT: Too Few Operands",
        "ALERT: Division By 0 Is Not Allowed"
};

// Helper function
int number_or_not(char* given_token){
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
}// number_or_not



int error_checking(char* expression){
    int numbers = 0;
    int operators = 0;

    char placeholder_string[100];
    strcpy(placeholder_string, expression);
    char* element = strtok(placeholder_string, " ");

    while(element != NULL) {
        if (number_or_not(element) == 1) {
            numbers++;
        }// if

        else{
            operators++;
        }//else


        element = strtok(NULL, " ");

    }// while

        if(operators > numbers-1){
            printf("There are too many operators");
            return 0;
        }// if

        else if(operators < numbers -1){
            printf("There are too few operators");
            return  0;
        }// else if

        else{
        return 1;
        }//else
}//error_checking

/* Checks for invalid elements in the expression given and returns 1
 * if valid and returns 0 if invalid*/
int invalid_elements_check(char* string_to_postfix){
    char placeholder_string_5[100];
    int return_value = 0;
    strcpy(placeholder_string_5, string_to_postfix);
    char* element_1 = strtok(placeholder_string_5, " ");

    while(element_1 != NULL){

        int val = number_or_not(element_1);

        if(val == 1){
            return_value = 1;
        }// if

        else if (*element_1 == '^' ||
                 *element_1 == '*' ||
                 *element_1 == '/' ||
                 *element_1 == '+' ||
                 *element_1 == '-' ||
                 *element_1 == '(' ||
                 *element_1 == ')')
        {
            return_value = 1;
        }// else if

        else{
            return 0;
        }// else

        element_1 = strtok(NULL, " ");
    }// while

    return return_value;

}// invalid_elements_check



char* null_removed_char_pointer(char* line) {

    char placeholder[100] = {0};
    char* space = " ";
    int counter = 0;
    char* element = strtok(line, " ");

    while(element != NULL){
        counter++;
        strncat(placeholder, element, strlen(element));
        strncat(placeholder, space, 1);
        element = strtok(NULL, " ");
    }// while





    return placeholder;
}// while

