const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

class Node {
  constructor(item) {
    this.item = item;
    this.prev = null;
    this.next = null;
  }
}

class Deque {
  constructor() {
    this.head = null;
    this.tail = null;
    this.size = 0;
  }

  getSize() {
    return this.size;
  }

  isEmpty() {
    return this.size === 0 ? 1 : 0;
  }

  pushFront(item) {
    const node = new Node(item);
    
    if (this.isEmpty()) {
      this.head = node;
      this.tail = node;
    } else {
      node.next = this.head;
      this.head.prev = node;
      this.head = node;
    }
    
    this.size++;
  }

  pushBack(item) {
    const node = new Node(item);
    
    if (this.isEmpty()) {
      this.head = node;
      this.tail = node;
    } else {
      this.tail.next = node;
      node.prev = this.tail;
      this.tail = node;
    }
    
    this.size++;
  }

  popFront() {
    if (this.isEmpty()) {
      return -1;
    }
    
    const item = this.head.item;
    
    if (this.size === 1) {
      this.head = null;
      this.tail = null;
    } else {
      this.head = this.head.next;
      this.head.prev = null;
    }
    
    this.size--;
    return item;
  }

  popBack() {
    if (this.isEmpty()) {
      return -1;
    }
    
    const item = this.tail.item;
    
    if (this.size === 1) {
      this.head = null;
      this.tail = null;
    } else {
      this.tail = this.tail.prev;
      this.tail.next = null;
    }
    
    this.size--;
    return item;
  }

  front() {
    if (this.isEmpty()) {
      return -1;
    }
    return this.head.item;
  }

  back() {
    if (this.isEmpty()) {
      return -1;
    }
    return this.tail.item;
  }
}

let input = [];
let lineCnt = 0;
let n = 0;
const deque = new Deque();
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
    const cmd = parseInt(parts[0]);

    switch (cmd) {
      case 1:
        deque.pushFront(parseInt(parts[1]));
        break;
      case 2:
        deque.pushBack(parseInt(parts[1]));
        break;
      case 3:
        res.push(deque.popFront());
        break;
      case 4:
        res.push(deque.popBack());
        break;
      case 5:
        res.push(deque.getSize());
        break;
      case 6:
        res.push(deque.isEmpty());
        break;
      case 7:
        res.push(deque.front());
        break;
      case 8:
        res.push(deque.back());
        break;
      default:
        break;
    }
  }

  console.log(res.join('\n'));
  process.exit();
});