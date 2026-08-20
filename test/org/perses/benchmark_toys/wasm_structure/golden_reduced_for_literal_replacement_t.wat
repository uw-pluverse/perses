(module
  (type       (func))
  (type       (func (param i32 i32 i32) (result i32)))
  (type       (func                                 ))
  (type       (func                                             ))
  (type       (func                ))
  (type       (func (param i32)))
  (type       (func (param i32 i32 i32 i32) (result i32)))
  (type       (func (param i32) (result i32)))
  (type       (func (param i32 i64 i32 i32) (result i32)))
  (import "wasi_snapshot_preview1" "proc_exit" (func       (type 5)))
  (import "wasi_snapshot_preview1" "fd_write" (func       (type 6)))
  (import "wasi_snapshot_preview1" "fd_close" (func       (type 7)))
  (import "wasi_snapshot_preview1" "fd_seek" (func       (type 8)))
  (func
           )
  (func
        i32.const 0
        call 11
    unreachable
          )
  (func
    call 5
               )
  (func               )
 (func
 )
 (func
 )
 (func
 )
  (func                  (param i32    ) (result i32)
    global.get 0
    i32.const 0
    i32.or
    local.get 0
    local.get 0
    call 39
               )
  (func                 (param i32 i32 i32) (result i32)
    (local f32 f32 i32                )
    global.get 0
    i32.const 0
    i32.or
    local.tee 0
    i32.load offset=10
    local.set 5
    local.get 0
    local.get 5
    i32.store offset=20
              local.get 0
              local.get 1
              i32.const 16
              i32.or
              i32.const 1
              local.get 1
              call 1
               )
 (func
 )
 (func
 )
 (func
 )
  (func                            )
 (func
 )
 (func
 )
 (func
 )
 (func
 )
  (func                            )
 (func
 )
 (func
 )
 (func
 )
  (func
               )
 (func
 )
 (func
 )
 (func
 )
  (func                 (param i32 i32 i32) (result i32)
        local.get 1
        local.get 0
        local.get 0
        local.get 2
        i32.load offset=36
        call_indirect (type 1)
        return
               )
  (func                  (param i32 i32 i32 i32 i32) (result i32)
    global.get 0
    i32.const 0
        local.get 0
        call 31
    unreachable
               )
  (func                  (param i32 i32 i32                )
                                i32.const 7
                                  local.get 0
                                  local.get 0
                                  local.get 1
                                  call 32
 drop
                        i32.const 0
                        local.set 0
                  local.get 0
                  call 0
                )
  (func                  (param i32 i32 i32)
      local.get 0
      local.get 2
      local.get 0
      call 29
      drop
       )
 (func
 )
 (func
 )
 (func
 )
 (func
 )
 (func
 )
 (func
 )
  (func                 (param i32 i32 i32) (result i32)
    local.get 0
    local.get 0
    local.get 0
    i32.const 0
    i32.const 0
    call 30)
  (table       9   funcref)
  (memory       8      )
  (global            i32   i32.const 1     )
  (export "_start" (func 6))
  (elem       (i32.const 1)      0 0  12               )
  (data       (i32.const 500  ) "-+   0X0x\00-0X+0X 0X-0x+0x 0x\00Unknown error\00nan\00inf\00NAN\00INF\00.\00(null)\00unreachable\0a\00hello world\0a\00\00\00\19\00\0b\00\19\19\19\00\00\00\00\05\00\00\00\00\00\00\09\00\00\00\00\0b\00\00\00\00\00\00\00\00\19\00\0a\0a\19\19\19\03\0a\07\00\01\00\09\0b\18\00\00\09\06\0b\00\00\0b\00\06\19\00\00\00\19\19\19\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\0e\00\00\00\00\00\00\00\00\19\00\0b\0d\19\19\19\00\0d\00\00\02\00\09\0e\00\00\00\09\00\0e\00\00\0e\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\0c\00\00\00\00\00\00\00\00\00\00\00\13\00\00\00\00\13\00\00\00\00\09\0c\00\00\00\00\00\0c\00\00\0c\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\10\00\00\00\00\00\00\00\00\00\00\00\0f\00\00\00\04\0f\00\00\00\00\09\10\00\00\00\00\00\10\00\00\10\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\12\00\00\00\00\00\00\00\00\00\00\00\11\00\00\00\00\11\00\00\00\00\09\12\00\00\00\00\00\12\00\00\12\00\00\1a\00\00\00\1a\1a\1a\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\1a\00\00\00\1a\1a\1a\00\00\00\00\00\00\09\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\14\00\00\00\00\00\00\00\00\00\00\00\17\00\00\00\00\17\00\00\00\00\09\14\00\00\00\00\00\14\00\00\14\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\16\00\00\00\00\00\00\00\00\00\00\00\15\00\00\00\00\15\00\00\00\00\09\16\00\00\00\00\00\16\00\00\16\00\000123456789ABCDEF\00\00\a0\02N\00\eb\01\a7\05~\05 \01u\06\18\03\86\04\fa\00\b9\03,\03\fd\05\b7\01\8a\01z\03\bc\04\1e\00\cc\06\a2\00=\03I\03\d7\01\00\04\08\00\93\06\08\01\8f\02\06\02*\06_\02\b7\02\fa\02X\03\d9\04\fd\06\ca\02\bd\05\e1\05\cd\05\dc\02\10\06@\02x\00}\02g\03a\04\ec\00\e5\03\0a\05\d4\00\cc\03>\06O\02v\01\98\03\af\04\00\00D\00\10\02\ae\00\ae\03`\00\fa\01w\04!\05\eb\04+\00`\01A\01\92\00\a9\06\a3\01n\02N\01\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\13\04\00\00\00\00\00\00\00\00*\02\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00'\049\04H\04\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\92\04\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\008\05R\05`\05S\06\00\00\ca\01\00\00\00\00\00\00\00\00\bb\06\db\06\eb\06\10\07+\07;\07P\07Success\00Illegal byte sequence\00Domain error\00Result not representable\00Not a tty\00Permission denied\00Operation not permitted\00No such file or directory\00No such process\00File exists\00Value too large for defined data type\00No space left on device\00Out of memory\00Resource busy\00Interrupted system call\00Resource temporarily unavailable\00Invalid seek\00Cross-device link\00Read-only file system\00Directory not empty\00Connection reset by peer\00Operation timed out\00Connection refused\00Host is down\00Host is unreachable\00Address in use\00Broken pipe\00I/O error\00No such device or address\00Block device required\00No such device\00Not a directory\00Is a directory\00Text file busy\00Exec format error\00Invalid argument\00Argument list too long\00Symbolic link loop\00Filename too long\00Too many open files in system\00No file descriptors available\00Bad file descriptor\00No child process\00Bad address\00File too large\00Too many links\00No locks available\00Resource deadlock would occur\00State not recoverable\00Owner died\00Operation canceled\00Function not implemented\00No message of desired type\00Identifier removed\00Device not a stream\00No data available\00Device timeout\00Out of streams resources\00Link has been severed\00Protocol error\00Bad message\00File descriptor in bad state\00Not a socket\00Destination address required\00Message too large\00Protocol wrong type for socket\00Protocol not available\00Protocol not supported\00Socket type not supported\00Not supported\00Protocol family not supported\00Address family not supported by protocol\00Address not available\00Network is down\00Network unreachable\00Connection reset by network\00Connection aborted\00No buffer space available\00Socket is connected\00Socket not connected\00Cannot send after socket shutdown\00Operation already in progress\00Operation in progress\00Stale file handle\00Remote I/O error\00Quota exceeded\00No medium found\00Wrong medium type\00Multihop attempted\00Required key not available\00Key has expired\00Key has been revoked\00Key was rejected by service\00")
  (data       (i32.const 1    ) "\05\00\00\00\00\00\00\00\00\00\00\00\02\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\03\00\00\00\04\00\00\00\18\0c\01\00\00\04\00\00\00\00\00\00\00\00\00\00\01\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\ff\ff\ff\ff\0a\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\e0\0a\01\00\00 \00\00\05\00\00\00\00\00\00\00\00\00\00\00\07\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\03\00\00\00\08\00\00\00\ec\10\01\00\00\00\00\00\00\00\00\00\00\00\00\00\02\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\ff\ff\ff\ff\ff\ff\ff\ff\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00x\0b\01\00"))
