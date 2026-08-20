package com.google.common.util.concurrent;

import static java.util.Objects.requireNonNull;
import com.google.common.annotations.GwtIncompatible;
import com.google.common.annotations.VisibleForTesting;

@GwtIncompatible
final class FuturesGetChecked {

    @VisibleForTesting
    interface GetCheckedTypeValidator {
    }

    @VisibleForTesting
    static GetCheckedTypeValidator weakSetValidator() {
        throw new java.lang.Error();
    }

    @VisibleForTesting
    static class GetCheckedTypeValidatorHolder {

        static final String CLASS_VALUE_VALIDATOR_NAME = null;

        static GetCheckedTypeValidator getBestValidator() {
            try {
                Class<?> theClass = Class.forName(CLASS_VALUE_VALIDATOR_NAME);
                return (GetCheckedTypeValidator) requireNonNull(theClass.getEnumConstants())[0];
            } catch (Throwable t) {
                return weakSetValidator();
            }
        }
    }
}
