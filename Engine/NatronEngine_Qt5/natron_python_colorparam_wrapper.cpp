
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
#include "natron_python_colorparam_wrapper.h"

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

void ColorParamWrapper::pysideInitQtMetaTypes()
{
}

ColorParamWrapper::~ColorParamWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_Natron_Python_ColorParamFunc_addAsDependencyOf(PyObject* self, PyObject* args)
{
    ColorParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ColorParamWrapper *>(reinterpret_cast< ::Natron::Python::ColorParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_COLORPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
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
    // 0: ColorParam::addAsDependencyOf(Natron::Python::Param*,int,int,QString,QString)
    if (numArgs == 5
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[4])))) {
        overloadId = 0; // addAsDependencyOf(Natron::Python::Param*,int,int,QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ColorParamFunc_addAsDependencyOf_TypeError;

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
            double cppResult = cppSelf->addAsDependencyOf(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ColorParamFunc_addAsDependencyOf_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ColorParam.addAsDependencyOf");
        return {};
}

static PyObject* Sbk_Natron_Python_ColorParamFunc_get(PyObject* self, PyObject* args, PyObject* kwds)
{
    ColorParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ColorParamWrapper *>(reinterpret_cast< ::Natron::Python::ColorParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_COLORPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
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
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.get(): too many arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OO:get", &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: ColorParam::get(QString)const
    // 1: ColorParam::get(double,QString)const
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
    if (overloadId == -1) goto Sbk_Natron_Python_ColorParamFunc_get_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // get(const QString & view) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "view");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.get(): got multiple values for keyword argument 'view'.");
                    return {};
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0]))))
                        goto Sbk_Natron_Python_ColorParamFunc_get_TypeError;
                }
            }
            ::QString cppArg0 = QLatin1String(kPyParamViewIdxMain);
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // get(QString)const
                Natron::Python::ColorTuple* cppResult = new Natron::Python::ColorTuple(const_cast<const ::ColorParamWrapper*>(cppSelf)->get(cppArg0));
                pyResult = Shiboken::Object::newObject(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_COLORTUPLE_IDX]), cppResult, true, true);
            }
            break;
        }
        case 1: // get(double frame, const QString & view) const
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "view");
                if (value && pyArgs[1]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.get(): got multiple values for keyword argument 'view'.");
                    return {};
                } else if (value) {
                    pyArgs[1] = value;
                    if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                        goto Sbk_Natron_Python_ColorParamFunc_get_TypeError;
                }
            }
            double cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1 = QLatin1String(kPyParamViewIdxMain);
            if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // get(double,QString)const
                Natron::Python::ColorTuple* cppResult = new Natron::Python::ColorTuple(const_cast<const ::ColorParamWrapper*>(cppSelf)->get(cppArg0, cppArg1));
                pyResult = Shiboken::Object::newObject(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_COLORTUPLE_IDX]), cppResult, true, true);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ColorParamFunc_get_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ColorParam.get");
        return {};
}

static PyObject* Sbk_Natron_Python_ColorParamFunc_getDefaultValue(PyObject* self, PyObject* args, PyObject* kwds)
{
    ColorParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ColorParamWrapper *>(reinterpret_cast< ::Natron::Python::ColorParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_COLORPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
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
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.getDefaultValue(): too many arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|O:getDefaultValue", &(pyArgs[0])))
        return {};


    // Overloaded function decisor
    // 0: ColorParam::getDefaultValue(int)const
    if (numArgs == 0) {
        overloadId = 0; // getDefaultValue(int)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // getDefaultValue(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ColorParamFunc_getDefaultValue_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "dimension");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.getDefaultValue(): got multiple values for keyword argument 'dimension'.");
                return {};
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_Natron_Python_ColorParamFunc_getDefaultValue_TypeError;
            }
        }
        int cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // getDefaultValue(int)const
            double cppResult = const_cast<const ::ColorParamWrapper*>(cppSelf)->getDefaultValue(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ColorParamFunc_getDefaultValue_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ColorParam.getDefaultValue");
        return {};
}

static PyObject* Sbk_Natron_Python_ColorParamFunc_getDisplayMaximum(PyObject* self, PyObject* pyArg)
{
    ColorParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ColorParamWrapper *>(reinterpret_cast< ::Natron::Python::ColorParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_COLORPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: ColorParam::getDisplayMaximum(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // getDisplayMaximum(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ColorParamFunc_getDisplayMaximum_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getDisplayMaximum(int)const
            double cppResult = const_cast<const ::ColorParamWrapper*>(cppSelf)->getDisplayMaximum(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ColorParamFunc_getDisplayMaximum_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.ColorParam.getDisplayMaximum");
        return {};
}

static PyObject* Sbk_Natron_Python_ColorParamFunc_getDisplayMinimum(PyObject* self, PyObject* pyArg)
{
    ColorParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ColorParamWrapper *>(reinterpret_cast< ::Natron::Python::ColorParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_COLORPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: ColorParam::getDisplayMinimum(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // getDisplayMinimum(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ColorParamFunc_getDisplayMinimum_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getDisplayMinimum(int)const
            double cppResult = const_cast<const ::ColorParamWrapper*>(cppSelf)->getDisplayMinimum(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ColorParamFunc_getDisplayMinimum_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.ColorParam.getDisplayMinimum");
        return {};
}

static PyObject* Sbk_Natron_Python_ColorParamFunc_getMaximum(PyObject* self, PyObject* args, PyObject* kwds)
{
    ColorParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ColorParamWrapper *>(reinterpret_cast< ::Natron::Python::ColorParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_COLORPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
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
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.getMaximum(): too many arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|O:getMaximum", &(pyArgs[0])))
        return {};


    // Overloaded function decisor
    // 0: ColorParam::getMaximum(int)const
    if (numArgs == 0) {
        overloadId = 0; // getMaximum(int)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // getMaximum(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ColorParamFunc_getMaximum_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "dimension");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.getMaximum(): got multiple values for keyword argument 'dimension'.");
                return {};
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_Natron_Python_ColorParamFunc_getMaximum_TypeError;
            }
        }
        int cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // getMaximum(int)const
            double cppResult = const_cast<const ::ColorParamWrapper*>(cppSelf)->getMaximum(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ColorParamFunc_getMaximum_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ColorParam.getMaximum");
        return {};
}

static PyObject* Sbk_Natron_Python_ColorParamFunc_getMinimum(PyObject* self, PyObject* args, PyObject* kwds)
{
    ColorParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ColorParamWrapper *>(reinterpret_cast< ::Natron::Python::ColorParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_COLORPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
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
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.getMinimum(): too many arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|O:getMinimum", &(pyArgs[0])))
        return {};


    // Overloaded function decisor
    // 0: ColorParam::getMinimum(int)const
    if (numArgs == 0) {
        overloadId = 0; // getMinimum(int)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        overloadId = 0; // getMinimum(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ColorParamFunc_getMinimum_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "dimension");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.getMinimum(): got multiple values for keyword argument 'dimension'.");
                return {};
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_Natron_Python_ColorParamFunc_getMinimum_TypeError;
            }
        }
        int cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // getMinimum(int)const
            double cppResult = const_cast<const ::ColorParamWrapper*>(cppSelf)->getMinimum(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ColorParamFunc_getMinimum_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ColorParam.getMinimum");
        return {};
}

static PyObject* Sbk_Natron_Python_ColorParamFunc_getValue(PyObject* self, PyObject* args, PyObject* kwds)
{
    ColorParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ColorParamWrapper *>(reinterpret_cast< ::Natron::Python::ColorParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_COLORPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
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
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.getValue(): too many arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OO:getValue", &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: ColorParam::getValue(int,QString)const
    if (numArgs == 0) {
        overloadId = 0; // getValue(int,QString)const
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // getValue(int,QString)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 0; // getValue(int,QString)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ColorParamFunc_getValue_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "dimension");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.getValue(): got multiple values for keyword argument 'dimension'.");
                return {};
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_Natron_Python_ColorParamFunc_getValue_TypeError;
            }
            value = PyDict_GetItemString(kwds, "view");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.getValue(): got multiple values for keyword argument 'view'.");
                return {};
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                    goto Sbk_Natron_Python_ColorParamFunc_getValue_TypeError;
            }
        }
        int cppArg0 = 0;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = QLatin1String(kPyParamViewIdxMain);
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // getValue(int,QString)const
            double cppResult = const_cast<const ::ColorParamWrapper*>(cppSelf)->getValue(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ColorParamFunc_getValue_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ColorParam.getValue");
        return {};
}

static PyObject* Sbk_Natron_Python_ColorParamFunc_getValueAtTime(PyObject* self, PyObject* args, PyObject* kwds)
{
    ColorParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ColorParamWrapper *>(reinterpret_cast< ::Natron::Python::ColorParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_COLORPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
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
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.getValueAtTime(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.getValueAtTime(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OOO:getValueAtTime", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return {};


    // Overloaded function decisor
    // 0: ColorParam::getValueAtTime(double,int,QString)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // getValueAtTime(double,int,QString)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // getValueAtTime(double,int,QString)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
                overloadId = 0; // getValueAtTime(double,int,QString)const
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ColorParamFunc_getValueAtTime_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "dimension");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.getValueAtTime(): got multiple values for keyword argument 'dimension'.");
                return {};
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_Natron_Python_ColorParamFunc_getValueAtTime_TypeError;
            }
            value = PyDict_GetItemString(kwds, "view");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.getValueAtTime(): got multiple values for keyword argument 'view'.");
                return {};
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2]))))
                    goto Sbk_Natron_Python_ColorParamFunc_getValueAtTime_TypeError;
            }
        }
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QString cppArg2 = QLatin1String(kPyParamViewIdxMain);
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // getValueAtTime(double,int,QString)const
            double cppResult = const_cast<const ::ColorParamWrapper*>(cppSelf)->getValueAtTime(cppArg0, cppArg1, cppArg2);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_ColorParamFunc_getValueAtTime_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ColorParam.getValueAtTime");
        return {};
}

static PyObject* Sbk_Natron_Python_ColorParamFunc_restoreDefaultValue(PyObject* self, PyObject* args, PyObject* kwds)
{
    ColorParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ColorParamWrapper *>(reinterpret_cast< ::Natron::Python::ColorParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_COLORPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.restoreDefaultValue(): too many arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OO:restoreDefaultValue", &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: ColorParam::restoreDefaultValue(int,QString)
    if (numArgs == 0) {
        overloadId = 0; // restoreDefaultValue(int,QString)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // restoreDefaultValue(int,QString)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 0; // restoreDefaultValue(int,QString)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ColorParamFunc_restoreDefaultValue_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "dimension");
            if (value && pyArgs[0]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.restoreDefaultValue(): got multiple values for keyword argument 'dimension'.");
                return {};
            } else if (value) {
                pyArgs[0] = value;
                if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0]))))
                    goto Sbk_Natron_Python_ColorParamFunc_restoreDefaultValue_TypeError;
            }
            value = PyDict_GetItemString(kwds, "view");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.restoreDefaultValue(): got multiple values for keyword argument 'view'.");
                return {};
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                    goto Sbk_Natron_Python_ColorParamFunc_restoreDefaultValue_TypeError;
            }
        }
        int cppArg0 = -1;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = QLatin1String(kPyParamViewSetSpecAll);
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // restoreDefaultValue(int,QString)
            cppSelf->restoreDefaultValue(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_ColorParamFunc_restoreDefaultValue_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ColorParam.restoreDefaultValue");
        return {};
}

static PyObject* Sbk_Natron_Python_ColorParamFunc_set(PyObject* self, PyObject* args, PyObject* kwds)
{
    ColorParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ColorParamWrapper *>(reinterpret_cast< ::Natron::Python::ColorParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_COLORPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 6) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.set(): too many arguments");
        return {};
    } else if (numArgs < 4) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.set(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OOOOOO:set", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5])))
        return {};


    // Overloaded function decisor
    // 0: ColorParam::set(double,double,double,double,QString)
    // 1: ColorParam::set(double,double,double,double,double,QString)
    if (numArgs >= 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[3])))) {
        if (numArgs == 4) {
            overloadId = 0; // set(double,double,double,double,QString)
        } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[4])))) {
            if (numArgs == 5) {
                overloadId = 1; // set(double,double,double,double,double,QString)
            } else if ((pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[5])))) {
                overloadId = 1; // set(double,double,double,double,double,QString)
            }
        } else if ((pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[4])))) {
            overloadId = 0; // set(double,double,double,double,QString)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ColorParamFunc_set_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // set(double r, double g, double b, double a, const QString & view)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "view");
                if (value && pyArgs[4]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.set(): got multiple values for keyword argument 'view'.");
                    return {};
                } else if (value) {
                    pyArgs[4] = value;
                    if (!(pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[4]))))
                        goto Sbk_Natron_Python_ColorParamFunc_set_TypeError;
                }
            }
            double cppArg0;
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
                // set(double,double,double,double,QString)
                cppSelf->set(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
            }
            break;
        }
        case 1: // set(double r, double g, double b, double a, double frame, const QString & view)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "view");
                if (value && pyArgs[5]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.set(): got multiple values for keyword argument 'view'.");
                    return {};
                } else if (value) {
                    pyArgs[5] = value;
                    if (!(pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[5]))))
                        goto Sbk_Natron_Python_ColorParamFunc_set_TypeError;
                }
            }
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
            ::QString cppArg5 = QLatin1String(kPyParamViewSetSpecAll);
            if (pythonToCpp[5]) pythonToCpp[5](pyArgs[5], &cppArg5);

            if (!PyErr_Occurred()) {
                // set(double,double,double,double,double,QString)
                cppSelf->set(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5);
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_ColorParamFunc_set_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ColorParam.set");
        return {};
}

static PyObject* Sbk_Natron_Python_ColorParamFunc_setDefaultValue(PyObject* self, PyObject* args, PyObject* kwds)
{
    ColorParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ColorParamWrapper *>(reinterpret_cast< ::Natron::Python::ColorParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_COLORPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.setDefaultValue(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.setDefaultValue(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OO:setDefaultValue", &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: ColorParam::setDefaultValue(double,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setDefaultValue(double,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // setDefaultValue(double,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ColorParamFunc_setDefaultValue_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "dimension");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.setDefaultValue(): got multiple values for keyword argument 'dimension'.");
                return {};
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_Natron_Python_ColorParamFunc_setDefaultValue_TypeError;
            }
        }
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setDefaultValue(double,int)
            cppSelf->setDefaultValue(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_ColorParamFunc_setDefaultValue_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ColorParam.setDefaultValue");
        return {};
}

static PyObject* Sbk_Natron_Python_ColorParamFunc_setDisplayMaximum(PyObject* self, PyObject* args, PyObject* kwds)
{
    ColorParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ColorParamWrapper *>(reinterpret_cast< ::Natron::Python::ColorParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_COLORPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.setDisplayMaximum(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.setDisplayMaximum(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OO:setDisplayMaximum", &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: ColorParam::setDisplayMaximum(double,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setDisplayMaximum(double,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // setDisplayMaximum(double,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ColorParamFunc_setDisplayMaximum_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "dimension");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.setDisplayMaximum(): got multiple values for keyword argument 'dimension'.");
                return {};
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_Natron_Python_ColorParamFunc_setDisplayMaximum_TypeError;
            }
        }
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setDisplayMaximum(double,int)
            cppSelf->setDisplayMaximum(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_ColorParamFunc_setDisplayMaximum_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ColorParam.setDisplayMaximum");
        return {};
}

static PyObject* Sbk_Natron_Python_ColorParamFunc_setDisplayMinimum(PyObject* self, PyObject* args, PyObject* kwds)
{
    ColorParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ColorParamWrapper *>(reinterpret_cast< ::Natron::Python::ColorParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_COLORPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.setDisplayMinimum(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.setDisplayMinimum(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OO:setDisplayMinimum", &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: ColorParam::setDisplayMinimum(double,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setDisplayMinimum(double,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // setDisplayMinimum(double,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ColorParamFunc_setDisplayMinimum_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "dimension");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.setDisplayMinimum(): got multiple values for keyword argument 'dimension'.");
                return {};
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_Natron_Python_ColorParamFunc_setDisplayMinimum_TypeError;
            }
        }
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setDisplayMinimum(double,int)
            cppSelf->setDisplayMinimum(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_ColorParamFunc_setDisplayMinimum_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ColorParam.setDisplayMinimum");
        return {};
}

static PyObject* Sbk_Natron_Python_ColorParamFunc_setMaximum(PyObject* self, PyObject* args, PyObject* kwds)
{
    ColorParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ColorParamWrapper *>(reinterpret_cast< ::Natron::Python::ColorParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_COLORPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.setMaximum(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.setMaximum(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OO:setMaximum", &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: ColorParam::setMaximum(double,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setMaximum(double,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // setMaximum(double,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ColorParamFunc_setMaximum_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "dimension");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.setMaximum(): got multiple values for keyword argument 'dimension'.");
                return {};
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_Natron_Python_ColorParamFunc_setMaximum_TypeError;
            }
        }
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setMaximum(double,int)
            cppSelf->setMaximum(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_ColorParamFunc_setMaximum_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ColorParam.setMaximum");
        return {};
}

static PyObject* Sbk_Natron_Python_ColorParamFunc_setMinimum(PyObject* self, PyObject* args, PyObject* kwds)
{
    ColorParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ColorParamWrapper *>(reinterpret_cast< ::Natron::Python::ColorParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_COLORPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.setMinimum(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.setMinimum(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OO:setMinimum", &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: ColorParam::setMinimum(double,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setMinimum(double,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // setMinimum(double,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ColorParamFunc_setMinimum_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "dimension");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.setMinimum(): got multiple values for keyword argument 'dimension'.");
                return {};
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_Natron_Python_ColorParamFunc_setMinimum_TypeError;
            }
        }
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setMinimum(double,int)
            cppSelf->setMinimum(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_ColorParamFunc_setMinimum_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ColorParam.setMinimum");
        return {};
}

static PyObject* Sbk_Natron_Python_ColorParamFunc_setValue(PyObject* self, PyObject* args, PyObject* kwds)
{
    ColorParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ColorParamWrapper *>(reinterpret_cast< ::Natron::Python::ColorParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_COLORPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.setValue(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.setValue(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OOO:setValue", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return {};


    // Overloaded function decisor
    // 0: ColorParam::setValue(double,int,QString)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setValue(double,int,QString)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // setValue(double,int,QString)
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
                overloadId = 0; // setValue(double,int,QString)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ColorParamFunc_setValue_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "dimension");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.setValue(): got multiple values for keyword argument 'dimension'.");
                return {};
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_Natron_Python_ColorParamFunc_setValue_TypeError;
            }
            value = PyDict_GetItemString(kwds, "view");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.setValue(): got multiple values for keyword argument 'view'.");
                return {};
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2]))))
                    goto Sbk_Natron_Python_ColorParamFunc_setValue_TypeError;
            }
        }
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QString cppArg2 = QLatin1String(kPyParamViewSetSpecAll);
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // setValue(double,int,QString)
            cppSelf->setValue(cppArg0, cppArg1, cppArg2);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_ColorParamFunc_setValue_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ColorParam.setValue");
        return {};
}

static PyObject* Sbk_Natron_Python_ColorParamFunc_setValueAtTime(PyObject* self, PyObject* args, PyObject* kwds)
{
    ColorParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<ColorParamWrapper *>(reinterpret_cast< ::Natron::Python::ColorParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_COLORPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.setValueAtTime(): too many arguments");
        return {};
    } else if (numArgs < 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.setValueAtTime(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OOOO:setValueAtTime", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return {};


    // Overloaded function decisor
    // 0: ColorParam::setValueAtTime(double,double,int,QString)
    if (numArgs >= 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))) {
        if (numArgs == 2) {
            overloadId = 0; // setValueAtTime(double,double,int,QString)
        } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
            if (numArgs == 3) {
                overloadId = 0; // setValueAtTime(double,double,int,QString)
            } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3])))) {
                overloadId = 0; // setValueAtTime(double,double,int,QString)
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ColorParamFunc_setValueAtTime_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "dimension");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.setValueAtTime(): got multiple values for keyword argument 'dimension'.");
                return {};
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2]))))
                    goto Sbk_Natron_Python_ColorParamFunc_setValueAtTime_TypeError;
            }
            value = PyDict_GetItemString(kwds, "view");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.ColorParam.setValueAtTime(): got multiple values for keyword argument 'view'.");
                return {};
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[3]))))
                    goto Sbk_Natron_Python_ColorParamFunc_setValueAtTime_TypeError;
            }
        }
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        double cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2 = 0;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
        ::QString cppArg3 = QLatin1String(kPyParamViewSetSpecAll);
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // setValueAtTime(double,double,int,QString)
            cppSelf->setValueAtTime(cppArg0, cppArg1, cppArg2, cppArg3);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_ColorParamFunc_setValueAtTime_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ColorParam.setValueAtTime");
        return {};
}

static PyMethodDef Sbk_Natron_Python_ColorParam_methods[] = {
    {"addAsDependencyOf", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ColorParamFunc_addAsDependencyOf), METH_VARARGS},
    {"get", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ColorParamFunc_get), METH_VARARGS|METH_KEYWORDS},
    {"getDefaultValue", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ColorParamFunc_getDefaultValue), METH_VARARGS|METH_KEYWORDS},
    {"getDisplayMaximum", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ColorParamFunc_getDisplayMaximum), METH_O},
    {"getDisplayMinimum", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ColorParamFunc_getDisplayMinimum), METH_O},
    {"getMaximum", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ColorParamFunc_getMaximum), METH_VARARGS|METH_KEYWORDS},
    {"getMinimum", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ColorParamFunc_getMinimum), METH_VARARGS|METH_KEYWORDS},
    {"getValue", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ColorParamFunc_getValue), METH_VARARGS|METH_KEYWORDS},
    {"getValueAtTime", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ColorParamFunc_getValueAtTime), METH_VARARGS|METH_KEYWORDS},
    {"restoreDefaultValue", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ColorParamFunc_restoreDefaultValue), METH_VARARGS|METH_KEYWORDS},
    {"set", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ColorParamFunc_set), METH_VARARGS|METH_KEYWORDS},
    {"setDefaultValue", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ColorParamFunc_setDefaultValue), METH_VARARGS|METH_KEYWORDS},
    {"setDisplayMaximum", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ColorParamFunc_setDisplayMaximum), METH_VARARGS|METH_KEYWORDS},
    {"setDisplayMinimum", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ColorParamFunc_setDisplayMinimum), METH_VARARGS|METH_KEYWORDS},
    {"setMaximum", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ColorParamFunc_setMaximum), METH_VARARGS|METH_KEYWORDS},
    {"setMinimum", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ColorParamFunc_setMinimum), METH_VARARGS|METH_KEYWORDS},
    {"setValue", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ColorParamFunc_setValue), METH_VARARGS|METH_KEYWORDS},
    {"setValueAtTime", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ColorParamFunc_setValueAtTime), METH_VARARGS|METH_KEYWORDS},

    {nullptr, nullptr} // Sentinel
};

} // extern "C"

static int Sbk_Natron_Python_ColorParam_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_Natron_Python_ColorParam_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_Natron_Python_ColorParam_Type = nullptr;
static SbkObjectType *Sbk_Natron_Python_ColorParam_TypeF(void)
{
    return _Sbk_Natron_Python_ColorParam_Type;
}

static PyType_Slot Sbk_Natron_Python_ColorParam_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_Natron_Python_ColorParam_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_Natron_Python_ColorParam_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_Natron_Python_ColorParam_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        nullptr},
    {Py_tp_new,         reinterpret_cast<void*>(SbkDummyNew /* PYSIDE-595: Prevent replacement of "0" with base->tp_new. */)},
    {0, nullptr}
};
static PyType_Spec Sbk_Natron_Python_ColorParam_spec = {
    "NatronEngine.Natron.Python.ColorParam",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Natron_Python_ColorParam_slots
};

} //extern "C"

static void* Sbk_Natron_Python_ColorParam_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::Natron::Python::Param >()))
        return dynamic_cast< ::Natron::Python::ColorParam*>(reinterpret_cast< ::Natron::Python::Param*>(cptr));
    return {};
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void ColorParam_PythonToCpp_ColorParam_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_Natron_Python_ColorParam_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_ColorParam_PythonToCpp_ColorParam_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_ColorParam_TypeF())))
        return ColorParam_PythonToCpp_ColorParam_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* ColorParam_PTR_CppToPython_ColorParam(const void* cppIn) {
    auto pyOut = reinterpret_cast<PyObject*>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::Natron::Python::ColorParam *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_Natron_Python_ColorParam_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *Natron_Python_ColorParam_SignatureStrings[] = {
    "NatronEngine.Natron.Python.ColorParam.addAsDependencyOf(param:NatronEngine.Natron.Python.Param,fromExprDimension:int,thisDimension:int,fromExprView:QString,thisView:QString)->double",
    "1:NatronEngine.Natron.Python.ColorParam.get(view:QString=QLatin1String(kPyParamViewIdxMain))->NatronEngine.Natron.Python.ColorTuple",
    "0:NatronEngine.Natron.Python.ColorParam.get(frame:double,view:QString=QLatin1String(kPyParamViewIdxMain))->NatronEngine.Natron.Python.ColorTuple",
    "NatronEngine.Natron.Python.ColorParam.getDefaultValue(dimension:int=0)->double",
    "NatronEngine.Natron.Python.ColorParam.getDisplayMaximum(dimension:int)->double",
    "NatronEngine.Natron.Python.ColorParam.getDisplayMinimum(dimension:int)->double",
    "NatronEngine.Natron.Python.ColorParam.getMaximum(dimension:int=0)->double",
    "NatronEngine.Natron.Python.ColorParam.getMinimum(dimension:int=0)->double",
    "NatronEngine.Natron.Python.ColorParam.getValue(dimension:int=0,view:QString=QLatin1String(kPyParamViewIdxMain))->double",
    "NatronEngine.Natron.Python.ColorParam.getValueAtTime(time:double,dimension:int=0,view:QString=QLatin1String(kPyParamViewIdxMain))->double",
    "NatronEngine.Natron.Python.ColorParam.restoreDefaultValue(dimension:int=-1,view:QString=QLatin1String(kPyParamViewSetSpecAll))",
    "1:NatronEngine.Natron.Python.ColorParam.set(r:double,g:double,b:double,a:double,view:QString=QLatin1String(kPyParamViewSetSpecAll))",
    "0:NatronEngine.Natron.Python.ColorParam.set(r:double,g:double,b:double,a:double,frame:double,view:QString=QLatin1String(kPyParamViewSetSpecAll))",
    "NatronEngine.Natron.Python.ColorParam.setDefaultValue(value:double,dimension:int=0)",
    "NatronEngine.Natron.Python.ColorParam.setDisplayMaximum(maximum:double,dimension:int=0)",
    "NatronEngine.Natron.Python.ColorParam.setDisplayMinimum(minimum:double,dimension:int=0)",
    "NatronEngine.Natron.Python.ColorParam.setMaximum(maximum:double,dimension:int=0)",
    "NatronEngine.Natron.Python.ColorParam.setMinimum(minimum:double,dimension:int=0)",
    "NatronEngine.Natron.Python.ColorParam.setValue(value:double,dimension:int=0,view:QString=QLatin1String(kPyParamViewSetSpecAll))",
    "NatronEngine.Natron.Python.ColorParam.setValueAtTime(value:double,time:double,dimension:int=0,view:QString=QLatin1String(kPyParamViewSetSpecAll))",
    nullptr}; // Sentinel

void init_Natron_Python_ColorParam(PyObject* module)
{
    _Sbk_Natron_Python_ColorParam_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "ColorParam",
        "Natron::Python::ColorParam*",
        &Sbk_Natron_Python_ColorParam_spec,
        Natron_Python_ColorParam_SignatureStrings,
        &Shiboken::callCppDestructor< ::Natron::Python::ColorParam >,
        reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ANIMATEDPARAM_IDX]),
        0,
        0    );
    
    SbkNatronEngineTypes[SBK_NATRON_PYTHON_COLORPARAM_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_ColorParam_TypeF());

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_Natron_Python_ColorParam_TypeF(),
        ColorParam_PythonToCpp_ColorParam_PTR,
        is_ColorParam_PythonToCpp_ColorParam_PTR_Convertible,
        ColorParam_PTR_CppToPython_ColorParam);

    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::ColorParam");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::ColorParam*");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::ColorParam&");
    Shiboken::Conversions::registerConverterName(converter, "Python::ColorParam");
    Shiboken::Conversions::registerConverterName(converter, "Python::ColorParam*");
    Shiboken::Conversions::registerConverterName(converter, "Python::ColorParam&");
    Shiboken::Conversions::registerConverterName(converter, "ColorParam");
    Shiboken::Conversions::registerConverterName(converter, "ColorParam*");
    Shiboken::Conversions::registerConverterName(converter, "ColorParam&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Natron::Python::ColorParam).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::ColorParamWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_Natron_Python_ColorParam_TypeF(), &Sbk_Natron_Python_ColorParam_typeDiscovery);


    ColorParamWrapper::pysideInitQtMetaTypes();
}
