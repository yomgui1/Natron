
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
#include "natron_python_choiceparam_wrapper.h"

// inner classes

// Extra includes
#include <PyAppInstance.h>
#include <PyItemsTable.h>
#include <PyNode.h>
#include <PyParameter.h>
#include <list>
#include <utility>


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

void ChoiceParamWrapper::pysideInitQtMetaTypes()
{
}

ChoiceParamWrapper::~ChoiceParamWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_Natron_Python_ChoiceParamFunc_addAsDependencyOf(PyObject* self, PyObject* args)
{
    ChoiceParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ChoiceParamWrapper *>(reinterpret_cast< ::Natron::Python::ChoiceParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_CHOICEPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
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
    // 0: ChoiceParam::addAsDependencyOf(Natron::Python::Param*,int,int,QString,QString)
    if (numArgs == 5
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[4])))) {
        overloadId = 0; // addAsDependencyOf(Natron::Python::Param*,int,int,QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ChoiceParamFunc_addAsDependencyOf_TypeError;

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
            int cppResult = cppSelf->addAsDependencyOf(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ChoiceParamFunc_addAsDependencyOf_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ChoiceParam.addAsDependencyOf");
        return {};
}

static PyObject* Sbk_Natron_Python_ChoiceParamFunc_addOption(PyObject* self, PyObject* args)
{
    ChoiceParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ChoiceParamWrapper *>(reinterpret_cast< ::Natron::Python::ChoiceParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_CHOICEPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "addOption", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return {};


    // Overloaded function decisor
    // 0: ChoiceParam::addOption(QString,QString,QString)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
        overloadId = 0; // addOption(QString,QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ChoiceParamFunc_addOption_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QString cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // addOption(QString,QString,QString)
            cppSelf->addOption(cppArg0, cppArg1, cppArg2);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_ChoiceParamFunc_addOption_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ChoiceParam.addOption");
        return {};
}

static PyObject* Sbk_Natron_Python_ChoiceParamFunc_get(PyObject* self, PyObject* args, PyObject* kwds)
{
    ChoiceParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ChoiceParamWrapper *>(reinterpret_cast< ::Natron::Python::ChoiceParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_CHOICEPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
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
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ChoiceParam.get(): too many arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OO:get", &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: ChoiceParam::get(QString)const
    // 1: ChoiceParam::get(double,QString)const
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
    if (overloadId == -1) goto Sbk_Natron_Python_ChoiceParamFunc_get_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // get(const QString & view) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "view");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ChoiceParam.get(): got multiple values for keyword argument 'view'.");
                    return {};
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0]))))
                        goto Sbk_Natron_Python_ChoiceParamFunc_get_TypeError;
                }
            }
            ::QString cppArg0 = QLatin1String(kPyParamViewIdxMain);
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // get(QString)const
                int cppResult = const_cast<const ::ChoiceParamWrapper*>(cppSelf)->get(cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
            }
            break;
        }
        case 1: // get(double frame, const QString & view) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "view");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ChoiceParam.get(): got multiple values for keyword argument 'view'.");
                    return {};
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                        goto Sbk_Natron_Python_ChoiceParamFunc_get_TypeError;
                }
            }
            double cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = QLatin1String(kPyParamViewIdxMain);
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // get(double,QString)const
                int cppResult = const_cast<const ::ChoiceParamWrapper*>(cppSelf)->get(cppArg0, cppArg1);
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

    Sbk_Natron_Python_ChoiceParamFunc_get_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ChoiceParam.get");
        return {};
}

static PyObject* Sbk_Natron_Python_ChoiceParamFunc_getActiveOption(PyObject* self, PyObject* args, PyObject* kwds)
{
    ChoiceParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ChoiceParamWrapper *>(reinterpret_cast< ::Natron::Python::ChoiceParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_CHOICEPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
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
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ChoiceParam.getActiveOption(): too many arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|O:getActiveOption", &(pyArgs[0])))
        return {};


    // Overloaded function decisor
    // 0: ChoiceParam::getActiveOption(QString*,QString*,QString*,QString)const
    if (numArgs == 0) {
        overloadId = 0; // getActiveOption(QString*,QString*,QString*,QString)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 0; // getActiveOption(QString*,QString*,QString*,QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ChoiceParamFunc_getActiveOption_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "view");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ChoiceParam.getActiveOption(): got multiple values for keyword argument 'view'.");
                return {};
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0]))))
                    goto Sbk_Natron_Python_ChoiceParamFunc_getActiveOption_TypeError;
            }
        }
        ::QString cppArg0 = QLatin1String(kPyParamViewIdxMain);
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // getActiveOption(QString*,QString*,QString*,QString)const
            // Begin code injection

            QString optionID, optionLabel, optionHint;
            cppSelf->getActiveOption(&optionID,&optionLabel, &optionHint, cppArg0);
            pyResult = PyTuple_New(3);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &optionID));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &optionLabel));
            PyTuple_SET_ITEM(pyResult, 2, Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &optionHint));
            return pyResult;

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ChoiceParamFunc_getActiveOption_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ChoiceParam.getActiveOption");
        return {};
}

static PyObject* Sbk_Natron_Python_ChoiceParamFunc_getDefaultValue(PyObject* self)
{
    ChoiceParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ChoiceParamWrapper *>(reinterpret_cast< ::Natron::Python::ChoiceParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_CHOICEPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getDefaultValue()const
            int cppResult = const_cast<const ::ChoiceParamWrapper*>(cppSelf)->getDefaultValue();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_ChoiceParamFunc_getNumOptions(PyObject* self)
{
    ChoiceParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ChoiceParamWrapper *>(reinterpret_cast< ::Natron::Python::ChoiceParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_CHOICEPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getNumOptions()const
            int cppResult = const_cast<const ::ChoiceParamWrapper*>(cppSelf)->getNumOptions();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_ChoiceParamFunc_getOption(PyObject* self, PyObject* pyArg)
{
    ChoiceParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ChoiceParamWrapper *>(reinterpret_cast< ::Natron::Python::ChoiceParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_CHOICEPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: ChoiceParam::getOption(int,QString*,QString*,QString*)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // getOption(int,QString*,QString*,QString*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ChoiceParamFunc_getOption_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getOption(int,QString*,QString*,QString*)const
            // Begin code injection

            QString optionID, optionLabel, optionHint;
            bool ok = cppSelf->getOption(cppArg0, &optionID,&optionLabel, &optionHint);
            pyResult = PyTuple_New(4);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &ok));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &optionID));
            PyTuple_SET_ITEM(pyResult, 2, Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &optionLabel));
            PyTuple_SET_ITEM(pyResult, 3, Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &optionHint));
            return pyResult;

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ChoiceParamFunc_getOption_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.ChoiceParam.getOption");
        return {};
}

static PyObject* Sbk_Natron_Python_ChoiceParamFunc_getOptions(PyObject* self, PyObject* args)
{
    ChoiceParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ChoiceParamWrapper *>(reinterpret_cast< ::Natron::Python::ChoiceParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_CHOICEPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "getOptions", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return {};


    // Overloaded function decisor
    // 0: ChoiceParam::getOptions(std::list<QString>*,std::list<QString>*,std::list<QString>*)const
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_QSTRING_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_QSTRING_IDX], (pyArgs[2])))) {
        overloadId = 0; // getOptions(std::list<QString>*,std::list<QString>*,std::list<QString>*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ChoiceParamFunc_getOptions_TypeError;

    // Call function/method
    {
        ::std::list<QString >* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::std::list<QString >* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::std::list<QString >* cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // getOptions(std::list<QString>*,std::list<QString>*,std::list<QString>*)const
            const_cast<const ::ChoiceParamWrapper*>(cppSelf)->getOptions(cppArg0, cppArg1, cppArg2);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_ChoiceParamFunc_getOptions_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ChoiceParam.getOptions");
        return {};
}

static PyObject* Sbk_Natron_Python_ChoiceParamFunc_getValue(PyObject* self, PyObject* args, PyObject* kwds)
{
    ChoiceParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ChoiceParamWrapper *>(reinterpret_cast< ::Natron::Python::ChoiceParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_CHOICEPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
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
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ChoiceParam.getValue(): too many arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|O:getValue", &(pyArgs[0])))
        return {};


    // Overloaded function decisor
    // 0: ChoiceParam::getValue(QString)const
    if (numArgs == 0) {
        overloadId = 0; // getValue(QString)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 0; // getValue(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ChoiceParamFunc_getValue_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "view");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ChoiceParam.getValue(): got multiple values for keyword argument 'view'.");
                return {};
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0]))))
                    goto Sbk_Natron_Python_ChoiceParamFunc_getValue_TypeError;
            }
        }
        ::QString cppArg0 = QLatin1String(kPyParamViewIdxMain);
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // getValue(QString)const
            int cppResult = const_cast<const ::ChoiceParamWrapper*>(cppSelf)->getValue(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ChoiceParamFunc_getValue_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ChoiceParam.getValue");
        return {};
}

static PyObject* Sbk_Natron_Python_ChoiceParamFunc_getValueAtTime(PyObject* self, PyObject* args, PyObject* kwds)
{
    ChoiceParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ChoiceParamWrapper *>(reinterpret_cast< ::Natron::Python::ChoiceParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_CHOICEPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
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
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ChoiceParam.getValueAtTime(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ChoiceParam.getValueAtTime(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OO:getValueAtTime", &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: ChoiceParam::getValueAtTime(double,QString)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // getValueAtTime(double,QString)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 0; // getValueAtTime(double,QString)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ChoiceParamFunc_getValueAtTime_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "view");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ChoiceParam.getValueAtTime(): got multiple values for keyword argument 'view'.");
                return {};
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                    goto Sbk_Natron_Python_ChoiceParamFunc_getValueAtTime_TypeError;
            }
        }
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = QLatin1String(kPyParamViewIdxMain);
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // getValueAtTime(double,QString)const
            int cppResult = const_cast<const ::ChoiceParamWrapper*>(cppSelf)->getValueAtTime(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ChoiceParamFunc_getValueAtTime_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ChoiceParam.getValueAtTime");
        return {};
}

static PyObject* Sbk_Natron_Python_ChoiceParamFunc_restoreDefaultValue(PyObject* self, PyObject* args, PyObject* kwds)
{
    ChoiceParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ChoiceParamWrapper *>(reinterpret_cast< ::Natron::Python::ChoiceParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_CHOICEPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ChoiceParam.restoreDefaultValue(): too many arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|O:restoreDefaultValue", &(pyArgs[0])))
        return {};


    // Overloaded function decisor
    // 0: ChoiceParam::restoreDefaultValue(QString)
    if (numArgs == 0) {
        overloadId = 0; // restoreDefaultValue(QString)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 0; // restoreDefaultValue(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ChoiceParamFunc_restoreDefaultValue_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "view");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ChoiceParam.restoreDefaultValue(): got multiple values for keyword argument 'view'.");
                return {};
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0]))))
                    goto Sbk_Natron_Python_ChoiceParamFunc_restoreDefaultValue_TypeError;
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

    Sbk_Natron_Python_ChoiceParamFunc_restoreDefaultValue_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ChoiceParam.restoreDefaultValue");
        return {};
}

static PyObject* Sbk_Natron_Python_ChoiceParamFunc_set(PyObject* self, PyObject* args, PyObject* kwds)
{
    ChoiceParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ChoiceParamWrapper *>(reinterpret_cast< ::Natron::Python::ChoiceParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_CHOICEPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ChoiceParam.set(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ChoiceParam.set(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OOO:set", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return {};


    // Overloaded function decisor
    // 0: ChoiceParam::set(QString,QString)
    // 1: ChoiceParam::set(int,QString)
    // 2: ChoiceParam::set(int,double,QString)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // set(int,QString)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 2; // set(int,double,QString)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
                overloadId = 2; // set(int,double,QString)
            }
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 1; // set(int,QString)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // set(QString,QString)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 0; // set(QString,QString)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ChoiceParamFunc_set_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // set(const QString & label, const QString & view)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "view");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ChoiceParam.set(): got multiple values for keyword argument 'view'.");
                    return {};
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                        goto Sbk_Natron_Python_ChoiceParamFunc_set_TypeError;
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
        case 1: // set(int x, const QString & view)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "view");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ChoiceParam.set(): got multiple values for keyword argument 'view'.");
                    return {};
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                        goto Sbk_Natron_Python_ChoiceParamFunc_set_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = QLatin1String(kPyParamViewSetSpecAll);
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // set(int,QString)
                cppSelf->set(cppArg0, cppArg1);
            }
            break;
        }
        case 2: // set(int x, double frame, const QString & view)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "view");
                if (value && pyArgs[2]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ChoiceParam.set(): got multiple values for keyword argument 'view'.");
                    return {};
                } else if (value) {
                    pyArgs[2] = value;
                    if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2]))))
                        goto Sbk_Natron_Python_ChoiceParamFunc_set_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            double cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            ::QString cppArg2 = QLatin1String(kPyParamViewSetSpecAll);
            if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

            if (!PyErr_Occurred()) {
                // set(int,double,QString)
                cppSelf->set(cppArg0, cppArg1, cppArg2);
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_ChoiceParamFunc_set_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ChoiceParam.set");
        return {};
}

static PyObject* Sbk_Natron_Python_ChoiceParamFunc_setDefaultValue(PyObject* self, PyObject* pyArg)
{
    ChoiceParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ChoiceParamWrapper *>(reinterpret_cast< ::Natron::Python::ChoiceParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_CHOICEPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: ChoiceParam::setDefaultValue(QString)
    // 1: ChoiceParam::setDefaultValue(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 1; // setDefaultValue(int)
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setDefaultValue(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ChoiceParamFunc_setDefaultValue_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setDefaultValue(const QString & value)
        {
            ::QString cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // setDefaultValue(QString)
                cppSelf->setDefaultValue(cppArg0);
            }
            break;
        }
        case 1: // setDefaultValue(int value)
        {
            int cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // setDefaultValue(int)
                cppSelf->setDefaultValue(cppArg0);
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_ChoiceParamFunc_setDefaultValue_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.ChoiceParam.setDefaultValue");
        return {};
}

static PyObject* Sbk_Natron_Python_ChoiceParamFunc_setOptions(PyObject* self, PyObject* pyArg)
{
    ChoiceParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ChoiceParamWrapper *>(reinterpret_cast< ::Natron::Python::ChoiceParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_CHOICEPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: ChoiceParam::setOptions(std::list<QString>,std::list<QString>,std::list<QString>)
    // 1: ChoiceParam::setOptions(std::list<std::pair<QString,QString> >)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_STD_PAIR_QSTRING_QSTRING_IDX], (pyArg)))) {
        overloadId = 1; // setOptions(std::list<std::pair<QString,QString> >)
    } else if (PySequence_Check(pyArg)) {
        overloadId = 0; // setOptions(std::list<QString>,std::list<QString>,std::list<QString>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ChoiceParamFunc_setOptions_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setOptions(const std::list<QString > & optionIDs, const std::list<QString > & optionLabels, const std::list<QString > & optionHelps)
        {

            if (!PyErr_Occurred()) {
                // setOptions(std::list<QString>,std::list<QString>,std::list<QString>)
                // Begin code injection


                if (!PyList_Check(pyArg)) {
                    PyErr_SetString(PyExc_ValueError, "Argument must be a list of tuples");
                    return 0;
                }

                int listSize = PyList_Size(pyArg);
                if (listSize == 0) {
                    PyErr_SetString(PyExc_ValueError, "Argument must be a list of tuples");
                    return 0;
                }

                std::list<QString> optionIDs, optionLabels, optionHelps;
                for (int i = 0; i < listSize; ++i) {
                    PyObject* obj = PyList_GetItem(pyArg, i);
                    if (!PyTuple_Check(obj)) {
                        PyErr_SetString(PyExc_ValueError, "Argument must be a list of tuples");
                        return 0;
                    }
                    int tupleSize = PyTuple_Size(obj);
                    if (tupleSize != 3) {
                        PyErr_SetString(PyExc_ValueError, "Each option must be a tuple of 3 strings");
                        return 0;
                    }
                    PyObject* pyOptionId = PyTuple_GetItem(obj, 0);
                    PyObject* pyOptionLabel = PyTuple_GetItem(obj, 1);
                    PyObject* pyOptionHnt = PyTuple_GetItem(obj, 2);
                    ::QString optionId;
                    Shiboken::Conversions::pythonToCppCopy(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], pyOptionId, &(optionId));
                    ::QString optionLabel;
                    Shiboken::Conversions::pythonToCppCopy(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], pyOptionLabel, &(optionLabel));
                    ::QString optionHint;
                    Shiboken::Conversions::pythonToCppCopy(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], pyOptionHnt, &(optionHint));
                    optionIDs.push_back(optionId);
                    optionLabels.push_back(optionLabel);
                    optionHelps.push_back(optionHint);
                }

                cppSelf->setOptions(optionIDs, optionLabels, optionHelps);


                // End of code injection


            }
            break;
        }
        case 1: // setOptions(const std::list<std::pair< QString,QString > > & options)
        {
            ::std::list<std::pair< QString,QString > > cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // setOptions(std::list<std::pair<QString,QString> >)
                cppSelf->setOptions(cppArg0);
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_ChoiceParamFunc_setOptions_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.ChoiceParam.setOptions");
        return {};
}

static PyObject* Sbk_Natron_Python_ChoiceParamFunc_setValue(PyObject* self, PyObject* args, PyObject* kwds)
{
    ChoiceParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ChoiceParamWrapper *>(reinterpret_cast< ::Natron::Python::ChoiceParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_CHOICEPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ChoiceParam.setValue(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ChoiceParam.setValue(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OO:setValue", &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: ChoiceParam::setValue(QString,QString)
    // 1: ChoiceParam::setValue(int,QString)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 1; // setValue(int,QString)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 1; // setValue(int,QString)
        }
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setValue(QString,QString)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 0; // setValue(QString,QString)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ChoiceParamFunc_setValue_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // setValue(const QString & label, const QString & view)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "view");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ChoiceParam.setValue(): got multiple values for keyword argument 'view'.");
                    return {};
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                        goto Sbk_Natron_Python_ChoiceParamFunc_setValue_TypeError;
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
            break;
        }
        case 1: // setValue(int value, const QString & view)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "view");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ChoiceParam.setValue(): got multiple values for keyword argument 'view'.");
                    return {};
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                        goto Sbk_Natron_Python_ChoiceParamFunc_setValue_TypeError;
                }
            }
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = QLatin1String(kPyParamViewSetSpecAll);
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // setValue(int,QString)
                cppSelf->setValue(cppArg0, cppArg1);
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_ChoiceParamFunc_setValue_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ChoiceParam.setValue");
        return {};
}

static PyObject* Sbk_Natron_Python_ChoiceParamFunc_setValueAtTime(PyObject* self, PyObject* args, PyObject* kwds)
{
    ChoiceParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ChoiceParamWrapper *>(reinterpret_cast< ::Natron::Python::ChoiceParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_CHOICEPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ChoiceParam.setValueAtTime(): too many arguments");
        return {};
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ChoiceParam.setValueAtTime(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OOO:setValueAtTime", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return {};


    // Overloaded function decisor
    // 0: ChoiceParam::setValueAtTime(int,double,QString)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // setValueAtTime(int,double,QString)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
            overloadId = 0; // setValueAtTime(int,double,QString)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ChoiceParamFunc_setValueAtTime_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "view");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ChoiceParam.setValueAtTime(): got multiple values for keyword argument 'view'.");
                return {};
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2]))))
                    goto Sbk_Natron_Python_ChoiceParamFunc_setValueAtTime_TypeError;
            }
        }
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        double cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QString cppArg2 = QLatin1String(kPyParamViewSetSpecAll);
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // setValueAtTime(int,double,QString)
            cppSelf->setValueAtTime(cppArg0, cppArg1, cppArg2);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_ChoiceParamFunc_setValueAtTime_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ChoiceParam.setValueAtTime");
        return {};
}

static PyMethodDef Sbk_Natron_Python_ChoiceParam_methods[] = {
    {"addAsDependencyOf", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ChoiceParamFunc_addAsDependencyOf), METH_VARARGS},
    {"addOption", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ChoiceParamFunc_addOption), METH_VARARGS},
    {"get", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ChoiceParamFunc_get), METH_VARARGS|METH_KEYWORDS},
    {"getActiveOption", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ChoiceParamFunc_getActiveOption), METH_VARARGS|METH_KEYWORDS},
    {"getDefaultValue", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ChoiceParamFunc_getDefaultValue), METH_NOARGS},
    {"getNumOptions", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ChoiceParamFunc_getNumOptions), METH_NOARGS},
    {"getOption", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ChoiceParamFunc_getOption), METH_O},
    {"getOptions", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ChoiceParamFunc_getOptions), METH_VARARGS},
    {"getValue", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ChoiceParamFunc_getValue), METH_VARARGS|METH_KEYWORDS},
    {"getValueAtTime", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ChoiceParamFunc_getValueAtTime), METH_VARARGS|METH_KEYWORDS},
    {"restoreDefaultValue", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ChoiceParamFunc_restoreDefaultValue), METH_VARARGS|METH_KEYWORDS},
    {"set", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ChoiceParamFunc_set), METH_VARARGS|METH_KEYWORDS},
    {"setDefaultValue", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ChoiceParamFunc_setDefaultValue), METH_O},
    {"setOptions", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ChoiceParamFunc_setOptions), METH_O},
    {"setValue", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ChoiceParamFunc_setValue), METH_VARARGS|METH_KEYWORDS},
    {"setValueAtTime", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ChoiceParamFunc_setValueAtTime), METH_VARARGS|METH_KEYWORDS},

    {nullptr, nullptr} // Sentinel
};

} // extern "C"

static int Sbk_Natron_Python_ChoiceParam_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_Natron_Python_ChoiceParam_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_Natron_Python_ChoiceParam_Type = nullptr;
static SbkObjectType *Sbk_Natron_Python_ChoiceParam_TypeF(void)
{
    return _Sbk_Natron_Python_ChoiceParam_Type;
}

static PyType_Slot Sbk_Natron_Python_ChoiceParam_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_Natron_Python_ChoiceParam_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_Natron_Python_ChoiceParam_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_Natron_Python_ChoiceParam_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        nullptr},
    {Py_tp_new,         reinterpret_cast<void*>(SbkDummyNew /* PYSIDE-595: Prevent replacement of "0" with base->tp_new. */)},
    {0, nullptr}
};
static PyType_Spec Sbk_Natron_Python_ChoiceParam_spec = {
    "NatronEngine.Natron.Python.ChoiceParam",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Natron_Python_ChoiceParam_slots
};

} //extern "C"

static void* Sbk_Natron_Python_ChoiceParam_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::Natron::Python::Param >()))
        return dynamic_cast< ::Natron::Python::ChoiceParam*>(reinterpret_cast< ::Natron::Python::Param*>(cptr));
    return {};
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void ChoiceParam_PythonToCpp_ChoiceParam_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_Natron_Python_ChoiceParam_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_ChoiceParam_PythonToCpp_ChoiceParam_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_ChoiceParam_TypeF())))
        return ChoiceParam_PythonToCpp_ChoiceParam_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* ChoiceParam_PTR_CppToPython_ChoiceParam(const void* cppIn) {
    auto pyOut = reinterpret_cast<PyObject*>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::Natron::Python::ChoiceParam *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_Natron_Python_ChoiceParam_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *Natron_Python_ChoiceParam_SignatureStrings[] = {
    "NatronEngine.Natron.Python.ChoiceParam.addAsDependencyOf(param:NatronEngine.Natron.Python.Param,fromExprDimension:int,thisDimension:int,fromExprView:QString,thisView:QString)->int",
    "NatronEngine.Natron.Python.ChoiceParam.addOption(optionID:QString,optionLabel:QString,optionHelp:QString)",
    "1:NatronEngine.Natron.Python.ChoiceParam.get(view:QString=QLatin1String(kPyParamViewIdxMain))->int",
    "0:NatronEngine.Natron.Python.ChoiceParam.get(frame:double,view:QString=QLatin1String(kPyParamViewIdxMain))->int",
    "NatronEngine.Natron.Python.ChoiceParam.getActiveOption(optionID:PySide2.QtCore.QString,optionLabel:PySide2.QtCore.QString,optionHelp:PySide2.QtCore.QString,view:QString=QLatin1String(kPyParamViewIdxMain))",
    "NatronEngine.Natron.Python.ChoiceParam.getDefaultValue()->int",
    "NatronEngine.Natron.Python.ChoiceParam.getNumOptions()->int",
    "NatronEngine.Natron.Python.ChoiceParam.getOption(index:int,optionID:PySide2.QtCore.QString,optionLabel:PySide2.QtCore.QString,optionHelp:PySide2.QtCore.QString)->bool",
    "NatronEngine.Natron.Python.ChoiceParam.getOptions(optionIDs:QList[QString],optionLabels:QList[QString],optionHelps:QList[QString])",
    "NatronEngine.Natron.Python.ChoiceParam.getValue(view:QString=QLatin1String(kPyParamViewIdxMain))->int",
    "NatronEngine.Natron.Python.ChoiceParam.getValueAtTime(time:double,view:QString=QLatin1String(kPyParamViewIdxMain))->int",
    "NatronEngine.Natron.Python.ChoiceParam.restoreDefaultValue(view:QString=QLatin1String(kPyParamViewSetSpecAll))",
    "2:NatronEngine.Natron.Python.ChoiceParam.set(label:QString,view:QString=QLatin1String(kPyParamViewSetSpecAll))",
    "1:NatronEngine.Natron.Python.ChoiceParam.set(x:int,view:QString=QLatin1String(kPyParamViewSetSpecAll))",
    "0:NatronEngine.Natron.Python.ChoiceParam.set(x:int,frame:double,view:QString=QLatin1String(kPyParamViewSetSpecAll))",
    "1:NatronEngine.Natron.Python.ChoiceParam.setDefaultValue(value:QString)",
    "0:NatronEngine.Natron.Python.ChoiceParam.setDefaultValue(value:int)",
    "1:NatronEngine.Natron.Python.ChoiceParam.setOptions(optionIDs:QList[QString],optionLabels:QList[QString],optionHelps:QList[QString])",
    "0:NatronEngine.Natron.Python.ChoiceParam.setOptions(options:QList[QPair])",
    "1:NatronEngine.Natron.Python.ChoiceParam.setValue(label:QString,view:QString=QLatin1String(kPyParamViewSetSpecAll))",
    "0:NatronEngine.Natron.Python.ChoiceParam.setValue(value:int,view:QString=QLatin1String(kPyParamViewSetSpecAll))",
    "NatronEngine.Natron.Python.ChoiceParam.setValueAtTime(value:int,time:double,view:QString=QLatin1String(kPyParamViewSetSpecAll))",
    nullptr}; // Sentinel

void init_Natron_Python_ChoiceParam(PyObject* module)
{
    _Sbk_Natron_Python_ChoiceParam_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "ChoiceParam",
        "Natron::Python::ChoiceParam*",
        &Sbk_Natron_Python_ChoiceParam_spec,
        Natron_Python_ChoiceParam_SignatureStrings,
        &Shiboken::callCppDestructor< ::Natron::Python::ChoiceParam >,
        reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ANIMATEDPARAM_IDX]),
        0,
        0    );
    
    SbkNatronEngineTypes[SBK_NATRON_PYTHON_CHOICEPARAM_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_ChoiceParam_TypeF());

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_Natron_Python_ChoiceParam_TypeF(),
        ChoiceParam_PythonToCpp_ChoiceParam_PTR,
        is_ChoiceParam_PythonToCpp_ChoiceParam_PTR_Convertible,
        ChoiceParam_PTR_CppToPython_ChoiceParam);

    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::ChoiceParam");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::ChoiceParam*");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::ChoiceParam&");
    Shiboken::Conversions::registerConverterName(converter, "Python::ChoiceParam");
    Shiboken::Conversions::registerConverterName(converter, "Python::ChoiceParam*");
    Shiboken::Conversions::registerConverterName(converter, "Python::ChoiceParam&");
    Shiboken::Conversions::registerConverterName(converter, "ChoiceParam");
    Shiboken::Conversions::registerConverterName(converter, "ChoiceParam*");
    Shiboken::Conversions::registerConverterName(converter, "ChoiceParam&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Natron::Python::ChoiceParam).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::ChoiceParamWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_Natron_Python_ChoiceParam_TypeF(), &Sbk_Natron_Python_ChoiceParam_typeDiscovery);


    ChoiceParamWrapper::pysideInitQtMetaTypes();
}
