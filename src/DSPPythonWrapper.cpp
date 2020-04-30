/**
 * @file DSPPythonWrapper.cpp
 * @author Andrea Martelloni (a.martelloni@qmul.ac.uk)
 * @brief 
 * @version 0.1
 * @date 2020-04-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifdef PYTHON_WRAPPER

#include <boost/python.hpp>
// Include user libraries here
#include "BlockOperations.hpp"

using namespace boost::python;
namespace np = boost::python::numpy;


BOOST_PYTHON_MODULE(DSPPythonWrapper)
{
    // Boilerplate to initialise the runtime
    Py_Initialize();
    np::initialize();

    // Define functions here
    def("SumTwoArrays", &BlockOperations::SumTwoArrays_py);

    // Define classes here
    class_<BlockOperations::MonoGain_py>("MonoGain", init<float>())
        .def("Process", &BlockOperations::MonoGain_py::Process_py)
        .def("SetGain", &BlockOperations::MonoGain_py::SetGain);
}

#endif
