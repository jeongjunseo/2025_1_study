## 📌 [week2] choitaejin

[자료 구조, 스택] [28278] 문제풀이
[자료 구조, 큐] [18258] 문제풀이
[자료 구조, 덱] [28279] 문제 풀이

---

## ✅ 해결한 문제
- [ ] 문제 1 스택 2 (https://www.acmicpc.net/problem/28278)
- [ ] 문제 2 큐 2 (https://www.acmicpc.net/problem/18258)
- [ ] 문제 3 덱 2 (https://www.acmicpc.net/problem/28279)
- [ ] 문제 4 제목 (문제 링크)

---

## 💡 문제 해결 방법 및 핵심 로직
### - 문제 1: 28278번
  - 해결 방법:
    - JavaScript에서 제공하는 `push()`와 `pop()`함수를 사용해서 스택을 구현합니다.
    - 각 명령어마다 `console.log()`로 결과값을 출력해주면 시간 복잡도 측면에서 비효율적이므로 결과를 저장하는 배열을 생성해서 해당 배열에 저장 후 마지막에 `console.log(res.join('\n'));` 로 한번에 결과값을 문제 조건에 맞게 출력해줍니다.
    - 또한 같은 이유로 `if ~ else if`문으로 입력값을 검사하기 보단 `switch ~ case`문으로 검사합니다.
  - 핵심 로직:
    - 문제 조건에 맞는 method 작성하기
    - 입력값 검사는 switch ~ case로 진행하기

```javascript
// 배열 기반 스택 class
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
    // 비어있으면 true, 비어있지 않으면 false를 return해줌
    return this.items.length === 0;
  }

  size() {
    return this.items.length;
  }

  peek() {
    if (this.isEmpty()) {
      return -1;
    }
    return this.items[this.items.length - 1];
  }
}

// 중간 생략

// 입력된 data 처리
for (let i = 0; i < n; i++) {
  // push인 경우 input배열에서 공백으로 구분된 숫자 체크를 위해 parts와 cmd로 나눔
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
        res.push(stack.size());
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
```

### - 문제 2: 18258번
  - 해결 방법:
    - `shift()`라는 배열의 첫 번째 요소를 출력해주는 함수가 존재하지만 이를 사용하면 배열 기반 큐가 되므로 시간 복잡도가 O(n)이 되어 문제의 조건에 부합하지 않음
    - node class를 생성해주고 일반 큐이기 때문에 signle-linked-list로 구현하면 된다.
  - 핵심 로직:
    - node class를 통해 큐를 single-linked-list로 구현
    - 문제 조건에 맞는 method 작성하기
    - 입력값 검사는 switch ~ case로 진행하기

```javascript
// 단일 연결 리스트르 위한 node
class Node {
  constructor(item) {
    this.item = item;
    this.next = null;
  }
}

// 단일 연결 리스트 기반의 큐 class
class Queue {
  constructor() {
    // 큐의 시작과 끝을 가리키는 index 및 전체 size
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
      // 배열이 비어있는 경우 (this.isEmpty()로 조건 체크해도 될듯)
      this.head = node;
      this.tail = node;
    }
    else {
      // 배열에 item이 존재하는 경우 tail의 next를 새로운 node로 연결 후 tail을 새로운 node로 설정
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

    // 큐는 FIFO니까 out할 item을 미리 보관하고
    const item = this.head.item;
    // head를 기존 head의 next로 변경 후 size 감소
    this.head = this.head.next;
    this.size--;

    // 마지막 요소를 dequeue한 경우 tail을 null로 설정
    if (this.isEmpty()) {
      this.tail = null;
    }

    // 저장해둔 head item return해주기
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

// 중간 생략

// 입력받은 data처리
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
```

### - 문제 3: 28279번
  - 해결 방법:
    - 큐에서 node class에 prev를 추가해주고, enqueue와 dequeue를 양쪽에서 가능하게 만들어준다.
  - 핵심 로직:
    - 큐에서의 삽입/삭제를 세분화 하여 pushFront(), pushRear(), popFront(), popRear()로 만들어주면된다.
    - 삽입/삭제 진행 시 node의 next뿐만 아니라 prev도 고려해주기.

```javascript
// node class에 prev 추가
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

  // head로 push 진행하는 경우
  pushFront(item) {
    const node = new Node(item);
    
    // 덱이 비어있는 경우
    if (this.isEmpty()) {
      this.head = node;
      this.tail = node;
    }
    else {
      // 덱 요소가 존재하는 경우 push할 node의 next를 기존 head로 연결
      node.next = this.head;
      // 기존 head의 prev는 새로운 node와 연결 및 head를 새로운 node로 변경
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
      // 기존 tail의 next를 새로운 node로 설정 및 node의 prev를 기존 tail로 설정
      // tail을 새로운 node로 변경하기
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
      // head를 pop 해줄 예정이니 비어있는 head를 기존 head의 next로 변경
      this.head = this.head.next;
      // 새로운 head의 prev는 null로 설정
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
      // tail를 pop 해줄 예정이니 비어있는 tail를 기존 tail의 prev로 변경
      this.tail = this.tail.prev;
      // 새로운 tail의 next는 null로 설정
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

// 중간 생략

// 입력받은 data처리
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
```
---

## ✨ 기타 참고 사항
- 예제 입력/출력과 실행 결과 : 예제와 동일하게 입/출력 결과 나옴.

- 고민했던 부분이나 어려웠던 점 :
  - 처음에 시간 복잡도를 고려하지 않고 배열기반 구현에 `push()`, `shift()`와 같은 제공되는 함수를 사용하다가 시간 제한을 초과하였다.
  - 그래서 배열이 아닌 연결 리스트로 구현해야 겠다고 생각 후 코드를 수정하였다.

- 추가로 개선할 사항 : 문제 조건에서 주어지는 시간 제한과 메모리 제한을 조금 더 체크해보고 구현 전 제한을 초과할까? 라는 생각을 해야겠다.