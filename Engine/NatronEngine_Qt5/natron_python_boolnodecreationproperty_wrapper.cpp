
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
#include "natron_python_boolnodecreationproperty_wrapper.h"

// inner classes

// Extra includes
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

// Native ---------------------------------------------------------

void BoolNodeCreationPropertyWrapper::pysideInitQtMetaTypes()
{
}

BoolNodeCreationPropertyWrapper::BoolNodeCreationPropertyWrapper(bool value) : Natron::Python::BoolNodeCreationProperty(value)
{
    // ... middle
}

BoolNodeCreationPropertyWrapper::BoolNodeCreationPropertyWrapper(const std::vector<bool > & values) : Natron::Python::BoolNodeCreationProperty(values)
{
    // ... middle
}

BoolNodeCreationPropertyWrapper::~BoolNodeCreationPropertyWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_Natron_Python_BoolNodeCreationProperty_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::Natron::Python::BoolNodeCreationProperty >()))
        return -1;

    ::BoolNodeCreationPropertyWrapper* cptr{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BoolNodeCreationProperty(): too many arguments");
        return -1;
    }

    if (!PyArg_ParseTuple(args, "|O:BoolNodeCreationProperty", &(pyArgs[0])))
        return -1;


    // Overloaded function decisor
    // 0: BoolNodeCreationProperty::BoolNodeCreationProperty(bool)
    // 1: BoolNodeCreationProperty::BoolNodeCreationProperty(std::vector<bool>)
    if (numArgs == 0) {
        overloadId = 1; // BoolNodeCreationProperty(std::vector<bool>)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[0])))) {
        overloadId = 0; // BoolNodeCreationProperty(bool)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_VECTOR_BOOL_IDX], (pyArgs[0])))) {
        overloadId = 1; // BoolNodeCreationProperty(std::vector<bool>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_BoolNodeCreationProperty_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // BoolNodeCreationProperty(bool value)
        {
            bool cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // BoolNodeCreationProperty(bool)
                cptr = new ::BoolNodeCreationPropertyWrapper(cppArg0);
            }
            break;
        }
        case 1: // BoolNodeCreationProperty(const std::vector<bool > & values)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "values");
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BoolNodeCreationProperty(): got multiple values for keyword argument 'values'.");
                    return -1;
                } else if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_VECTOR_BOOL_IDX], (pyArgs[0]))))
                        goto Sbk_Natron_Python_BoolNodeCreationProperty_Init_TypeError;
                }
            }
            ::std::vector<bool > cppArg0;
            if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // BoolNodeCreationProperty(std::vector<bool>)
                cptr = new ::BoolNodeCreationPropertyWrapper(cppArg0);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::Natron::Python::BoolNodeCreationProperty >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_Natron_Python_BoolNodeCreationProperty_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    if (Shiboken::BindingManager::instance().hasWrapper(cptr)) {
        Shiboken::BindingManager::instance().releaseWrapper(Shiboken::BindingManager::instance().retrieveWrapper(cptr));
    }
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_Natron_Python_BoolNodeCreationProperty_Init_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.BoolNodeCreationProperty");
        return -1;
}

static PyObject* Sbk_Natron_Python_BoolNodeCreationPropertyFunc_getValues(PyObject* self)
{
    ::Natron::Python::BoolNodeCreationProperty* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::BoolNodeCreationProperty *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_BOOLNODECREATIONPROPERTY_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getValues()const
            const std::vector<bool > & cppResult = const_cast<const ::Natron::Python::BoolNodeCreationProperty*>(cppSelf)->getValues();
            pyResult = Shiboken::Conversions::copyToPython(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_VECTOR_BOOL_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_BoolNodeCreationPropertyFunc_setValue(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::Natron::Python::BoolNodeCreationProperty* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::BoolNodeCreationProperty *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_BOOLNODECREATIONPROPERTY_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BoolNodeCreationProperty.setValue(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BoolNodeCreationProperty.setValue(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OO:setValue", &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: BoolNodeCreationProperty::setValue(bool,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // setValue(bool,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // setValue(bool,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_BoolNodeCreationPropertyFunc_setValue_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "index");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.BoolNodeCreationProperty.setValue(): got multiple values for keyword argument 'index'.");
                return {};
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_Natron_Python_BoolNodeCreationPropertyFunc_setValue_TypeError;
            }
        }
        bool cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setValue(bool,int)
            cppSelf->setValue(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_BoolNodeCreationPropertyFunc_setValue_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.BoolNodeCreationProperty.setValue");
        return {};
}

static PyMethodDef Sbk_Natron_Python_BoolNodeCreationProperty_methods[] = {
    {"getValues", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_BoolNodeCreationPropertyFunc_getValues), METH_NOARGS},
    {"setValue", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_BoolNodeCreationPropertyFunc_setValue), METH_VARARGS|METH_KEYWORDS},

    {nullptr, nullptr} // Sentinel
};

} // extern "C"

static int Sbk_Natron_Python_BoolNodeCreationProperty_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_Natron_Python_BoolNodeCreationProperty_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_Natron_Python_BoolNodeCreationProperty_Type = nullptr;
static SbkObjectType *Sbk_Natron_Python_BoolNodeCreationProperty_TypeF(void)
{
    return _Sbk_Natron_Python_BoolNodeCreationProperty_Type;
}

static PyType_Slot Sbk_Natron_Python_BoolNodeCreationProperty_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_Natron_Python_BoolNodeCreationProperty_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_Natron_Python_BoolNodeCreationProperty_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_Natron_Python_BoolNodeCreationProperty_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        reinterpret_cast<void*>(Sbk_Natron_Python_BoolNodeCreationProperty_Init)},
    {Py_tp_new,         reinterpret_cast<void*>(SbkObjectTpNew)},
    {0, nullptr}
};
static PyType_Spec Sbk_Natron_Python_BoolNodeCreationProperty_spec = {
    "NatronEngine.Natron.Python.BoolNodeCreationProperty",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Natron_Python_BoolNodeCreationProperty_slots
};

} //extern "C"


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void BoolNodeCreationProperty_PythonToCpp_BoolNodeCreationProperty_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_Natron_Python_BoolNodeCreationProperty_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_BoolNodeCreationProperty_PythonToCpp_BoolNodeCreationProperty_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_BoolNodeCreationProperty_TypeF())))
        return BoolNodeCreationProperty_PythonToCpp_BoolNodeCreationProperty_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* BoolNodeCreationProperty_PTR_CppToPython_BoolNodeCreationProperty(const void* cppIn) {
    auto pyOut = reinterpret_cast<PyObject*>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::Natron::Python::BoolNodeCreationProperty *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_Natron_Python_BoolNodeCreationProperty_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *Natron_Python_BoolNodeCreationProperty_SignatureStrings[] = {
    "1:NatronEngine.Natron.Python.BoolNodeCreationProperty(value:bool)",
    "0:NatronEngine.Natron.Python.BoolNodeCreationProperty(values:QVector[bool]=std.vector< bool >())",
    "NatronEngine.Natron.Python.BoolNodeCreationProperty.getValues()->QVector[bool]",
    "NatronEngine.Natron.Python.BoolNodeCreationProperty.setValue(value:bool,index:int=0)",
    nullptr}; // Sentinel

void init_Natron_Python_BoolNodeCreationProperty(PyObject* module)
{
    _Sbk_Natron_Python_BoolNodeCreationProperty_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "BoolNodeCreationProperty",
        "Natron::Python::BoolNodeCreationProperty*",
        &Sbk_Natron_Python_BoolNodeCreationProperty_spec,
        Natron_Python_BoolNodeCreationProperty_SignatureStrings,
        &Shiboken::callCppDestructor< ::Natron::Python::BoolNodeCreationProperty >,
        reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_NODECREATIONPROPERTY_IDX]),
        0,
        0    );
    
    SbkNatronEngineTypes[SBK_NATRON_PYTHON_BOOLNODECREATIONPROPERTY_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_BoolNodeCreationProperty_TypeF());

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_Natron_Python_BoolNodeCreationProperty_TypeF(),
        BoolNodeCreationProperty_PythonToCpp_BoolNodeCreationProperty_PTR,
        is_BoolNodeCreationProperty_PythonToCpp_BoolNodeCreationProperty_PTR_Convertible,
        BoolNodeCreationProperty_PTR_CppToPython_BoolNodeCreationProperty);

    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::BoolNodeCreationProperty");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::BoolNodeCreationProperty*");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::BoolNodeCreationProperty&");
    Shiboken::Conversions::registerConverterName(converter, "Python::BoolNodeCreationProperty");
    Shiboken::Conversions::registerConverterName(converter, "Python::BoolNodeCreationProperty*");
    Shiboken::Conversions::registerConverterName(converter, "Python::BoolNodeCreationProperty&");
    Shiboken::Conversions::registerConverterName(converter, "BoolNodeCreationProperty");
    Shiboken::Conversions::registerConverterName(converter, "BoolNodeCreationProperty*");
    Shiboken::Conversions::registerConverterName(converter, "BoolNodeCreationProperty&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Natron::Python::BoolNodeCreationProperty).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::BoolNodeCreationPropertyWrapper).name());



    BoolNodeCreationPropertyWrapper::pysideInitQtMetaTypes();
}
