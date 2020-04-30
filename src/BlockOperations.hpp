/**
 * @file BlockOperations.hpp
 * @author Andrea Martelloni (a.martelloni@qmul.ac.uk)
 * @brief 
 * @version 0.1
 * @date 2020-04-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */

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

/**
 * @brief Sum two arrays together in a third array.
 * 
 * @param array1 
 * @param array2 
 * @param array_out 
 * @param n_samples 
 */
void SumTwoArrays(float *array1,
    float *array2,
    float *array_out,
    unsigned int n_samples);


/**
 * @brief Applies a fixed, stored gain to a mono signal.
 * 
 */
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


#endif  // __BLOCK_OPERATIONS_HPP__
