_Complex float x = { 1.0f, 1.0f/0.0f };
_Complex float f(float x, float y) { _Complex float z = { x, y }; return z; }
_Complex float f2(float x, float y) { return (_Complex float){ x, y }; }
