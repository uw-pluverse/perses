parser grammar JacksonParser;

tokens {
    START_OBJECT,
    END_OBJECT,
    START_ARRAY,
    END_ARRAY,
    FIELD_NAME,
    VALUE_EMBEDDED_OBJECT,
    VALUE_STRING,
    VALUE_NUMBER_INT,
    VALUE_NUMBER_FLOAT,
    VALUE_TRUE,
    VALUE_FALSE,
    VALUE_NULL
}

start
    : value EOF
    ;

value
    : object
    | array
    | VALUE_EMBEDDED_OBJECT
    | VALUE_STRING
    | VALUE_NUMBER_INT
    | VALUE_NUMBER_FLOAT
    | VALUE_TRUE
    | VALUE_FALSE
    | VALUE_NULL
    ;

object
    : START_OBJECT (FIELD_NAME value)*  END_OBJECT
    ;

array
    : START_ARRAY value* END_ARRAY
    ;