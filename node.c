//
// Created by Anirudh on 30/03/21.
//

#include "node.h"
#include "stack.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



// Enum type variable declaring type of operation in the parsed token



// Function to create nodes and push onto stack
node* createNode(int type, char *token) {

    node *temp = NULL;
    temp = (node *) malloc(sizeof(node));


    if (type == OPERATOR) {
        switch (*token) {
            case '(':
                temp->contents.operator = '(';
                temp->precedence = 6;
                break;
            case '^':
                temp->contents.operator = '^';
                temp->precedence = 5;
                break;
            case '*':
                temp->contents.operator = '*';
                temp->precedence = 4;
                break;
            case '/':
                temp->contents.operator = '/';
                temp->precedence = 3;
                break;
            case '+':
                temp->contents.operator = '+';
                temp->precedence = 2;
                break;
            case '-':
                temp->contents.operator = '-';
                temp->precedence = 1;
                break;

        }// switch

        temp->type = OPERATOR;
        temp->next = NULL;
        return temp;
    }// if OPERATOR


    else {
        // strtod() function coverts a character to an int

        temp->contents.value = (double)atoi(token);
        temp->type = NUMBER;
        temp->next = NULL;
        return temp;
    }// if NUMBER

// CreateNode
}


int to_number_converter(char* given_token){
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
}



