#ifndef __WRAPPER_UTILS_HPP__
#define __WRAPPER_UTILS_HPP__

#ifdef PYTHON_WRAPPER

#include <boost/python.hpp>
#include <boost/python/numpy.hpp>
namespace p = boost::python;
namespace np = boost::python::numpy;


class WrapperUtils {
 public:
    struct BufferSize {
        unsigned int n_channels;
        unsigned int n_samples;
    };
    static BufferSize CheckAndGetSize(np::ndarray &buffer_main);
    static BufferSize CheckAndGetSize(np::ndarray &buffer_main, np::ndarray &buffer_other);
    template<typename ... Args>
    static BufferSize CheckAndGetSize(np::ndarray &buffer_main, np::ndarray &buffer_other,
            Args ... args);
    template<typename CPP_TYPE>
    static np::ndarray CheckAndConvertType(np::ndarray &buffer);
    template<typename CPP_TYPE>
    static np::ndarray AllocateBuffer(BufferSize size);
    template<typename CPP_TYPE>
    static inline CPP_TYPE* GetData(np::ndarray &buffer);
};


template<typename CPP_TYPE>
np::ndarray WrapperUtils::CheckAndConvertType(np::ndarray &buffer) {
    if (buffer.get_dtype() == np::dtype::get_builtin<CPP_TYPE>()) {
        return buffer;
    } else {
        return buffer.astype(np::dtype::get_builtin<CPP_TYPE>());
    }
}


template<typename CPP_TYPE>
np::ndarray WrapperUtils::AllocateBuffer(BufferSize size) {
    p::tuple sizetuple;
    if (1 == size.n_channels) {
        // 1-d array
        sizetuple = p::make_tuple(size.n_samples);
    } else {
        // Interleaved array
        sizetuple = p::make_tuple(size.n_samples, size.n_channels);
    }
    return np::zeros(sizetuple, np::dtype::get_builtin<CPP_TYPE>());
}


template<typename CPP_TYPE>
CPP_TYPE* WrapperUtils::GetData(np::ndarray &buffer) {
    return reinterpret_cast<CPP_TYPE *>(buffer.get_data());
}


#endif  // PYTHON_WRAPPER

#endif  // __WRAPPER_UTILS_HPP__
