package main

import "fmt"

func main() {
    var a, b int;

    fmt.Println(divide(a, b));
}

func divide (a int, b int) (int, error) {
    _, err := fmt.Scan(&a, &b) // функция Scan возвращает два параметра, но нам сейчас важно проверить только ошибку
	if err != nil {
		return 0, err;
	} else {
		return (a / b), err;
	}
}