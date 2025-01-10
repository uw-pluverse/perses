core::panic!();
macro_rules! define_other_core {
    ( ) => {
        extern crate std as core;
    };
}
define_other_core!();
