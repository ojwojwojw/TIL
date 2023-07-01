//for each
// const arr = [1,2,3,4];
// const newArr = [];

// arr.forEach( (elm) =>{
//   newArr.push(elm*2);
// })

// console.log(newArr)


//map
// const arr = [1,2,3,4]
// const newArr = arr.map((elm)=>{
//   return elm * 2;
// })

// console.log(newArr)


//인덱스 혹은 요소 찾기
// const arr = [
//   { color: "red"},
//   { color: "black"},
//   { color: "blue"},
//   { color: "green"}
// ];


// console.log(arr.findIndex((elm)=>{
//   return elm.color === "red"
//   })
// )


// const element = arr.find((elm)=>{
//   return elm.color === "red"
//   })

// console.log(element)



//필터, 자르기
// const arr = [
//   { num:1, color: "red"},
//   { num:2, color: "black"},
//   { num:3, color: "blue"},
//   { num:4, color: "green"}
// ];

// console.log(arr.filter((elm)=>elm.num === 1))
// console.log(arr.slice(0,3)) 



//배열 정렬하기
// let numbers = [0,1,2,10,30,20]

// const compare = (a,b) => {
//   if (a>b){
//     return 1
//   } 
//   if (a<b){
//     return -1
//   }

//   return 0
// }

// numbers.sort(compare)
// console.log(numbers)



//조인
// const arr = ["오정원","님","안녕하세요","또오셨네요"]
// console.log(arr.join(" "))
