



package InnerInterface2;

class Builder<Community> {

    class Produces<B extends AbstractBuilder> {}

    interface AbstractBuilder {}

}

class MyBuilder extends Builder<String> {
    
    Produces<HTMLConsumer> p0;
    Produces<MyABuilder> p1;
}

class MyABuilder implements HTMLConsumer {
}

interface HTMLConsumer extends Builder.AbstractBuilder {}
