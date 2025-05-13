const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let n, k;
let lineCnt = 0;
let arr = [];
let sortCnt = 0;
let res = -1;

function mergeSort(arr, p, r) {
    if (p < r) {
        const q = Math.floor((p + r) / 2);
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

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
    if (lineCnt === 0) {
        const inputs = line.split(' ');
        n = parseInt(inputs[0]);
        k = parseInt(inputs[1]);
        lineCnt++;
    }
    else if (lineCnt === 1) {
        arr = line.split(' ').map(num => parseInt(num));
        rl.close(); 
    }
}).on('close', () => {
    mergeSort(arr, 0, arr.length - 1);
    console.log(res);
    
    process.exit();
});