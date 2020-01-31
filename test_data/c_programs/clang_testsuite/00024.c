int printf(const char *restrict,...);
typedef unsigned long UInt32;
typedef signed long SInt32;
typedef SInt32 OSStatus;
typedef unsigned char Boolean;
enum { noErr = 0};
typedef const void *CFTypeRef;
typedef const struct __CFString *CFStringRef;
typedef const struct __CFAllocator *CFAllocatorRef;
extern void CFRelease(CFTypeRef cf);
typedef UInt32 CFStringEncoding;
enum { kCFStringEncodingMacRoman = 0, kCFStringEncodingWindowsLatin1 = 0x0500,
       kCFStringEncodingISOLatin1 = 0x0201, kCFStringEncodingNextStepLatin = 0x0B01,
       kCFStringEncodingASCII = 0x0600, kCFStringEncodingUnicode = 0x0100,
       kCFStringEncodingUTF8 = 0x08000100, kCFStringEncodingNonLossyASCII = 0x0BFF,
       kCFStringEncodingUTF16 = 0x0100, kCFStringEncodingUTF16BE = 0x10000100,
       kCFStringEncodingUTF16LE = 0x14000100, kCFStringEncodingUTF32 = 0x0c000100,
       kCFStringEncodingUTF32BE = 0x18000100, kCFStringEncodingUTF32LE = 0x1c000100};
extern CFStringRef CFStringCreateWithCString(CFAllocatorRef alloc, const char *cStr, CFStringEncoding encoding);
enum { memROZWarn = -99, memROZError = -99, memROZErr = -99, memFullErr = -108,
       nilHandleErr = -109, memWZErr = -111, memPurErr = -112, memAdrErr = -110,
       memAZErr = -113, memPCErr = -114, memBCErr = -115, memSCErr = -116, memLockedErr = -117};
void DebugStop(const char *format,...);
void DebugTraceIf(unsigned int condition, const char *format,...);
Boolean DebugDisplayOSStatusMsg(OSStatus status, const char *statusStr, const char *fileName, unsigned long lineNumber);
void DebugStop(const char *format,...);
int main(int argc, char *argv[]) {
  CFStringRef cfString;
  OSStatus status = noErr;
  cfString = CFStringCreateWithCString(0, "hello", kCFStringEncodingUTF8);
  if (!(cfString != 0)) { DebugStop("Assertion failure: %s [File: %s, Line: %lu]", "cfString != 0", "/tmp/llvm-builder/llvm-source-trunk/tools/clang/test/Analysis/cfref_rdar6080742.c", 51); return memFullErr; }
    printf("cfstring %p\n", cfString);
  Exit:
  CFRelease(cfString);
  return 0;
}
