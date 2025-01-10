package p1 ;
class c1 ;
endclass
typedef c1 c3 ;
endpackage
package p3 ;
class c33 ;
endclass
endpackage
package p2 ;
import p1 :: * ; wire [ X : 0 ] varwidth = ( FIVE == 5 ) ? TWO : 0 ;
endpackage
