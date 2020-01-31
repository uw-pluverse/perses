



public
class DeclarationStatementInline {
        {
            class Foo {
                Foo() {
                    System.out.println("Hello");
                }
            }
            new Foo();
        }

    DeclarationStatementInline() {
        System.out.println("Constructor one");
    }

    DeclarationStatementInline(int i) {
        System.out.println("Constructor two");
    }

    public static void main() {
        new DeclarationStatementInline();
    }
}
