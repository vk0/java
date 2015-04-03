package main

import (
	"fmt"
	"log"
	"os"
	"path/filepath"
)

var bigDigits = [][]string{
	{" 000 ", " 0 0 ", "0 0", "0 0", "0 0", " 0 0 ", " 000 "},
	{" 1 ", "11 ", " 1 ", " 1 ", " 1 ", " 1 ", "111"},
	{" 222 ", "2 2", " 2 ", " 2 ", " 2 ", "2 ", "22222"},
	// ... с 3 по 8 ...
	{" 9999", "9 9", "9 9", " 9999", " 9", " 9", " 9"},
}

func main() {
	if len(os.Args) == 1 {
		fmt.Printf("usage: %s <whole-number>\n", filepath.Base(os.Args[0]))
		os.Exit(1)
	}
	stringOfDigits := os.Args[1]
	for row := range bigDigits[0] {
		line := ""
		for column := range stringOfDigits {
			digit := stringOfDigits[column] - '0'
			if 0 <= digit && digit <= 9 {
				line += bigDigits[digit][row] + " "
			} else {
				log.Fatal("invalid whole number")
			}
		}
		fmt.Println(line)
	}
}
