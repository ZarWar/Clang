package main

import (
	"fmt"
)

func funReturnFun() func() int {
	i := 0
	return func() int {
		fmt.Println("i =", i)
		i++
		fmt.Println("i =", i)
		return i * i
	}
}

func main() {
	// i := funReturnFun(2)
	j := funReturnFun()

	// fmt.Println("1:", i())
	// fmt.Println("2:", i())
	fmt.Println("j1:", j())
	fmt.Println("j2:", j())
	fmt.Println("j3:", j())
	fmt.Println("j4:", j())
	fmt.Println("j5:", j())
	fmt.Println("j6:", j())
	// fmt.Println("3:", i())
}
