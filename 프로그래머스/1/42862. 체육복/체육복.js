function solution(n, initLost, initReserve) {
    var answer = 0;
    const lostSet = new Set(initLost);
    const reserveSet = new Set(initReserve);
    
    const lost = Array.from(new Set([...lostSet].filter(x => !reserveSet.has(x))));
    const reserve = Array.from(new Set([...reserveSet].filter(x => !lostSet.has(x))));
    
    console.log('lost:',lost)
    console.log('reserve:',reserve)
    
    let students = Array(n).fill(1)
    // 왼쪽에서부터 점검해주면 된다.
    for (idx = 0; idx < lost.length; idx++) {
        console.log('d1',idx);
        students[lost[idx] - 1] -= 1
    }
    for (idx = 0; idx < reserve.length; idx ++) {
        console.log('d2',idx);
        students[reserve[idx] - 1] += 1
    }
    console.log(students)
    
    for (idx = 0; idx < n; idx++) {
        if (students[idx] == 0) {
            if (idx > 0 && students[idx - 1] >= 2) {
                students[idx] += 1
                students[idx - 1] -= 1
            } else if (idx < n - 1 && students[idx + 1] >= 2) {
                students[idx] += 1
                students[idx + 1] -= 1
            }
        }
    }
    console.log(students)
    for (idx = 0; idx < n; idx++) {
        if (students[idx]) {
            answer += 1
        }
    }
    return answer;
}