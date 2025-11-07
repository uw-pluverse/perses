(module
  (type (;0;) (func (param i32 i32 i32 i32) (result i32)))
  (type (;1;) (func (param i32)))
  (type (;2;) (func))
  (type (;3;) (func (result i32)))
  (func (;0;) (type 2)
    (local i32 f32 i64 f64)
    i32.const 305419896
    local.set 0
    f32.const 0x1.8cp+6 (;=99;)
    local.set 1
    i64.const -72057589709208571
    local.set 2
    f64.const 0x1.5f0b08c960a79p+109 (;=8.9e+32;)
    local.set 3
    i32.const 0
    i32.const -1
    i32.const 1
    memory.init 1
    local.get 0
    global.set 8
    local.get 1
    global.set 9
    local.get 2
    global.set 10
    local.get 3
    global.set 11)
  (func (;1;) (type 3) (result i32)
    i32.const 1
    i32.const 3
    i32.add)
  (func (;2;) (type 3) (result i32)
    i32.const 2
    i32.const 3
    i32.add)
  (func (;3;) (type 3) (result i32)
    i32.const 3
    i32.const 3
    i32.add)
  (table (;0;) 10 20 funcref)
  (memory (;0;) 1 5)
  (global (;0;) i32 (i32.const 541))
  (global (;1;) (mut i32) (i32.const 191))
  (global (;2;) f32 (f32.const 0x1.0e8p+9 (;=541;)))
  (global (;3;) (mut f32) (f32.const 0x1.8p+7 (;=192;)))
  (global (;4;) i64 (i64.const 54))
  (global (;5;) (mut i64) (i64.const 19))
  (global (;6;) f64 (f64.const 0x1.bp+5 (;=54;)))
  (global (;7;) (mut f64) (f64.const 0x1.3p+4 (;=19;)))
  (global (;8;) (mut i32) (i32.const 0))
  (global (;9;) (mut f32) (f32.const 0x0p+0 (;=0;)))
  (global (;10;) (mut i64) (i64.const 0))
  (global (;11;) (mut f64) (f64.const 0x0p+0 (;=0;)))
  (export "_start" (func 0))
  (export "to_test" (func 0))
  (elem (;0;) (i32.const 0) func 1 2 3 0 1)
  (elem (;1;) (i32.const 5) func 3 3 2 1)
  (elem (;2;) (i32.const 9) func 0)
  (data (;0;) (i32.const 8) "\01\02\03\04\05\06\07\08")
  (data (;1;) (i32.const 16) "\01\02\03\04\05\06\07\08\ff")
  (data (;2;) (i32.const 32) "\01\02\03\04\05\06\07\08\ff"))
