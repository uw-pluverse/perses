





#![feature(no_core, lang_items)]
#![no_core]

#[lang="sized"]
trait Sized { }
#[lang="freeze"]
trait Freeze { }
#[lang="copy"]
trait Copy { }

#[repr(C)]
pub struct Bool {
    b: bool,
}


#[no_mangle]
pub extern "C" fn structbool() -> Bool {
    Bool { b: true }
}
