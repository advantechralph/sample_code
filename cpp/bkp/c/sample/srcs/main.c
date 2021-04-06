#include <stdio.h>
#include <stdlib.h>

void pause(void){
    printf("pause, please enter any key...");
    getchar();
}

int main() { 
    pause();
    return 0; 
} 

