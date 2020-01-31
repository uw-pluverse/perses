

class LocalClasses_2 {

    void foo() {
        class Local { }
        {
            class Local { }                     
        }
    }

    void bar() {

        class Local { }

        class Baz {
            void quux() {
                class Local { }                 
            }
        }

        class Quux {
            void baz() {
                class Random {
                    void quem() {
                        class Local { }         
                    }
                }
            }
        }
    }
}
