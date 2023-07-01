const cookie = {
  base : "cookie" ,
  madeIn : "kroea"
}


const chocochipCookie = {
  ...cookie ,
  toping :  "chocochip"
}

console.log(chocochipCookie)


//


const A  = [1,2]
const B = [3,4,5,6]

const C = [...A , 123 ,...B]
console.log(C)