#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer = {51,51,-1,-1};
    int X; //바탕화면 세로
    int Y; //바탕화면 가로
    
    X = wallpaper.size();
    Y = wallpaper[0].length();
        
    //cout << X << ' ' << Y << endl;
    
    for (int i = 0 ; i < X ;i++){
        for (int j = 0 ; j < Y ; j++){   
            if(wallpaper[i][j] == '#'){
                if (i < answer[0]){
                    answer[0] = i;
                }
                if (j < answer[1]){
                    answer[1] = j;
                }
                if (i+1 > answer[2]){
                    answer[2] = i+1;
                }
                if (j+1 > answer[3]){
                    answer[3] = j+1;
                }
            }    
        }
    }
    
    
    
    return answer;
}