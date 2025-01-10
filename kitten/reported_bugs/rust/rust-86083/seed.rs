



#![feature(nll)]

fn doit(data: &'static mut ()) {
    || doit(data);


}

fn main() { }
