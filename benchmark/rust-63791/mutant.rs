pub fn main() {
    let plain = [127, 0, 0, 1, 174, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
    let key = [0; 16];
    let encrypted = [
        222, 157, 168, 71, 195, 237, 77, 237, 182, 194, 17, 235, 182, 214, 204, 80,
    ];

    let output = encrypt(plain, key);
    if output != encrypted {
        std::process::abort();
    }
    // assert_eq!(output, encrypted);

    // println!("success");
}

fn encrypt(input: [u8; 16], key: [u8; 16]) -> [u8; 16] {
    let mut block = input;
    let cipher = Aes128::new(&key);
    cipher.encrypt_block(&mut block);
    block
}

use std::ops::{BitAnd, BitOr, BitXor, Not};
use std::ptr::copy_nonoverlapping;

macro_rules! read_slice {
    ($src:expr, $dst:expr, $size:expr, $which:ident) => {{
        assert_eq!($src.len(), $size * $dst.len());

        unsafe {
            copy_nonoverlapping($src.as_ptr(), $dst.as_mut_ptr() as *mut u8, $src.len());
        }
        for v in $dst.iter_mut() {
            *v = v.$which();
        }
    }};
}
macro_rules! write_num_bytes {
    ($ty:ty, $size:expr, $n:expr, $dst:expr, $which:ident) => {{
        assert!($size <= $dst.len());
        unsafe {
            let bytes = *(&$n.$which() as *const _ as *const [u8; $size]);
            copy_nonoverlapping((&bytes).as_ptr(), $dst.as_mut_ptr(), $size);
        }
    }};
}

const U32X4_0: u32x4 = u32x4(0, 0, 0, 0);
const U32X4_1: u32x4 = u32x4(0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff);
trait AesOps {
    fn sub_bytes(self) -> Self;
    fn inv_sub_bytes(self) -> Self;
    fn shift_rows(self) -> Self;
    fn inv_shift_rows(self) -> Self;
    fn mix_columns(self) -> Self;
    fn inv_mix_columns(self) -> Self;
    fn add_round_key(self, rk: &Self) -> Self;
}

fn encrypt_core<S: AesOps + Copy>(state: &S, sk: &[S]) -> S {
    let mut tmp = state.add_round_key(&sk[0]);
    for i in 1..sk.len() - 1 {
        tmp = tmp.sub_bytes();
        tmp = tmp.shift_rows();
        tmp = tmp.mix_columns();
        tmp = tmp.add_round_key(&sk[i]);
    }
    tmp = tmp.sub_bytes();
    tmp = tmp.shift_rows();
    tmp = tmp.add_round_key(&sk[sk.len() - 1]);

    tmp
}

#[derive(Clone, Copy)]
struct Bs8State<T>(T, T, T, T, T, T, T, T);

impl<T: Copy> Bs8State<T> {
    fn split(self) -> (Bs4State<T>, Bs4State<T>) {
        let Bs8State(x0, x1, x2, x3, x4, x5, x6, x7) = self;
        (Bs4State(x0, x1, x2, x3), Bs4State(x4, x5, x6, x7))
    }
}

impl<T: BitXor<Output = T> + Copy> Bs8State<T> {
    fn xor(self, rhs: Bs8State<T>) -> Bs8State<T> {
        let Bs8State(a0, a1, a2, a3, a4, a5, a6, a7) = self;
        let Bs8State(b0, b1, b2, b3, b4, b5, b6, b7) = rhs;
        Bs8State(
            a0 ^ b0,
            a1 ^ b1,
            a2 ^ b2,
            a3 ^ b3,
            a4 ^ b4,
            a5 ^ b5,
            a6 ^ b6,
            a7 ^ b7,
        )
    }

    fn change_basis_a2x(&self) -> Bs8State<T> {
        let t06 = self.6 ^ self.0;
        let t056 = self.5 ^ t06;
        let t0156 = t056 ^ self.1;
        let t13 = self.1 ^ self.3;

        let x0 = self.2 ^ t06 ^ t13;
        let x1 = t056;
        let x2 = self.0;
        let x3 = self.0 ^ self.4 ^ self.7 ^ t13;
        let x4 = self.7 ^ t056;
        let x5 = t0156;
        let x6 = self.4 ^ t056;
        let x7 = self.2 ^ self.7 ^ t0156;

        Bs8State(x0, x1, x2, x3, x4, x5, x6, x7)
    }

    fn change_basis_x2s(&self) -> Bs8State<T> {
        let t46 = self.4 ^ self.6;
        let t35 = self.3 ^ self.5;
        let t06 = self.0 ^ self.6;
        let t357 = t35 ^ self.7;

        let x0 = self.1 ^ t46;
        let x1 = self.1 ^ self.4 ^ self.5;
        let x2 = self.2 ^ t35 ^ t06;
        let x3 = t46 ^ t357;
        let x4 = t357;
        let x5 = t06;
        let x6 = self.3 ^ self.7;
        let x7 = t35;

        Bs8State(x0, x1, x2, x3, x4, x5, x6, x7)
    }

    fn change_basis_x2a(&self) -> Bs8State<T> {
        let t15 = self.1 ^ self.5;
        let t36 = self.3 ^ self.6;
        let t1356 = t15 ^ t36;
        let t07 = self.0 ^ self.7;

        let x0 = self.2;
        let x1 = t15;
        let x2 = self.4 ^ self.7 ^ t15;
        let x3 = self.2 ^ self.4 ^ t1356;
        let x4 = self.1 ^ self.6;
        let x5 = self.2 ^ self.5 ^ t36 ^ t07;
        let x6 = t1356 ^ t07;
        let x7 = self.1 ^ self.4;

        Bs8State(x0, x1, x2, x3, x4, x5, x6, x7)
    }

    fn change_basis_s2x(&self) -> Bs8State<T> {
        let t46 = self.4 ^ self.6;
        let t01 = self.0 ^ self.1;
        let t0146 = t01 ^ t46;

        let x0 = self.5 ^ t0146;
        let x1 = self.0 ^ self.3 ^ self.4;
        let x2 = self.2 ^ self.5 ^ self.7;
        let x3 = self.7 ^ t46;
        let x4 = self.3 ^ self.6 ^ t01;
        let x5 = t46;
        let x6 = t0146;
        let x7 = self.4 ^ self.7;

        Bs8State(x0, x1, x2, x3, x4, x5, x6, x7)
    }
}

impl<T: Not<Output = T> + Copy> Bs8State<T> {
    fn xor_x63(self) -> Bs8State<T> {
        Bs8State(
            !self.0, !self.1, self.2, self.3, self.4, !self.5, !self.6, self.7,
        )
    }
}

#[derive(Clone, Copy)]
struct Bs4State<T>(T, T, T, T);

impl<T: Copy> Bs4State<T> {
    fn split(self) -> (Bs2State<T>, Bs2State<T>) {
        let Bs4State(x0, x1, x2, x3) = self;
        (Bs2State(x0, x1), Bs2State(x2, x3))
    }

    fn join(self, rhs: Bs4State<T>) -> Bs8State<T> {
        let Bs4State(a0, a1, a2, a3) = self;
        let Bs4State(b0, b1, b2, b3) = rhs;
        Bs8State(a0, a1, a2, a3, b0, b1, b2, b3)
    }
}

impl<T: BitXor<Output = T> + Copy> Bs4State<T> {
    fn xor(self, rhs: Bs4State<T>) -> Bs4State<T> {
        let Bs4State(a0, a1, a2, a3) = self;
        let Bs4State(b0, b1, b2, b3) = rhs;
        Bs4State(a0 ^ b0, a1 ^ b1, a2 ^ b2, a3 ^ b3)
    }
}

#[derive(Clone, Copy)]
struct Bs2State<T>(T, T);

impl<T> Bs2State<T> {
    fn split(self) -> (T, T) {
        let Bs2State(x0, x1) = self;
        (x0, x1)
    }

    fn join(self, rhs: Bs2State<T>) -> Bs4State<T> {
        let Bs2State(a0, a1) = self;
        let Bs2State(b0, b1) = rhs;
        Bs4State(a0, a1, b0, b1)
    }
}

impl<T: BitXor<Output = T> + Copy> Bs2State<T> {
    fn xor(self, rhs: Bs2State<T>) -> Bs2State<T> {
        let Bs2State(a0, a1) = self;
        let Bs2State(b0, b1) = rhs;
        Bs2State(a0 ^ b0, a1 ^ b1)
    }
}
#[inline(always)]
fn bit_slice_4x4_with_u16(a: u32, b: u32, c: u32, d: u32) -> Bs8State<u16> {
    fn pb(x: u32, bit: u32, shift: u32) -> u16 {
        (((x >> bit) & 1) as u16) << shift
    }

    fn construct(a: u32, b: u32, c: u32, d: u32, bit: u32) -> u16 {
        pb(a, bit, 0)
            | pb(b, bit, 1)
            | pb(c, bit, 2)
            | pb(d, bit, 3)
            | pb(a, bit + 8, 4)
            | pb(b, bit + 8, 5)
            | pb(c, bit + 8, 6)
            | pb(d, bit + 8, 7)
            | pb(a, bit + 16, 8)
            | pb(b, bit + 16, 9)
            | pb(c, bit + 16, 10)
            | pb(d, bit + 16, 11)
            | pb(a, bit + 24, 12)
            | pb(b, bit + 24, 13)
            | pb(c, bit + 24, 14)
            | pb(d, bit + 24, 15)
    }

    let x0 = construct(a, b, c, d, 0);
    let x1 = construct(a, b, c, d, 1);
    let x2 = construct(a, b, c, d, 2);
    let x3 = construct(a, b, c, d, 3);
    let x4 = construct(a, b, c, d, 4);
    let x5 = construct(a, b, c, d, 5);
    let x6 = construct(a, b, c, d, 6);
    let x7 = construct(a, b, c, d, 7);

    Bs8State(x0, x1, x2, x3, x4, x5, x6, x7)
}
fn bit_slice_4x1_with_u16(a: u32) -> Bs8State<u16> {
    bit_slice_4x4_with_u16(a, 0, 0, 0)
}
fn bit_slice_1x16_with_u16(data: &[u8]) -> Bs8State<u16> {
    let mut n = [0u32; 4];
    // LE::read_u32_into(data, &mut n);
    read_slice!(data, &mut n, 4, to_le);

    let a = n[0];
    let b = n[1];
    let c = n[2];
    let d = n[3];

    bit_slice_4x4_with_u16(a, b, c, d)
}
fn un_bit_slice_4x4_with_u16(bs: &Bs8State<u16>) -> (u32, u32, u32, u32) {
    fn pb(x: u16, bit: u32, shift: u32) -> u32 {
        u32::from((x >> bit) & 1) << shift
    }

    fn deconstruct(bs: &Bs8State<u16>, bit: u32) -> u32 {
        let Bs8State(x0, x1, x2, x3, x4, x5, x6, x7) = *bs;

        pb(x0, bit, 0)
            | pb(x1, bit, 1)
            | pb(x2, bit, 2)
            | pb(x3, bit, 3)
            | pb(x4, bit, 4)
            | pb(x5, bit, 5)
            | pb(x6, bit, 6)
            | pb(x7, bit, 7)
            | pb(x0, bit + 4, 8)
            | pb(x1, bit + 4, 9)
            | pb(x2, bit + 4, 10)
            | pb(x3, bit + 4, 11)
            | pb(x4, bit + 4, 12)
            | pb(x5, bit + 4, 13)
            | pb(x6, bit + 4, 14)
            | pb(x7, bit + 4, 15)
            | pb(x0, bit + 8, 16)
            | pb(x1, bit + 8, 17)
            | pb(x2, bit + 8, 18)
            | pb(x3, bit + 8, 19)
            | pb(x4, bit + 8, 20)
            | pb(x5, bit + 8, 21)
            | pb(x6, bit + 8, 22)
            | pb(x7, bit + 8, 23)
            | pb(x0, bit + 12, 24)
            | pb(x1, bit + 12, 25)
            | pb(x2, bit + 12, 26)
            | pb(x3, bit + 12, 27)
            | pb(x4, bit + 12, 28)
            | pb(x5, bit + 12, 29)
            | pb(x6, bit + 12, 30)
            | pb(x7, bit + 12, 31)
    }

    let a = deconstruct(bs, 0);
    let b = deconstruct(bs, 1);
    let c = deconstruct(bs, 2);
    let d = deconstruct(bs, 3);

    (a, b, c, d)
}
fn un_bit_slice_4x1_with_u16(bs: &Bs8State<u16>) -> u32 {
    let (a, _, _, _) = un_bit_slice_4x4_with_u16(bs);
    a
}
fn un_bit_slice_1x16_with_u16(bs: &Bs8State<u16>, output: &mut [u8]) {
    let (a, b, c, d) = un_bit_slice_4x4_with_u16(bs);

    write_num_bytes!(u32, 4, a, &mut output[0..4], to_le);
    write_num_bytes!(u32, 4, b, &mut output[4..8], to_le);
    write_num_bytes!(u32, 4, c, &mut output[8..12], to_le);
    write_num_bytes!(u32, 4, d, &mut output[12..16], to_le);
}
fn bit_slice_1x128_with_u32x4(data: &[u8]) -> Bs8State<u32x4> {
    let bit0 = u32x4(0x01010101, 0x01010101, 0x01010101, 0x01010101);
    let bit1 = u32x4(0x02020202, 0x02020202, 0x02020202, 0x02020202);
    let bit2 = u32x4(0x04040404, 0x04040404, 0x04040404, 0x04040404);
    let bit3 = u32x4(0x08080808, 0x08080808, 0x08080808, 0x08080808);
    let bit4 = u32x4(0x10101010, 0x10101010, 0x10101010, 0x10101010);
    let bit5 = u32x4(0x20202020, 0x20202020, 0x20202020, 0x20202020);
    let bit6 = u32x4(0x40404040, 0x40404040, 0x40404040, 0x40404040);
    let bit7 = u32x4(0x80808080, 0x80808080, 0x80808080, 0x80808080);

    fn read_row_major(data: &[u8]) -> u32x4 {
        u32x4(
            u32::from(data[0])
                | (u32::from(data[4]) << 8)
                | (u32::from(data[8]) << 16)
                | (u32::from(data[12]) << 24),
            u32::from(data[1])
                | (u32::from(data[5]) << 8)
                | (u32::from(data[9]) << 16)
                | (u32::from(data[13]) << 24),
            u32::from(data[2])
                | (u32::from(data[6]) << 8)
                | (u32::from(data[10]) << 16)
                | (u32::from(data[14]) << 24),
            u32::from(data[3])
                | (u32::from(data[7]) << 8)
                | (u32::from(data[11]) << 16)
                | (u32::from(data[15]) << 24),
        )
    }

    let t0 = read_row_major(&data[0..16]);
    let t1 = read_row_major(&data[16..32]);
    let t2 = read_row_major(&data[32..48]);
    let t3 = read_row_major(&data[48..64]);
    let t4 = read_row_major(&data[64..80]);
    let t5 = read_row_major(&data[80..96]);
    let t6 = read_row_major(&data[96..112]);
    let t7 = read_row_major(&data[112..128]);

    let x0 = (t0 & bit0)
        | (t1.lsh(1) & bit1)
        | (t2.lsh(2) & bit2)
        | (t3.lsh(3) & bit3)
        | (t4.lsh(4) & bit4)
        | (t5.lsh(5) & bit5)
        | (t6.lsh(6) & bit6)
        | (t7.lsh(7) & bit7);
    let x1 = (t0.rsh(1) & bit0)
        | (t1 & bit1)
        | (t2.lsh(1) & bit2)
        | (t3.lsh(2) & bit3)
        | (t4.lsh(3) & bit4)
        | (t5.lsh(4) & bit5)
        | (t6.lsh(5) & bit6)
        | (t7.lsh(6) & bit7);
    let x2 = (t0.rsh(2) & bit0)
        | (t1.rsh(1) & bit1)
        | (t2 & bit2)
        | (t3.lsh(1) & bit3)
        | (t4.lsh(2) & bit4)
        | (t5.lsh(3) & bit5)
        | (t6.lsh(4) & bit6)
        | (t7.lsh(5) & bit7);
    let x3 = (t0.rsh(3) & bit0)
        | (t1.rsh(2) & bit1)
        | (t2.rsh(1) & bit2)
        | (t3 & bit3)
        | (t4.lsh(1) & bit4)
        | (t5.lsh(2) & bit5)
        | (t6.lsh(3) & bit6)
        | (t7.lsh(4) & bit7);
    let x4 = (t0.rsh(4) & bit0)
        | (t1.rsh(3) & bit1)
        | (t2.rsh(2) & bit2)
        | (t3.rsh(1) & bit3)
        | (t4 & bit4)
        | (t5.lsh(1) & bit5)
        | (t6.lsh(2) & bit6)
        | (t7.lsh(3) & bit7);
    let x5 = (t0.rsh(5) & bit0)
        | (t1.rsh(4) & bit1)
        | (t2.rsh(3) & bit2)
        | (t3.rsh(2) & bit3)
        | (t4.rsh(1) & bit4)
        | (t5 & bit5)
        | (t6.lsh(1) & bit6)
        | (t7.lsh(2) & bit7);
    let x6 = (t0.rsh(6) & bit0)
        | (t1.rsh(5) & bit1)
        | (t2.rsh(4) & bit2)
        | (t3.rsh(3) & bit3)
        | (t4.rsh(2) & bit4)
        | (t5.rsh(1) & bit5)
        | (t6 & bit6)
        | (t7.lsh(1) & bit7);
    let x7 = (t0.rsh(7) & bit0)
        | (t1.rsh(6) & bit1)
        | (t2.rsh(5) & bit2)
        | (t3.rsh(4) & bit3)
        | (t4.rsh(3) & bit4)
        | (t5.rsh(2) & bit5)
        | (t6.rsh(1) & bit6)
        | (t7 & bit7);

    Bs8State(x0, x1, x2, x3, x4, x5, x6, x7)
}

fn bit_slice_fill_4x4_with_u32x4(a: u32, b: u32, c: u32, d: u32) -> Bs8State<u32x4> {
    let mut tmp = [0u8; 128];
    for i in 0..8 {
        write_num_bytes!(u32, 4, a, &mut tmp[i * 16..i * 16 + 4], to_le);
        write_num_bytes!(u32, 4, b, &mut tmp[i * 16 + 4..i * 16 + 8], to_le);
        write_num_bytes!(u32, 4, c, &mut tmp[i * 16 + 8..i * 16 + 12], to_le);
        write_num_bytes!(u32, 4, d, &mut tmp[i * 16 + 12..i * 16 + 16], to_le);
    }
    bit_slice_1x128_with_u32x4(&tmp)
}

impl<T: BitXor<Output = T> + BitAnd<Output = T> + Copy> Bs2State<T> {
    fn mul(self, y: Bs2State<T>) -> Bs2State<T> {
        let (b, a) = self.split();
        let (d, c) = y.split();
        let e = (a ^ b) & (c ^ d);
        let p = (a & c) ^ e;
        let q = (b & d) ^ e;
        Bs2State(q, p)
    }

    fn scl_n(self) -> Bs2State<T> {
        let (b, a) = self.split();
        let q = a ^ b;
        Bs2State(q, b)
    }

    fn scl_n2(self) -> Bs2State<T> {
        let (b, a) = self.split();
        let p = a ^ b;
        let q = a;
        Bs2State(q, p)
    }

    fn sq(self) -> Bs2State<T> {
        let (b, a) = self.split();
        Bs2State(a, b)
    }

    fn inv(self) -> Bs2State<T> {
        self.sq()
    }
}

impl<T: BitXor<Output = T> + BitAnd<Output = T> + Copy> Bs4State<T> {
    fn mul(self, y: Bs4State<T>) -> Bs4State<T> {
        let (b, a) = self.split();
        let (d, c) = y.split();
        let f = c.xor(d);
        let e = a.xor(b).mul(f).scl_n();
        let p = a.mul(c).xor(e);
        let q = b.mul(d).xor(e);
        q.join(p)
    }

    fn sq_scl(self) -> Bs4State<T> {
        let (b, a) = self.split();
        let p = a.xor(b).sq();
        let q = b.sq().scl_n2();
        q.join(p)
    }

    fn inv(self) -> Bs4State<T> {
        let (b, a) = self.split();
        let c = a.xor(b).sq().scl_n();
        let d = a.mul(b);
        let e = c.xor(d).inv();
        let p = e.mul(b);
        let q = e.mul(a);
        q.join(p)
    }
}

impl<T: BitXor<Output = T> + BitAnd<Output = T> + Copy + Default> Bs8State<T> {
    fn inv(&self) -> Bs8State<T> {
        let (b, a) = self.split();
        let c = a.xor(b).sq_scl();
        let d = a.mul(b);
        let e = c.xor(d).inv();
        let p = e.mul(b);
        let q = e.mul(a);
        q.join(p)
    }
}

impl<T: AesBitValueOps + Copy + 'static> AesOps for Bs8State<T> {
    fn sub_bytes(self) -> Bs8State<T> {
        let nb: Bs8State<T> = self.change_basis_a2x();
        let inv = nb.inv();
        let nb2: Bs8State<T> = inv.change_basis_x2s();
        nb2.xor_x63()
    }

    fn inv_sub_bytes(self) -> Bs8State<T> {
        let t = self.xor_x63();
        let nb: Bs8State<T> = t.change_basis_s2x();
        let inv = nb.inv();
        inv.change_basis_x2a()
    }

    fn shift_rows(self) -> Bs8State<T> {
        let Bs8State(x0, x1, x2, x3, x4, x5, x6, x7) = self;
        Bs8State(
            x0.shift_row(),
            x1.shift_row(),
            x2.shift_row(),
            x3.shift_row(),
            x4.shift_row(),
            x5.shift_row(),
            x6.shift_row(),
            x7.shift_row(),
        )
    }

    fn inv_shift_rows(self) -> Bs8State<T> {
        let Bs8State(x0, x1, x2, x3, x4, x5, x6, x7) = self;
        Bs8State(
            x0.inv_shift_row(),
            x1.inv_shift_row(),
            x2.inv_shift_row(),
            x3.inv_shift_row(),
            x4.inv_shift_row(),
            x5.inv_shift_row(),
            x6.inv_shift_row(),
            x7.inv_shift_row(),
        )
    }
    fn mix_columns(self) -> Bs8State<T> {
        let Bs8State(x0, x1, x2, x3, x4, x5, x6, x7) = self;

        let x0out = x7 ^ x7.ror1() ^ x0.ror1() ^ (x0 ^ x0.ror1()).ror2();
        let x1out = x0 ^ x0.ror1() ^ x7 ^ x7.ror1() ^ x1.ror1() ^ (x1 ^ x1.ror1()).ror2();
        let x2out = x1 ^ x1.ror1() ^ x2.ror1() ^ (x2 ^ x2.ror1()).ror2();
        let x3out = x2 ^ x2.ror1() ^ x7 ^ x7.ror1() ^ x3.ror1() ^ (x3 ^ x3.ror1()).ror2();
        let x4out = x3 ^ x3.ror1() ^ x7 ^ x7.ror1() ^ x4.ror1() ^ (x4 ^ x4.ror1()).ror2();
        let x5out = x4 ^ x4.ror1() ^ x5.ror1() ^ (x5 ^ x5.ror1()).ror2();
        let x6out = x5 ^ x5.ror1() ^ x6.ror1() ^ (x6 ^ x6.ror1()).ror2();
        let x7out = x6 ^ x6.ror1() ^ x7.ror1() ^ (x7 ^ x7.ror1()).ror2();

        Bs8State(x0out, x1out, x2out, x3out, x4out, x5out, x6out, x7out)
    }
    fn inv_mix_columns(self) -> Bs8State<T> {
        let Bs8State(x0, x1, x2, x3, x4, x5, x6, x7) = self;

        let x0out = x5 ^ x6 ^ x7 ^ (x5 ^ x7 ^ x0).ror1() ^ (x0 ^ x5 ^ x6).ror2() ^ (x5 ^ x0).ror3();
        let x1out = x5
            ^ x0
            ^ (x6 ^ x5 ^ x0 ^ x7 ^ x1).ror1()
            ^ (x1 ^ x7 ^ x5).ror2()
            ^ (x6 ^ x5 ^ x1).ror3();
        let x2out = x6
            ^ x0
            ^ x1
            ^ (x7 ^ x6 ^ x1 ^ x2).ror1()
            ^ (x0 ^ x2 ^ x6).ror2()
            ^ (x7 ^ x6 ^ x2).ror3();
        let x3out = x0
            ^ x5
            ^ x1
            ^ x6
            ^ x2
            ^ (x0 ^ x5 ^ x2 ^ x3).ror1()
            ^ (x0 ^ x1 ^ x3 ^ x5 ^ x6 ^ x7).ror2()
            ^ (x0 ^ x5 ^ x7 ^ x3).ror3();
        let x4out = x1
            ^ x5
            ^ x2
            ^ x3
            ^ (x1 ^ x6 ^ x5 ^ x3 ^ x7 ^ x4).ror1()
            ^ (x1 ^ x2 ^ x4 ^ x5 ^ x7).ror2()
            ^ (x1 ^ x5 ^ x6 ^ x4).ror3();
        let x5out = x2
            ^ x6
            ^ x3
            ^ x4
            ^ (x2 ^ x7 ^ x6 ^ x4 ^ x5).ror1()
            ^ (x2 ^ x3 ^ x5 ^ x6).ror2()
            ^ (x2 ^ x6 ^ x7 ^ x5).ror3();
        let x6out = x3
            ^ x7
            ^ x4
            ^ x5
            ^ (x3 ^ x7 ^ x5 ^ x6).ror1()
            ^ (x3 ^ x4 ^ x6 ^ x7).ror2()
            ^ (x3 ^ x7 ^ x6).ror3();
        let x7out = x4 ^ x5 ^ x6 ^ (x4 ^ x6 ^ x7).ror1() ^ (x4 ^ x5 ^ x7).ror2() ^ (x4 ^ x7).ror3();

        Bs8State(x0out, x1out, x2out, x3out, x4out, x5out, x6out, x7out)
    }

    fn add_round_key(self, rk: &Bs8State<T>) -> Bs8State<T> {
        self.xor(*rk)
    }
}

trait AesBitValueOps:
    BitXor<Output = Self> + BitAnd<Output = Self> + Not<Output = Self> + Default + Sized
{
    fn shift_row(self) -> Self;
    fn inv_shift_row(self) -> Self;
    fn ror1(self) -> Self;
    fn ror2(self) -> Self;
    fn ror3(self) -> Self;
}

impl AesBitValueOps for u16 {
    fn shift_row(self) -> u16 {
        (self & 0x000f)
            | ((self & 0x00e0) >> 1)
            | ((self & 0x0010) << 3)
            | ((self & 0x0c00) >> 2)
            | ((self & 0x0300) << 2)
            | ((self & 0x8000) >> 3)
            | ((self & 0x7000) << 1)
    }

    fn inv_shift_row(self) -> u16 {
        (self & 0x000f)
            | ((self & 0x0080) >> 3)
            | ((self & 0x0070) << 1)
            | ((self & 0x0c00) >> 2)
            | ((self & 0x0300) << 2)
            | ((self & 0xe000) >> 1)
            | ((self & 0x1000) << 3)
    }

    fn ror1(self) -> u16 {
        self >> 4 | self << 12
    }

    fn ror2(self) -> u16 {
        self >> 8 | self << 8
    }

    fn ror3(self) -> u16 {
        self >> 12 | self << 4
    }
}

impl u32x4 {
    fn lsh(self, s: u32) -> u32x4 {
        let u32x4(a0, a1, a2, a3) = self;
        u32x4(
            a0 << s,
            (a1 << s) | (a0 >> (32 - s)),
            (a2 << s) | (a1 >> (32 - s)),
            (a3 << s) | (a2 >> (32 - s)),
        )
    }

    fn rsh(self, s: u32) -> u32x4 {
        let u32x4(a0, a1, a2, a3) = self;
        u32x4(
            (a0 >> s) | (a1 << (32 - s)),
            (a1 >> s) | (a2 << (32 - s)),
            (a2 >> s) | (a3 << (32 - s)),
            a3 >> s,
        )
    }
}

impl Not for u32x4 {
    type Output = u32x4;

    fn not(self) -> u32x4 {
        self ^ U32X4_1
    }
}

impl Default for u32x4 {
    fn default() -> u32x4 {
        u32x4(0, 0, 0, 0)
    }
}

impl AesBitValueOps for u32x4 {
    fn shift_row(self) -> u32x4 {
        let u32x4(a0, a1, a2, a3) = self;
        u32x4(
            a0,
            a1 >> 8 | a1 << 24,
            a2 >> 16 | a2 << 16,
            a3 >> 24 | a3 << 8,
        )
    }

    fn inv_shift_row(self) -> u32x4 {
        let u32x4(a0, a1, a2, a3) = self;
        u32x4(
            a0,
            a1 >> 24 | a1 << 8,
            a2 >> 16 | a2 << 16,
            a3 >> 8 | a3 << 24,
        )
    }

    fn ror1(self) -> u32x4 {
        let u32x4(a0, a1, a2, a3) = self;
        u32x4(a1, a2, a3, a0)
    }

    fn ror2(self) -> u32x4 {
        let u32x4(a0, a1, a2, a3) = self;
        u32x4(a2, a3, a0, a1)
    }

    fn ror3(self) -> u32x4 {
        let u32x4(a0, a1, a2, a3) = self;
        u32x4(a3, a0, a1, a2)
    }
}

#[derive(Clone, Copy, PartialEq, Eq)]
#[allow(non_camel_case_types)]
struct u32x4(u32, u32, u32, u32);

impl BitXor for u32x4 {
    type Output = u32x4;

    #[inline(always)]
    fn bitxor(self, rhs: u32x4) -> u32x4 {
        u32x4(
            self.0 ^ rhs.0,
            self.1 ^ rhs.1,
            self.2 ^ rhs.2,
            self.3 ^ rhs.3,
        )
    }
}

impl BitAnd for u32x4 {
    type Output = u32x4;

    #[inline(always)]
    fn bitand(self, rhs: u32x4) -> u32x4 {
        u32x4(
            self.0 & rhs.0,
            self.1 & rhs.1,
            self.2 & rhs.2,
            self.3 & rhs.3,
        )
    }
}

impl BitOr for u32x4 {
    type Output = u32x4;

    #[inline(always)]
    fn bitor(self, rhs: u32x4) -> u32x4 {
        u32x4(
            self.0 | rhs.0,
            self.1 | rhs.1,
            self.2 | rhs.2,
            self.3 | rhs.3,
        )
    }
}

#[derive(Clone)]
struct Aes128 {
    enc_keys: [Bs8State<u16>; 11],
    dec_keys: [Bs8State<u16>; 11],
    enc_keys8: [Bs8State<u32x4>; 11],
    dec_keys8: [Bs8State<u32x4>; 11],
}

impl Aes128 {
    #[inline]
    fn new(key: &[u8; 16]) -> Self {
        let (ek, dk) = expand_key(key);
        let k8 = Bs8State(
            U32X4_0, U32X4_0, U32X4_0, U32X4_0, U32X4_0, U32X4_0, U32X4_0, U32X4_0,
        );
        let mut c = Self {
            enc_keys: [Bs8State(0, 0, 0, 0, 0, 0, 0, 0); 11],
            dec_keys: [Bs8State(0, 0, 0, 0, 0, 0, 0, 0); 11],
            enc_keys8: [k8; 11],
            dec_keys8: [k8; 11],
        };
        for i in 0..11 {
            c.enc_keys[i] = bit_slice_4x4_with_u16(ek[i][0], ek[i][1], ek[i][2], ek[i][3]);
            c.dec_keys[i] = bit_slice_4x4_with_u16(dk[i][0], dk[i][1], dk[i][2], dk[i][3]);
            c.enc_keys8[i] = bit_slice_fill_4x4_with_u32x4(ek[i][0], ek[i][1], ek[i][2], ek[i][3]);
            c.dec_keys8[i] = bit_slice_fill_4x4_with_u32x4(dk[i][0], dk[i][1], dk[i][2], dk[i][3]);
        }
        c
    }

    #[inline]
    fn encrypt_block(&self, block: &mut [u8; 16]) {
        let mut bs = bit_slice_1x16_with_u16(block);
        bs = encrypt_core(&bs, &self.enc_keys);
        un_bit_slice_1x16_with_u16(&bs, block);
    }
}
static RCON: [u32; 10] = [0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36];

fn ffmulx(x: u32) -> u32 {
    let m1: u32 = 0x80808080;
    let m2: u32 = 0x7f7f7f7f;
    let m3: u32 = 0x0000001b;
    ((x & m2) << 1) ^ (((x & m1) >> 7) * m3)
}

fn inv_mcol(x: u32) -> u32 {
    let f2 = ffmulx(x);
    let f4 = ffmulx(f2);
    let f8 = ffmulx(f4);
    let f9 = x ^ f8;

    f2 ^ f4 ^ f8 ^ (f2 ^ f9).rotate_right(8) ^ (f4 ^ f9).rotate_right(16) ^ f9.rotate_right(24)
}

fn sub_word(x: u32) -> u32 {
    let bs = bit_slice_4x1_with_u16(x).sub_bytes();
    un_bit_slice_4x1_with_u16(&bs)
}
fn expand_key(key: &[u8; 16]) -> ([[u32; 4]; 11], [[u32; 4]; 11]) {
    let rounds = 11;
    let key_len = 16;
    let key_words = match key_len {
        16 => 4,
        24 => 6,
        32 => 8,
        _ => panic!("Invalid AES key size."),
    };
    let mut ek = <[[u32; 4]; 11]>::default();
    let mut j = 0;
    for i in 0..key_len / 4 {
        ek[j / 4][j % 4] = u32::from(key[4 * i])
            | (u32::from(key[4 * i + 1]) << 8)
            | (u32::from(key[4 * i + 2]) << 16)
            | (u32::from(key[4 * i + 3]) << 24);
        j += 1;
    }
    for i in key_words..rounds * 4 {
        let mut tmp = ek[(i - 1) / 4][(i - 1) % 4];
        if (i % key_words) == 0 {
            tmp = sub_word(tmp.rotate_right(8)) ^ RCON[(i / key_words) - 1];
        } else if (key_words == 8) && ((i % key_words) == 4) {
            tmp = sub_word(tmp);
        }
        ek[i / 4][i % 4] = ek[(i - key_words) / 4][(i - key_words) % 4] ^ tmp;
    }
    let mut dk = <[[u32; 4]; 11]>::default();
    dk[0] = ek[0];
    for j in 1..rounds - 1 {
        for i in 0..4 {
            dk[j][i] = inv_mcol(ek[j][i]);
        }
    }
    dk[rounds - 1] = ek[rounds - 1];

    (ek, dk)
}
