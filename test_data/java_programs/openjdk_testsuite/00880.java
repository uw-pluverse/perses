



package enum_init_;

import java.util.Arrays;

import java.lang.annotation.*;

@NestedEnum(getVehicles=NestedEnum.Vehicles.sports)
class AnnotationDriverTest {}

@Retention(RetentionPolicy.RUNTIME)
@interface NestedEnum {
    enum Vehicles {
        sports {
        };
    }
    Vehicles getVehicles();
}
