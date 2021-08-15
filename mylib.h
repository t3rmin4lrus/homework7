#pragma once

#include <iostream>

namespace MyLib {

    struct ArrayStructure {
        size_t pos_nums;
        size_t neg_nums;
    };

    void init_array(float* const array, size_t const array_size);
    void print_array(float const* const array, size_t const array_size);
    void fill_array_structure(float const* const array, size_t const array_size, ArrayStructure* const array_structure);

}