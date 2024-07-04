function isPrime(number) {
    if (number < 2) return false;
    for (let i = 2; i <= Math.sqrt(number); i++) {
        if (number % i === 0) return false;
    }
    return true;
}

function printPrimesContinuously() {
    let number = 2;
    while (true) {
        if (isPrime(number)) {
            console.log(number);
        }
        number++;
    }
}

printPrimesContinuously();