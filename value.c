//
// Created by Felix Zhang on 2024-08-05.
//

#include <stdio.h>

#include "value.h"
#include "memory.h"

void initValueArray(ValueArray *array) {
    array->count = 0;
    array->capacity = 0;
    array->values = NULL;
}

void writeValueArray(ValueArray *array, Value byte) {
    if (array->count + 1 > array->capacity) {
        int old = array->capacity;
        array->capacity = GROW_CAPACITY(old);
        array->values = GROW_ARRAY(Value, array->values, old, array->capacity);
    }

    array->values[array->count++] = byte;
}

void freeValueArray(ValueArray *array) {
    FREE_ARRAY(uint8_t, array->values, array->capacity);
    initValueArray(array);
}

void printValue(Value value) {
    printf("%g", value);
}
