mod Y {
    pub type X = usize;
    extern {
        pub static x: *const usize;
    }
    pub fn foo(value: *const X) -> *const X {
        value
    }
}

static foo: *const Y::X = Y::foo(Y::x as *const Y::X);




fn main() {}
