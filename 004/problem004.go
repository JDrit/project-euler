package main

import (
    "fmt"
    "strconv"
)

func isPalindromic(num int) bool {
    str := strconv.Itoa(num)
    for i := 0 ; i < len(str) ; i++ {
        if str[i] != str[len(str) - 1- i] {
            return false
        }
    }
    return true
}

func main() {
    best := 0
    for i := 999 ; i > 0 ; i-- {
        for j := 999 ; j > 0 ; j-- {
            if i * j > best && isPalindromic(i * j) {
                best = i * j;
            }
        }
    }
    fmt.Println(best)
}
