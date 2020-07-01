
// default includes
#include "Global/Macros.h"
CLANG_DIAG_OFF(mismatched-tags)
GCC_DIAG_OFF(unused-parameter)
GCC_DIAG_OFF(missing-field-initializers)
GCC_DIAG_OFF(missing-declarations)
GCC_DIAG_OFF(uninitialized)
GCC_DIAG_UNUSED_LOCAL_TYPEDEFS_OFF
#include <shiboken.h> // produces many warnings
#ifndef QT_NO_VERSION_TAGGING
#  define QT_NO_VERSION_TAGGING
#endif
#include <QDebug>
#include <pysidesignal.h>
#include <pysideproperty.h>
#include <pyside.h>
#include <destroylistener.h>
#include <qapp_macro.h>
#include <typeinfo>

// module include
#include "natronengine_python.h"

// main header
#include "natron_python_exprutils_wrapper.h"

// inner classes

// Extra includes
#include <PyParameter.h>
#include <vector>


#include <cctype>
#include <cstring>

QT_WARNING_DISABLE_DEPRECATED
using namespace Natron;



template <class T>
static const char *typeNameOf(const T &t)
{
    const char *typeName =  typeid(t).name();
    auto size = std::strlen(typeName);
#if defined(Q_CC_MSVC) // MSVC: "class QPaintDevice * __ptr64"
    if (auto lastStar = strchr(typeName, '*')) {
        // MSVC: "class QPaintDevice * __ptr64"
        while (*--lastStar == ' ') {
        }
        size = lastStar - typeName + 1;
    }
#else // g++, Clang: "QPaintDevice *" -> "P12QPaintDevice"
    if (size > 2 && typeName[0] == 'P' && std::isdigit(typeName[1])) {
        ++typeName;
        --size;
    }
#endif
    char *result = new char[size + 1];
    result[size] = '\0';
    memcpy(result, typeName, size);
    return result;
}


// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_Natron_Python_ExprUtils_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::Natron::Python::ExprUtils >()))
        return -1;

    ::Natron::Python::ExprUtils* cptr{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // ExprUtils()
            cptr = new ::Natron::Python::ExprUtils();
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::Natron::Python::ExprUtils >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    if (Shiboken::BindingManager::instance().hasWrapper(cptr)) {
        Shiboken::BindingManager::instance().releaseWrapper(Shiboken::BindingManager::instance().retrieveWrapper(cptr));
    }
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_Natron_Python_ExprUtilsFunc_boxstep(PyObject* self, PyObject* args)
{
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "boxstep", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: static ExprUtils::boxstep(double,double)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))) {
        overloadId = 0; // boxstep(double,double)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ExprUtilsFunc_boxstep_TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        double cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // boxstep(double,double)
            double cppResult = ::Natron::Python::ExprUtils::boxstep(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ExprUtilsFunc_boxstep_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ExprUtils.boxstep");
        return {};
}

static PyObject* Sbk_Natron_Python_ExprUtilsFunc_ccellnoise(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: static ExprUtils::ccellnoise(Natron::Python::Double3DTuple)
    if (true) {
        overloadId = 0; // ccellnoise(Natron::Python::Double3DTuple)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ExprUtilsFunc_ccellnoise_TypeError;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // ccellnoise(Natron::Python::Double3DTuple)
            // Begin code injection

            int tupleSize = PyTuple_GET_SIZE(pyArg);
            if (tupleSize != 3) {
            PyErr_SetString(PyExc_TypeError, "the tuple must have 3 items.");
            return 0;
            }
            double x1;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArg, 0), &(x1));
            double x2;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArg, 1), &(x2));
            double x3;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArg, 2), &(x3));
            Natron::Python::Double3DTuple p = {x1, x2, x3};
            Natron::Python::Double3DTuple ret = Natron::Python::ExprUtils::ccellnoise(p);
            pyResult = PyTuple_New(3);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret.x));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret.y));
            PyTuple_SET_ITEM(pyResult, 2, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret.z));
            return pyResult;

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ExprUtilsFunc_ccellnoise_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.ExprUtils.ccellnoise");
        return {};
}

static PyObject* Sbk_Natron_Python_ExprUtilsFunc_cellnoise(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: static ExprUtils::cellnoise(Natron::Python::Double3DTuple)
    if (true) {
        overloadId = 0; // cellnoise(Natron::Python::Double3DTuple)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ExprUtilsFunc_cellnoise_TypeError;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // cellnoise(Natron::Python::Double3DTuple)
            // Begin code injection

            int tupleSize = PyTuple_GET_SIZE(pyArg);
            if (tupleSize != 3) {
            PyErr_SetString(PyExc_TypeError, "the tuple must have 3 items.");
            return 0;
            }
            double x1;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArg, 0), &(x1));
            double x2;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArg, 1), &(x2));
            double x3;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArg, 2), &(x3));
            Natron::Python::Double3DTuple p = {x1, x2, x3};
            double ret = Natron::Python::ExprUtils::cellnoise(p);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret);
            return pyResult;

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ExprUtilsFunc_cellnoise_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.ExprUtils.cellnoise");
        return {};
}

static PyObject* Sbk_Natron_Python_ExprUtilsFunc_cfbm(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.cfbm(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.cfbm(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OOOO:cfbm", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return {};


    // Overloaded function decisor
    // 0: static ExprUtils::cfbm(Natron::Python::Double3DTuple,int,double,double)
    if (true) {
        if (numArgs == 1) {
            overloadId = 0; // cfbm(Natron::Python::Double3DTuple,int,double,double)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // cfbm(Natron::Python::Double3DTuple,int,double,double)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 0; // cfbm(Natron::Python::Double3DTuple,int,double,double)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[3])))) {
                    overloadId = 0; // cfbm(Natron::Python::Double3DTuple,int,double,double)
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ExprUtilsFunc_cfbm_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "octaves");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.cfbm(): got multiple values for keyword argument 'octaves'.");
                return {};
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_Natron_Python_ExprUtilsFunc_cfbm_TypeError;
            }
            value = PyDict_GetItemString(kwds, "lacunarity");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.cfbm(): got multiple values for keyword argument 'lacunarity'.");
                return {};
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2]))))
                    goto Sbk_Natron_Python_ExprUtilsFunc_cfbm_TypeError;
            }
            value = PyDict_GetItemString(kwds, "gain");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.cfbm(): got multiple values for keyword argument 'gain'.");
                return {};
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[3]))))
                    goto Sbk_Natron_Python_ExprUtilsFunc_cfbm_TypeError;
            }
        }
        int cppArg1 = 6;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        double cppArg2 = 2.;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
        double cppArg3 = 0.5;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // cfbm(Natron::Python::Double3DTuple,int,double,double)
            // Begin code injection

            int tupleSize = PyTuple_GET_SIZE(pyArgs[1-1]);
            if (tupleSize != 3) {
            PyErr_SetString(PyExc_TypeError, "the tuple must have 3 items.");
            return 0;
            }
            double x1;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArgs[1-1], 0), &(x1));
            double x2;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArgs[1-1], 1), &(x2));
            double x3;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArgs[1-1], 2), &(x3));
            Natron::Python::Double3DTuple p = {x1, x2, x3};
            Natron::Python::Double3DTuple ret = Natron::Python::ExprUtils::cfbm(p, cppArg1, cppArg2, cppArg3);
            pyResult = PyTuple_New(3);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret.x));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret.y));
            PyTuple_SET_ITEM(pyResult, 2, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret.z));
            return pyResult;

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ExprUtilsFunc_cfbm_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ExprUtils.cfbm");
        return {};
}

static PyObject* Sbk_Natron_Python_ExprUtilsFunc_cfbm4(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.cfbm4(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.cfbm4(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OOOO:cfbm4", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return {};


    // Overloaded function decisor
    // 0: static ExprUtils::cfbm4(Natron::Python::ColorTuple,int,double,double)
    if (true) {
        if (numArgs == 1) {
            overloadId = 0; // cfbm4(Natron::Python::ColorTuple,int,double,double)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // cfbm4(Natron::Python::ColorTuple,int,double,double)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 0; // cfbm4(Natron::Python::ColorTuple,int,double,double)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[3])))) {
                    overloadId = 0; // cfbm4(Natron::Python::ColorTuple,int,double,double)
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ExprUtilsFunc_cfbm4_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "octaves");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.cfbm4(): got multiple values for keyword argument 'octaves'.");
                return {};
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_Natron_Python_ExprUtilsFunc_cfbm4_TypeError;
            }
            value = PyDict_GetItemString(kwds, "lacunarity");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.cfbm4(): got multiple values for keyword argument 'lacunarity'.");
                return {};
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2]))))
                    goto Sbk_Natron_Python_ExprUtilsFunc_cfbm4_TypeError;
            }
            value = PyDict_GetItemString(kwds, "gain");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.cfbm4(): got multiple values for keyword argument 'gain'.");
                return {};
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[3]))))
                    goto Sbk_Natron_Python_ExprUtilsFunc_cfbm4_TypeError;
            }
        }
        int cppArg1 = 6;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        double cppArg2 = 2.;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
        double cppArg3 = 0.5;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // cfbm4(Natron::Python::ColorTuple,int,double,double)
            // Begin code injection

            int tupleSize = PyTuple_GET_SIZE(pyArgs[1-1]);
            if (tupleSize != 4) {
            PyErr_SetString(PyExc_TypeError, "the tuple must have 4 items.");
            return 0;
            }
            double x1;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArgs[1-1], 0), &(x1));
            double x2;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArgs[1-1], 1), &(x2));
            double x3;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArgs[1-1], 2), &(x3));
            double x4;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArgs[1-1], 3), &(x4));
            Natron::Python::ColorTuple p = {x1, x2, x3, x4};
            Natron::Python::Double3DTuple ret = Natron::Python::ExprUtils::cfbm4(p, cppArg1, cppArg2, cppArg3);
            pyResult = PyTuple_New(3);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret.x));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret.y));
            PyTuple_SET_ITEM(pyResult, 2, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret.z));
            return pyResult;

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ExprUtilsFunc_cfbm4_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ExprUtils.cfbm4");
        return {};
}

static PyObject* Sbk_Natron_Python_ExprUtilsFunc_cnoise(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: static ExprUtils::cnoise(Natron::Python::Double3DTuple)
    if (true) {
        overloadId = 0; // cnoise(Natron::Python::Double3DTuple)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ExprUtilsFunc_cnoise_TypeError;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // cnoise(Natron::Python::Double3DTuple)
            // Begin code injection

            int tupleSize = PyTuple_GET_SIZE(pyArg);
            if (tupleSize != 3) {
            PyErr_SetString(PyExc_TypeError, "the tuple must have 3 items.");
            return 0;
            }
            double x1;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArg, 0), &(x1));
            double x2;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArg, 1), &(x2));
            double x3;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArg, 2), &(x3));
            Natron::Python::Double3DTuple p = {x1, x2, x3};
            Natron::Python::Double3DTuple ret = Natron::Python::ExprUtils::cnoise(p);
            pyResult = PyTuple_New(3);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret.x));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret.y));
            PyTuple_SET_ITEM(pyResult, 2, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret.z));
            return pyResult;

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ExprUtilsFunc_cnoise_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.ExprUtils.cnoise");
        return {};
}

static PyObject* Sbk_Natron_Python_ExprUtilsFunc_cnoise4(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: static ExprUtils::cnoise4(Natron::Python::ColorTuple)
    if (true) {
        overloadId = 0; // cnoise4(Natron::Python::ColorTuple)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ExprUtilsFunc_cnoise4_TypeError;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // cnoise4(Natron::Python::ColorTuple)
            // Begin code injection

            int tupleSize = PyTuple_GET_SIZE(pyArg);
            if (tupleSize != 4) {
            PyErr_SetString(PyExc_TypeError, "the tuple must have 4 items.");
            return 0;
            }
            double x1;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArg, 0), &(x1));
            double x2;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArg, 1), &(x2));
            double x3;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArg, 2), &(x3));
            double x4;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArg, 3), &(x4));
            Natron::Python::ColorTuple p = {x1, x2, x3, x4};
            Natron::Python::Double3DTuple ret = Natron::Python::ExprUtils::cnoise4(p);
            pyResult = PyTuple_New(3);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret.x));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret.y));
            PyTuple_SET_ITEM(pyResult, 2, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret.z));
            return pyResult;

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ExprUtilsFunc_cnoise4_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.ExprUtils.cnoise4");
        return {};
}

static PyObject* Sbk_Natron_Python_ExprUtilsFunc_cturbulence(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.cturbulence(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.cturbulence(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OOOO:cturbulence", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return {};


    // Overloaded function decisor
    // 0: static ExprUtils::cturbulence(Natron::Python::Double3DTuple,int,double,double)
    if (true) {
        if (numArgs == 1) {
            overloadId = 0; // cturbulence(Natron::Python::Double3DTuple,int,double,double)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // cturbulence(Natron::Python::Double3DTuple,int,double,double)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 0; // cturbulence(Natron::Python::Double3DTuple,int,double,double)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[3])))) {
                    overloadId = 0; // cturbulence(Natron::Python::Double3DTuple,int,double,double)
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ExprUtilsFunc_cturbulence_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "octaves");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.cturbulence(): got multiple values for keyword argument 'octaves'.");
                return {};
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_Natron_Python_ExprUtilsFunc_cturbulence_TypeError;
            }
            value = PyDict_GetItemString(kwds, "lacunarity");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.cturbulence(): got multiple values for keyword argument 'lacunarity'.");
                return {};
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2]))))
                    goto Sbk_Natron_Python_ExprUtilsFunc_cturbulence_TypeError;
            }
            value = PyDict_GetItemString(kwds, "gain");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.cturbulence(): got multiple values for keyword argument 'gain'.");
                return {};
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[3]))))
                    goto Sbk_Natron_Python_ExprUtilsFunc_cturbulence_TypeError;
            }
        }
        int cppArg1 = 6;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        double cppArg2 = 2.;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
        double cppArg3 = 0.5;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // cturbulence(Natron::Python::Double3DTuple,int,double,double)
            // Begin code injection

            int tupleSize = PyTuple_GET_SIZE(pyArgs[1-1]);
            if (tupleSize != 3) {
            PyErr_SetString(PyExc_TypeError, "the tuple must have 3 items.");
            return 0;
            }
            double x1;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArgs[1-1], 0), &(x1));
            double x2;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArgs[1-1], 1), &(x2));
            double x3;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArgs[1-1], 2), &(x3));
            Natron::Python::Double3DTuple p = {x1, x2, x3};
            Natron::Python::Double3DTuple ret = Natron::Python::ExprUtils::cturbulence(p, cppArg1, cppArg2, cppArg3);
            pyResult = PyTuple_New(3);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret.x));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret.y));
            PyTuple_SET_ITEM(pyResult, 2, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret.z));
            return pyResult;

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ExprUtilsFunc_cturbulence_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ExprUtils.cturbulence");
        return {};
}

static PyObject* Sbk_Natron_Python_ExprUtilsFunc_fbm(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.fbm(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.fbm(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OOOO:fbm", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return {};


    // Overloaded function decisor
    // 0: static ExprUtils::fbm(Natron::Python::Double3DTuple,int,double,double)
    if (true) {
        if (numArgs == 1) {
            overloadId = 0; // fbm(Natron::Python::Double3DTuple,int,double,double)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // fbm(Natron::Python::Double3DTuple,int,double,double)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 0; // fbm(Natron::Python::Double3DTuple,int,double,double)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[3])))) {
                    overloadId = 0; // fbm(Natron::Python::Double3DTuple,int,double,double)
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ExprUtilsFunc_fbm_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "octaves");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.fbm(): got multiple values for keyword argument 'octaves'.");
                return {};
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_Natron_Python_ExprUtilsFunc_fbm_TypeError;
            }
            value = PyDict_GetItemString(kwds, "lacunarity");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.fbm(): got multiple values for keyword argument 'lacunarity'.");
                return {};
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2]))))
                    goto Sbk_Natron_Python_ExprUtilsFunc_fbm_TypeError;
            }
            value = PyDict_GetItemString(kwds, "gain");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.fbm(): got multiple values for keyword argument 'gain'.");
                return {};
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[3]))))
                    goto Sbk_Natron_Python_ExprUtilsFunc_fbm_TypeError;
            }
        }
        int cppArg1 = 6;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        double cppArg2 = 2.;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
        double cppArg3 = 0.5;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // fbm(Natron::Python::Double3DTuple,int,double,double)
            // Begin code injection

            int tupleSize = PyTuple_GET_SIZE(pyArgs[1-1]);
            if (tupleSize != 3) {
            PyErr_SetString(PyExc_TypeError, "the tuple must have 3 items.");
            return 0;
            }
            double x1;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArgs[1-1], 0), &(x1));
            double x2;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArgs[1-1], 1), &(x2));
            double x3;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArgs[1-1], 2), &(x3));
            Natron::Python::Double3DTuple p = {x1, x2, x3};
            double ret = Natron::Python::ExprUtils::fbm(p, cppArg1, cppArg2, cppArg3);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret);
            return pyResult;

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ExprUtilsFunc_fbm_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ExprUtils.fbm");
        return {};
}

static PyObject* Sbk_Natron_Python_ExprUtilsFunc_fbm4(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.fbm4(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.fbm4(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OOOO:fbm4", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return {};


    // Overloaded function decisor
    // 0: static ExprUtils::fbm4(Natron::Python::ColorTuple,int,double,double)
    if (true) {
        if (numArgs == 1) {
            overloadId = 0; // fbm4(Natron::Python::ColorTuple,int,double,double)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // fbm4(Natron::Python::ColorTuple,int,double,double)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 0; // fbm4(Natron::Python::ColorTuple,int,double,double)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[3])))) {
                    overloadId = 0; // fbm4(Natron::Python::ColorTuple,int,double,double)
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ExprUtilsFunc_fbm4_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "octaves");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.fbm4(): got multiple values for keyword argument 'octaves'.");
                return {};
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_Natron_Python_ExprUtilsFunc_fbm4_TypeError;
            }
            value = PyDict_GetItemString(kwds, "lacunarity");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.fbm4(): got multiple values for keyword argument 'lacunarity'.");
                return {};
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2]))))
                    goto Sbk_Natron_Python_ExprUtilsFunc_fbm4_TypeError;
            }
            value = PyDict_GetItemString(kwds, "gain");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.fbm4(): got multiple values for keyword argument 'gain'.");
                return {};
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[3]))))
                    goto Sbk_Natron_Python_ExprUtilsFunc_fbm4_TypeError;
            }
        }
        int cppArg1 = 6;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        double cppArg2 = 2.;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
        double cppArg3 = 0.5;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // fbm4(Natron::Python::ColorTuple,int,double,double)
            // Begin code injection

            int tupleSize = PyTuple_GET_SIZE(pyArgs[1-1]);
            if (tupleSize != 4) {
            PyErr_SetString(PyExc_TypeError, "the tuple must have 4 items.");
            return 0;
            }
            double x1;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArgs[1-1], 0), &(x1));
            double x2;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArgs[1-1], 1), &(x2));
            double x3;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArgs[1-1], 2), &(x3));
            double x4;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArgs[1-1], 3), &(x4));
            Natron::Python::ColorTuple p = {x1, x2, x3, x4};
            double ret = Natron::Python::ExprUtils::fbm4(p, cppArg1, cppArg2, cppArg3);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret);
            return pyResult;

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ExprUtilsFunc_fbm4_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ExprUtils.fbm4");
        return {};
}

static PyObject* Sbk_Natron_Python_ExprUtilsFunc_gaussstep(PyObject* self, PyObject* args)
{
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "gaussstep", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return {};


    // Overloaded function decisor
    // 0: static ExprUtils::gaussstep(double,double,double)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2])))) {
        overloadId = 0; // gaussstep(double,double,double)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ExprUtilsFunc_gaussstep_TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        double cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        double cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // gaussstep(double,double,double)
            double cppResult = ::Natron::Python::ExprUtils::gaussstep(cppArg0, cppArg1, cppArg2);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ExprUtilsFunc_gaussstep_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ExprUtils.gaussstep");
        return {};
}

static PyObject* Sbk_Natron_Python_ExprUtilsFunc_hash(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: static ExprUtils::hash(std::vector<double>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_VECTOR_DOUBLE_IDX], (pyArg)))) {
        overloadId = 0; // hash(std::vector<double>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ExprUtilsFunc_hash_TypeError;

    // Call function/method
    {
        ::std::vector<double > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // hash(std::vector<double>)
            double cppResult = ::Natron::Python::ExprUtils::hash(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ExprUtilsFunc_hash_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.ExprUtils.hash");
        return {};
}

static PyObject* Sbk_Natron_Python_ExprUtilsFunc_linearstep(PyObject* self, PyObject* args)
{
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "linearstep", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return {};


    // Overloaded function decisor
    // 0: static ExprUtils::linearstep(double,double,double)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2])))) {
        overloadId = 0; // linearstep(double,double,double)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ExprUtilsFunc_linearstep_TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        double cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        double cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // linearstep(double,double,double)
            double cppResult = ::Natron::Python::ExprUtils::linearstep(cppArg0, cppArg1, cppArg2);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ExprUtilsFunc_linearstep_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ExprUtils.linearstep");
        return {};
}

static PyObject* Sbk_Natron_Python_ExprUtilsFunc_mix(PyObject* self, PyObject* args)
{
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "mix", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return {};


    // Overloaded function decisor
    // 0: static ExprUtils::mix(double,double,double)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2])))) {
        overloadId = 0; // mix(double,double,double)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ExprUtilsFunc_mix_TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        double cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        double cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // mix(double,double,double)
            double cppResult = ::Natron::Python::ExprUtils::mix(cppArg0, cppArg1, cppArg2);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ExprUtilsFunc_mix_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ExprUtils.mix");
        return {};
}

static PyObject* Sbk_Natron_Python_ExprUtilsFunc_noise(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: static ExprUtils::noise(Natron::Python::Double2DTuple)
    // 1: static ExprUtils::noise(double)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArg)))) {
        overloadId = 1; // noise(double)
    } else if (true) {
        overloadId = 0; // noise(Natron::Python::Double2DTuple)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ExprUtilsFunc_noise_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // noise(const Natron::Python::Double2DTuple & p)
        {

            if (!PyErr_Occurred()) {
                // noise(Natron::Python::Double2DTuple)
                // Begin code injection

                int tupleSize = PyTuple_GET_SIZE(pyArg);
                if (tupleSize != 4 && tupleSize != 3  && tupleSize != 2) {
                 PyErr_SetString(PyExc_TypeError, "the tuple must have 2, 3 or 4 items.");
                 return 0;
                }

                double ret = 0.;
                double x1;
                    Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArg, 0), &(x1));
                if (tupleSize == 2) {
                 double x2;
                    Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArg, 1), &(x2));
                 Natron::Python::Double2DTuple p = {x1, x2};
                 ret = Natron::Python::ExprUtils::noise(p);
                } else if (tupleSize == 3) {
                 double x2;
                    Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArg, 1), &(x2));
                 double x3;
                    Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArg, 2), &(x3));
                 Natron::Python::Double3DTuple p = {x1, x2, x3};
                 ret = Natron::Python::ExprUtils::noise(p);
                } else if (tupleSize == 4) {
                 double x2;
                    Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArg, 1), &(x2));
                 double x3;
                    Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArg, 2), &(x3));
                 double x4;
                    Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArg, 3), &(x4));
                 Natron::Python::ColorTuple p = {x1, x2, x3, x4};
                 ret = Natron::Python::ExprUtils::noise(p);
                }
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret);

                return pyResult;

                // End of code injection


            }
            break;
        }
        case 1: // noise(double x)
        {
            double cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // noise(double)
                double cppResult = ::Natron::Python::ExprUtils::noise(cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ExprUtilsFunc_noise_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.ExprUtils.noise");
        return {};
}

static PyObject* Sbk_Natron_Python_ExprUtilsFunc_pnoise(PyObject* self, PyObject* args)
{
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "pnoise", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: static ExprUtils::pnoise(Natron::Python::Double3DTuple,Natron::Python::Double3DTuple)
    if (numArgs == 2) {
        overloadId = 0; // pnoise(Natron::Python::Double3DTuple,Natron::Python::Double3DTuple)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ExprUtilsFunc_pnoise_TypeError;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pnoise(Natron::Python::Double3DTuple,Natron::Python::Double3DTuple)
            // Begin code injection

            int tupleSize = PyTuple_GET_SIZE(pyArgs[1-1]);
            if (tupleSize != 3) {
            PyErr_SetString(PyExc_TypeError, "the tuple must have 3 items.");
            return 0;
            }
            tupleSize = PyTuple_GET_SIZE(pyArgs[2-1]);
            if (tupleSize != 3) {
            PyErr_SetString(PyExc_TypeError, "the tuple must have 3 items.");
            return 0;
            }
            double x1;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArgs[1-1], 0), &(x1));
            double x2;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArgs[1-1], 1), &(x2));
            double x3;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArgs[1-1], 2), &(x3));
            double p1;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArgs[2-1], 0), &(p1));
            double p2;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArgs[2-1], 1), &(p2));
            double p3;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArgs[2-1], 2), &(p3));
            Natron::Python::Double3DTuple p = {x1, x2, x3};
            Natron::Python::Double3DTuple period = {p1, p2, p3};
            double ret = Natron::Python::ExprUtils::pnoise(p, period);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret);
            return pyResult;

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ExprUtilsFunc_pnoise_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ExprUtils.pnoise");
        return {};
}

static PyObject* Sbk_Natron_Python_ExprUtilsFunc_remap(PyObject* self, PyObject* args)
{
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "remap", 5, 5, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return {};


    // Overloaded function decisor
    // 0: static ExprUtils::remap(double,double,double,double,double)
    if (numArgs == 5
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[4])))) {
        overloadId = 0; // remap(double,double,double,double,double)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ExprUtilsFunc_remap_TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        double cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        double cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        double cppArg3;
        pythonToCpp[3](pyArgs[3], &cppArg3);
        double cppArg4;
        pythonToCpp[4](pyArgs[4], &cppArg4);

        if (!PyErr_Occurred()) {
            // remap(double,double,double,double,double)
            double cppResult = ::Natron::Python::ExprUtils::remap(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ExprUtilsFunc_remap_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ExprUtils.remap");
        return {};
}

static PyObject* Sbk_Natron_Python_ExprUtilsFunc_smoothstep(PyObject* self, PyObject* args)
{
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "smoothstep", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return {};


    // Overloaded function decisor
    // 0: static ExprUtils::smoothstep(double,double,double)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2])))) {
        overloadId = 0; // smoothstep(double,double,double)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ExprUtilsFunc_smoothstep_TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        double cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        double cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // smoothstep(double,double,double)
            double cppResult = ::Natron::Python::ExprUtils::smoothstep(cppArg0, cppArg1, cppArg2);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ExprUtilsFunc_smoothstep_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ExprUtils.smoothstep");
        return {};
}

static PyObject* Sbk_Natron_Python_ExprUtilsFunc_snoise(PyObject* self, PyObject* pyArg)
{
    ::Natron::Python::ExprUtils* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::ExprUtils *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EXPRUTILS_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: ExprUtils::snoise(Natron::Python::Double3DTuple)
    if (true) {
        overloadId = 0; // snoise(Natron::Python::Double3DTuple)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ExprUtilsFunc_snoise_TypeError;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // snoise(Natron::Python::Double3DTuple)
            // Begin code injection

            int tupleSize = PyTuple_GET_SIZE(pyArg);
            if (tupleSize != 3) {
            PyErr_SetString(PyExc_TypeError, "the tuple must have 3 items.");
            return 0;
            }
            double x1;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArg, 0), &(x1));
            double x2;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArg, 1), &(x2));
            double x3;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArg, 2), &(x3));
            Natron::Python::Double3DTuple p = {x1, x2, x3};
            double ret = cppSelf->snoise(p);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret);
            return pyResult;

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ExprUtilsFunc_snoise_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.ExprUtils.snoise");
        return {};
}

static PyObject* Sbk_Natron_Python_ExprUtilsFunc_snoise4(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: static ExprUtils::snoise4(Natron::Python::ColorTuple)
    if (true) {
        overloadId = 0; // snoise4(Natron::Python::ColorTuple)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ExprUtilsFunc_snoise4_TypeError;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // snoise4(Natron::Python::ColorTuple)
            // Begin code injection

            int tupleSize = PyTuple_GET_SIZE(pyArg);
            if (tupleSize != 4) {
            PyErr_SetString(PyExc_TypeError, "the tuple must have 4 items.");
            return 0;
            }
            double x1;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArg, 0), &(x1));
            double x2;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArg, 1), &(x2));
            double x3;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArg, 2), &(x3));
            double x4;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArg, 3), &(x4));
            Natron::Python::ColorTuple p = {x1, x2, x3, x4};
            double ret = Natron::Python::ExprUtils::snoise4(p);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret);
            return pyResult;

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ExprUtilsFunc_snoise4_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.ExprUtils.snoise4");
        return {};
}

static PyObject* Sbk_Natron_Python_ExprUtilsFunc_turbulence(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.turbulence(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.turbulence(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OOOO:turbulence", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return {};


    // Overloaded function decisor
    // 0: static ExprUtils::turbulence(Natron::Python::Double3DTuple,int,double,double)
    if (true) {
        if (numArgs == 1) {
            overloadId = 0; // turbulence(Natron::Python::Double3DTuple,int,double,double)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // turbulence(Natron::Python::Double3DTuple,int,double,double)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 0; // turbulence(Natron::Python::Double3DTuple,int,double,double)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[3])))) {
                    overloadId = 0; // turbulence(Natron::Python::Double3DTuple,int,double,double)
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ExprUtilsFunc_turbulence_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "octaves");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.turbulence(): got multiple values for keyword argument 'octaves'.");
                return {};
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_Natron_Python_ExprUtilsFunc_turbulence_TypeError;
            }
            value = PyDict_GetItemString(kwds, "lacunarity");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.turbulence(): got multiple values for keyword argument 'lacunarity'.");
                return {};
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2]))))
                    goto Sbk_Natron_Python_ExprUtilsFunc_turbulence_TypeError;
            }
            value = PyDict_GetItemString(kwds, "gain");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.turbulence(): got multiple values for keyword argument 'gain'.");
                return {};
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[3]))))
                    goto Sbk_Natron_Python_ExprUtilsFunc_turbulence_TypeError;
            }
        }
        int cppArg1 = 6;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        double cppArg2 = 2.;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
        double cppArg3 = 0.5;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // turbulence(Natron::Python::Double3DTuple,int,double,double)
            // Begin code injection

            int tupleSize = PyTuple_GET_SIZE(pyArgs[1-1]);
            if (tupleSize != 3) {
            PyErr_SetString(PyExc_TypeError, "the tuple must have 3 items.");
            return 0;
            }
            double x1;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArgs[1-1], 0), &(x1));
            double x2;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArgs[1-1], 1), &(x2));
            double x3;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArgs[1-1], 2), &(x3));
            Natron::Python::Double3DTuple p = {x1, x2, x3};
            double ret = Natron::Python::ExprUtils::turbulence(p, cppArg1, cppArg2, cppArg3);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret);
            return pyResult;

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ExprUtilsFunc_turbulence_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ExprUtils.turbulence");
        return {};
}

static PyObject* Sbk_Natron_Python_ExprUtilsFunc_vfbm(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.vfbm(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.vfbm(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OOOO:vfbm", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return {};


    // Overloaded function decisor
    // 0: static ExprUtils::vfbm(Natron::Python::Double3DTuple,int,double,double)
    if (true) {
        if (numArgs == 1) {
            overloadId = 0; // vfbm(Natron::Python::Double3DTuple,int,double,double)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // vfbm(Natron::Python::Double3DTuple,int,double,double)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 0; // vfbm(Natron::Python::Double3DTuple,int,double,double)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[3])))) {
                    overloadId = 0; // vfbm(Natron::Python::Double3DTuple,int,double,double)
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ExprUtilsFunc_vfbm_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "octaves");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.vfbm(): got multiple values for keyword argument 'octaves'.");
                return {};
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_Natron_Python_ExprUtilsFunc_vfbm_TypeError;
            }
            value = PyDict_GetItemString(kwds, "lacunarity");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.vfbm(): got multiple values for keyword argument 'lacunarity'.");
                return {};
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2]))))
                    goto Sbk_Natron_Python_ExprUtilsFunc_vfbm_TypeError;
            }
            value = PyDict_GetItemString(kwds, "gain");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.vfbm(): got multiple values for keyword argument 'gain'.");
                return {};
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[3]))))
                    goto Sbk_Natron_Python_ExprUtilsFunc_vfbm_TypeError;
            }
        }
        int cppArg1 = 6;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        double cppArg2 = 2.;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
        double cppArg3 = 0.5;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // vfbm(Natron::Python::Double3DTuple,int,double,double)
            // Begin code injection

            int tupleSize = PyTuple_GET_SIZE(pyArgs[1-1]);
            if (tupleSize != 3) {
            PyErr_SetString(PyExc_TypeError, "the tuple must have 3 items.");
            return 0;
            }
            double x1;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArgs[1-1], 0), &(x1));
            double x2;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArgs[1-1], 1), &(x2));
            double x3;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArgs[1-1], 2), &(x3));
            Natron::Python::Double3DTuple p = {x1, x2, x3};
            Natron::Python::Double3DTuple ret = Natron::Python::ExprUtils::vfbm(p, cppArg1, cppArg2, cppArg3);
            pyResult = PyTuple_New(3);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret.x));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret.y));
            PyTuple_SET_ITEM(pyResult, 2, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret.z));
            return pyResult;

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ExprUtilsFunc_vfbm_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ExprUtils.vfbm");
        return {};
}

static PyObject* Sbk_Natron_Python_ExprUtilsFunc_vfbm4(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.vfbm4(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.vfbm4(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OOOO:vfbm4", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return {};


    // Overloaded function decisor
    // 0: static ExprUtils::vfbm4(Natron::Python::ColorTuple,int,double,double)
    if (true) {
        if (numArgs == 1) {
            overloadId = 0; // vfbm4(Natron::Python::ColorTuple,int,double,double)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // vfbm4(Natron::Python::ColorTuple,int,double,double)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 0; // vfbm4(Natron::Python::ColorTuple,int,double,double)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[3])))) {
                    overloadId = 0; // vfbm4(Natron::Python::ColorTuple,int,double,double)
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ExprUtilsFunc_vfbm4_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "octaves");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.vfbm4(): got multiple values for keyword argument 'octaves'.");
                return {};
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_Natron_Python_ExprUtilsFunc_vfbm4_TypeError;
            }
            value = PyDict_GetItemString(kwds, "lacunarity");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.vfbm4(): got multiple values for keyword argument 'lacunarity'.");
                return {};
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2]))))
                    goto Sbk_Natron_Python_ExprUtilsFunc_vfbm4_TypeError;
            }
            value = PyDict_GetItemString(kwds, "gain");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.vfbm4(): got multiple values for keyword argument 'gain'.");
                return {};
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[3]))))
                    goto Sbk_Natron_Python_ExprUtilsFunc_vfbm4_TypeError;
            }
        }
        int cppArg1 = 6;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        double cppArg2 = 2.;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
        double cppArg3 = 0.5;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // vfbm4(Natron::Python::ColorTuple,int,double,double)
            // Begin code injection

            int tupleSize = PyTuple_GET_SIZE(pyArgs[1-1]);
            if (tupleSize != 4) {
            PyErr_SetString(PyExc_TypeError, "the tuple must have 4 items.");
            return 0;
            }
            double x1;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArgs[1-1], 0), &(x1));
            double x2;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArgs[1-1], 1), &(x2));
            double x3;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArgs[1-1], 2), &(x3));
            double x4;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArgs[1-1], 3), &(x4));
            Natron::Python::ColorTuple p = {x1, x2, x3, x4};
            Natron::Python::Double3DTuple ret = Natron::Python::ExprUtils::vfbm4(p, cppArg1, cppArg2, cppArg3);
            pyResult = PyTuple_New(3);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret.x));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret.y));
            PyTuple_SET_ITEM(pyResult, 2, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret.z));
            return pyResult;

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ExprUtilsFunc_vfbm4_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ExprUtils.vfbm4");
        return {};
}

static PyObject* Sbk_Natron_Python_ExprUtilsFunc_vnoise(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: static ExprUtils::vnoise(Natron::Python::Double3DTuple)
    if (true) {
        overloadId = 0; // vnoise(Natron::Python::Double3DTuple)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ExprUtilsFunc_vnoise_TypeError;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // vnoise(Natron::Python::Double3DTuple)
            // Begin code injection

            int tupleSize = PyTuple_GET_SIZE(pyArg);
            if (tupleSize != 3) {
            PyErr_SetString(PyExc_TypeError, "the tuple must have 3 items.");
            return 0;
            }
            double x1;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArg, 0), &(x1));
            double x2;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArg, 1), &(x2));
            double x3;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArg, 2), &(x3));
            Natron::Python::Double3DTuple p = {x1, x2, x3};
            Natron::Python::Double3DTuple ret = Natron::Python::ExprUtils::vnoise(p);
            pyResult = PyTuple_New(3);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret.x));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret.y));
            PyTuple_SET_ITEM(pyResult, 2, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret.z));
            return pyResult;

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ExprUtilsFunc_vnoise_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.ExprUtils.vnoise");
        return {};
}

static PyObject* Sbk_Natron_Python_ExprUtilsFunc_vnoise4(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: static ExprUtils::vnoise4(Natron::Python::ColorTuple)
    if (true) {
        overloadId = 0; // vnoise4(Natron::Python::ColorTuple)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ExprUtilsFunc_vnoise4_TypeError;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // vnoise4(Natron::Python::ColorTuple)
            // Begin code injection

            int tupleSize = PyTuple_GET_SIZE(pyArg);
            if (tupleSize != 4) {
            PyErr_SetString(PyExc_TypeError, "the tuple must have 4 items.");
            return 0;
            }
            double x1;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArg, 0), &(x1));
            double x2;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArg, 1), &(x2));
            double x3;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArg, 2), &(x3));
            double x4;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArg, 3), &(x4));
            Natron::Python::ColorTuple p = {x1, x2, x3, x4};
            Natron::Python::Double3DTuple ret = Natron::Python::ExprUtils::vnoise4(p);
            pyResult = PyTuple_New(3);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret.x));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret.y));
            PyTuple_SET_ITEM(pyResult, 2, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret.z));
            return pyResult;

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ExprUtilsFunc_vnoise4_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.ExprUtils.vnoise4");
        return {};
}

static PyObject* Sbk_Natron_Python_ExprUtilsFunc_vturbulence(PyObject* self, PyObject* args, PyObject* kwds)
{
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.vturbulence(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.vturbulence(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OOOO:vturbulence", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return {};


    // Overloaded function decisor
    // 0: static ExprUtils::vturbulence(Natron::Python::Double3DTuple,int,double,double)
    if (true) {
        if (numArgs == 1) {
            overloadId = 0; // vturbulence(Natron::Python::Double3DTuple,int,double,double)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // vturbulence(Natron::Python::Double3DTuple,int,double,double)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 0; // vturbulence(Natron::Python::Double3DTuple,int,double,double)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[3])))) {
                    overloadId = 0; // vturbulence(Natron::Python::Double3DTuple,int,double,double)
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ExprUtilsFunc_vturbulence_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "octaves");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.vturbulence(): got multiple values for keyword argument 'octaves'.");
                return {};
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_Natron_Python_ExprUtilsFunc_vturbulence_TypeError;
            }
            value = PyDict_GetItemString(kwds, "lacunarity");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.vturbulence(): got multiple values for keyword argument 'lacunarity'.");
                return {};
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2]))))
                    goto Sbk_Natron_Python_ExprUtilsFunc_vturbulence_TypeError;
            }
            value = PyDict_GetItemString(kwds, "gain");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ExprUtils.vturbulence(): got multiple values for keyword argument 'gain'.");
                return {};
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[3]))))
                    goto Sbk_Natron_Python_ExprUtilsFunc_vturbulence_TypeError;
            }
        }
        int cppArg1 = 6;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        double cppArg2 = 2.;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
        double cppArg3 = 0.5;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // vturbulence(Natron::Python::Double3DTuple,int,double,double)
            // Begin code injection

            int tupleSize = PyTuple_GET_SIZE(pyArgs[1-1]);
            if (tupleSize != 3) {
            PyErr_SetString(PyExc_TypeError, "the tuple must have 3 items.");
            return 0;
            }
            double x1;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArgs[1-1], 0), &(x1));
            double x2;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArgs[1-1], 1), &(x2));
            double x3;
                Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), PyTuple_GET_ITEM(pyArgs[1-1], 2), &(x3));
            Natron::Python::Double3DTuple p = {x1, x2, x3};
            Natron::Python::Double3DTuple ret = Natron::Python::ExprUtils::vturbulence(p, cppArg1, cppArg2, cppArg3);
            pyResult = PyTuple_New(3);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret.x));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret.y));
            PyTuple_SET_ITEM(pyResult, 2, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret.z));
            return pyResult;

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ExprUtilsFunc_vturbulence_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ExprUtils.vturbulence");
        return {};
}

static PyMethodDef Sbk_Natron_Python_ExprUtils_methods[] = {
    {"boxstep", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ExprUtilsFunc_boxstep), METH_VARARGS|METH_STATIC},
    {"ccellnoise", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ExprUtilsFunc_ccellnoise), METH_O|METH_STATIC},
    {"cellnoise", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ExprUtilsFunc_cellnoise), METH_O|METH_STATIC},
    {"cfbm", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ExprUtilsFunc_cfbm), METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"cfbm4", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ExprUtilsFunc_cfbm4), METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"cnoise", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ExprUtilsFunc_cnoise), METH_O|METH_STATIC},
    {"cnoise4", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ExprUtilsFunc_cnoise4), METH_O|METH_STATIC},
    {"cturbulence", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ExprUtilsFunc_cturbulence), METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"fbm", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ExprUtilsFunc_fbm), METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"fbm4", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ExprUtilsFunc_fbm4), METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"gaussstep", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ExprUtilsFunc_gaussstep), METH_VARARGS|METH_STATIC},
    {"hash", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ExprUtilsFunc_hash), METH_O|METH_STATIC},
    {"linearstep", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ExprUtilsFunc_linearstep), METH_VARARGS|METH_STATIC},
    {"mix", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ExprUtilsFunc_mix), METH_VARARGS|METH_STATIC},
    {"noise", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ExprUtilsFunc_noise), METH_O|METH_STATIC},
    {"pnoise", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ExprUtilsFunc_pnoise), METH_VARARGS|METH_STATIC},
    {"remap", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ExprUtilsFunc_remap), METH_VARARGS|METH_STATIC},
    {"smoothstep", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ExprUtilsFunc_smoothstep), METH_VARARGS|METH_STATIC},
    {"snoise", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ExprUtilsFunc_snoise), METH_O},
    {"snoise4", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ExprUtilsFunc_snoise4), METH_O|METH_STATIC},
    {"turbulence", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ExprUtilsFunc_turbulence), METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"vfbm", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ExprUtilsFunc_vfbm), METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"vfbm4", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ExprUtilsFunc_vfbm4), METH_VARARGS|METH_KEYWORDS|METH_STATIC},
    {"vnoise", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ExprUtilsFunc_vnoise), METH_O|METH_STATIC},
    {"vnoise4", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ExprUtilsFunc_vnoise4), METH_O|METH_STATIC},
    {"vturbulence", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ExprUtilsFunc_vturbulence), METH_VARARGS|METH_KEYWORDS|METH_STATIC},

    {nullptr, nullptr} // Sentinel
};

} // extern "C"

static int Sbk_Natron_Python_ExprUtils_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_Natron_Python_ExprUtils_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_Natron_Python_ExprUtils_Type = nullptr;
static SbkObjectType *Sbk_Natron_Python_ExprUtils_TypeF(void)
{
    return _Sbk_Natron_Python_ExprUtils_Type;
}

static PyType_Slot Sbk_Natron_Python_ExprUtils_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_Natron_Python_ExprUtils_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_Natron_Python_ExprUtils_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_Natron_Python_ExprUtils_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        reinterpret_cast<void*>(Sbk_Natron_Python_ExprUtils_Init)},
    {Py_tp_new,         reinterpret_cast<void*>(SbkObjectTpNew)},
    {0, nullptr}
};
static PyType_Spec Sbk_Natron_Python_ExprUtils_spec = {
    "NatronEngine.Natron.Python.ExprUtils",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Natron_Python_ExprUtils_slots
};

} //extern "C"


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void ExprUtils_PythonToCpp_ExprUtils_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_Natron_Python_ExprUtils_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_ExprUtils_PythonToCpp_ExprUtils_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_ExprUtils_TypeF())))
        return ExprUtils_PythonToCpp_ExprUtils_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* ExprUtils_PTR_CppToPython_ExprUtils(const void* cppIn) {
    auto pyOut = reinterpret_cast<PyObject*>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::Natron::Python::ExprUtils *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_Natron_Python_ExprUtils_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *Natron_Python_ExprUtils_SignatureStrings[] = {
    "NatronEngine.Natron.Python.ExprUtils()",
    "NatronEngine.Natron.Python.ExprUtils.boxstep(x:double,a:double)->double",
    "NatronEngine.Natron.Python.ExprUtils.ccellnoise(p:NatronEngine.Natron.Python.Double3DTuple)->NatronEngine.Natron.Python.Double3DTuple",
    "NatronEngine.Natron.Python.ExprUtils.cellnoise(p:NatronEngine.Natron.Python.Double3DTuple)->double",
    "NatronEngine.Natron.Python.ExprUtils.cfbm(p:NatronEngine.Natron.Python.Double3DTuple,octaves:int=6,lacunarity:double=2.,gain:double=0.5)->NatronEngine.Natron.Python.Double3DTuple",
    "NatronEngine.Natron.Python.ExprUtils.cfbm4(p:NatronEngine.Natron.Python.ColorTuple,octaves:int=6,lacunarity:double=2.,gain:double=0.5)->NatronEngine.Natron.Python.Double3DTuple",
    "NatronEngine.Natron.Python.ExprUtils.cnoise(p:NatronEngine.Natron.Python.Double3DTuple)->NatronEngine.Natron.Python.Double3DTuple",
    "NatronEngine.Natron.Python.ExprUtils.cnoise4(p:NatronEngine.Natron.Python.ColorTuple)->NatronEngine.Natron.Python.Double3DTuple",
    "NatronEngine.Natron.Python.ExprUtils.cturbulence(p:NatronEngine.Natron.Python.Double3DTuple,octaves:int=6,lacunarity:double=2.,gain:double=0.5)->NatronEngine.Natron.Python.Double3DTuple",
    "NatronEngine.Natron.Python.ExprUtils.fbm(p:NatronEngine.Natron.Python.Double3DTuple,octaves:int=6,lacunarity:double=2.,gain:double=0.5)->double",
    "NatronEngine.Natron.Python.ExprUtils.fbm4(p:NatronEngine.Natron.Python.ColorTuple,octaves:int=6,lacunarity:double=2.,gain:double=0.5)->double",
    "NatronEngine.Natron.Python.ExprUtils.gaussstep(x:double,a:double,b:double)->double",
    "NatronEngine.Natron.Python.ExprUtils.hash(args:QVector[double])->double",
    "NatronEngine.Natron.Python.ExprUtils.linearstep(x:double,a:double,b:double)->double",
    "NatronEngine.Natron.Python.ExprUtils.mix(x:double,y:double,alpha:double)->double",
    "1:NatronEngine.Natron.Python.ExprUtils.noise(p:NatronEngine.Natron.Python.Double2DTuple)->double",
    "0:NatronEngine.Natron.Python.ExprUtils.noise(x:double)->double",
    "NatronEngine.Natron.Python.ExprUtils.pnoise(p:NatronEngine.Natron.Python.Double3DTuple,period:NatronEngine.Natron.Python.Double3DTuple)->double",
    "NatronEngine.Natron.Python.ExprUtils.remap(x:double,source:double,range:double,falloff:double,interp:double)->double",
    "NatronEngine.Natron.Python.ExprUtils.smoothstep(x:double,a:double,b:double)->double",
    "NatronEngine.Natron.Python.ExprUtils.snoise(p:NatronEngine.Natron.Python.Double3DTuple)->double",
    "NatronEngine.Natron.Python.ExprUtils.snoise4(p:NatronEngine.Natron.Python.ColorTuple)->double",
    "NatronEngine.Natron.Python.ExprUtils.turbulence(p:NatronEngine.Natron.Python.Double3DTuple,octaves:int=6,lacunarity:double=2.,gain:double=0.5)->double",
    "NatronEngine.Natron.Python.ExprUtils.vfbm(p:NatronEngine.Natron.Python.Double3DTuple,octaves:int=6,lacunarity:double=2.,gain:double=0.5)->NatronEngine.Natron.Python.Double3DTuple",
    "NatronEngine.Natron.Python.ExprUtils.vfbm4(p:NatronEngine.Natron.Python.ColorTuple,octaves:int=6,lacunarity:double=2.,gain:double=0.5)->NatronEngine.Natron.Python.Double3DTuple",
    "NatronEngine.Natron.Python.ExprUtils.vnoise(p:NatronEngine.Natron.Python.Double3DTuple)->NatronEngine.Natron.Python.Double3DTuple",
    "NatronEngine.Natron.Python.ExprUtils.vnoise4(p:NatronEngine.Natron.Python.ColorTuple)->NatronEngine.Natron.Python.Double3DTuple",
    "NatronEngine.Natron.Python.ExprUtils.vturbulence(p:NatronEngine.Natron.Python.Double3DTuple,octaves:int=6,lacunarity:double=2.,gain:double=0.5)->NatronEngine.Natron.Python.Double3DTuple",
    nullptr}; // Sentinel

void init_Natron_Python_ExprUtils(PyObject* module)
{
    _Sbk_Natron_Python_ExprUtils_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "ExprUtils",
        "Natron::Python::ExprUtils*",
        &Sbk_Natron_Python_ExprUtils_spec,
        Natron_Python_ExprUtils_SignatureStrings,
        &Shiboken::callCppDestructor< ::Natron::Python::ExprUtils >,
        0,
        0,
        0    );
    
    SbkNatronEngineTypes[SBK_NATRON_PYTHON_EXPRUTILS_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_ExprUtils_TypeF());

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_Natron_Python_ExprUtils_TypeF(),
        ExprUtils_PythonToCpp_ExprUtils_PTR,
        is_ExprUtils_PythonToCpp_ExprUtils_PTR_Convertible,
        ExprUtils_PTR_CppToPython_ExprUtils);

    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::ExprUtils");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::ExprUtils*");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::ExprUtils&");
    Shiboken::Conversions::registerConverterName(converter, "Python::ExprUtils");
    Shiboken::Conversions::registerConverterName(converter, "Python::ExprUtils*");
    Shiboken::Conversions::registerConverterName(converter, "Python::ExprUtils&");
    Shiboken::Conversions::registerConverterName(converter, "ExprUtils");
    Shiboken::Conversions::registerConverterName(converter, "ExprUtils*");
    Shiboken::Conversions::registerConverterName(converter, "ExprUtils&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Natron::Python::ExprUtils).name());



}
