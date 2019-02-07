package main

import (
	"fmt"
	"time"
)

const total uint64 = 45

var arr [total]uint64

func fib(n uint64) uint64 {
	if n <= 1 {
		return 1
	}

	if arr[n-1] != 0 && arr[n-2] != 0 {

		return (arr[n-1] + arr[n-2])
	} else {

		return (fib(n-1) + fib(n-2))
	}

}
func main() {

	start := time.Now()
	var i uint64
	for i = 0; i < total; i++ {
		arr[i] = fib(i)
		fmt.Printf("%d => %d\n", i, arr[i])

	}

	elapsed := time.Since(start)
	fmt.Printf("Execution time  ⏲  => %s\n", elapsed)
}
