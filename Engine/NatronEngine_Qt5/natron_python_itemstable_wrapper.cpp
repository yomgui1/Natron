
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
#include "natron_python_itemstable_wrapper.h"

// inner classes

// Extra includes
#include <PyItemsTable.h>
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

void ItemsTableWrapper::pysideInitQtMetaTypes()
{
}

ItemsTableWrapper::~ItemsTableWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_Natron_Python_ItemsTableFunc_getAttributeName(PyObject* self)
{
    ::Natron::Python::ItemsTable* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::ItemsTable *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ITEMSTABLE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getAttributeName()const
            QString cppResult = const_cast<const ::Natron::Python::ItemsTable*>(cppSelf)->getAttributeName();
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_ItemsTableFunc_getItemByFullyQualifiedScriptName(PyObject* self, PyObject* pyArg)
{
    ::Natron::Python::ItemsTable* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::ItemsTable *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ITEMSTABLE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: ItemsTable::getItemByFullyQualifiedScriptName(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // getItemByFullyQualifiedScriptName(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ItemsTableFunc_getItemByFullyQualifiedScriptName_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getItemByFullyQualifiedScriptName(QString)const
            Natron::Python::ItemBase * cppResult = const_cast<const ::Natron::Python::ItemsTable*>(cppSelf)->getItemByFullyQualifiedScriptName(cppArg0);
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

    Sbk_Natron_Python_ItemsTableFunc_getItemByFullyQualifiedScriptName_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.ItemsTable.getItemByFullyQualifiedScriptName");
        return {};
}

static PyObject* Sbk_Natron_Python_ItemsTableFunc_getSelectedItems(PyObject* self)
{
    ::Natron::Python::ItemsTable* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::ItemsTable *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ITEMSTABLE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getSelectedItems()const
            // Begin code injection

            std::list<Natron::Python::ItemBase*> items = cppSelf->getSelectedItems();
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

static PyObject* Sbk_Natron_Python_ItemsTableFunc_getTableName(PyObject* self)
{
    ::Natron::Python::ItemsTable* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::ItemsTable *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ITEMSTABLE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getTableName()const
            QString cppResult = const_cast<const ::Natron::Python::ItemsTable*>(cppSelf)->getTableName();
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_ItemsTableFunc_getTopLevelItems(PyObject* self)
{
    ::Natron::Python::ItemsTable* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::ItemsTable *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ITEMSTABLE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getTopLevelItems()const
            // Begin code injection

            std::list<Natron::Python::ItemBase*> items = cppSelf->getTopLevelItems();
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

static PyObject* Sbk_Natron_Python_ItemsTableFunc_insertItem(PyObject* self, PyObject* args)
{
    ::Natron::Python::ItemsTable* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::ItemsTable *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ITEMSTABLE_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "insertItem", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return {};


    // Overloaded function decisor
    // 0: ItemsTable::insertItem(int,const Natron::Python::ItemBase*,const Natron::Python::ItemBase*)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ITEMBASE_IDX]), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ITEMBASE_IDX]), (pyArgs[2])))) {
        overloadId = 0; // insertItem(int,const Natron::Python::ItemBase*,const Natron::Python::ItemBase*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ItemsTableFunc_insertItem_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return {};
        ::Natron::Python::ItemBase* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        if (!Shiboken::Object::isValid(pyArgs[2]))
            return {};
        ::Natron::Python::ItemBase* cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // insertItem(int,const Natron::Python::ItemBase*,const Natron::Python::ItemBase*)
            cppSelf->insertItem(cppArg0, cppArg1, cppArg2);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_ItemsTableFunc_insertItem_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.ItemsTable.insertItem");
        return {};
}

static PyObject* Sbk_Natron_Python_ItemsTableFunc_isModelParentingEnabled(PyObject* self)
{
    ::Natron::Python::ItemsTable* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::ItemsTable *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ITEMSTABLE_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isModelParentingEnabled()const
            bool cppResult = const_cast<const ::Natron::Python::ItemsTable*>(cppSelf)->isModelParentingEnabled();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_ItemsTableFunc_removeItem(PyObject* self, PyObject* pyArg)
{
    ::Natron::Python::ItemsTable* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::ItemsTable *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ITEMSTABLE_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: ItemsTable::removeItem(const Natron::Python::ItemBase*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ITEMBASE_IDX]), (pyArg)))) {
        overloadId = 0; // removeItem(const Natron::Python::ItemBase*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_ItemsTableFunc_removeItem_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return {};
        ::Natron::Python::ItemBase* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // removeItem(const Natron::Python::ItemBase*)
            cppSelf->removeItem(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_ItemsTableFunc_removeItem_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.ItemsTable.removeItem");
        return {};
}

static PyMethodDef Sbk_Natron_Python_ItemsTable_methods[] = {
    {"getAttributeName", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ItemsTableFunc_getAttributeName), METH_NOARGS},
    {"getItemByFullyQualifiedScriptName", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ItemsTableFunc_getItemByFullyQualifiedScriptName), METH_O},
    {"getSelectedItems", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ItemsTableFunc_getSelectedItems), METH_NOARGS},
    {"getTableName", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ItemsTableFunc_getTableName), METH_NOARGS},
    {"getTopLevelItems", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ItemsTableFunc_getTopLevelItems), METH_NOARGS},
    {"insertItem", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ItemsTableFunc_insertItem), METH_VARARGS},
    {"isModelParentingEnabled", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ItemsTableFunc_isModelParentingEnabled), METH_NOARGS},
    {"removeItem", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_ItemsTableFunc_removeItem), METH_O},

    {nullptr, nullptr} // Sentinel
};

} // extern "C"

static int Sbk_Natron_Python_ItemsTable_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_Natron_Python_ItemsTable_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_Natron_Python_ItemsTable_Type = nullptr;
static SbkObjectType *Sbk_Natron_Python_ItemsTable_TypeF(void)
{
    return _Sbk_Natron_Python_ItemsTable_Type;
}

static PyType_Slot Sbk_Natron_Python_ItemsTable_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_Natron_Python_ItemsTable_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_Natron_Python_ItemsTable_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_Natron_Python_ItemsTable_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        nullptr},
    {Py_tp_new,         reinterpret_cast<void*>(SbkDummyNew /* PYSIDE-595: Prevent replacement of "0" with base->tp_new. */)},
    {0, nullptr}
};
static PyType_Spec Sbk_Natron_Python_ItemsTable_spec = {
    "NatronEngine.Natron.Python.ItemsTable",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Natron_Python_ItemsTable_slots
};

} //extern "C"


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void ItemsTable_PythonToCpp_ItemsTable_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_Natron_Python_ItemsTable_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_ItemsTable_PythonToCpp_ItemsTable_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_ItemsTable_TypeF())))
        return ItemsTable_PythonToCpp_ItemsTable_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* ItemsTable_PTR_CppToPython_ItemsTable(const void* cppIn) {
    auto pyOut = reinterpret_cast<PyObject*>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::Natron::Python::ItemsTable *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_Natron_Python_ItemsTable_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *Natron_Python_ItemsTable_SignatureStrings[] = {
    "NatronEngine.Natron.Python.ItemsTable.getAttributeName()->QString",
    "NatronEngine.Natron.Python.ItemsTable.getItemByFullyQualifiedScriptName(name:QString)->NatronEngine.Natron.Python.ItemBase",
    "NatronEngine.Natron.Python.ItemsTable.getSelectedItems()->QList[NatronEngine.Natron.Python.ItemBase]",
    "NatronEngine.Natron.Python.ItemsTable.getTableName()->QString",
    "NatronEngine.Natron.Python.ItemsTable.getTopLevelItems()->QList[NatronEngine.Natron.Python.ItemBase]",
    "NatronEngine.Natron.Python.ItemsTable.insertItem(index:int,item:NatronEngine.Natron.Python.ItemBase,parent:NatronEngine.Natron.Python.ItemBase)",
    "NatronEngine.Natron.Python.ItemsTable.isModelParentingEnabled()->bool",
    "NatronEngine.Natron.Python.ItemsTable.removeItem(item:NatronEngine.Natron.Python.ItemBase)",
    nullptr}; // Sentinel

void init_Natron_Python_ItemsTable(PyObject* module)
{
    _Sbk_Natron_Python_ItemsTable_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "ItemsTable",
        "Natron::Python::ItemsTable*",
        &Sbk_Natron_Python_ItemsTable_spec,
        Natron_Python_ItemsTable_SignatureStrings,
        &Shiboken::callCppDestructor< ::Natron::Python::ItemsTable >,
        0,
        0,
        0    );
    
    SbkNatronEngineTypes[SBK_NATRON_PYTHON_ITEMSTABLE_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_ItemsTable_TypeF());

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_Natron_Python_ItemsTable_TypeF(),
        ItemsTable_PythonToCpp_ItemsTable_PTR,
        is_ItemsTable_PythonToCpp_ItemsTable_PTR_Convertible,
        ItemsTable_PTR_CppToPython_ItemsTable);

    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::ItemsTable");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::ItemsTable*");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::ItemsTable&");
    Shiboken::Conversions::registerConverterName(converter, "Python::ItemsTable");
    Shiboken::Conversions::registerConverterName(converter, "Python::ItemsTable*");
    Shiboken::Conversions::registerConverterName(converter, "Python::ItemsTable&");
    Shiboken::Conversions::registerConverterName(converter, "ItemsTable");
    Shiboken::Conversions::registerConverterName(converter, "ItemsTable*");
    Shiboken::Conversions::registerConverterName(converter, "ItemsTable&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Natron::Python::ItemsTable).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::ItemsTableWrapper).name());



    ItemsTableWrapper::pysideInitQtMetaTypes();
}
