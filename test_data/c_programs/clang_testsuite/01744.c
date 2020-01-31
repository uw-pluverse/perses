void foo()
{
 (void) L'ab';
#pragma clang diagnostic warning "-Weverything"
 (void) L'cd';
#pragma clang diagnostic ignored "-Weverything"
 (void) L'ef';
#pragma clang diagnostic warning "-Weverything"
 (void) L'gh';
#pragma clang diagnostic error "-Weverything"
 (void) L'ij';
}
