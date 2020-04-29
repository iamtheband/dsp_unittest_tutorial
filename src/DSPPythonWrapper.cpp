#ifdef PYTHON_WRAPPER

#include <boost/python.hpp>
// Include user libraries heres
#include "EnvTest.hpp"
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

    // Define clases here
    class_<Test::EnvTest>("EnvTest", init<float>())
        .def("TestPrint", &Test::EnvTest::TestPrint)
        .def("TestSum", &Test::EnvTest::TestSum_py)
        .def("TestGain", &Test::EnvTest::TestGain_py);
}

#endif
