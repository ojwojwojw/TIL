#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define LEN_INPUT 10

int main(void) {
    char s1[LEN_INPUT];
    scanf("%s", s1);

    int length = strlen(s1);
    
    for (int i = 0 ; i < length ; i ++){
        if ((s1[i] & 32 )== 32){
            s1[i] = s1[i] & ~32;
        } 
        else{
            s1[i] = s1[i] | 32;
        }
    }
    
    printf("%s",s1);
    
    return 0;
}
