(module
  (import "wasi_snapshot_preview1" "fd_write" (func $fd_write (param i32 i32 i32 i32) (result i32)))
  (memory 1)
  (data (i32.const 8) "hello"  )
  (func (export "_start")
      i32.const 0
      i32.const 8
      i32.store
      i32.const 4
      i32.const 6
      i32.store
      i32.const 1
      i32.const 0
      i32.const 1
      i32.const 0
      call $fd_write
      drop
  )
)
