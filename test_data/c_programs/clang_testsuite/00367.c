#pragma pack(push, 2)
typedef union command {
  void *windowRef;
  struct menu {
    void *menuRef;
    unsigned char menuItemIndex;
  } menu;
} command;
command c;
