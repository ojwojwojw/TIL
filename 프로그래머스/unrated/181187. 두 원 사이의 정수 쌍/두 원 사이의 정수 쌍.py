import math

def solution(r1, r2):
    answer = 0
    quarter_cnt = 0
    boundary_cnt = 0
    
    for x in range(0, r2+1):
        if x >= r1:
            max = math.sqrt(r2**2 - x**2)
            quarter_cnt += math.floor(max) + 1
            boundary_cnt += 1
            # print(max,min)
            # print( math.floor(max) + 1)
        else:
            max = math.sqrt(r2**2 - x**2)
            min = math.sqrt(r1**2 - x**2)
            
            quarter_cnt += math.floor(max) - math.ceil(min) + 1
            # print(max,min)
            # print( math.floor(max) - math.ceil(min) + 1)
        
    answer = 4*quarter_cnt - 4*boundary_cnt
        
    return answer