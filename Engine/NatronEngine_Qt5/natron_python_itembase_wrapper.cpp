
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
#include "natron_python_itembase_wrapper.h"

// inner classes

// Extra includes
#include <PyItemsTable.h>
#include <PyParameter.h>
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

void ItemBaseWrapper::pysideInitQtMetaTypes()
{
}

ItemBaseWrapper::~ItemBaseWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_Natron_Python_ItemBaseFunc_getChildren(PyObject* self)
{
    ::Natron::Python::ItemBase* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::ItemBase *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ITEMBASE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getChildren()const
            // Begin code injection

            std::list<Natron::Python::ItemBase*> items = cppSelf->getChildren();
            PyObject* ret = PyList_New((int) items.size());
            int idx = 0;
            for (std::list<Natron::Python::ItemBase*>::iterator it = items.begin(); it!=items.end(); ++it,++idx) {
            PyObject* item = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ITEMBASE_IDX]), *it);
            // Ownership transferences.
            Shiboken::Object::getOwnership(item);
            PyList_SET_ITEM(ret, idx, item);
            }
            return ret;

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_ItemBaseFunc_getIconFilePath(PyObject* self)
{
    ::Natron::Python::ItemBase* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::ItemBase *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ITEMBASE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getIconFilePath()const
            QString cppResult = const_cast<const ::Natron::Python::ItemBase*>(cppSelf)->getIconFilePath();
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_ItemBaseFunc_getIndexInParent(PyObject* self)
{
    ::Natron::Python::ItemBase* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::ItemBase *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ITEMBASE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getIndexInParent()const
            int cppResult = const_cast<const ::Natron::Python::ItemBase*>(cppSelf)->getIndexInParent();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_ItemBaseFunc_getLabel(PyObject* self)
{
    ::Natron::Python::ItemBase* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::ItemBase *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ITEMBASE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getLabel()const
            QString cppResult = const_cast<const ::Natron::Python::ItemBase*>(cppSelf)->getLabel();
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_ItemBaseFunc_getParam(PyObject* self, PyObject* pyArg)
{
    ::Natron::Python::ItemBase* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::ItemBase *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ITEMBASE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: ItemBase::getParam(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // getParam(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ItemBaseFunc_getParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getParam(QString)const
            Natron::Python::Param * cppResult = const_cast<const ::Natron::Python::ItemBase*>(cppSelf)->getParam(cppArg0);
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

    Sbk_Natron_Python_ItemBaseFunc_getParam_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.ItemBase.getParam");
        return {};
}

static PyObject* Sbk_Natron_Python_ItemBaseFunc_getParams(PyObject* self)
{
    ::Natron::Python::ItemBase* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::ItemBase *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ITEMBASE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getParams()const
            // Begin code injection

            std::list<Natron::Python::Param*> params = cppSelf->getParams();
            PyObject* ret = PyList_New((int) params.size());
            int idx = 0;
            for (std::list<Natron::Python::Param*>::iterator it = params.begin(); it!=params.end(); ++it,++idx) {
            PyObject* item = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX]), *it);
            // Ownership transferences.
            Shiboken::Object::getOwnership(item);
            PyList_SET_ITEM(ret, idx, item);
            }
            return ret;

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_ItemBaseFunc_getParent(PyObject* self)
{
    ::Natron::Python::ItemBase* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::ItemBase *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ITEMBASE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getParent()const
            Natron::Python::ItemBase * cppResult = const_cast<const ::Natron::Python::ItemBase*>(cppSelf)->getParent();
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

static PyObject* Sbk_Natron_Python_ItemBaseFunc_getScriptName(PyObject* self)
{
    ::Natron::Python::ItemBase* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::ItemBase *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ITEMBASE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getScriptName()const
            QString cppResult = const_cast<const ::Natron::Python::ItemBase*>(cppSelf)->getScriptName();
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_ItemBaseFunc_setIconFilePath(PyObject* self, PyObject* pyArg)
{
    ::Natron::Python::ItemBase* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::ItemBase *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ITEMBASE_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: ItemBase::setIconFilePath(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setIconFilePath(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ItemBaseFunc_setIconFilePath_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setIconFilePath(QString)
            cppSelf->setIconFilePath(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_ItemBaseFunc_setIconFilePath_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.ItemBase.setIconFilePath");
        return {};
}

static PyObject* Sbk_Natron_Python_ItemBaseFunc_setLabel(PyObject* self, PyObject* pyArg)
{
    ::Natron::Python::ItemBase* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::ItemBase *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ITEMBASE_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: ItemBase::setLabel(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setLabel(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ItemBaseFunc_setLabel_TypeError;

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

    Sbk_Natron_Python_ItemBaseFunc_setLabel_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.ItemBase.setLabel");
        return {};
}

static PyMethodDef Sbk_Natron_Python_ItemBase_methods[] = {
    {"getChildren", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ItemBaseFunc_getChildren), METH_NOARGS},
    {"getIconFilePath", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ItemBaseFunc_getIconFilePath), METH_NOARGS},
    {"getIndexInParent", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ItemBaseFunc_getIndexInParent), METH_NOARGS},
    {"getLabel", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ItemBaseFunc_getLabel), METH_NOARGS},
    {"getParam", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ItemBaseFunc_getParam), METH_O},
    {"getParams", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ItemBaseFunc_getParams), METH_NOARGS},
    {"getParent", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ItemBaseFunc_getParent), METH_NOARGS},
    {"getScriptName", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ItemBaseFunc_getScriptName), METH_NOARGS},
    {"setIconFilePath", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ItemBaseFunc_setIconFilePath), METH_O},
    {"setLabel", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ItemBaseFunc_setLabel), METH_O},

    {nullptr, nullptr} // Sentinel
};

} // extern "C"

static int Sbk_Natron_Python_ItemBase_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_Natron_Python_ItemBase_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_Natron_Python_ItemBase_Type = nullptr;
static SbkObjectType *Sbk_Natron_Python_ItemBase_TypeF(void)
{
    return _Sbk_Natron_Python_ItemBase_Type;
}

static PyType_Slot Sbk_Natron_Python_ItemBase_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_Natron_Python_ItemBase_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_Natron_Python_ItemBase_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_Natron_Python_ItemBase_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        nullptr},
    {Py_tp_new,         reinterpret_cast<void*>(SbkDummyNew /* PYSIDE-595: Prevent replacement of "0" with base->tp_new. */)},
    {0, nullptr}
};
static PyType_Spec Sbk_Natron_Python_ItemBase_spec = {
    "NatronEngine.Natron.Python.ItemBase",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Natron_Python_ItemBase_slots
};

} //extern "C"


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void ItemBase_PythonToCpp_ItemBase_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_Natron_Python_ItemBase_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_ItemBase_PythonToCpp_ItemBase_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_ItemBase_TypeF())))
        return ItemBase_PythonToCpp_ItemBase_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* ItemBase_PTR_CppToPython_ItemBase(const void* cppIn) {
    auto pyOut = reinterpret_cast<PyObject*>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::Natron::Python::ItemBase *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_Natron_Python_ItemBase_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *Natron_Python_ItemBase_SignatureStrings[] = {
    "NatronEngine.Natron.Python.ItemBase.getChildren()->QList[NatronEngine.Natron.Python.ItemBase]",
    "NatronEngine.Natron.Python.ItemBase.getIconFilePath()->QString",
    "NatronEngine.Natron.Python.ItemBase.getIndexInParent()->int",
    "NatronEngine.Natron.Python.ItemBase.getLabel()->QString",
    "NatronEngine.Natron.Python.ItemBase.getParam(name:QString)->NatronEngine.Natron.Python.Param",
    "NatronEngine.Natron.Python.ItemBase.getParams()->QList[NatronEngine.Natron.Python.Param]",
    "NatronEngine.Natron.Python.ItemBase.getParent()->NatronEngine.Natron.Python.ItemBase",
    "NatronEngine.Natron.Python.ItemBase.getScriptName()->QString",
    "NatronEngine.Natron.Python.ItemBase.setIconFilePath(icon:QString)",
    "NatronEngine.Natron.Python.ItemBase.setLabel(name:QString)",
    nullptr}; // Sentinel

void init_Natron_Python_ItemBase(PyObject* module)
{
    _Sbk_Natron_Python_ItemBase_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "ItemBase",
        "Natron::Python::ItemBase*",
        &Sbk_Natron_Python_ItemBase_spec,
        Natron_Python_ItemBase_SignatureStrings,
        &Shiboken::callCppDestructor< ::Natron::Python::ItemBase >,
        0,
        0,
        0    );
    
    SbkNatronEngineTypes[SBK_NATRON_PYTHON_ITEMBASE_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_ItemBase_TypeF());

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_Natron_Python_ItemBase_TypeF(),
        ItemBase_PythonToCpp_ItemBase_PTR,
        is_ItemBase_PythonToCpp_ItemBase_PTR_Convertible,
        ItemBase_PTR_CppToPython_ItemBase);

    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::ItemBase");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::ItemBase*");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::ItemBase&");
    Shiboken::Conversions::registerConverterName(converter, "Python::ItemBase");
    Shiboken::Conversions::registerConverterName(converter, "Python::ItemBase*");
    Shiboken::Conversions::registerConverterName(converter, "Python::ItemBase&");
    Shiboken::Conversions::registerConverterName(converter, "ItemBase");
    Shiboken::Conversions::registerConverterName(converter, "ItemBase*");
    Shiboken::Conversions::registerConverterName(converter, "ItemBase&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Natron::Python::ItemBase).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::ItemBaseWrapper).name());



    ItemBaseWrapper::pysideInitQtMetaTypes();
}
