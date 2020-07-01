
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
#include "natron_python_stringparambase_wrapper.h"

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

void StringParamBaseWrapper::pysideInitQtMetaTypes()
{
}

StringParamBaseWrapper::~StringParamBaseWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_Natron_Python_StringParamBaseFunc_addAsDependencyOf(PyObject* self, PyObject* args)
{
    StringParamBaseWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<StringParamBaseWrapper *>(reinterpret_cast< ::Natron::Python::StringParamBase *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STRINGPARAMBASE_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "addAsDependencyOf", 5, 5, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return {};


    // Overloaded function decisor
    // 0: StringParamBase::addAsDependencyOf(Natron::Python::Param*,int,int,QString,QString)
    if (numArgs == 5
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[4])))) {
        overloadId = 0; // addAsDependencyOf(Natron::Python::Param*,int,int,QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_StringParamBaseFunc_addAsDependencyOf_TypeError;

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
            // addAsDependencyOf(Natron::Python::Param*,int,int,QString,QString)
            QString cppResult = cppSelf->addAsDependencyOf(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_StringParamBaseFunc_addAsDependencyOf_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.StringParamBase.addAsDependencyOf");
        return {};
}

static PyObject* Sbk_Natron_Python_StringParamBaseFunc_get(PyObject* self, PyObject* args, PyObject* kwds)
{
    StringParamBaseWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<StringParamBaseWrapper *>(reinterpret_cast< ::Natron::Python::StringParamBase *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STRINGPARAMBASE_IDX], reinterpret_cast<SbkObject *>(self))));
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
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.StringParamBase.get(): too many arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OO:get", &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: StringParamBase::get(QString)const
    // 1: StringParamBase::get(double,QString)const
    if (numArgs == 0) {
        overloadId = 0; // get(QString)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // get(double,QString)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 1; // get(double,QString)const
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 0; // get(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_StringParamBaseFunc_get_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // get(const QString & view) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "view");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.StringParamBase.get(): got multiple values for keyword argument 'view'.");
                    return {};
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0]))))
                        goto Sbk_Natron_Python_StringParamBaseFunc_get_TypeError;
                }
            }
            ::QString cppArg0 = QLatin1String(kPyParamViewIdxMain);
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // get(QString)const
                QString cppResult = const_cast<const ::StringParamBaseWrapper*>(cppSelf)->get(cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 1: // get(double frame, const QString & view) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "view");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.StringParamBase.get(): got multiple values for keyword argument 'view'.");
                    return {};
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                        goto Sbk_Natron_Python_StringParamBaseFunc_get_TypeError;
                }
            }
            double cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = QLatin1String(kPyParamViewIdxMain);
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // get(double,QString)const
                QString cppResult = const_cast<const ::StringParamBaseWrapper*>(cppSelf)->get(cppArg0, cppArg1);
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_StringParamBaseFunc_get_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.StringParamBase.get");
        return {};
}

static PyObject* Sbk_Natron_Python_StringParamBaseFunc_getDefaultValue(PyObject* self)
{
    StringParamBaseWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<StringParamBaseWrapper *>(reinterpret_cast< ::Natron::Python::StringParamBase *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STRINGPARAMBASE_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getDefaultValue()const
            QString cppResult = const_cast<const ::StringParamBaseWrapper*>(cppSelf)->getDefaultValue();
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_StringParamBaseFunc_getValue(PyObject* self, PyObject* args, PyObject* kwds)
{
    StringParamBaseWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<StringParamBaseWrapper *>(reinterpret_cast< ::Natron::Python::StringParamBase *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STRINGPARAMBASE_IDX], reinterpret_cast<SbkObject *>(self))));
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
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.StringParamBase.getValue(): too many arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|O:getValue", &(pyArgs[0])))
        return {};


    // Overloaded function decisor
    // 0: StringParamBase::getValue(QString)const
    if (numArgs == 0) {
        overloadId = 0; // getValue(QString)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 0; // getValue(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_StringParamBaseFunc_getValue_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "view");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.StringParamBase.getValue(): got multiple values for keyword argument 'view'.");
                return {};
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0]))))
                    goto Sbk_Natron_Python_StringParamBaseFunc_getValue_TypeError;
            }
        }
        ::QString cppArg0 = QLatin1String(kPyParamViewIdxMain);
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // getValue(QString)const
            QString cppResult = const_cast<const ::StringParamBaseWrapper*>(cppSelf)->getValue(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_StringParamBaseFunc_getValue_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.StringParamBase.getValue");
        return {};
}

static PyObject* Sbk_Natron_Python_StringParamBaseFunc_getValueAtTime(PyObject* self, PyObject* args, PyObject* kwds)
{
    StringParamBaseWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<StringParamBaseWrapper *>(reinterpret_cast< ::Natron::Python::StringParamBase *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STRINGPARAMBASE_IDX], reinterpret_cast<SbkObject *>(self))));
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
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.StringParamBase.getValueAtTime(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.StringParamBase.getValueAtTime(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OO:getValueAtTime", &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: StringParamBase::getValueAtTime(double,QString)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // getValueAtTime(double,QString)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 0; // getValueAtTime(double,QString)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_StringParamBaseFunc_getValueAtTime_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "view");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.StringParamBase.getValueAtTime(): got multiple values for keyword argument 'view'.");
                return {};
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                    goto Sbk_Natron_Python_StringParamBaseFunc_getValueAtTime_TypeError;
            }
        }
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = QLatin1String(kPyParamViewIdxMain);
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // getValueAtTime(double,QString)const
            QString cppResult = const_cast<const ::StringParamBaseWrapper*>(cppSelf)->getValueAtTime(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_StringParamBaseFunc_getValueAtTime_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.StringParamBase.getValueAtTime");
        return {};
}

static PyObject* Sbk_Natron_Python_StringParamBaseFunc_restoreDefaultValue(PyObject* self, PyObject* args, PyObject* kwds)
{
    StringParamBaseWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<StringParamBaseWrapper *>(reinterpret_cast< ::Natron::Python::StringParamBase *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STRINGPARAMBASE_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.StringParamBase.restoreDefaultValue(): too many arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|O:restoreDefaultValue", &(pyArgs[0])))
        return {};


    // Overloaded function decisor
    // 0: StringParamBase::restoreDefaultValue(QString)
    if (numArgs == 0) {
        overloadId = 0; // restoreDefaultValue(QString)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 0; // restoreDefaultValue(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_StringParamBaseFunc_restoreDefaultValue_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "view");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.StringParamBase.restoreDefaultValue(): got multiple values for keyword argument 'view'.");
                return {};
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0]))))
                    goto Sbk_Natron_Python_StringParamBaseFunc_restoreDefaultValue_TypeError;
            }
        }
        ::QString cppArg0 = QLatin1String(kPyParamViewSetSpecAll);
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // restoreDefaultValue(QString)
            cppSelf->restoreDefaultValue(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_StringParamBaseFunc_restoreDefaultValue_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.StringParamBase.restoreDefaultValue");
        return {};
}

static PyObject* Sbk_Natron_Python_StringParamBaseFunc_set(PyObject* self, PyObject* args, PyObject* kwds)
{
    StringParamBaseWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<StringParamBaseWrapper *>(reinterpret_cast< ::Natron::Python::StringParamBase *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STRINGPARAMBASE_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.StringParamBase.set(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.StringParamBase.set(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OOO:set", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return {};


    // Overloaded function decisor
    // 0: StringParamBase::set(QString,QString)
    // 1: StringParamBase::set(QString,double,QString)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // set(QString,QString)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 1; // set(QString,double,QString)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
                overloadId = 1; // set(QString,double,QString)
            }
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 0; // set(QString,QString)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_StringParamBaseFunc_set_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // set(const QString & x, const QString & view)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "view");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.StringParamBase.set(): got multiple values for keyword argument 'view'.");
                    return {};
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                        goto Sbk_Natron_Python_StringParamBaseFunc_set_TypeError;
                }
            }
            ::QString cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = QLatin1String(kPyParamViewSetSpecAll);
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // set(QString,QString)
                cppSelf->set(cppArg0, cppArg1);
            }
            break;
        }
        case 1: // set(const QString & x, double frame, const QString & view)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "view");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.StringParamBase.set(): got multiple values for keyword argument 'view'.");
                    return {};
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2]))))
                        goto Sbk_Natron_Python_StringParamBaseFunc_set_TypeError;
                }
            }
            ::QString cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            double cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QString cppArg2 = QLatin1String(kPyParamViewSetSpecAll);
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // set(QString,double,QString)
                cppSelf->set(cppArg0, cppArg1, cppArg2);
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_StringParamBaseFunc_set_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.StringParamBase.set");
        return {};
}

static PyObject* Sbk_Natron_Python_StringParamBaseFunc_setDefaultValue(PyObject* self, PyObject* pyArg)
{
    StringParamBaseWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<StringParamBaseWrapper *>(reinterpret_cast< ::Natron::Python::StringParamBase *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STRINGPARAMBASE_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: StringParamBase::setDefaultValue(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setDefaultValue(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_StringParamBaseFunc_setDefaultValue_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDefaultValue(QString)
            cppSelf->setDefaultValue(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_StringParamBaseFunc_setDefaultValue_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.StringParamBase.setDefaultValue");
        return {};
}

static PyObject* Sbk_Natron_Python_StringParamBaseFunc_setValue(PyObject* self, PyObject* args, PyObject* kwds)
{
    StringParamBaseWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<StringParamBaseWrapper *>(reinterpret_cast< ::Natron::Python::StringParamBase *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STRINGPARAMBASE_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.StringParamBase.setValue(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.StringParamBase.setValue(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OO:setValue", &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: StringParamBase::setValue(QString,QString)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setValue(QString,QString)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 0; // setValue(QString,QString)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_StringParamBaseFunc_setValue_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "view");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.StringParamBase.setValue(): got multiple values for keyword argument 'view'.");
                return {};
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                    goto Sbk_Natron_Python_StringParamBaseFunc_setValue_TypeError;
            }
        }
        ::QString cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = QLatin1String(kPyParamViewSetSpecAll);
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setValue(QString,QString)
            cppSelf->setValue(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_StringParamBaseFunc_setValue_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.StringParamBase.setValue");
        return {};
}

static PyObject* Sbk_Natron_Python_StringParamBaseFunc_setValueAtTime(PyObject* self, PyObject* args, PyObject* kwds)
{
    StringParamBaseWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<StringParamBaseWrapper *>(reinterpret_cast< ::Natron::Python::StringParamBase *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STRINGPARAMBASE_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.StringParamBase.setValueAtTime(): too many arguments");
        return {};
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.StringParamBase.setValueAtTime(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OOO:setValueAtTime", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return {};


    // Overloaded function decisor
    // 0: StringParamBase::setValueAtTime(QString,double,QString)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // setValueAtTime(QString,double,QString)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
            overloadId = 0; // setValueAtTime(QString,double,QString)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_StringParamBaseFunc_setValueAtTime_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "view");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.StringParamBase.setValueAtTime(): got multiple values for keyword argument 'view'.");
                return {};
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2]))))
                    goto Sbk_Natron_Python_StringParamBaseFunc_setValueAtTime_TypeError;
            }
        }
        ::QString cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        double cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QString cppArg2 = QLatin1String(kPyParamViewSetSpecAll);
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // setValueAtTime(QString,double,QString)
            cppSelf->setValueAtTime(cppArg0, cppArg1, cppArg2);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_StringParamBaseFunc_setValueAtTime_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.StringParamBase.setValueAtTime");
        return {};
}

static PyMethodDef Sbk_Natron_Python_StringParamBase_methods[] = {
    {"addAsDependencyOf", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_StringParamBaseFunc_addAsDependencyOf), METH_VARARGS},
    {"get", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_StringParamBaseFunc_get), METH_VARARGS|METH_KEYWORDS},
    {"getDefaultValue", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_StringParamBaseFunc_getDefaultValue), METH_NOARGS},
    {"getValue", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_StringParamBaseFunc_getValue), METH_VARARGS|METH_KEYWORDS},
    {"getValueAtTime", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_StringParamBaseFunc_getValueAtTime), METH_VARARGS|METH_KEYWORDS},
    {"restoreDefaultValue", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_StringParamBaseFunc_restoreDefaultValue), METH_VARARGS|METH_KEYWORDS},
    {"set", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_StringParamBaseFunc_set), METH_VARARGS|METH_KEYWORDS},
    {"setDefaultValue", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_StringParamBaseFunc_setDefaultValue), METH_O},
    {"setValue", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_StringParamBaseFunc_setValue), METH_VARARGS|METH_KEYWORDS},
    {"setValueAtTime", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_StringParamBaseFunc_setValueAtTime), METH_VARARGS|METH_KEYWORDS},

    {nullptr, nullptr} // Sentinel
};

} // extern "C"

static int Sbk_Natron_Python_StringParamBase_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_Natron_Python_StringParamBase_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_Natron_Python_StringParamBase_Type = nullptr;
static SbkObjectType *Sbk_Natron_Python_StringParamBase_TypeF(void)
{
    return _Sbk_Natron_Python_StringParamBase_Type;
}

static PyType_Slot Sbk_Natron_Python_StringParamBase_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_Natron_Python_StringParamBase_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_Natron_Python_StringParamBase_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_Natron_Python_StringParamBase_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        nullptr},
    {Py_tp_new,         reinterpret_cast<void*>(SbkDummyNew /* PYSIDE-595: Prevent replacement of "0" with base->tp_new. */)},
    {0, nullptr}
};
static PyType_Spec Sbk_Natron_Python_StringParamBase_spec = {
    "NatronEngine.Natron.Python.StringParamBase",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Natron_Python_StringParamBase_slots
};

} //extern "C"

static void* Sbk_Natron_Python_StringParamBase_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::Natron::Python::Param >()))
        return dynamic_cast< ::Natron::Python::StringParamBase*>(reinterpret_cast< ::Natron::Python::Param*>(cptr));
    return {};
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void StringParamBase_PythonToCpp_StringParamBase_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_Natron_Python_StringParamBase_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_StringParamBase_PythonToCpp_StringParamBase_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_StringParamBase_TypeF())))
        return StringParamBase_PythonToCpp_StringParamBase_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* StringParamBase_PTR_CppToPython_StringParamBase(const void* cppIn) {
    auto pyOut = reinterpret_cast<PyObject*>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::Natron::Python::StringParamBase *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_Natron_Python_StringParamBase_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *Natron_Python_StringParamBase_SignatureStrings[] = {
    "NatronEngine.Natron.Python.StringParamBase.addAsDependencyOf(param:NatronEngine.Natron.Python.Param,fromExprDimension:int,thisDimension:int,fromExprView:QString,thisView:QString)->QString",
    "1:NatronEngine.Natron.Python.StringParamBase.get(view:QString=QLatin1String(kPyParamViewIdxMain))->QString",
    "0:NatronEngine.Natron.Python.StringParamBase.get(frame:double,view:QString=QLatin1String(kPyParamViewIdxMain))->QString",
    "NatronEngine.Natron.Python.StringParamBase.getDefaultValue()->QString",
    "NatronEngine.Natron.Python.StringParamBase.getValue(view:QString=QLatin1String(kPyParamViewIdxMain))->QString",
    "NatronEngine.Natron.Python.StringParamBase.getValueAtTime(time:double,view:QString=QLatin1String(kPyParamViewIdxMain))->QString",
    "NatronEngine.Natron.Python.StringParamBase.restoreDefaultValue(view:QString=QLatin1String(kPyParamViewSetSpecAll))",
    "1:NatronEngine.Natron.Python.StringParamBase.set(x:QString,view:QString=QLatin1String(kPyParamViewSetSpecAll))",
    "0:NatronEngine.Natron.Python.StringParamBase.set(x:QString,frame:double,view:QString=QLatin1String(kPyParamViewSetSpecAll))",
    "NatronEngine.Natron.Python.StringParamBase.setDefaultValue(value:QString)",
    "NatronEngine.Natron.Python.StringParamBase.setValue(value:QString,view:QString=QLatin1String(kPyParamViewSetSpecAll))",
    "NatronEngine.Natron.Python.StringParamBase.setValueAtTime(value:QString,time:double,view:QString=QLatin1String(kPyParamViewSetSpecAll))",
    nullptr}; // Sentinel

void init_Natron_Python_StringParamBase(PyObject* module)
{
    _Sbk_Natron_Python_StringParamBase_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "StringParamBase",
        "Natron::Python::StringParamBase*",
        &Sbk_Natron_Python_StringParamBase_spec,
        Natron_Python_StringParamBase_SignatureStrings,
        &Shiboken::callCppDestructor< ::Natron::Python::StringParamBase >,
        reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ANIMATEDPARAM_IDX]),
        0,
        0    );
    
    SbkNatronEngineTypes[SBK_NATRON_PYTHON_STRINGPARAMBASE_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_StringParamBase_TypeF());

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_Natron_Python_StringParamBase_TypeF(),
        StringParamBase_PythonToCpp_StringParamBase_PTR,
        is_StringParamBase_PythonToCpp_StringParamBase_PTR_Convertible,
        StringParamBase_PTR_CppToPython_StringParamBase);

    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::StringParamBase");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::StringParamBase*");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::StringParamBase&");
    Shiboken::Conversions::registerConverterName(converter, "Python::StringParamBase");
    Shiboken::Conversions::registerConverterName(converter, "Python::StringParamBase*");
    Shiboken::Conversions::registerConverterName(converter, "Python::StringParamBase&");
    Shiboken::Conversions::registerConverterName(converter, "StringParamBase");
    Shiboken::Conversions::registerConverterName(converter, "StringParamBase*");
    Shiboken::Conversions::registerConverterName(converter, "StringParamBase&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Natron::Python::StringParamBase).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::StringParamBaseWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_Natron_Python_StringParamBase_TypeF(), &Sbk_Natron_Python_StringParamBase_typeDiscovery);


    StringParamBaseWrapper::pysideInitQtMetaTypes();
}
