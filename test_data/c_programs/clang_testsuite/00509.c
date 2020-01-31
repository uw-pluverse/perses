typedef struct _attrs {
        unsigned file_attributes;
        unsigned char filename_length;
} __attribute__((__packed__)) attrs;
typedef union _attr_union {
  attrs file_attrs;
  unsigned owner_id;
} __attribute__((__packed__)) attr_union;
attr_union u;
