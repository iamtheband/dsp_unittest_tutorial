#ifdef PYTHON_WRAPPER

#include <boost/python.hpp>
#include "EnvTest.hpp"


BOOST_PYTHON_MODULE(DSPPythonWrapper)
{
    using namespace boost::python;

    class_<Test::EnvTest>("EnvTest", init<float>())
        .def("TestPrint", &Test::EnvTest::TestPrint)
        .def("TestSum", &Test::EnvTest::TestSum_py)
        .def("TestGain", &Test::EnvTest::TestGain_py);
}

#endif
