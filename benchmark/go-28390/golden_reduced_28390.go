package main;

import (
 "fmt";
);

type A struct {
 K int;


};

func newA(k int, s string) (a A) {
 a.K = k;



 return;
};

func proxy() (x int, a A) {
 return 1, newA(2, "3");
};

func consume(x int, a interface{}) {

 fmt.Println(a);
};

func main() {
 consume(proxy());
};
