pragma  experimental SMTChecker ;
abstract contract A {
bool s ;
function f ( ) public view mod { assembly {
let d := 0x10
function asmfun ( a , b , c ) -> x , y , z {
x := g ( a )
function g ( r ) -> s {
s := mul ( r , r )
}
y := g ( b )
z := 7
}
let a1 , b1 , c1 := asmfun ( 1 , 2 , 3 )
mstore ( 0x00 , a1 )
mstore ( 0x20 , b1 )
mstore ( 0x40 , c1 )
mstore ( 0x60 , d )
return ( 0 , 0x80 )
}
}
modifier mod ( ) virtual ;
}
contract B is A {
modifier mod ( ) virtual override {
s = false ;
_ ;
}
}
contract C is B {
modifier mod ( ) override {
s = true ;
_ ;
}
}
