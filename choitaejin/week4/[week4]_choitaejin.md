## 📌 [week4] choitaejin

[수학, 구현] [10870] 문제풀이
[구현, 정렬, 재귀] [24060] 문제풀이
[분할 정복, 재귀] [4779] 문제 풀이

---

## ✅ 해결한 문제
- [ ] 문제 1 피보나치 수 5 (https://www.acmicpc.net/problem/10870)
- [ ] 문제 2 알고리즘 수업 - 병합 정렬 1 (https://www.acmicpc.net/problem/24060)
- [ ] 문제 3 칸토어 집합 (https://www.acmicpc.net/problem/4779)
- [ ] 문제 4 제목 (문제 링크)

---

## 💡 문제 해결 방법 및 핵심 로직
### - 문제 1: 10870번
  - 해결 방법:
    - 문제에서 제공하는 피보나치 수열을 그대로 코드로 구현하면 된다.
  - 핵심 로직:
    - n >= 2라는 조건이 있으니 if문으로 n == 0일때, n == 1일때 다르게 처리해주면 된다.
    - input은 int자료형이 아니므로 parseInt를 통해 형변환을 해줘야한다.

```javascript
let input;

rl.on('line', (line) => {
    input = line;
    rl.close();
}).on('close', () => {
    
    // 피보나치 수열 함수
    function Fibo(n) {
        if (n == 0) {
            return 0;
        }
        else if (n == 1) {
            return 1;
        }
        else {
            return Fibo(n-1) + Fibo(n-2);
        }        
    }

    // input은 int자료형이 아니므로 parseInt를 통해 형변환 해주기
    console.log(Fibo(parseInt(input)));
    process.exit();
});
```

### - 문제 2: 24060번
  - 해결 방법:
    - 문제에서 주어진 pseudo code를 javascript로 작성하면 된다.
  - 핵심 로직:
    - 반 씩 나눌 때 부동 소수점 문제를 방지하기 위해 그냥 `p+r / 2` 하면 안되고 `Math.floor((p+r)/2)`로 해주어야한다.
    - 메모리 효율성을 위해 `[]`가 아닌 `new Array`로 배열 생성하기

```javascript
let n, k;
let lineCnt = 0;
let arr = [];
let sortCnt = 0;
let res = -1; // 결과 값 (k번째 값)

function mergeSort(arr, p, r) {
    if (p < r) {
        const q = Math.floor((p + r) / 2); // mid point 계산
        mergeSort(arr, p, q); // mid point 기준으로 왼쪽 절반 mergeSort
        mergeSort(arr, q + 1, r); // 오른쪽 절반 mergeSort
        merge(arr, p, q, r); // 정렬된 두 배열 merge
    }
}

// 정렬된 배열을 하나로 합치는 merge 함수
function merge(arr, p, q, r) {
    let i = p;
    let j = q + 1;
    let t = 0;
    const temp = new Array(r - p + 1);

    while (i <= q && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[t++] = arr[i++];
        }
        else {
            temp[t++] = arr[j++];
        }
    }

    while (i <= q) { 
        temp[t++] = arr[i++];
    }
    
    while (j <= r) { 
        temp[t++] = arr[j++];
    }

    i = p;
    t = 0;
    while (i <= r) {
        sortCnt++;
        if (sortCnt === k) {
            res = temp[t];
        }
        arr[i++] = temp[t++]; 
    }
}

rl.on('line', (line) => {
    if (lineCnt === 0) { // 첫 번째 줄 입력 (n, k)
        const inputs = line.split(' ');
        n = parseInt(inputs[0]);
        k = parseInt(inputs[1]);
        lineCnt++;
    }
    else if (lineCnt === 1) { // 두 번째 줄 입력 (array)
        arr = line.split(' ').map(num => parseInt(num));
        rl.close(); 
    }
}).on('close', () => {
    mergeSort(arr, 0, arr.length - 1);
    console.log(res);
    
    process.exit();
});
```

### - 문제 3: 4779번
  - 해결 방법:
    - 3^n 개의 '-'로 구성된 배열을 생성하고 3등분 하여 가운데 지점을 ' '으로 변경
    - 분할된 배열이 '-'만 남을 때 까지 재귀 호출?
  - 핵심 로직:
    - '-' 만 남을 때 까지가 아니라 더 이상 분할하지 못할 때 까지 반복을 진행해야한다.

```javascript
// 칸토어 함수
function cantor(arr, start, length, depth) {
  if (depth === 0) { // 깊이가 0이면 == 더 이상 분할이 안되면 종료
    return;
  }
  
  // 3등분 계산
  const segment = Math.floor(length / 3);
  
  // 3등분 된 가운데 구간을 공백으로 변경
  for (let i = start + segment; i < start + 2 * segment; i++) {
    arr[i] = ' ';
  }
  
  // 왼쪽에 다시 재귀 호출
  cantor(arr, start, segment, depth - 1);
  
  // 오른쪽에 다시 재귀 호출
  cantor(arr, start + 2 * segment, segment, depth - 1);
}

const inputs = [];

rl.on('line', (line) => {
  if (line === '') { // 비어있는 입력 시 종료
    rl.close();
    return;
  }
  
  inputs.push(parseInt(line));
}).on('close', () => {
  inputs.forEach(n => {
    const length = Math.pow(3, n);
    const arr = new Array(length).fill('-');
    
    cantor(arr, 0, length, n);
    
    console.log(arr.join(''));
  });
  
  process.exit();
});
```
---

## ✨ 기타 참고 사항
- 예제 입력/출력과 실행 결과 : 

- 고민했던 부분이나 어려웠던 점 :
  - 4779번: 따로 입력 종료가 없어서 무한 반복으로 계속 해야하나 고민했지만 빈 줄이 입력되면 입력 종료 시키면 되었다.
  - 4779번: 3^n을 진행할 때 Math.pow로 진행하면 되는데 **, ^ 찾으면서 잘 안되서 해메었다.
  - 4779번: 재귀 호출에서 무한 재귀 발생, depth를 감소 시키지 않는 문제가 있었다.

- 추가로 개선할 사항 : 평소에 자주 사용하지 않는 함수와 메서드를 또 까먹었다. 다시 읽어봐야 할 듯