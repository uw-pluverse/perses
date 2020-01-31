





void foo (void) __attribute__ ((target ("custom-fcmpnes=226,custom-fcmpeqs=227")));
void foo (void) __attribute__ ((target ("custom-fcmpnes =226 ,custom-fcmpeqs=227")));
void foo (void) __attribute__ ((target ("custom-fcmpnes= 226, custom-fcmpeqs=227")));
void foo (void) __attribute__ ((target (" custom-fcmpnes=226 , custom-fcmpeqs = 227")));
void foo (void) __attribute__ ((target (" custom-fcmpnes=226 ,custom-fcmpeqs =227 ")));


