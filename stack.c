//
// Created by Anirudh on 30/03/21.
//
#include <stdlib.h>
#include "stack.h"
#include "node.h"
#include <string.h>
#include <stdio.h>


// Variable Head of type node which always contains the pointer to the top of the stack
struct node *Head = NULL;


// Pushes a node onto a stack
void push(node* node){
    node->next = Head;
    Head = node;

}// push


// Pops the uppermost node off the stack
node* pop(){
    struct node *placeholder = Head;
    if(Head){
        Head = Head->next;
    }//if
    else{
        placeholder = NULL;

    }//else

    return placeholder;
}// pop


// Returns a reference to the node on top of the stack
node* peek(){

    return Head;
}// peek


// Clears the stacks and free's the malloced nodes in the stack
void clearStack(){
    while(Head != NULL){
        struct node *placeholder = Head;
        Head = Head->next;
        free(placeholder);
    } // while
}// clearStack


int counting(){
    int counter = 0;
    node* placeholder3 = Head;
    while(placeholder3 != NULL){
        placeholder3 = placeholder3->next;
        counter = counter + 1;
    }// while
    return counter;
}// counting


void print_stack(){
    node* placeholder_head = Head;
    while(placeholder_head!=NULL){
        placeholder_head = placeholder_head->next;
    }
}