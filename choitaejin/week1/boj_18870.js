const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];
let lineCnt = 0;
let n;
let arr = [];
let res = [];

rl.on('line', (line) => {
  input.push(line);
  lineCnt++;

  if (lineCnt === 1) {
    n = Number(line);
  } else if (lineCnt === 2) {
    arr = line.split(' ').map(Number);
    rl.close();
  }
}).on('close', () => {
  const sortedArr = [...new Set(arr)].sort((a, b) => a - b);
  const resMap = new Map();

  sortedArr.forEach((num, index) => {
    resMap.set(num, index);
  });

  res = arr.map((num) => resMap.get(num));

  console.log(res.join(' '));

  process.exit();
});