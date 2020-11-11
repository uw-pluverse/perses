fn main() {
    const MOD: i64 = 100_000_000;
    const N: u64 = 1_000_000_000_000;

    const SIZE: usize = 4;
    const SIZE64: u64 = SIZE as _;
    type Mat = [[i64; SIZE]; SIZE];

    fn matrix_prod(a: &Mat, b: &Mat, n: usize, m: usize, p: usize) -> Mat {
        let mut res: Mat = Mat::default();
        for i in 0 .. n {
            for j in 0 .. p {
                for k in 0 .. m {
                    res[i][j] = (res[i][j] + a[i][k] * b[k][j] % MOD) % MOD;
                }
            }
        }
        res
    }

    fn matrix_pow(mut a: Mat, s: usize, mut n: u64) -> Mat {
        let mut res: Mat = [[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, 0], [0, 0, 0, 1]];

        while n != 0 {
            if (n & 1) != 0 {
                res = matrix_prod(&a, &res, s, s, s);
            }
            n >>= 1;
            a = matrix_prod(&a, &a, s, s, s);
        }
        res
    }

    const G1: Mat = [[0, 1, 0, 0], [0, 0, 1, 0], [0, 0, 0, 1], [1, -2, 2, 2]];
    let g2 = matrix_pow(G1, SIZE, N - SIZE64);
    println!("{:?}", g2);
}
