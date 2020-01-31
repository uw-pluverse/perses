#pragma GCC diagnostic warning "-Wundef"
#pragma GCC diagnostic ignored "-Wun" "def"
#pragma GCC diagnostic error "-Wundef"
#pragma GCC diagnostic foo "-Wundef"
#pragma GCC diagnostic error 42
#pragma GCC diagnostic error "-Wundef" 42
#pragma GCC diagnostic error "invalid-name"
#pragma GCC diagnostic error "-Winvalid-name"
void ppo(){}
#pragma clang diagnostic warning "-Weverything"
void ppp(){}
#pragma clang diagnostic ignored "-Weverything"
void ppq(){}
#pragma clang diagnostic error "-Weverything"
void ppr(){}
#pragma clang diagnostic warning "-Weverything"
void pps(){}
