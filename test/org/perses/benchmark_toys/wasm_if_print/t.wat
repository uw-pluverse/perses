(module
  ;; Import the WASI function for writing to stdout
  (import "wasi_snapshot_preview1" "fd_write" (func $fd_write (param i32 i32 i32 i32) (result i32)))

  (memory 1)
  (export "memory" (memory 0))

  ;; Store "hello\n" at offset 8
  (data (i32.const 8) "hello\n")

  ;; Global variable a = 1
  (global $a i32 (i32.const 1))

  ;; WASI looks for a function named _start
  (func (export "_start")
    global.get $a
    i32.const 1
    i32.eq
    if
      ;; Prepare WASI iovec: [address of string, length of string]
      ;; We store this structure at memory offset 0
      i32.const 0  ;; offset 0
      i32.const 8  ;; string starts at offset 8
      i32.store

      i32.const 4  ;; offset 4
      i32.const 6  ;; string length is 6 ("hello\n")
      i32.store

      ;; Call fd_write(file_descriptor, iovs_ptr, iovs_len, nwritten_ptr)
      i32.const 1  ;; 1 = stdout
      i32.const 0  ;; pointer to our iovec at offset 0
      i32.const 1  ;; we are sending 1 iovec
      i32.const 20 ;; where to store the number of bytes written
      call $fd_write
      drop         ;; ignore the error code returned by fd_write
    end
  )
)