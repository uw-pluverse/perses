(module
  (import "wasi_snapshot_preview1" "fd_write" (func $fd_write (param i32 i32 i32 i32) (result i32)))
  (memory 1)
  (data (i32.const 10) "else"  )
  (func (export "_start")
        i32.const 10
        i32.const 5
        call $print
  )
  (func $print (param $offset i32) (param $len i32)
    i32.const 0
    local.get $offset
    i32.store
    i32.const 4
    local.get $len
    i32.store
    i32.const 1
    i32.const 0
    i32.const 1
    i32.const 0
    call $fd_write
    drop
  )
)
