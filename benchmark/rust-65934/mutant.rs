// build: nightly-2019-10-29
// error: internal compiler error

trait Trait {
    type Assoc;
}

impl Trait for () {
    type Assoc = ();
}

trait Dummy<T> {}

impl<T> Dummy<T> for () {}

fn make<T: Trait>() -> impl Dummy<T::Assoc> {}

fn extract<T>(_: impl Dummy<T>) -> Option<T> {
    None
}

pub fn ice() {
    extract(make::<()>());
}

fn main() {
}
