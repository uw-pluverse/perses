
#![feature(type_alias_impl_trait)]

pub trait Bar {
    type E: Copy;

    fn foo<T>() -> Self::E;
}

impl<S: Default> Bar for S {
    type E = impl Copy;



    fn foo<T: Default>() -> Self::E {


        (S::default(), T::default())
    }
}

fn main() {}
