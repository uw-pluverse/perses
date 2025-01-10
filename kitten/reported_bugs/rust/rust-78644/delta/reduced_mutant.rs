#![no_core]
#[lang = "sized"]
trait Sized {}
#[lang = "deref"]
trait Deref {}
fn test() {
    epriv()
}
