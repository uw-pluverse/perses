typedef const struct __CFAllocator * CFAllocatorRef;
typedef const struct __CFArray * CFArrayRef;
typedef const struct __CFDictionary * CFDictionaryRef;
typedef const struct __CFSet * CFSetRef;
extern const CFAllocatorRef kCFAllocatorDefault;
CFArrayRef CFArrayCreate(CFAllocatorRef);
CFDictionaryRef CFDictionaryCreate(CFAllocatorRef);
CFSetRef CFSetCreate(CFAllocatorRef);
void testNoCrash() {
  (void)CFArrayCreate(kCFAllocatorDefault);
  (void)CFDictionaryCreate(kCFAllocatorDefault);
  (void)CFSetCreate(kCFAllocatorDefault);
}
