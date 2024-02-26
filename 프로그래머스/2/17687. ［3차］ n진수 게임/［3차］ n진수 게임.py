mapp = {0:'0',1:'1',2:'2',3:'3',4:'4',5:'5',
        6:'6',7:'7',8:'8',9:'9',10:'A',
       11:'B',12:'C',13:'D',14:'E',15:'F'}


def solution(n, t, m, p):
    answer = ''
    num_string = ''
    
    for i in range(n*t*m):
        num = i
        if num == 0:
            num_string += '0'
        
        temp_str = ""
        while (num > 0) :
            temp_str = mapp[num %n] + temp_str
            num = num//n
    
        num_string += temp_str
    
    #print(num_string)
    
    for i in range(p-1,t*m,m):
        answer += num_string[i]
    
    return answer