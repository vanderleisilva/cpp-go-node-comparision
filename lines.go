package main

import (
	"fmt"
	"os"
	"strconv"
	"time"
)

func factorial(n int) int {
	if n == 0 || n == 1 {
		return 1
	} else {
		return n * factorial(n-1)
	}
}

func createFileWithLines(lines int, fileName string) error {
	startTime := time.Now()

	file, err := os.Create(fileName)
	if err != nil {
		return err
	}
	defer file.Close()

	for i := 1; i <= lines; i++ {
		line := fmt.Sprintf("factorial of %d is %d\n", i, factorial(i))
		// line := fmt.Sprintf("line %d\n", i)
		_, err := file.WriteString(line)
		if err != nil {
			return err
		}
	}

	duration := time.Since(startTime)
	fmt.Printf("File %s created successfully with %d lines.\n", fileName, lines)
	fmt.Printf("Time taken: %d milliseconds\n", duration.Milliseconds())

	return nil
}

func main() {
	if len(os.Args) < 3 {
		fmt.Println("Usage: go run main.go <lines> <fileName>")
		return
	}

	lines, err := strconv.Atoi(os.Args[1])
	if err != nil {
		fmt.Println("Invalid lines argument:", err)
		return
	}

	fileName := os.Args[2]

	err = createFileWithLines(lines, fileName)
	if err != nil {
		fmt.Println("Error creating file:", err)
		return
	}
}
