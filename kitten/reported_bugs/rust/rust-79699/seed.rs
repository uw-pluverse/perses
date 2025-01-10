


#![feature(rustc_attrs)]



#[rustc_variance]
struct Test2<'a, 'b, 'c> {
    x: &'a isize,
    y: &'b [isize],
    c: &'c str
}



#[rustc_variance]
struct Test3<'a, 'b, 'c> {
    x: extern "Rust" fn(&'a isize),
    y: extern "Rust" fn(&'b [isize]),
    c: extern "Rust" fn(&'c str),
}



#[rustc_variance]
struct Test4<'a, 'b:'a> {
    x: &'a mut &'b isize,
}




#[rustc_variance]
struct Test5<'a, 'b:'a> {
    x: extern "Rust" fn(&'a mut &'b isize),
}






#[rustc_variance]
struct Test6<'a, 'b:'a> {
    x: &'a mut extern "Rust" fn(&'b isize),
}



#[rustc_variance]
struct Test7<'a> {
    x: isize
}



#[rustc_variance]
enum Test8<'a, 'b, 'c:'b> {
    Test8A(extern "Rust" fn(&'a isize)),
    Test8B(&'b [isize]),
    Test8C(&'b mut &'c str),
}

fn main() {}
