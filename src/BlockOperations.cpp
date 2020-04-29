#include "BlockOperations.hpp"

namespace BlockOperations {

void SumTwoArrays(float *array1,
    float *array2,
    float *array_out,
    unsigned int n_samples) {
    
    while (n_samples-- > 0) {
        *array_out++ = *array1++ + *array2++;
    }
}

MonoGain::MonoGain(float gain) :
    gain_(gain) {}

void MonoGain::Process(float *array,
        float *array_out,
        unsigned int n_samples) {
    while (n_samples-- > 0) {
        *array_out++ = *array++ * gain_;
    }
}


#ifdef PYTHON_WRAPPER

np::ndarray SumTwoArrays_py(np::ndarray array1, np::ndarray array2) {
    WrapperUtils::BufferSize size = WrapperUtils::CheckAndGetSize(
        array1);

    np::ndarray result = np::zeros(1, array1.get_shape(), array1.get_dtype());
    return result;
}

#endif


}
