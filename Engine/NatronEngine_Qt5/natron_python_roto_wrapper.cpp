
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
#include "natron_python_roto_wrapper.h"

// inner classes

// Extra includes
#include <PyItemsTable.h>
#include <PyRoto.h>
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

void RotoWrapper::pysideInitQtMetaTypes()
{
}

RotoWrapper::~RotoWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_Natron_Python_RotoFunc_createBezier(PyObject* self, PyObject* args)
{
    ::Natron::Python::Roto* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Roto *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ROTO_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createBezier", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return {};


    // Overloaded function decisor
    // 0: Roto::createBezier(double,double,double)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2])))) {
        overloadId = 0; // createBezier(double,double,double)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_RotoFunc_createBezier_TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        double cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        double cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // createBezier(double,double,double)
            // Begin code injection

            Natron::Python::BezierCurve * cppResult = cppSelf->createBezier(cppArg0,cppArg1,cppArg2);
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_BEZIERCURVE_IDX]), cppResult);

            // End of code injection



            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_RotoFunc_createBezier_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.Roto.createBezier");
        return {};
}

static PyObject* Sbk_Natron_Python_RotoFunc_createEllipse(PyObject* self, PyObject* args)
{
    ::Natron::Python::Roto* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Roto *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ROTO_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createEllipse", 5, 5, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return {};


    // Overloaded function decisor
    // 0: Roto::createEllipse(double,double,double,bool,double)
    if (numArgs == 5
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[4])))) {
        overloadId = 0; // createEllipse(double,double,double,bool,double)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_RotoFunc_createEllipse_TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        double cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        double cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        bool cppArg3;
        pythonToCpp[3](pyArgs[3], &cppArg3);
        double cppArg4;
        pythonToCpp[4](pyArgs[4], &cppArg4);

        if (!PyErr_Occurred()) {
            // createEllipse(double,double,double,bool,double)
            // Begin code injection

            Natron::Python::BezierCurve * cppResult = cppSelf->createEllipse(cppArg0,cppArg1,cppArg2,cppArg3,cppArg4);
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_BEZIERCURVE_IDX]), cppResult);

            // End of code injection



            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_RotoFunc_createEllipse_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.Roto.createEllipse");
        return {};
}

static PyObject* Sbk_Natron_Python_RotoFunc_createLayer(PyObject* self)
{
    ::Natron::Python::Roto* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Roto *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ROTO_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // createLayer()
            // Begin code injection

            Natron::Python::ItemBase * cppResult = cppSelf->createLayer();
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ITEMBASE_IDX]), cppResult);

            // End of code injection



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

static PyObject* Sbk_Natron_Python_RotoFunc_createRectangle(PyObject* self, PyObject* args)
{
    ::Natron::Python::Roto* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Roto *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ROTO_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createRectangle", 4, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return {};


    // Overloaded function decisor
    // 0: Roto::createRectangle(double,double,double,double)
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[3])))) {
        overloadId = 0; // createRectangle(double,double,double,double)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_RotoFunc_createRectangle_TypeError;

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

        if (!PyErr_Occurred()) {
            // createRectangle(double,double,double,double)
            // Begin code injection

            Natron::Python::BezierCurve * cppResult = cppSelf->createRectangle(cppArg0,cppArg1,cppArg2,cppArg3);
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_BEZIERCURVE_IDX]), cppResult);

            // End of code injection



            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_RotoFunc_createRectangle_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.Roto.createRectangle");
        return {};
}

static PyObject* Sbk_Natron_Python_RotoFunc_createStroke(PyObject* self, PyObject* pyArg)
{
    ::Natron::Python::Roto* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Roto *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ROTO_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: Roto::createStroke(Natron::RotoStrokeType)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(*PepType_SGTP(SbkNatronEngineTypes[SBK_NATRON_ROTOSTROKETYPE_IDX])->converter, (pyArg)))) {
        overloadId = 0; // createStroke(Natron::RotoStrokeType)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_RotoFunc_createStroke_TypeError;

    // Call function/method
    {
        ::Natron::RotoStrokeType cppArg0{Natron::eRotoStrokeTypeSolid};
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // createStroke(Natron::RotoStrokeType)
            // Begin code injection

            Natron::Python::ItemBase * cppResult = cppSelf->createStroke(cppArg0);
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ITEMBASE_IDX]), cppResult);

            // End of code injection



            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_RotoFunc_createStroke_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.Roto.createStroke");
        return {};
}

static PyMethodDef Sbk_Natron_Python_Roto_methods[] = {
    {"createBezier", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_RotoFunc_createBezier), METH_VARARGS},
    {"createEllipse", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_RotoFunc_createEllipse), METH_VARARGS},
    {"createLayer", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_RotoFunc_createLayer), METH_NOARGS},
    {"createRectangle", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_RotoFunc_createRectangle), METH_VARARGS},
    {"createStroke", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_RotoFunc_createStroke), METH_O},

    {nullptr, nullptr} // Sentinel
};

} // extern "C"

static int Sbk_Natron_Python_Roto_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_Natron_Python_Roto_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_Natron_Python_Roto_Type = nullptr;
static SbkObjectType *Sbk_Natron_Python_Roto_TypeF(void)
{
    return _Sbk_Natron_Python_Roto_Type;
}

static PyType_Slot Sbk_Natron_Python_Roto_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_Natron_Python_Roto_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_Natron_Python_Roto_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_Natron_Python_Roto_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        nullptr},
    {Py_tp_new,         reinterpret_cast<void*>(SbkDummyNew /* PYSIDE-595: Prevent replacement of "0" with base->tp_new. */)},
    {0, nullptr}
};
static PyType_Spec Sbk_Natron_Python_Roto_spec = {
    "NatronEngine.Natron.Python.Roto",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Natron_Python_Roto_slots
};

} //extern "C"

static void* Sbk_Natron_Python_Roto_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::Natron::Python::ItemsTable >()))
        return dynamic_cast< ::Natron::Python::Roto*>(reinterpret_cast< ::Natron::Python::ItemsTable*>(cptr));
    return {};
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void Roto_PythonToCpp_Roto_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_Natron_Python_Roto_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_Roto_PythonToCpp_Roto_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_Roto_TypeF())))
        return Roto_PythonToCpp_Roto_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* Roto_PTR_CppToPython_Roto(const void* cppIn) {
    auto pyOut = reinterpret_cast<PyObject*>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::Natron::Python::Roto *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_Natron_Python_Roto_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *Natron_Python_Roto_SignatureStrings[] = {
    "NatronEngine.Natron.Python.Roto.createBezier(x:double,y:double,time:double)->NatronEngine.Natron.Python.BezierCurve",
    "NatronEngine.Natron.Python.Roto.createEllipse(x:double,y:double,diameter:double,fromCenter:bool,time:double)->NatronEngine.Natron.Python.BezierCurve",
    "NatronEngine.Natron.Python.Roto.createLayer()->NatronEngine.Natron.Python.ItemBase",
    "NatronEngine.Natron.Python.Roto.createRectangle(x:double,y:double,size:double,time:double)->NatronEngine.Natron.Python.BezierCurve",
    "NatronEngine.Natron.Python.Roto.createStroke(type:NatronEngine.Natron.RotoStrokeType)->NatronEngine.Natron.Python.ItemBase",
    nullptr}; // Sentinel

void init_Natron_Python_Roto(PyObject* module)
{
    _Sbk_Natron_Python_Roto_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "Roto",
        "Natron::Python::Roto*",
        &Sbk_Natron_Python_Roto_spec,
        Natron_Python_Roto_SignatureStrings,
        &Shiboken::callCppDestructor< ::Natron::Python::Roto >,
        reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ITEMSTABLE_IDX]),
        0,
        0    );
    
    SbkNatronEngineTypes[SBK_NATRON_PYTHON_ROTO_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_Roto_TypeF());

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_Natron_Python_Roto_TypeF(),
        Roto_PythonToCpp_Roto_PTR,
        is_Roto_PythonToCpp_Roto_PTR_Convertible,
        Roto_PTR_CppToPython_Roto);

    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::Roto");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::Roto*");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::Roto&");
    Shiboken::Conversions::registerConverterName(converter, "Python::Roto");
    Shiboken::Conversions::registerConverterName(converter, "Python::Roto*");
    Shiboken::Conversions::registerConverterName(converter, "Python::Roto&");
    Shiboken::Conversions::registerConverterName(converter, "Roto");
    Shiboken::Conversions::registerConverterName(converter, "Roto*");
    Shiboken::Conversions::registerConverterName(converter, "Roto&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Natron::Python::Roto).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::RotoWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_Natron_Python_Roto_TypeF(), &Sbk_Natron_Python_Roto_typeDiscovery);


    RotoWrapper::pysideInitQtMetaTypes();
}
