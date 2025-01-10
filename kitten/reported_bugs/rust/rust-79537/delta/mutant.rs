# ! [ allow ( warnings ) ]
# ! [ feature ( rustc_attrs ) ]
# ! [ crate_type = "rlib" ]
# [ cfg ( cfail1 ) ]
pub fn change_closure_body ( ) {
let _ = || 1u32 ;
}
# [ cfg ( not ( cfail1 ) ) ]
# [ rustc_clean ( cfg = "cfail2" , except = "hir_owner_nodes" ) ]
# [ rustc_clean ( cfg = "cfail3" ) ]
pub fn change_closure_body ( ) {
let _ = || 3u32 ;
}
# [ cfg ( cfail1 ) ]
pub fn add_parameter ( ) {
let x = 0u32 ;
let _ = || x + 1 ;
}
# [ cfg ( not ( cfail1 ) ) ]
# [ rustc_clean ( cfg = "cfail2" , except = "hir_owner_nodes, optimized_mir, typeck" ) ]
# [ rustc_clean ( cfg = "cfail3" ) ]
pub fn add_parameter ( ) {
let x = 0u32 ;
let _ = | x : u32 | x + 1 ;
}
# [ cfg ( cfail1 ) ]
pub fn change_parameter_pattern ( ) {
let _ = | x : ( u32 , ) | x ;
}
# [ cfg ( not ( cfail1 ) ) ]
# [ rustc_clean ( cfg = "cfail2" , except = "hir_owner_nodes, typeck" ) ]
# [ rustc_clean ( cfg = "cfail3" ) ]
pub fn change_parameter_pattern ( ) {
let _ = | ( x , ) : ( x , ) | x ;
}
# [ cfg ( cfail1 ) ]
pub fn add_move ( ) {
let _ = || 1 ;
}
# [ cfg ( not ( cfail1 ) ) ]
# [ rustc_clean ( cfg = "cfail2" , except = "hir_owner_nodes" ) ]
# [ rustc_clean ( cfg = "cfail3" ) ]
pub fn add_move ( ) {
let _ = move || 1 ;
}
# [ cfg ( cfail1 ) ]
pub fn add_type_ascription_to_parameter ( ) {
let closure = | x | x + 1u32 ;
let _ : u32 = closure ( 1 ) ;
}
# [ cfg ( not ( cfail1 ) ) ]
# [ rustc_clean ( cfg = "cfail2" , except = "hir_owner_nodes, typeck" ) ]
# [ rustc_clean ( cfg = "cfail3" ) ]
pub fn add_type_ascription_to_parameter ( ) {
let closure = | x : u32 | x + 1u32 ;
let _ : u32 = closure ( 1 ) ;
}
# [ cfg ( cfail1 ) ]
pub fn change_parameter_type ( ) {
let closure = | x : u32 | ( x as u64 ) + 1 ;
let _ = closure ( 1 ) ;
}
# [ cfg ( not ( cfail1 ) ) ]
# [ rustc_clean ( cfg = "cfail2" , except = "hir_owner_nodes, optimized_mir, typeck" ) ]
# [ rustc_clean ( cfg = "cfail3" ) ]
pub fn change_parameter_type ( ) {
let closure = | x : u16 | ( x as u64 ) + 1 ;
let _ = closure ( 1 ) ;
}
