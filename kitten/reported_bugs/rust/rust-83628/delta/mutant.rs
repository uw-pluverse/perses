# ! [ feature ( no_core , lang_items ) ]
# ! [ no_core ]
# [ lang = "sized" ]
trait Sized { } fn main ( ) {
if let ( 0 , 1 ) | ( 0 , 2 ) | ( 0 , 3 ) = ( 0 , 0 ) { }
}
# [ lang = "copy" ]
trait Copy { }
# [ repr ( C ) ]
pub struct Bool {
b : bool ,
}
# [ no_mangle ]
pub extern "C" fn structbool ( ) -> Bool {
Bool { b : true }
}
