# ! [ crate_type = "lib" ]
# ! [ feature ( no_core , lang_items , abi_efiapi ) ]
# ! [ no_core ]
# [ lang = "sized" ]
trait Sized { }
# [ lang = "freeze" ]
trait Freeze { }
# [ lang = "copy" ]
trait Copy { }
# [ no_mangle ]
pub extern "efiapi" fn has_efiapi ( ) {
if let 0 = 1 { }
}
