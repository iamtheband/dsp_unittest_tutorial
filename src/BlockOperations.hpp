#ifndef __BLOCK_OPERATIONS_HPP__
#define __BLOCK_OPERATIONS_HPP__


#ifdef PYTHON_WRAPPER

#include <boost/python.hpp>
#include <boost/python/numpy.hpp>
#include "WrapperUtils.hpp"

namespace p = boost::python;
namespace np = boost::python::numpy;

#endif  // PYTHON_WRAPPER


namespace BlockOperations {

void SumTwoArrays(float *array1,
    float *array2,
    float *array_out,
    unsigned int n_samples);

class MonoGain {
 public:
    MonoGain(float gain);
    void Process(float *array,
        float *array_out,
        unsigned int n_samples);
    void SetGain(float gain);

 private:
    float gain_;
};

#ifdef PYTHON_WRAPPER

np::ndarray SumTwoArrays_py(np::ndarray array1, np::ndarray array2);

class MonoGain_py : public MonoGain {
 public:
    MonoGain_py(float gain) : MonoGain(gain) {}
    np::ndarray Process_py(np::ndarray array);
};

#endif

}  // namespace BlockOperations


#endif  // __ARRAY_OPERATIONS_HPP__
