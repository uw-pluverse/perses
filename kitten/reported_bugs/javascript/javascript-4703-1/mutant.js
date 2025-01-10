let i = - 1 << 1 ;
Object . defineProperty ( a , "length" , {
get : function ( ) {
return 6 ;
}
} ) ;
delete a . __proto__ . __proto__ [ Symbol . iterator ] ;
Float64Array . from ( a ) ;
