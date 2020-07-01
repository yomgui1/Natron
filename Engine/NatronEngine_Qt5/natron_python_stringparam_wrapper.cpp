
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
#include "natron_python_stringparam_wrapper.h"

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

void StringParamWrapper::pysideInitQtMetaTypes()
{
    qRegisterMetaType< ::Natron::Python::StringParam::TypeEnum >("StringParam::TypeEnum");
    qRegisterMetaType< ::Natron::Python::StringParam::TypeEnum >("Natron::StringParam::TypeEnum");
}

StringParamWrapper::~StringParamWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_Natron_Python_StringParamFunc_setType(PyObject* self, PyObject* pyArg)
{
    StringParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<StringParamWrapper *>(reinterpret_cast< ::Natron::Python::StringParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STRINGPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: StringParam::setType(Natron::Python::StringParam::TypeEnum)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(*PepType_SGTP(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STRINGPARAM_TYPEENUM_IDX])->converter, (pyArg)))) {
        overloadId = 0; // setType(Natron::Python::StringParam::TypeEnum)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_StringParamFunc_setType_TypeError;

    // Call function/method
    {
        ::Natron::Python::StringParam::TypeEnum cppArg0{Natron::Python::StringParam::eStringTypeLabel};
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setType(Natron::Python::StringParam::TypeEnum)
            cppSelf->setType(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_StringParamFunc_setType_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.StringParam.setType");
        return {};
}

static PyMethodDef Sbk_Natron_Python_StringParam_methods[] = {
    {"setType", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_StringParamFunc_setType), METH_O},

    {nullptr, nullptr} // Sentinel
};

} // extern "C"

static int Sbk_Natron_Python_StringParam_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_Natron_Python_StringParam_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_Natron_Python_StringParam_Type = nullptr;
static SbkObjectType *Sbk_Natron_Python_StringParam_TypeF(void)
{
    return _Sbk_Natron_Python_StringParam_Type;
}

static PyType_Slot Sbk_Natron_Python_StringParam_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_Natron_Python_StringParam_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_Natron_Python_StringParam_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_Natron_Python_StringParam_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        nullptr},
    {Py_tp_new,         reinterpret_cast<void*>(SbkDummyNew /* PYSIDE-595: Prevent replacement of "0" with base->tp_new. */)},
    {0, nullptr}
};
static PyType_Spec Sbk_Natron_Python_StringParam_spec = {
    "NatronEngine.Natron.Python.StringParam",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Natron_Python_StringParam_slots
};

} //extern "C"

static void* Sbk_Natron_Python_StringParam_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::Natron::Python::Param >()))
        return dynamic_cast< ::Natron::Python::StringParam*>(reinterpret_cast< ::Natron::Python::Param*>(cptr));
    return {};
}


// Type conversion functions.

// Python to C++ enum conversion.
static void Natron_Python_StringParam_TypeEnum_PythonToCpp_Natron_Python_StringParam_TypeEnum(PyObject* pyIn, void* cppOut) {
    *reinterpret_cast<::Natron::Python::StringParam::TypeEnum*>(cppOut) =
        static_cast<::Natron::Python::StringParam::TypeEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_Python_StringParam_TypeEnum_PythonToCpp_Natron_Python_StringParam_TypeEnum_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_PYTHON_STRINGPARAM_TYPEENUM_IDX]))
        return Natron_Python_StringParam_TypeEnum_PythonToCpp_Natron_Python_StringParam_TypeEnum;
    return {};
}
static PyObject* Natron_Python_StringParam_TypeEnum_CppToPython_Natron_Python_StringParam_TypeEnum(const void* cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::Python::StringParam::TypeEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STRINGPARAM_TYPEENUM_IDX], castCppIn);

}

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void StringParam_PythonToCpp_StringParam_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_Natron_Python_StringParam_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_StringParam_PythonToCpp_StringParam_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_StringParam_TypeF())))
        return StringParam_PythonToCpp_StringParam_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* StringParam_PTR_CppToPython_StringParam(const void* cppIn) {
    auto pyOut = reinterpret_cast<PyObject*>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::Natron::Python::StringParam *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_Natron_Python_StringParam_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *Natron_Python_StringParam_SignatureStrings[] = {
    "NatronEngine.Natron.Python.StringParam.setType(type:NatronEngine.Natron.Python.StringParam.TypeEnum)",
    nullptr}; // Sentinel

void init_Natron_Python_StringParam(PyObject* module)
{
    _Sbk_Natron_Python_StringParam_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "StringParam",
        "Natron::Python::StringParam*",
        &Sbk_Natron_Python_StringParam_spec,
        Natron_Python_StringParam_SignatureStrings,
        &Shiboken::callCppDestructor< ::Natron::Python::StringParam >,
        reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STRINGPARAMBASE_IDX]),
        0,
        0    );
    
    SbkNatronEngineTypes[SBK_NATRON_PYTHON_STRINGPARAM_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_StringParam_TypeF());

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_Natron_Python_StringParam_TypeF(),
        StringParam_PythonToCpp_StringParam_PTR,
        is_StringParam_PythonToCpp_StringParam_PTR_Convertible,
        StringParam_PTR_CppToPython_StringParam);

    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::StringParam");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::StringParam*");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::StringParam&");
    Shiboken::Conversions::registerConverterName(converter, "Python::StringParam");
    Shiboken::Conversions::registerConverterName(converter, "Python::StringParam*");
    Shiboken::Conversions::registerConverterName(converter, "Python::StringParam&");
    Shiboken::Conversions::registerConverterName(converter, "StringParam");
    Shiboken::Conversions::registerConverterName(converter, "StringParam*");
    Shiboken::Conversions::registerConverterName(converter, "StringParam&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Natron::Python::StringParam).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::StringParamWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_Natron_Python_StringParam_TypeF(), &Sbk_Natron_Python_StringParam_typeDiscovery);

    // Initialization of enums.

    // Initialization of enum 'TypeEnum'.
    SbkNatronEngineTypes[SBK_NATRON_PYTHON_STRINGPARAM_TYPEENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_Python_StringParam_TypeF(),
        "TypeEnum",
        "NatronEngine.Natron.Python.StringParam.TypeEnum",
        "Natron::Python::StringParam::TypeEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_PYTHON_STRINGPARAM_TYPEENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STRINGPARAM_TYPEENUM_IDX],
        Sbk_Natron_Python_StringParam_TypeF(), "eStringTypeLabel", (long) Natron::Python::StringParam::TypeEnum::eStringTypeLabel))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STRINGPARAM_TYPEENUM_IDX],
        Sbk_Natron_Python_StringParam_TypeF(), "eStringTypeMultiLine", (long) Natron::Python::StringParam::TypeEnum::eStringTypeMultiLine))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STRINGPARAM_TYPEENUM_IDX],
        Sbk_Natron_Python_StringParam_TypeF(), "eStringTypeRichTextMultiLine", (long) Natron::Python::StringParam::TypeEnum::eStringTypeRichTextMultiLine))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STRINGPARAM_TYPEENUM_IDX],
        Sbk_Natron_Python_StringParam_TypeF(), "eStringTypeCustom", (long) Natron::Python::StringParam::TypeEnum::eStringTypeCustom))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STRINGPARAM_TYPEENUM_IDX],
        Sbk_Natron_Python_StringParam_TypeF(), "eStringTypeDefault", (long) Natron::Python::StringParam::TypeEnum::eStringTypeDefault))
        return;
    // Register converter for enum 'Natron::Python::StringParam::TypeEnum'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STRINGPARAM_TYPEENUM_IDX],
            Natron_Python_StringParam_TypeEnum_CppToPython_Natron_Python_StringParam_TypeEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_Python_StringParam_TypeEnum_PythonToCpp_Natron_Python_StringParam_TypeEnum,
            is_Natron_Python_StringParam_TypeEnum_PythonToCpp_Natron_Python_StringParam_TypeEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STRINGPARAM_TYPEENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::Python::StringParam::TypeEnum");
        Shiboken::Conversions::registerConverterName(converter, "Python::StringParam::TypeEnum");
        Shiboken::Conversions::registerConverterName(converter, "StringParam::TypeEnum");
        Shiboken::Conversions::registerConverterName(converter, "TypeEnum");
    }
    // End of 'TypeEnum' enum.


    StringParamWrapper::pysideInitQtMetaTypes();
}
