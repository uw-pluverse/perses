package com.cogvio.time;

import java.time.Clock;
import java.time.Instant;
import java.time.ZoneId;

public final class MutableClock extends Clock {

    private Instant instant;

    private ZoneId zone;

    private MutableClock(final Instant instant, final ZoneId zone) {
        this.setZone(zone);
        this.setInstant(instant);
    }

    public void setInstant(final Instant instant) {
        throw new java.lang.Error();
    }

    public void setZone(final ZoneId zone) {
        throw new java.lang.Error();
    }

    public ZoneId getZone() {
        throw new java.lang.Error();
    }

    public MutableClock withZone(final ZoneId newZone) {
        throw new java.lang.Error();
    }

    public Instant instant() {
        throw new java.lang.Error();
    }
}
