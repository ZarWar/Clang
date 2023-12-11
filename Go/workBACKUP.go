package main

import (
	"bufio"
	"encoding/csv"
	"fmt"
	"io/ioutil"
	"os"
	"regexp"
	"strings"
)

func main() {

	fContent, err := ioutil.ReadFile("master.xml")
	if err != nil {
		panic(err)
	}

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

	path := "hello.xml"
	var fileFINAL, err2 = os.OpenFile(path, os.O_RDWR, 0644)
	if err2 != nil {
		panic(err2)
	}

	str := record[0]
	res := CompileNTIN(str, fContent)
	str = record[1]
	res2 := CompileMATDESC(str, res)
	res3 := CompileRECDESC(str, res2)
	str = record[2]
	res4 := CompileRECDESC(str, res3)

	// m := regexp.MustCompile("[0-9]{14}")
	// res := m.ReplaceAllString(string(fContent), str)

	// line11 := "<materialDescription>"
	// line12 := "</materialDescription>"
	// line21 := "<recipeDescription>"
	// line22 := "</recipeDescription>"
	// line31 := "<detail name=\"kegVolume\">"
	// line32 := "</detail>"

	// m = regexp.MustCompile("<materialDescription>.+?</materialDescription>")
	// str = record[1]
	// slice := []string{line11, str, line12}
	// res = m.ReplaceAllString(string(fContent), strings.Join(slice, ""))

	// m = regexp.MustCompile("<recipeDescription>.+?</recipeDescription>")
	// slice = []string{line21, str, line22}
	// res = m.ReplaceAllString(string(fContent), strings.Join(slice, ""))

	// m = regexp.MustCompile("<detail name=\"kegVolume\">.+?</detail>")
	// str = record[2]
	// slice = []string{line31, str, line32}
	// res = m.ReplaceAllString(string(fContent), strings.Join(slice, ""))

	fileFINAL.WriteString(string(res4))

	fmt.Printf("First:\n\n%s\n\n", res4)
}

func CompileNTIN(str string, fContent []byte) string {
	m := regexp.MustCompile("[0-9]{14}")
	res := m.ReplaceAllString(string(fContent), str)
	return res
}

func CompileMATDESC(str string, fContent string) string {
	m := regexp.MustCompile("<materialDescription>.+?</materialDescription>")
	line11 := "<materialDescription>"
	line12 := "</materialDescription>"
	slice := []string{line11, str, line12}
	res := m.ReplaceAllString(string(fContent), strings.Join(slice, ""))
	return res
}

func CompileRECDESC(str string, fContent string) string {
	m := regexp.MustCompile("<recipeDescription>.+?</recipeDescription>")
	line21 := "<recipeDescription>"
	line22 := "</recipeDescription>"
	slice := []string{line21, str, line22}
	res := m.ReplaceAllString(string(fContent), strings.Join(slice, ""))
	return res
}

func CompileKEGVOL(str string, fContent string) string {
	m := regexp.MustCompile("<detail name=\"kegVolume\".+?</detail>")
	line31 := "<detail name=\"kegVolume\">"
	line32 := "</detail>"
	slice := []string{line31, str, line32}
	res := m.ReplaceAllString(string(fContent), strings.Join(slice, ""))
	return res
}

// серийник \d{14}
// строка может иметь вид тэг>14цифр<тэг или тэг>чтототам-чтототам-14цифр<тэг

// описание всегда имеет тэг "<materialDescription>" или "<recipeDescription>"

// объём кеги всегда имеет тэг <detail name="kegVolume">20</detail>
