

struct timespec
  {
    long int tv_sec;
    long int tv_nsec;
  };

struct itimerspec
  {
    struct timespec it_interval;
    struct timespec it_value;
  };

struct timespec base_var8;
struct itimerspec *base_var9;


struct gstruct_head_ordy_decl_not;
struct gstruct_head_ordy_defn_not { int field_head_ordy_defn_not; };

struct gstruct_head_ordy_decl_ref_head;
struct gstruct_head_ordy_defn_ref_head { int field_head_ordy_defn_ref_head; };
struct gstruct_head_ordy_defn_ptr_head { int field_head_ordy_defn_ptr_head; };
struct gstruct_head_ordy_defn_fld_head { int field_head_ordy_defn_fld_head; };
struct gstruct_head_ordy_defn_var_head {
    struct gstruct_head_ordy_decl_ref_head *field_head_ordy_defn_var_head_inc;
    struct gstruct_head_ordy_defn_ref_head *field_head_ordy_defn_var_head_ref;
    struct gstruct_head_ordy_defn_ptr_head *field_head_ordy_defn_var_head_ptr;
    struct gstruct_head_ordy_defn_fld_head field_head_ordy_defn_var_head_fld;
};
extern struct gstruct_head_ordy_defn_var_head head_var1;

struct gstruct_head_ordy_decl_ref_base;
struct gstruct_head_ordy_defn_ref_base { int field_head_ordy_defn_ref_base; };
struct gstruct_head_ordy_defn_ptr_base { int field_head_ordy_defn_ptr_base; };
struct gstruct_head_ordy_defn_fld_base { int field_head_ordy_defn_fld_base; };
struct gstruct_head_ordy_defn_var_base { int field_head_ordy_defn_var_base; };

inline int head_function() {
    return 0
+ head_var1.field_head_ordy_defn_var_head_ptr->field_head_ordy_defn_ptr_head
+ head_var1.field_head_ordy_defn_var_head_fld.field_head_ordy_defn_fld_head
;
}

struct gstruct_base_ordy_decl_not;
struct gstruct_base_ordy_defn_not { int field_base_ordy_defn_not; };

struct gstruct_base_ordy_decl_ref_base;
struct gstruct_base_ordy_defn_ref_base { int field_base_ordy_defn_ref_base; };
struct gstruct_base_ordy_defn_ptr_base { int field_base_ordy_defn_ptr_base; };
struct gstruct_base_ordy_defn_fld_base { int field_base_ordy_defn_fld_base; };
struct gstruct_base_ordy_defn_var_base {
    struct gstruct_head_ordy_decl_ref_base *field1_base_ordy_defn_var_base_inc;
    struct gstruct_head_ordy_defn_ref_base *field1_base_ordy_defn_var_base_ref;
    struct gstruct_head_ordy_defn_ptr_base *field1_base_ordy_defn_var_base_ptr;
    struct gstruct_head_ordy_defn_fld_base field1_base_ordy_defn_var_base_fld;
    struct gstruct_base_ordy_decl_ref_base *field2_base_ordy_defn_var_base_inc;
    struct gstruct_base_ordy_defn_ref_base *field2_base_ordy_defn_var_base_ref;
    struct gstruct_base_ordy_defn_ptr_base *field2_base_ordy_defn_var_base_ptr;
    struct gstruct_base_ordy_defn_fld_base field2_base_ordy_defn_var_base_fld;
};

struct gstruct_head_ordy_defn_var_base base_var1;
struct gstruct_base_ordy_defn_var_base base_var2;

int base_function() {
    return 0
+ base_var1.field_head_ordy_defn_var_base
+ base_var2.field1_base_ordy_defn_var_base_ptr->field_head_ordy_defn_ptr_base
+ base_var2.field1_base_ordy_defn_var_base_fld.field_head_ordy_defn_fld_base
+ base_var2.field2_base_ordy_defn_var_base_ptr->field_base_ordy_defn_ptr_base
+ base_var2.field2_base_ordy_defn_var_base_fld.field_base_ordy_defn_fld_base
;
}
