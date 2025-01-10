#![feature(rustc_attrs)]
#![allow(dead_code)]
#![allow(feature         )]
#![rustc_if_this_changed(hir_crate)]
fn main() {}
struct Foo<T> {
    f: T,
}
type TypeAlias<T> = Foo<T>;
#[rustc_then_this_would_need(variances_of)]
struct Use<T> {
    x: TypeAlias<T>,
}
