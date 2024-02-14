# 소수점 올림해주는 함수
def Upper(num):
    if num % 1 == 0:
        return int(num)
    else :
        return int(num) + 1
    
# 00:00 을 분단위로 바꾸어주는 함수
def ToMinute(string):
    h,m = string.split(":")
    return 60*int(h) + int(m)

def solution(fees, records):
    #print(fees) # 기본시간 , 기본 요금 , 단위 시간 , 단위요금
    #print(records) # 시간 , 차량번호 ,입/출차여부
    
    answer = []
    feeTable = {}
    lastDir = {}
    N = len(records)
    
    for record in records:
        time, car_num, direction = record.split()
        feeTable[car_num] = []
        
    #print(feeTable)
    
    for record in records:
        time, car_num, direction = record.split()
        #print(time,car_num,direction)
        if direction == "IN":
            feeTable[car_num].append(ToMinute(time))
            lastDir[car_num] = direction
        elif direction == "OUT":
            in_time = feeTable[car_num].pop()
            feeTable[car_num].append(ToMinute(time) - in_time)
            lastDir[car_num] = direction
    
    #11:59 처리
    for car_num in feeTable.keys():
        #print(car_num)
        if lastDir[car_num] == "IN" :
            in_time = feeTable[car_num].pop()
            feeTable[car_num].append(ToMinute("23:59") - in_time)
            lastDir[car_num] = direction
            

    print(feeTable)
    # feeTable을 먼저 차량번호가 작은순으로 정렬하고 정답을 계산
    sorted_car_num = sorted(feeTable.keys())
    
    
    print(sorted_car_num)
    for car_num in sorted_car_num:
        #print(car_num)
        total_time = sum(feeTable[car_num])
        #print(total_time)
        if total_time <= fees[0]:
            answer.append(fees[1])
        else:
            answer.append(fees[1] + Upper((total_time - fees[0])/fees[2])*fees[3])
        
    return answer