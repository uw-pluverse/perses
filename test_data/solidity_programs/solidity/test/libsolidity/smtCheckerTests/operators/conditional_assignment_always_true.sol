pragma experimental SMTChecker;

contract C {
	function f(bool b) public pure {
		require(b);
		uint c = b ? 5 : 1;
		assert(c < 5);
	}
}
// ----
// Warning 6328: (118-131): CHC: Assertion violation happens here.\nCounterexample:\n\nb = true\nc = 5\n\nTransaction trace:\nC.constructor()\nC.f(true)
// Warning 6838: (105-106): BMC: Condition is always true.
