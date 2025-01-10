contract C {
    function f() external view {}
 function test(address a) external view returns (bool status) {

  (status,) = a.staticcall{gas: 42}("");
  this.f{gas: 42}();
 }
}
