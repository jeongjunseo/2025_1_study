const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];
let N, K;
let lineCnt = 0;
let score = [];

rl.on('line', (line) => {
  input.push(line);
  lineCnt++;

  if (lineCnt == 1) {
    [N, K] = line.split(' ').map(Number);
  }
  else if (lineCnt == 2) {
    score = line.split(' ').map(Number);
    rl.close();
  }


}).on('close', () => {
    score.sort((a,b) => b-a);
    console.log(score[K - 1]);
  process.exit();
});
