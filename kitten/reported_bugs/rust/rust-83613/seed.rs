

#![feature(type_alias_impl_trait)]

trait OpaqueTrait {}
impl<T> OpaqueTrait for T {}
type OpaqueType = impl OpaqueTrait;
fn mk_opaque() -> OpaqueType {
    ()
}

#[derive(Debug)]
struct D<T>(T);

trait AnotherTrait {}
impl<T: Send> AnotherTrait for T {}




impl AnotherTrait for D<OpaqueType> {

}

fn main() {}
