package main

import "fmt"

func main() {
	xs := []float64{98, 93, 77, 82, 83}
	// total := 0.0
	// for _, v := range xs {
	// 	total += v
	// }
	// fmt.Println(total / float64(len(xs)))
	fmt.Println(average(xs))
	fmt.Println(add(1, 2, 3))
	fmt.Println(factorial(20))
	defer second()
	// second()
	first()
	fmt.Println(fib(7))
	// panic("PANIC")
	// str := recover()
	// fmt.Println(str)
	// defer func() {
	// 	str := recover()
	// 	fmt.Println(str)
	// }()
	// panic("PANIC")

}
func factorial(x uint) uint {
	if x == 0 {
		return 1
	}

	return x * factorial(x-1)
}

func fib(x uint) uint {
	if x == 0 {
		return 0
	}
	if x == 1 {
		return 1
	}
	return fib(x-1) + fib(x-2)
}

func add(args ...int) int {
	total := 0
	for _, v := range args {
		total += v
	}
	return total
}

func average(xs []float64) float64 {
	total := 0.0
	for _, v := range xs {
		total += v
	}
	return total / float64(len(xs))
}

func first() {
	fmt.Println("1st")
}
func second() {
	fmt.Println("2nd")
}
