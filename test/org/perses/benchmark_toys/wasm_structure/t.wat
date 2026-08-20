(module
  (type       (func))
  (type       (func (param i32 i32 i32) (result i32)))
  (type       (func (param i32 i64 i32) (result f32)))
  (type       (func (param f32 f32 f32 f32 f32 f32) (result f32)))
  (type       (func (param f32 f32)))
  (type       (func (param i32)))
  (type       (func (param i32 i32 i32 i32) (result i32)))
  (type       (func (param i32) (result i32)))
  (type       (func (param i32 i64 i32 i32) (result i32)))
  (type       (func (result i32)))
  (type        (func (param i32 i32) (result i32)))
  (type        (func (param f32 f32) (result f32)))
  (type        (func (param i32 i32 i32 i32 i32) (result i32)))
  (type        (func (param f32 f32 f32 f32 f32 f32 f32) (result f32)))
  (type        (func (param i32 i32 i32)))
  (type        (func (param f32 f32 f32 f32)))
  (type        (func (param f32 f32 f32) (result f32)))
  (type        (func (param i64 i32) (result i32)))
  (type        (func (param i32 i32 i32 i32 i32)))
  (import "wasi_snapshot_preview1" "proc_exit" (func       (type 5)))
  (import "wasi_snapshot_preview1" "fd_write" (func       (type 6)))
  (import "wasi_snapshot_preview1" "fd_close" (func       (type 7)))
  (import "wasi_snapshot_preview1" "fd_seek" (func       (type 8)))
  (func       (type 0)
    call 4
    call 7 )
  (func       (type 9) (result i32)
    (local i32 f32)
    global.get 0
    i32.const 0
    i32.or
    local.set 0
    local.get 0
    global.set 0
    local.get 0
    i32.const 0
    i32.store offset=0
    local.get 0
    i32.const 0
    i32.store offset=0
    block
      block
        local.get 0
        i32.load offset=0
        i32.const 0
        i32.or
        i32.const 0
        i32.eq
        i32.const 0
        i32.or
        i32.eqz
        br_if 0
        i32.const 0
        i32.const 0
        call 11
        drop
        br 0
      end
      f32.const 0
      i32.const 0
      call 0
      drop
    end
    i32.const 0
    local.set 0
    local.get 0
    i32.const 0
    i32.or
    global.set 0
    local.get 0
    return)
  (func       (type 0)
    block
      i32.const 0
      i32.eqz
      br_if 0
      call 4
    end
    call 5
    call 0
    unreachable)
  (func       (type 0))
  (func       (type 0)
    (local i32)
    i32.const 0
    local.set 0
    block
      i32.const 0
      i32.const 0
      i32.le_u
      br_if 0
      loop
        local.get 0
        i32.const +0
        i32.or
        local.tee 0
        i32.load
        call_indirect (type 0)
        local.get 0
        i32.const 0
        i32.gt_u
        br_if 0
      end
    end
    call 7)
  (func       (type 5) (param i32)
    call 7
    call 8
    call 13
    local.get 0
    call 0
    unreachable)
  (func        (type 5) (param i32)
    local.get 0
    call 0
    unreachable)
  (func        (type 10) (param i32 i32) (result i32)
    (local f32)
    global.get 0
    i32.const 0
    i32.or
    local.tee 0
    global.set 0
    local.get 0
    local.get 0
    i32.store offset=0
    i32.const 0
    local.get 0
    local.get 0
    call 39
    local.set 0
    local.get 0
    i32.const 0
    i32.or
    global.set 0
    local.get 0)
  (func        (type 1) (param i32 i32 i32) (result i32)
    (local f32 f32 i32 i32 f32 f32 f32)
    global.get 0
    i32.const 0
    i32.or
    local.tee 0
    global.set 0
    local.get 0
    local.get 0
    i32.load offset=0
    local.tee 1
    i32.store offset=0
    local.get 0
    i32.load offset=10
    local.set 5
    local.get 0
    local.get 0
    i32.store offset=0
    local.get 0
    local.get 0
    i32.store offset=0
    local.get 1
    local.get 5
    local.get 0
    i32.or
    local.tee 1
    i32.store offset=20
    local.get 1
    local.get 0
    i32.or
    local.set 6
    local.get 0
    i32.const 0
    i32.or
    local.set 0
    i32.const 0
    local.set 1
    block
      block
        block
          block
            block
              local.get 0
              i32.load offset=0
              local.get 1
              i32.const 16
              i32.or
              i32.const 1
              local.get 1
              i32.const 12
              i32.or
              call 1
              call 43
              i32.eqz
              br_if 0
              local.get 0
              local.set 0
              br 0
            end
            loop
              local.get 6
              local.get 1
              i32.load offset=12
              local.tee 0
              i32.eq
              br_if 1
              block
                local.get 0
                i32.const +0
                i32.gt_s
                br_if 0
                local.get 0
                local.set 0
                br 0
              end
              local.get 0
              i32.const 0
              i32.const 0
              local.get 0
              local.get 0
              i32.load offset=0
              local.tee 0
              i32.gt_u
              local.tee 0
              select
              i32.or
              local.tee 0
              local.get 0
              i32.load
              local.get 0
              local.get 0
              i32.const 0
              local.get 0
              select
              i32.or
              local.tee 0
              i32.or
              i32.store
              local.get 0
              i32.const 0
              i32.const 0
              local.get 0
              select
              i32.or
              local.tee 0
              local.get 0
              i32.load
              local.get 0
              i32.or
              i32.store
              local.get 0
              local.get 0
              i32.or
              local.set 0
              local.get 0
              local.set 0
              local.get 0
              i32.load offset=0
              local.get 0
              local.get 0
              local.get 0
              i32.or
              local.tee 0
              local.get 0
              i32.const 0
              i32.or
              call 1
              call 13
              i32.eqz
              br_if 0
            end
          end
          local.get 0
          i32.const +0
          i32.ne
          br_if 0
        end
        local.get 0
        local.get 0
        i32.load offset=0
        local.tee 0
        i32.store offset=0
        local.get 0
        local.get 0
        i32.store offset=0
        local.get 0
        local.get 0
        local.get 0
        i32.load offset=0
        i32.or
        i32.store offset=0
        local.get 0
        local.set 0
        br 0
      end
      i32.const 0
      local.set 0
      local.get 0
      i32.const 0
      i32.store offset=0
      local.get 0
      i64.const 0
      i64.store offset=0
      local.get 0
      local.get 0
      i32.load
      i32.const 0
      i32.or
      i32.store
      local.get 0
      i32.const 0
      i32.eq
      br_if 0
      local.get 0
      local.get 0
      i32.load offset=0
      i32.or
      local.set 0
    end
    local.get 0
    i32.const 0
    i32.or
    global.set 0
    local.get 0)
 (func  (type
                     0
                         )
     unreachable
 )
 (func  (type
                     0
                         )
     unreachable
 )
 (func  (type
                     0
                         )
     unreachable
 )
  (func        (type 5) (param i32))
 (func  (type
                     9
                         )
     unreachable
 )
 (func  (type
                     0
                         )
     unreachable
 )
  (func        (type 1) (param i32 i32 i32) (result i32)
    (local f32 f32 f32)
    block
      local.get 0
      i32.const 0
      i32.lt_u
      br_if 0
      local.get 0
      local.get 0
      local.get 0
      call 0
      return
    end
    local.get 0
    local.get 0
    i32.or
    local.set 0
    block
      block
        local.get 0
        local.get 0
        i32.or
        i32.const 0
        i32.or
        br_if 0
        block
          block
            local.get 0
            i32.const 0
            i32.or
            br_if 0
            local.get 0
            local.set 0
            br 0
          end
          block
            local.get 0
            br_if 0
            local.get 0
            local.set 0
            br 0
          end
          local.get 0
          local.set 0
          loop
            local.get 0
            local.get 0
            i32.load
            i32.store
            local.get 0
            i32.const 0
            i32.or
            local.set 0
            local.get 0
            i32.const 0
            i32.or
            local.tee 0
            i32.const 0
            i32.or
            i32.eqz
            br_if 0
            local.get 0
            local.get 0
            i32.lt_u
            br_if 0
          end
        end
        local.get 0
        i32.const +0
        i32.or
        local.set 0
        block
          local.get 0
          i32.const 0
          i32.lt_u
          br_if 0
          local.get 0
          local.get 0
          i32.const +0
          i32.or
          local.tee 0
          i32.gt_u
          br_if 0
          loop
            local.get 0
            local.get 0
            i32.load
            i32.store
            local.get 0
            local.get 0
            i32.load offset=0
            i32.store offset=0
            local.get 0
            local.get 0
            i32.load offset=0
            i32.store offset=0
            local.get 0
            local.get 0
            i32.load offset=0
            i32.store offset=0
            local.get 0
            local.get 0
            i32.load offset=0
            i32.store offset=0
            local.get 0
            local.get 0
            i32.load offset=0
            i32.store offset=0
            local.get 0
            local.get 0
            i32.load offset=0
            i32.store offset=0
            local.get 0
            local.get 0
            i32.load offset=0
            i32.store offset=0
            local.get 0
            local.get 0
            i32.load offset=0
            i32.store offset=0
            local.get 0
            local.get 0
            i32.load offset=0
            i32.store offset=0
            local.get 0
            local.get 0
            i32.load offset=0
            i32.store offset=0
            local.get 0
            local.get 0
            i32.load offset=0
            i32.store offset=0
            local.get 0
            local.get 0
            i32.load offset=0
            i32.store offset=0
            local.get 0
            local.get 0
            i32.load offset=0
            i32.store offset=0
            local.get 0
            local.get 0
            i32.load offset=0
            i32.store offset=0
            local.get 0
            local.get 0
            i32.load offset=0
            i32.store offset=0
            local.get 0
            i32.const 0
            i32.or
            local.set 0
            local.get 0
            i32.const 0
            i32.or
            local.tee 0
            local.get 0
            i32.le_u
            br_if 0
          end
        end
        local.get 0
        local.get 0
        i32.ge_u
        br_if 0
        loop
          local.get 0
          local.get 0
          i32.load
          i32.store
          local.get 0
          i32.const 0
          i32.or
          local.set 0
          local.get 0
          i32.const 0
          i32.or
          local.tee 0
          local.get 0
          i32.lt_u
          br_if 0
          br 0
        end
      end
      block
        local.get 0
        i32.const 0
        i32.ge_u
        br_if 0
        local.get 0
        local.set 0
        br 0
      end
      block
        local.get 0
        i32.const 0
        i32.ge_u
        br_if 0
        local.get 0
        local.set 0
        br 0
      end
      local.get 0
      i32.const +0
      i32.or
      local.set 0
      local.get 0
      local.set 0
      loop
        local.get 0
        local.get 0
        i32.load
        i32.store
        local.get 0
        local.get 0
        i32.load    offset=0
        i32.store  offset=0
        local.get 0
        local.get 0
        i32.load    offset=0
        i32.store  offset=0
        local.get 0
        local.get 0
        i32.load    offset=0
        i32.store  offset=0
        local.get 0
        i32.const 0
        i32.or
        local.set 0
        local.get 0
        i32.const 0
        i32.or
        local.tee 0
        local.get 0
        i32.le_u
        br_if 0
      end
    end
    block
      local.get 0
      local.get 0
      i32.ge_u
      br_if 0
      loop
        local.get 0
        local.get 0
        i32.load
        i32.store
        local.get 0
        i32.const 0
        i32.or
        local.set 0
        local.get 0
        i32.const 0
        i32.or
        local.tee 0
        local.get 0
        i32.ne
        br_if 0
      end
    end
    local.get 0)
 (func  (type
                     0
                         )
     unreachable
 )
  (func        (type 5) (param i32))
  (func        (type 9) (result i32)
    i32.const 0
    call 0
    i32.const 0    )
  (func        (type 0)
    (local i32)
    block
      call 22
      i32.load
      local.tee 0
      i32.eqz
      br_if 0
      loop
        local.get 0
        call 0
        local.get 0
        i32.load offset=0
        local.tee 0
        br_if 0
      end
    end
    i32.const 0
    i32.load offset=0
    call 0
    i32.const 0
    i32.load offset=0
    call 0
    i32.const 0
    i32.load offset=0
    call 0 )
  (func        (type 5) (param i32)
    (local f32 f32)
    block
      local.get 0
      i32.eqz
      br_if 0
      block
        local.get 0
        i32.load offset=0
        i32.const 0
        i32.lt_s
        br_if 0
        local.get 0
        call 15
        drop
      end
      block
        local.get 0
        i32.load offset=0
        local.get 0
        i32.load offset=0
        i32.eq
        br_if 0
        local.get 0
        i32.const 0
        i32.const 0
        local.get 0
        i32.load offset=0
        call_indirect (type 1)
        drop
      end
      local.get 0
      i32.load offset=0
      local.tee 0
      local.get 0
      i32.load offset=0
      local.tee 0
      i32.eq
      br_if 0
      local.get 0
      local.get 0
      local.get 0
      i32.or
      i64.extend_i32_s
      i32.const 0
      local.get 0
      i32.load offset=0
      call_indirect (type 2)
      drop
    end)
  (func        (type 7) (param i32) (result i32)
    (local f32)
    local.get 0
    local.get 0
    i32.load offset=0
    local.tee 0
    i32.const +0
    i32.or
    local.get 0
    i32.or
    i32.store offset=0
    block
      local.get 0
      i32.load
      local.tee 0
      i32.const 0
      i32.or
      i32.eqz
      br_if 0
      local.get 0
      local.get 0
      i32.const 0
      i32.or
      i32.store
      i32.const +0
      return
    end
    local.get 0
    i64.const 0
    i64.store offset=0 align=1
    local.get 0
    local.get 0
    i32.load offset=0
    local.tee 0
    i32.store offset=0
    local.get 0
    local.get 0
    i32.store offset=0
    local.get 0
    local.get 0
    local.get 0
    i32.load offset=0
    i32.or
    i32.store offset=0
    i32.const 0)
 (func  (type
                     0
                         )
     unreachable
 )
 (func  (type
                     0
                         )
     unreachable
 )
 (func  (type
                     0
                         )
     unreachable
 )
  (func        (type 1) (param i32 i32 i32) (result i32)
    (local f32 f32 f32)
    block
      block
        local.get 1
        i32.load offset=0
        local.tee 0
        br_if 0
        i32.const 0
        local.set 0
        local.get 0
        call 25
        br_if 0
        local.get 0
        i32.load offset=0
        local.set 0
      end
      block
        local.get 1
        local.get 0
        local.get 0
        i32.load offset=0
        local.tee 0
        i32.or
        i32.le_u
        br_if 0
        local.get 0
        local.get 0
        local.get 0
        local.get 2
        i32.load offset=36
        call_indirect (type 1)
        return
      end
      block
        block
          local.get 0
          i32.load offset=0
          i32.const 0
          i32.lt_s
          br_if 0
          local.get 0
          i32.eqz
          br_if 0
          local.get 0
          local.set 0
          block
            loop
              local.get 0
              local.get 0
              i32.or
              local.tee 0
              i32.const +0
              i32.or
              i32.load
              i32.const 0
              i32.eq
              br_if 0
              local.get 0
              i32.const +0
              i32.or
              local.tee 0
              i32.eqz
              br_if 0
              br 0
            end
          end
          local.get 0
          local.get 0
          local.get 0
          local.get 0
          i32.load offset=0
          call_indirect (type 0)
          local.tee 0
          local.get 0
          i32.lt_u
          br_if 0
          local.get 0
          local.get 0
          i32.or
          local.set 0
          local.get 0
          i32.load offset=0
          local.set 0
          br 0
        end
        local.get 0
        local.set 0
        i32.const 0
        local.set 0
      end
      local.get 0
      local.get 0
      local.get 0
      call 19
      drop
      local.get 0
      local.get 0
      i32.load offset=0
      local.get 0
      i32.or
      i32.store offset=0
      local.get 0
      local.get 0
      i32.or
      local.set 0
    end
    local.get 0)
  (func        (type 12) (param i32 i32 i32 i32 i32) (result i32)
    (local f32 f32 f32 f32)
    global.get 0
    i32.const 0
    i32.or
    local.tee 0
    global.set 0
    local.get 0
    local.get 0
    i32.store offset=0
    local.get 0
    i32.const 0
    i32.or
    i32.const 0
    i32.const 0
    memory.fill
    local.get 0
    local.get 0
    i32.load offset=0
    i32.store offset=0
    block
      block
        f32.const 0
        local.get 0
        local.get 0
        i32.const 0
        i32.or
        local.get 0
        i32.const 0
        i32.or
        local.get 0
        i32.const 0
        i32.or
        local.get 0
        local.get 0
        call 1
        i32.const 0
        i32.ge_s
        br_if 0
        i32.const +0
        local.set 0
        br 0
      end
      block
        block
          local.get 0
          i32.load offset=76
          i32.const 0
          i32.ge_s
          br_if 0
          i32.const 0
          local.set 1
          br 1
        end
        local.get 0
        call 15
        i32.eqz
        local.set 0
      end
      local.get 0
      local.get 0
      i32.load
      local.tee 1
      i32.const +0
      i32.or
      i32.store
      block
        block
          block
            block
              local.get 0
              i32.load offset=0
              br_if 0
              local.get 0
              i32.const 0
              i32.store offset=0
              local.get 0
              i32.const 0
              i32.store offset=0
              local.get 0
              i64.const 0
              i64.store offset=0
              local.get 0
              i32.load offset=0
              local.set 1
              local.get 0
              local.get 0
              i32.store offset=0
              br 0
            end
            i32.const 0
            local.set 1
            local.get 0
            i32.load offset=0
            br_if 0
          end
          i32.const +0
          local.set 1
          local.get 0
          call 25
          br_if 0
        end
        local.get 0
        local.get 0
        local.get 0
        i32.const 0
        i32.or
        local.get 0
        i32.const 0
        i32.or
        local.get 0
        i32.const 0
        i32.or
        local.get 0
        local.get 0
        call 31
        local.set 0
      end
      local.get 0
      i32.const 0
      i32.or
      local.set 0
      block
        local.get 0
        i32.eqz
        br_if 0
        local.get 0
        i32.const 0
        i32.const 0
        local.get 0
        i32.load offset=0
        call_indirect (type 1)
        drop
        local.get 0
        i32.const 0
        i32.store offset=0
        local.get 0
        local.get 0
        i32.store offset=0
        local.get 0
        i32.const 0
        i32.store offset=0
        local.get 0
        i32.load offset=0
        local.set 0
        local.get 0
        i64.const 0
        i64.store offset=0
        local.get 0
        i32.const +0
        local.get 0
        select
        local.set 0
      end
      local.get 0
      local.get 0
      i32.load
      local.tee 0
      local.get 0
      i32.or
      i32.store
      i32.const +0
      local.get 0
      local.get 0
      i32.const 0
      i32.or
      select
      local.set 0
      local.get 0
      br_if 0
      local.get 0
      call 0
    end
    local.get 0
    i32.const 0
    i32.or
    global.set 0
    local.get 0)
  (func                  (param i32 i32 i32 i32 i32 i32 i32) (result i32)
    (local f32 f32 f32 f32 f32 f32 f32 f32 f32 f32 f32 f32 f32 f32 f32 f32 f32 f32 f32 i64)
    block
      block
        block
          block
            loop
              i32.const 0
              local.set 1
              loop
                local.get 0
                local.set 0
                local.get 0
                local.get 0
                i32.const 0
                i32.or
                i32.gt_s
                br_if 0
                local.get 0
                local.get 0
                i32.or
                local.set 0
                local.get 0
                local.set 0
                block
                  block
                    block
                      block
                        block
                          block
                            local.get 0
                            i32.load
                            local.tee 0
                            i32.eqz
                            br_if 0
                            loop
                              block
                                block
                                  block
                                    local.get 0
                                    i32.const 0
                                    i32.or
                                    local.tee 0
                                    br_if 0
                                    local.get 0
                                    local.set 0
                                    br 0
                                  end
                                  local.get 0
                                  i32.const 0
                                  i32.ne
                                  br_if 0
                                  local.get 0
                                  local.set 0
                                  loop
                                    block
                                      local.get 0
                                      i32.load    offset=0
                                      i32.const 0
                                      i32.eq
                                      br_if 0
                                      local.get 0
                                      local.set 0
                                      br 0
                                    end
                                    local.get 0
                                    i32.const 0
                                    i32.or
                                    local.set 0
                                    local.get 0
                                    i32.load    offset=0
                                    local.set 0
                                    local.get 0
                                    i32.const 0
                                    i32.or
                                    local.tee 0
                                    local.set 0
                                    local.get 0
                                    i32.const 0
                                    i32.eq
                                    br_if 0
                                  end
                                end
                                local.get 0
                                local.get 0
                                i32.or
                                local.tee 0
                                local.get 0
                                i32.const 7
                                i32.or
                                local.tee 1
                                i32.gt_s
                                br_if 0
                                block
                                  local.get 0
                                  i32.eqz
                                  br_if 0
                                  local.get 0
                                  local.get 0
                                  local.get 1
                                  call 32
                                end
                                local.get 0
                                br_if 8
                                local.get 0
                                local.get 0
                                i32.store offset=0
                                local.get 0
                                i32.const 0
                                i32.or
                                local.set 0
                                i32.const +0
                                local.set 0
                                block
                                  local.get 0
                                  i32.load    offset=0
                                  i32.const +0
                                  i32.or
                                  local.tee 0
                                  i32.const 0
                                  i32.gt_u
                                  br_if 0
                                  local.get 0
                                  i32.load    offset=0
                                  i32.const 0
                                  i32.ne
                                  br_if 0
                                  local.get 0
                                  i32.const 0
                                  i32.or
                                  local.set 0
                                  i32.const 0
                                  local.set 0
                                  local.get 0
                                  local.set 0
                                end
                                local.get 0
                                local.get 0
                                i32.store offset=0
                                i32.const 0
                                local.set 0
                                block
                                  block
                                    local.get 0
                                    i32.load
                                    local.tee 0
                                    i32.const +0
                                    i32.or
                                    local.tee 0
                                    i32.const 0
                                    i32.le_u
                                    br_if 0
                                    local.get 0
                                    local.set 0
                                    br 0
                                  end
                                  i32.const 0
                                  local.set 0
                                  local.get 0
                                  local.set 0
                                  i32.const 0
                                  local.get 0
                                  i32.or
                                  local.tee 0
                                  i32.const 0
                                  i32.or
                                  i32.eqz
                                  br_if 0
                                  loop
                                    local.get 0
                                    local.get 0
                                    i32.const 0
                                    i32.or
                                    local.tee 0
                                    i32.store offset=0
                                    local.get 0
                                    local.get 0
                                    i32.or
                                    local.set 0
                                    local.get 0
                                    i32.load    offset=0
                                    local.tee 0
                                    i32.const +0
                                    i32.or
                                    local.tee 0
                                    i32.const 0
                                    i32.ge_u
                                    br_if 0
                                    local.get 0
                                    local.set 0
                                    i32.const 0
                                    local.get 0
                                    i32.or
                                    local.tee 0
                                    i32.const 0
                                    i32.or
                                    br_if 0
                                  end
                                end
                                block
                                  block
                                    local.get 0
                                    i32.const 0
                                    i32.ne
                                    br_if 0
                                    block
                                      block
                                        local.get 0
                                        i32.load    offset=0
                                        i32.const +0
                                        i32.or
                                        local.tee 0
                                        i32.const 0
                                        i32.gt_u
                                        br_if 0
                                        local.get 0
                                        i32.load    offset=0
                                        i32.const 0
                                        i32.ne
                                        br_if 0
                                        block
                                          block
                                            local.get 0
                                            br_if 0
                                            local.get 0
                                            local.get 0
                                            i32.const 0
                                            i32.or
                                            i32.or
                                            i32.const 0
                                            i32.store
                                            i32.const 0
                                            local.set 0
                                            br 0
                                          end
                                          local.get 0
                                          local.get 0
                                          i32.const 0
                                          i32.or
                                          i32.or
                                          i32.load
                                          local.set 0
                                        end
                                        local.get 0
                                        i32.const 0
                                        i32.or
                                        local.set 0
                                        i32.const 0
                                        local.set 0
                                        br 0
                                      end
                                      local.get 0
                                      br_if 0
                                      local.get 0
                                      i32.const 0
                                      i32.or
                                      local.set 0
                                      block
                                        local.get 0
                                        br_if 0
                                        local.get 0
                                        local.get 0
                                        i32.store offset=0
                                        i32.const 0
                                        local.set 0
                                        i32.const 0
                                        local.set 0
                                        br 0
                                      end
                                      local.get 0
                                      local.get 0
                                      i32.load
                                      local.tee 0
                                      i32.const 0
                                      i32.or
                                      i32.store
                                      local.get 0
                                      i32.load
                                      local.set 0
                                      i32.const 0
                                      local.set 0
                                    end
                                    local.get 0
                                    local.get 0
                                    i32.store offset=0
                                    local.get 0
                                    i32.const +0
                                    i32.gt_s
                                    br_if 0
                                    i32.const 0
                                    local.get 0
                                    i32.or
                                    local.set 0
                                    local.get 0
                                    i32.const 0
                                    i32.or
                                    local.set 0
                                    br 0
                                  end
                                  local.get 0
                                  i32.const 0
                                  i32.or
                                  call 13
                                  local.tee 0
                                  i32.const 0
                                  i32.lt_s
                                  br_if 0
                                  local.get 0
                                  i32.load offset=0
                                  local.set 0
                                end
                                i32.const 0
                                local.set 0
                                i32.const +0
                                local.set 0
                                block
                                  block
                                    local.get 0
                                    i32.load
                                    i32.const 0
                                    i32.eq
                                    br_if 0
                                    i32.const 0
                                    local.set 0
                                    br 0
                                  end
                                  block
                                    local.get 0
                                    i32.load    offset=0
                                    i32.const 0
                                    i32.ne
                                    br_if 0
                                    block
                                      block
                                        local.get 0
                                        i32.load    offset=0
                                        i32.const +0
                                        i32.or
                                        local.tee 0
                                        i32.const 0
                                        i32.gt_u
                                        br_if 0
                                        local.get 0
                                        i32.load    offset=0
                                        i32.const 0
                                        i32.ne
                                        br_if 0
                                        block
                                          block
                                            local.get 0
                                            br_if 0
                                            local.get 0
                                            local.get 0
                                            i32.const 0
                                            i32.or
                                            i32.or
                                            i32.const 0
                                            i32.store
                                            i32.const 0
                                            local.set 0
                                            br 0
                                          end
                                          local.get 0
                                          local.get 0
                                          i32.const 0
                                          i32.or
                                          i32.or
                                          i32.load
                                          local.set 0
                                        end
                                        local.get 0
                                        i32.const 0
                                        i32.or
                                        local.set 0
                                        br 0
                                      end
                                      local.get 0
                                      br_if 0
                                      local.get 0
                                      i32.const 0
                                      i32.or
                                      local.set 0
                                      block
                                        local.get 0
                                        br_if 0
                                        i32.const 0
                                        local.set 0
                                        br 0
                                      end
                                      local.get 0
                                      local.get 0
                                      i32.load
                                      local.tee 0
                                      i32.const 0
                                      i32.or
                                      i32.store
                                      local.get 0
                                      i32.load
                                      local.set 0
                                    end
                                    local.get 0
                                    local.get 0
                                    i32.store offset=0
                                    local.get 0
                                    i32.const +0
                                    i32.gt_s
                                    local.set 0
                                    br 0
                                  end
                                  local.get 0
                                  local.get 0
                                  i32.const 0
                                  i32.or
                                  i32.store offset=0
                                  i32.const 0
                                  local.set 0
                                  local.get 0
                                  i32.const 0
                                  i32.or
                                  call 13
                                  local.set 0
                                  local.get 0
                                  i32.load offset=0
                                  local.set 0
                                end
                                loop
                                  local.get 0
                                  local.set 0
                                  i32.const 0
                                  local.set 0
                                  local.get 0
                                  local.tee 0
                                  i32.load
                                  local.tee 0
                                  i32.const +0
                                  i32.or
                                  i32.const +0
                                  i32.lt_u
                                  br_if 0
                                  local.get 0
                                  i32.const 0
                                  i32.or
                                  local.set 0
                                  local.get 0
                                  i32.const 0
                                  i32.or
                                  local.get 0
                                  i32.or
                                  i32.const 0
                                  i32.or
                                  i32.load
                                  local.tee 0
                                  i32.const +0
                                  i32.or
                                  i32.const 0
                                  i32.or
                                  i32.const 0
                                  i32.lt_u
                                  br_if 0
                                end
                                local.get 0
                                local.get 0
                                i32.store offset=0
                                block
                                  block
                                    local.get 0
                                    i32.const 0
                                    i32.eq
                                    br_if 0
                                    local.get 0
                                    i32.eqz
                                    br_if 0
                                    block
                                      local.get 0
                                      i32.const 0
                                      i32.lt_s
                                      br_if 0
                                      block
                                        local.get 0
                                        br_if 0
                                        local.get 0
                                        local.get 0
                                        i32.const 0
                                        i32.or
                                        i32.or
                                        local.get 0
                                        i32.store
                                        br 0
                                      end
                                      local.get 0
                                      local.get 0
                                      local.get 0
                                      i32.const 0
                                      i32.or
                                      i32.or
                                      i64.load
                                      i64.store offset=0
                                      br 0
                                    end
                                    local.get 0
                                    i32.eqz
                                    br_if 0
                                    local.get 0
                                    i32.const 0
                                    i32.or
                                    local.get 0
                                    local.get 0
                                    local.get 0
                                    call 0
                                    br 0
                                  end
                                  local.get 0
                                  i32.const +0
                                  i32.gt_s
                                  br_if 0
                                  i32.const 0
                                  local.set 0
                                  local.get 0
                                  i32.eqz
                                  br_if 0
                                end
                                local.get 0
                                i32.load
                                i32.const 0
                                i32.or
                                br_if 0
                                local.get 0
                                i32.const +0
                                i32.or
                                local.tee 0
                                local.get 0
                                local.get 0
                                i32.const 0
                                i32.or
                                select
                                local.set 0
                                i32.const 0
                                local.set 0
                                i32.const 0
                                local.set 0
                                local.get 0
                                local.set 0
                                block
                                  block
                                    block
                                      block
                                        block
                                          block
                                            block
                                              block
                                                block
                                                  block
                                                    block
                                                      block
                                                        block
                                                          block
                                                            block
                                                              block
                                                                block
                                                                  local.get 0
                                                                  i32.load
                                                                  local.tee 0
                                                                  i32.extend8_s
                                                                  local.tee 0
                                                                  i32.const +0
                                                                  i32.or
                                                                  local.get 0
                                                                  local.get 0
                                                                  i32.const 0
                                                                  i32.or
                                                                  i32.const 0
                                                                  i32.eq
                                                                  select
                                                                  local.get 0
                                                                  local.get 0
                                                                  select
                                                                  local.tee 0
                                                                  i32.const +0
                                                                  i32.or
                                                                  br_table 0         0         0         0         0         0         0         0         0         0          0         0         0         0          0          0          0         0         0         0         0         0         0         0         0         0         0         0          0         0         0         0         0         0
                                                                end
                                                                local.get 0
                                                                local.set 0
                                                                block
                                                                  local.get 0
                                                                  i32.const +0
                                                                  i32.or
                                                                  br_table 0          0         0          0         0          0          0          0
                                                                end
                                                                local.get 0
                                                                i32.const 0
                                                                i32.eq
                                                                br_if 0
                                                                br 0
                                                              end
                                                              i32.const 0
                                                              local.set 0
                                                              i32.const 0
                                                              local.set 0
                                                              local.get 0
                                                              i64.load offset=0
                                                              local.set 26
                                                              br 0
                                                            end
                                                            i32.const 0
                                                            local.set 0
                                                            block
                                                              block
                                                                block
                                                                  block
                                                                    block
                                                                      block
                                                                        block
                                                                          local.get 0
                                                                          br_table 0         0         0         0         0         0         0         0         0
                                                                        end
                                                                        local.get 0
                                                                        i32.load offset=0
                                                                        local.get 0
                                                                        i32.store
                                                                        br 0
                                                                      end
                                                                      local.get 0
                                                                      i32.load offset=0
                                                                      local.get 0
                                                                      i32.store
                                                                      br 0
                                                                    end
                                                                    local.get 0
                                                                    i32.load offset=0
                                                                    local.get 0
                                                                    i64.extend_i32_s
                                                                    i64.store
                                                                    br 0
                                                                  end
                                                                  local.get 0
                                                                  i32.load offset=0
                                                                  local.get 0
                                                                  i32.store
                                                                  br 0
                                                                end
                                                                local.get 0
                                                                i32.load offset=0
                                                                local.get 0
                                                                i32.store
                                                                br 0
                                                              end
                                                              local.get 0
                                                              i32.load offset=0
                                                              local.get 0
                                                              i32.store
                                                              br 0
                                                            end
                                                            local.get 0
                                                            i32.load offset=0
                                                            local.get 0
                                                            i64.extend_i32_s
                                                            i64.store
                                                            br 0
                                                          end
                                                          local.get 0
                                                          i32.const 0
                                                          local.get 0
                                                          i32.const 0
                                                          i32.gt_u
                                                          select
                                                          local.set 0
                                                          local.get 0
                                                          i32.const 0
                                                          i32.or
                                                          local.set 0
                                                          i32.const 0
                                                          local.set 0
                                                        end
                                                        i32.const 0
                                                        local.set 0
                                                        i32.const 0
                                                        local.set 0
                                                        local.get 0
                                                        i64.load offset=0
                                                        local.tee 26
                                                        local.get 0
                                                        local.get 0
                                                        i32.const 0
                                                        i32.or
                                                        call 0
                                                        local.set 0
                                                        local.get 26
                                                        i64.eqz
                                                        br_if 0
                                                        local.get 0
                                                        i32.const 0
                                                        i32.or
                                                        i32.eqz
                                                        br_if 0
                                                        local.get 0
                                                        i32.const 0
                                                        i32.or
                                                        i32.const 0
                                                        i32.or
                                                        local.set 0
                                                        i32.const 0
                                                        local.set 0
                                                        br 0
                                                      end
                                                      i32.const 0
                                                      local.set 0
                                                      i32.const 0
                                                      local.set 0
                                                      local.get 0
                                                      i64.load offset=0
                                                      local.tee 26
                                                      local.get 0
                                                      call 6
                                                      local.set 0
                                                      local.get 0
                                                      i32.const 0
                                                      i32.or
                                                      i32.eqz
                                                      br_if 0
                                                      local.get 0
                                                      local.get 0
                                                      local.get 0
                                                      i32.or
                                                      local.tee 0
                                                      local.get 0
                                                      local.get 0
                                                      i32.gt_s
                                                      select
                                                      local.set 0
                                                      br 0
                                                    end
                                                    block
                                                      local.get 0
                                                      i64.load offset=0
                                                      local.tee 26
                                                      i64.const +0
                                                      i64.gt_s
                                                      br_if 0
                                                      local.get 0
                                                      i64.const 0
                                                      local.get 26
                                                      i64.or
                                                      local.tee 26
                                                      i64.store offset=0
                                                      i32.const 0
                                                      local.set 0
                                                      i32.const 0
                                                      local.set 0
                                                      br 0
                                                    end
                                                    block
                                                      local.get 0
                                                      i32.const 0
                                                      i32.or
                                                      i32.eqz
                                                      br_if 0
                                                      i32.const 0
                                                      local.set 0
                                                      i32.const 0
                                                      local.set 0
                                                      br 0
                                                    end
                                                    i32.const 0
                                                    i32.const 0
                                                    local.get 0
                                                    i32.const 0
                                                    i32.or
                                                    local.tee 0
                                                    select
                                                    local.set 0
                                                  end
                                                  local.get 26
                                                  local.get 0
                                                  call 37
                                                  local.set 0
                                                end
                                                local.get 0
                                                local.get 0
                                                i32.const 0
                                                i32.lt_s
                                                i32.or
                                                br_if 0
                                                local.get 0
                                                i32.const +0
                                                i32.or
                                                local.get 0
                                                local.get 0
                                                select
                                                local.set 0
                                                block
                                                  local.get 26
                                                  i64.const 0
                                                  i64.ne
                                                  br_if 0
                                                  local.get 0
                                                  br_if 0
                                                  local.get 0
                                                  local.set 0
                                                  local.get 0
                                                  local.set 0
                                                  i32.const 0
                                                  local.set 0
                                                  br 0
                                                end
                                                local.get 0
                                                local.get 0
                                                local.get 0
                                                i32.or
                                                local.get 26
                                                i64.eqz
                                                i32.or
                                                local.tee 0
                                                local.get 0
                                                local.get 0
                                                i32.gt_s
                                                select
                                                local.set 0
                                                br 0
                                              end
                                              local.get 0
                                              i32.load    offset=0
                                              local.set 0
                                              br 0
                                            end
                                            local.get 0
                                            i32.load offset=0
                                            local.tee 0
                                            i32.const 0
                                            local.get 0
                                            select
                                            local.set 0
                                            local.get 0
                                            local.get 0
                                            local.get 0
                                            i32.const 0
                                            local.get 0
                                            i32.const 0
                                            i32.lt_u
                                            select
                                            call 0
                                            local.tee 0
                                            i32.or
                                            local.set 0
                                            block
                                              local.get 0
                                              i32.const +0
                                              i32.le_s
                                              br_if 0
                                              local.get 0
                                              local.set 0
                                              local.get 0
                                              local.set 0
                                              br 0
                                            end
                                            local.get 0
                                            local.set 0
                                            local.get 0
                                            local.set 0
                                            local.get 0
                                            i32.load
                                            br_if 0
                                            br 0
                                          end
                                          local.get 0
                                          i64.load offset=0
                                          local.tee 26
                                          i64.eqz
                                          i32.eqz
                                          br_if 0
                                          i32.const 0
                                          local.set 0
                                          br 0
                                        end
                                        block
                                          local.get 0
                                          i32.eqz
                                          br_if 0
                                          local.get 0
                                          i32.load offset=0
                                          local.set 0
                                          br 0
                                        end
                                        i32.const 0
                                        local.set 0
                                        local.get 0
                                        f32.const 0
                                        local.get 0
                                        f32.const 0
                                        local.get 0
                                        call 0
                                        br 0
                                      end
                                      local.get 0
                                      i32.const 0
                                      i32.store offset=0
                                      local.get 0
                                      local.get 26
                                      i64.store   offset=0
                                      local.get 0
                                      local.get 0
                                      i32.const 0
                                      i32.or
                                      i32.store offset=0
                                      local.get 0
                                      i32.const 0
                                      i32.or
                                      local.set 0
                                      i32.const +0
                                      local.set 0
                                    end
                                    i32.const 0
                                    local.set 0
                                    block
                                      loop
                                        local.get 0
                                        i32.load
                                        local.tee 0
                                        i32.eqz
                                        br_if 0
                                        local.get 0
                                        i32.const 0
                                        i32.or
                                        local.get 0
                                        call 0
                                        local.tee 0
                                        i32.const 0
                                        i32.lt_s
                                        br_if 0
                                        local.get 0
                                        local.get 0
                                        local.get 0
                                        i32.or
                                        i32.gt_u
                                        br_if 0
                                        local.get 0
                                        i32.const 0
                                        i32.or
                                        local.set 0
                                        local.get 0
                                        local.get 0
                                        i32.or
                                        local.tee 0
                                        local.get 0
                                        i32.lt_u
                                        br_if 0
                                      end
                                    end
                                    i32.const 0
                                    local.set 0
                                    local.get 0
                                    i32.const 0
                                    i32.lt_s
                                    br_if 0
                                    local.get 0
                                    i32.const 0
                                    local.get 0
                                    local.get 0
                                    local.get 0
                                    call 38
                                    block
                                      local.get 0
                                      br_if 0
                                      i32.const 0
                                      local.set 0
                                      br 0
                                    end
                                    i32.const 0
                                    local.set 0
                                    local.get 0
                                    i32.load offset=0
                                    local.set 0
                                    loop
                                      local.get 0
                                      i32.load
                                      local.tee 0
                                      i32.eqz
                                      br_if 0
                                      local.get 0
                                      i32.const 0
                                      i32.or
                                      local.get 0
                                      call 0
                                      local.tee 0
                                      local.get 0
                                      i32.or
                                      local.tee 0
                                      local.get 0
                                      i32.gt_u
                                      br_if 0
                                      local.get 0
                                      local.get 0
                                      i32.const 0
                                      i32.or
                                      local.get 0
                                      call 32
                                      local.get 0
                                      i32.const 0
                                      i32.or
                                      local.set 0
                                      local.get 0
                                      local.get 0
                                      i32.lt_u
                                      br_if 0
                                    end
                                  end
                                  local.get 0
                                  f32.const 0
                                  local.get 0
                                  local.get 0
                                  local.get 0
                                  i32.const 0
                                  i32.or
                                  call 0
                                  local.get 0
                                  local.get 0
                                  local.get 0
                                  local.get 0
                                  i32.gt_s
                                  select
                                  local.set 0
                                  br 0
                                end
                                local.get 0
                                local.get 0
                                i32.const 0
                                i32.lt_s
                                i32.or
                                br_if 0
                                i32.const 0
                                local.set 0
                                local.get 0
                                local.get 0
                                f32.load offset=0
                                local.get 0
                                local.get 0
                                local.get 0
                                local.get 0
                                local.get 0
                                call_indirect (type 0)
                                local.tee 0
                                i32.const 0
                                i32.ge_s
                                br_if 0
                                br 0
                              end
                              local.get 0
                              i32.load    offset=0
                              local.set 0
                              local.get 0
                              i32.const 0
                              i32.or
                              local.set 0
                              br 0
                            end
                          end
                          local.get 0
                          br_if 0
                          local.get 0
                          i32.eqz
                          br_if 0
                          i32.const 0
                          local.set 0
                          block
                            loop
                              local.get 0
                              local.get 0
                              i32.const 0
                              i32.or
                              i32.or
                              i32.load
                              local.tee 0
                              i32.eqz
                              br_if 0
                              local.get 0
                              local.get 0
                              i32.const 0
                              i32.or
                              i32.or
                              local.get 0
                              local.get 0
                              local.get 0
                              call 0
                              i32.const 0
                              local.set 0
                              local.get 0
                              i32.const 0
                              i32.or
                              local.tee 0
                              i32.const 0
                              i32.ne
                              br_if 0
                              br 0
                            end
                          end
                          block
                            local.get 0
                            i32.const 0
                            i32.lt_u
                            br_if 0
                            i32.const 0
                            local.set 0
                            br 0
                          end
                          loop
                            local.get 0
                            local.get 0
                            i32.const 0
                            i32.or
                            i32.or
                            i32.load
                            br_if 0
                            i32.const 0
                            local.set 0
                            local.get 0
                            i32.const 0
                            i32.or
                            local.tee 0
                            i32.const 0
                            i32.eq
                            br_if 0
                            br 0
                          end
                        end
                        i32.const 0
                        local.set 0
                        br 0
                      end
                      local.get 0
                      local.get 0
                      i32.store  offset=0
                      i32.const 0
                      local.set 0
                      local.get 0
                      local.set 0
                      local.get 0
                      local.set 0
                      local.get 0
                      local.set 0
                      br 0
                    end
                    local.get 0
                    local.set 0
                  end
                  local.get 0
                  local.get 0
                  local.get 0
                  i32.or
                  local.tee 0
                  local.get 0
                  local.get 0
                  i32.gt_s
                  select
                  local.tee 0
                  local.get 0
                  i32.const 0
                  i32.or
                  i32.gt_s
                  br_if 0
                  i32.const 0
                  local.set 0
                  local.get 0
                  local.get 0
                  local.get 0
                  i32.or
                  local.tee 0
                  local.get 0
                  local.get 0
                  i32.gt_s
                  select
                  local.tee 0
                  local.get 0
                  i32.gt_u
                  br_if 0
                  local.get 0
                  f32.const 0
                  local.get 0
                  local.get 0
                  local.get 0
                  call 0
                  local.get 0
                  local.get 0
                  local.get 0
                  call 0
                  local.get 0
                  f32.const 0
                  local.get 0
                  local.get 0
                  local.get 0
                  i32.const 0
                  i32.or
                  call 0
                  local.get 0
                  f32.const 0
                  local.get 0
                  local.get 0
                  i32.const 0
                  call 0
                  local.get 0
                  local.get 0
                  local.get 0
                  call 0
                  local.get 0
                  f32.const 0
                  local.get 0
                  local.get 0
                  local.get 0
                  i32.const 0
                  i32.or
                  call 0
                  local.get 0
                  i32.load offset=0
                  local.set 0
                  br 0
                end
              end
            end
            i32.const 0
            local.set 0
            br 0
          end
          i32.const 0
          local.set 0
        end
        call 17
        local.get 0
        i32.store
      end
      i32.const +0
      local.set 0
    end
    local.get 0
                )
  (func        (type 14) (param i32 i32 i32)
    block
      local.get 0
      i32.load
      i32.const 0
      i32.and
      br_if 0
      local.get 0
      local.get 2
      local.get 0
      call 29
      drop
    end)
 (func  (type
                     0
                         )
     unreachable
 )
 (func  (type
                     0
                         )
     unreachable
 )
 (func  (type
                     0
                         )
     unreachable
 )
 (func  (type
                     0
                         )
     unreachable
 )
 (func  (type
                     17
                         )
     unreachable
 )
 (func  (type
                     18
                         )
     unreachable
 )
  (func        (type 1) (param i32 i32 i32) (result i32)
    local.get 0
    local.get 0
    local.get 0
    i32.const 0
    i32.const 0
    call 30)
 (func  (type
                     0
                         )
     unreachable
 )
 (func  (type
                     0
                         )
     unreachable
 )
 (func  (type
                     0
                         )
     unreachable
 )
  (func        (type 7) (param i32) (result i32)
    block
      local.get 0
      br_if 0
      i32.const 0
      return
    end
    call 17
    local.get 0
    i32.store
    i32.const +0)
  (table       9 9 funcref)
  (memory       8   8  )
  (global       (mut i32) (i32.const 1    ))
  (export "_start" (func 6))
  (elem       (i32.const 1) func 0 0  12 0  0  0  0  0 )
  (data       (i32.const 500  ) "-+   0X0x\00-0X+0X 0X-0x+0x 0x\00Unknown error\00nan\00inf\00NAN\00INF\00.\00(null)\00unreachable\0a\00hello world\0a\00\00\00\19\00\0b\00\19\19\19\00\00\00\00\05\00\00\00\00\00\00\09\00\00\00\00\0b\00\00\00\00\00\00\00\00\19\00\0a\0a\19\19\19\03\0a\07\00\01\00\09\0b\18\00\00\09\06\0b\00\00\0b\00\06\19\00\00\00\19\19\19\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\0e\00\00\00\00\00\00\00\00\19\00\0b\0d\19\19\19\00\0d\00\00\02\00\09\0e\00\00\00\09\00\0e\00\00\0e\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\0c\00\00\00\00\00\00\00\00\00\00\00\13\00\00\00\00\13\00\00\00\00\09\0c\00\00\00\00\00\0c\00\00\0c\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\10\00\00\00\00\00\00\00\00\00\00\00\0f\00\00\00\04\0f\00\00\00\00\09\10\00\00\00\00\00\10\00\00\10\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\12\00\00\00\00\00\00\00\00\00\00\00\11\00\00\00\00\11\00\00\00\00\09\12\00\00\00\00\00\12\00\00\12\00\00\1a\00\00\00\1a\1a\1a\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\1a\00\00\00\1a\1a\1a\00\00\00\00\00\00\09\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\14\00\00\00\00\00\00\00\00\00\00\00\17\00\00\00\00\17\00\00\00\00\09\14\00\00\00\00\00\14\00\00\14\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\16\00\00\00\00\00\00\00\00\00\00\00\15\00\00\00\00\15\00\00\00\00\09\16\00\00\00\00\00\16\00\00\16\00\000123456789ABCDEF\00\00\a0\02N\00\eb\01\a7\05~\05 \01u\06\18\03\86\04\fa\00\b9\03,\03\fd\05\b7\01\8a\01z\03\bc\04\1e\00\cc\06\a2\00=\03I\03\d7\01\00\04\08\00\93\06\08\01\8f\02\06\02*\06_\02\b7\02\fa\02X\03\d9\04\fd\06\ca\02\bd\05\e1\05\cd\05\dc\02\10\06@\02x\00}\02g\03a\04\ec\00\e5\03\0a\05\d4\00\cc\03>\06O\02v\01\98\03\af\04\00\00D\00\10\02\ae\00\ae\03`\00\fa\01w\04!\05\eb\04+\00`\01A\01\92\00\a9\06\a3\01n\02N\01\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\13\04\00\00\00\00\00\00\00\00*\02\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00'\049\04H\04\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\92\04\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\008\05R\05`\05S\06\00\00\ca\01\00\00\00\00\00\00\00\00\bb\06\db\06\eb\06\10\07+\07;\07P\07Success\00Illegal byte sequence\00Domain error\00Result not representable\00Not a tty\00Permission denied\00Operation not permitted\00No such file or directory\00No such process\00File exists\00Value too large for defined data type\00No space left on device\00Out of memory\00Resource busy\00Interrupted system call\00Resource temporarily unavailable\00Invalid seek\00Cross-device link\00Read-only file system\00Directory not empty\00Connection reset by peer\00Operation timed out\00Connection refused\00Host is down\00Host is unreachable\00Address in use\00Broken pipe\00I/O error\00No such device or address\00Block device required\00No such device\00Not a directory\00Is a directory\00Text file busy\00Exec format error\00Invalid argument\00Argument list too long\00Symbolic link loop\00Filename too long\00Too many open files in system\00No file descriptors available\00Bad file descriptor\00No child process\00Bad address\00File too large\00Too many links\00No locks available\00Resource deadlock would occur\00State not recoverable\00Owner died\00Operation canceled\00Function not implemented\00No message of desired type\00Identifier removed\00Device not a stream\00No data available\00Device timeout\00Out of streams resources\00Link has been severed\00Protocol error\00Bad message\00File descriptor in bad state\00Not a socket\00Destination address required\00Message too large\00Protocol wrong type for socket\00Protocol not available\00Protocol not supported\00Socket type not supported\00Not supported\00Protocol family not supported\00Address family not supported by protocol\00Address not available\00Network is down\00Network unreachable\00Connection reset by network\00Connection aborted\00No buffer space available\00Socket is connected\00Socket not connected\00Cannot send after socket shutdown\00Operation already in progress\00Operation in progress\00Stale file handle\00Remote I/O error\00Quota exceeded\00No medium found\00Wrong medium type\00Multihop attempted\00Required key not available\00Key has expired\00Key has been revoked\00Key was rejected by service\00")
  (data       (i32.const 1    ) "\05\00\00\00\00\00\00\00\00\00\00\00\02\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\03\00\00\00\04\00\00\00\18\0c\01\00\00\04\00\00\00\00\00\00\00\00\00\00\01\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\ff\ff\ff\ff\0a\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\e0\0a\01\00\00 \00\00\05\00\00\00\00\00\00\00\00\00\00\00\07\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\03\00\00\00\08\00\00\00\ec\10\01\00\00\00\00\00\00\00\00\00\00\00\00\00\02\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\ff\ff\ff\ff\ff\ff\ff\ff\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00\00x\0b\01\00"))
