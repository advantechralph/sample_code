#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "isUTF8.h"
#include "isASCII.h"
int main(int argc, char *argv[]){
    printf("%s, %d: \n", __FUNCTION__, __LINE__);
    uint8_t chinese1[]="\xe4\xb8\x80"; 
    uint8_t chinese2[]="\xe4\xb8\x80\xc3"; 
    uint8_t chinese3[]="\xe4\xb8\x80\xe4\xb8\x80"; 
    printf("chinese1: ret(%d)\n", isUTF8((const char *)chinese1, 3));
    printf("chinese2: ret(%d)\n", isUTF8((const char *)chinese2, 4));
    printf("chinese3: ret(%d)\n", isUTF8((const char *)chinese3, 6));
    return 0; 
}
