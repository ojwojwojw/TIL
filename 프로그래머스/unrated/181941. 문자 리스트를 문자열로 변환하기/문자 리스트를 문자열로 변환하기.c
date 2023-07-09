#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* arr[], size_t arr_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    
    size_t total_length = 0;
    for (int i = 0 ; i < arr_len ; i ++)
    {
        total_length += strlen(arr[i]);
    }
    
    // printf("%d", total_length);
    
    
    char* answer = (char*)malloc(total_length + 1 );
    
    
    answer[0] = '\0';
    
    for (int j = 0 ; j < arr_len ; j++)
    {
        answer = strcat(answer,arr[j]);
    }
    printf("%s",answer);
    
    return answer;
}