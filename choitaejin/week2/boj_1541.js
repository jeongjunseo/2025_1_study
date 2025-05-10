const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input;
let arr = [];

rl.on('line', (line) => {
  input = line;
  arr = input.split("-");
  rl.close();
}).on('close', () => {
  // +를 제거해주면서 숫자형 배열로 변환
  const number = arr.map((str) =>
    str.split('+').map((num) => Number(num))
  );

  // 괄호로 묶인 부분들 계산
  const sums = number.map((nums) =>
    nums.reduce((acc, curr) => acc + curr, 0)
  );
  
  let res = sums[0]; // res초기화
  for (let i = 1; i < sums.length; i++) {
    res -= sums[i]; // 두 번째 부분부터 마지막 부분까지 돌면서 결과값에서 각 부분의 합을 뺌
  }

  console.log(res);
  process.exit();
});
