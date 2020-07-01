
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
#include "natron_python_pycoreapplication_wrapper.h"

// inner classes

// Extra includes
#include <PyAppInstance.h>


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

void PyCoreApplicationWrapper::pysideInitQtMetaTypes()
{
}

PyCoreApplicationWrapper::PyCoreApplicationWrapper() : Natron::Python::PyCoreApplication()
{
    // ... middle
}

PyCoreApplicationWrapper::~PyCoreApplicationWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_Natron_Python_PyCoreApplication_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::Natron::Python::PyCoreApplication >()))
        return -1;

    ::PyCoreApplicationWrapper* cptr{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // PyCoreApplication()
            cptr = new ::PyCoreApplicationWrapper();
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::Natron::Python::PyCoreApplication >(), cptr)) {
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

static PyObject* Sbk_Natron_Python_PyCoreApplicationFunc_appendToNatronPath(PyObject* self, PyObject* pyArg)
{
    ::Natron::Python::PyCoreApplication* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::PyCoreApplication *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYCOREAPPLICATION_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: PyCoreApplication::appendToNatronPath(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // appendToNatronPath(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyCoreApplicationFunc_appendToNatronPath_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // appendToNatronPath(QString)
            cppSelf->appendToNatronPath(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_PyCoreApplicationFunc_appendToNatronPath_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.PyCoreApplication.appendToNatronPath");
        return {};
}

static PyObject* Sbk_Natron_Python_PyCoreApplicationFunc_getActiveInstance(PyObject* self)
{
    ::Natron::Python::PyCoreApplication* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::PyCoreApplication *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYCOREAPPLICATION_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getActiveInstance()const
            Natron::Python::App * cppResult = const_cast<const ::Natron::Python::PyCoreApplication*>(cppSelf)->getActiveInstance();
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_APP_IDX]), cppResult);

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

static PyObject* Sbk_Natron_Python_PyCoreApplicationFunc_getBuildNumber(PyObject* self)
{
    ::Natron::Python::PyCoreApplication* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::PyCoreApplication *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYCOREAPPLICATION_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getBuildNumber()const
            int cppResult = const_cast<const ::Natron::Python::PyCoreApplication*>(cppSelf)->getBuildNumber();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_PyCoreApplicationFunc_getInstance(PyObject* self, PyObject* pyArg)
{
    ::Natron::Python::PyCoreApplication* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::PyCoreApplication *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYCOREAPPLICATION_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: PyCoreApplication::getInstance(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // getInstance(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyCoreApplicationFunc_getInstance_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getInstance(int)const
            Natron::Python::App * cppResult = const_cast<const ::Natron::Python::PyCoreApplication*>(cppSelf)->getInstance(cppArg0);
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_APP_IDX]), cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_PyCoreApplicationFunc_getInstance_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.PyCoreApplication.getInstance");
        return {};
}

static PyObject* Sbk_Natron_Python_PyCoreApplicationFunc_getNatronDevelopmentStatus(PyObject* self)
{
    ::Natron::Python::PyCoreApplication* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::PyCoreApplication *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYCOREAPPLICATION_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getNatronDevelopmentStatus()const
            QString cppResult = const_cast<const ::Natron::Python::PyCoreApplication*>(cppSelf)->getNatronDevelopmentStatus();
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_PyCoreApplicationFunc_getNatronPath(PyObject* self)
{
    ::Natron::Python::PyCoreApplication* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::PyCoreApplication *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYCOREAPPLICATION_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getNatronPath()const
            QStringList cppResult = const_cast<const ::Natron::Python::PyCoreApplication*>(cppSelf)->getNatronPath();
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_PyCoreApplicationFunc_getNatronVersionEncoded(PyObject* self)
{
    ::Natron::Python::PyCoreApplication* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::PyCoreApplication *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYCOREAPPLICATION_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getNatronVersionEncoded()const
            int cppResult = const_cast<const ::Natron::Python::PyCoreApplication*>(cppSelf)->getNatronVersionEncoded();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_PyCoreApplicationFunc_getNatronVersionMajor(PyObject* self)
{
    ::Natron::Python::PyCoreApplication* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::PyCoreApplication *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYCOREAPPLICATION_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getNatronVersionMajor()const
            int cppResult = const_cast<const ::Natron::Python::PyCoreApplication*>(cppSelf)->getNatronVersionMajor();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_PyCoreApplicationFunc_getNatronVersionMinor(PyObject* self)
{
    ::Natron::Python::PyCoreApplication* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::PyCoreApplication *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYCOREAPPLICATION_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getNatronVersionMinor()const
            int cppResult = const_cast<const ::Natron::Python::PyCoreApplication*>(cppSelf)->getNatronVersionMinor();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_PyCoreApplicationFunc_getNatronVersionRevision(PyObject* self)
{
    ::Natron::Python::PyCoreApplication* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::PyCoreApplication *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYCOREAPPLICATION_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getNatronVersionRevision()const
            int cppResult = const_cast<const ::Natron::Python::PyCoreApplication*>(cppSelf)->getNatronVersionRevision();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_PyCoreApplicationFunc_getNatronVersionString(PyObject* self)
{
    ::Natron::Python::PyCoreApplication* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::PyCoreApplication *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYCOREAPPLICATION_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getNatronVersionString()const
            QString cppResult = const_cast<const ::Natron::Python::PyCoreApplication*>(cppSelf)->getNatronVersionString();
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_PyCoreApplicationFunc_getNumCpus(PyObject* self)
{
    ::Natron::Python::PyCoreApplication* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::PyCoreApplication *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYCOREAPPLICATION_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getNumCpus()const
            int cppResult = const_cast<const ::Natron::Python::PyCoreApplication*>(cppSelf)->getNumCpus();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_PyCoreApplicationFunc_getNumInstances(PyObject* self)
{
    ::Natron::Python::PyCoreApplication* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::PyCoreApplication *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYCOREAPPLICATION_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getNumInstances()const
            int cppResult = const_cast<const ::Natron::Python::PyCoreApplication*>(cppSelf)->getNumInstances();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_PyCoreApplicationFunc_getPluginIDs(PyObject* self, PyObject* args)
{
    ::Natron::Python::PyCoreApplication* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::PyCoreApplication *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYCOREAPPLICATION_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "getPluginIDs", 0, 1, &(pyArgs[0])))
        return {};


    // Overloaded function decisor
    // 0: PyCoreApplication::getPluginIDs()const
    // 1: PyCoreApplication::getPluginIDs(QString)const
    if (numArgs == 0) {
        overloadId = 0; // getPluginIDs()const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        overloadId = 1; // getPluginIDs(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyCoreApplicationFunc_getPluginIDs_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // getPluginIDs() const
        {

            if (!PyErr_Occurred()) {
                // getPluginIDs()const
                QStringList cppResult = const_cast<const ::Natron::Python::PyCoreApplication*>(cppSelf)->getPluginIDs();
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
            }
            break;
        }
        case 1: // getPluginIDs(const QString & filter) const
        {
            ::QString cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // getPluginIDs(QString)const
                QStringList cppResult = const_cast<const ::Natron::Python::PyCoreApplication*>(cppSelf)->getPluginIDs(cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRINGLIST_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_PyCoreApplicationFunc_getPluginIDs_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.PyCoreApplication.getPluginIDs");
        return {};
}

static PyObject* Sbk_Natron_Python_PyCoreApplicationFunc_getSettings(PyObject* self)
{
    ::Natron::Python::PyCoreApplication* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::PyCoreApplication *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYCOREAPPLICATION_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getSettings()const
            Natron::Python::AppSettings * cppResult = const_cast<const ::Natron::Python::PyCoreApplication*>(cppSelf)->getSettings();
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_APPSETTINGS_IDX]), cppResult);

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

static PyObject* Sbk_Natron_Python_PyCoreApplicationFunc_is64Bit(PyObject* self)
{
    ::Natron::Python::PyCoreApplication* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::PyCoreApplication *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYCOREAPPLICATION_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // is64Bit()const
            bool cppResult = const_cast<const ::Natron::Python::PyCoreApplication*>(cppSelf)->is64Bit();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_PyCoreApplicationFunc_isBackground(PyObject* self)
{
    ::Natron::Python::PyCoreApplication* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::PyCoreApplication *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYCOREAPPLICATION_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isBackground()const
            bool cppResult = const_cast<const ::Natron::Python::PyCoreApplication*>(cppSelf)->isBackground();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_PyCoreApplicationFunc_isLinux(PyObject* self)
{
    ::Natron::Python::PyCoreApplication* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::PyCoreApplication *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYCOREAPPLICATION_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isLinux()const
            bool cppResult = const_cast<const ::Natron::Python::PyCoreApplication*>(cppSelf)->isLinux();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_PyCoreApplicationFunc_isMacOSX(PyObject* self)
{
    ::Natron::Python::PyCoreApplication* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::PyCoreApplication *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYCOREAPPLICATION_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isMacOSX()const
            bool cppResult = const_cast<const ::Natron::Python::PyCoreApplication*>(cppSelf)->isMacOSX();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_PyCoreApplicationFunc_isUnix(PyObject* self)
{
    ::Natron::Python::PyCoreApplication* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::PyCoreApplication *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYCOREAPPLICATION_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isUnix()const
            bool cppResult = const_cast<const ::Natron::Python::PyCoreApplication*>(cppSelf)->isUnix();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_PyCoreApplicationFunc_isWindows(PyObject* self)
{
    ::Natron::Python::PyCoreApplication* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::PyCoreApplication *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYCOREAPPLICATION_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isWindows()const
            bool cppResult = const_cast<const ::Natron::Python::PyCoreApplication*>(cppSelf)->isWindows();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_PyCoreApplicationFunc_setOnProjectCreatedCallback(PyObject* self, PyObject* pyArg)
{
    ::Natron::Python::PyCoreApplication* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::PyCoreApplication *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYCOREAPPLICATION_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: PyCoreApplication::setOnProjectCreatedCallback(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setOnProjectCreatedCallback(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyCoreApplicationFunc_setOnProjectCreatedCallback_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setOnProjectCreatedCallback(QString)
            cppSelf->setOnProjectCreatedCallback(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_PyCoreApplicationFunc_setOnProjectCreatedCallback_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.PyCoreApplication.setOnProjectCreatedCallback");
        return {};
}

static PyObject* Sbk_Natron_Python_PyCoreApplicationFunc_setOnProjectLoadedCallback(PyObject* self, PyObject* pyArg)
{
    ::Natron::Python::PyCoreApplication* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::PyCoreApplication *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYCOREAPPLICATION_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: PyCoreApplication::setOnProjectLoadedCallback(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setOnProjectLoadedCallback(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyCoreApplicationFunc_setOnProjectLoadedCallback_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setOnProjectLoadedCallback(QString)
            cppSelf->setOnProjectLoadedCallback(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_PyCoreApplicationFunc_setOnProjectLoadedCallback_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.PyCoreApplication.setOnProjectLoadedCallback");
        return {};
}

static PyMethodDef Sbk_Natron_Python_PyCoreApplication_methods[] = {
    {"appendToNatronPath", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyCoreApplicationFunc_appendToNatronPath), METH_O},
    {"getActiveInstance", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyCoreApplicationFunc_getActiveInstance), METH_NOARGS},
    {"getBuildNumber", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyCoreApplicationFunc_getBuildNumber), METH_NOARGS},
    {"getInstance", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyCoreApplicationFunc_getInstance), METH_O},
    {"getNatronDevelopmentStatus", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyCoreApplicationFunc_getNatronDevelopmentStatus), METH_NOARGS},
    {"getNatronPath", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyCoreApplicationFunc_getNatronPath), METH_NOARGS},
    {"getNatronVersionEncoded", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyCoreApplicationFunc_getNatronVersionEncoded), METH_NOARGS},
    {"getNatronVersionMajor", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyCoreApplicationFunc_getNatronVersionMajor), METH_NOARGS},
    {"getNatronVersionMinor", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyCoreApplicationFunc_getNatronVersionMinor), METH_NOARGS},
    {"getNatronVersionRevision", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyCoreApplicationFunc_getNatronVersionRevision), METH_NOARGS},
    {"getNatronVersionString", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyCoreApplicationFunc_getNatronVersionString), METH_NOARGS},
    {"getNumCpus", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyCoreApplicationFunc_getNumCpus), METH_NOARGS},
    {"getNumInstances", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyCoreApplicationFunc_getNumInstances), METH_NOARGS},
    {"getPluginIDs", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyCoreApplicationFunc_getPluginIDs), METH_VARARGS},
    {"getSettings", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyCoreApplicationFunc_getSettings), METH_NOARGS},
    {"is64Bit", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyCoreApplicationFunc_is64Bit), METH_NOARGS},
    {"isBackground", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyCoreApplicationFunc_isBackground), METH_NOARGS},
    {"isLinux", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyCoreApplicationFunc_isLinux), METH_NOARGS},
    {"isMacOSX", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyCoreApplicationFunc_isMacOSX), METH_NOARGS},
    {"isUnix", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyCoreApplicationFunc_isUnix), METH_NOARGS},
    {"isWindows", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyCoreApplicationFunc_isWindows), METH_NOARGS},
    {"setOnProjectCreatedCallback", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyCoreApplicationFunc_setOnProjectCreatedCallback), METH_O},
    {"setOnProjectLoadedCallback", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyCoreApplicationFunc_setOnProjectLoadedCallback), METH_O},

    {nullptr, nullptr} // Sentinel
};

} // extern "C"

static int Sbk_Natron_Python_PyCoreApplication_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_Natron_Python_PyCoreApplication_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_Natron_Python_PyCoreApplication_Type = nullptr;
static SbkObjectType *Sbk_Natron_Python_PyCoreApplication_TypeF(void)
{
    return _Sbk_Natron_Python_PyCoreApplication_Type;
}

static PyType_Slot Sbk_Natron_Python_PyCoreApplication_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_Natron_Python_PyCoreApplication_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_Natron_Python_PyCoreApplication_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_Natron_Python_PyCoreApplication_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        reinterpret_cast<void*>(Sbk_Natron_Python_PyCoreApplication_Init)},
    {Py_tp_new,         reinterpret_cast<void*>(SbkObjectTpNew)},
    {0, nullptr}
};
static PyType_Spec Sbk_Natron_Python_PyCoreApplication_spec = {
    "NatronEngine.Natron.Python.PyCoreApplication",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Natron_Python_PyCoreApplication_slots
};

} //extern "C"


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void PyCoreApplication_PythonToCpp_PyCoreApplication_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_Natron_Python_PyCoreApplication_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_PyCoreApplication_PythonToCpp_PyCoreApplication_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_PyCoreApplication_TypeF())))
        return PyCoreApplication_PythonToCpp_PyCoreApplication_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* PyCoreApplication_PTR_CppToPython_PyCoreApplication(const void* cppIn) {
    auto pyOut = reinterpret_cast<PyObject*>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::Natron::Python::PyCoreApplication *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_Natron_Python_PyCoreApplication_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *Natron_Python_PyCoreApplication_SignatureStrings[] = {
    "NatronEngine.Natron.Python.PyCoreApplication()",
    "NatronEngine.Natron.Python.PyCoreApplication.appendToNatronPath(path:QString)",
    "NatronEngine.Natron.Python.PyCoreApplication.getActiveInstance()->NatronEngine.Natron.Python.App",
    "NatronEngine.Natron.Python.PyCoreApplication.getBuildNumber()->int",
    "NatronEngine.Natron.Python.PyCoreApplication.getInstance(idx:int)->NatronEngine.Natron.Python.App",
    "NatronEngine.Natron.Python.PyCoreApplication.getNatronDevelopmentStatus()->QString",
    "NatronEngine.Natron.Python.PyCoreApplication.getNatronPath()->QStringList",
    "NatronEngine.Natron.Python.PyCoreApplication.getNatronVersionEncoded()->int",
    "NatronEngine.Natron.Python.PyCoreApplication.getNatronVersionMajor()->int",
    "NatronEngine.Natron.Python.PyCoreApplication.getNatronVersionMinor()->int",
    "NatronEngine.Natron.Python.PyCoreApplication.getNatronVersionRevision()->int",
    "NatronEngine.Natron.Python.PyCoreApplication.getNatronVersionString()->QString",
    "NatronEngine.Natron.Python.PyCoreApplication.getNumCpus()->int",
    "NatronEngine.Natron.Python.PyCoreApplication.getNumInstances()->int",
    "1:NatronEngine.Natron.Python.PyCoreApplication.getPluginIDs()->QStringList",
    "0:NatronEngine.Natron.Python.PyCoreApplication.getPluginIDs(filter:QString)->QStringList",
    "NatronEngine.Natron.Python.PyCoreApplication.getSettings()->NatronEngine.Natron.Python.AppSettings",
    "NatronEngine.Natron.Python.PyCoreApplication.is64Bit()->bool",
    "NatronEngine.Natron.Python.PyCoreApplication.isBackground()->bool",
    "NatronEngine.Natron.Python.PyCoreApplication.isLinux()->bool",
    "NatronEngine.Natron.Python.PyCoreApplication.isMacOSX()->bool",
    "NatronEngine.Natron.Python.PyCoreApplication.isUnix()->bool",
    "NatronEngine.Natron.Python.PyCoreApplication.isWindows()->bool",
    "NatronEngine.Natron.Python.PyCoreApplication.setOnProjectCreatedCallback(pythonFunctionName:QString)",
    "NatronEngine.Natron.Python.PyCoreApplication.setOnProjectLoadedCallback(pythonFunctionName:QString)",
    nullptr}; // Sentinel

void init_Natron_Python_PyCoreApplication(PyObject* module)
{
    _Sbk_Natron_Python_PyCoreApplication_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "PyCoreApplication",
        "Natron::Python::PyCoreApplication*",
        &Sbk_Natron_Python_PyCoreApplication_spec,
        Natron_Python_PyCoreApplication_SignatureStrings,
        &Shiboken::callCppDestructor< ::Natron::Python::PyCoreApplication >,
        0,
        0,
        0    );
    
    SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYCOREAPPLICATION_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_PyCoreApplication_TypeF());

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_Natron_Python_PyCoreApplication_TypeF(),
        PyCoreApplication_PythonToCpp_PyCoreApplication_PTR,
        is_PyCoreApplication_PythonToCpp_PyCoreApplication_PTR_Convertible,
        PyCoreApplication_PTR_CppToPython_PyCoreApplication);

    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::PyCoreApplication");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::PyCoreApplication*");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::PyCoreApplication&");
    Shiboken::Conversions::registerConverterName(converter, "Python::PyCoreApplication");
    Shiboken::Conversions::registerConverterName(converter, "Python::PyCoreApplication*");
    Shiboken::Conversions::registerConverterName(converter, "Python::PyCoreApplication&");
    Shiboken::Conversions::registerConverterName(converter, "PyCoreApplication");
    Shiboken::Conversions::registerConverterName(converter, "PyCoreApplication*");
    Shiboken::Conversions::registerConverterName(converter, "PyCoreApplication&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Natron::Python::PyCoreApplication).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::PyCoreApplicationWrapper).name());



    PyCoreApplicationWrapper::pysideInitQtMetaTypes();
}
