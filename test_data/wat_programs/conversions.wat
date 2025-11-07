(module
  ;; ------------------------------------------------------------------------
  ;; Integer Extensions (Sign Extension)
  ;; ------------------------------------------------------------------------
  (func (export "i32_extend8_s_func") (param $val i32) (result i32)
    local.get $val
    i32.extend8_s
  )
  (func (export "i32_extend16_s_func") (param $val i32) (result i32)
    local.get $val
    i32.extend16_s
  )
  (func (export "i64_extend8_s_func") (param $val i64) (result i64)
    local.get $val
    i64.extend8_s
  )
  (func (export "i64_extend16_s_func") (param $val i64) (result i64)
    local.get $val
    i64.extend16_s
  )
  (func (export "i64_extend32_s_func") (param $val i64) (result i64)
    local.get $val
    i64.extend32_s
  )

  ;; ------------------------------------------------------------------------
  ;; Integer Truncation (Wrap)
  ;; ------------------------------------------------------------------------
  (func (export "i32_wrap_i64_func") (param $val i64) (result i32)
    local.get $val
    i32.wrap_i64
  )

  ;; ------------------------------------------------------------------------
  ;; Integer to Integer Conversions
  ;; ------------------------------------------------------------------------
  (func (export "i64_extend_i32_s_func") (param $val i32) (result i64)
    local.get $val
    i64.extend_i32_s
  )
  (func (export "i64_extend_i32_u_func") (param $val i32) (result i64)
    local.get $val
    i64.extend_i32_u
  )

  ;; ------------------------------------------------------------------------
  ;; Integer to Floating-Point Conversions
  ;; ------------------------------------------------------------------------
  (func (export "f32_convert_i32_s_func") (param $val i32) (result f32)
    local.get $val
    f32.convert_i32_s
  )
  (func (export "f32_convert_i32_u_func") (param $val i32) (result f32)
    local.get $val
    f32.convert_i32_u
  )
  (func (export "f32_convert_i64_s_func") (param $val i64) (result f32)
    local.get $val
    f32.convert_i64_s
  )
  (func (export "f32_convert_i64_u_func") (param $val i64) (result f32)
    local.get $val
    f32.convert_i64_u
  )
  (func (export "f64_convert_i32_s_func") (param $val i32) (result f64)
    local.get $val
    f64.convert_i32_s
  )
  (func (export "f64_convert_i32_u_func") (param $val i32) (result f64)
    local.get $val
    f64.convert_i32_u
  )
  (func (export "f64_convert_i64_s_func") (param $val i64) (result f64)
    local.get $val
    f64.convert_i64_s
  )
  (func (export "f64_convert_i64_u_func") (param $val i64) (result f64)
    local.get $val
    f64.convert_i64_u
  )

  ;; ------------------------------------------------------------------------
  ;; Floating-Point to Integer Conversions (Truncation)
  ;; These can trap if the input is NaN, infinity, or out of range.
  ;; ------------------------------------------------------------------------
  (func (export "i32_trunc_f32_s_func") (param $val f32) (result i32)
    local.get $val
    i32.trunc_f32_s
  )
  (func (export "i32_trunc_f32_u_func") (param $val f32) (result i32)
    local.get $val
    i32.trunc_f32_u
  )
  (func (export "i32_trunc_f64_s_func") (param $val f64) (result i32)
    local.get $val
    i32.trunc_f64_s
  )
  (func (export "i32_trunc_f64_u_func") (param $val f64) (result i32)
    local.get $val
    i32.trunc_f64_u
  )
  (func (export "i64_trunc_f32_s_func") (param $val f32) (result i64)
    local.get $val
    i64.trunc_f32_s
  )
  (func (export "i64_trunc_f32_u_func") (param $val f32) (result i64)
    local.get $val
    i64.trunc_f32_u
  )
  (func (export "i64_trunc_f64_s_func") (param $val f64) (result i64)
    local.get $val
    i64.trunc_f64_s
  )
  (func (export "i64_trunc_f64_u_func") (param $val f64) (result i64)
    local.get $val
    i64.trunc_f64_u
  )

  ;; ------------------------------------------------------------------------
  ;; Floating-Point to Floating-Point Conversions
  ;; ------------------------------------------------------------------------
  (func (export "f32_demote_f64_func") (param $val f64) (result f32)
    local.get $val
    f32.demote_f64
  )
  (func (export "f64_promote_f32_func") (param $val f32) (result f64)
    local.get $val
    f64.promote_f32
  )

  ;; ------------------------------------------------------------------------
  ;; Reinterpret Conversions (Bit-casts)
  ;; ------------------------------------------------------------------------
  (func (export "i32_reinterpret_f32_func") (param $val i32) (result f32)
    local.get $val
    f32.reinterpret_i32
  )
  (func (export "f32_reinterpret_i32_func") (param $val f32) (result i32)
    local.get $val
    i32.reinterpret_f32
  )
  (func (export "i64_reinterpret_f64_func") (param $val i64) (result f64)
    local.get $val
    f64.reinterpret_i64
  )
  (func (export "f64_reinterpret_i64_func") (param $val f64) (result i64)
    local.get $val
    i64.reinterpret_f64
  )
)