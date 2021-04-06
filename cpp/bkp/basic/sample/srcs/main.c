#include <stdio.h>
#include <stdlib.h>
#include <iostream>

void pause(void){
    printf("pause, please enter any key...");
    getchar();
}

int main() { 
    pause();
    return 0; 
} 

