<p style="font-size: 33px; font-weight: 700; margin-bottom: 3rem">제어문(Control Statement)</p>

[파이썬 문서](https://docs.python.org/ko/3/tutorial/controlflow.html)

지금까지 우리는 위에서부터 아래로 순차적으로 명령을 수행하는 프로그램을 작성하였습니다.

특정 상황에 따라 코드를 선택적으로 실행(분기)하거나 동일한 코드를 계속해서 실행해야하려면 어떻게 해야할까요? 

이 경우, **코드 실행의 순차적인 흐름을 제어**(Control Flow)할 필요가 있습니다.

이러한 순차적인 코드의 흐름을 제어하는 것을 제어문이라고 하고, 제어문은 크게 **조건문**과 **반복문**으로 나눌 수 있습니다. 

제어문을 통해 다음과 순서도(Flow Chart)를 코드로 표현할 수 있습니다.

<center> 
    <img src="https://user-images.githubusercontent.com/18046097/61180553-25e87b00-a653-11e9-9895-7976d7204734.png", alt='if flowchart'/>
</center>


```python
# 위의 Flow Chart를 조건문으로 작성해봅시다.
# if 문을 활용해봅시다.
```


```python
a=5
if a>5:
    print('5 초과')
else:
    print('5 이하')
print(a)

```

    5 이하
    5
    

# 조건문(Conditional Statement)

`if` 문은 반드시 **참/거짓을 판단할 수 있는 조건**과 함께 사용합니다.


## `if` 조건문의 구성

### 활용법

- **문법**

```python
if <expression>:
    <코드 블럭>
else:
    <코드 블럭>
```

- **예시**

```python
if a > 0:
    print('양수입니다.')
else:
    print('음수입니다.')
```
* `expression`에는 일반적으로 참/거짓에 대한 조건식이 들어갑니다.

* **조건**이 **참**인 경우 `:` 이후의 문장을 수행합니다.

* **조건**이 **거짓**인 경우 `else:` 이후의 문장을 수행합니다.

* 여러 개의 `elif` 부가 있을 수 있고(없거나), `else`는 선택적으로 사용합니다.

### 주의사항
* 이때 반드시 **들여쓰기**를 유의해야합니다. 
    - 파이썬에서는 코드 블록을 자바나 C언어의 `{}`와 달리 **들여쓰기**로 판단하기 때문입니다.
* 앞으로 우리는 [PEP 8](https://www.python.org/dev/peps/pep-0008/#indentation)에서 권장하는 **4spaces**를 사용합니다.


<center>
    <img src="https://user-images.githubusercontent.com/18046097/61180564-3a2c7800-a653-11e9-9fba-d60d2688ed3a.png", alt="if style"/>
</center>

<br>

<center>
    <img src="https://user-images.githubusercontent.com/18046097/61180566-3ac50e80-a653-11e9-81a6-2f195eeb0a65.png", alt="[space vs tab]"/>
</center>    




[출처 : 400,000 GitHub repositories, 1 billion files, 14 terabytes of code: Spaces or Tabs?](https://medium.com/@hoffa/400-000-github-repositories-1-billion-files-14-terabytes-of-code-spaces-or-tabs-7cfe0b5dd7fd)


### [실습] 홀/짝 판독기


> 조건문을 통해 변수 num의 값과 홀수/짝수 여부를 출력하세요.

---

**[입력 예시]**

3

**[출력 예시]**

홀수입니다.


```python
num = int(input('숫자를 입력하세요 : '))
```

    숫자를 입력하세요 : 10
    


```python
# 아래에 코드를 작성하세요.
# if 문을 활용해봅시다.
# num에 할당된 값을 2로 나누었을때 나머지가 있는 경우에는 '홀수입니다.'를 출력하고
# num에 할당된 값이 2로 나누어 떨어지는 경우에는 '짝수입니다.'를 출력하는 코드를 작성하세요.
```


```python
if num%2==1:
    print('홀수')
else:
    print('짝수')
```

    짝수
    

### [연습] 크리스마스 판독기
> 조건문을 통해 사용자가 입력한 날짜가 크리스마스인지 확인하세요.

---

**[입력 예시]**

12/25

**[출력 예시]**

크리스마스입니다.


```python
is_christmas = input('날짜를 입력해주세요 ex)12/24 : ')
```

    날짜를 입력해주세요 ex)12/24 : 12/25
    


```python
# 아래에 코드를 작성하세요.
# if 문을 활용해봅시다.
# is_christmas에 할당된 값이 '12/25'인 경우에는
# '크리스마스입니다 :)' 를 출력하고
# 그외의 경우에는 '크리스마스가 아닙니다 :(' 를 출력하는 코드를 작성하세요.
```

if is_christmas=='12/25':
    print('크리스마스 입니다')
else:
    print('크리스마스 아닙니다')


```python
## `elif` 복수 조건

2개 이상의 조건을 활용할 경우 `elif <조건>:`을 활용합니다.
<center>
<img src="https://user-images.githubusercontent.com/18046097/61180560-3993e180-a653-11e9-8263-79bd7bc6eed7.png", alt="elif">
</center>
```

### [연습] 복수 조건문 연습

> 다음은 미세먼지 농도에 따른 등급일 때,
> dust 값에 따라 등급을 출력하는 조건식을 작성하세요.
> (단, 조건식 완료 후 미세먼지 확인 완료라는 문구를 출력)

![image-2.png](attachment:image-2.png)

--- 

**[입력 예시]**

80

**[출력 예시]**

보통

미세먼지 확인 완료!


```python
dust = int(input('미세먼지 농도를 입력하세요 : '))
```

    미세먼지 농도를 입력하세요 : 80
    


```python
# 아래에 코드를 작성하세요.
# if, elif, else 문을 활용해봅시다.
# dust에 할당된 값이 150 초과인 경우에는 '매우 나쁨'을 출력하고,
# dust에 할당된 값이 150 이하, 80 초과인 경우에는 '나쁨'을 출력하고,
# dust에 할당된 값이 80 이하, 30 초과인 경우에는 '보통'을 출력하고,
# dust에 할당된 값이 30 이하인 경우에는 '좋음'을 출력하고,
# 조건식 완료 이후 '미세먼지 확인 완료!'를 출력하는 코드를 작성하세요.
```


```python
if dust>150:
    print('매우 나쁨')
elif dust>80:
    print('나쁨')
elif dust>30:
    print('보통')
else:
    print('좋음')
print('미세먼지 학인 완료!')
```

    보통
    미세먼지 학인 완료!
    


```python
# 조건문은 순서대로 조건식을 검증하므로 순서에 유의해야 한다.
# dust 가 120이지만 조건문의 순서에 따라 '나쁨'을 출력하지 못하고 '보통'을 출력한다.

dust = 120

if dust > 150:
    print('매우 나쁨')
elif dust > 30:
    print('보통')
elif dust > 80:
    print('나쁨')
```

    보통
    

## 중첩 조건문(Nested Conditional Statement)

조건문은 다른 조건문에 중첩 가능합니다.

### [연습] 중첩 조건문 활용

> 아래의 코드에서 중첩조건문을 활용하여 미세먼지 농도(dust 값)이 300이 넘는 경우 ‘실외 활동을 자제하세요.’를 추가적으로 출력하고 음수인 경우 ‘값이 잘못 되었습니다.’를 출력하세요.

--- 
**[출력 예시]**

매우 나쁨

실외 활동을 자제하세요.


```python
dust = -1
```


```python
# 아래에 코드를 작성하세요.
# if, elif, else 문을 상황에 따라 중첩해서 활용해봅시다.
# dust에 할당된 값이 150 초과인 경우에 일단 '매우 나쁨'을 출력하고,
# dust에 할당된 값이 300 초과인 경우에는 추가적으로 '실외 활동을 자제하세요.'를 출력하고,
# dust에 할당된 값이 150 이하, 80 초과인 경우에는 '나쁨'을 출력하고,
# dust에 할당된 값이 80 이하, 30 초과인 경우에는 '보통'을 출력하고,
# dust에 할당된 값이 30 이하, 0 이상인 경우에는 '좋음'을 출력하고,
# dust에 할당된 값이 0 미만인 경우에는 '값이 잘못 되었습니다.'를 출력하는 코드를 작성하세요.
```


```python
if dust > 150:
    print('매우 나쁨')
    if dust > 300:
        print('실외 활동을 자제하세요')
elif dust > 80:
    print('나쁨')
elif dust > 30:
    print('보통')
elif dust >=0:
    print('좋음')
else:
    print('값이 잘못 되었습니다')
```

    값이 잘못 되었습니다
    

## 조건 표현식(Conditional Expression)

* 조건 표현식은 일반적으로 조건에 따라 값을 정할 때 활용됩니다.

* **삼항 연산자(Ternary Operator)**라고 부르기도 합니다.

---

**활용법**

```python
true_value if <조건식> else false_value
```


```python
num = int(input('숫자를 입력하세요 : '))

print('0 보다 큼') if num > 0 else print('0 보다 크지않음')
```

    숫자를 입력하세요 : 10
    0 보다 큼
    


```python
# 아래의 코드는 무엇을 위한 코드일까요?
num = int(input('숫자를 입력하세요 : '))
value = num if num >= 0 else -num
print(value)
```

    숫자를 입력하세요 : -30
    30
    


```python
# 아래에 주석으로 답변을 작성하세요.
```


```python
#절댓값을 구하는 조건식
```

### [연습] 조건 표현식 작성하기

> 다음의 코드와 동일한 조건 표현식을 작성해보세요.

```python
num = 2
if num % 2:
    result = '홀수입니다.'
else:
    result = '짝수입니다.'
print(result)
```
---

**[출력 예시]**
```
짝수입니다.
```


```python
# 아래에 코드를 작성하세요.
# 위의 조건문을 조건 표현식으로 바꿔보세요.
```


```python
num=2
result='짝수입니다'if num % 2 == 0 else '홀수입니다'
print(result)

```

    짝수입니다
    

### [실습] 조건 표현식과 동일한 if 문 작성하기

> 다음의 코드와 동일한 `if`문을 작성해보세요.

```python
num = -5
value = num if num >= 0 else 0
print(value)
```
---
**[출력 예시]**

0


```python
# 아래에 코드를 작성하세요.
# 위의 조건 표현식을 if 문으로 바꿔보세요.
```


```python
num = -5
if num >= 0 :
    value = num
else:
    value = 0 
print(value)
```

    0
    

---

# 반복문(Loop Statement)

- while
- for

## `while` 반복문

`while` 문은 조건식이 참(`True`)인 경우 반복적으로 코드를 실행합니다.


### 활용법
- **문법**

```python
while <조건식>:
    <코드 블럭>
```

- 예시

```python
while True:
    print('조건식이 참일 때까지')
    print('계속 반복')
```

### 주의사항
* `while` 문 역시 조건식 뒤에 콜론(`:`)이 반드시 필요하며, 이후 실행될 코드 블럭은 **4spaces**로 **들여쓰기**를 합니다.
* **반드시 종료조건을 설정해야 합니다.**


<br>
<center>
    <img src="https://user-images.githubusercontent.com/18046097/61180567-3ac50e80-a653-11e9-9f12-39c404f4be30.png", alt="">
</center>

<br>
<center>
    <img src="https://user-images.githubusercontent.com/18046097/61180568-3ac50e80-a653-11e9-9960-ba15137290a6.png", alt="while"/>
</center>


```python
# 위의 flow chart를 조건문을 통해 만들어봅시다.
# 아래에 코드를 작성하세요.
# while 문을 활용해봅시다.
```


```python
a = 0
while a < 5:
    print(a)
    a+=1
print('끝')
```

    0
    1
    2
    3
    4
    끝
    

### [연습] while 문 작성하기
> 사용자가 "안녕"이라고 입력할 때까지 인사하는 코드를 작성해보세요.


```python
# 아래에 코드를 작성하세요.
# while 문을 활용해봅시다.

# user_input에 초기값으로 비어있는 문자열을로 할당하고,

# user_input에 할당되는 값이 '안녕'일 떄까지,
    # '안녕?'을 출력하고
    # user_input에 사용자의 입력값을 받는 코드를 작성하세요.
```


```python
user_input = ''
while user_input != '안녕':
    print('안녕?')
    user_input = input('말해봐 : ')
```

    안녕?
    말해봐 : 네
    안녕?
    말해봐 : 네
    안녕?
    말해봐 : 네
    안녕?
    말해봐 : 시발
    안녕?
    말해봐 : 안녕
    

### [실습] 합(Summation)

> 1부터 사용자가 입력한 양의 정수까지의 총합을 구하는 코드를 작성해보세요.

---
**[입력 예시]**

10

**[출력 예시]**

55


```python
# 아래에 코드를 작성하세요.
```


```python
num = int(input())
a = 1
sum = 0

while a<num+1:
    sum+=a
    a+=1
   
print(sum)
```

    100
    5050
    

### [응용] 한자리 씩 출력하기

> 사용자로부터 입력 받은 양의 정수의 각 자리 수를 1의 자리부터 차례대로 출력하는 코드를 작성해보세요.


---
**[입력 예시]**

185

**[출력 예시]**

5

8

1


```python
# 아래에 코드를 작성하세요.
```


```python
num = int(input())

while num > 0.1:
    print(num%10)
    num=num//10
```

    25431
    1
    3
    4
    5
    2
    

## `for` 문

`for` 문은 시퀀스(string, tuple, list, range)를 포함한 순회가능한 객체(iterable)의 요소들을 순회합니다.

---

### 활용법
- **문법**

```python
for <임시변수> in <순회가능한데이터(iterable)>:
    <코드 블럭>
```

- **예시**

```python
for fruit in ['apple', 'mango', 'banana']:
    print(fruit)
print('끝')
```

<center>
    <img src="https://user-images.githubusercontent.com/18046097/61180565-3a2c7800-a653-11e9-806a-28838248de31.png", alt="">
</center>


```python
# flowchart를 for문을 통해 코드로 작성해봅시다.
# 아래에 코드를 작성하세요.
```


```python
for fruit in ['apple', 'mango', 'banana']:
    print(fruit)
print('끝')
```

    apple
    mango
    banana
    끝
    

![for animation](https://user-images.githubusercontent.com/18046097/61180563-3a2c7800-a653-11e9-8a7a-c7d6e6b30141.gif)

### [연습] for 문 작성하기
> `for` 문을 활용하여 사용자가 입력한 문자를 한글자씩 출력해보세요.

---
**[입력 예시]**
```
문자를 입력하세요 : 안녕!
```


**[출력 예시]**

```
안
녕
!
```


```python
chars = input('문자를 입력하세요 : ')
```

    문자를 입력하세요 : 으아아아아러어라
    


```python
# 아래에 코드를 작성하세요.
# for 문을 활용해봅시다.
# 변수 char에 할당된 문자를 한글자씩 출력하는 for 반복문을 작성하세요.
```


```python
for ch in chars:
    print(ch)
```

    으
    아
    아
    아
    아
    러
    어
    라
    

### 문자열(String) 순회

#### `range(문자열의 길이)`
`range()`와 순회할 srting의 길이를 활용하여 index를 조작 가능합니다.


```python
chars = input('문자를 입력하세요 : ')
```

    문자를 입력하세요 : 으아거아라아ㅏ가
    


```python
# 위에서 사용자가 입력한 문자를 range를 활용하여 한 글자씩 출력하는 for 문을 작성해봅시다.
```


```python
for i in range(len(chars)):
    print(chars[i])
```

    으
    아
    거
    아
    라
    아
    ㅏ
    가
    

### 딕셔너리 순회(반복문 활용)

딕셔너리에 `for` 문을 실행하면 기본적으로 다음과 같이 동작합니다.


```python
# 딕셔너리를 반복문과 함께 사용해봅시다.
# ''peter(key)은 80 이라는 점수(value)를 가지며,
# 'jake'(key)은 90 이라는 점수(value)를 가지는,
# 변수명이 grades인 딕셔너리를 만들어봅시다.

grades = {'peter':  80, 'jake': 90}
```


```python
# for문을 통해 딕셔너리 grades를 순회하면서 출력 값을 확인해봅시다.
for student in grades:
    print(student)
```

    peter
    jake
    

딕셔너리의 **key**에 접근할 수 있으면, 이를 통해 **value**에도 접근할 수 있습니다.

따라서 딕셔너리의 value를 출력하기 위해서는 아래와 같이 작성합니다.


```python
# 위에서 출력한 학생 이름(key)을 활용하여 점수(value)를 출력해봅시다.
```


```python
for student in grades:
    print(grades[student])
```

    80
    90
    

* dictionary에서 `for`를 활용하는 4가지 방법

```python
# 0. dictionary 순회 (key 활용)
for key in dict:
    print(key)
    print(dict[key])


# 1. `.keys()` 활용
for key in dict.keys():
    print(key)
    print(dict[key])
    
    
# 2. `.values()` 활용
# 이 경우 key는 출력할 수 없음
for val in dict.values():
    print(val)

    
# 3. `.items()` 활용
for key, val in dict.items():
    print(key, val)

```

### `enumerate()`
인덱스(index)와 값(value)을 함께 활용 가능합니다.

> `enumerate()`를 활용하면, 추가적인 변수를 활용할 수 있습니다.
- `enumerate()`는 [내장 함수](https://docs.python.org/ko/3.6/library/functions.html) 중 하나이며, 다음과 같이 구성되어 있습니다.
>
> <center>
    <img src="https://user-images.githubusercontent.com/18046097/61180561-3993e180-a653-11e9-9558-085c9a0ad65d.png", alt="enumerate">
</center>


```python
# enumerate()를 활용해서 출력해봅시다.
members = ['민수', '영희', '철수']
```


```python
# enumerate() 에 의해 반환되는 인덱스와 값(value)를 함께 출력하는 for 반복문을 작성해봅시다.
for idx, member in enumerate(members):
    print(idx, member)
```

    0 민수
    1 영희
    2 철수
    


```python
# enumerate()를 사용하였을 때 어떻게 표현이 되는지 확인해봅시다.
```


```python
print(enumerate(members))
print(list(enumerate(members)))
```

    <enumerate object at 0x000002CA185C5680>
    [(0, '민수'), (1, '영희'), (2, '철수')]
    


```python
# 첫번쨰 항목의 type을 확인해봅시다.
```


```python
print(list(enumerate(members))[0])
print(type(list(enumerate(members))[0]))
```

    (0, '민수')
    <class 'tuple'>
    

* 숫자를 1부터 카운트 할 수도 있습니다.


```python
# enumerate() 에 의해 반환되는 인덱스가 1로 시작하여 카운트되는 for 반복문을 작성해봅시다.
for idx, member in enumerate(members, start=1):
    print(idx, member)
```

    1 민수
    2 영희
    3 철수
    

### List Comprehension

List Comprehension은 표현식과 제어문을 통해 리스트를 생성합니다.

여러 줄의 코드를 한 줄로 줄일 수 있습니다.

---

#### 활용법

```python
[expression for 변수 in iterable]

list(expression for 변수 in iterable)
```

#### 세제곱 리스트

> 다음의 리스트를 작성하세요.
- 1~3까지의 숫자로 만든 세제곱 담긴 리스트 `cubic_list`


```python
# 1~3의 세제곱 리스트 만들기
cubic_list = []
for number in range(1, 4):
    cubic_list.append(number ** 3)
```


```python
print(cubic_list)
```

    [1, 8, 27]
    


```python
# List comprehension을 활용하여 작성하세요.
```


```python
list = []
for n in range(1,5):
    list.append(n ** 5)
print(list)
```

    [1, 32, 243, 1024]
    


```python
print(cubic_list)
```

    [1, 8, 27]
    

### Dictionary comprehension

dictionary도 comprehension을 활용하여 만들 수 있습니다. 

---

#### 활용법
`iterable`에서 `dict`를 생성할 수 있습니다.

```python
{키: 값 for 요소 in iterable}

dict({키: 값 for 요소 in iterable})
```


```python
# 1~3의 세제곱 딕셔너리 만들기
cubic = {}

for number in range(1, 4):
    cubic[number] = number**3
print(cubic)
```

    {1: 1, 2: 8, 3: 27}
    


```python
# Dictionary comprehension을 활용하여 작성하세요.
```


```python
cubic = {}

for n in range(0,5):
    cubic[n] = n**5
print(cubic)
```

    {0: 0, 1: 1, 2: 32, 3: 243, 4: 1024}
    

###  [실습] for 문과 if 문 작성하기

> 반복문과 조건문만 활용하여 1~30까지 숫자 중에 홀수만 출력해보세요.

---

**[출력 예시]**

```
1
3
5
...
27
29
```


```python
# 아래에 코드를 작성하세요.
```


```python
for i in range(1,31):
    if i%2==1:
        print(i)
```

    1
    3
    5
    7
    9
    11
    13
    15
    17
    19
    21
    23
    25
    27
    29
    

## 반복제어(`break`, `continue`, `for-else`)

### `break` 

반복문을 종료합니다.

* `for` 나 `while` 문에서 빠져나갑니다.


```python
# while 문에서 break를 활용해봅시다.
```


```python
# 종료 조건이 있는 while 문을 작성해봅시다.
# n의 초기값을 0으로 할당하고,
# n의 값이 3보다 작은 경우 n을 출력한 후, n을 1씩 증가시키는 while 반복문 코드를 작성해봅시다. 
n = 0
while n < 3:
    print(n)
    n += 1
```

    0
    1
    2
    


```python
# 종료 조건이 없는 while 문을 break 를 활용해서 종료시키는 코드를 작성해봅시다.
# n의 초기값을 0으로 할당하고,
# 종료조건 없이 n을 1씩 증가시키는 while 반복문 안에서 
# n이 3이 되는 경우에 break되어 반복문을 종료하는 코드를 작성해봅시다.
n = 0
while True:
    if n == 3:
        break
    print(n)
    n += 1
```

    0
    1
    2
    


```python
# for 문에서도 break를 사용할 수 있습니다.
```


```python
# 0부터 9까지 순회하는 for 반복문 안에서 
# 1을 초과하는 경우 '0과 1만 필요해!' 를 출력하며 종료하는 코드를 작성해봅시다.
for i in range(0,10):
    
    if i>1:
        print('we only need 1 and 0 !')
        break
    print(i)
```

    0
    1
    we only need 1 and 0 !
    

### [연습] `break` 활용하기

> 조건문과 반복문, `break`를 활용하여 리스트에서 쌀이 나왔을때 `for` 문을 멈추는 코드를 작성하세요.

---

**[출력 예시]**

보리

보리

쌀

잡았다!


```python
rice = ['보리', '보리', '보리', '쌀', '보리']

# 아래에 코드를 작성하세요.
```


```python
for i in rice:
    print(i)
    if i == '쌀':
        print('잡았다!')
        break
```

    보리
    보리
    보리
    쌀
    잡았다!
    

### `continue`

`continue`문은 continue 이후의 코드를 수행하지 않고, *다음 요소부터 계속(continue)하여* 반복을 수행합니다.


```python
# continue 문을 확인해봅시다.
# for문을 통해 0~5까지의 숫자를 반복하며,
# 짝수인 경우 continue하고,
# 홀수인 경우 해당 숫자를 출력하는 코드를 작성하세요.
```


```python
for i in range(6):
    if i % 2 == 0:
        continue
        # continue 이후의 코드는 실행되지 않습니다.
    print(f'{i}는 홀수다.')
```

    1는 홀수다.
    3는 홀수다.
    5는 홀수다.
    

### [연습] `continue` 문 작성하기

> 나이가 입력된 리스트가 있을때,
> 조건문과 반복문, `continue`문을 활용하여 20살 이상일때만 "성인입니다"라는 출력을 하는 코드를 작성하세요.

---

**[출력 예시]**

23 살은 성인입니다.

30 살은 성인입니다.

25 살은 성인입니다.

31 살은 성인입니다.


```python
ages = [10, 23, 8, 30, 25, 31]

# 아래에 코드를 작성하세요.
```


```python
for i in ages:
    
    if i <20:
        continue
    print(f'{i}살은 성인입니다.')
```

    23살은 성인입니다.
    30살은 성인입니다.
    25살은 성인입니다.
    31살은 성인입니다.
    

### `pass` 
아무것도 하지 않습니다.
* 들여쓰기 이후 문장이 필요하지만, 프로그램이 특별히 할 일이 없을 때 자리를 채우는 용도로 사용할 수 있습니다.

`pass` 와 `continue` 차이


```python
# pass
# 0부터 4의 범위를 순회하며 출력하는 반복문 안에서
# 3이 나오는 경우 pass 하는 조건문을 작성해봅시다.

```


```python
# 아래에 코드를 작성하세요.
for i in range(0,5):
    print(i)
    if i==3:
        pass
    
```

    0
    1
    2
    3
    4
    


```python
# continue
# 0부터 4의 범위를 순회하며 출력하는 반복문 안에서 
# 3이 나오는 경우 continue 하는 조건문을 작성해봅시다.

```


```python
# 아래에 코드을 작성하세요.
for i in range(0,5):
    
    if i==3:
        continue
    print(i)
```

    0
    1
    2
    4
    

### `else`

끝까지 반복문을 실행한 이후에 실행됩니다.
- 반복문이 **`break` 문으로 종료될 때는 실행되지 않습니다.** (즉, `break`를 통해 중간에 종료되지 않은 경우만 실행)


```python
# break가 동작하지 않는 상황을 확인해봅시다.
# 'apple' 이라는 문자열을 순회하면서
# 'b'가 있으면 'b!'를 출력한 후 break에 의해 순회를 종료하고,
# 문자열 끝까지 순회해도 'b'가 없는 경우에는 'b가 없습니다.'를 출력하는 코드를 작성하세요.
```


```python
# 아래에 코드를 작성하세요.
ch='apple'
cnt=0

for i in ch:
    if i == 'b':
        print('b!')
        break
    
    elif i != 'b':
        cnt+=1
        if cnt==len(ch):
            print('문자열을 끝까지 순회해도 b가 없습니다')
            
    
        

```

    문자열을 끝까지 순회해도 b가 없습니다
    


```python
# break가 동작하는 상황을 확인해봅시다.
# 'banana' 라는 문자열을 순회하면서
# 'b'가 있으면 'b!'를 출력한 후 break에 의해 순회를 종료하고,
# 문자열 끝까지 순회해도 'b'가 없는 경우에는 'b가 없습니다.'를 출력하는 코드를 작성하세요.
```


```python
# 아래에 코드를 작성하세요.

```

### [연습] `for-else` 활용하기

> 조건문과 반복문, break, else 를 통해서 아래의 코드와 동일한 코드를 작성하세요.
* numbers 리스트에 4가 있을 경우 `True`를 출력하고, 없을 경우 `False`를 출력한다.

---

**[출력 예시]**

`False`



```python
numbers = [1, 4, 7, 9]

# 아래에 코드를 작성하세요.
```


```python
cnt = 0

for i in numbers:
    if int(i) == 4:
        cnt+=1
    else:
        pass
    
if cnt != 0:
    print(True)
else:
    print(False)
```

    True
    
