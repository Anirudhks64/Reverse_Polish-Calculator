//
// Created by Anirudh on 02/04/21.
//

#ifndef PS5_ERRORS_H
#define PS5_ERRORS_H
#define SUCCESSFUL 0;
#define NULL_POINTER 1;
#define TOO_MANY 2;
#define TOO_LESS 3;
#define ALERT_DIVIDE 4;
int error_checking(char* expression);
int invalid_elements_check(char* string_to_postfix);
char* null_removed_char_pointer(char* line);
#endif //PS5_ERRORS_H
