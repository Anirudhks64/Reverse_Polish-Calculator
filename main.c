#include <stdio.h>
#include <stdlib.h>
#include "rpn.h"
#include "errors.h"
#include <string.h>

#define SIZE_OF_STRING 100

int main() {

    int status = 0;
    char* converted_postfix;

/*Reading from a file*/
    FILE *fp = fopen("ps5-infile.txt","r");
    FILE *fw = fopen("ps5-outfile.txt", "w");
    char dataLine[SIZE_OF_STRING] = {0};

    // Error handling for NULL pointer to file
    if(!fp){
        perror("Error: The file could not be opened");
        exit(1);
    }// if

/*Getting lines from the opened file*/
        while(fgets(dataLine, SIZE_OF_STRING, fp)){
            dataLine[strcspn(dataLine, "\n")] = 0;
            char* next_line = "\n";
            converted_postfix = converter(dataLine);
            /* Inside converter function I have called an if_error() function
            * which returns in the case of Mismatched Parenthesis so that I can
            * print it onto the ps5-output.txt*/
            if(converted_postfix == NULL){
                printf("Error in your code: Recheck input string for mismatched parenthesis or invalid operators\n");
                fprintf(fw, "Error in your code: Recheck input string for mismatched parenthesis or invalid operators");
                fprintf(fw, "%s", next_line);
                continue;
            }// if
                double result = evaluate(converted_postfix, &status);
                fprintf(fw, "Postfix: %s", converted_postfix);
                fprintf(fw, "%f", result);
                fprintf(fw, "%s", next_line);
                printf("%f\n", result);

        }// while
        fclose(fp);
        fclose(fw);
    return 0;
}// main