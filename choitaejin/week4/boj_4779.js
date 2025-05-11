const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

function cantor(arr, start, length, depth) {
  if (depth === 0) {
    return;
  }
  
  const segment = Math.floor(length / 3);
  
  for (let i = start + segment; i < start + 2 * segment; i++) {
    arr[i] = ' ';
  }
  
  cantor(arr, start, segment, depth - 1);
  
  cantor(arr, start + 2 * segment, segment, depth - 1);
}

const inputs = [];

rl.on('line', (line) => {
  if (line === '') {
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