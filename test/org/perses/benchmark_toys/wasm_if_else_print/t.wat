(module
  ;; Import WASI function for printing
  (import "wasi_snapshot_preview1" "fd_write" (func $fd_write (param i32 i32 i32 i32) (result i32)))

  (memory 1)
  (export "memory" (memory 0))

  ;; Data strings at specific memory offsets
  (data (i32.const 8) "hello\n")
  (data (i32.const 16) "world\n")
  (data (i32.const 24) "else\n")

  ;; Global variable 'a' (Set to 1, 2, or any other number to test)
  (global $a i32 (i32.const 3))

  (func (export "_start")
    ;; --- Check if a == 1 ---
    global.get $a
    i32.const 1
    i32.eq
    if
      ;; Case: a == 1
      i32.const 8  ;; offset
      i32.const 6  ;; length (including \n)
      call $print
    else
      ;; --- Nested check: if a != 1, check if a == 2 ---
      global.get $a
      i32.const 2
      i32.eq
      if
        ;; Case: a == 2
        i32.const 16 ;; offset
        i32.const 6  ;; length
        call $print
      else
        ;; Case: a is neither 1 nor 2
        i32.const 24 ;; offset
        i32.const 5  ;; length
        call $print
      end
    end
  )

  ;; Helper function to handle the WASI fd_write boilerplate
  (func $print (param $offset i32) (param $len i32)
    ;; Write iovec to memory
    i32.const 0          ;; address 0
    local.get $offset    ;; string address
    i32.store
    i32.const 4          ;; address 4
    local.get $len       ;; string length
    i32.store

    ;; Call fd_write
    i32.const 1          ;; stdout
    i32.const 0          ;; iovec pointer
    i32.const 1          ;; number of iovecs
    i32.const 40         ;; result storage
    call $fd_write
    drop
  )
)