(module
  ;; Import the 'fd_write' function from the 'wasi_snapshot_preview1' module.
  (import "wasi_snapshot_preview1" "fd_write" (func $fd_write (param i32 i32 i32 i32) (result i32)))

  ;; Export a memory section with one page (64KB) of memory.
  (memory (export "memory") 1)

  (type $add_type (func (param i32 i32) (result i32)))

  ;; Define the data segments in memory.
  ;; They are placed one after the other. We'll use offsets to keep track.
  ;; String 1: "hello world"
  (data (i32.const 16) "hello world\n")
  ;; String 2: "3"
  (data (i32.const 30) "3\n")
  ;; String 3: "This is the second hello world"
  (data (i32.const 33) "This is the second hello world\n")

  (func $f0 (result i32)
    (i32.const 0)
  )

  (func $f1 (param $a i32) (result i32)
    (local.get $a)
  )

  (func $f2 (param $a i32) (param $b i32) (result i32)
    (i32.add (local.get $a) (local.get $b))
  )

  (func $f3 (param $a i32) (param $b i32) (param $c i32) (result i32)
    (i32.add (local.get $a) (local.get $b))
  )

  (func $add (export "add") (type $add_type)
    (local $temp i32)
    (i32.add (local.get 0) (local.get 1))
    (local.tee $temp)
  )

  ;; The main function, which is exported as "_start".
  (func (export "_start")

    ;; --- Print "hello world" ---
    ;; Create the iovec for the first string.
    ;; iovec at offset 8, buffer at offset 16, length 12
    i32.const 8        ;; iovec offset
    i32.const 16       ;; iov.buf: pointer to "hello world"
    i32.store offset=0 ;; Store the pointer at iovec offset 8
    i32.const 8        ;; iovec offset
    i32.const 12       ;; iov.buf_len: length of the string including newline
    i32.store offset=4 ;; Store the length at iovec offset 12

    ;; Call fd_write for the first string.
    i32.const 1        ;; file descriptor (stdout)
    i32.const 8        ;; iovec pointer
    i32.const 1        ;; iovec count
    i32.const 0        ;; bytes written pointer
    call $fd_write
    drop               ;; drop the result from the stack

    ;; --- Print "3" ---
    ;; Create the iovec for the number "3".
    ;; iovec at offset 20, buffer at offset 30, length 2
    i32.const 20       ;; iovec offset
    i32.const 30       ;; iov.buf: pointer to "3"
    i32.store offset=0 ;; Store the pointer at iovec offset 20
    i32.const 20       ;; iovec offset
    i32.const 2        ;; iov.buf_len: length of "3" and newline
    i32.store offset=4 ;; Store the length at iovec offset 24

    ;; Call fd_write for the number "3".
    i32.const 1        ;; file descriptor (stdout)
    i32.const 20       ;; iovec pointer
    i32.const 1        ;; iovec count
    i32.const 0        ;; bytes written pointer
    call $fd_write
    drop               ;; drop the result from the stack

    ;; --- Print "This is the second hello world" ---
    ;; Create the iovec for the second hello world string.
    ;; iovec at offset 28, buffer at offset 33, length 31
    i32.const 28       ;; iovec offset
    i32.const 33       ;; iov.buf: pointer to "This is the second hello world"
    i32.store offset=0 ;; Store the pointer at iovec offset 28
    i32.const 28       ;; iovec offset
    i32.const 31       ;; iov.buf_len: length of string + newline
    i32.store offset=4 ;; Store the length at iovec offset 32

    ;; Call fd_write for the second hello world string.
    i32.const 1        ;; file descriptor (stdout)
    i32.const 28       ;; iovec pointer
    i32.const 1        ;; iovec count
    i32.const 0        ;; bytes written pointer
    call $fd_write
    drop               ;; drop the result from the stack
  )
)