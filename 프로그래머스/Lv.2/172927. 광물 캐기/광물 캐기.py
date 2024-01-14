def solution(picks, minerals):
    answer = 0
    
    dia_mapping = {"diamond":1,"iron":1,"stone":1}
    iron_mapping = {"diamond":5,"iron":1,"stone":1}
    stone_mapping = {"diamond":25,"iron":5,"stone":1}
    
    dia_picker = picks[0]
    iron_picker = picks[1]
    stone_picker = picks[2]
    
    #미네랄을 5단위로 끊어서 새로운 리스트를 만든다.
    #슬라이스 연산자로 곡괭이의 개수만큼 잘라준다.
    minerals = [minerals[i:i+5] for i in range(0,len(minerals),5)][:sum(picks)]
    
    #그리디 알고리즘을 위해 minerals_5 의 정렬이 필요하다.
    # 다이아몬드, 철, 돌의 개수에 따라 내림차순으로 정렬
    #print(minerals)
    minerals.sort(key = lambda x : (x.count("diamond"),x.count("iron"),x.count("stone")), reverse = True)
    #print(minerals)
    
    for mineral in minerals:
        
        if dia_picker > 0 :
            for name in mineral:
                answer += dia_mapping[name]
            dia_picker -= 1
            
        elif iron_picker > 0:
            for name in mineral:
                answer += iron_mapping[name]
            iron_picker -= 1
        
        elif stone_picker > 0:
            for name in mineral:
                answer += stone_mapping[name]
            stone_picker -= 1

    return answer