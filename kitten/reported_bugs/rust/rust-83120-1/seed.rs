





#![warn(indirect_structural_match)]


struct NoDerive(i32);


impl PartialEq for NoDerive { fn eq(&self, _: &Self) -> bool { false } }

impl Eq for NoDerive { }

#[derive(PartialEq, Eq)]
struct WrapInline(NoDerive);

const WRAP_INDIRECT_INLINE: & &WrapInline = & &WrapInline(NoDerive(0));

fn main() {
    match WRAP_INDIRECT_INLINE {
        WRAP_INDIRECT_INLINE => { panic!("WRAP_INDIRECT_INLINE matched itself"); }


        _ => { println!("WRAP_INDIRECT_INLINE did not match itself"); }
    }
}
