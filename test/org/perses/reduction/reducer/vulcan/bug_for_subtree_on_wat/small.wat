(module
  (type       (func))
  (type       (func))
  (type       (func))
  (type       (func))
  (type       (func))
  (type       (func))
  (type       (func))
  (type       (func))
  (type       (func))
  (type       (func))
  (type        (func (param i32 i32 i32 i32)))
  (func               )
  (func               )
  (func               )
  (func               )
  (func               )
  (func               )
  (func               )
  (func               )
  (func               )
  (func       (type 10)                        )
  (func                  (param f64 i32) (result f64)
    local.get 1
    local.get 1
    local.get 1
    local.get 1
    i32.const 1
    call_indirect (type 10)
    f32.const 0
    local.get 1
    f32.load
    drop
    drop
    local.get 0)
  (func
    f64.const 0
    i32.const 0
    call 10
    return)
  (table       10 funcref)
  (memory       0)
  (export "main" (func 11))
  (elem       (i32.const 1)      9))
