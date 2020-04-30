/**
 * @file BlockOperations.cpp
 * @author Andrea Martelloni (a.martelloni@qmul.ac.uk)
 * @brief 
 * @version 0.1
 * @date 2020-04-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */

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

// Implement wrapper functions/classes here

#endif


}  // namespace BlockOperations
