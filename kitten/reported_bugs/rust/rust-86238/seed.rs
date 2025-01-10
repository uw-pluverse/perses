







#![feature(no_core, lang_items, rustc_attrs, repr_simd)]
#![crate_type = "rlib"]
#![no_core]
#![allow(asm_sub_register, non_camel_case_types)]

#[rustc_builtin_macro]
macro_rules! asm {
    () => {};
}
#[rustc_builtin_macro]
macro_rules! concat {
    () => {};
}
#[rustc_builtin_macro]
macro_rules! stringify {
    () => {};
}

#[lang = "sized"]
trait Sized {}
#[lang = "copy"]
trait Copy {}

type ptr = *mut u8;

#[repr(simd)]
pub struct i8x16(i8, i8, i8, i8, i8, i8, i8, i8, i8, i8, i8, i8, i8, i8, i8, i8);
#[repr(simd)]
pub struct i16x8(i16, i16, i16, i16, i16, i16, i16, i16);
#[repr(simd)]
pub struct i32x4(i32, i32, i32, i32);
#[repr(simd)]
pub struct i64x2(i64, i64);
#[repr(simd)]
pub struct f32x4(f32, f32, f32, f32);
#[repr(simd)]
pub struct f64x2(f64, f64);

#[repr(simd)]
pub struct i8x32(
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
);
#[repr(simd)]
pub struct i16x16(i16, i16, i16, i16, i16, i16, i16, i16, i16, i16, i16, i16, i16, i16, i16, i16);
#[repr(simd)]
pub struct i32x8(i32, i32, i32, i32, i32, i32, i32, i32);
#[repr(simd)]
pub struct i64x4(i64, i64, i64, i64);
#[repr(simd)]
pub struct f32x8(f32, f32, f32, f32, f32, f32, f32, f32);
#[repr(simd)]
pub struct f64x4(f64, f64, f64, f64);

#[repr(simd)]
pub struct i8x64(
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
    i8,
);
#[repr(simd)]
pub struct i16x32(
    i16,
    i16,
    i16,
    i16,
    i16,
    i16,
    i16,
    i16,
    i16,
    i16,
    i16,
    i16,
    i16,
    i16,
    i16,
    i16,
    i16,
    i16,
    i16,
    i16,
    i16,
    i16,
    i16,
    i16,
    i16,
    i16,
    i16,
    i16,
    i16,
    i16,
    i16,
    i16,
);
#[repr(simd)]
pub struct i32x16(i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32);
#[repr(simd)]
pub struct i64x8(i64, i64, i64, i64, i64, i64, i64, i64);
#[repr(simd)]
pub struct f32x16(f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32);
#[repr(simd)]
pub struct f64x8(f64, f64, f64, f64, f64, f64, f64, f64);

impl Copy for i8 {}
impl Copy for i16 {}
impl Copy for i32 {}
impl Copy for f32 {}
impl Copy for i64 {}
impl Copy for f64 {}
impl Copy for ptr {}
impl Copy for i8x16 {}
impl Copy for i16x8 {}
impl Copy for i32x4 {}
impl Copy for i64x2 {}
impl Copy for f32x4 {}
impl Copy for f64x2 {}
impl Copy for i8x32 {}
impl Copy for i16x16 {}
impl Copy for i32x8 {}
impl Copy for i64x4 {}
impl Copy for f32x8 {}
impl Copy for f64x4 {}
impl Copy for i8x64 {}
impl Copy for i16x32 {}
impl Copy for i32x16 {}
impl Copy for i64x8 {}
impl Copy for f32x16 {}
impl Copy for f64x8 {}

extern "C" {
    fn extern_func();
    static extern_static: u8;
}





#[no_mangle]
pub unsafe fn sym_fn() {
    asm!("call {}", sym extern_func);
}





#[no_mangle]
pub unsafe fn sym_static() {
    asm!("mov al, byte ptr [{}]", sym extern_static);
}

macro_rules! check {
    ($func:ident $ty:ident $class:ident $mov:literal) => {
        #[no_mangle]
        pub unsafe fn $func(x: $ty) -> $ty {

            extern "Rust" {
                fn dont_merge(s: &str);
            }
            dont_merge(stringify!($func));

            let y;
            asm!(concat!($mov, " {}, {}"), lateout($class) y, in($class) x);
            y
        }
    };
}

macro_rules! check_reg {
    ($func:ident $ty:ident $reg:tt $mov:literal) => {
        #[no_mangle]
        pub unsafe fn $func(x: $ty) -> $ty {

            extern "Rust" {
                fn dont_merge(s: &str);
            }
            dont_merge(stringify!($func));

            let y;
            asm!(concat!($mov, " ", $reg, ", ", $reg), lateout($reg) y, in($reg) x);
            y
        }
    };
}






check!(reg_i16 i16 reg "mov");






check!(reg_i32 i32 reg "mov");






check!(reg_f32 f32 reg "mov");





#[cfg(x86_64)]
check!(reg_i64 i64 reg "mov");





#[cfg(x86_64)]
check!(reg_f64 f64 reg "mov");






check!(reg_ptr ptr reg "mov");






check!(reg_abcd_i16 i16 reg_abcd "mov");






check!(reg_abcd_i32 i32 reg_abcd "mov");






check!(reg_abcd_f32 f32 reg_abcd "mov");





#[cfg(x86_64)]
check!(reg_abcd_i64 i64 reg_abcd "mov");





#[cfg(x86_64)]
check!(reg_abcd_f64 f64 reg_abcd "mov");






check!(reg_abcd_ptr ptr reg_abcd "mov");





check!(reg_byte i8 reg_byte "mov");





check!(xmm_reg_i32 i32 xmm_reg "movaps");





check!(xmm_reg_f32 f32 xmm_reg "movaps");





check!(xmm_reg_i64 i64 xmm_reg "movaps");





check!(xmm_reg_f64 f64 xmm_reg "movaps");





check!(xmm_reg_ptr ptr xmm_reg "movaps");





check!(xmm_reg_i8x16 i8x16 xmm_reg "movaps");





check!(xmm_reg_i16x8 i16x8 xmm_reg "movaps");





check!(xmm_reg_i32x4 i32x4 xmm_reg "movaps");





check!(xmm_reg_i64x2 i64x2 xmm_reg "movaps");





check!(xmm_reg_f32x4 f32x4 xmm_reg "movaps");





check!(xmm_reg_f64x2 f64x2 xmm_reg "movaps");





check!(ymm_reg_i32 i32 ymm_reg "vmovaps");





check!(ymm_reg_f32 f32 ymm_reg "vmovaps");





check!(ymm_reg_i64 i64 ymm_reg "vmovaps");





check!(ymm_reg_f64 f64 ymm_reg "vmovaps");





check!(ymm_reg_ptr ptr ymm_reg "vmovaps");





check!(ymm_reg_i8x16 i8x16 ymm_reg "vmovaps");





check!(ymm_reg_i16x8 i16x8 ymm_reg "vmovaps");





check!(ymm_reg_i32x4 i32x4 ymm_reg "vmovaps");





check!(ymm_reg_i64x2 i64x2 ymm_reg "vmovaps");





check!(ymm_reg_f32x4 f32x4 ymm_reg "vmovaps");





check!(ymm_reg_f64x2 f64x2 ymm_reg "vmovaps");





check!(ymm_reg_i8x32 i8x32 ymm_reg "vmovaps");





check!(ymm_reg_i16x16 i16x16 ymm_reg "vmovaps");





check!(ymm_reg_i32x8 i32x8 ymm_reg "vmovaps");





check!(ymm_reg_i64x4 i64x4 ymm_reg "vmovaps");





check!(ymm_reg_f32x8 f32x8 ymm_reg "vmovaps");





check!(ymm_reg_f64x4 f64x4 ymm_reg "vmovaps");





check!(zmm_reg_i32 i32 zmm_reg "vmovaps");





check!(zmm_reg_f32 f32 zmm_reg "vmovaps");





check!(zmm_reg_i64 i64 zmm_reg "vmovaps");





check!(zmm_reg_f64 f64 zmm_reg "vmovaps");





check!(zmm_reg_ptr ptr zmm_reg "vmovaps");





check!(zmm_reg_i8x16 i8x16 zmm_reg "vmovaps");





check!(zmm_reg_i16x8 i16x8 zmm_reg "vmovaps");





check!(zmm_reg_i32x4 i32x4 zmm_reg "vmovaps");





check!(zmm_reg_i64x2 i64x2 zmm_reg "vmovaps");





check!(zmm_reg_f32x4 f32x4 zmm_reg "vmovaps");





check!(zmm_reg_f64x2 f64x2 zmm_reg "vmovaps");





check!(zmm_reg_i8x32 i8x32 zmm_reg "vmovaps");





check!(zmm_reg_i16x16 i16x16 zmm_reg "vmovaps");





check!(zmm_reg_i32x8 i32x8 zmm_reg "vmovaps");





check!(zmm_reg_i64x4 i64x4 zmm_reg "vmovaps");





check!(zmm_reg_f32x8 f32x8 zmm_reg "vmovaps");





check!(zmm_reg_f64x4 f64x4 zmm_reg "vmovaps");





check!(zmm_reg_i8x64 i8x64 zmm_reg "vmovaps");





check!(zmm_reg_i16x32 i16x32 zmm_reg "vmovaps");





check!(zmm_reg_i32x16 i32x16 zmm_reg "vmovaps");





check!(zmm_reg_i64x8 i64x8 zmm_reg "vmovaps");





check!(zmm_reg_f32x16 f32x16 zmm_reg "vmovaps");





check!(zmm_reg_f64x8 f64x8 zmm_reg "vmovaps");





check!(kreg_i8 i8 kreg "kmovb");





check!(kreg_i16 i16 kreg "kmovw");





check!(kreg_i32 i32 kreg "kmovd");





check!(kreg_i64 i64 kreg "kmovq");





check!(kreg_ptr ptr kreg "kmovq");





check_reg!(eax_i16 i16 "eax" "mov");





check_reg!(eax_i32 i32 "eax" "mov");





check_reg!(eax_f32 f32 "eax" "mov");





#[cfg(x86_64)]
check_reg!(eax_i64 i64 "eax" "mov");





#[cfg(x86_64)]
check_reg!(eax_f64 f64 "eax" "mov");





check_reg!(eax_ptr ptr "eax" "mov");





check_reg!(ah_byte i8 "ah" "mov");





check_reg!(xmm0_i32 i32 "xmm0" "movaps");





check_reg!(xmm0_f32 f32 "xmm0" "movaps");





check_reg!(xmm0_i64 i64 "xmm0" "movaps");





check_reg!(xmm0_f64 f64 "xmm0" "movaps");





check_reg!(xmm0_ptr ptr "xmm0" "movaps");





check_reg!(xmm0_i8x16 i8x16 "xmm0" "movaps");





check_reg!(xmm0_i16x8 i16x8 "xmm0" "movaps");





check_reg!(xmm0_i32x4 i32x4 "xmm0" "movaps");





check_reg!(xmm0_i64x2 i64x2 "xmm0" "movaps");





check_reg!(xmm0_f32x4 f32x4 "xmm0" "movaps");





check_reg!(xmm0_f64x2 f64x2 "xmm0" "movaps");





check_reg!(ymm0_i32 i32 "ymm0" "vmovaps");





check_reg!(ymm0_f32 f32 "ymm0" "vmovaps");





check_reg!(ymm0_i64 i64 "ymm0" "vmovaps");





check_reg!(ymm0_f64 f64 "ymm0" "vmovaps");





check_reg!(ymm0_ptr ptr "ymm0" "vmovaps");





check_reg!(ymm0_i8x16 i8x16 "ymm0" "vmovaps");





check_reg!(ymm0_i16x8 i16x8 "ymm0" "vmovaps");





check_reg!(ymm0_i32x4 i32x4 "ymm0" "vmovaps");





check_reg!(ymm0_i64x2 i64x2 "ymm0" "vmovaps");





check_reg!(ymm0_f32x4 f32x4 "ymm0" "vmovaps");





check_reg!(ymm0_f64x2 f64x2 "ymm0" "vmovaps");





check_reg!(ymm0_i8x32 i8x32 "ymm0" "vmovaps");





check_reg!(ymm0_i16x16 i16x16 "ymm0" "vmovaps");





check_reg!(ymm0_i32x8 i32x8 "ymm0" "vmovaps");





check_reg!(ymm0_i64x4 i64x4 "ymm0" "vmovaps");





check_reg!(ymm0_f32x8 f32x8 "ymm0" "vmovaps");





check_reg!(ymm0_f64x4 f64x4 "ymm0" "vmovaps");





check_reg!(zmm0_i32 i32 "zmm0" "vmovaps");





check_reg!(zmm0_f32 f32 "zmm0" "vmovaps");





check_reg!(zmm0_i64 i64 "zmm0" "vmovaps");





check_reg!(zmm0_f64 f64 "zmm0" "vmovaps");





check_reg!(zmm0_ptr ptr "zmm0" "vmovaps");





check_reg!(zmm0_i8x16 i8x16 "zmm0" "vmovaps");





check_reg!(zmm0_i16x8 i16x8 "zmm0" "vmovaps");





check_reg!(zmm0_i32x4 i32x4 "zmm0" "vmovaps");





check_reg!(zmm0_i64x2 i64x2 "zmm0" "vmovaps");





check_reg!(zmm0_f32x4 f32x4 "zmm0" "vmovaps");





check_reg!(zmm0_f64x2 f64x2 "zmm0" "vmovaps");





check_reg!(zmm0_i8x32 i8x32 "zmm0" "vmovaps");





check_reg!(zmm0_i16x16 i16x16 "zmm0" "vmovaps");





check_reg!(zmm0_i32x8 i32x8 "zmm0" "vmovaps");





check_reg!(zmm0_i64x4 i64x4 "zmm0" "vmovaps");





check_reg!(zmm0_f32x8 f32x8 "zmm0" "vmovaps");





check_reg!(zmm0_f64x4 f64x4 "zmm0" "vmovaps");





check_reg!(zmm0_i8x64 i8x64 "zmm0" "vmovaps");





check_reg!(zmm0_i16x32 i16x32 "zmm0" "vmovaps");





check_reg!(zmm0_i32x16 i32x16 "zmm0" "vmovaps");





check_reg!(zmm0_i64x8 i64x8 "zmm0" "vmovaps");





check_reg!(zmm0_f32x16 f32x16 "zmm0" "vmovaps");





check_reg!(zmm0_f64x8 f64x8 "zmm0" "vmovaps");





check_reg!(k1_i8 i8 "k1" "kmovb");





check_reg!(k1_i16 i16 "k1" "kmovw");





check_reg!(k1_i32 i32 "k1" "kmovd");





check_reg!(k1_i64 i64 "k1" "kmovq");





check_reg!(k1_ptr ptr "k1" "kmovq");
