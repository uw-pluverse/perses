__attribute__ (( enable_if(1, "") ))
void f() { }
__attribute__ (( __enable_if__(1, "") ))
void g() { }
__attribute__ (( enable_if(0, "") ))
void h() { }
__attribute__ (( __enable_if__(0, "") ))
void i() { }
#pragma clang system_header
__attribute__ (( enable_if(1, "") ))
void j() { }
__attribute__ (( __enable_if__(1, "") ))
void k() { }
__attribute__ (( enable_if(0, "") ))
void l() { }
__attribute__ (( __enable_if__(0, "") ))
void m() { }
