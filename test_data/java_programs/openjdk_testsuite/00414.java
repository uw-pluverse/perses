



import java.util.Stack;
class Bug {
    void f() {
        Stack<?> stack = null;
        String o = stack.pop();
    }
}
