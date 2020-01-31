#pragma clang attribute pop
#pragma clang attribute push (__attribute__((annotate)), apply_to = function)
#pragma clang attribute pop
#pragma clang attribute push (__attribute__((annotate)), apply_to = function)
void test5_begin();
void test5_1();
#pragma clang attribute push (__attribute__((annotate())), apply_to = function)
void test5_2();
#pragma clang attribute push (__attribute__((annotate("hello", "world"))), apply_to = function)
void test5_3();
#pragma clang attribute pop
#pragma clang attribute pop
#pragma clang attribute pop
#pragma clang attribute push (__attribute__((optnone)), apply_to = function)
__attribute__((always_inline)) void optnone1() { }
void optnone2() { }
__attribute__((always_inline)) void optnone3() { }
#pragma clang attribute pop
#pragma clang attribute push ([[]], apply_to = function)
#pragma clang attribute pop
#pragma clang attribute push (__attribute__((annotate("func"))), apply_to = function)
void function();
