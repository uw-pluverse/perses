

__attribute__((__simd__("bug")))
int simd_attr (void) { return 0; }

__attribute__((__simd__("notinbranch", "inbranch")))
int simd_attr2 (void) { return 0; }
