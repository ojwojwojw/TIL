Number = ['1','2','3','4','5','6','7','8','9','0']
Area = ['S','D','T']
AtoN = {'S' : 1 , 'D' : 2 , 'T' : 3}
Option = ['*','#']


def Calculate (lst):
    char = ''
    res = 0
    if len(lst)== 2:
        res = int(lst[0])**AtoN[lst[1]]
    elif len(lst) == 3:
        if lst[2] == "*":
            res = int(lst[0])**AtoN[lst[1]]
            res *= 2
        else :
            res = int(lst[0])**AtoN[lst[1]]
            res *= -1
    return res

def solution(dartResult):
    answer = 0
    record = []
    p = 0
    ST = []
    char = '' 
    last_idx = len(dartResult)
    
    for i in range(last_idx):
        char = dartResult[i]  
 
        print('char:',char ,'ST:', ST)
        if not ST:
            ST.append(char)
        elif ST[-1] in Number and char in Number:
            ST[-1] += char
        elif ST and char in Area:
            ST.append(char)
            if (i == last_idx - 1):
                record.append(Calculate(ST))
                ST = []
                p += 1
            if (i < last_idx-1 and dartResult[i+1] in Number):
                record.append(Calculate(ST))
                ST = []
                p += 1
        elif ST and char in Option:
            ST.append(char)
            record.append(Calculate(ST))
            if ST[-1] == "*" and p > 0:
                record[p-1] *= 2
            ST = []
            p += 1


        print('record: ',record)

    answer = sum(record)
    return answer