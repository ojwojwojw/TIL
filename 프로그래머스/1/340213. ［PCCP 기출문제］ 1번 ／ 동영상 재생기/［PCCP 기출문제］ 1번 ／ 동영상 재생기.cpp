#include <string>
#include <vector>
#include <iostream>

using namespace std;

int to_number(string in){
    int min = 60 * ((in[0]-'0')*10 + (in[1]-'0'));
    int second = ((in[3]-'0')*10 + (in[4]-'0'));
    return min + second;
    }

string to_str(int in){
    string res = "00:00";
    int min = in/60;
    int sec = in%60;
    if (min < 10){
        res[1] = min + '0';
    }else{
        res[0] = (min/10) + '0';
        res[1] = (min%10) + '0';
    }
    
    if (sec < 10){
        res[4] = sec + '0';
    }else{
        res[3] = (sec/10) + '0';
        res[4] = (sec%10) + '0';
    }
    

    
    return res;
}


string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    int L = commands.size();
    string command = "";
    
    for (int i = 0 ; i<L ; i++){
        command = commands[i];
        
        if(to_number(op_start) <= to_number(pos) && to_number(pos) <= to_number(op_end)){
            pos = op_end;
        }
        
        
        if(command == "next"){
            if(to_number(pos) + 10 > to_number(video_len)){
                pos = video_len;
            }else{
                pos = to_str(to_number(pos) + 10);
            }
            
        }
        
        if(command == "prev"){
            if(to_number(pos) < 10){
                pos = "00:00";
            }else{
                pos = to_str(to_number(pos) - 10);
            }
        }
        
        if(to_number(op_start) <= to_number(pos) && to_number(pos) <= to_number(op_end)){
            pos = op_end;
        }    

    }
    
    answer = pos;
    return answer;
}