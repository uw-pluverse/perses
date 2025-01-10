static X: i32 = 1;
const C: i32 = 2;
static mut M: i32 = 3;

const CR: &'static mut i32 = &mut C;

static STATIC_REF: &'static mut i32 = &mut X;


static CONST_REF: &'static mut i32 = &mut C;

static STATIC_MUT_REF: &'static mut i32 = unsafe { &mut M };
fn main() {}
