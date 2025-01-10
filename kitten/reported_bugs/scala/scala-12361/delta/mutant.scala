object Test extends App {
def foo [ U ] ( x : U ) : Unit = macro Impls . foo [ U ] += "-source:3.0-migration"
}
