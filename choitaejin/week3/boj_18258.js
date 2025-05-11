const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

class Node {
  constructor(item) {
    this.item = item;
    this.next = null;
  }
}

class Queue {
  constructor() {
    this.head = null;
    this.tail = null;
    this.size = 0;
  }

  getSize() {
    return this.size;
  }

  enqueue(item) {
    const node = new Node(item);

    if (!this.head) {
      this.head = node;
      this.tail = node;
    }
    else {
      this.tail.next = node;
      this.tail = node;
    }

    this.size++;
  }

  isEmpty() {
    return this.size === 0 ? 1 : 0;
  }

  dequeue() {
    if (this.isEmpty()) {
      return -1;
    }

    const item = this.head.item;
    this.head = this.head.next;
    this.size--;

    if (this.isEmpty()) {
      this.tail = null;
    }

    return item;
  }


  front() {
    if (this.isEmpty()) {
      return -1;
    }
    else {
      return this.head.item;
    }
  }

  back() {
    if (this.isEmpty()) {
      return -1;
    }
    else {
      return this.tail.item;
    }
  }

}

let input = [];
let lineCnt = 0;
let n = 0;
const queue = new Queue();
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
      case 'push':
        queue.enqueue(parts[1]);
        break;
      case 'pop':
        res.push(queue.dequeue());
        break;
      case 'size':
        res.push(queue.getSize());
        break;
      case 'empty':
        res.push(queue.isEmpty());
        break;
      case 'front':
        res.push(queue.front());
        break;
      case 'back':
        res.push(queue.back());
        break;
      default:
        break;
    }
  }

  console.log(res.join('\n'));
  process.exit();
});
