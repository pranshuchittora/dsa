package main

import "fmt"

func display(arr []int, n int) {

	for _, elm := range arr {
		fmt.Printf("%d ", elm)
	}
	fmt.Printf("\n")

}
func main() {
	const n int = 8
	var arr = []int{7, 4, 5, 3, 2, 8, 1, 6}
	for i := 1; i < n; i++ {
		key := arr[i]
		j := i - 1
		for j >= 0 && arr[j] > key {

			arr[j+1] = arr[j]
			arr[j] = key
			j--
		}
		display(arr, n)

	}
}
