
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
#include <algorithm>
#include <set>

// module include
#include "natronengine_python.h"

// main header
#include "natron_python_effect_wrapper.h"

// inner classes

// Extra includes
#include <PyItemsTable.h>
#include <PyNode.h>
#include <PyNodeGroup.h>
#include <PyOverlayInteract.h>
#include <PyParameter.h>
#include <RectD.h>
#include <RectI.h>
#include <list>
#include <map>


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

void EffectWrapper::pysideInitQtMetaTypes()
{
}

EffectWrapper::~EffectWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_Natron_Python_EffectFunc_addUserPlane(PyObject* self, PyObject* args)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "addUserPlane", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: Effect::addUserPlane(QString,QStringList)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArgs[1])))) {
        overloadId = 0; // addUserPlane(QString,QStringList)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_EffectFunc_addUserPlane_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QStringList cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // addUserPlane(QString,QStringList)
            bool cppResult = cppSelf->addUserPlane(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_EffectFunc_addUserPlane_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.Effect.addUserPlane");
        return {};
}

static PyObject* Sbk_Natron_Python_EffectFunc_beginChanges(PyObject* self)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // beginChanges()
            cppSelf->beginChanges();
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_Natron_Python_EffectFunc_beginParametersUndoCommand(PyObject* self, PyObject* pyArg)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: Effect::beginParametersUndoCommand(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // beginParametersUndoCommand(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_EffectFunc_beginParametersUndoCommand_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // beginParametersUndoCommand(QString)
            cppSelf->beginParametersUndoCommand(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_EffectFunc_beginParametersUndoCommand_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.Effect.beginParametersUndoCommand");
        return {};
}

static PyObject* Sbk_Natron_Python_EffectFunc_canConnectInput(PyObject* self, PyObject* args)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "canConnectInput", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: Effect::canConnectInput(int,const Natron::Python::Effect*)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX]), (pyArgs[1])))) {
        overloadId = 0; // canConnectInput(int,const Natron::Python::Effect*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_EffectFunc_canConnectInput_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return {};
        ::Natron::Python::Effect* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // canConnectInput(int,const Natron::Python::Effect*)const
            bool cppResult = const_cast<const ::Natron::Python::Effect*>(cppSelf)->canConnectInput(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_EffectFunc_canConnectInput_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.Effect.canConnectInput");
        return {};
}

static PyObject* Sbk_Natron_Python_EffectFunc_clearViewerUIParameters(PyObject* self)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clearViewerUIParameters()
            cppSelf->clearViewerUIParameters();
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_Natron_Python_EffectFunc_connectInput(PyObject* self, PyObject* args)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "connectInput", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: Effect::connectInput(int,const Natron::Python::Effect*)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX]), (pyArgs[1])))) {
        overloadId = 0; // connectInput(int,const Natron::Python::Effect*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_EffectFunc_connectInput_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return {};
        ::Natron::Python::Effect* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // connectInput(int,const Natron::Python::Effect*)
            // Begin code injection

            bool cppResult = cppSelf->connectInput(cppArg0,cppArg1);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_EffectFunc_connectInput_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.Effect.connectInput");
        return {};
}

static PyObject* Sbk_Natron_Python_EffectFunc_destroy(PyObject* self)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // destroy()
            cppSelf->destroy();
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_Natron_Python_EffectFunc_disconnectInput(PyObject* self, PyObject* pyArg)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: Effect::disconnectInput(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // disconnectInput(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_EffectFunc_disconnectInput_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // disconnectInput(int)
            // Begin code injection

            cppSelf->disconnectInput(cppArg0);

            // End of code injection


        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_EffectFunc_disconnectInput_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.Effect.disconnectInput");
        return {};
}

static PyObject* Sbk_Natron_Python_EffectFunc_endChanges(PyObject* self)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // endChanges()
            cppSelf->endChanges();
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_Natron_Python_EffectFunc_endParametersUndoCommand(PyObject* self)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // endParametersUndoCommand()
            cppSelf->endParametersUndoCommand();
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_Natron_Python_EffectFunc_getAllItemsTable(PyObject* self)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getAllItemsTable()const
            // Begin code injection

            std::list<Natron::Python::ItemsTable*> tables = cppSelf->getAllItemsTable();
            PyObject* ret = PyList_New((int) tables.size());
            int idx = 0;
            for (std::list<Natron::Python::ItemsTable*>::iterator it = tables.begin(); it!=tables.end(); ++it,++idx) {
            PyObject* item = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ITEMSTABLE_IDX]), *it);
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

static PyObject* Sbk_Natron_Python_EffectFunc_getAvailableLayers(PyObject* self, PyObject* pyArg)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: Effect::getAvailableLayers(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // getAvailableLayers(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_EffectFunc_getAvailableLayers_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getAvailableLayers(int)const
            std::list<Natron::Python::ImageLayer > cppResult = const_cast<const ::Natron::Python::Effect*>(cppSelf)->getAvailableLayers(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_NATRON_PYTHON_IMAGELAYER_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_EffectFunc_getAvailableLayers_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.Effect.getAvailableLayers");
        return {};
}

static PyObject* Sbk_Natron_Python_EffectFunc_getBitDepth(PyObject* self)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getBitDepth()const
            Natron::ImageBitDepthEnum cppResult = Natron::ImageBitDepthEnum(const_cast<const ::Natron::Python::Effect*>(cppSelf)->getBitDepth());
            pyResult = Shiboken::Conversions::copyToPython(*PepType_SGTP(SbkNatronEngineTypes[SBK_NATRON_IMAGEBITDEPTHENUM_IDX])->converter, &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_EffectFunc_getColor(PyObject* self)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getColor(double*,double*,double*)const
            // Begin code injection

            double r,g,b;
            cppSelf->getColor(&r,&g,&b);
            pyResult = PyTuple_New(3);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &r));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &g));
            PyTuple_SET_ITEM(pyResult, 2, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &b));
            return pyResult;

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_EffectFunc_getContainerGroup(PyObject* self)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getContainerGroup()const
            Natron::Python::Group * cppResult = const_cast<const ::Natron::Python::Effect*>(cppSelf)->getContainerGroup();
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_GROUP_IDX]), cppResult);

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

static PyObject* Sbk_Natron_Python_EffectFunc_getCurrentTime(PyObject* self)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getCurrentTime()const
            double cppResult = const_cast<const ::Natron::Python::Effect*>(cppSelf)->getCurrentTime();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_EffectFunc_getFrameRate(PyObject* self)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getFrameRate()const
            double cppResult = const_cast<const ::Natron::Python::Effect*>(cppSelf)->getFrameRate();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_EffectFunc_getInput(PyObject* self, PyObject* pyArg)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: Effect::getInput(QString)const
    // 1: Effect::getInput(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 1; // getInput(int)const
    } else if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // getInput(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_EffectFunc_getInput_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // getInput(const QString & inputLabel) const
        {
            ::QString cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // getInput(QString)const
                Natron::Python::Effect * cppResult = const_cast<const ::Natron::Python::Effect*>(cppSelf)->getInput(cppArg0);
                pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX]), cppResult);

                // Ownership transferences.
                Shiboken::Object::getOwnership(pyResult);
            }
            break;
        }
        case 1: // getInput(int inputNumber) const
        {
            int cppArg0;
            pythonToCpp(pyArg, &cppArg0);

            if (!PyErr_Occurred()) {
                // getInput(int)const
                Natron::Python::Effect * cppResult = const_cast<const ::Natron::Python::Effect*>(cppSelf)->getInput(cppArg0);
                pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX]), cppResult);

                // Ownership transferences.
                Shiboken::Object::getOwnership(pyResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_EffectFunc_getInput_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.Effect.getInput");
        return {};
}

static PyObject* Sbk_Natron_Python_EffectFunc_getInputLabel(PyObject* self, PyObject* pyArg)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: Effect::getInputLabel(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // getInputLabel(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_EffectFunc_getInputLabel_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getInputLabel(int)
            QString cppResult = cppSelf->getInputLabel(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_EffectFunc_getInputLabel_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.Effect.getInputLabel");
        return {};
}

static PyObject* Sbk_Natron_Python_EffectFunc_getItemsTable(PyObject* self, PyObject* pyArg)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: Effect::getItemsTable(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // getItemsTable(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_EffectFunc_getItemsTable_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getItemsTable(QString)const
            Natron::Python::ItemsTable * cppResult = const_cast<const ::Natron::Python::Effect*>(cppSelf)->getItemsTable(cppArg0);
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ITEMSTABLE_IDX]), cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_EffectFunc_getItemsTable_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.Effect.getItemsTable");
        return {};
}

static PyObject* Sbk_Natron_Python_EffectFunc_getLabel(PyObject* self)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getLabel()const
            QString cppResult = const_cast<const ::Natron::Python::Effect*>(cppSelf)->getLabel();
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_EffectFunc_getMaxInputCount(PyObject* self)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getMaxInputCount()const
            int cppResult = const_cast<const ::Natron::Python::Effect*>(cppSelf)->getMaxInputCount();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_EffectFunc_getOutputFormat(PyObject* self)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getOutputFormat()const
            Natron::RectI* cppResult = new Natron::RectI(const_cast<const ::Natron::Python::Effect*>(cppSelf)->getOutputFormat());
            pyResult = Shiboken::Object::newObject(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX]), cppResult, true, true);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_EffectFunc_getParam(PyObject* self, PyObject* pyArg)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: Effect::getParam(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // getParam(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_EffectFunc_getParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getParam(QString)const
            Natron::Python::Param * cppResult = const_cast<const ::Natron::Python::Effect*>(cppSelf)->getParam(cppArg0);
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

    Sbk_Natron_Python_EffectFunc_getParam_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.Effect.getParam");
        return {};
}

static PyObject* Sbk_Natron_Python_EffectFunc_getParams(PyObject* self)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));
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

static PyObject* Sbk_Natron_Python_EffectFunc_getPixelAspectRatio(PyObject* self)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getPixelAspectRatio()const
            double cppResult = const_cast<const ::Natron::Python::Effect*>(cppSelf)->getPixelAspectRatio();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_EffectFunc_getPluginID(PyObject* self)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getPluginID()const
            QString cppResult = const_cast<const ::Natron::Python::Effect*>(cppSelf)->getPluginID();
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_EffectFunc_getPosition(PyObject* self)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getPosition(double*,double*)const
            // Begin code injection

            double x,y;
            cppSelf->getPosition(&x,&y);
            pyResult = PyTuple_New(2);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &x));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &y));
            return pyResult;

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_EffectFunc_getPremult(PyObject* self)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getPremult()const
            Natron::ImagePremultiplicationEnum cppResult = Natron::ImagePremultiplicationEnum(const_cast<const ::Natron::Python::Effect*>(cppSelf)->getPremult());
            pyResult = Shiboken::Conversions::copyToPython(*PepType_SGTP(SbkNatronEngineTypes[SBK_NATRON_IMAGEPREMULTIPLICATIONENUM_IDX])->converter, &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_EffectFunc_getRegionOfDefinition(PyObject* self, PyObject* args)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "getRegionOfDefinition", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: Effect::getRegionOfDefinition(double,QString)const
    // 1: Effect::getRegionOfDefinition(double,int)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))) {
        if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 1; // getRegionOfDefinition(double,int)const
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
            overloadId = 0; // getRegionOfDefinition(double,QString)const
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_EffectFunc_getRegionOfDefinition_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // getRegionOfDefinition(double time, const QString & view) const
        {
            double cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            ::QString cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // getRegionOfDefinition(double,QString)const
                Natron::RectD* cppResult = new Natron::RectD(const_cast<const ::Natron::Python::Effect*>(cppSelf)->getRegionOfDefinition(cppArg0, cppArg1));
                pyResult = Shiboken::Object::newObject(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX]), cppResult, true, true);
            }
            break;
        }
        case 1: // getRegionOfDefinition(double time, int view) const
        {
            double cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // getRegionOfDefinition(double,int)const
                Natron::RectD* cppResult = new Natron::RectD(const_cast<const ::Natron::Python::Effect*>(cppSelf)->getRegionOfDefinition(cppArg0, cppArg1));
                pyResult = Shiboken::Object::newObject(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX]), cppResult, true, true);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_EffectFunc_getRegionOfDefinition_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.Effect.getRegionOfDefinition");
        return {};
}

static PyObject* Sbk_Natron_Python_EffectFunc_getScriptName(PyObject* self)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getScriptName()const
            QString cppResult = const_cast<const ::Natron::Python::Effect*>(cppSelf)->getScriptName();
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_EffectFunc_getSize(PyObject* self)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getSize(double*,double*)const
            // Begin code injection

            double x,y;
            cppSelf->getSize(&x,&y);
            pyResult = PyTuple_New(2);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &x));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &y));
            return pyResult;

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_EffectFunc_getUserPageParam(PyObject* self)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getUserPageParam()const
            Natron::Python::PageParam * cppResult = const_cast<const ::Natron::Python::Effect*>(cppSelf)->getUserPageParam();
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PAGEPARAM_IDX]), cppResult);

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

static PyObject* Sbk_Natron_Python_EffectFunc_insertParamInViewerUI(PyObject* self, PyObject* args, PyObject* kwds)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Effect.insertParamInViewerUI(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Effect.insertParamInViewerUI(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OO:insertParamInViewerUI", &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: Effect::insertParamInViewerUI(Natron::Python::Param*,int)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // insertParamInViewerUI(Natron::Python::Param*,int)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            overloadId = 0; // insertParamInViewerUI(Natron::Python::Param*,int)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_EffectFunc_insertParamInViewerUI_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "index");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.Effect.insertParamInViewerUI(): got multiple values for keyword argument 'index'.");
                return {};
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_Natron_Python_EffectFunc_insertParamInViewerUI_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return {};
        ::Natron::Python::Param* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = -1;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // insertParamInViewerUI(Natron::Python::Param*,int)
            cppSelf->insertParamInViewerUI(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_EffectFunc_insertParamInViewerUI_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.Effect.insertParamInViewerUI");
        return {};
}

static PyObject* Sbk_Natron_Python_EffectFunc_isNodeSelected(PyObject* self)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isNodeSelected()const
            bool cppResult = const_cast<const ::Natron::Python::Effect*>(cppSelf)->isNodeSelected();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_EffectFunc_isReaderNode(PyObject* self)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isReaderNode()
            bool cppResult = cppSelf->isReaderNode();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_EffectFunc_isWriterNode(PyObject* self)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isWriterNode()
            bool cppResult = cppSelf->isWriterNode();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_EffectFunc_registerOverlay(PyObject* self, PyObject* args)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "registerOverlay", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: Effect::registerOverlay(Natron::Python::PyOverlayInteract*,std::map<QString,QString>)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYOVERLAYINTERACT_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_MAP_QSTRING_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // registerOverlay(Natron::Python::PyOverlayInteract*,std::map<QString,QString>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_EffectFunc_registerOverlay_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return {};
        ::Natron::Python::PyOverlayInteract* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::std::map<QString,QString > cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // registerOverlay(Natron::Python::PyOverlayInteract*,std::map<QString,QString>)
            bool cppResult = cppSelf->registerOverlay(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_EffectFunc_registerOverlay_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.Effect.registerOverlay");
        return {};
}

static PyObject* Sbk_Natron_Python_EffectFunc_removeOverlay(PyObject* self, PyObject* pyArg)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: Effect::removeOverlay(Natron::Python::PyOverlayInteract*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYOVERLAYINTERACT_IDX]), (pyArg)))) {
        overloadId = 0; // removeOverlay(Natron::Python::PyOverlayInteract*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_EffectFunc_removeOverlay_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return {};
        ::Natron::Python::PyOverlayInteract* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // removeOverlay(Natron::Python::PyOverlayInteract*)
            cppSelf->removeOverlay(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_EffectFunc_removeOverlay_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.Effect.removeOverlay");
        return {};
}

static PyObject* Sbk_Natron_Python_EffectFunc_removeParamFromViewerUI(PyObject* self, PyObject* pyArg)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: Effect::removeParamFromViewerUI(Natron::Python::Param*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX]), (pyArg)))) {
        overloadId = 0; // removeParamFromViewerUI(Natron::Python::Param*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_EffectFunc_removeParamFromViewerUI_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return {};
        ::Natron::Python::Param* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // removeParamFromViewerUI(Natron::Python::Param*)
            cppSelf->removeParamFromViewerUI(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_EffectFunc_removeParamFromViewerUI_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.Effect.removeParamFromViewerUI");
        return {};
}

static PyObject* Sbk_Natron_Python_EffectFunc_setColor(PyObject* self, PyObject* args)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setColor", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return {};


    // Overloaded function decisor
    // 0: Effect::setColor(double,double,double)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2])))) {
        overloadId = 0; // setColor(double,double,double)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_EffectFunc_setColor_TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        double cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        double cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // setColor(double,double,double)
            cppSelf->setColor(cppArg0, cppArg1, cppArg2);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_EffectFunc_setColor_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.Effect.setColor");
        return {};
}

static PyObject* Sbk_Natron_Python_EffectFunc_setLabel(PyObject* self, PyObject* pyArg)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: Effect::setLabel(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setLabel(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_EffectFunc_setLabel_TypeError;

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

    Sbk_Natron_Python_EffectFunc_setLabel_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.Effect.setLabel");
        return {};
}

static PyObject* Sbk_Natron_Python_EffectFunc_setPagesOrder(PyObject* self, PyObject* pyArg)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: Effect::setPagesOrder(QStringList)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], (pyArg)))) {
        overloadId = 0; // setPagesOrder(QStringList)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_EffectFunc_setPagesOrder_TypeError;

    // Call function/method
    {
        ::QStringList cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPagesOrder(QStringList)
            cppSelf->setPagesOrder(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_EffectFunc_setPagesOrder_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.Effect.setPagesOrder");
        return {};
}

static PyObject* Sbk_Natron_Python_EffectFunc_setPosition(PyObject* self, PyObject* args)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setPosition", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: Effect::setPosition(double,double)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))) {
        overloadId = 0; // setPosition(double,double)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_EffectFunc_setPosition_TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        double cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setPosition(double,double)
            cppSelf->setPosition(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_EffectFunc_setPosition_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.Effect.setPosition");
        return {};
}

static PyObject* Sbk_Natron_Python_EffectFunc_setScriptName(PyObject* self, PyObject* pyArg)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: Effect::setScriptName(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setScriptName(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_EffectFunc_setScriptName_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setScriptName(QString)
            // Begin code injection

            bool cppResult = cppSelf->setScriptName(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_EffectFunc_setScriptName_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.Effect.setScriptName");
        return {};
}

static PyObject* Sbk_Natron_Python_EffectFunc_setSize(PyObject* self, PyObject* args)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setSize", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: Effect::setSize(double,double)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))) {
        overloadId = 0; // setSize(double,double)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_EffectFunc_setSize_TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        double cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setSize(double,double)
            cppSelf->setSize(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_EffectFunc_setSize_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.Effect.setSize");
        return {};
}

static PyObject* Sbk_Natron_Python_EffectFunc_setSubGraphEditable(PyObject* self, PyObject* pyArg)
{
    ::Natron::Python::Effect* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::Effect *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: Effect::setSubGraphEditable(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setSubGraphEditable(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_EffectFunc_setSubGraphEditable_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setSubGraphEditable(bool)
            cppSelf->setSubGraphEditable(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_EffectFunc_setSubGraphEditable_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.Effect.setSubGraphEditable");
        return {};
}

static PyMethodDef Sbk_Natron_Python_Effect_methods[] = {
    {"addUserPlane", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_addUserPlane), METH_VARARGS},
    {"beginChanges", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_beginChanges), METH_NOARGS},
    {"beginParametersUndoCommand", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_beginParametersUndoCommand), METH_O},
    {"canConnectInput", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_canConnectInput), METH_VARARGS},
    {"clearViewerUIParameters", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_clearViewerUIParameters), METH_NOARGS},
    {"connectInput", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_connectInput), METH_VARARGS},
    {"destroy", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_destroy), METH_NOARGS},
    {"disconnectInput", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_disconnectInput), METH_O},
    {"endChanges", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_endChanges), METH_NOARGS},
    {"endParametersUndoCommand", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_endParametersUndoCommand), METH_NOARGS},
    {"getAllItemsTable", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_getAllItemsTable), METH_NOARGS},
    {"getAvailableLayers", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_getAvailableLayers), METH_O},
    {"getBitDepth", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_getBitDepth), METH_NOARGS},
    {"getColor", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_getColor), METH_NOARGS},
    {"getContainerGroup", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_getContainerGroup), METH_NOARGS},
    {"getCurrentTime", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_getCurrentTime), METH_NOARGS},
    {"getFrameRate", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_getFrameRate), METH_NOARGS},
    {"getInput", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_getInput), METH_O},
    {"getInputLabel", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_getInputLabel), METH_O},
    {"getItemsTable", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_getItemsTable), METH_O},
    {"getLabel", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_getLabel), METH_NOARGS},
    {"getMaxInputCount", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_getMaxInputCount), METH_NOARGS},
    {"getOutputFormat", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_getOutputFormat), METH_NOARGS},
    {"getParam", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_getParam), METH_O},
    {"getParams", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_getParams), METH_NOARGS},
    {"getPixelAspectRatio", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_getPixelAspectRatio), METH_NOARGS},
    {"getPluginID", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_getPluginID), METH_NOARGS},
    {"getPosition", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_getPosition), METH_NOARGS},
    {"getPremult", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_getPremult), METH_NOARGS},
    {"getRegionOfDefinition", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_getRegionOfDefinition), METH_VARARGS},
    {"getScriptName", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_getScriptName), METH_NOARGS},
    {"getSize", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_getSize), METH_NOARGS},
    {"getUserPageParam", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_getUserPageParam), METH_NOARGS},
    {"insertParamInViewerUI", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_insertParamInViewerUI), METH_VARARGS|METH_KEYWORDS},
    {"isNodeSelected", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_isNodeSelected), METH_NOARGS},
    {"isReaderNode", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_isReaderNode), METH_NOARGS},
    {"isWriterNode", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_isWriterNode), METH_NOARGS},
    {"registerOverlay", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_registerOverlay), METH_VARARGS},
    {"removeOverlay", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_removeOverlay), METH_O},
    {"removeParamFromViewerUI", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_removeParamFromViewerUI), METH_O},
    {"setColor", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_setColor), METH_VARARGS},
    {"setLabel", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_setLabel), METH_O},
    {"setPagesOrder", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_setPagesOrder), METH_O},
    {"setPosition", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_setPosition), METH_VARARGS},
    {"setScriptName", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_setScriptName), METH_O},
    {"setSize", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_setSize), METH_VARARGS},
    {"setSubGraphEditable", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_EffectFunc_setSubGraphEditable), METH_O},

    {nullptr, nullptr} // Sentinel
};

} // extern "C"

static int Sbk_Natron_Python_Effect_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_Natron_Python_Effect_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
static int mi_offsets[] = { -1, -1, -1, -1, -1 };
int*
Sbk_Natron_Python_Effect_mi_init(const void* cptr)
{
    if (mi_offsets[0] == -1) {
        std::set<int> offsets;
        const auto* class_ptr = reinterpret_cast<const Natron::Python::Effect*>(cptr);
        const auto base = reinterpret_cast<uintptr_t>(class_ptr);
        offsets.insert(int(reinterpret_cast<uintptr_t>(static_cast<const Natron::Python::Group*>(class_ptr)) - base));
        offsets.insert(int(reinterpret_cast<uintptr_t>(static_cast<const Natron::Python::Group*>(static_cast<const Natron::Python::Effect*>(static_cast<const void*>(class_ptr)))) - base));
        offsets.insert(int(reinterpret_cast<uintptr_t>(static_cast<const Natron::Python::UserParamHolder*>(class_ptr)) - base));
        offsets.insert(int(reinterpret_cast<uintptr_t>(static_cast<const Natron::Python::UserParamHolder*>(static_cast<const Natron::Python::Effect*>(static_cast<const void*>(class_ptr)))) - base));

        offsets.erase(0);

        std::copy(offsets.cbegin(), offsets.cend(), mi_offsets);
    }
    return mi_offsets;
}
static void* Sbk_Natron_Python_EffectSpecialCastFunction(void* obj, SbkObjectType* desiredType)
{
    Natron::Python::Effect* me = reinterpret_cast< ::Natron::Python::Effect*>(obj);
    if (desiredType == reinterpret_cast<SbkObjectType*>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_GROUP_IDX]))
        return static_cast< ::Natron::Python::Group*>(me);
    else if (desiredType == reinterpret_cast<SbkObjectType*>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_USERPARAMHOLDER_IDX]))
        return static_cast< ::Natron::Python::UserParamHolder*>(me);
    return me;
}


// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_Natron_Python_Effect_Type = nullptr;
static SbkObjectType *Sbk_Natron_Python_Effect_TypeF(void)
{
    return _Sbk_Natron_Python_Effect_Type;
}

static PyType_Slot Sbk_Natron_Python_Effect_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_Natron_Python_Effect_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_Natron_Python_Effect_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_Natron_Python_Effect_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        nullptr},
    {Py_tp_new,         reinterpret_cast<void*>(SbkDummyNew /* PYSIDE-595: Prevent replacement of "0" with base->tp_new. */)},
    {0, nullptr}
};
static PyType_Spec Sbk_Natron_Python_Effect_spec = {
    "NatronEngine.Natron.Python.Effect",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Natron_Python_Effect_slots
};

} //extern "C"

static void* Sbk_Natron_Python_Effect_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::Natron::Python::Group >()))
        return dynamic_cast< ::Natron::Python::Effect*>(reinterpret_cast< ::Natron::Python::Group*>(cptr));
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::Natron::Python::UserParamHolder >()))
        return dynamic_cast< ::Natron::Python::Effect*>(reinterpret_cast< ::Natron::Python::UserParamHolder*>(cptr));
    return {};
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void Effect_PythonToCpp_Effect_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_Natron_Python_Effect_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_Effect_PythonToCpp_Effect_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_Effect_TypeF())))
        return Effect_PythonToCpp_Effect_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* Effect_PTR_CppToPython_Effect(const void* cppIn) {
    auto pyOut = reinterpret_cast<PyObject*>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::Natron::Python::Effect *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_Natron_Python_Effect_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *Natron_Python_Effect_SignatureStrings[] = {
    "NatronEngine.Natron.Python.Effect.addUserPlane(planeName:QString,channels:QStringList)->bool",
    "NatronEngine.Natron.Python.Effect.beginChanges()",
    "NatronEngine.Natron.Python.Effect.beginParametersUndoCommand(name:QString)",
    "NatronEngine.Natron.Python.Effect.canConnectInput(inputNumber:int,node:NatronEngine.Natron.Python.Effect)->bool",
    "NatronEngine.Natron.Python.Effect.clearViewerUIParameters()",
    "NatronEngine.Natron.Python.Effect.connectInput(inputNumber:int,input:NatronEngine.Natron.Python.Effect)->bool",
    "NatronEngine.Natron.Python.Effect.destroy()",
    "NatronEngine.Natron.Python.Effect.disconnectInput(inputNumber:int)",
    "NatronEngine.Natron.Python.Effect.endChanges()",
    "NatronEngine.Natron.Python.Effect.endParametersUndoCommand()",
    "NatronEngine.Natron.Python.Effect.getAllItemsTable()->QList[NatronEngine.Natron.Python.ItemsTable]",
    "NatronEngine.Natron.Python.Effect.getAvailableLayers(inputNb:int)->QList[NatronEngine.Natron.Python.ImageLayer]",
    "NatronEngine.Natron.Python.Effect.getBitDepth()->NatronEngine.Natron.ImageBitDepthEnum",
    "NatronEngine.Natron.Python.Effect.getColor(r:NatronEngine.double,g:NatronEngine.double,b:NatronEngine.double)",
    "NatronEngine.Natron.Python.Effect.getContainerGroup()->NatronEngine.Natron.Python.Group",
    "NatronEngine.Natron.Python.Effect.getCurrentTime()->double",
    "NatronEngine.Natron.Python.Effect.getFrameRate()->double",
    "1:NatronEngine.Natron.Python.Effect.getInput(inputLabel:QString)->NatronEngine.Natron.Python.Effect",
    "0:NatronEngine.Natron.Python.Effect.getInput(inputNumber:int)->NatronEngine.Natron.Python.Effect",
    "NatronEngine.Natron.Python.Effect.getInputLabel(inputNumber:int)->QString",
    "NatronEngine.Natron.Python.Effect.getItemsTable(identifier:QString)->NatronEngine.Natron.Python.ItemsTable",
    "NatronEngine.Natron.Python.Effect.getLabel()->QString",
    "NatronEngine.Natron.Python.Effect.getMaxInputCount()->int",
    "NatronEngine.Natron.Python.Effect.getOutputFormat()->NatronEngine.Natron.RectI",
    "NatronEngine.Natron.Python.Effect.getParam(name:QString)->NatronEngine.Natron.Python.Param",
    "NatronEngine.Natron.Python.Effect.getParams()->QList[NatronEngine.Natron.Python.Param]",
    "NatronEngine.Natron.Python.Effect.getPixelAspectRatio()->double",
    "NatronEngine.Natron.Python.Effect.getPluginID()->QString",
    "NatronEngine.Natron.Python.Effect.getPosition(x:NatronEngine.double,y:NatronEngine.double)",
    "NatronEngine.Natron.Python.Effect.getPremult()->NatronEngine.Natron.ImagePremultiplicationEnum",
    "1:NatronEngine.Natron.Python.Effect.getRegionOfDefinition(time:double,view:QString)->NatronEngine.Natron.RectD",
    "0:NatronEngine.Natron.Python.Effect.getRegionOfDefinition(time:double,view:int)->NatronEngine.Natron.RectD",
    "NatronEngine.Natron.Python.Effect.getScriptName()->QString",
    "NatronEngine.Natron.Python.Effect.getSize(w:NatronEngine.double,h:NatronEngine.double)",
    "NatronEngine.Natron.Python.Effect.getUserPageParam()->NatronEngine.Natron.Python.PageParam",
    "NatronEngine.Natron.Python.Effect.insertParamInViewerUI(param:NatronEngine.Natron.Python.Param,index:int=-1)",
    "NatronEngine.Natron.Python.Effect.isNodeSelected()->bool",
    "NatronEngine.Natron.Python.Effect.isReaderNode()->bool",
    "NatronEngine.Natron.Python.Effect.isWriterNode()->bool",
    "NatronEngine.Natron.Python.Effect.registerOverlay(interact:NatronEngine.Natron.Python.PyOverlayInteract,params:QMap)->bool",
    "NatronEngine.Natron.Python.Effect.removeOverlay(interact:NatronEngine.Natron.Python.PyOverlayInteract)",
    "NatronEngine.Natron.Python.Effect.removeParamFromViewerUI(param:NatronEngine.Natron.Python.Param)",
    "NatronEngine.Natron.Python.Effect.setColor(r:double,g:double,b:double)",
    "NatronEngine.Natron.Python.Effect.setLabel(name:QString)",
    "NatronEngine.Natron.Python.Effect.setPagesOrder(pages:QStringList)",
    "NatronEngine.Natron.Python.Effect.setPosition(x:double,y:double)",
    "NatronEngine.Natron.Python.Effect.setScriptName(scriptName:QString)->bool",
    "NatronEngine.Natron.Python.Effect.setSize(w:double,h:double)",
    "NatronEngine.Natron.Python.Effect.setSubGraphEditable(editable:bool)",
    nullptr}; // Sentinel

void init_Natron_Python_Effect(PyObject* module)
{
    PyObject* Sbk_Natron_Python_Effect_Type_bases = PyTuple_Pack(2,
        reinterpret_cast<PyObject*>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_GROUP_IDX]),
        reinterpret_cast<PyObject*>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_USERPARAMHOLDER_IDX]));

    _Sbk_Natron_Python_Effect_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "Effect",
        "Natron::Python::Effect*",
        &Sbk_Natron_Python_Effect_spec,
        Natron_Python_Effect_SignatureStrings,
        &Shiboken::callCppDestructor< ::Natron::Python::Effect >,
        reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_USERPARAMHOLDER_IDX]),
        Sbk_Natron_Python_Effect_Type_bases,
        0    );
    
    SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_Effect_TypeF());

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_Natron_Python_Effect_TypeF(),
        Effect_PythonToCpp_Effect_PTR,
        is_Effect_PythonToCpp_Effect_PTR_Convertible,
        Effect_PTR_CppToPython_Effect);

    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::Effect");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::Effect*");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::Effect&");
    Shiboken::Conversions::registerConverterName(converter, "Python::Effect");
    Shiboken::Conversions::registerConverterName(converter, "Python::Effect*");
    Shiboken::Conversions::registerConverterName(converter, "Python::Effect&");
    Shiboken::Conversions::registerConverterName(converter, "Effect");
    Shiboken::Conversions::registerConverterName(converter, "Effect*");
    Shiboken::Conversions::registerConverterName(converter, "Effect&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Natron::Python::Effect).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::EffectWrapper).name());


    MultipleInheritanceInitFunction func = Sbk_Natron_Python_Effect_mi_init;
    Shiboken::ObjectType::setMultipleInheritanceFunction(Sbk_Natron_Python_Effect_TypeF(), func);
    Shiboken::ObjectType::setCastFunction(Sbk_Natron_Python_Effect_TypeF(), &Sbk_Natron_Python_EffectSpecialCastFunction);
    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_Natron_Python_Effect_TypeF(), &Sbk_Natron_Python_Effect_typeDiscovery);


    EffectWrapper::pysideInitQtMetaTypes();
}
