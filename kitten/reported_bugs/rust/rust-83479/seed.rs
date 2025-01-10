

#![allow(unused)]
#![feature(nll, type_ascription)]

type PairUncoupled<'a, 'b, T> = (&'a T, &'b T);
type PairCoupledTypes<T> = (T, T);
type PairCoupledRegions<'a, T> = (&'a T, &'a T);

fn uncoupled_wilds_rhs<'a>(_x: &'a u32, s: &'static u32) -> &'static u32 {
    let ((y, _z),) = ((s, _x),): (PairUncoupled<_>,);
    y
}

fn coupled_wilds_rhs<'a>(_x: &'a u32, s: &'static u32) -> &'static u32 {
    let ((y, _z),) = ((s, _x),): (PairCoupledTypes<_>,);
    y
}

fn coupled_regions_rhs<'a>(_x: &'a u32, s: &'static u32) -> &'static u32 {
    let ((y, _z),) = ((s, _x),): (PairCoupledRegions<_>,);
    y
}

fn cast_uncoupled_wilds_rhs<'a>(_x: &'a u32, s: &'static u32) -> &'static u32 {
    let ((y, _z),) = ((s, _x),) as (PairUncoupled<_>,);
    y
}

fn cast_coupled_wilds_rhs<'a>(_x: &'a u32, s: &'static u32) -> &'static u32 {
    let ((y, _z),) = ((s, _x),) as (PairCoupledTypes<_>,);
    y
}

fn cast_coupled_regions_rhs<'a>(_x: &'a u32, s: &'static u32) -> &'static u32 {
    let ((y, _z),) = ((s, _x),) as (PairCoupledRegions<_>,);
    y
}

fn main() {}
