def countMeasure (num , l , p):
    # num의 약수에는 1과 num도 포함하므로 result를 2로 한다
    result = 2
    d = 2
    o = num
    # num보다 작은 2와 num 사이의 수들로 
    # num 을 계속 나누며 약수의 개수를 구한다
    # d가 num의 약수라면 1/d도 num 약수이다
    while (d*d <= o):
        if d*d == num:
            result += 1
        
        elif num%d == 0:
            result += 2
        d += 1
    
    # 1은 예외 처리
    if num == 1 :
        result  = 1
          
    # power와 limit을 고려한 처리  
    if result  > l:
        return p
    else:
        return result 
        
def solution(number, limit, power):
    answer = 0

    # 1부터 number를 순회한다
    for i in range(1, number+1):
         #각 원소에 해당하는 약수의 개수를 구한다
         # 함수 내에서 limit와 power를 고려한 예외 처리를 해준다
        # print(countMeasure(i , limit ,power))
        answer += countMeasure(i ,limit ,power)
        
    return answer