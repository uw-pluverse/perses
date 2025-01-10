function f ( ) {
var x = ( ( "-1.234" << 0 ) ) ;
var y = 3.14 ;
assertEq ( true && x < y , true ) ;
}
f ( ) ;
