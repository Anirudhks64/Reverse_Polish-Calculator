//
// Created by Anirudh on 30/03/21.
//

#ifndef PS5_NODE_H
#define PS5_NODE_H


enum type_of_value{
    OPERATOR,
    NUMBER
};


enum type_of_operation{
    LEFT_BRACKET,
    RIGHT_BRACKET,
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION,
    EXPONENTIATION
};


typedef struct node{
    union{
        double value;
        char operator;
    } contents;
    int type;
    int precedence;
    struct node *next;
}node;


struct node* createNode(int type, char *token);

#endif //PS5_NODE_H
