extern "rust-intrinsic" fn f1 ( ) { }
extern "platform-intrinsic" fn f2 ( ) { }
extern "vectorcall" fn f3 ( ) { }
extern "rust-call" fn f4 ( ) { }
extern "msp430-interrupt" fn f5 ( ) { }
extern "ptx-kernel" fn f6 ( ) { }
extern "x86-interrupt" fn f7 ( ) { }
extern "thiscall" fn f8 ( ) { }
extern "amdgpu-kernel" fn f9 ( ) { }
extern "efiapi" fn f10 ( ) { }
trait Tr {
extern "rust-intrinsic" fn m1 ( ) ;
extern "platform-intrinsic" fn m2 ( ) ;
extern "vectorcall" fn m3 ( ) ;
extern "rust-call" fn m4 ( ) ;
extern "msp430-interrupt" fn m5 ( ) ;
extern "ptx-kernel" fn m6 ( ) ;
extern "x86-interrupt" fn m7 ( ) ;
extern "thiscall" fn m8 ( ) ;
extern "amdgpu-kernel" fn m9 ( ) ;
extern "efiapi" fn m10 ( ) ;
extern "vectorcall" fn dm3 ( ) { }
extern "rust-call" fn dm4 ( ) { }
extern "msp430-interrupt" fn dm5 ( ) { }
extern "ptx-kernel" fn dm6 ( ) { }
extern "x86-interrupt" fn dm7 ( ) { }
extern "thiscall" fn dm8 ( ) { }
extern "amdgpu-kernel" fn dm9 ( ) { }
extern "efiapi" fn dm10 ( ) { }
}
struct S ;
impl Tr for S {
extern "rust-intrinsic" fn m1 ( ) { }
extern "platform-intrinsic" fn m2 ( ) { }
extern "vectorcall" fn m3 ( ) { }
extern "rust-call" fn m4 ( ) { }
extern "msp430-interrupt" fn m5 ( ) { }
extern "ptx-kernel" fn m6 ( ) { }
extern "x86-interrupt" fn m7 ( ) { }
extern "thiscall" fn m8 ( ) { }
extern "amdgpu-kernel" fn m9 ( ) { }
extern "efiapi" fn m10 ( ) { }
}
impl im1 {
extern "rust-intrinsic" fn im1 ( ) { }
extern "platform-intrinsic" fn im2 ( ) { }
extern "vectorcall" fn im3 ( ) { }
extern "rust-call" fn im4 ( ) { }
extern "msp430-interrupt" fn im5 ( ) { }
extern "ptx-kernel" fn im6 ( ) { }
extern "x86-interrupt" fn im7 ( ) { }
extern "thiscall" fn im8 ( ) { }
extern "amdgpu-kernel" fn im9 ( ) { }
extern "efiapi" fn im10 ( ) { }
}
type A1 = extern "rust-intrinsic" fn ( ) ;
type A2 = extern "platform-intrinsic" fn ( ) ;
type A3 = extern "vectorcall" fn ( ) ;
type A4 = extern "rust-call" fn ( ) ;
type A5 = extern "msp430-interrupt" fn ( ) ;
type A6 = extern "ptx-kernel" fn ( ) ;
type A7 = extern "x86-interrupt" fn ( ) ;
type A8 = extern "thiscall" fn ( ) ;
type A9 = extern "amdgpu-kernel" fn ( ) ;
type A10 = extern "efiapi" fn ( ) ;
extern "rust-intrinsic" { }
extern "platform-intrinsic" { }
extern "vectorcall" { }
extern "rust-call" { }
extern "msp430-interrupt" { }
extern "ptx-kernel" { }
extern "x86-interrupt" { }
extern "thiscall" { }
extern "amdgpu-kernel" { }
extern "efiapi" { }
fn main ( ) { }
