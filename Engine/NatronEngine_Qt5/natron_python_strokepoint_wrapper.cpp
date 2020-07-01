
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
#include "natron_python_strokepoint_wrapper.h"

// inner classes

// Extra includes


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
Sbk_Natron_Python_StrokePoint_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::Natron::Python::StrokePoint >()))
        return -1;

    ::Natron::Python::StrokePoint* cptr{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // StrokePoint()
            cptr = new ::Natron::Python::StrokePoint();
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::Natron::Python::StrokePoint >(), cptr)) {
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

static PyMethodDef Sbk_Natron_Python_StrokePoint_methods[] = {

    {nullptr, nullptr} // Sentinel
};

static PyObject* Sbk_Natron_Python_StrokePoint_get_x(PyObject* self, void*)
{
    ::Natron::Python::StrokePoint* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return nullptr;
    cppSelf = reinterpret_cast< ::Natron::Python::StrokePoint *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STROKEPOINT_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyOut = {};
    pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppSelf->x);
    return pyOut;
}
static int Sbk_Natron_Python_StrokePoint_set_x(PyObject* self, PyObject* pyIn, void*)
{
    ::Natron::Python::StrokePoint* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = reinterpret_cast< ::Natron::Python::StrokePoint *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STROKEPOINT_IDX], reinterpret_cast<SbkObject *>(self)));
    if (pyIn == nullptr) {
        PyErr_SetString(PyExc_TypeError, "'x' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp{nullptr};
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'x', 'double' or convertible type expected");
        return -1;
    }

    double& cppOut_ptr = cppSelf->x;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_Natron_Python_StrokePoint_get_y(PyObject* self, void*)
{
    ::Natron::Python::StrokePoint* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return nullptr;
    cppSelf = reinterpret_cast< ::Natron::Python::StrokePoint *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STROKEPOINT_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyOut = {};
    pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppSelf->y);
    return pyOut;
}
static int Sbk_Natron_Python_StrokePoint_set_y(PyObject* self, PyObject* pyIn, void*)
{
    ::Natron::Python::StrokePoint* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = reinterpret_cast< ::Natron::Python::StrokePoint *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STROKEPOINT_IDX], reinterpret_cast<SbkObject *>(self)));
    if (pyIn == nullptr) {
        PyErr_SetString(PyExc_TypeError, "'y' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp{nullptr};
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'y', 'double' or convertible type expected");
        return -1;
    }

    double& cppOut_ptr = cppSelf->y;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_Natron_Python_StrokePoint_get_pressure(PyObject* self, void*)
{
    ::Natron::Python::StrokePoint* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return nullptr;
    cppSelf = reinterpret_cast< ::Natron::Python::StrokePoint *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STROKEPOINT_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyOut = {};
    pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppSelf->pressure);
    return pyOut;
}
static int Sbk_Natron_Python_StrokePoint_set_pressure(PyObject* self, PyObject* pyIn, void*)
{
    ::Natron::Python::StrokePoint* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = reinterpret_cast< ::Natron::Python::StrokePoint *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STROKEPOINT_IDX], reinterpret_cast<SbkObject *>(self)));
    if (pyIn == nullptr) {
        PyErr_SetString(PyExc_TypeError, "'pressure' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp{nullptr};
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'pressure', 'double' or convertible type expected");
        return -1;
    }

    double& cppOut_ptr = cppSelf->pressure;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_Natron_Python_StrokePoint_get_timestamp(PyObject* self, void*)
{
    ::Natron::Python::StrokePoint* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return nullptr;
    cppSelf = reinterpret_cast< ::Natron::Python::StrokePoint *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STROKEPOINT_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyOut = {};
    pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppSelf->timestamp);
    return pyOut;
}
static int Sbk_Natron_Python_StrokePoint_set_timestamp(PyObject* self, PyObject* pyIn, void*)
{
    ::Natron::Python::StrokePoint* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = reinterpret_cast< ::Natron::Python::StrokePoint *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STROKEPOINT_IDX], reinterpret_cast<SbkObject *>(self)));
    if (pyIn == nullptr) {
        PyErr_SetString(PyExc_TypeError, "'timestamp' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp{nullptr};
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'timestamp', 'double' or convertible type expected");
        return -1;
    }

    double& cppOut_ptr = cppSelf->timestamp;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

// Getters and Setters for StrokePoint
static PyGetSetDef Sbk_Natron_Python_StrokePoint_getsetlist[] = {
    {const_cast<char*>("x"), Sbk_Natron_Python_StrokePoint_get_x, Sbk_Natron_Python_StrokePoint_set_x},
    {const_cast<char*>("y"), Sbk_Natron_Python_StrokePoint_get_y, Sbk_Natron_Python_StrokePoint_set_y},
    {const_cast<char*>("pressure"), Sbk_Natron_Python_StrokePoint_get_pressure, Sbk_Natron_Python_StrokePoint_set_pressure},
    {const_cast<char*>("timestamp"), Sbk_Natron_Python_StrokePoint_get_timestamp, Sbk_Natron_Python_StrokePoint_set_timestamp},
    {nullptr} // Sentinel
};

} // extern "C"

static int Sbk_Natron_Python_StrokePoint_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_Natron_Python_StrokePoint_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_Natron_Python_StrokePoint_Type = nullptr;
static SbkObjectType *Sbk_Natron_Python_StrokePoint_TypeF(void)
{
    return _Sbk_Natron_Python_StrokePoint_Type;
}

static PyType_Slot Sbk_Natron_Python_StrokePoint_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_Natron_Python_StrokePoint_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_Natron_Python_StrokePoint_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_Natron_Python_StrokePoint_methods)},
    {Py_tp_getset,      reinterpret_cast<void*>(Sbk_Natron_Python_StrokePoint_getsetlist)},
    {Py_tp_init,        reinterpret_cast<void*>(Sbk_Natron_Python_StrokePoint_Init)},
    {Py_tp_new,         reinterpret_cast<void*>(SbkObjectTpNew)},
    {0, nullptr}
};
static PyType_Spec Sbk_Natron_Python_StrokePoint_spec = {
    "NatronEngine.Natron.Python.StrokePoint",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Natron_Python_StrokePoint_slots
};

} //extern "C"


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void StrokePoint_PythonToCpp_StrokePoint_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_Natron_Python_StrokePoint_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_StrokePoint_PythonToCpp_StrokePoint_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_StrokePoint_TypeF())))
        return StrokePoint_PythonToCpp_StrokePoint_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* StrokePoint_PTR_CppToPython_StrokePoint(const void* cppIn) {
    auto pyOut = reinterpret_cast<PyObject*>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::Natron::Python::StrokePoint *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_Natron_Python_StrokePoint_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *Natron_Python_StrokePoint_SignatureStrings[] = {
    "NatronEngine.Natron.Python.StrokePoint()",
    nullptr}; // Sentinel

void init_Natron_Python_StrokePoint(PyObject* module)
{
    _Sbk_Natron_Python_StrokePoint_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "StrokePoint",
        "Natron::Python::StrokePoint*",
        &Sbk_Natron_Python_StrokePoint_spec,
        Natron_Python_StrokePoint_SignatureStrings,
        &Shiboken::callCppDestructor< ::Natron::Python::StrokePoint >,
        0,
        0,
        0    );
    
    SbkNatronEngineTypes[SBK_NATRON_PYTHON_STROKEPOINT_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_StrokePoint_TypeF());

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_Natron_Python_StrokePoint_TypeF(),
        StrokePoint_PythonToCpp_StrokePoint_PTR,
        is_StrokePoint_PythonToCpp_StrokePoint_PTR_Convertible,
        StrokePoint_PTR_CppToPython_StrokePoint);

    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::StrokePoint");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::StrokePoint*");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::StrokePoint&");
    Shiboken::Conversions::registerConverterName(converter, "Python::StrokePoint");
    Shiboken::Conversions::registerConverterName(converter, "Python::StrokePoint*");
    Shiboken::Conversions::registerConverterName(converter, "Python::StrokePoint&");
    Shiboken::Conversions::registerConverterName(converter, "StrokePoint");
    Shiboken::Conversions::registerConverterName(converter, "StrokePoint*");
    Shiboken::Conversions::registerConverterName(converter, "StrokePoint&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Natron::Python::StrokePoint).name());



}
