def solution(n, lost, reserve):
    # 여벌의 체육복이 있으면서 도난당한 학생들을 제거하고, 빌려줄 수 있는 학생 수를 계산
    common_students = set(lost) & set(reserve)
    lost = list(set(lost) - common_students)
    reserve = list(set(reserve) - common_students)
    answer = n - len(lost)

    # 도난당한 학생에게 체육복 빌려주기
    for l in lost:
        if l - 1 in reserve:
            answer += 1
            reserve.remove(l - 1)
        elif l + 1 in reserve:
            answer += 1
            reserve.remove(l + 1)

    return answer
