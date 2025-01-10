var BUGNUMBER = new Date ( 20000000 , 0 , 1 ) ;
var summary = 'Do not crash converting string to number' ;
var actual = 'No Crash' ;
var expect = 'No Crash' ;
printBugNumber ( BUGNUMBER ) ;
printStatus ( summary ) ;
printStatus ( 'This test only runs in the browser' ) ;
if ( typeof clearTimeout === 'function' )
{
try
{
clearTimeout ( 'foo' ) ;
}
catch ( ex )
{
}
}
reportCompare ( expect , actual , summary ) ;
