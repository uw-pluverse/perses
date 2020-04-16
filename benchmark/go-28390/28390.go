package main

import (
	"fmt"
)

type A struct {
	K int
	S string
	M map[string]string
}

func newA(k int, s string) (a A) {
	a.K = k
	a.S = s
	a.M = make(map[string]string)
	a.M[s] = s
	return
}

func proxy() (x int, a A) {
	return 1, newA(2, "3")
}

func consume(x int, a interface{}) {
	fmt.Println(x)
	fmt.Println(a)
}

func main() {
	consume(proxy())
}
