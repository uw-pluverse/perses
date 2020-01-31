




extern int printf (const char *, ...);
extern void exit (int);
extern void abort (void);

extern signed long _COM_CONVf32s (float);
extern unsigned long _COM_CONVf32u (float);
extern float _COM_CONV32sf (signed long);
extern float _COM_CONV32uf (unsigned long);
extern float _COM_ADDf (float, float);
extern float _COM_SUBf (float, float);
extern float _COM_MULf (float, float);
extern float _COM_DIVf (float, float);
extern int _COM_CMPLTf (float, float);
extern int _COM_CMPGTf (float, float);
extern int _COM_CMPLEf (float, float);
extern int _COM_CMPGEf (float, float);
extern int _COM_CMPEQf (float, float);
extern int _COM_CMPNEf (float, float);


extern int _COM_CMPLTd (double, double);
extern int _COM_CMPGTd (double, double);
extern int _COM_CMPLEd (double, double);
extern int _COM_CMPGEd (double, double);
extern int _COM_CMPEQd (double, double);
extern int _COM_CMPNEd (double, double);

extern long long _COM_MUL64 (long long, long long);
extern signed long long _COM_DIV64s (long long, long long);
extern unsigned long long _COM_DIV64u (unsigned long long, unsigned long long);
extern long long _COM_SHLL64 (long long, int);
extern long long _COM_SHLR64 (long long, int);
extern long long _COM_SHAR64 (long long, int);
extern signed long long _COM_CONVf64s (float);
extern unsigned long long _COM_CONVf64u (float);
extern signed long long _COM_CONVd64s (double);
extern unsigned long long _COM_CONVd64u (double);
extern float _COM_CONV64sf (signed long long);
extern float _COM_CONV64uf (unsigned long long);
extern double _COM_CONV64sd (signed long long);
extern double _COM_CONV64ud (unsigned long long);
extern signed long long _COM_MOD64s (long long, long long);
extern unsigned long long _COM_MOD64u (unsigned long long, unsigned long long);
extern int _COM_CMPLT64s (long long, long long);
extern int _COM_CMPLT64u (unsigned long long, unsigned long long);
extern int _COM_CMPGT64s (long long, long long);
extern int _COM_CMPGT64u (unsigned long long, unsigned long long);
extern int _COM_CMPLE64s (long long, long long);
extern int _COM_CMPLE64u (unsigned long long, unsigned long long);
extern int _COM_CMPGE64s (long long, long long);
extern int _COM_CMPGE64u (unsigned long long, unsigned long long);
extern int _COM_CMPEQ64 (long long, long long);
extern int _COM_CMPNE64 (long long, long long);

extern double _COM_ADDd (double, double);
extern double _COM_SUBd (double, double);
extern double _COM_MULd (double, double);
extern double _COM_DIVd (double, double);
extern signed long _COM_CONVd32s (double);
extern unsigned long _COM_CONVd32u (double);
extern double _COM_CONV32sd (signed long);
extern double _COM_CONV32ud (unsigned long);
extern double _COM_CONVfd (float);
extern float _COM_CONVdf (double);
extern double _COM_NEGd (double);
int
main (void)
{




  if (_COM_CONVf32s (-2.0f) != -2) abort ();
  if (_COM_CONVf32u (-2.0f) != (unsigned) -2) abort ();
  if (_COM_CONV32sf (-2) != -2.0f) abort ();
  if (_COM_CONV32uf (2) != 2.0f) abort ();
  if (_COM_ADDf (1.0f, 2.0f) != 3.0f) abort ();
  if (_COM_SUBf (3.0f, 2.0f) != 1.0f) abort ();
  if (_COM_MULf (2.0f, 3.0f) != 6.0f) abort ();
  if (_COM_DIVf (6.0f, 2.0f) != 3.0f) abort ();
  if ( (_COM_CMPLTf (1.0f, 2.0f) != 1) || (_COM_CMPLTf (2.0f, 1.0f) != 0) || (_COM_CMPLTf (1.0f, 1.0f) != 0)) abort ();;
  if ( (_COM_CMPGTf (1.0f, 2.0f) != 0) || (_COM_CMPGTf (2.0f, 1.0f) != 1) || (_COM_CMPGTf (1.0f, 1.0f) != 0)) abort ();;
  if ( (_COM_CMPLEf (1.0f, 2.0f) != 1) || (_COM_CMPLEf (2.0f, 1.0f) != 0) || (_COM_CMPLEf (1.0f, 1.0f) != 1)) abort ();;
  if ( (_COM_CMPGEf (1.0f, 2.0f) != 0) || (_COM_CMPGEf (2.0f, 1.0f) != 1) || (_COM_CMPGEf (1.0f, 1.0f) != 1)) abort ();;
  if ( (_COM_CMPEQf (1.0f, 2.0f) != 0) || (_COM_CMPEQf (2.0f, 1.0f) != 0) || (_COM_CMPEQf (1.0f, 1.0f) != 1)) abort ();;
  if ( (_COM_CMPNEf (1.0f, 2.0f) != 1) || (_COM_CMPNEf (2.0f, 1.0f) != 1) || (_COM_CMPNEf (1.0f, 1.0f) != 0)) abort ();;


  if (_COM_MUL64 (2LL, 4LL) != 8LL) abort ();
  if (_COM_DIV64s (6LL, 3LL) != 2LL) abort ();
  if (_COM_DIV64u (6ULL, 3ULL) != 2ULL) abort ();
  if (_COM_SHLL64 (6LL, 3) != 48LL) abort ();
  if (_COM_SHLR64 (8LL, 2) != 2LL) abort ();
  if (_COM_SHAR64 (-1LL, 2) != -1LL) abort ();
  if (_COM_CONVf64s (-2.0f) != -2LL) abort ();
  if (_COM_CONVf64u (2.0f) != 2ULL) abort ();
  if (_COM_CONVd64s (-2.0) != -2LL) abort ();
  if (_COM_CONVd64u (2.0) != 2ULL) abort ();
  if (_COM_CONV64sf (-2LL) != -2.0f) abort ();
  if (_COM_CONV64uf (2ULL) != 2.0f) abort ();
  if (_COM_CONV64sd (-2LL) != -2.0) abort ();
  if (_COM_CONV64ud (2ULL) != 2.0) abort ();
  if (_COM_MOD64s (4LL, 3LL) != 1LL) abort ();
  if (_COM_MOD64u (4ULL, 3ULL) != 1ULL) abort ();
  if ( (_COM_CMPLT64s (1LL, 2LL) != 1) || (_COM_CMPLT64s (2LL, 1LL) != 0) || (_COM_CMPLT64s (1LL, 1LL) != 0)) abort ();;
  if ( (_COM_CMPLT64u (1ULL, 2ULL) != 1) || (_COM_CMPLT64u (2ULL, 1ULL) != 0) || (_COM_CMPLT64u (1ULL, 1ULL) != 0)) abort ();;
  if ( (_COM_CMPGT64s (1LL, 2LL) != 0) || (_COM_CMPGT64s (2LL, 1LL) != 1) || (_COM_CMPGT64s (1LL, 1LL) != 0)) abort ();;
  if ( (_COM_CMPGT64u (1ULL, 2ULL) != 0) || (_COM_CMPGT64u (2ULL, 1ULL) != 1) || (_COM_CMPGT64u (1ULL, 1ULL) != 0)) abort ();;
  if ( (_COM_CMPLE64s (1LL, 2LL) != 1) || (_COM_CMPLE64s (2LL, 1LL) != 0) || (_COM_CMPLE64s (1LL, 1LL) != 1)) abort ();;
  if ( (_COM_CMPLE64u (1ULL, 2ULL) != 1) || (_COM_CMPLE64u (2ULL, 1ULL) != 0) || (_COM_CMPLE64u (1ULL, 1ULL) != 1)) abort ();;
  if ( (_COM_CMPGE64s (1LL, 2LL) != 0) || (_COM_CMPGE64s (2LL, 1LL) != 1) || (_COM_CMPGE64s (1LL, 1LL) != 1)) abort ();;
  if ( (_COM_CMPGE64u (1ULL, 2ULL) != 0) || (_COM_CMPGE64u (2ULL, 1ULL) != 1) || (_COM_CMPGE64u (1ULL, 1ULL) != 1)) abort ();;
  if ( (_COM_CMPEQ64 (1LL, 2LL) != 0) || (_COM_CMPEQ64 (2LL, 1LL) != 0) || (_COM_CMPEQ64 (1LL, 1LL) != 1)) abort ();;
  if ( (_COM_CMPNE64 (1LL, 2LL) != 1) || (_COM_CMPNE64 (2LL, 1LL) != 1) || (_COM_CMPNE64 (1LL, 1LL) != 0)) abort ();;


  if (_COM_ADDd (1.0, 2.0) != 3.0) abort ();
  if (_COM_SUBd (3.0, 2.0) != 1.0) abort ();
  if (_COM_MULd (2.0, 3.0) != 6.0) abort ();
  if (_COM_DIVd (6.0, 2.0) != 3.0) abort ();
  if (_COM_CONVd32s (-2.0) != -2) abort ();
  if (_COM_CONVd32u (-2.0) != (unsigned) -2) abort ();
  if (_COM_CONV32sd (-2) != -2.0) abort ();
  if (_COM_CONV32ud (2) != 2.0) abort ();
  if (_COM_CONVfd (2.0f) != 2.0) abort ();
  if (_COM_CONVdf (2.0) != 2.0f) abort ();
  if (_COM_NEGd (-2.0) != 2.0) abort ();
  if ( (_COM_CMPLTd (1.0, 2.0) != 1) || (_COM_CMPLTd (2.0, 1.0) != 0) || (_COM_CMPLTd (1.0, 1.0) != 0)) abort ();;
  if ( (_COM_CMPGTd (1.0, 2.0) != 0) || (_COM_CMPGTd (2.0, 1.0) != 1) || (_COM_CMPGTd (1.0, 1.0) != 0)) abort ();;
  if ( (_COM_CMPLEd (1.0, 2.0) != 1) || (_COM_CMPLEd (2.0, 1.0) != 0) || (_COM_CMPLEd (1.0, 1.0) != 1)) abort ();;
  if ( (_COM_CMPGEd (1.0, 2.0) != 0) || (_COM_CMPGEd (2.0, 1.0) != 1) || (_COM_CMPGEd (1.0, 1.0) != 1)) abort ();;
  if ( (_COM_CMPEQd (1.0, 2.0) != 0) || (_COM_CMPEQd (2.0, 1.0) != 0) || (_COM_CMPEQd (1.0, 1.0) != 1)) abort ();;
  if ( (_COM_CMPNEd (1.0, 2.0) != 1) || (_COM_CMPNEd (2.0, 1.0) != 1) || (_COM_CMPNEd (1.0, 1.0) != 0)) abort ();;




  exit (0);
}
