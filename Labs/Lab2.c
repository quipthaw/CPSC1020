/************************** 
 * *Manning Graham 
 * *CPSC 1021, F19 
 * *Mcgraha@g.clemson.edu
 * *Prof Hochrine
 * **************************/
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
void sizeOfName(char** name);
void printSizeOfName(int* first, int* last, char** name);
void reverseString(int* first, int* last, char** name);
int main(){
 
    char** name;
    int i=0;
    name = (char**)malloc(2 * sizeof(char*));
    name[0] = (char*)malloc(100 * sizeof(char));
    name[1] = (char*)malloc(100 * sizeof(char));
 
    printf("what is your first name? ");
    scanf("%s", name[0]);
    printf("what is your last name? ");
    scanf("%s", name[1]);
    
    sizeOfName(name);
    
    free(name[0]);
    free(name[1]);
    free(name);
return 0;
}
 
void sizeOfName(char** name){ //This first function determines the number of characters in each function
    int firstCount=0;
    int lastCount = 0;
    
    while(name[0][firstCount]!='\0'){ //This while loop determines the number of characters in the first array
        firstCount++;
    }
    while(name[1][lastCount]!='\0'){ //This while loop determines the number of characters in the second array
        lastCount++;
    }
    printSizeOfName(&firstCount, &lastCount, name);
 
}
 
void printSizeOfName(int *firstCount, int *lastCount, char** name){ // They are then printed with this function
    printf("\n\n");
    printf("%s, Your first name is %d characters.\n", name[0], *firstCount);
    printf("Your last name, %s, is %d characters.\n", name[1], *lastCount);
    reverseString(firstCount, lastCount, name);
}
 
void reverseString(int *first, int *last, char **name){ // and lastly this function reverses and prints both arrays
    printf("\n\n");
    printf("Your name in reverse is:\n");
    int i;
    for(i=0; i < (*first)/2; i++){  // This for loop reverses the first arrays order
        char ch = name[0][i]; 
        name[0][i] = name[0][(*first)-i-1];
        name[0][(*first)-i-1] = ch;
    }
 
    for(i=0; i < (*last)/2; i++){ // This for loop reverses the second arrays order
        char ch = name[1][i];
        name[1][i] = name[1][(*last)-i-1];
        name[1][(*last)-i-1] = ch;
    }
 
    printf("%s\n%s\n", name[0], name[1]);
}