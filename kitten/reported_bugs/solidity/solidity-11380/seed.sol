pragma experimental SMTChecker;

abstract contract A {
 bool s;

 function f() public view mod {
  assert(s);
 }
 modifier mod() virtual;
}

contract B is A {
 modifier mod() virtual override {
  s = false;
  _;
 }
}

contract C is B {
 modifier mod() override {
  s = true;
  _;
 }
}
