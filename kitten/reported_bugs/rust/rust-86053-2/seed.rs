





struct Invariant<'a> {
    f: &'a mut &'a isize
}

fn use_<'short,'long>(c: Invariant<'long>,
                      s: &'short isize,
                      l: &'long isize,
                      _where:Option<&'short &'long ()>) {





    let _: Invariant<'short> = c;
}

fn main() { }
