package main

import (
	"bufio"
	"encoding/csv"
	"fmt"
	"io/ioutil"
	"os"
	"strings"
)

func main() {

	content, err := ioutil.ReadFile("masterTest.xml")
	if err != nil {
		//Do something
	}

	lines := strings.Split(string(content), "\n")

	fileCSV, err := os.Open("test.csv")
	if err != nil {
		panic(err)
	}
	defer fileCSV.Close()

	reader := csv.NewReader(bufio.NewReader(fileCSV))
	reader.FieldsPerRecord = 3
	reader.Comment = '#'
	record, err := reader.Read()
	if err != nil {
		panic(err)
	}

	fmt.Println(record, len(record))
	fmt.Println(lines)
	fmt.Printf("%s", lines)

	// for _, str := range lines {
	// 	fmt.Println(str)
	// }

	// path := "hello.xml"
	// var fileFINAL, err2 = os.OpenFile(path, os.O_RDWR, 0644)
	// if err2 != nil {
	// 	panic(err2)
	// }

}

// func CompileRECDESC(str string, fContent string) string {
// 	m := regexp.MustCompile("<recipeDescription>.+?</recipeDescription>")
// 	line21 := "<recipeDescription>"
// 	line22 := "</recipeDescription>"
// 	slice := []string{line21, str, line22}
// 	res := m.ReplaceAllString(string(fContent), strings.Join(slice, ""))
// 	return res
// }

// серийник \d{14}
// строка может иметь вид тэг>14цифр<тэг или тэг>чтототам-чтототам-14цифр<тэг

// описание всегда имеет тэг "<materialDescription>" или "<recipeDescription>"

// объём кеги всегда имеет тэг <detail name="kegVolume">20</detail>
