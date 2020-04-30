#include "BlockOperations.hpp"
#include <iostream>

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

void MonoGain::SetGain(float gain) {
    gain_ = gain;
}

void MonoGain::Process(float *array,
        float *array_out,
        unsigned int n_samples) {
    while (n_samples-- > 0) {
        *array_out++ = *array++ * gain_;
    }
}


#ifdef PYTHON_WRAPPER

np::ndarray SumTwoArrays_py(np::ndarray array1, np::ndarray array2) {
    WrapperUtils::BufferSize size = WrapperUtils::CheckAndGetSize(array1, array2);
    np::ndarray array1_float = WrapperUtils::CheckAndConvertType<float>(array1);
    np::ndarray array2_float = WrapperUtils::CheckAndConvertType<float>(array2);
    np::ndarray result = WrapperUtils::AllocateArray<float>(size);

    SumTwoArrays(reinterpret_cast<float *>(array1_float.get_data()),
        reinterpret_cast<float *>(array2_float.get_data()),
        reinterpret_cast<float *>(result.get_data()),
        size.n_samples);

    return result;
}

np::ndarray MonoGain_py::Process_py(np::ndarray array) {
    WrapperUtils::BufferSize size = WrapperUtils::CheckAndGetSize(array);
    np::ndarray array_float = WrapperUtils::CheckAndConvertType<float>(array);
    np::ndarray result = WrapperUtils::AllocateArray<float>(size);

    Process(reinterpret_cast<float *>(array_float.get_data()),
        reinterpret_cast<float *>(result.get_data()), size.n_samples);

    return result;
}


#endif


}  // namespace BlockOperations
