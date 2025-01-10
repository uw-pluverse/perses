#![feature(no_core, lang_items)]
#![no_core]
#[lang = "sized"]
trait Sized {}
#[lang = "copy"]
trait Copy {}
#[no_mangle]
fn test() {
    &1;
}
