#include <string>
#include <vector>
#include <iostream>
using namespace std;
int canZip(int n,int x,int y,vector<vector<int>> &arr){
    int sumV = 0;
    for(int i = x ; i < x + n; i++){
        for (int j = y ; j < y + n ; j++){
            sumV += arr[i][j];
        }
    }
    
   	if(sumV == n*n){
        return 1;
    }
    else if(sumV == 0){
        return 0;
    }
    else{
        return 2;
    }
    
}

void recursion(int n, int x, int y , vector<vector<int>> &arr ,vector<int> &answer){
    int allSame = 0;
    int before = arr[x][y];
    bool stopSearch = false;
    for(int i = x ; i < x + n ; i++){
        for(int j = y ; j < y + n ; j++){
            if(before != arr[i][j]){
                stopSearch = true;
                break;
            }
            allSame += arr[i][j];
            before = arr[i][j];
        }
        if(stopSearch) break;
    }
    
    if(!stopSearch){
        if(allSame == n*n){
        answer[1]++;
        return;
        }
        else if (allSame == 0){
            answer[0]++;
            return;
        }  
    }
    
    for (int i = x ; i <= x + n/2 ; i += n/2){
        for (int j = y ; j <= y + n/2 ; j += n/2){
            recursion(n/2,i,j,arr,answer);
        }
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer = {0, 0};
    int n = arr.size();
    recursion(n,0,0,arr,answer);
    return answer;
}