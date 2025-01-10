


#![crate_type = "lib"]
#![feature(lang_items)]
#![feature(no_core)]
#![no_core]

#[lang="sized"]
pub trait Sized {

}

#[lang = "add"]
trait Add<RHS=Self> {
    type Output;

    fn add(self, _: RHS) -> Self::Output;
}

fn ice<A>(a: A) {
    let r = loop {};
    r = r + a;

}
