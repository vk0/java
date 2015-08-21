package main

import "fmt"

var x string = "Hello XY"

func main() {
	//var x string = "Hello World"
	fmt.Println(x)
	x = "first "
	fmt.Println(x)
	x = x + "second"
	fmt.Println(x)
	var xx string = "hello"
	var y string = "world"
	fmt.Println(xx == y)
	xxx := "Hello XXX"
	fmt.Println(xxx)
	xy := 5
	fmt.Println(xy)
	dogsName := "Max"
	fmt.Println("My dog's name is", dogsName)
	const x1 string = "Hello World"
	fmt.Println(x1)

	fmt.Print("Enter a number: ")
	var input float64
	fmt.Scanf("%f", &input)
	output := input * 2
	fmt.Println(output)

	fal := 100
	cal := ((fal - 32) * 5 / 9)
	fmt.Println(fal, "Fal in Celc is", cal)
}

func f() {
	fmt.Println(x)
}
