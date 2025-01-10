
#![feature(cmse_nonsecure_entry)]

#[no_mangle]
#[cmse_nonsecure_entry]
pub extern "C" fn entry_function(input: u32) -> u32 {
    input + 6
}

fn main() {}
