#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(void) {
    string str;
    cin >> str;
    
    char ans[str.length()+1];
    
    strcpy(ans , str.c_str());
        
    for (int i = 0 ;  i < str.length() ; i++){
        cout << ans[i]<< endl;
    }
    
    return 0;
}