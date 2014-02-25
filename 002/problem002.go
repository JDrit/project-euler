package main

import "fmt"

func fib_gen() func() int {
    x, y := 0, 1
    return func() int {
        x, y = y, y + x
        return x + y
    }
}

func main() {
    f := fib_gen()
    sum := 0
    for {
        n := f()
        if n >= 4000000 {
            break
        } else if n % 2 == 0 {
            sum += n
        }
    }
    fmt.Println(sum)
}
