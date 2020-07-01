
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
#include "natron_python_fileparam_wrapper.h"

// inner classes

// Extra includes
#include <PyAppInstance.h>
#include <PyItemsTable.h>
#include <PyNode.h>
#include <PyParameter.h>
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

void FileParamWrapper::pysideInitQtMetaTypes()
{
}

FileParamWrapper::~FileParamWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_Natron_Python_FileParamFunc_openFile(PyObject* self)
{
    FileParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<FileParamWrapper *>(reinterpret_cast< ::Natron::Python::FileParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_FILEPARAM_IDX], reinterpret_cast<SbkObject *>(self))));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // openFile()
            cppSelf->openFile();
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_Natron_Python_FileParamFunc_reloadFile(PyObject* self)
{
    FileParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<FileParamWrapper *>(reinterpret_cast< ::Natron::Python::FileParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_FILEPARAM_IDX], reinterpret_cast<SbkObject *>(self))));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // reloadFile()
            cppSelf->reloadFile();
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_Natron_Python_FileParamFunc_setDialogType(PyObject* self, PyObject* args)
{
    FileParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<FileParamWrapper *>(reinterpret_cast< ::Natron::Python::FileParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_FILEPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setDialogType", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return {};


    // Overloaded function decisor
    // 0: FileParam::setDialogType(bool,bool,std::vector<std::string>)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_VECTOR_STD_STRING_IDX], (pyArgs[2])))) {
        overloadId = 0; // setDialogType(bool,bool,std::vector<std::string>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_FileParamFunc_setDialogType_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        bool cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::std::vector<std::string > cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // setDialogType(bool,bool,std::vector<std::string>)
            cppSelf->setDialogType(cppArg0, cppArg1, cppArg2);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_FileParamFunc_setDialogType_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.FileParam.setDialogType");
        return {};
}

static PyObject* Sbk_Natron_Python_FileParamFunc_setSequenceEnabled(PyObject* self, PyObject* pyArg)
{
    FileParamWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<FileParamWrapper *>(reinterpret_cast< ::Natron::Python::FileParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_FILEPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: FileParam::setSequenceEnabled(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setSequenceEnabled(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_FileParamFunc_setSequenceEnabled_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSequenceEnabled(bool)
            cppSelf->setSequenceEnabled(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_FileParamFunc_setSequenceEnabled_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.FileParam.setSequenceEnabled");
        return {};
}

static PyMethodDef Sbk_Natron_Python_FileParam_methods[] = {
    {"openFile", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_FileParamFunc_openFile), METH_NOARGS},
    {"reloadFile", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_FileParamFunc_reloadFile), METH_NOARGS},
    {"setDialogType", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_FileParamFunc_setDialogType), METH_VARARGS},
    {"setSequenceEnabled", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_FileParamFunc_setSequenceEnabled), METH_O},

    {nullptr, nullptr} // Sentinel
};

} // extern "C"

static int Sbk_Natron_Python_FileParam_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_Natron_Python_FileParam_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_Natron_Python_FileParam_Type = nullptr;
static SbkObjectType *Sbk_Natron_Python_FileParam_TypeF(void)
{
    return _Sbk_Natron_Python_FileParam_Type;
}

static PyType_Slot Sbk_Natron_Python_FileParam_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_Natron_Python_FileParam_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_Natron_Python_FileParam_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_Natron_Python_FileParam_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        nullptr},
    {Py_tp_new,         reinterpret_cast<void*>(SbkDummyNew /* PYSIDE-595: Prevent replacement of "0" with base->tp_new. */)},
    {0, nullptr}
};
static PyType_Spec Sbk_Natron_Python_FileParam_spec = {
    "NatronEngine.Natron.Python.FileParam",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Natron_Python_FileParam_slots
};

} //extern "C"

static void* Sbk_Natron_Python_FileParam_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::Natron::Python::Param >()))
        return dynamic_cast< ::Natron::Python::FileParam*>(reinterpret_cast< ::Natron::Python::Param*>(cptr));
    return {};
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void FileParam_PythonToCpp_FileParam_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_Natron_Python_FileParam_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_FileParam_PythonToCpp_FileParam_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_FileParam_TypeF())))
        return FileParam_PythonToCpp_FileParam_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* FileParam_PTR_CppToPython_FileParam(const void* cppIn) {
    auto pyOut = reinterpret_cast<PyObject*>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::Natron::Python::FileParam *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_Natron_Python_FileParam_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *Natron_Python_FileParam_SignatureStrings[] = {
    "NatronEngine.Natron.Python.FileParam.openFile()",
    "NatronEngine.Natron.Python.FileParam.reloadFile()",
    "NatronEngine.Natron.Python.FileParam.setDialogType(fileExisting:bool,useSequences:bool,filters:QVector[std.string])",
    "NatronEngine.Natron.Python.FileParam.setSequenceEnabled(enabled:bool)",
    nullptr}; // Sentinel

void init_Natron_Python_FileParam(PyObject* module)
{
    _Sbk_Natron_Python_FileParam_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "FileParam",
        "Natron::Python::FileParam*",
        &Sbk_Natron_Python_FileParam_spec,
        Natron_Python_FileParam_SignatureStrings,
        &Shiboken::callCppDestructor< ::Natron::Python::FileParam >,
        reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STRINGPARAMBASE_IDX]),
        0,
        0    );
    
    SbkNatronEngineTypes[SBK_NATRON_PYTHON_FILEPARAM_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_FileParam_TypeF());

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_Natron_Python_FileParam_TypeF(),
        FileParam_PythonToCpp_FileParam_PTR,
        is_FileParam_PythonToCpp_FileParam_PTR_Convertible,
        FileParam_PTR_CppToPython_FileParam);

    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::FileParam");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::FileParam*");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::FileParam&");
    Shiboken::Conversions::registerConverterName(converter, "Python::FileParam");
    Shiboken::Conversions::registerConverterName(converter, "Python::FileParam*");
    Shiboken::Conversions::registerConverterName(converter, "Python::FileParam&");
    Shiboken::Conversions::registerConverterName(converter, "FileParam");
    Shiboken::Conversions::registerConverterName(converter, "FileParam*");
    Shiboken::Conversions::registerConverterName(converter, "FileParam&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Natron::Python::FileParam).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::FileParamWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_Natron_Python_FileParam_TypeF(), &Sbk_Natron_Python_FileParam_typeDiscovery);


    FileParamWrapper::pysideInitQtMetaTypes();
}
