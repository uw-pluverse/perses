package com.github.benmanes.caffeine.cache;

public enum RemovalCause {

    COLLECTED {

        public boolean wasEvicted() {
            return true;
        }
    }
    , SIZE {

        public boolean wasEvicted() {
            return true;
        }
    }

}
