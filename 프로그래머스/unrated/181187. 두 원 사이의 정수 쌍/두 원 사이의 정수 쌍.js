function solution(r1, r2) {
    var answer = 0;
    let quarter_cnt = 0;
    let boundary_cnt = 0;
    let max = 0;
    let min = 0;
    
    for (let x = 0 ; x < r2 + 1 ; x++){
        if (x >= r1){
            max = Math.sqrt(r2*r2 - x*x)
            quarter_cnt += Math.floor(max) + 1
            boundary_cnt += 1
            // console.log(Math.floor(max) + 1)
        }
        else{
            max = Math.sqrt(r2*r2 - x*x)
            min = Math.sqrt(r1*r1 - x*x)
            quarter_cnt += Math.floor(max) - Math.ceil(min) + 1
            // console.log(Math.floor(max) - Math.ceil(min) + 1)
        }
    }
    answer = 4*quarter_cnt - 4*boundary_cnt
    return answer;
    
}