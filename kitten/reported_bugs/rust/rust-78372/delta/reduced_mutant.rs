use std::ops::DispatchFromDyn;
struct Smaht<T, MISC>(PhantomData);
impl<T> DispatchFromDyn<Smaht<U, MISC>> for T {}
trait Foo: X<u32> {}
trait X<T> {
    fn foo(self: Smaht<Self, T>);
}
trait Marker {}
impl Marker for Foo {}
