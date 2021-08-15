#include "mylib.h"

namespace MyLib {

    void init_array(float* const array, size_t const array_size)
    {
        for (int i = 0; i < array_size; i++) {
            array[i] = (i % 2 == 0) ? i : -i;
        }
    }

    void print_array(float const* const array, size_t const array_size)
    {
        for (size_t i = 0; i < array_size; i++) {
            std::cout << array[i] << ' ';
        }
        std::cout << '\n';
    }

    void fill_array_structure(float const* const array, size_t const array_size, ArrayStructure* const array_structure)
    {
        for (size_t i = 0; i < array_size; i++) {
            if (array[i] < 0) {
                array_structure->neg_nums++;
            }
            else {
                array_structure->pos_nums++;
            }
        }
    }

}