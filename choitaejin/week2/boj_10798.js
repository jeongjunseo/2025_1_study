const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];
let lineCnt = 0;
let res = "";

rl.on('line', (line) => {
  input.push(line);
  lineCnt++;

  if (lineCnt === 5) {
    rl.close(); // 5줄 입력 받으면 입력 닫기
  }
}).on('close', () => {
  const maxLength = Math.max(...input.map((str) => str.length)); // 15까지 전부 다 체크할 수 없으니 가장 긴 배열값 체크

  for (let i = 0; i < maxLength; i++) { // 문자열 배열에서 [i][j]는 i번째 배열요소의 j번째 글자이다.
    for (let j = 0; j < 5; j++) {
      if (input[j][i]) { // 값이 존재하면 결과 배열에 넣어주기기
        res += input[j][i];
      }
    }
  }
  console.log(res);
  process.exit();
});