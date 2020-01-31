typedef int INT1 __attribute__((deprecated("Please avoid INT1")));
typedef INT1 INT2 __attribute__ ((__deprecated__("Please avoid INT2")));
typedef INT1 INT1a;
typedef INT1 INT1b __attribute__ ((deprecated("Please avoid INT1b")));
INT1 should_be_unavailable;
INT1a should_not_be_deprecated;
INT1 f1(void) __attribute__ ((deprecated("Please avoid f1")));
INT1 f2(void);
typedef enum {red, green, blue} Color __attribute__((deprecated("Please avoid Color")));
Color c1;
int g1;
int g2 __attribute__ ((deprecated("Please avoid g2")));
int func1()
{
   int (*pf)() = f1;
   int i = f2();
   return g1 + g2;
}
