const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];
let arr = [];

rl.on('line', (line) => {
    input.push(line);
    arr = line.split('').map(Number);
    rl.close();

}).on('close', () => {
    arr.sort((a,b) => b - a);
    const res = parseInt(arr.join(''));
    console.log(res);
    process.exit();
});