
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
#include "natron_python_beziercurve_wrapper.h"

// inner classes

// Extra includes
#include <PyItemsTable.h>
#include <PyParameter.h>
#include <RectD.h>
#include <list>


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

// Native ---------------------------------------------------------

void BezierCurveWrapper::pysideInitQtMetaTypes()
{
}

BezierCurveWrapper::~BezierCurveWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_Natron_Python_BezierCurveFunc_addControlPoint(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::Natron::Python::BezierCurve* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::BezierCurve *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_BEZIERCURVE_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.addControlPoint(): too many arguments");
        return {};
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.addControlPoint(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OOO:addControlPoint", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return {};


    // Overloaded function decisor
    // 0: BezierCurve::addControlPoint(double,double,QString)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // addControlPoint(double,double,QString)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
            overloadId = 0; // addControlPoint(double,double,QString)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_BezierCurveFunc_addControlPoint_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "view");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.addControlPoint(): got multiple values for keyword argument 'view'.");
                return {};
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2]))))
                    goto Sbk_Natron_Python_BezierCurveFunc_addControlPoint_TypeError;
            }
        }
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        double cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QString cppArg2 = QLatin1String(kPyParamViewSetSpecAll);
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // addControlPoint(double,double,QString)
            cppSelf->addControlPoint(cppArg0, cppArg1, cppArg2);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_BezierCurveFunc_addControlPoint_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.BezierCurve.addControlPoint");
        return {};
}

static PyObject* Sbk_Natron_Python_BezierCurveFunc_addControlPointOnSegment(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::Natron::Python::BezierCurve* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::BezierCurve *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_BEZIERCURVE_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.addControlPointOnSegment(): too many arguments");
        return {};
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.addControlPointOnSegment(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OOO:addControlPointOnSegment", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return {};


    // Overloaded function decisor
    // 0: BezierCurve::addControlPointOnSegment(int,double,QString)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // addControlPointOnSegment(int,double,QString)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
            overloadId = 0; // addControlPointOnSegment(int,double,QString)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_BezierCurveFunc_addControlPointOnSegment_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "view");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.addControlPointOnSegment(): got multiple values for keyword argument 'view'.");
                return {};
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2]))))
                    goto Sbk_Natron_Python_BezierCurveFunc_addControlPointOnSegment_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        double cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QString cppArg2 = QLatin1String(kPyParamViewSetSpecAll);
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // addControlPointOnSegment(int,double,QString)
            cppSelf->addControlPointOnSegment(cppArg0, cppArg1, cppArg2);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_BezierCurveFunc_addControlPointOnSegment_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.BezierCurve.addControlPointOnSegment");
        return {};
}

static PyObject* Sbk_Natron_Python_BezierCurveFunc_getBoundingBox(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::Natron::Python::BezierCurve* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::BezierCurve *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_BEZIERCURVE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.getBoundingBox(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.getBoundingBox(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OO:getBoundingBox", &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: BezierCurve::getBoundingBox(double,QString)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // getBoundingBox(double,QString)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 0; // getBoundingBox(double,QString)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_BezierCurveFunc_getBoundingBox_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "view");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.getBoundingBox(): got multiple values for keyword argument 'view'.");
                return {};
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                    goto Sbk_Natron_Python_BezierCurveFunc_getBoundingBox_TypeError;
            }
        }
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = QLatin1String(kPyParamViewIdxMain);
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // getBoundingBox(double,QString)const
            Natron::RectD* cppResult = new Natron::RectD(const_cast<const ::Natron::Python::BezierCurve*>(cppSelf)->getBoundingBox(cppArg0, cppArg1));
            pyResult = Shiboken::Object::newObject(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX]), cppResult, true, true);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_BezierCurveFunc_getBoundingBox_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.BezierCurve.getBoundingBox");
        return {};
}

static PyObject* Sbk_Natron_Python_BezierCurveFunc_getControlPointPosition(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::Natron::Python::BezierCurve* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::BezierCurve *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_BEZIERCURVE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.getControlPointPosition(): too many arguments");
        return {};
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.getControlPointPosition(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OOO:getControlPointPosition", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return {};


    // Overloaded function decisor
    // 0: BezierCurve::getControlPointPosition(int,double,double*,double*,double*,double*,double*,double*,QString)const
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // getControlPointPosition(int,double,double*,double*,double*,double*,double*,double*,QString)const
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
            overloadId = 0; // getControlPointPosition(int,double,double*,double*,double*,double*,double*,double*,QString)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_BezierCurveFunc_getControlPointPosition_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "view");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.getControlPointPosition(): got multiple values for keyword argument 'view'.");
                return {};
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2]))))
                    goto Sbk_Natron_Python_BezierCurveFunc_getControlPointPosition_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        double cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QString cppArg2 = QLatin1String(kPyParamViewIdxMain);
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // getControlPointPosition(int,double,double*,double*,double*,double*,double*,double*,QString)const
            // Begin code injection

            double x,y,rx,ry,lx,ly;
            cppSelf->getControlPointPosition(cppArg0, cppArg1, &x,&y, &lx,&ly,&rx,&ry, cppArg2);

            PyObject* ret = PyTuple_New(6);
            PyTuple_SET_ITEM(ret, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &x));
            PyTuple_SET_ITEM(ret, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &y));
            PyTuple_SET_ITEM(ret, 2, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &lx));
            PyTuple_SET_ITEM(ret, 3, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ly));
            PyTuple_SET_ITEM(ret, 4, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &rx));
            PyTuple_SET_ITEM(ret, 5, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ry));
            return ret;

            // End of code injection


            pyResult = Py_None;
            Py_INCREF(Py_None);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_BezierCurveFunc_getControlPointPosition_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.BezierCurve.getControlPointPosition");
        return {};
}

static PyObject* Sbk_Natron_Python_BezierCurveFunc_getFeatherPointPosition(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::Natron::Python::BezierCurve* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::BezierCurve *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_BEZIERCURVE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.getFeatherPointPosition(): too many arguments");
        return {};
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.getFeatherPointPosition(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OOO:getFeatherPointPosition", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return {};


    // Overloaded function decisor
    // 0: BezierCurve::getFeatherPointPosition(int,double,double*,double*,double*,double*,double*,double*,QString)const
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // getFeatherPointPosition(int,double,double*,double*,double*,double*,double*,double*,QString)const
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
            overloadId = 0; // getFeatherPointPosition(int,double,double*,double*,double*,double*,double*,double*,QString)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_BezierCurveFunc_getFeatherPointPosition_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "view");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.getFeatherPointPosition(): got multiple values for keyword argument 'view'.");
                return {};
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2]))))
                    goto Sbk_Natron_Python_BezierCurveFunc_getFeatherPointPosition_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        double cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QString cppArg2 = QLatin1String(kPyParamViewIdxMain);
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // getFeatherPointPosition(int,double,double*,double*,double*,double*,double*,double*,QString)const
            // Begin code injection

            double x,y,rx,ry,lx,ly;
            cppSelf->getFeatherPointPosition(cppArg0, cppArg1, &x,&y, &lx,&ly,&rx,&ry,cppArg2);

            PyObject* ret = PyTuple_New(6);
            PyTuple_SET_ITEM(ret, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &x));
            PyTuple_SET_ITEM(ret, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &y));
            PyTuple_SET_ITEM(ret, 2, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &lx));
            PyTuple_SET_ITEM(ret, 3, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ly));
            PyTuple_SET_ITEM(ret, 4, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &rx));
            PyTuple_SET_ITEM(ret, 5, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ry));
            return ret;

            // End of code injection


            pyResult = Py_None;
            Py_INCREF(Py_None);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_BezierCurveFunc_getFeatherPointPosition_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.BezierCurve.getFeatherPointPosition");
        return {};
}

static PyObject* Sbk_Natron_Python_BezierCurveFunc_getNumControlPoints(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::Natron::Python::BezierCurve* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::BezierCurve *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_BEZIERCURVE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.getNumControlPoints(): too many arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|O:getNumControlPoints", &(pyArgs[0])))
        return {};


    // Overloaded function decisor
    // 0: BezierCurve::getNumControlPoints(QString)const
    if (numArgs == 0) {
        overloadId = 0; // getNumControlPoints(QString)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 0; // getNumControlPoints(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_BezierCurveFunc_getNumControlPoints_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "view");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.getNumControlPoints(): got multiple values for keyword argument 'view'.");
                return {};
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0]))))
                    goto Sbk_Natron_Python_BezierCurveFunc_getNumControlPoints_TypeError;
            }
        }
        ::QString cppArg0 = QLatin1String(kPyParamViewIdxMain);
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // getNumControlPoints(QString)const
            int cppResult = const_cast<const ::Natron::Python::BezierCurve*>(cppSelf)->getNumControlPoints(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_BezierCurveFunc_getNumControlPoints_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.BezierCurve.getNumControlPoints");
        return {};
}

static PyObject* Sbk_Natron_Python_BezierCurveFunc_getViewsList(PyObject* self)
{
    ::Natron::Python::BezierCurve* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::BezierCurve *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_BEZIERCURVE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getViewsList()const
            QStringList cppResult = const_cast<const ::Natron::Python::BezierCurve*>(cppSelf)->getViewsList();
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_BezierCurveFunc_isActivated(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::Natron::Python::BezierCurve* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::BezierCurve *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_BEZIERCURVE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.isActivated(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.isActivated(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OO:isActivated", &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: BezierCurve::isActivated(double,QString)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // isActivated(double,QString)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 0; // isActivated(double,QString)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_BezierCurveFunc_isActivated_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "view");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.isActivated(): got multiple values for keyword argument 'view'.");
                return {};
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                    goto Sbk_Natron_Python_BezierCurveFunc_isActivated_TypeError;
            }
        }
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = QLatin1String(kPyParamViewIdxMain);
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // isActivated(double,QString)const
            bool cppResult = const_cast<const ::Natron::Python::BezierCurve*>(cppSelf)->isActivated(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_BezierCurveFunc_isActivated_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.BezierCurve.isActivated");
        return {};
}

static PyObject* Sbk_Natron_Python_BezierCurveFunc_isCurveFinished(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::Natron::Python::BezierCurve* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::BezierCurve *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_BEZIERCURVE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.isCurveFinished(): too many arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|O:isCurveFinished", &(pyArgs[0])))
        return {};


    // Overloaded function decisor
    // 0: BezierCurve::isCurveFinished(QString)const
    if (numArgs == 0) {
        overloadId = 0; // isCurveFinished(QString)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 0; // isCurveFinished(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_BezierCurveFunc_isCurveFinished_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "view");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.isCurveFinished(): got multiple values for keyword argument 'view'.");
                return {};
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0]))))
                    goto Sbk_Natron_Python_BezierCurveFunc_isCurveFinished_TypeError;
            }
        }
        ::QString cppArg0 = QLatin1String(kPyParamViewIdxMain);
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // isCurveFinished(QString)const
            bool cppResult = const_cast<const ::Natron::Python::BezierCurve*>(cppSelf)->isCurveFinished(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_BezierCurveFunc_isCurveFinished_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.BezierCurve.isCurveFinished");
        return {};
}

static PyObject* Sbk_Natron_Python_BezierCurveFunc_moveFeatherByIndex(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::Natron::Python::BezierCurve* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::BezierCurve *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_BEZIERCURVE_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 5) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.moveFeatherByIndex(): too many arguments");
        return {};
    } else if (numArgs < 4) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.moveFeatherByIndex(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OOOOO:moveFeatherByIndex", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return {};


    // Overloaded function decisor
    // 0: BezierCurve::moveFeatherByIndex(int,double,double,double,QString)
    if (numArgs >= 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[3])))) {
        if (numArgs == 4) {
            overloadId = 0; // moveFeatherByIndex(int,double,double,double,QString)
        } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[4])))) {
            overloadId = 0; // moveFeatherByIndex(int,double,double,double,QString)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_BezierCurveFunc_moveFeatherByIndex_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "view");
            if (value && pyArgs[4]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.moveFeatherByIndex(): got multiple values for keyword argument 'view'.");
                return {};
            } else if (value) {
                pyArgs[4] = value;
                if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[4]))))
                    goto Sbk_Natron_Python_BezierCurveFunc_moveFeatherByIndex_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        double cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        double cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        double cppArg3;
        pythonToCpp[3](pyArgs[3], &cppArg3);
        ::QString cppArg4 = QLatin1String(kPyParamViewSetSpecAll);
        if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

        if (!PyErr_Occurred()) {
            // moveFeatherByIndex(int,double,double,double,QString)
            cppSelf->moveFeatherByIndex(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_BezierCurveFunc_moveFeatherByIndex_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.BezierCurve.moveFeatherByIndex");
        return {};
}

static PyObject* Sbk_Natron_Python_BezierCurveFunc_moveLeftBezierPoint(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::Natron::Python::BezierCurve* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::BezierCurve *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_BEZIERCURVE_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 5) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.moveLeftBezierPoint(): too many arguments");
        return {};
    } else if (numArgs < 4) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.moveLeftBezierPoint(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OOOOO:moveLeftBezierPoint", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return {};


    // Overloaded function decisor
    // 0: BezierCurve::moveLeftBezierPoint(int,double,double,double,QString)
    if (numArgs >= 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[3])))) {
        if (numArgs == 4) {
            overloadId = 0; // moveLeftBezierPoint(int,double,double,double,QString)
        } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[4])))) {
            overloadId = 0; // moveLeftBezierPoint(int,double,double,double,QString)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_BezierCurveFunc_moveLeftBezierPoint_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "view");
            if (value && pyArgs[4]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.moveLeftBezierPoint(): got multiple values for keyword argument 'view'.");
                return {};
            } else if (value) {
                pyArgs[4] = value;
                if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[4]))))
                    goto Sbk_Natron_Python_BezierCurveFunc_moveLeftBezierPoint_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        double cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        double cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        double cppArg3;
        pythonToCpp[3](pyArgs[3], &cppArg3);
        ::QString cppArg4 = QLatin1String(kPyParamViewSetSpecAll);
        if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

        if (!PyErr_Occurred()) {
            // moveLeftBezierPoint(int,double,double,double,QString)
            cppSelf->moveLeftBezierPoint(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_BezierCurveFunc_moveLeftBezierPoint_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.BezierCurve.moveLeftBezierPoint");
        return {};
}

static PyObject* Sbk_Natron_Python_BezierCurveFunc_movePointByIndex(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::Natron::Python::BezierCurve* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::BezierCurve *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_BEZIERCURVE_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 5) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.movePointByIndex(): too many arguments");
        return {};
    } else if (numArgs < 4) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.movePointByIndex(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OOOOO:movePointByIndex", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return {};


    // Overloaded function decisor
    // 0: BezierCurve::movePointByIndex(int,double,double,double,QString)
    if (numArgs >= 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[3])))) {
        if (numArgs == 4) {
            overloadId = 0; // movePointByIndex(int,double,double,double,QString)
        } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[4])))) {
            overloadId = 0; // movePointByIndex(int,double,double,double,QString)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_BezierCurveFunc_movePointByIndex_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "view");
            if (value && pyArgs[4]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.movePointByIndex(): got multiple values for keyword argument 'view'.");
                return {};
            } else if (value) {
                pyArgs[4] = value;
                if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[4]))))
                    goto Sbk_Natron_Python_BezierCurveFunc_movePointByIndex_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        double cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        double cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        double cppArg3;
        pythonToCpp[3](pyArgs[3], &cppArg3);
        ::QString cppArg4 = QLatin1String(kPyParamViewSetSpecAll);
        if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

        if (!PyErr_Occurred()) {
            // movePointByIndex(int,double,double,double,QString)
            cppSelf->movePointByIndex(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_BezierCurveFunc_movePointByIndex_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.BezierCurve.movePointByIndex");
        return {};
}

static PyObject* Sbk_Natron_Python_BezierCurveFunc_moveRightBezierPoint(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::Natron::Python::BezierCurve* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::BezierCurve *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_BEZIERCURVE_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 5) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.moveRightBezierPoint(): too many arguments");
        return {};
    } else if (numArgs < 4) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.moveRightBezierPoint(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OOOOO:moveRightBezierPoint", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return {};


    // Overloaded function decisor
    // 0: BezierCurve::moveRightBezierPoint(int,double,double,double,QString)
    if (numArgs >= 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[3])))) {
        if (numArgs == 4) {
            overloadId = 0; // moveRightBezierPoint(int,double,double,double,QString)
        } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[4])))) {
            overloadId = 0; // moveRightBezierPoint(int,double,double,double,QString)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_BezierCurveFunc_moveRightBezierPoint_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "view");
            if (value && pyArgs[4]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.moveRightBezierPoint(): got multiple values for keyword argument 'view'.");
                return {};
            } else if (value) {
                pyArgs[4] = value;
                if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[4]))))
                    goto Sbk_Natron_Python_BezierCurveFunc_moveRightBezierPoint_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        double cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        double cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        double cppArg3;
        pythonToCpp[3](pyArgs[3], &cppArg3);
        ::QString cppArg4 = QLatin1String(kPyParamViewSetSpecAll);
        if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

        if (!PyErr_Occurred()) {
            // moveRightBezierPoint(int,double,double,double,QString)
            cppSelf->moveRightBezierPoint(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_BezierCurveFunc_moveRightBezierPoint_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.BezierCurve.moveRightBezierPoint");
        return {};
}

static PyObject* Sbk_Natron_Python_BezierCurveFunc_removeControlPointByIndex(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::Natron::Python::BezierCurve* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::BezierCurve *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_BEZIERCURVE_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.removeControlPointByIndex(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.removeControlPointByIndex(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OO:removeControlPointByIndex", &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: BezierCurve::removeControlPointByIndex(int,QString)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // removeControlPointByIndex(int,QString)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 0; // removeControlPointByIndex(int,QString)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_BezierCurveFunc_removeControlPointByIndex_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "view");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.removeControlPointByIndex(): got multiple values for keyword argument 'view'.");
                return {};
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                    goto Sbk_Natron_Python_BezierCurveFunc_removeControlPointByIndex_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = QLatin1String(kPyParamViewSetSpecAll);
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // removeControlPointByIndex(int,QString)
            cppSelf->removeControlPointByIndex(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_BezierCurveFunc_removeControlPointByIndex_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.BezierCurve.removeControlPointByIndex");
        return {};
}

static PyObject* Sbk_Natron_Python_BezierCurveFunc_setCurveFinished(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::Natron::Python::BezierCurve* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::BezierCurve *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_BEZIERCURVE_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.setCurveFinished(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.setCurveFinished(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OO:setCurveFinished", &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: BezierCurve::setCurveFinished(bool,QString)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setCurveFinished(bool,QString)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 0; // setCurveFinished(bool,QString)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_BezierCurveFunc_setCurveFinished_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "view");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.setCurveFinished(): got multiple values for keyword argument 'view'.");
                return {};
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                    goto Sbk_Natron_Python_BezierCurveFunc_setCurveFinished_TypeError;
            }
        }
        bool cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = QLatin1String(kPyParamViewSetSpecAll);
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setCurveFinished(bool,QString)
            cppSelf->setCurveFinished(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_BezierCurveFunc_setCurveFinished_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.BezierCurve.setCurveFinished");
        return {};
}

static PyObject* Sbk_Natron_Python_BezierCurveFunc_setFeatherPointAtIndex(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::Natron::Python::BezierCurve* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::BezierCurve *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_BEZIERCURVE_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 9) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.setFeatherPointAtIndex(): too many arguments");
        return {};
    } else if (numArgs < 8) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.setFeatherPointAtIndex(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OOOOOOOOO:setFeatherPointAtIndex", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5]), &(pyArgs[6]), &(pyArgs[7]), &(pyArgs[8])))
        return {};


    // Overloaded function decisor
    // 0: BezierCurve::setFeatherPointAtIndex(int,double,double,double,double,double,double,double,QString)
    if (numArgs >= 8
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[4])))
        && (pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[5])))
        && (pythonToCpp[6] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[6])))
        && (pythonToCpp[7] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[7])))) {
        if (numArgs == 8) {
            overloadId = 0; // setFeatherPointAtIndex(int,double,double,double,double,double,double,double,QString)
        } else if ((pythonToCpp[8] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[8])))) {
            overloadId = 0; // setFeatherPointAtIndex(int,double,double,double,double,double,double,double,QString)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_BezierCurveFunc_setFeatherPointAtIndex_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "view");
            if (value && pyArgs[8]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.setFeatherPointAtIndex(): got multiple values for keyword argument 'view'.");
                return {};
            } else if (value) {
                pyArgs[8] = value;
                if (!(pythonToCpp[8] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[8]))))
                    goto Sbk_Natron_Python_BezierCurveFunc_setFeatherPointAtIndex_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        double cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        double cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        double cppArg3;
        pythonToCpp[3](pyArgs[3], &cppArg3);
        double cppArg4;
        pythonToCpp[4](pyArgs[4], &cppArg4);
        double cppArg5;
        pythonToCpp[5](pyArgs[5], &cppArg5);
        double cppArg6;
        pythonToCpp[6](pyArgs[6], &cppArg6);
        double cppArg7;
        pythonToCpp[7](pyArgs[7], &cppArg7);
        ::QString cppArg8 = QLatin1String(kPyParamViewSetSpecAll);
        if (pythonToCpp[8]) pythonToCpp[8](pyArgs[8], &cppArg8);

        if (!PyErr_Occurred()) {
            // setFeatherPointAtIndex(int,double,double,double,double,double,double,double,QString)
            cppSelf->setFeatherPointAtIndex(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5, cppArg6, cppArg7, cppArg8);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_BezierCurveFunc_setFeatherPointAtIndex_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.BezierCurve.setFeatherPointAtIndex");
        return {};
}

static PyObject* Sbk_Natron_Python_BezierCurveFunc_setPointAtIndex(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::Natron::Python::BezierCurve* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::BezierCurve *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_BEZIERCURVE_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 9) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.setPointAtIndex(): too many arguments");
        return {};
    } else if (numArgs < 8) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.setPointAtIndex(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OOOOOOOOO:setPointAtIndex", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5]), &(pyArgs[6]), &(pyArgs[7]), &(pyArgs[8])))
        return {};


    // Overloaded function decisor
    // 0: BezierCurve::setPointAtIndex(int,double,double,double,double,double,double,double,QString)
    if (numArgs >= 8
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[4])))
        && (pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[5])))
        && (pythonToCpp[6] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[6])))
        && (pythonToCpp[7] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[7])))) {
        if (numArgs == 8) {
            overloadId = 0; // setPointAtIndex(int,double,double,double,double,double,double,double,QString)
        } else if ((pythonToCpp[8] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[8])))) {
            overloadId = 0; // setPointAtIndex(int,double,double,double,double,double,double,double,QString)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_BezierCurveFunc_setPointAtIndex_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "view");
            if (value && pyArgs[8]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BezierCurve.setPointAtIndex(): got multiple values for keyword argument 'view'.");
                return {};
            } else if (value) {
                pyArgs[8] = value;
                if (!(pythonToCpp[8] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[8]))))
                    goto Sbk_Natron_Python_BezierCurveFunc_setPointAtIndex_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        double cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        double cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        double cppArg3;
        pythonToCpp[3](pyArgs[3], &cppArg3);
        double cppArg4;
        pythonToCpp[4](pyArgs[4], &cppArg4);
        double cppArg5;
        pythonToCpp[5](pyArgs[5], &cppArg5);
        double cppArg6;
        pythonToCpp[6](pyArgs[6], &cppArg6);
        double cppArg7;
        pythonToCpp[7](pyArgs[7], &cppArg7);
        ::QString cppArg8 = QLatin1String(kPyParamViewSetSpecAll);
        if (pythonToCpp[8]) pythonToCpp[8](pyArgs[8], &cppArg8);

        if (!PyErr_Occurred()) {
            // setPointAtIndex(int,double,double,double,double,double,double,double,QString)
            cppSelf->setPointAtIndex(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5, cppArg6, cppArg7, cppArg8);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_BezierCurveFunc_setPointAtIndex_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.BezierCurve.setPointAtIndex");
        return {};
}

static PyObject* Sbk_Natron_Python_BezierCurveFunc_splitView(PyObject* self, PyObject* pyArg)
{
    ::Natron::Python::BezierCurve* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::BezierCurve *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_BEZIERCURVE_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: BezierCurve::splitView(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // splitView(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_BezierCurveFunc_splitView_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // splitView(QString)
            cppSelf->splitView(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_BezierCurveFunc_splitView_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.BezierCurve.splitView");
        return {};
}

static PyObject* Sbk_Natron_Python_BezierCurveFunc_unSplitView(PyObject* self, PyObject* pyArg)
{
    ::Natron::Python::BezierCurve* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::BezierCurve *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_BEZIERCURVE_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: BezierCurve::unSplitView(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // unSplitView(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_BezierCurveFunc_unSplitView_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // unSplitView(QString)
            cppSelf->unSplitView(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_BezierCurveFunc_unSplitView_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.BezierCurve.unSplitView");
        return {};
}

static PyMethodDef Sbk_Natron_Python_BezierCurve_methods[] = {
    {"addControlPoint", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_BezierCurveFunc_addControlPoint), METH_VARARGS|METH_KEYWORDS},
    {"addControlPointOnSegment", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_BezierCurveFunc_addControlPointOnSegment), METH_VARARGS|METH_KEYWORDS},
    {"getBoundingBox", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_BezierCurveFunc_getBoundingBox), METH_VARARGS|METH_KEYWORDS},
    {"getControlPointPosition", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_BezierCurveFunc_getControlPointPosition), METH_VARARGS|METH_KEYWORDS},
    {"getFeatherPointPosition", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_BezierCurveFunc_getFeatherPointPosition), METH_VARARGS|METH_KEYWORDS},
    {"getNumControlPoints", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_BezierCurveFunc_getNumControlPoints), METH_VARARGS|METH_KEYWORDS},
    {"getViewsList", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_BezierCurveFunc_getViewsList), METH_NOARGS},
    {"isActivated", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_BezierCurveFunc_isActivated), METH_VARARGS|METH_KEYWORDS},
    {"isCurveFinished", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_BezierCurveFunc_isCurveFinished), METH_VARARGS|METH_KEYWORDS},
    {"moveFeatherByIndex", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_BezierCurveFunc_moveFeatherByIndex), METH_VARARGS|METH_KEYWORDS},
    {"moveLeftBezierPoint", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_BezierCurveFunc_moveLeftBezierPoint), METH_VARARGS|METH_KEYWORDS},
    {"movePointByIndex", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_BezierCurveFunc_movePointByIndex), METH_VARARGS|METH_KEYWORDS},
    {"moveRightBezierPoint", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_BezierCurveFunc_moveRightBezierPoint), METH_VARARGS|METH_KEYWORDS},
    {"removeControlPointByIndex", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_BezierCurveFunc_removeControlPointByIndex), METH_VARARGS|METH_KEYWORDS},
    {"setCurveFinished", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_BezierCurveFunc_setCurveFinished), METH_VARARGS|METH_KEYWORDS},
    {"setFeatherPointAtIndex", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_BezierCurveFunc_setFeatherPointAtIndex), METH_VARARGS|METH_KEYWORDS},
    {"setPointAtIndex", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_BezierCurveFunc_setPointAtIndex), METH_VARARGS|METH_KEYWORDS},
    {"splitView", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_BezierCurveFunc_splitView), METH_O},
    {"unSplitView", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_BezierCurveFunc_unSplitView), METH_O},

    {nullptr, nullptr} // Sentinel
};

} // extern "C"

static int Sbk_Natron_Python_BezierCurve_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_Natron_Python_BezierCurve_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_Natron_Python_BezierCurve_Type = nullptr;
static SbkObjectType *Sbk_Natron_Python_BezierCurve_TypeF(void)
{
    return _Sbk_Natron_Python_BezierCurve_Type;
}

static PyType_Slot Sbk_Natron_Python_BezierCurve_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_Natron_Python_BezierCurve_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_Natron_Python_BezierCurve_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_Natron_Python_BezierCurve_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        nullptr},
    {Py_tp_new,         reinterpret_cast<void*>(SbkDummyNew /* PYSIDE-595: Prevent replacement of "0" with base->tp_new. */)},
    {0, nullptr}
};
static PyType_Spec Sbk_Natron_Python_BezierCurve_spec = {
    "NatronEngine.Natron.Python.BezierCurve",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Natron_Python_BezierCurve_slots
};

} //extern "C"

static void* Sbk_Natron_Python_BezierCurve_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::Natron::Python::ItemBase >()))
        return dynamic_cast< ::Natron::Python::BezierCurve*>(reinterpret_cast< ::Natron::Python::ItemBase*>(cptr));
    return {};
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void BezierCurve_PythonToCpp_BezierCurve_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_Natron_Python_BezierCurve_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_BezierCurve_PythonToCpp_BezierCurve_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_BezierCurve_TypeF())))
        return BezierCurve_PythonToCpp_BezierCurve_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* BezierCurve_PTR_CppToPython_BezierCurve(const void* cppIn) {
    auto pyOut = reinterpret_cast<PyObject*>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::Natron::Python::BezierCurve *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_Natron_Python_BezierCurve_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *Natron_Python_BezierCurve_SignatureStrings[] = {
    "NatronEngine.Natron.Python.BezierCurve.addControlPoint(x:double,y:double,view:QString=QLatin1String(kPyParamViewSetSpecAll))",
    "NatronEngine.Natron.Python.BezierCurve.addControlPointOnSegment(index:int,t:double,view:QString=QLatin1String(kPyParamViewSetSpecAll))",
    "NatronEngine.Natron.Python.BezierCurve.getBoundingBox(time:double,view:QString=QLatin1String(kPyParamViewIdxMain))->NatronEngine.Natron.RectD",
    "NatronEngine.Natron.Python.BezierCurve.getControlPointPosition(index:int,time:double,x:NatronEngine.double,y:NatronEngine.double,lx:NatronEngine.double,ly:NatronEngine.double,rx:NatronEngine.double,ry:NatronEngine.double,view:QString=QLatin1String(kPyParamViewIdxMain))",
    "NatronEngine.Natron.Python.BezierCurve.getFeatherPointPosition(index:int,time:double,x:NatronEngine.double,y:NatronEngine.double,lx:NatronEngine.double,ly:NatronEngine.double,rx:NatronEngine.double,ry:NatronEngine.double,view:QString=QLatin1String(kPyParamViewIdxMain))",
    "NatronEngine.Natron.Python.BezierCurve.getNumControlPoints(view:QString=QLatin1String(kPyParamViewIdxMain))->int",
    "NatronEngine.Natron.Python.BezierCurve.getViewsList()->QStringList",
    "NatronEngine.Natron.Python.BezierCurve.isActivated(frame:double,view:QString=QLatin1String(kPyParamViewIdxMain))->bool",
    "NatronEngine.Natron.Python.BezierCurve.isCurveFinished(view:QString=QLatin1String(kPyParamViewIdxMain))->bool",
    "NatronEngine.Natron.Python.BezierCurve.moveFeatherByIndex(index:int,time:double,dx:double,dy:double,view:QString=QLatin1String(kPyParamViewSetSpecAll))",
    "NatronEngine.Natron.Python.BezierCurve.moveLeftBezierPoint(index:int,time:double,dx:double,dy:double,view:QString=QLatin1String(kPyParamViewSetSpecAll))",
    "NatronEngine.Natron.Python.BezierCurve.movePointByIndex(index:int,time:double,dx:double,dy:double,view:QString=QLatin1String(kPyParamViewSetSpecAll))",
    "NatronEngine.Natron.Python.BezierCurve.moveRightBezierPoint(index:int,time:double,dx:double,dy:double,view:QString=QLatin1String(kPyParamViewSetSpecAll))",
    "NatronEngine.Natron.Python.BezierCurve.removeControlPointByIndex(index:int,view:QString=QLatin1String(kPyParamViewSetSpecAll))",
    "NatronEngine.Natron.Python.BezierCurve.setCurveFinished(finished:bool,view:QString=QLatin1String(kPyParamViewSetSpecAll))",
    "NatronEngine.Natron.Python.BezierCurve.setFeatherPointAtIndex(index:int,time:double,x:double,y:double,lx:double,ly:double,rx:double,ry:double,view:QString=QLatin1String(kPyParamViewSetSpecAll))",
    "NatronEngine.Natron.Python.BezierCurve.setPointAtIndex(index:int,time:double,x:double,y:double,lx:double,ly:double,rx:double,ry:double,view:QString=QLatin1String(kPyParamViewSetSpecAll))",
    "NatronEngine.Natron.Python.BezierCurve.splitView(viewName:QString)",
    "NatronEngine.Natron.Python.BezierCurve.unSplitView(viewName:QString)",
    nullptr}; // Sentinel

void init_Natron_Python_BezierCurve(PyObject* module)
{
    _Sbk_Natron_Python_BezierCurve_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "BezierCurve",
        "Natron::Python::BezierCurve*",
        &Sbk_Natron_Python_BezierCurve_spec,
        Natron_Python_BezierCurve_SignatureStrings,
        &Shiboken::callCppDestructor< ::Natron::Python::BezierCurve >,
        reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ITEMBASE_IDX]),
        0,
        0    );
    
    SbkNatronEngineTypes[SBK_NATRON_PYTHON_BEZIERCURVE_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_BezierCurve_TypeF());

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_Natron_Python_BezierCurve_TypeF(),
        BezierCurve_PythonToCpp_BezierCurve_PTR,
        is_BezierCurve_PythonToCpp_BezierCurve_PTR_Convertible,
        BezierCurve_PTR_CppToPython_BezierCurve);

    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::BezierCurve");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::BezierCurve*");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::BezierCurve&");
    Shiboken::Conversions::registerConverterName(converter, "Python::BezierCurve");
    Shiboken::Conversions::registerConverterName(converter, "Python::BezierCurve*");
    Shiboken::Conversions::registerConverterName(converter, "Python::BezierCurve&");
    Shiboken::Conversions::registerConverterName(converter, "BezierCurve");
    Shiboken::Conversions::registerConverterName(converter, "BezierCurve*");
    Shiboken::Conversions::registerConverterName(converter, "BezierCurve&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Natron::Python::BezierCurve).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::BezierCurveWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_Natron_Python_BezierCurve_TypeF(), &Sbk_Natron_Python_BezierCurve_typeDiscovery);


    BezierCurveWrapper::pysideInitQtMetaTypes();
}
