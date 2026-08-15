(module
  (import "wasi_snapshot_preview1" "fd_write" (func $fd_write (param i32 i32 i32 i32) (result i32)))
  (memory                   1)
  (data (i32.const 0 ) "hello"        )
  (func (export "_start")
    i32.const 8
    i32.const 10
    i32.store offset=4
memory.size
    i32.const 8
memory.size
    i32.const 0
    call $fd_write
drop
  )
)
