#include <string>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    long long quarter_cnt = 0;
    long long boundary_cnt = 0;
    double max = 0;
    double min = 0;
    
    for(long long x = 0 ; x < r2+1; x++){
        if (x >= r1){
            max = sqrt(r2*(long long)r2 - x*(long long)x);
            quarter_cnt += floor(max) + 1;
            boundary_cnt += 1;
            // cout << floor(max) + 1 << endl;
        }
        else{
            max = sqrt(r2*(long long)r2 - x*(long long)x);
            min = sqrt(r1*(long long)r1 - x*(long long)x);
            quarter_cnt += floor(max) - ceil(min) + 1;
            // cout << max << min << endl;
            // cout << floor(max) - ceil(min) + 1 << endl;
        }
    }
    
    answer = 4*quarter_cnt - 4*boundary_cnt;

    return answer;
}