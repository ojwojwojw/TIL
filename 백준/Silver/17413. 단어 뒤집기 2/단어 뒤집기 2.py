
def reverse(String):
    String = String[::-1]
    Ans = ''
    for char in String:
        Ans += char
    return Ans

Numbers = ['1','2','3','4','5','6','7','8','9','0']
Alphabets = ['a','b','c','d','e','f','g','h','i','j',
             'k','l','m','n','o','p','q','r','s','t','u','v',
             'w','x','y','z']
String = input() + ' '
Ans = ''
temp = ''
meetLessSign = False
meetNumber = False

index = 0
for char in String:
    if char in Alphabets or char in Numbers:
        temp += char
        if char in Numbers:
            meetNumber = True

    elif char == ' ' and not meetLessSign:
        Ans += reverse(temp) + char
        temp = ''
    elif char == ' ' and meetLessSign:
        temp += char

    elif char == '<' and not meetNumber and meetLessSign:
        temp += char
        meetLessSign = True

    elif char == '<' and not meetNumber and not meetLessSign:
        Ans += reverse(temp)
        temp = ''
        temp += char
        meetLessSign = True

    elif char == '<' and meetNumber:
        Ans += reverse(temp)
        temp = ''
        temp += char
        meetLessSign = True

    elif char == '>' :
        Ans += temp + char
        temp = ''
        meetLessSign = False

    index +=1
print(Ans.rstrip())
