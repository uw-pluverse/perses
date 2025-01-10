




#![crate_type = "rlib"]
#![feature(thread_local)]



#[no_mangle]
#[thread_local]
static mut STATIC_VAR_1: [u32; 8] = [0; 8];


#[no_mangle]
#[thread_local]
static mut STATIC_VAR_2: [u32; 8] = [4; 8];

#[no_mangle]
pub unsafe fn f(x: &mut [u32; 8]) {
    std::mem::swap(x, &mut STATIC_VAR_1)
}

#[no_mangle]
pub unsafe fn g(x: &mut [u32; 8]) {
    std::mem::swap(x, &mut STATIC_VAR_2)
}
