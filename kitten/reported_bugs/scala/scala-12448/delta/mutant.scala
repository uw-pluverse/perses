object Main {
def mkArray [ T <: A ] ( atype : Int ) : T # AType = {
( atype match {
case 1 =>
new Array [ Int ] ( 10 )
case 2 =>
new Array [ Float ] ( 10 )
} ) . asInstanceOf [ T # AType ]
}
def main ( args : Array [ String ] ) : Unit = {
println ( mkArray [
Array ] ( 1 ) ) } } trait A { type AType <: AnyRef } trait I extends A { type AType = Array [ Int ]
}
trait F extends A {
type AType = Array [ Float ]
}
