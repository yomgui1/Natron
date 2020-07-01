
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
#include "natron_python_userparamholder_wrapper.h"

// inner classes

// Extra includes
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

void UserParamHolderWrapper::pysideInitQtMetaTypes()
{
}

UserParamHolderWrapper::UserParamHolderWrapper() : Natron::Python::UserParamHolder()
{
    // ... middle
}

UserParamHolderWrapper::~UserParamHolderWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_Natron_Python_UserParamHolder_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::Natron::Python::UserParamHolder >()))
        return -1;

    ::UserParamHolderWrapper* cptr{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // UserParamHolder()
            cptr = new ::UserParamHolderWrapper();
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::Natron::Python::UserParamHolder >(), cptr)) {
        delete cptr;
        return -1;
    }
    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    if (Shiboken::BindingManager::instance().hasWrapper(cptr)) {
        Shiboken::BindingManager::instance().releaseWrapper(Shiboken::BindingManager::instance().retrieveWrapper(cptr));
    }
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;
}

static PyObject* Sbk_Natron_Python_UserParamHolderFunc_createBooleanParam(PyObject* self, PyObject* args)
{
    ::Natron::Python::UserParamHolder* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::UserParamHolder *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_USERPARAMHOLDER_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createBooleanParam", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: UserParamHolder::createBooleanParam(QString,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // createBooleanParam(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_UserParamHolderFunc_createBooleanParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // createBooleanParam(QString,QString)
            Natron::Python::BooleanParam * cppResult = cppSelf->createBooleanParam(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_BOOLEANPARAM_IDX]), cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_UserParamHolderFunc_createBooleanParam_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.UserParamHolder.createBooleanParam");
        return {};
}

static PyObject* Sbk_Natron_Python_UserParamHolderFunc_createButtonParam(PyObject* self, PyObject* args)
{
    ::Natron::Python::UserParamHolder* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::UserParamHolder *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_USERPARAMHOLDER_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createButtonParam", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: UserParamHolder::createButtonParam(QString,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // createButtonParam(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_UserParamHolderFunc_createButtonParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // createButtonParam(QString,QString)
            Natron::Python::ButtonParam * cppResult = cppSelf->createButtonParam(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_BUTTONPARAM_IDX]), cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_UserParamHolderFunc_createButtonParam_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.UserParamHolder.createButtonParam");
        return {};
}

static PyObject* Sbk_Natron_Python_UserParamHolderFunc_createChoiceParam(PyObject* self, PyObject* args)
{
    ::Natron::Python::UserParamHolder* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::UserParamHolder *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_USERPARAMHOLDER_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createChoiceParam", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: UserParamHolder::createChoiceParam(QString,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // createChoiceParam(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_UserParamHolderFunc_createChoiceParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // createChoiceParam(QString,QString)
            Natron::Python::ChoiceParam * cppResult = cppSelf->createChoiceParam(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_CHOICEPARAM_IDX]), cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_UserParamHolderFunc_createChoiceParam_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.UserParamHolder.createChoiceParam");
        return {};
}

static PyObject* Sbk_Natron_Python_UserParamHolderFunc_createColorParam(PyObject* self, PyObject* args)
{
    ::Natron::Python::UserParamHolder* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::UserParamHolder *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_USERPARAMHOLDER_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createColorParam", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return {};


    // Overloaded function decisor
    // 0: UserParamHolder::createColorParam(QString,QString,bool)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[2])))) {
        overloadId = 0; // createColorParam(QString,QString,bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_UserParamHolderFunc_createColorParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        bool cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // createColorParam(QString,QString,bool)
            Natron::Python::ColorParam * cppResult = cppSelf->createColorParam(cppArg0, cppArg1, cppArg2);
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_COLORPARAM_IDX]), cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_UserParamHolderFunc_createColorParam_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.UserParamHolder.createColorParam");
        return {};
}

static PyObject* Sbk_Natron_Python_UserParamHolderFunc_createDouble2DParam(PyObject* self, PyObject* args)
{
    ::Natron::Python::UserParamHolder* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::UserParamHolder *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_USERPARAMHOLDER_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createDouble2DParam", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: UserParamHolder::createDouble2DParam(QString,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // createDouble2DParam(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_UserParamHolderFunc_createDouble2DParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // createDouble2DParam(QString,QString)
            Natron::Python::Double2DParam * cppResult = cppSelf->createDouble2DParam(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLE2DPARAM_IDX]), cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_UserParamHolderFunc_createDouble2DParam_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.UserParamHolder.createDouble2DParam");
        return {};
}

static PyObject* Sbk_Natron_Python_UserParamHolderFunc_createDouble3DParam(PyObject* self, PyObject* args)
{
    ::Natron::Python::UserParamHolder* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::UserParamHolder *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_USERPARAMHOLDER_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createDouble3DParam", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: UserParamHolder::createDouble3DParam(QString,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // createDouble3DParam(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_UserParamHolderFunc_createDouble3DParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // createDouble3DParam(QString,QString)
            Natron::Python::Double3DParam * cppResult = cppSelf->createDouble3DParam(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLE3DPARAM_IDX]), cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_UserParamHolderFunc_createDouble3DParam_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.UserParamHolder.createDouble3DParam");
        return {};
}

static PyObject* Sbk_Natron_Python_UserParamHolderFunc_createDoubleParam(PyObject* self, PyObject* args)
{
    ::Natron::Python::UserParamHolder* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::UserParamHolder *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_USERPARAMHOLDER_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createDoubleParam", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: UserParamHolder::createDoubleParam(QString,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // createDoubleParam(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_UserParamHolderFunc_createDoubleParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // createDoubleParam(QString,QString)
            Natron::Python::DoubleParam * cppResult = cppSelf->createDoubleParam(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLEPARAM_IDX]), cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_UserParamHolderFunc_createDoubleParam_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.UserParamHolder.createDoubleParam");
        return {};
}

static PyObject* Sbk_Natron_Python_UserParamHolderFunc_createFileParam(PyObject* self, PyObject* args)
{
    ::Natron::Python::UserParamHolder* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::UserParamHolder *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_USERPARAMHOLDER_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createFileParam", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: UserParamHolder::createFileParam(QString,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // createFileParam(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_UserParamHolderFunc_createFileParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // createFileParam(QString,QString)
            Natron::Python::FileParam * cppResult = cppSelf->createFileParam(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_FILEPARAM_IDX]), cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_UserParamHolderFunc_createFileParam_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.UserParamHolder.createFileParam");
        return {};
}

static PyObject* Sbk_Natron_Python_UserParamHolderFunc_createGroupParam(PyObject* self, PyObject* args)
{
    ::Natron::Python::UserParamHolder* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::UserParamHolder *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_USERPARAMHOLDER_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createGroupParam", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: UserParamHolder::createGroupParam(QString,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // createGroupParam(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_UserParamHolderFunc_createGroupParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // createGroupParam(QString,QString)
            Natron::Python::GroupParam * cppResult = cppSelf->createGroupParam(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_GROUPPARAM_IDX]), cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_UserParamHolderFunc_createGroupParam_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.UserParamHolder.createGroupParam");
        return {};
}

static PyObject* Sbk_Natron_Python_UserParamHolderFunc_createInt2DParam(PyObject* self, PyObject* args)
{
    ::Natron::Python::UserParamHolder* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::UserParamHolder *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_USERPARAMHOLDER_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createInt2DParam", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: UserParamHolder::createInt2DParam(QString,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // createInt2DParam(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_UserParamHolderFunc_createInt2DParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // createInt2DParam(QString,QString)
            Natron::Python::Int2DParam * cppResult = cppSelf->createInt2DParam(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_INT2DPARAM_IDX]), cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_UserParamHolderFunc_createInt2DParam_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.UserParamHolder.createInt2DParam");
        return {};
}

static PyObject* Sbk_Natron_Python_UserParamHolderFunc_createInt3DParam(PyObject* self, PyObject* args)
{
    ::Natron::Python::UserParamHolder* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::UserParamHolder *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_USERPARAMHOLDER_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createInt3DParam", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: UserParamHolder::createInt3DParam(QString,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // createInt3DParam(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_UserParamHolderFunc_createInt3DParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // createInt3DParam(QString,QString)
            Natron::Python::Int3DParam * cppResult = cppSelf->createInt3DParam(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_INT3DPARAM_IDX]), cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_UserParamHolderFunc_createInt3DParam_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.UserParamHolder.createInt3DParam");
        return {};
}

static PyObject* Sbk_Natron_Python_UserParamHolderFunc_createIntParam(PyObject* self, PyObject* args)
{
    ::Natron::Python::UserParamHolder* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::UserParamHolder *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_USERPARAMHOLDER_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createIntParam", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: UserParamHolder::createIntParam(QString,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // createIntParam(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_UserParamHolderFunc_createIntParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // createIntParam(QString,QString)
            Natron::Python::IntParam * cppResult = cppSelf->createIntParam(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_INTPARAM_IDX]), cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_UserParamHolderFunc_createIntParam_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.UserParamHolder.createIntParam");
        return {};
}

static PyObject* Sbk_Natron_Python_UserParamHolderFunc_createOutputFileParam(PyObject* self, PyObject* args)
{
    ::Natron::Python::UserParamHolder* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::UserParamHolder *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_USERPARAMHOLDER_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createOutputFileParam", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: UserParamHolder::createOutputFileParam(QString,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // createOutputFileParam(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_UserParamHolderFunc_createOutputFileParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // createOutputFileParam(QString,QString)
            Natron::Python::FileParam * cppResult = cppSelf->createOutputFileParam(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_FILEPARAM_IDX]), cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_UserParamHolderFunc_createOutputFileParam_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.UserParamHolder.createOutputFileParam");
        return {};
}

static PyObject* Sbk_Natron_Python_UserParamHolderFunc_createPageParam(PyObject* self, PyObject* args)
{
    ::Natron::Python::UserParamHolder* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::UserParamHolder *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_USERPARAMHOLDER_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createPageParam", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: UserParamHolder::createPageParam(QString,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // createPageParam(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_UserParamHolderFunc_createPageParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // createPageParam(QString,QString)
            Natron::Python::PageParam * cppResult = cppSelf->createPageParam(cppArg0, cppArg1);
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

    Sbk_Natron_Python_UserParamHolderFunc_createPageParam_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.UserParamHolder.createPageParam");
        return {};
}

static PyObject* Sbk_Natron_Python_UserParamHolderFunc_createParametricParam(PyObject* self, PyObject* args)
{
    ::Natron::Python::UserParamHolder* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::UserParamHolder *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_USERPARAMHOLDER_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createParametricParam", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return {};


    // Overloaded function decisor
    // 0: UserParamHolder::createParametricParam(QString,QString,int)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        overloadId = 0; // createParametricParam(QString,QString,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_UserParamHolderFunc_createParametricParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // createParametricParam(QString,QString,int)
            Natron::Python::ParametricParam * cppResult = cppSelf->createParametricParam(cppArg0, cppArg1, cppArg2);
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAMETRICPARAM_IDX]), cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_UserParamHolderFunc_createParametricParam_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.UserParamHolder.createParametricParam");
        return {};
}

static PyObject* Sbk_Natron_Python_UserParamHolderFunc_createPathParam(PyObject* self, PyObject* args)
{
    ::Natron::Python::UserParamHolder* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::UserParamHolder *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_USERPARAMHOLDER_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createPathParam", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: UserParamHolder::createPathParam(QString,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // createPathParam(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_UserParamHolderFunc_createPathParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // createPathParam(QString,QString)
            Natron::Python::PathParam * cppResult = cppSelf->createPathParam(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PATHPARAM_IDX]), cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_UserParamHolderFunc_createPathParam_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.UserParamHolder.createPathParam");
        return {};
}

static PyObject* Sbk_Natron_Python_UserParamHolderFunc_createSeparatorParam(PyObject* self, PyObject* args)
{
    ::Natron::Python::UserParamHolder* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::UserParamHolder *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_USERPARAMHOLDER_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createSeparatorParam", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: UserParamHolder::createSeparatorParam(QString,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // createSeparatorParam(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_UserParamHolderFunc_createSeparatorParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // createSeparatorParam(QString,QString)
            Natron::Python::SeparatorParam * cppResult = cppSelf->createSeparatorParam(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_SEPARATORPARAM_IDX]), cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_UserParamHolderFunc_createSeparatorParam_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.UserParamHolder.createSeparatorParam");
        return {};
}

static PyObject* Sbk_Natron_Python_UserParamHolderFunc_createStringParam(PyObject* self, PyObject* args)
{
    ::Natron::Python::UserParamHolder* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::UserParamHolder *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_USERPARAMHOLDER_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "createStringParam", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: UserParamHolder::createStringParam(QString,QString)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))) {
        overloadId = 0; // createStringParam(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_UserParamHolderFunc_createStringParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // createStringParam(QString,QString)
            Natron::Python::StringParam * cppResult = cppSelf->createStringParam(cppArg0, cppArg1);
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STRINGPARAM_IDX]), cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_UserParamHolderFunc_createStringParam_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.UserParamHolder.createStringParam");
        return {};
}

static PyObject* Sbk_Natron_Python_UserParamHolderFunc_refreshUserParamsGUI(PyObject* self)
{
    ::Natron::Python::UserParamHolder* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::UserParamHolder *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_USERPARAMHOLDER_IDX], reinterpret_cast<SbkObject *>(self)));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // refreshUserParamsGUI()
            cppSelf->refreshUserParamsGUI();
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_Natron_Python_UserParamHolderFunc_removeParam(PyObject* self, PyObject* pyArg)
{
    ::Natron::Python::UserParamHolder* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::UserParamHolder *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_USERPARAMHOLDER_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: UserParamHolder::removeParam(Natron::Python::Param*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX]), (pyArg)))) {
        overloadId = 0; // removeParam(Natron::Python::Param*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_UserParamHolderFunc_removeParam_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return {};
        ::Natron::Python::Param* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // removeParam(Natron::Python::Param*)
            bool cppResult = cppSelf->removeParam(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_UserParamHolderFunc_removeParam_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.UserParamHolder.removeParam");
        return {};
}

static PyMethodDef Sbk_Natron_Python_UserParamHolder_methods[] = {
    {"createBooleanParam", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_UserParamHolderFunc_createBooleanParam), METH_VARARGS},
    {"createButtonParam", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_UserParamHolderFunc_createButtonParam), METH_VARARGS},
    {"createChoiceParam", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_UserParamHolderFunc_createChoiceParam), METH_VARARGS},
    {"createColorParam", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_UserParamHolderFunc_createColorParam), METH_VARARGS},
    {"createDouble2DParam", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_UserParamHolderFunc_createDouble2DParam), METH_VARARGS},
    {"createDouble3DParam", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_UserParamHolderFunc_createDouble3DParam), METH_VARARGS},
    {"createDoubleParam", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_UserParamHolderFunc_createDoubleParam), METH_VARARGS},
    {"createFileParam", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_UserParamHolderFunc_createFileParam), METH_VARARGS},
    {"createGroupParam", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_UserParamHolderFunc_createGroupParam), METH_VARARGS},
    {"createInt2DParam", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_UserParamHolderFunc_createInt2DParam), METH_VARARGS},
    {"createInt3DParam", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_UserParamHolderFunc_createInt3DParam), METH_VARARGS},
    {"createIntParam", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_UserParamHolderFunc_createIntParam), METH_VARARGS},
    {"createOutputFileParam", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_UserParamHolderFunc_createOutputFileParam), METH_VARARGS},
    {"createPageParam", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_UserParamHolderFunc_createPageParam), METH_VARARGS},
    {"createParametricParam", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_UserParamHolderFunc_createParametricParam), METH_VARARGS},
    {"createPathParam", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_UserParamHolderFunc_createPathParam), METH_VARARGS},
    {"createSeparatorParam", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_UserParamHolderFunc_createSeparatorParam), METH_VARARGS},
    {"createStringParam", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_UserParamHolderFunc_createStringParam), METH_VARARGS},
    {"refreshUserParamsGUI", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_UserParamHolderFunc_refreshUserParamsGUI), METH_NOARGS},
    {"removeParam", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_UserParamHolderFunc_removeParam), METH_O},

    {nullptr, nullptr} // Sentinel
};

} // extern "C"

static int Sbk_Natron_Python_UserParamHolder_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_Natron_Python_UserParamHolder_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_Natron_Python_UserParamHolder_Type = nullptr;
static SbkObjectType *Sbk_Natron_Python_UserParamHolder_TypeF(void)
{
    return _Sbk_Natron_Python_UserParamHolder_Type;
}

static PyType_Slot Sbk_Natron_Python_UserParamHolder_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_Natron_Python_UserParamHolder_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_Natron_Python_UserParamHolder_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_Natron_Python_UserParamHolder_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        reinterpret_cast<void*>(Sbk_Natron_Python_UserParamHolder_Init)},
    {Py_tp_new,         reinterpret_cast<void*>(SbkObjectTpNew)},
    {0, nullptr}
};
static PyType_Spec Sbk_Natron_Python_UserParamHolder_spec = {
    "NatronEngine.Natron.Python.UserParamHolder",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Natron_Python_UserParamHolder_slots
};

} //extern "C"


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void UserParamHolder_PythonToCpp_UserParamHolder_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_Natron_Python_UserParamHolder_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_UserParamHolder_PythonToCpp_UserParamHolder_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_UserParamHolder_TypeF())))
        return UserParamHolder_PythonToCpp_UserParamHolder_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* UserParamHolder_PTR_CppToPython_UserParamHolder(const void* cppIn) {
    auto pyOut = reinterpret_cast<PyObject*>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::Natron::Python::UserParamHolder *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_Natron_Python_UserParamHolder_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *Natron_Python_UserParamHolder_SignatureStrings[] = {
    "NatronEngine.Natron.Python.UserParamHolder()",
    "NatronEngine.Natron.Python.UserParamHolder.createBooleanParam(name:QString,label:QString)->NatronEngine.Natron.Python.BooleanParam",
    "NatronEngine.Natron.Python.UserParamHolder.createButtonParam(name:QString,label:QString)->NatronEngine.Natron.Python.ButtonParam",
    "NatronEngine.Natron.Python.UserParamHolder.createChoiceParam(name:QString,label:QString)->NatronEngine.Natron.Python.ChoiceParam",
    "NatronEngine.Natron.Python.UserParamHolder.createColorParam(name:QString,label:QString,useAlpha:bool)->NatronEngine.Natron.Python.ColorParam",
    "NatronEngine.Natron.Python.UserParamHolder.createDouble2DParam(name:QString,label:QString)->NatronEngine.Natron.Python.Double2DParam",
    "NatronEngine.Natron.Python.UserParamHolder.createDouble3DParam(name:QString,label:QString)->NatronEngine.Natron.Python.Double3DParam",
    "NatronEngine.Natron.Python.UserParamHolder.createDoubleParam(name:QString,label:QString)->NatronEngine.Natron.Python.DoubleParam",
    "NatronEngine.Natron.Python.UserParamHolder.createFileParam(name:QString,label:QString)->NatronEngine.Natron.Python.FileParam",
    "NatronEngine.Natron.Python.UserParamHolder.createGroupParam(name:QString,label:QString)->NatronEngine.Natron.Python.GroupParam",
    "NatronEngine.Natron.Python.UserParamHolder.createInt2DParam(name:QString,label:QString)->NatronEngine.Natron.Python.Int2DParam",
    "NatronEngine.Natron.Python.UserParamHolder.createInt3DParam(name:QString,label:QString)->NatronEngine.Natron.Python.Int3DParam",
    "NatronEngine.Natron.Python.UserParamHolder.createIntParam(name:QString,label:QString)->NatronEngine.Natron.Python.IntParam",
    "NatronEngine.Natron.Python.UserParamHolder.createOutputFileParam(name:QString,label:QString)->NatronEngine.Natron.Python.FileParam",
    "NatronEngine.Natron.Python.UserParamHolder.createPageParam(name:QString,label:QString)->NatronEngine.Natron.Python.PageParam",
    "NatronEngine.Natron.Python.UserParamHolder.createParametricParam(name:QString,label:QString,nbCurves:int)->NatronEngine.Natron.Python.ParametricParam",
    "NatronEngine.Natron.Python.UserParamHolder.createPathParam(name:QString,label:QString)->NatronEngine.Natron.Python.PathParam",
    "NatronEngine.Natron.Python.UserParamHolder.createSeparatorParam(name:QString,label:QString)->NatronEngine.Natron.Python.SeparatorParam",
    "NatronEngine.Natron.Python.UserParamHolder.createStringParam(name:QString,label:QString)->NatronEngine.Natron.Python.StringParam",
    "NatronEngine.Natron.Python.UserParamHolder.refreshUserParamsGUI()",
    "NatronEngine.Natron.Python.UserParamHolder.removeParam(param:NatronEngine.Natron.Python.Param)->bool",
    nullptr}; // Sentinel

void init_Natron_Python_UserParamHolder(PyObject* module)
{
    _Sbk_Natron_Python_UserParamHolder_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "UserParamHolder",
        "Natron::Python::UserParamHolder*",
        &Sbk_Natron_Python_UserParamHolder_spec,
        Natron_Python_UserParamHolder_SignatureStrings,
        &Shiboken::callCppDestructor< ::Natron::Python::UserParamHolder >,
        0,
        0,
        0    );
    
    SbkNatronEngineTypes[SBK_NATRON_PYTHON_USERPARAMHOLDER_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_UserParamHolder_TypeF());

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_Natron_Python_UserParamHolder_TypeF(),
        UserParamHolder_PythonToCpp_UserParamHolder_PTR,
        is_UserParamHolder_PythonToCpp_UserParamHolder_PTR_Convertible,
        UserParamHolder_PTR_CppToPython_UserParamHolder);

    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::UserParamHolder");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::UserParamHolder*");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::UserParamHolder&");
    Shiboken::Conversions::registerConverterName(converter, "Python::UserParamHolder");
    Shiboken::Conversions::registerConverterName(converter, "Python::UserParamHolder*");
    Shiboken::Conversions::registerConverterName(converter, "Python::UserParamHolder&");
    Shiboken::Conversions::registerConverterName(converter, "UserParamHolder");
    Shiboken::Conversions::registerConverterName(converter, "UserParamHolder*");
    Shiboken::Conversions::registerConverterName(converter, "UserParamHolder&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Natron::Python::UserParamHolder).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::UserParamHolderWrapper).name());



    UserParamHolderWrapper::pysideInitQtMetaTypes();
}
