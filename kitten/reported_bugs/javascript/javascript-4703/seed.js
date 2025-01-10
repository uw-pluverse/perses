














function testcase() {

        function _13_0_10_fun() {
            function _13_0_10_inner() {
                "use strict";
                eval("eval = 42;");
            }
            _13_0_10_inner();
        };
        try {
            _13_0_10_fun();
            return false;
        } catch (e) {
            return e instanceof SyntaxError;
        }
    }
runTestCase(testcase);
