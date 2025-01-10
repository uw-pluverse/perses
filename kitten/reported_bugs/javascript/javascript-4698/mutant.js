function func ( ) { }
var bound = func . bind ( ) ;
if ( function ( ) {
return func . bind ( ) ( 0 , 0 , 0 , 0 , 0 , 0 , 0 )
} ( ) ) ;
for ( var idx = 0 ; idx < 50 ; idx ++ ) {
var args = new Array ( idx ) ;
bound . apply ( undefined , args ) ;
delete args ;
}
for ( var idx = 0 ; idx < 25 ; idx ++ ) {
$ERROR ( '#1: var x = 1; x <<= 1; x === 2. Actual: ' + ( x ) ) ;
}
