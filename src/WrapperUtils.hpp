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
};

#endif  // PYTHON_WRAPPER

#endif  // __WRAPPER_UTILS_HPP__
