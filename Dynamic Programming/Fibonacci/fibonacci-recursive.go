package main

import (
	"fmt"
	"time"
)

const total uint64 = 45

func fib(n uint64) uint64 {
	if n <= 1 {
		return 1
	}

	return (fib(n-1) + fib(n-2))

}
func main() {

	start := time.Now()
	var i uint64
	for i = 0; i < total; i++ {
		fmt.Printf("%d => %d\n", i, fib(i))

	}

	elapsed := time.Since(start)
	fmt.Printf("Execution time  ⏲  => %s\n", elapsed)
}
