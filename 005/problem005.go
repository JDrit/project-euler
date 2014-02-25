package main

import "fmt"

func main() {
    n := 20
    for {
        if n % 11 == 0 &&
            n % 12 == 0 &&
            n % 13 == 0 &&
            n % 14 == 0 &&
            n % 15 == 0 &&
            n % 16 == 0 &&
            n % 17 == 0 &&
            n % 18 == 0 &&
            n % 19 == 0 && 
            n % 20 == 0 {
            fmt.Println(n)
            break
        }
        n += 20
    }

}
