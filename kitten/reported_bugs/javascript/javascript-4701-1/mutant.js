( function ( ) {
var res = 0 ;
var step = 4 ;
for ( var i = 0x7fffffff | 0 ; i >= ( 1 << step ) ; i -= ( i >> step ) ) {
var x = i ^ ( i << 1 ) ;
res += ( ( ( x + x ) + res + res ) | 0 ) ;
}
return res ;
} ) ( )
