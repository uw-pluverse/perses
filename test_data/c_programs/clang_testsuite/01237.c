typedef unsigned int v2u __attribute__ ((ext_vector_type(2)));
typedef int v2s __attribute__ ((ext_vector_type(2)));
typedef float v2f __attribute__ ((ext_vector_type(2)));
void test1(v2u v2ua, v2s v2sa, v2f v2fa) {
  (void)(v2ua & v2ua);
  (void)(v2fa & v2fa);
  (void)(~v2ua);
  (void)(~v2fa);
  v2sa = (v2ua==v2sa);
  int array1[v2ua];
  int array2[17];
  (void)(array2[v2ua]);
  v2u *v2u_ptr = 0;
  v2s *v2s_ptr;
}
