fn main ( ) {
static NONE : Option < ( AsRef < OsStr > , & 'static u8 ) > = None ;
let ptr = unsafe {
* ( & NONE as * const _ as * const * const u8 )
} ;
assert ! ( ptr . is_null ( ) ) ;
}
