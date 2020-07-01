
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
#include "natron_python_param_wrapper.h"

// inner classes

// Extra includes
#include <PyAppInstance.h>
#include <PyItemsTable.h>
#include <PyNode.h>
#include <PyParameter.h>


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

void ParamWrapper::pysideInitQtMetaTypes()
{
}

ParamWrapper::~ParamWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_Natron_Python_ParamFunc__addAsDependencyOf(PyObject* self, PyObject* args)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "_addAsDependencyOf", 5, 5, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return {};


    // Overloaded function decisor
    // 0: Param::_addAsDependencyOf(Natron::Python::Param*,int,int,QString,QString)
    if (numArgs == 5
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[4])))) {
        overloadId = 0; // _addAsDependencyOf(Natron::Python::Param*,int,int,QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ParamFunc__addAsDependencyOf_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return {};
        ::Natron::Python::Param* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        ::QString cppArg3;
        pythonToCpp[3](pyArgs[3], &cppArg3);
        ::QString cppArg4;
        pythonToCpp[4](pyArgs[4], &cppArg4);

        if (!PyErr_Occurred()) {
            // _addAsDependencyOf(Natron::Python::Param*,int,int,QString,QString)
            static_cast<::ParamWrapper*>(cppSelf)->ParamWrapper::_addAsDependencyOf_protected(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_ParamFunc__addAsDependencyOf_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.Param._addAsDependencyOf");
        return {};
}

static PyObject* Sbk_Natron_Python_ParamFunc_beginChanges(PyObject* self)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // beginChanges()
            cppSelf->beginChanges();
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_Natron_Python_ParamFunc_copy(PyObject* self, PyObject* args, PyObject* kwds)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 5) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Param.copy(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Param.copy(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OOOOO:copy", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return {};


    // Overloaded function decisor
    // 0: Param::copy(Natron::Python::Param*,int,int,QString,QString)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // copy(Natron::Python::Param*,int,int,QString,QString)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // copy(Natron::Python::Param*,int,int,QString,QString)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 0; // copy(Natron::Python::Param*,int,int,QString,QString)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3])))) {
                    if (numArgs == 4) {
                        overloadId = 0; // copy(Natron::Python::Param*,int,int,QString,QString)
                    } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[4])))) {
                        overloadId = 0; // copy(Natron::Python::Param*,int,int,QString,QString)
                    }
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ParamFunc_copy_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "thisDimension");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Param.copy(): got multiple values for keyword argument 'thisDimension'.");
                return {};
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_Natron_Python_ParamFunc_copy_TypeError;
            }
            value = PyDict_GetItemString(kwds, "otherDimension");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Param.copy(): got multiple values for keyword argument 'otherDimension'.");
                return {};
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                    goto Sbk_Natron_Python_ParamFunc_copy_TypeError;
            }
            value = PyDict_GetItemString(kwds, "thisView");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Param.copy(): got multiple values for keyword argument 'thisView'.");
                return {};
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3]))))
                    goto Sbk_Natron_Python_ParamFunc_copy_TypeError;
            }
            value = PyDict_GetItemString(kwds, "otherView");
            if (value && pyArgs[4]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Param.copy(): got multiple values for keyword argument 'otherView'.");
                return {};
            } else if (value) {
                pyArgs[4] = value;
                if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[4]))))
                    goto Sbk_Natron_Python_ParamFunc_copy_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return {};
        ::Natron::Python::Param* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = Natron::Python::Param::kPyParamDimSpecAll;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2 = Natron::Python::Param::kPyParamDimSpecAll;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
        ::QString cppArg3 = QLatin1String(kPyParamViewSetSpecAll);
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
        ::QString cppArg4 = QLatin1String(kPyParamViewSetSpecAll);
        if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

        if (!PyErr_Occurred()) {
            // copy(Natron::Python::Param*,int,int,QString,QString)
            bool cppResult = cppSelf->copy(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ParamFunc_copy_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.Param.copy");
        return {};
}

static PyObject* Sbk_Natron_Python_ParamFunc_curve(PyObject* self, PyObject* args, PyObject* kwds)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
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
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Param.curve(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Param.curve(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OOO:curve", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return {};


    // Overloaded function decisor
    // 0: Param::curve(double,int,QString)const
    // 1: Param::curve(int,int,QString)const
    if (PyFloat_Check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // curve(double,int,QString)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // curve(double,int,QString)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
                overloadId = 0; // curve(double,int,QString)const
            }
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // curve(int,int,QString)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 1; // curve(int,int,QString)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
                overloadId = 1; // curve(int,int,QString)const
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ParamFunc_curve_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // curve(double time, int dimension, const QString & thisView) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "dimension");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Param.curve(): got multiple values for keyword argument 'dimension'.");
                    return {};
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                        goto Sbk_Natron_Python_ParamFunc_curve_TypeError;
                }
                value = PyDict_GetItemString(kwds, "thisView");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Param.curve(): got multiple values for keyword argument 'thisView'.");
                    return {};
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2]))))
                        goto Sbk_Natron_Python_ParamFunc_curve_TypeError;
                }
            }
            double cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QString cppArg2 = QLatin1String(kPyParamViewIdxMain);
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // curve(double,int,QString)const
                double cppResult = const_cast<const ::ParamWrapper*>(cppSelf)->curve(cppArg0, cppArg1, cppArg2);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
            }
            break;
        }
        case 1: // curve(int time, int dimension, const QString & thisView) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "dimension");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Param.curve(): got multiple values for keyword argument 'dimension'.");
                    return {};
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                        goto Sbk_Natron_Python_ParamFunc_curve_TypeError;
                }
                value = PyDict_GetItemString(kwds, "thisView");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Param.curve(): got multiple values for keyword argument 'thisView'.");
                    return {};
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2]))))
                        goto Sbk_Natron_Python_ParamFunc_curve_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1 = 0;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QString cppArg2 = QLatin1String(kPyParamViewIdxMain);
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // curve(int,int,QString)const
                double cppResult = const_cast<const ::ParamWrapper*>(cppSelf)->curve(cppArg0, cppArg1, cppArg2);
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

    Sbk_Natron_Python_ParamFunc_curve_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.Param.curve");
        return {};
}

static PyObject* Sbk_Natron_Python_ParamFunc_endChanges(PyObject* self)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // endChanges()
            cppSelf->endChanges();
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_Natron_Python_ParamFunc_getAddNewLine(PyObject* self)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getAddNewLine()
            bool cppResult = cppSelf->getAddNewLine();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_ParamFunc_getApp(PyObject* self)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getApp()const
            Natron::Python::App * cppResult = const_cast<const ::ParamWrapper*>(cppSelf)->getApp();
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_APP_IDX]), cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_ParamFunc_getCanAnimate(PyObject* self)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getCanAnimate()const
            bool cppResult = const_cast<const ::ParamWrapper*>(cppSelf)->getCanAnimate();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_ParamFunc_getEvaluateOnChange(PyObject* self)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getEvaluateOnChange()const
            bool cppResult = const_cast<const ::ParamWrapper*>(cppSelf)->getEvaluateOnChange();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_ParamFunc_getHasViewerUI(PyObject* self)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getHasViewerUI()const
            bool cppResult = const_cast<const ::ParamWrapper*>(cppSelf)->getHasViewerUI();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_ParamFunc_getHelp(PyObject* self)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getHelp()const
            QString cppResult = const_cast<const ::ParamWrapper*>(cppSelf)->getHelp();
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_ParamFunc_getIsAnimationEnabled(PyObject* self)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getIsAnimationEnabled()const
            bool cppResult = const_cast<const ::ParamWrapper*>(cppSelf)->getIsAnimationEnabled();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_ParamFunc_getIsEnabled(PyObject* self)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getIsEnabled()const
            bool cppResult = const_cast<const ::ParamWrapper*>(cppSelf)->getIsEnabled();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_ParamFunc_getIsPersistent(PyObject* self)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getIsPersistent()const
            bool cppResult = const_cast<const ::ParamWrapper*>(cppSelf)->getIsPersistent();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_ParamFunc_getIsVisible(PyObject* self)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getIsVisible()const
            bool cppResult = const_cast<const ::ParamWrapper*>(cppSelf)->getIsVisible();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_ParamFunc_getLabel(PyObject* self)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getLabel()const
            QString cppResult = const_cast<const ::ParamWrapper*>(cppSelf)->getLabel();
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_ParamFunc_getNumDimensions(PyObject* self)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getNumDimensions()const
            int cppResult = const_cast<const ::ParamWrapper*>(cppSelf)->getNumDimensions();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_ParamFunc_getParent(PyObject* self)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getParent()const
            Natron::Python::Param * cppResult = const_cast<const ::ParamWrapper*>(cppSelf)->getParent();
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX]), cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_ParamFunc_getParentEffect(PyObject* self)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getParentEffect()const
            Natron::Python::Effect * cppResult = const_cast<const ::ParamWrapper*>(cppSelf)->getParentEffect();
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX]), cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_ParamFunc_getParentItemBase(PyObject* self)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getParentItemBase()const
            Natron::Python::ItemBase * cppResult = const_cast<const ::ParamWrapper*>(cppSelf)->getParentItemBase();
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ITEMBASE_IDX]), cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_ParamFunc_getScriptName(PyObject* self)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getScriptName()const
            QString cppResult = const_cast<const ::ParamWrapper*>(cppSelf)->getScriptName();
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_ParamFunc_getTypeName(PyObject* self)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getTypeName()const
            QString cppResult = const_cast<const ::ParamWrapper*>(cppSelf)->getTypeName();
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_ParamFunc_getViewerUIIconFilePath(PyObject* self, PyObject* args, PyObject* kwds)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
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
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Param.getViewerUIIconFilePath(): too many arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|O:getViewerUIIconFilePath", &(pyArgs[0])))
        return {};


    // Overloaded function decisor
    // 0: Param::getViewerUIIconFilePath(bool)const
    if (numArgs == 0) {
        overloadId = 0; // getViewerUIIconFilePath(bool)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[0])))) {
        overloadId = 0; // getViewerUIIconFilePath(bool)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ParamFunc_getViewerUIIconFilePath_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "checked");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Param.getViewerUIIconFilePath(): got multiple values for keyword argument 'checked'.");
                return {};
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[0]))))
                    goto Sbk_Natron_Python_ParamFunc_getViewerUIIconFilePath_TypeError;
            }
        }
        bool cppArg0 = false;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // getViewerUIIconFilePath(bool)const
            QString cppResult = const_cast<const ::ParamWrapper*>(cppSelf)->getViewerUIIconFilePath(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ParamFunc_getViewerUIIconFilePath_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.Param.getViewerUIIconFilePath");
        return {};
}

static PyObject* Sbk_Natron_Python_ParamFunc_getViewerUIItemSpacing(PyObject* self)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getViewerUIItemSpacing()const
            int cppResult = const_cast<const ::ParamWrapper*>(cppSelf)->getViewerUIItemSpacing();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_ParamFunc_getViewerUILabel(PyObject* self)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getViewerUILabel()const
            QString cppResult = const_cast<const ::ParamWrapper*>(cppSelf)->getViewerUILabel();
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_ParamFunc_getViewerUILayoutType(PyObject* self)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getViewerUILayoutType()const
            Natron::ViewerContextLayoutTypeEnum cppResult = Natron::ViewerContextLayoutTypeEnum(const_cast<const ::ParamWrapper*>(cppSelf)->getViewerUILayoutType());
            pyResult = Shiboken::Conversions::copyToPython(*PepType_SGTP(SbkNatronEngineTypes[SBK_NATRON_VIEWERCONTEXTLAYOUTTYPEENUM_IDX])->converter, &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_ParamFunc_getViewerUIVisible(PyObject* self)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getViewerUIVisible()const
            bool cppResult = const_cast<const ::ParamWrapper*>(cppSelf)->getViewerUIVisible();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_ParamFunc_isExpressionCacheEnabled(PyObject* self)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isExpressionCacheEnabled()const
            bool cppResult = const_cast<const ::ParamWrapper*>(cppSelf)->isExpressionCacheEnabled();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_ParamFunc_linkTo(PyObject* self, PyObject* args, PyObject* kwds)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 5) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Param.linkTo(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Param.linkTo(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OOOOO:linkTo", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return {};


    // Overloaded function decisor
    // 0: Param::linkTo(Natron::Python::Param*,int,int,QString,QString)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // linkTo(Natron::Python::Param*,int,int,QString,QString)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // linkTo(Natron::Python::Param*,int,int,QString,QString)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 0; // linkTo(Natron::Python::Param*,int,int,QString,QString)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3])))) {
                    if (numArgs == 4) {
                        overloadId = 0; // linkTo(Natron::Python::Param*,int,int,QString,QString)
                    } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[4])))) {
                        overloadId = 0; // linkTo(Natron::Python::Param*,int,int,QString,QString)
                    }
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ParamFunc_linkTo_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "thisDimension");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Param.linkTo(): got multiple values for keyword argument 'thisDimension'.");
                return {};
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_Natron_Python_ParamFunc_linkTo_TypeError;
            }
            value = PyDict_GetItemString(kwds, "otherDimension");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Param.linkTo(): got multiple values for keyword argument 'otherDimension'.");
                return {};
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                    goto Sbk_Natron_Python_ParamFunc_linkTo_TypeError;
            }
            value = PyDict_GetItemString(kwds, "thisView");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Param.linkTo(): got multiple values for keyword argument 'thisView'.");
                return {};
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3]))))
                    goto Sbk_Natron_Python_ParamFunc_linkTo_TypeError;
            }
            value = PyDict_GetItemString(kwds, "otherView");
            if (value && pyArgs[4]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Param.linkTo(): got multiple values for keyword argument 'otherView'.");
                return {};
            } else if (value) {
                pyArgs[4] = value;
                if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[4]))))
                    goto Sbk_Natron_Python_ParamFunc_linkTo_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return {};
        ::Natron::Python::Param* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = Natron::Python::Param::kPyParamDimSpecAll;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2 = Natron::Python::Param::kPyParamDimSpecAll;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
        ::QString cppArg3 = QLatin1String(kPyParamViewSetSpecAll);
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
        ::QString cppArg4 = QLatin1String(kPyParamViewSetSpecAll);
        if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

        if (!PyErr_Occurred()) {
            // linkTo(Natron::Python::Param*,int,int,QString,QString)
            bool cppResult = cppSelf->linkTo(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ParamFunc_linkTo_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.Param.linkTo");
        return {};
}

static PyObject* Sbk_Natron_Python_ParamFunc_random(PyObject* self, PyObject* args, PyObject* kwds)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
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
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Param.random(): too many arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OOOO:random", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return {};


    // Overloaded function decisor
    // 0: Param::random(double,double)const
    // 1: Param::random(double,double,double,uint)const
    if (numArgs == 0) {
        overloadId = 0; // random(double,double)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // random(double,double)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // random(double,double)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 1; // random(double,double,double,uint)const
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), (pyArgs[3])))) {
                    overloadId = 1; // random(double,double,double,uint)const
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ParamFunc_random_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // random(double min, double max) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "min");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Param.random(): got multiple values for keyword argument 'min'.");
                    return {};
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0]))))
                        goto Sbk_Natron_Python_ParamFunc_random_TypeError;
                }
                value = PyDict_GetItemString(kwds, "max");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Param.random(): got multiple values for keyword argument 'max'.");
                    return {};
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1]))))
                        goto Sbk_Natron_Python_ParamFunc_random_TypeError;
                }
            }
            double cppArg0 = 0.;
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);
            double cppArg1 = 1.;
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // random(double,double)const
                double cppResult = const_cast<const ::ParamWrapper*>(cppSelf)->random(cppArg0, cppArg1);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
            }
            break;
        }
        case 1: // random(double min, double max, double time, unsigned int seed) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "seed");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Param.random(): got multiple values for keyword argument 'seed'.");
                    return {};
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), (pyArgs[3]))))
                        goto Sbk_Natron_Python_ParamFunc_random_TypeError;
                }
            }
            double cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            double cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            double cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            unsigned int cppArg3 = 0;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // random(double,double,double,uint)const
                double cppResult = const_cast<const ::ParamWrapper*>(cppSelf)->random(cppArg0, cppArg1, cppArg2, cppArg3);
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

    Sbk_Natron_Python_ParamFunc_random_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.Param.random");
        return {};
}

static PyObject* Sbk_Natron_Python_ParamFunc_randomInt(PyObject* self, PyObject* args, PyObject* kwds)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
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
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Param.randomInt(): too many arguments");
        return {};
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Param.randomInt(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OOOO:randomInt", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return {};


    // Overloaded function decisor
    // 0: Param::randomInt(int,int)
    // 1: Param::randomInt(int,int,double,uint)const
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // randomInt(int,int)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 1; // randomInt(int,int,double,uint)const
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), (pyArgs[3])))) {
                overloadId = 1; // randomInt(int,int,double,uint)const
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ParamFunc_randomInt_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // randomInt(int min, int max)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // randomInt(int,int)
                int cppResult = cppSelf->randomInt(cppArg0, cppArg1);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
            }
            break;
        }
        case 1: // randomInt(int min, int max, double time, unsigned int seed) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "seed");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Param.randomInt(): got multiple values for keyword argument 'seed'.");
                    return {};
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned int>(), (pyArgs[3]))))
                        goto Sbk_Natron_Python_ParamFunc_randomInt_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            double cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            unsigned int cppArg3 = 0;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // randomInt(int,int,double,uint)const
                int cppResult = const_cast<const ::ParamWrapper*>(cppSelf)->randomInt(cppArg0, cppArg1, cppArg2, cppArg3);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ParamFunc_randomInt_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.Param.randomInt");
        return {};
}

static PyObject* Sbk_Natron_Python_ParamFunc_setAddNewLine(PyObject* self, PyObject* pyArg)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: Param::setAddNewLine(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setAddNewLine(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ParamFunc_setAddNewLine_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAddNewLine(bool)
            cppSelf->setAddNewLine(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_ParamFunc_setAddNewLine_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.Param.setAddNewLine");
        return {};
}

static PyObject* Sbk_Natron_Python_ParamFunc_setAnimationEnabled(PyObject* self, PyObject* pyArg)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: Param::setAnimationEnabled(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setAnimationEnabled(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ParamFunc_setAnimationEnabled_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAnimationEnabled(bool)
            cppSelf->setAnimationEnabled(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_ParamFunc_setAnimationEnabled_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.Param.setAnimationEnabled");
        return {};
}

static PyObject* Sbk_Natron_Python_ParamFunc_setAsAlias(PyObject* self, PyObject* pyArg)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: Param::setAsAlias(Natron::Python::Param*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX]), (pyArg)))) {
        overloadId = 0; // setAsAlias(Natron::Python::Param*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ParamFunc_setAsAlias_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return {};
        ::Natron::Python::Param* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAsAlias(Natron::Python::Param*)
            bool cppResult = cppSelf->setAsAlias(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ParamFunc_setAsAlias_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.Param.setAsAlias");
        return {};
}

static PyObject* Sbk_Natron_Python_ParamFunc_setEnabled(PyObject* self, PyObject* pyArg)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: Param::setEnabled(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setEnabled(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ParamFunc_setEnabled_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setEnabled(bool)
            cppSelf->setEnabled(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_ParamFunc_setEnabled_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.Param.setEnabled");
        return {};
}

static PyObject* Sbk_Natron_Python_ParamFunc_setEvaluateOnChange(PyObject* self, PyObject* pyArg)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: Param::setEvaluateOnChange(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setEvaluateOnChange(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ParamFunc_setEvaluateOnChange_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setEvaluateOnChange(bool)
            cppSelf->setEvaluateOnChange(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_ParamFunc_setEvaluateOnChange_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.Param.setEvaluateOnChange");
        return {};
}

static PyObject* Sbk_Natron_Python_ParamFunc_setExpressionCacheEnabled(PyObject* self, PyObject* pyArg)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: Param::setExpressionCacheEnabled(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setExpressionCacheEnabled(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ParamFunc_setExpressionCacheEnabled_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setExpressionCacheEnabled(bool)
            cppSelf->setExpressionCacheEnabled(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_ParamFunc_setExpressionCacheEnabled_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.Param.setExpressionCacheEnabled");
        return {};
}

static PyObject* Sbk_Natron_Python_ParamFunc_setHelp(PyObject* self, PyObject* pyArg)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: Param::setHelp(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setHelp(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ParamFunc_setHelp_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setHelp(QString)
            cppSelf->setHelp(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_ParamFunc_setHelp_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.Param.setHelp");
        return {};
}

static PyObject* Sbk_Natron_Python_ParamFunc_setIconFilePath(PyObject* self, PyObject* args, PyObject* kwds)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Param.setIconFilePath(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Param.setIconFilePath(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OO:setIconFilePath", &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: Param::setIconFilePath(QString,bool)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setIconFilePath(QString,bool)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
            overloadId = 0; // setIconFilePath(QString,bool)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ParamFunc_setIconFilePath_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "checked");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Param.setIconFilePath(): got multiple values for keyword argument 'checked'.");
                return {};
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1]))))
                    goto Sbk_Natron_Python_ParamFunc_setIconFilePath_TypeError;
            }
        }
        ::QString cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        bool cppArg1 = false;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setIconFilePath(QString,bool)
            cppSelf->setIconFilePath(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_ParamFunc_setIconFilePath_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.Param.setIconFilePath");
        return {};
}

static PyObject* Sbk_Natron_Python_ParamFunc_setLabel(PyObject* self, PyObject* pyArg)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: Param::setLabel(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setLabel(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ParamFunc_setLabel_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setLabel(QString)
            cppSelf->setLabel(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_ParamFunc_setLabel_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.Param.setLabel");
        return {};
}

static PyObject* Sbk_Natron_Python_ParamFunc_setPersistent(PyObject* self, PyObject* pyArg)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: Param::setPersistent(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setPersistent(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ParamFunc_setPersistent_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPersistent(bool)
            cppSelf->setPersistent(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_ParamFunc_setPersistent_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.Param.setPersistent");
        return {};
}

static PyObject* Sbk_Natron_Python_ParamFunc_setViewerUIIconFilePath(PyObject* self, PyObject* args, PyObject* kwds)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Param.setViewerUIIconFilePath(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Param.setViewerUIIconFilePath(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OO:setViewerUIIconFilePath", &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: Param::setViewerUIIconFilePath(QString,bool)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setViewerUIIconFilePath(QString,bool)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
            overloadId = 0; // setViewerUIIconFilePath(QString,bool)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ParamFunc_setViewerUIIconFilePath_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "checked");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Param.setViewerUIIconFilePath(): got multiple values for keyword argument 'checked'.");
                return {};
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1]))))
                    goto Sbk_Natron_Python_ParamFunc_setViewerUIIconFilePath_TypeError;
            }
        }
        ::QString cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        bool cppArg1 = false;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setViewerUIIconFilePath(QString,bool)
            cppSelf->setViewerUIIconFilePath(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_ParamFunc_setViewerUIIconFilePath_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.Param.setViewerUIIconFilePath");
        return {};
}

static PyObject* Sbk_Natron_Python_ParamFunc_setViewerUIItemSpacing(PyObject* self, PyObject* pyArg)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: Param::setViewerUIItemSpacing(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setViewerUIItemSpacing(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ParamFunc_setViewerUIItemSpacing_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setViewerUIItemSpacing(int)
            cppSelf->setViewerUIItemSpacing(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_ParamFunc_setViewerUIItemSpacing_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.Param.setViewerUIItemSpacing");
        return {};
}

static PyObject* Sbk_Natron_Python_ParamFunc_setViewerUILabel(PyObject* self, PyObject* pyArg)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: Param::setViewerUILabel(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setViewerUILabel(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ParamFunc_setViewerUILabel_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setViewerUILabel(QString)
            cppSelf->setViewerUILabel(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_ParamFunc_setViewerUILabel_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.Param.setViewerUILabel");
        return {};
}

static PyObject* Sbk_Natron_Python_ParamFunc_setViewerUILayoutType(PyObject* self, PyObject* pyArg)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: Param::setViewerUILayoutType(Natron::ViewerContextLayoutTypeEnum)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(*PepType_SGTP(SbkNatronEngineTypes[SBK_NATRON_VIEWERCONTEXTLAYOUTTYPEENUM_IDX])->converter, (pyArg)))) {
        overloadId = 0; // setViewerUILayoutType(Natron::ViewerContextLayoutTypeEnum)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ParamFunc_setViewerUILayoutType_TypeError;

    // Call function/method
    {
        ::Natron::ViewerContextLayoutTypeEnum cppArg0{Natron::eViewerContextLayoutTypeSpacing};
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setViewerUILayoutType(Natron::ViewerContextLayoutTypeEnum)
            cppSelf->setViewerUILayoutType(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_ParamFunc_setViewerUILayoutType_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.Param.setViewerUILayoutType");
        return {};
}

static PyObject* Sbk_Natron_Python_ParamFunc_setViewerUIVisible(PyObject* self, PyObject* pyArg)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: Param::setViewerUIVisible(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setViewerUIVisible(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ParamFunc_setViewerUIVisible_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setViewerUIVisible(bool)
            cppSelf->setViewerUIVisible(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_ParamFunc_setViewerUIVisible_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.Param.setViewerUIVisible");
        return {};
}

static PyObject* Sbk_Natron_Python_ParamFunc_setVisible(PyObject* self, PyObject* pyArg)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: Param::setVisible(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setVisible(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ParamFunc_setVisible_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setVisible(bool)
            cppSelf->setVisible(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_ParamFunc_setVisible_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.Param.setVisible");
        return {};
}

static PyObject* Sbk_Natron_Python_ParamFunc_slaveTo(PyObject* self, PyObject* args, PyObject* kwds)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 5) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Param.slaveTo(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Param.slaveTo(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OOOOO:slaveTo", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return {};


    // Overloaded function decisor
    // 0: Param::slaveTo(Natron::Python::Param*,int,int,QString,QString)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // slaveTo(Natron::Python::Param*,int,int,QString,QString)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // slaveTo(Natron::Python::Param*,int,int,QString,QString)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 0; // slaveTo(Natron::Python::Param*,int,int,QString,QString)
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3])))) {
                    if (numArgs == 4) {
                        overloadId = 0; // slaveTo(Natron::Python::Param*,int,int,QString,QString)
                    } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[4])))) {
                        overloadId = 0; // slaveTo(Natron::Python::Param*,int,int,QString,QString)
                    }
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ParamFunc_slaveTo_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "thisDimension");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Param.slaveTo(): got multiple values for keyword argument 'thisDimension'.");
                return {};
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_Natron_Python_ParamFunc_slaveTo_TypeError;
            }
            value = PyDict_GetItemString(kwds, "otherDimension");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Param.slaveTo(): got multiple values for keyword argument 'otherDimension'.");
                return {};
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                    goto Sbk_Natron_Python_ParamFunc_slaveTo_TypeError;
            }
            value = PyDict_GetItemString(kwds, "thisView");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Param.slaveTo(): got multiple values for keyword argument 'thisView'.");
                return {};
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3]))))
                    goto Sbk_Natron_Python_ParamFunc_slaveTo_TypeError;
            }
            value = PyDict_GetItemString(kwds, "otherView");
            if (value && pyArgs[4]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Param.slaveTo(): got multiple values for keyword argument 'otherView'.");
                return {};
            } else if (value) {
                pyArgs[4] = value;
                if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[4]))))
                    goto Sbk_Natron_Python_ParamFunc_slaveTo_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return {};
        ::Natron::Python::Param* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = Natron::Python::Param::kPyParamDimSpecAll;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2 = Natron::Python::Param::kPyParamDimSpecAll;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
        ::QString cppArg3 = QLatin1String(kPyParamViewSetSpecAll);
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);
        ::QString cppArg4 = QLatin1String(kPyParamViewSetSpecAll);
        if (pythonToCpp[4]) pythonToCpp[4](pyArgs[4], &cppArg4);

        if (!PyErr_Occurred()) {
            // slaveTo(Natron::Python::Param*,int,int,QString,QString)
            bool cppResult = cppSelf->slaveTo(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ParamFunc_slaveTo_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.Param.slaveTo");
        return {};
}

static PyObject* Sbk_Natron_Python_ParamFunc_unlink(PyObject* self, PyObject* args, PyObject* kwds)
{
    ParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ParamWrapper *>(reinterpret_cast< ::Natron::Python::Param *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Param.unlink(): too many arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OO:unlink", &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: Param::unlink(int,QString)
    if (numArgs == 0) {
        overloadId = 0; // unlink(int,QString)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // unlink(int,QString)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 0; // unlink(int,QString)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ParamFunc_unlink_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "dimension");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Param.unlink(): got multiple values for keyword argument 'dimension'.");
                return {};
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_Natron_Python_ParamFunc_unlink_TypeError;
            }
            value = PyDict_GetItemString(kwds, "thisView");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Param.unlink(): got multiple values for keyword argument 'thisView'.");
                return {};
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                    goto Sbk_Natron_Python_ParamFunc_unlink_TypeError;
            }
        }
        int cppArg0 = Natron::Python::Param::kPyParamDimSpecAll;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = QLatin1String(kPyParamViewSetSpecAll);
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // unlink(int,QString)
            cppSelf->unlink(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_ParamFunc_unlink_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.Param.unlink");
        return {};
}

static PyMethodDef Sbk_Natron_Python_Param_methods[] = {
    {"_addAsDependencyOf", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc__addAsDependencyOf), METH_VARARGS},
    {"beginChanges", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_beginChanges), METH_NOARGS},
    {"copy", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_copy), METH_VARARGS|METH_KEYWORDS},
    {"curve", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_curve), METH_VARARGS|METH_KEYWORDS},
    {"endChanges", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_endChanges), METH_NOARGS},
    {"getAddNewLine", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_getAddNewLine), METH_NOARGS},
    {"getApp", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_getApp), METH_NOARGS},
    {"getCanAnimate", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_getCanAnimate), METH_NOARGS},
    {"getEvaluateOnChange", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_getEvaluateOnChange), METH_NOARGS},
    {"getHasViewerUI", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_getHasViewerUI), METH_NOARGS},
    {"getHelp", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_getHelp), METH_NOARGS},
    {"getIsAnimationEnabled", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_getIsAnimationEnabled), METH_NOARGS},
    {"getIsEnabled", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_getIsEnabled), METH_NOARGS},
    {"getIsPersistent", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_getIsPersistent), METH_NOARGS},
    {"getIsVisible", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_getIsVisible), METH_NOARGS},
    {"getLabel", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_getLabel), METH_NOARGS},
    {"getNumDimensions", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_getNumDimensions), METH_NOARGS},
    {"getParent", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_getParent), METH_NOARGS},
    {"getParentEffect", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_getParentEffect), METH_NOARGS},
    {"getParentItemBase", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_getParentItemBase), METH_NOARGS},
    {"getScriptName", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_getScriptName), METH_NOARGS},
    {"getTypeName", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_getTypeName), METH_NOARGS},
    {"getViewerUIIconFilePath", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_getViewerUIIconFilePath), METH_VARARGS|METH_KEYWORDS},
    {"getViewerUIItemSpacing", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_getViewerUIItemSpacing), METH_NOARGS},
    {"getViewerUILabel", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_getViewerUILabel), METH_NOARGS},
    {"getViewerUILayoutType", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_getViewerUILayoutType), METH_NOARGS},
    {"getViewerUIVisible", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_getViewerUIVisible), METH_NOARGS},
    {"isExpressionCacheEnabled", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_isExpressionCacheEnabled), METH_NOARGS},
    {"linkTo", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_linkTo), METH_VARARGS|METH_KEYWORDS},
    {"random", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_random), METH_VARARGS|METH_KEYWORDS},
    {"randomInt", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_randomInt), METH_VARARGS|METH_KEYWORDS},
    {"setAddNewLine", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_setAddNewLine), METH_O},
    {"setAnimationEnabled", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_setAnimationEnabled), METH_O},
    {"setAsAlias", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_setAsAlias), METH_O},
    {"setEnabled", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_setEnabled), METH_O},
    {"setEvaluateOnChange", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_setEvaluateOnChange), METH_O},
    {"setExpressionCacheEnabled", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_setExpressionCacheEnabled), METH_O},
    {"setHelp", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_setHelp), METH_O},
    {"setIconFilePath", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_setIconFilePath), METH_VARARGS|METH_KEYWORDS},
    {"setLabel", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_setLabel), METH_O},
    {"setPersistent", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_setPersistent), METH_O},
    {"setViewerUIIconFilePath", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_setViewerUIIconFilePath), METH_VARARGS|METH_KEYWORDS},
    {"setViewerUIItemSpacing", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_setViewerUIItemSpacing), METH_O},
    {"setViewerUILabel", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_setViewerUILabel), METH_O},
    {"setViewerUILayoutType", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_setViewerUILayoutType), METH_O},
    {"setViewerUIVisible", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_setViewerUIVisible), METH_O},
    {"setVisible", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_setVisible), METH_O},
    {"slaveTo", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_slaveTo), METH_VARARGS|METH_KEYWORDS},
    {"unlink", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ParamFunc_unlink), METH_VARARGS|METH_KEYWORDS},

    {nullptr, nullptr} // Sentinel
};

} // extern "C"

static int Sbk_Natron_Python_Param_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_Natron_Python_Param_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_Natron_Python_Param_Type = nullptr;
static SbkObjectType *Sbk_Natron_Python_Param_TypeF(void)
{
    return _Sbk_Natron_Python_Param_Type;
}

static PyType_Slot Sbk_Natron_Python_Param_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_Natron_Python_Param_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_Natron_Python_Param_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_Natron_Python_Param_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        nullptr},
    {Py_tp_new,         reinterpret_cast<void*>(SbkDummyNew /* PYSIDE-595: Prevent replacement of "0" with base->tp_new. */)},
    {0, nullptr}
};
static PyType_Spec Sbk_Natron_Python_Param_spec = {
    "NatronEngine.Natron.Python.Param",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Natron_Python_Param_slots
};

} //extern "C"


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void Param_PythonToCpp_Param_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_Natron_Python_Param_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_Param_PythonToCpp_Param_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_Param_TypeF())))
        return Param_PythonToCpp_Param_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* Param_PTR_CppToPython_Param(const void* cppIn) {
    auto pyOut = reinterpret_cast<PyObject*>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::Natron::Python::Param *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_Natron_Python_Param_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *Natron_Python_Param_SignatureStrings[] = {
    "NatronEngine.Natron.Python.Param._addAsDependencyOf(param:NatronEngine.Natron.Python.Param,fromExprDimension:int,thisDimension:int,fromExprView:QString,thisView:QString)",
    "NatronEngine.Natron.Python.Param.beginChanges()",
    "NatronEngine.Natron.Python.Param.copy(other:NatronEngine.Natron.Python.Param,thisDimension:int=kPyParamDimSpecAll,otherDimension:int=kPyParamDimSpecAll,thisView:QString=QLatin1String(kPyParamViewSetSpecAll),otherView:QString=QLatin1String(kPyParamViewSetSpecAll))->bool",
    "1:NatronEngine.Natron.Python.Param.curve(time:double,dimension:int=0,thisView:QString=QLatin1String(kPyParamViewIdxMain))->double",
    "0:NatronEngine.Natron.Python.Param.curve(time:int,dimension:int=0,thisView:QString=QLatin1String(kPyParamViewIdxMain))->double",
    "NatronEngine.Natron.Python.Param.endChanges()",
    "NatronEngine.Natron.Python.Param.getAddNewLine()->bool",
    "NatronEngine.Natron.Python.Param.getApp()->NatronEngine.Natron.Python.App",
    "NatronEngine.Natron.Python.Param.getCanAnimate()->bool",
    "NatronEngine.Natron.Python.Param.getEvaluateOnChange()->bool",
    "NatronEngine.Natron.Python.Param.getHasViewerUI()->bool",
    "NatronEngine.Natron.Python.Param.getHelp()->QString",
    "NatronEngine.Natron.Python.Param.getIsAnimationEnabled()->bool",
    "NatronEngine.Natron.Python.Param.getIsEnabled()->bool",
    "NatronEngine.Natron.Python.Param.getIsPersistent()->bool",
    "NatronEngine.Natron.Python.Param.getIsVisible()->bool",
    "NatronEngine.Natron.Python.Param.getLabel()->QString",
    "NatronEngine.Natron.Python.Param.getNumDimensions()->int",
    "NatronEngine.Natron.Python.Param.getParent()->NatronEngine.Natron.Python.Param",
    "NatronEngine.Natron.Python.Param.getParentEffect()->NatronEngine.Natron.Python.Effect",
    "NatronEngine.Natron.Python.Param.getParentItemBase()->NatronEngine.Natron.Python.ItemBase",
    "NatronEngine.Natron.Python.Param.getScriptName()->QString",
    "NatronEngine.Natron.Python.Param.getTypeName()->QString",
    "NatronEngine.Natron.Python.Param.getViewerUIIconFilePath(checked:bool=false)->QString",
    "NatronEngine.Natron.Python.Param.getViewerUIItemSpacing()->int",
    "NatronEngine.Natron.Python.Param.getViewerUILabel()->QString",
    "NatronEngine.Natron.Python.Param.getViewerUILayoutType()->NatronEngine.Natron.ViewerContextLayoutTypeEnum",
    "NatronEngine.Natron.Python.Param.getViewerUIVisible()->bool",
    "NatronEngine.Natron.Python.Param.isExpressionCacheEnabled()->bool",
    "NatronEngine.Natron.Python.Param.linkTo(other:NatronEngine.Natron.Python.Param,thisDimension:int=kPyParamDimSpecAll,otherDimension:int=kPyParamDimSpecAll,thisView:QString=QLatin1String(kPyParamViewSetSpecAll),otherView:QString=QLatin1String(kPyParamViewSetSpecAll))->bool",
    "1:NatronEngine.Natron.Python.Param.random(min:double=0.,max:double=1.)->double",
    "0:NatronEngine.Natron.Python.Param.random(min:double,max:double,time:double,seed:unsigned int=0)->double",
    "1:NatronEngine.Natron.Python.Param.randomInt(min:int,max:int)->int",
    "0:NatronEngine.Natron.Python.Param.randomInt(min:int,max:int,time:double,seed:unsigned int=0)->int",
    "NatronEngine.Natron.Python.Param.setAddNewLine(a:bool)",
    "NatronEngine.Natron.Python.Param.setAnimationEnabled(e:bool)",
    "NatronEngine.Natron.Python.Param.setAsAlias(other:NatronEngine.Natron.Python.Param)->bool",
    "NatronEngine.Natron.Python.Param.setEnabled(enabled:bool)",
    "NatronEngine.Natron.Python.Param.setEvaluateOnChange(eval:bool)",
    "NatronEngine.Natron.Python.Param.setExpressionCacheEnabled(enabled:bool)",
    "NatronEngine.Natron.Python.Param.setHelp(help:QString)",
    "NatronEngine.Natron.Python.Param.setIconFilePath(icon:QString,checked:bool=false)",
    "NatronEngine.Natron.Python.Param.setLabel(label:QString)",
    "NatronEngine.Natron.Python.Param.setPersistent(persistent:bool)",
    "NatronEngine.Natron.Python.Param.setViewerUIIconFilePath(icon:QString,checked:bool=false)",
    "NatronEngine.Natron.Python.Param.setViewerUIItemSpacing(spacingPx:int)",
    "NatronEngine.Natron.Python.Param.setViewerUILabel(label:QString)",
    "NatronEngine.Natron.Python.Param.setViewerUILayoutType(type:NatronEngine.Natron.ViewerContextLayoutTypeEnum)",
    "NatronEngine.Natron.Python.Param.setViewerUIVisible(visible:bool)",
    "NatronEngine.Natron.Python.Param.setVisible(visible:bool)",
    "NatronEngine.Natron.Python.Param.slaveTo(other:NatronEngine.Natron.Python.Param,thisDimension:int=kPyParamDimSpecAll,otherDimension:int=kPyParamDimSpecAll,thisView:QString=QLatin1String(kPyParamViewSetSpecAll),otherView:QString=QLatin1String(kPyParamViewSetSpecAll))->bool",
    "NatronEngine.Natron.Python.Param.unlink(dimension:int=kPyParamDimSpecAll,thisView:QString=QLatin1String(kPyParamViewSetSpecAll))",
    nullptr}; // Sentinel

void init_Natron_Python_Param(PyObject* module)
{
    _Sbk_Natron_Python_Param_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "Param",
        "Natron::Python::Param*",
        &Sbk_Natron_Python_Param_spec,
        Natron_Python_Param_SignatureStrings,
        &Shiboken::callCppDestructor< ::Natron::Python::Param >,
        0,
        0,
        0    );
    
    SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_Param_TypeF());

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_Natron_Python_Param_TypeF(),
        Param_PythonToCpp_Param_PTR,
        is_Param_PythonToCpp_Param_PTR_Convertible,
        Param_PTR_CppToPython_Param);

    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::Param");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::Param*");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::Param&");
    Shiboken::Conversions::registerConverterName(converter, "Python::Param");
    Shiboken::Conversions::registerConverterName(converter, "Python::Param*");
    Shiboken::Conversions::registerConverterName(converter, "Python::Param&");
    Shiboken::Conversions::registerConverterName(converter, "Param");
    Shiboken::Conversions::registerConverterName(converter, "Param*");
    Shiboken::Conversions::registerConverterName(converter, "Param&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Natron::Python::Param).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::ParamWrapper).name());


    PyDict_SetItemString(reinterpret_cast<PyTypeObject *>(Sbk_Natron_Python_Param_TypeF())->tp_dict, "kPyParamDimSpecAll", Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &Natron::Python::Param::kPyParamDimSpecAll));

    ParamWrapper::pysideInitQtMetaTypes();
}
