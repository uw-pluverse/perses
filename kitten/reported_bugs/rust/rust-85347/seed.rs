#![allow(incomplete_features)]
#![feature(generic_associated_types)]



use std::ops::Deref;

trait Foo {
    type Bar<'a, 'b>;
}

trait Baz {
    type Quux<'a>: Foo where Self: 'a;


    type Baa<'a>: Deref<Target = <Self::Quux<'a> as Foo>::Bar<'a, 'static>>  where Self: 'a;
}

impl<T> Baz for T where T: Foo {
    type Quux<'a> where T: 'a = T;

    type Baa<'a> where T: 'a = &'a <T as Foo>::Bar<'a, 'static>;
}

fn main() {}
