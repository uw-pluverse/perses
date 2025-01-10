



fn ordering4<'a, 'b, F>(a: &'a usize, b: &'b usize, x: F) where F: FnOnce(&'a &'b usize) {


    let z: Option<&'a &'b usize> = None;
}

fn main() {}
