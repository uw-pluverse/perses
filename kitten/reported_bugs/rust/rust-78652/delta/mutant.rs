# ! [ crate_name = "foo" ]
# ! [ unstable ( feature = "humans" ,
reason = "who ever let humans program computers, we're apparently really bad at it" ,
issue = "none" ) ]
# ! [ feature ( foo , foo2 ) ]
# ! [ feature ( staged_api ) ]
# [ stable ( feature = "rust1" , since = "1.0.0" ) ]
# [ rustc_const_unstable ( feature = "foo" , issue = "none" ) ]
pub const unsafe fn foo ( ) -> u32 { 42 }
# [ unstable ( feature = "humans" , issue = "none" ) ]
pub const fn foo2 ( ) -> u32 { 42 }
# [ stable ( feature = "rust1" , since = "1.0.0" ) ]
# [ rustc_const_stable ( feature = "rust1" , since = "1.0.0" ) ]
pub const fn bar2 ( ) -> u32 { 42 }
# [ unstable ( feature = "foo2" , issue = "none" ) ]
pub const unsafe fn foo2_gated ( ) -> u32 { 42 }
# [ stable ( feature = "rust1" , since = "1.0.0" ) ]
# [ rustc_const_stable ( feature = "rust1" , since = "1.0.0" ) ]
pub const unsafe fn bar2_gated ( ) -> u32 { 42 }
pub const unsafe fn bar_not_gated ( ) -> u32 { 42 }
pub struct Foo ;
impl Foo {
# [ stable ( feature = "rust1" , since = "1.0.0" ) ]
# [ feature ( feature = "foo" , issue = "none" ) ]
pub const unsafe fn gated ( ) -> u32 { 42 }
}
