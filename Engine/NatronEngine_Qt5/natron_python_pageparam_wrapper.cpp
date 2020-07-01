
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
#include "natron_python_pageparam_wrapper.h"

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

void PageParamWrapper::pysideInitQtMetaTypes()
{
}

PageParamWrapper::~PageParamWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_Natron_Python_PageParamFunc_addParam(PyObject* self, PyObject* pyArg)
{
    PageParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<PageParamWrapper *>(reinterpret_cast< ::Natron::Python::PageParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PAGEPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: PageParam::addParam(const Natron::Python::Param*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX]), (pyArg)))) {
        overloadId = 0; // addParam(const Natron::Python::Param*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PageParamFunc_addParam_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return {};
        ::Natron::Python::Param* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // addParam(const Natron::Python::Param*)
            cppSelf->addParam(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_PageParamFunc_addParam_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.PageParam.addParam");
        return {};
}

static PyMethodDef Sbk_Natron_Python_PageParam_methods[] = {
    {"addParam", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PageParamFunc_addParam), METH_O},

    {nullptr, nullptr} // Sentinel
};

} // extern "C"

static int Sbk_Natron_Python_PageParam_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_Natron_Python_PageParam_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_Natron_Python_PageParam_Type = nullptr;
static SbkObjectType *Sbk_Natron_Python_PageParam_TypeF(void)
{
    return _Sbk_Natron_Python_PageParam_Type;
}

static PyType_Slot Sbk_Natron_Python_PageParam_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_Natron_Python_PageParam_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_Natron_Python_PageParam_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_Natron_Python_PageParam_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        nullptr},
    {Py_tp_new,         reinterpret_cast<void*>(SbkDummyNew /* PYSIDE-595: Prevent replacement of "0" with base->tp_new. */)},
    {0, nullptr}
};
static PyType_Spec Sbk_Natron_Python_PageParam_spec = {
    "NatronEngine.Natron.Python.PageParam",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Natron_Python_PageParam_slots
};

} //extern "C"

static void* Sbk_Natron_Python_PageParam_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::Natron::Python::Param >()))
        return dynamic_cast< ::Natron::Python::PageParam*>(reinterpret_cast< ::Natron::Python::Param*>(cptr));
    return {};
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void PageParam_PythonToCpp_PageParam_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_Natron_Python_PageParam_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_PageParam_PythonToCpp_PageParam_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_PageParam_TypeF())))
        return PageParam_PythonToCpp_PageParam_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* PageParam_PTR_CppToPython_PageParam(const void* cppIn) {
    auto pyOut = reinterpret_cast<PyObject*>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::Natron::Python::PageParam *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_Natron_Python_PageParam_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *Natron_Python_PageParam_SignatureStrings[] = {
    "NatronEngine.Natron.Python.PageParam.addParam(param:NatronEngine.Natron.Python.Param)",
    nullptr}; // Sentinel

void init_Natron_Python_PageParam(PyObject* module)
{
    _Sbk_Natron_Python_PageParam_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "PageParam",
        "Natron::Python::PageParam*",
        &Sbk_Natron_Python_PageParam_spec,
        Natron_Python_PageParam_SignatureStrings,
        &Shiboken::callCppDestructor< ::Natron::Python::PageParam >,
        reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX]),
        0,
        0    );
    
    SbkNatronEngineTypes[SBK_NATRON_PYTHON_PAGEPARAM_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_PageParam_TypeF());

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_Natron_Python_PageParam_TypeF(),
        PageParam_PythonToCpp_PageParam_PTR,
        is_PageParam_PythonToCpp_PageParam_PTR_Convertible,
        PageParam_PTR_CppToPython_PageParam);

    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::PageParam");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::PageParam*");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::PageParam&");
    Shiboken::Conversions::registerConverterName(converter, "Python::PageParam");
    Shiboken::Conversions::registerConverterName(converter, "Python::PageParam*");
    Shiboken::Conversions::registerConverterName(converter, "Python::PageParam&");
    Shiboken::Conversions::registerConverterName(converter, "PageParam");
    Shiboken::Conversions::registerConverterName(converter, "PageParam*");
    Shiboken::Conversions::registerConverterName(converter, "PageParam&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Natron::Python::PageParam).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::PageParamWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_Natron_Python_PageParam_TypeF(), &Sbk_Natron_Python_PageParam_typeDiscovery);


    PageParamWrapper::pysideInitQtMetaTypes();
}
