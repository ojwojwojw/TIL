#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// array_len은 배열 array의 길이입니다.
int solution(int array[], size_t array_len) {
    int answer = 0;
    int max_index = 0;
    int maxV = 0;
    int cnt_array[1000] = {0};
    int multi_check = 0;
    
    for(int i = 0 ; i < array_len ; i++){
        cnt_array[array[i]] += 1  ;   
    }
       
    
    for(int j = 0 ; j < 1000 ; j++){
        if (cnt_array[j] > maxV){
            max_index = j;
            maxV = cnt_array[j];
        }
    }
        
    
    for(int k = 0 ; k < 1000 ; k++){
        if (cnt_array[k] == maxV){
            multi_check += 1;
        }
    }
    
    
    if (multi_check == 1){
        answer = max_index;
    }
    else{
        answer = -1;
    }
    
    
    return answer;
}