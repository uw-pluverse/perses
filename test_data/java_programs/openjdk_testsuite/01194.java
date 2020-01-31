




class PotentialLambdaFound {

    interface SAM {
        void m();
    }

    SAM s = new SAM() { public void m() { } };
}
