
// default includes
#include "Global/Macros.h"
CLANG_DIAG_OFF(mismatched-tags)
GCC_DIAG_OFF(unused-parameter)
GCC_DIAG_OFF(missing-field-initializers)
GCC_DIAG_OFF(missing-declarations)
GCC_DIAG_OFF(uninitialized)
GCC_DIAG_UNUSED_LOCAL_TYPEDEFS_OFF
#include <shiboken.h> // produces many warnings
#include <pysidesignal.h>
#include <pysideproperty.h>
#include <pyside.h>
#include <typeresolver.h>
#include <typeinfo>
#include "natronengine_python.h"

#include "layer_wrapper.h"

// Extra includes
using namespace Natron; using namespace Natron::Python;
#include <PyParameter.h>
#include <PyRoto.h>
#include <list>


// Native ---------------------------------------------------------

void LayerWrapper::pysideInitQtMetaTypes()
{
}

LayerWrapper::~LayerWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_LayerFunc_addItem(PyObject* self, PyObject* pyArg)
{
    ::Layer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Layer*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_LAYER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: addItem(ItemBase*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkNatronEngineTypes[SBK_ITEMBASE_IDX], (pyArg)))) {
        overloadId = 0; // addItem(ItemBase*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_LayerFunc_addItem_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::ItemBase* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // addItem(ItemBase*)
            // Begin code injection

            cppSelf->addItem(cppArg0);

            // End of code injection


        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_LayerFunc_addItem_TypeError:
        const char* overloads[] = {"NatronEngine.ItemBase", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Layer.addItem", overloads);
        return 0;
}

static PyObject* Sbk_LayerFunc_getChildren(PyObject* self)
{
    ::Layer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Layer*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_LAYER_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getChildren()const
            // Begin code injection

            std::list<ItemBase*> items = cppSelf->getChildren();
            PyObject* ret = PyList_New((int) items.size());
            int idx = 0;
            for (std::list<ItemBase*>::iterator it = items.begin(); it!=items.end(); ++it,++idx) {
            PyObject* item = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkNatronEngineTypes[SBK_ITEMBASE_IDX], *it);
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
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_LayerFunc_insertItem(PyObject* self, PyObject* args)
{
    ::Layer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Layer*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_LAYER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "insertItem", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: insertItem(int,ItemBase*)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkNatronEngineTypes[SBK_ITEMBASE_IDX], (pyArgs[1])))) {
        overloadId = 0; // insertItem(int,ItemBase*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_LayerFunc_insertItem_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::ItemBase* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // insertItem(int,ItemBase*)
            // Begin code injection

            cppSelf->insertItem(cppArg0,cppArg1);

            // End of code injection


        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_LayerFunc_insertItem_TypeError:
        const char* overloads[] = {"int, NatronEngine.ItemBase", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Layer.insertItem", overloads);
        return 0;
}

static PyObject* Sbk_LayerFunc_removeItem(PyObject* self, PyObject* pyArg)
{
    ::Layer* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = ((::Layer*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_LAYER_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: removeItem(ItemBase*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkNatronEngineTypes[SBK_ITEMBASE_IDX], (pyArg)))) {
        overloadId = 0; // removeItem(ItemBase*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_LayerFunc_removeItem_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::ItemBase* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // removeItem(ItemBase*)
            // Begin code injection

            cppSelf->removeItem(cppArg0);

            // End of code injection


        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_LayerFunc_removeItem_TypeError:
        const char* overloads[] = {"NatronEngine.ItemBase", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Layer.removeItem", overloads);
        return 0;
}

static PyMethodDef Sbk_Layer_methods[] = {
    {"addItem", (PyCFunction)Sbk_LayerFunc_addItem, METH_O},
    {"getChildren", (PyCFunction)Sbk_LayerFunc_getChildren, METH_NOARGS},
    {"insertItem", (PyCFunction)Sbk_LayerFunc_insertItem, METH_VARARGS},
    {"removeItem", (PyCFunction)Sbk_LayerFunc_removeItem, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_Layer_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_Layer_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_Layer_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "NatronEngine.Layer",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             0,
    /*tp_as_number*/        0,
    /*tp_as_sequence*/      0,
    /*tp_as_mapping*/       0,
    /*tp_hash*/             0,
    /*tp_call*/             0,
    /*tp_str*/              0,
    /*tp_getattro*/         0,
    /*tp_setattro*/         0,
    /*tp_as_buffer*/        0,
    /*tp_flags*/            Py_TPFLAGS_DEFAULT|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    /*tp_doc*/              0,
    /*tp_traverse*/         Sbk_Layer_traverse,
    /*tp_clear*/            Sbk_Layer_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_Layer_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             0,
    /*tp_alloc*/            0,
    /*tp_new*/              0,
    /*tp_free*/             0,
    /*tp_is_gc*/            0,
    /*tp_bases*/            0,
    /*tp_mro*/              0,
    /*tp_cache*/            0,
    /*tp_subclasses*/       0,
    /*tp_weaklist*/         0
}, },
    /*priv_data*/           0
};
} //extern

static void* Sbk_Layer_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::ItemBase >()))
        return dynamic_cast< ::Layer*>(reinterpret_cast< ::ItemBase*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void Layer_PythonToCpp_Layer_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_Layer_Type, pyIn, cppOut);
}
static PythonToCppFunc is_Layer_PythonToCpp_Layer_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_Layer_Type))
        return Layer_PythonToCpp_Layer_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* Layer_PTR_CppToPython_Layer(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::Layer*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_Layer_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_Layer(PyObject* module)
{
    SbkNatronEngineTypes[SBK_LAYER_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_Layer_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "Layer", "Layer*",
        &Sbk_Layer_Type, &Shiboken::callCppDestructor< ::Layer >, (SbkObjectType*)SbkNatronEngineTypes[SBK_ITEMBASE_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_Layer_Type,
        Layer_PythonToCpp_Layer_PTR,
        is_Layer_PythonToCpp_Layer_PTR_Convertible,
        Layer_PTR_CppToPython_Layer);

    Shiboken::Conversions::registerConverterName(converter, "Layer");
    Shiboken::Conversions::registerConverterName(converter, "Layer*");
    Shiboken::Conversions::registerConverterName(converter, "Layer&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Layer).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::LayerWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_Layer_Type, &Sbk_Layer_typeDiscovery);


    LayerWrapper::pysideInitQtMetaTypes();
}
