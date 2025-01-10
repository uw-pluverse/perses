# ! [ feature ( arbitrary_self_types , coerce_unsized , dispatch_from_dyn , unsize , unsized_locals ) ]
use std :: marker :: PhantomData ;
mod internal {
use std :: ops :: { CoerceUnsized , Deref , DispatchFromDyn } ;
use std :: marker :: { x , Unsize } ;
pub struct Smaht < T : ? Sized , MISC > ( pub Box < T > , pub PhantomData < MISC > ) ;
impl < T : ? Sized , MISC > Deref for Smaht < T , MISC > {
type Target = T ;
fn deref ( & self ) -> & Self :: Target {
& self . 0
}
}
impl < T : ? Sized + Unsize < U > , U : ? Sized , MISC > CoerceUnsized < Smaht < U , MISC > >
for Smaht < T , MISC >
{ }
impl < T : ? Sized + Unsize < U > , U : ? Sized , MISC > DispatchFromDyn < Smaht < U , MISC > >
for Smaht < T , MISC >
{ }
pub trait Foo : X < u32 > { }
pub trait X < T > {
fn foo ( self : Smaht < Self , T > ) -> T ;
}
impl X < u32 > for ( ) {
fn foo ( self : Smaht < Self , u32 > ) -> u32 {
0
}
}
pub trait Marker { }
impl Marker for dyn Foo { }
impl < T : Marker + ? Sized > X < u64 > for T {
fn foo ( self : Smaht < Self , u64 > ) -> u64 {
1
}
}
impl Deref for dyn Foo {
type Target = ( ) ;
fn deref ( & self ) -> & ( ) { & ( ) }
}
impl Foo for ( ) { }
}
pub trait FinalFoo {
fn foo ( & self ) -> u8 ;
}
impl FinalFoo for ( ) {
fn foo ( & self ) -> u8 { 0 }
}
mod nuisance_foo {
pub trait NuisanceFoo {
fn foo ( self ) ;
}
impl < T : ? Sized > NuisanceFoo for T {
fn foo ( self ) { }
}
}
fn objectcandidate_impl ( ) {
let x : internal :: Smaht < ( ) , u32 > = internal :: Smaht ( Box :: new ( ( ) ) , PhantomData ) ;
let x : internal :: Smaht < dyn internal :: Foo , u32 > = x ;
let z = x . foo ( ) ;
let _seetype : ( ) = z ;
}
fn traitcandidate_impl ( ) {
use internal :: X ;
let x : internal :: Smaht < ( ) , u64 > = internal :: Smaht ( Box :: new ( ( ) ) , PhantomData ) ;
let x : internal :: Smaht < dyn internal :: Foo , u64 > = x ;
let z = x . foo ( ) ;
let _seetype : ( ) = z ;
}
fn traitcandidate_impl_with_nuisance ( ) {
use internal :: X ;
use nuisance_foo :: NuisanceFoo ;
let x : internal :: Smaht < ( ) , u64 > = internal :: Smaht ( Box :: new ( ( ) ) , PhantomData ) ;
let x : internal :: Smaht < dyn internal :: Foo , u64 > = x ;
let z = x . foo ( ) ;
}
fn neither_impl ( ) {
let x : internal :: Smaht < ( ) , u64 > = internal :: Smaht ( Box :: new ( ( ) ) , PhantomData ) ;
let x : internal :: Smaht < dyn internal :: Foo , u64 > = x ;
let z = x . foo ( ) ;
let _seetype : ( ) = z ;
}
fn both_impls ( ) {
use internal :: X ;
let x : internal :: Smaht < ( ) , u32 > = internal :: Smaht ( Box :: new ( ( ) ) , PhantomData ) ;
let x : internal :: Smaht < dyn internal :: Foo , u32 > = x ;
let z = x . foo ( ) ;
let _seetype : ( ) = z ;
}
fn both_impls_with_nuisance ( ) {
use internal :: X ;
use nuisance_foo :: NuisanceFoo ;
let x : internal :: Smaht < ( ) , u32 > = internal :: Smaht ( Box :: new ( ( ) ) , PhantomData ) ;
let x : internal :: Smaht < dyn internal :: Foo , u32 > = x ;
let z = x . foo ( ) ;
let _seetype : ( ) = z ;
}
fn main ( ) {
}
