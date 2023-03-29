package main

func fibonacci(n int) int {
    var fib1, fib2, cnt int = 1, 0, 0;

    for i := 0; i < n; i++ {
        cnt++;
        if cnt % 2 == 0 {
            fib2 = fib1 + fib2;
        } else {
            fib1 = fib1 + fib2;
        }
    }

    if fib1 > fib2 {
        return fib1;
    } else {
        return fib2;
    }
}