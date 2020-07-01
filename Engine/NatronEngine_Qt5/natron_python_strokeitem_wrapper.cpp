
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
#include "natron_python_strokeitem_wrapper.h"

// inner classes

// Extra includes
#include <PyItemsTable.h>
#include <PyParameter.h>
#include <PyRoto.h>
#include <RectD.h>
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

void StrokeItemWrapper::pysideInitQtMetaTypes()
{
}

StrokeItemWrapper::~StrokeItemWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_Natron_Python_StrokeItemFunc_getBoundingBox(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::Natron::Python::StrokeItem* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::StrokeItem *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STROKEITEM_IDX], reinterpret_cast<SbkObject *>(self)));
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
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.StrokeItem.getBoundingBox(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.StrokeItem.getBoundingBox(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OO:getBoundingBox", &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: StrokeItem::getBoundingBox(double,QString)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // getBoundingBox(double,QString)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 0; // getBoundingBox(double,QString)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_StrokeItemFunc_getBoundingBox_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "view");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.StrokeItem.getBoundingBox(): got multiple values for keyword argument 'view'.");
                return {};
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1]))))
                    goto Sbk_Natron_Python_StrokeItemFunc_getBoundingBox_TypeError;
            }
        }
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1 = QLatin1String(kPyParamViewIdxMain);
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // getBoundingBox(double,QString)const
            Natron::RectD* cppResult = new Natron::RectD(const_cast<const ::Natron::Python::StrokeItem*>(cppSelf)->getBoundingBox(cppArg0, cppArg1));
            pyResult = Shiboken::Object::newObject(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX]), cppResult, true, true);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_StrokeItemFunc_getBoundingBox_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.StrokeItem.getBoundingBox");
        return {};
}

static PyObject* Sbk_Natron_Python_StrokeItemFunc_getBrushType(PyObject* self)
{
    ::Natron::Python::StrokeItem* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::StrokeItem *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STROKEITEM_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getBrushType()const
            Natron::RotoStrokeType cppResult = Natron::RotoStrokeType(const_cast<const ::Natron::Python::StrokeItem*>(cppSelf)->getBrushType());
            pyResult = Shiboken::Conversions::copyToPython(*PepType_SGTP(SbkNatronEngineTypes[SBK_NATRON_ROTOSTROKETYPE_IDX])->converter, &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_StrokeItemFunc_getPoints(PyObject* self)
{
    ::Natron::Python::StrokeItem* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::StrokeItem *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STROKEITEM_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getPoints()const
            // Begin code injection

            std::list<std::list<Natron::Python::StrokePoint> > points = cppSelf->getPoints();
            PyObject* ret = PyList_New((int) points.size());
            int i = 0;
            for (std::list<std::list<Natron::Python::StrokePoint> >::iterator it = points.begin(); it!=points.end(); ++it, ++i) {


                PyObject* subStrokeItemList = PyList_New((int) it->size());

                int idx = 0;
                for (std::list<Natron::Python::StrokePoint>::iterator it2 = it->begin(); it2!=it->end(); ++it2,++idx) {
                    PyObject* item = Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STROKEPOINT_IDX]), &*it);
                    // Ownership transferences.
                    PyList_SET_ITEM(subStrokeItemList, idx, item);
                }
                PyList_SET_ITEM(ret, i, subStrokeItemList);
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

static PyObject* Sbk_Natron_Python_StrokeItemFunc_setPoints(PyObject* self, PyObject* pyArg)
{
    ::Natron::Python::StrokeItem* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::StrokeItem *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STROKEITEM_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: StrokeItem::setPoints(std::list<std::list<Natron::Python::StrokePoint> >)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_STD_LIST_NATRON_PYTHON_STROKEPOINT_IDX], (pyArg)))) {
        overloadId = 0; // setPoints(std::list<std::list<Natron::Python::StrokePoint> >)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_StrokeItemFunc_setPoints_TypeError;

    // Call function/method
    {
        ::std::list<std::list< Natron::Python::StrokePoint > > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPoints(std::list<std::list<Natron::Python::StrokePoint> >)
            cppSelf->setPoints(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_StrokeItemFunc_setPoints_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.StrokeItem.setPoints");
        return {};
}

static PyMethodDef Sbk_Natron_Python_StrokeItem_methods[] = {
    {"getBoundingBox", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_StrokeItemFunc_getBoundingBox), METH_VARARGS|METH_KEYWORDS},
    {"getBrushType", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_StrokeItemFunc_getBrushType), METH_NOARGS},
    {"getPoints", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_StrokeItemFunc_getPoints), METH_NOARGS},
    {"setPoints", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_StrokeItemFunc_setPoints), METH_O},

    {nullptr, nullptr} // Sentinel
};

} // extern "C"

static int Sbk_Natron_Python_StrokeItem_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_Natron_Python_StrokeItem_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_Natron_Python_StrokeItem_Type = nullptr;
static SbkObjectType *Sbk_Natron_Python_StrokeItem_TypeF(void)
{
    return _Sbk_Natron_Python_StrokeItem_Type;
}

static PyType_Slot Sbk_Natron_Python_StrokeItem_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_Natron_Python_StrokeItem_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_Natron_Python_StrokeItem_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_Natron_Python_StrokeItem_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        nullptr},
    {Py_tp_new,         reinterpret_cast<void*>(SbkDummyNew /* PYSIDE-595: Prevent replacement of "0" with base->tp_new. */)},
    {0, nullptr}
};
static PyType_Spec Sbk_Natron_Python_StrokeItem_spec = {
    "NatronEngine.Natron.Python.StrokeItem",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Natron_Python_StrokeItem_slots
};

} //extern "C"

static void* Sbk_Natron_Python_StrokeItem_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::Natron::Python::ItemBase >()))
        return dynamic_cast< ::Natron::Python::StrokeItem*>(reinterpret_cast< ::Natron::Python::ItemBase*>(cptr));
    return {};
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void StrokeItem_PythonToCpp_StrokeItem_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_Natron_Python_StrokeItem_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_StrokeItem_PythonToCpp_StrokeItem_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_StrokeItem_TypeF())))
        return StrokeItem_PythonToCpp_StrokeItem_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* StrokeItem_PTR_CppToPython_StrokeItem(const void* cppIn) {
    auto pyOut = reinterpret_cast<PyObject*>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::Natron::Python::StrokeItem *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_Natron_Python_StrokeItem_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *Natron_Python_StrokeItem_SignatureStrings[] = {
    "NatronEngine.Natron.Python.StrokeItem.getBoundingBox(time:double,view:QString=QLatin1String(kPyParamViewIdxMain))->NatronEngine.Natron.RectD",
    "NatronEngine.Natron.Python.StrokeItem.getBrushType()->NatronEngine.Natron.RotoStrokeType",
    "NatronEngine.Natron.Python.StrokeItem.getPoints()->QList[QList]",
    "NatronEngine.Natron.Python.StrokeItem.setPoints(strokes:QList[QList])",
    nullptr}; // Sentinel

void init_Natron_Python_StrokeItem(PyObject* module)
{
    _Sbk_Natron_Python_StrokeItem_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "StrokeItem",
        "Natron::Python::StrokeItem*",
        &Sbk_Natron_Python_StrokeItem_spec,
        Natron_Python_StrokeItem_SignatureStrings,
        &Shiboken::callCppDestructor< ::Natron::Python::StrokeItem >,
        reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ITEMBASE_IDX]),
        0,
        0    );
    
    SbkNatronEngineTypes[SBK_NATRON_PYTHON_STROKEITEM_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_StrokeItem_TypeF());

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_Natron_Python_StrokeItem_TypeF(),
        StrokeItem_PythonToCpp_StrokeItem_PTR,
        is_StrokeItem_PythonToCpp_StrokeItem_PTR_Convertible,
        StrokeItem_PTR_CppToPython_StrokeItem);

    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::StrokeItem");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::StrokeItem*");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::StrokeItem&");
    Shiboken::Conversions::registerConverterName(converter, "Python::StrokeItem");
    Shiboken::Conversions::registerConverterName(converter, "Python::StrokeItem*");
    Shiboken::Conversions::registerConverterName(converter, "Python::StrokeItem&");
    Shiboken::Conversions::registerConverterName(converter, "StrokeItem");
    Shiboken::Conversions::registerConverterName(converter, "StrokeItem*");
    Shiboken::Conversions::registerConverterName(converter, "StrokeItem&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Natron::Python::StrokeItem).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::StrokeItemWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_Natron_Python_StrokeItem_TypeF(), &Sbk_Natron_Python_StrokeItem_typeDiscovery);


    StrokeItemWrapper::pysideInitQtMetaTypes();
}
