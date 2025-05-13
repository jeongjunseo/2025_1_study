const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input;

rl.on('line', (line) => {
    input = line;
    rl.close();
}).on('close', () => {
    
    function Fibo(n) {
        if (n == 0) {
            return 0;
        }
        else if (n == 1) {
            return 1;
        }
        else {
            return Fibo(n-1) + Fibo(n-2);
        }        
    }

    console.log(Fibo(parseInt(input)));
    process.exit();
});