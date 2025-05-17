const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];
let N, K;
let lineCnt = 0;
let NotListen = new Set(); // 듣도 못한사람 배열
let NotSee = []; // 보도 못한사람 배열
let res =[]; // 듣보잡 결과 배열

rl.on('line', (line) => {
    input.push(line);
    lineCnt++;

    if (lineCnt === 1) {
        [N, K] = line.split(' ').map(Number);
    } else if (lineCnt >= 2 && lineCnt <= N + 1) {
        NotListen.add(line);
    } else if (lineCnt > N + 1 && lineCnt <= N + K + 1) {
        NotSee.push(line);
    }

    if (lineCnt === N + K + 1) {
        rl.close();
    }
}).on('close', () => {

    for (let name of NotSee) {
        if (NotListen.has(name)) {  // 보도못한 사람배열에서 듣도못한 사람과의 교집합을 결과 배열에 push해줌
            res.push(name);
        }
    }

    res.sort();
    console.log(res.length);
    for (let i = 0; i < res.length; i++) {
      console.log(res[i]);
    }
    process.exit();
});