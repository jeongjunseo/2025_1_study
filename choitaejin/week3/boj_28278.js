const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

class Stack {
  constructor() {
    this.items = [];
  }

  push(item) {
    this.items.push(item);
  }

  pop() {
    if (this.isEmpty()) {
      return -1;
    }
    return this.items.pop();
  }

  isEmpty() {
    return this.items.length === 0;
  }

  getSize() {
    return this.items.length;
  }

  peek() {
    if (this.isEmpty()) {
      return -1;
    }
    return this.items[this.items.length - 1];
  }
}

let input = [];
let lineCnt = 0;
let n = 0;
const stack = new Stack();
let res = [];

rl.on('line', (line) => {
  if (lineCnt === 0) {
    n = parseInt(line);
    lineCnt++;
  } else {
    input.push(line);
    lineCnt++;
  }

  if (lineCnt > n) {
    rl.close();
  }
}).on('close', () => {
  for (let i = 0; i < n; i++) {
    const parts = input[i].split(' ');
    const cmd = parts[0];

    switch (cmd) {
      case '1':
        stack.push(parseInt(parts[1]));
        break;
      case '2':
        res.push(stack.pop());
        break;
      case '3':
        res.push(stack.getSize());
        break;
      case '4':
        res.push(stack.isEmpty() ? 1 : 0);
        break;
      case '5':
        res.push(stack.peek());
        break;
    default:
        break;
    }
  }
  console.log(res.join('\n'));
  process.exit();
});