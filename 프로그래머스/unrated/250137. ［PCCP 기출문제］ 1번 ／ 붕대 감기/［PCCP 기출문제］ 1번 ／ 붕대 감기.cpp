#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int maxHp, vector<vector<int>> attacks) {
    int realTime = attacks[attacks.size() - 1][0];  //모든 공격이 끝나는 시간
    int ht = 0; // 현재 시전 시간 체크용
    int hp = maxHp ; // 현재 체력 
    bool isAttacked = false; // 현재 시간의 피격 여부
    int p = 0; // attacks를 순회할 포인터    

    // 1초단위로 상황을 체크한다
    for (int t = 1 ; t <= realTime ; t++){
       
        // 피격 여부를 체크한다
        if (t == attacks[p][0]){
            isAttacked = true;
        }

        // 공격 받았을때는 hp가 깎이고 ht가 초기화 된다.
        if (isAttacked){
            hp -= attacks[p][1];
            ht = 0;
            //포인터를 한칸 뒤로 이동한다.
            p ++;
        }
        
        
        
        // 공격 받지 않았을때에만 회복을 한다 
        if (!isAttacked){
            
            hp += bandage[1];
            // 회복한 체력이 maxHp를 넘지 않도록 한다
            if (hp > maxHp){
            hp = maxHp;
            }
            
            // 현재 시전시간이 1 오른다
            ht ++;
        }

        //현재 시전시간 달성시 추가 체력회복을 한다
        if (ht == bandage[0]){
            hp += bandage[2];
            // 회복한 체력이 maxHp를 넘지 않도록 한다
            if (hp > maxHp){
            hp = maxHp;
            }
            // 현재 시전시간이 초기화 된다.
            ht = 0;
        }
        
        // debug
        //cout<< "time:" << t << " "<< hp << " "<< ht << " "<<isAttacked << '\n';
        
    
        //매 초마다 초기화할 변수들
        isAttacked = false;
        
        //캐릭터 사망 체크
        if (hp <= 0){
            hp = -1;
            break;
        }

        
        
    }
    

    
    return hp;
}