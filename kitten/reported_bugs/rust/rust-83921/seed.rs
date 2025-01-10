


#![crate_type = "lib"]

#[repr(packed)]
pub struct Packed1 {
    dealign: u8,
    data: u32
}

#[repr(packed(2))]
pub struct Packed2 {
    dealign: u8,
    data: u32
}


#[no_mangle]
pub fn write_pkd1(pkd: &mut Packed1) -> u32 {


    let result = pkd.data;
    pkd.data = 42;
    result
}


#[no_mangle]
pub fn write_pkd2(pkd: &mut Packed2) -> u32 {


    let result = pkd.data;
    pkd.data = 42;
    result
}

pub struct Array([i32; 8]);
#[repr(packed)]
pub struct BigPacked1 {
    dealign: u8,
    data: Array
}

#[repr(packed(2))]
pub struct BigPacked2 {
    dealign: u8,
    data: Array
}


#[no_mangle]
pub fn call_pkd1(f: fn() -> Array) -> BigPacked1 {






    BigPacked1 { dealign: 0, data: f() }
}


#[no_mangle]
pub fn call_pkd2(f: fn() -> Array) -> BigPacked2 {






    BigPacked2 { dealign: 0, data: f() }
}





#[no_mangle]
pub fn write_packed_array1(p: &mut BigPacked1) {
    p.data.0[0] = 0;
    p.data.0[1] = 1;
    p.data.0[2] = 2;
}





#[no_mangle]
pub fn write_packed_array2(p: &mut BigPacked2) {
    p.data.0[0] = 0;
    p.data.0[1] = 1;
    p.data.0[2] = 2;
}



#[no_mangle]
pub fn repeat_packed_array1(p: &mut BigPacked1) {
    p.data.0 = [42; 8];
}



#[no_mangle]
pub fn repeat_packed_array2(p: &mut BigPacked2) {
    p.data.0 = [42; 8];
}

#[repr(packed)]
#[derive(Copy, Clone)]
pub struct Packed1Pair(u8, u32);

#[repr(packed(2))]
#[derive(Copy, Clone)]
pub struct Packed2Pair(u8, u32);


#[no_mangle]
pub fn pkd1_pair(pair1: &mut Packed1Pair, pair2: &mut Packed1Pair) {

    *pair2 = *pair1;
}


#[no_mangle]
pub fn pkd2_pair(pair1: &mut Packed2Pair, pair2: &mut Packed2Pair) {

    *pair2 = *pair1;
}

#[repr(packed)]
#[derive(Copy, Clone)]
pub struct Packed1NestedPair((u32, u32));

#[repr(packed(2))]
#[derive(Copy, Clone)]
pub struct Packed2NestedPair((u32, u32));


#[no_mangle]
pub fn pkd1_nested_pair(pair1: &mut Packed1NestedPair, pair2: &mut Packed1NestedPair) {

    *pair2 = *pair1;
}


#[no_mangle]
pub fn pkd2_nested_pair(pair1: &mut Packed2NestedPair, pair2: &mut Packed2NestedPair) {

    *pair2 = *pair1;
}
