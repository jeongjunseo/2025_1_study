## 📌 [week2] choitaejin

[수학, 그리디 알고리즘, 문자열, 파싱][1541] 문제풀이
[구현, 문자열][10798] 문제풀이
[자료 구조, 문자열, 정렬, 해시를 사용한 집합과 맵] [1764] 문제 풀이

---

## ✅ 해결한 문제
- [ ] 문제 1 잃어버린 괄호 (https://www.acmicpc.net/problem/1541)
- [ ] 문제 2 세로읽기 (https://www.acmicpc.net/problem/10798)
- [ ] 문제 3 듣보잡 (https://www.acmicpc.net/problem/1764)
- [ ] 문제 4 제목 (문제 링크)

---

## 💡 문제 해결 방법 및 핵심 로직
### - 문제 1: 1541번
  - 해결 방법: '-'를 기준으로 묶어서 분할해주고 묶인 부분들 합계산 후 [0]번째 합에서 나머지를 빼면 됨, (뭔가 설명하기 어려움)
  - 핵심 로직: [0]의 합에서 나머지 부분의 합을 모두 빼서 최소값을 계산
```javascript
const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input;
let arr = [];

rl.on('line', (line) => {
  input = line;
  arr = input.split("-"); // 먼저 '-'를 기준으로 분할하여 배열에 저장
  rl.close();
}).on('close', () => {
  // +를 제거해주면서 숫자형 배열로 변환
  const number = arr.map((str) =>
    str.split('+').map((num) => Number(num))
  );
  console.log(number);

  // 괄호로 묶인 부분들 계산
  const sums = number.map((nums) =>
    nums.reduce((acc, curr) => acc + curr, 0)
  );
  console.log(sums);

  let res = sums[0]; // res초기화
  for (let i = 1; i < sums.length; i++) {
    res -= sums[i]; // 두 번째 부분부터 마지막 부분까지 돌면서 결과값에서 각 부분의 합을 뺌
  }

  console.log(res);
  process.exit();
});
```

### - 문제 2: 10798번
  - 해결 방법: 각 문자열의 n번째를 모아서 하나의 문자열로 만든 후 출력해주기
  - 핵심 로직: 문자열 배열에서 str[i][j]은 i번째 요소의 j번째 요소이다. -> i를 고정하고 j만 for문으로 돌려서 새로운 결과 배열에 넣고 출력해주면 된다!

```javascript
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
    rl.close();
  }
}).on('close', () => {
  const maxLength = Math.max(...input.map((str) => str.length));

  for (let i = 0; i < maxLength; i++) {
    for (let j = 0; j < 5; j++) {
      if (input[j][i]) {
        res += input[j][i];
      }
    }
  }
  console.log(res);
  process.exit();
});
```

### - 문제 3: 1764번
  - 해결 방법: 두 배열을 입력받고, 교집합 찾아내서, 교집합 배열의 길이와 교집합 배열 요소를 사전순으로 출력해주기
  - 핵심 로직: for문으로 두 배열을 비교하면 시간초과가 발생하여, Set구조로 하나의 배열을 변경해준다.

```javascript
const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

// 입력 관련
let input = [];
let lineCnt = 0;

let N, K; // N: 듣도 못한 사람, K: 보도 못한 사람
let NotListen = new Set(); // array가 아닌 Set() 사용, 듣도못한사람
let NotSee = []; // 보도 못한사람
let res =[]; // 교집합 배열

rl.on('line', (line) => {
    input.push(line);
    lineCnt++;

    if (lineCnt === 1) {  // 첫 번쨰 입력값 처리
        [N, K] = line.split(' ').map(Number);
    } else if (lineCnt >= 2 && lineCnt <= N + 1) { // 듣도 못한사람 입력 받기
        NotListen.add(line);
    } else if (lineCnt > N + 1 && lineCnt <= N + K + 1) { // 보도 못한사람 입력 받기
        NotSee.push(line);
    }

    if (lineCnt === N + K + 1) { // 모든 입력이 종료되면 rl을 close하여 입력을 그만 받음
        rl.close();
    }
}).on('close', () => {

    for (let name of NotSee) { // NotSee에 있는 배열 요소와 NotListen에 있는 배열 요소 비교
        if (NotListen.has(name)) { 
            res.push(name); // 값이 일치하다면 결과 배열에 push해줌
        }
    }
    
    res.sort(); // 출력 조건에 맞게 결과 배열을 정렬
    console.log(res.length); // 조건에 결과 배열의 크기 먼저 출력
    for (let i = 0; i < res.length; i++) {
      console.log(res[i]); // 결과 배열 요소 하나씩 출력
    }
    process.exit();
});
```

---

## ✨ 기타 참고 사항
- 예제 입력/출력과 실행 결과 : 굳굳

- 고민했던 부분이나 어려웠던 점 : 
  - reduce()를 몰라서 1541푸는데 너무 오래걸림
  - 2차원 배열이 JS에서는 명시적으론 존재하지 않아 10798번 풀 때 살짝 막혔다. -> 문자열 배열의 특징을 알게됨
  - has매서드를 사용해서 객체에 해당 값이 존재하는지 찾으면 매우 빠르게 찾을 수 있다....저번에 썼는데 까먹어서 for문으로 돌리다가 시간초과나옴

- 추가로 개선할 사항 : 아직 Set과 Map 등등 JS에서 제공하는 함수나 메서드에에 익숙하지 않아서 문제를 처음 풀 때는 사용하지 않아 비효율적으로 코드가 늘었다. 여러 함수나 메서드, 객체를 사용할 수 있다는 것을 생각하며 모르는 함수나 메서드는 velog에 계속 정리해야할듯..