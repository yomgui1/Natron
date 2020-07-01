
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
#include "natron_python_app_wrapper.h"

// inner classes

// Extra includes
#include <PyAppInstance.h>
#include <PyNode.h>
#include <PyNodeGroup.h>
#include <PyParameter.h>
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

void AppWrapper::pysideInitQtMetaTypes()
{
}

AppWrapper::~AppWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_Natron_Python_AppFunc_addFormat(PyObject* self, PyObject* pyArg)
{
    AppWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<AppWrapper *>(reinterpret_cast< ::Natron::Python::App *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_APP_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: App::addFormat(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // addFormat(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_AppFunc_addFormat_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // addFormat(QString)
            cppSelf->addFormat(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_AppFunc_addFormat_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.App.addFormat");
        return {};
}

static PyObject* Sbk_Natron_Python_AppFunc_addProjectLayer(PyObject* self, PyObject* pyArg)
{
    AppWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<AppWrapper *>(reinterpret_cast< ::Natron::Python::App *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_APP_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: App::addProjectLayer(Natron::Python::ImageLayer)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_IMAGELAYER_IDX]), (pyArg)))) {
        overloadId = 0; // addProjectLayer(Natron::Python::ImageLayer)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_AppFunc_addProjectLayer_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return {};
        ::Natron::Python::ImageLayer cppArg0_local = ::Natron::Python::ImageLayer(::QString(), ::QString(), ::QStringList());
        ::Natron::Python::ImageLayer* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_IMAGELAYER_IDX]), pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // addProjectLayer(Natron::Python::ImageLayer)
            cppSelf->addProjectLayer(*cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_AppFunc_addProjectLayer_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.App.addProjectLayer");
        return {};
}

static PyObject* Sbk_Natron_Python_AppFunc_closeProject(PyObject* self)
{
    AppWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<AppWrapper *>(reinterpret_cast< ::Natron::Python::App *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_APP_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // closeProject()
            bool cppResult = cppSelf->closeProject();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_AppFunc_createNode(PyObject* self, PyObject* args, PyObject* kwds)
{
    AppWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<AppWrapper *>(reinterpret_cast< ::Natron::Python::App *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_APP_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.App.createNode(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.App.createNode(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OOOO:createNode", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return {};


    // Overloaded function decisor
    // 0: App::createNode(QString,int,Natron::Python::Group*,std::map<QString,Natron::Python::NodeCreationProperty*>)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // createNode(QString,int,Natron::Python::Group*,std::map<QString,Natron::Python::NodeCreationProperty*>)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // createNode(QString,int,Natron::Python::Group*,std::map<QString,Natron::Python::NodeCreationProperty*>)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_GROUP_IDX]), (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 0; // createNode(QString,int,Natron::Python::Group*,std::map<QString,Natron::Python::NodeCreationProperty*>)const
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_MAP_QSTRING_NATRON_PYTHON_NODECREATIONPROPERTYPTR_IDX], (pyArgs[3])))) {
                    overloadId = 0; // createNode(QString,int,Natron::Python::Group*,std::map<QString,Natron::Python::NodeCreationProperty*>)const
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_AppFunc_createNode_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "majorVersion");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.App.createNode(): got multiple values for keyword argument 'majorVersion'.");
                return {};
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_Natron_Python_AppFunc_createNode_TypeError;
            }
            value = PyDict_GetItemString(kwds, "group");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.App.createNode(): got multiple values for keyword argument 'group'.");
                return {};
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_GROUP_IDX]), (pyArgs[2]))))
                    goto Sbk_Natron_Python_AppFunc_createNode_TypeError;
            }
            value = PyDict_GetItemString(kwds, "props");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.App.createNode(): got multiple values for keyword argument 'props'.");
                return {};
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_MAP_QSTRING_NATRON_PYTHON_NODECREATIONPROPERTYPTR_IDX], (pyArgs[3]))))
                    goto Sbk_Natron_Python_AppFunc_createNode_TypeError;
            }
        }
        ::QString cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = -1;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        if (!Shiboken::Object::isValid(pyArgs[2]))
            return {};
        ::Natron::Python::Group* cppArg2 = 0;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
        ::std::map<QString,Natron::Python::NodeCreationProperty* > cppArg3;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // createNode(QString,int,Natron::Python::Group*,std::map<QString,Natron::Python::NodeCreationProperty*>)const
            // Begin code injection

            Natron::Python::Effect * cppResult = cppSelf->createNode(cppArg0,cppArg1,cppArg2, cppArg3);
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX]), cppResult);

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

    Sbk_Natron_Python_AppFunc_createNode_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.App.createNode");
        return {};
}

static PyObject* Sbk_Natron_Python_AppFunc_createReader(PyObject* self, PyObject* args, PyObject* kwds)
{
    AppWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<AppWrapper *>(reinterpret_cast< ::Natron::Python::App *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_APP_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.App.createReader(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.App.createReader(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OOO:createReader", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return {};


    // Overloaded function decisor
    // 0: App::createReader(QString,Natron::Python::Group*,std::map<QString,Natron::Python::NodeCreationProperty*>)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // createReader(QString,Natron::Python::Group*,std::map<QString,Natron::Python::NodeCreationProperty*>)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_GROUP_IDX]), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // createReader(QString,Natron::Python::Group*,std::map<QString,Natron::Python::NodeCreationProperty*>)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_MAP_QSTRING_NATRON_PYTHON_NODECREATIONPROPERTYPTR_IDX], (pyArgs[2])))) {
                overloadId = 0; // createReader(QString,Natron::Python::Group*,std::map<QString,Natron::Python::NodeCreationProperty*>)const
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_AppFunc_createReader_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "group");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.App.createReader(): got multiple values for keyword argument 'group'.");
                return {};
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_GROUP_IDX]), (pyArgs[1]))))
                    goto Sbk_Natron_Python_AppFunc_createReader_TypeError;
            }
            value = PyDict_GetItemString(kwds, "props");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.App.createReader(): got multiple values for keyword argument 'props'.");
                return {};
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_MAP_QSTRING_NATRON_PYTHON_NODECREATIONPROPERTYPTR_IDX], (pyArgs[2]))))
                    goto Sbk_Natron_Python_AppFunc_createReader_TypeError;
            }
        }
        ::QString cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return {};
        ::Natron::Python::Group* cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        ::std::map<QString,Natron::Python::NodeCreationProperty* > cppArg2;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // createReader(QString,Natron::Python::Group*,std::map<QString,Natron::Python::NodeCreationProperty*>)const
            // Begin code injection

            Natron::Python::Effect * cppResult = cppSelf->createReader(cppArg0,cppArg1, cppArg2);
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX]), cppResult);

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

    Sbk_Natron_Python_AppFunc_createReader_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.App.createReader");
        return {};
}

static PyObject* Sbk_Natron_Python_AppFunc_createWriter(PyObject* self, PyObject* args, PyObject* kwds)
{
    AppWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<AppWrapper *>(reinterpret_cast< ::Natron::Python::App *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_APP_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.App.createWriter(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.App.createWriter(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OOO:createWriter", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return {};


    // Overloaded function decisor
    // 0: App::createWriter(QString,Natron::Python::Group*,std::map<QString,Natron::Python::NodeCreationProperty*>)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // createWriter(QString,Natron::Python::Group*,std::map<QString,Natron::Python::NodeCreationProperty*>)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_GROUP_IDX]), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // createWriter(QString,Natron::Python::Group*,std::map<QString,Natron::Python::NodeCreationProperty*>)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_MAP_QSTRING_NATRON_PYTHON_NODECREATIONPROPERTYPTR_IDX], (pyArgs[2])))) {
                overloadId = 0; // createWriter(QString,Natron::Python::Group*,std::map<QString,Natron::Python::NodeCreationProperty*>)const
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_AppFunc_createWriter_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "group");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.App.createWriter(): got multiple values for keyword argument 'group'.");
                return {};
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_GROUP_IDX]), (pyArgs[1]))))
                    goto Sbk_Natron_Python_AppFunc_createWriter_TypeError;
            }
            value = PyDict_GetItemString(kwds, "props");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.App.createWriter(): got multiple values for keyword argument 'props'.");
                return {};
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_MAP_QSTRING_NATRON_PYTHON_NODECREATIONPROPERTYPTR_IDX], (pyArgs[2]))))
                    goto Sbk_Natron_Python_AppFunc_createWriter_TypeError;
            }
        }
        ::QString cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return {};
        ::Natron::Python::Group* cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        ::std::map<QString,Natron::Python::NodeCreationProperty* > cppArg2;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // createWriter(QString,Natron::Python::Group*,std::map<QString,Natron::Python::NodeCreationProperty*>)const
            // Begin code injection

            Natron::Python::Effect * cppResult = cppSelf->createWriter(cppArg0,cppArg1, cppArg2);
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX]), cppResult);

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

    Sbk_Natron_Python_AppFunc_createWriter_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.App.createWriter");
        return {};
}

static PyObject* Sbk_Natron_Python_AppFunc_getAppID(PyObject* self)
{
    AppWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<AppWrapper *>(reinterpret_cast< ::Natron::Python::App *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_APP_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getAppID()const
            int cppResult = const_cast<const ::AppWrapper*>(cppSelf)->getAppID();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_AppFunc_getProjectParam(PyObject* self, PyObject* pyArg)
{
    AppWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<AppWrapper *>(reinterpret_cast< ::Natron::Python::App *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_APP_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: App::getProjectParam(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // getProjectParam(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_AppFunc_getProjectParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getProjectParam(QString)const
            Natron::Python::Param * cppResult = const_cast<const ::AppWrapper*>(cppSelf)->getProjectParam(cppArg0);
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

    Sbk_Natron_Python_AppFunc_getProjectParam_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.App.getProjectParam");
        return {};
}

static PyObject* Sbk_Natron_Python_AppFunc_getViewIndex(PyObject* self, PyObject* pyArg)
{
    AppWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<AppWrapper *>(reinterpret_cast< ::Natron::Python::App *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_APP_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: App::getViewIndex(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // getViewIndex(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_AppFunc_getViewIndex_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getViewIndex(QString)const
            int cppResult = const_cast<const ::AppWrapper*>(cppSelf)->getViewIndex(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_AppFunc_getViewIndex_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.App.getViewIndex");
        return {};
}

static PyObject* Sbk_Natron_Python_AppFunc_getViewName(PyObject* self, PyObject* pyArg)
{
    AppWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<AppWrapper *>(reinterpret_cast< ::Natron::Python::App *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_APP_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: App::getViewName(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // getViewName(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_AppFunc_getViewName_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getViewName(int)const
            QString cppResult = const_cast<const ::AppWrapper*>(cppSelf)->getViewName(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_AppFunc_getViewName_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.App.getViewName");
        return {};
}

static PyObject* Sbk_Natron_Python_AppFunc_getViewNames(PyObject* self)
{
    AppWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<AppWrapper *>(reinterpret_cast< ::Natron::Python::App *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_APP_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getViewNames()const
            std::list<QString > cppResult = const_cast<const ::AppWrapper*>(cppSelf)->getViewNames();
            pyResult = Shiboken::Conversions::copyToPython(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_AppFunc_loadProject(PyObject* self, PyObject* pyArg)
{
    AppWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<AppWrapper *>(reinterpret_cast< ::Natron::Python::App *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_APP_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: App::loadProject(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // loadProject(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_AppFunc_loadProject_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // loadProject(QString)
            // Begin code injection

            Natron::Python::App * cppResult = cppSelf->loadProject(cppArg0);
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_APP_IDX]), cppResult);

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

    Sbk_Natron_Python_AppFunc_loadProject_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.App.loadProject");
        return {};
}

static PyObject* Sbk_Natron_Python_AppFunc_newProject(PyObject* self)
{
    AppWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<AppWrapper *>(reinterpret_cast< ::Natron::Python::App *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_APP_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // newProject()
            // Begin code injection

            Natron::Python::App * cppResult = cppSelf->newProject();
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_APP_IDX]), cppResult);

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

static PyObject* Sbk_Natron_Python_AppFunc_redrawViewer(PyObject* self, PyObject* pyArg)
{
    AppWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<AppWrapper *>(reinterpret_cast< ::Natron::Python::App *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_APP_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: App::redrawViewer(Natron::Python::Effect*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX]), (pyArg)))) {
        overloadId = 0; // redrawViewer(Natron::Python::Effect*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_AppFunc_redrawViewer_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return {};
        ::Natron::Python::Effect* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // redrawViewer(Natron::Python::Effect*)
            cppSelf->redrawViewer(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_AppFunc_redrawViewer_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.App.redrawViewer");
        return {};
}

static PyObject* Sbk_Natron_Python_AppFunc_refreshViewer(PyObject* self, PyObject* args, PyObject* kwds)
{
    AppWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<AppWrapper *>(reinterpret_cast< ::Natron::Python::App *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_APP_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.App.refreshViewer(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.App.refreshViewer(): not enough arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|OO:refreshViewer", &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: App::refreshViewer(Natron::Python::Effect*,bool)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX]), (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // refreshViewer(Natron::Python::Effect*,bool)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
            overloadId = 0; // refreshViewer(Natron::Python::Effect*,bool)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_AppFunc_refreshViewer_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "useCache");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.App.refreshViewer(): got multiple values for keyword argument 'useCache'.");
                return {};
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1]))))
                    goto Sbk_Natron_Python_AppFunc_refreshViewer_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return {};
        ::Natron::Python::Effect* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        bool cppArg1 = true;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // refreshViewer(Natron::Python::Effect*,bool)
            cppSelf->refreshViewer(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_AppFunc_refreshViewer_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.App.refreshViewer");
        return {};
}

static PyObject* Sbk_Natron_Python_AppFunc_render(PyObject* self, PyObject* args, PyObject* kwds)
{
    AppWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<AppWrapper *>(reinterpret_cast< ::Natron::Python::App *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_APP_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.App.render(): too many arguments");
        return {};
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.App.render(): not enough arguments");
        return {};
    } else if (numArgs == 2)
        goto Sbk_Natron_Python_AppFunc_render_TypeError;

    if (!PyArg_ParseTuple(args, "|OOOO:render", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return {};


    // Overloaded function decisor
    // 0: App::render(Natron::Python::Effect*,int,int,int)
    // 1: App::render(std::list<Natron::Python::Effect*>,std::list<int>,std::list<int>,std::list<int>)
    if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // render(Natron::Python::Effect*,int,int,int)
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
            overloadId = 0; // render(Natron::Python::Effect*,int,int,int)
        }
    } else if (numArgs == 1
        && PyList_Check(pyArgs[0])) {
        overloadId = 1; // render(std::list<Natron::Python::Effect*>,std::list<int>,std::list<int>,std::list<int>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_AppFunc_render_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // render(Natron::Python::Effect * writeNode, int firstFrame, int lastFrame, int frameStep)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "frameStep");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.Natron.Python.App.render(): got multiple values for keyword argument 'frameStep'.");
                    return {};
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3]))))
                        goto Sbk_Natron_Python_AppFunc_render_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return {};
            ::Natron::Python::Effect* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3 = 1;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // render(Natron::Python::Effect*,int,int,int)
                cppSelf->render(cppArg0, cppArg1, cppArg2, cppArg3);
            }
            break;
        }
        case 1: // render(const std::list<Natron::Python::Effect* > & effects, const std::list<int > & firstFrames, const std::list<int > & lastFrames, const std::list<int > & frameSteps)
        {

            if (!PyErr_Occurred()) {
                // render(std::list<Natron::Python::Effect*>,std::list<int>,std::list<int>,std::list<int>)
                // Begin code injection

                if (!PyList_Check(pyArgs[1-1])) {
                    PyErr_SetString(PyExc_TypeError, "tasks must be a list of tuple objects.");
                    return 0;
                }
                std::list<Natron::Python::Effect*> effects;

                std::list<int> firstFrames;

                std::list<int> lastFrames;

                std::list<int> frameSteps;

                int size = (int)PyList_GET_SIZE(pyArgs[1-1]);
                for (int i = 0; i < size; ++i) {
                    PyObject* tuple = PyList_GET_ITEM(pyArgs[1-1],i);
                    if (!tuple) {
                        PyErr_SetString(PyExc_TypeError, "tasks must be a list of tuple objects.");
                        return 0;
                    }

                    int tupleSize = PyTuple_GET_SIZE(tuple);
                    if (tupleSize != 4 && tupleSize != 3) {
                        PyErr_SetString(PyExc_TypeError, "the tuple must have 3 or 4 items.");
                        return 0;
                    }
                    ::Natron::Python::Effect* writeNode{nullptr};
                    Shiboken::Conversions::pythonToCppPointer(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX]), PyTuple_GET_ITEM(tuple, 0), &(writeNode));
                    int firstFrame;
                    Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<int>(), PyTuple_GET_ITEM(tuple, 1), &(firstFrame));
                    int lastFrame;
                    Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<int>(), PyTuple_GET_ITEM(tuple, 2), &(lastFrame));
                    int frameStep;
                    if (tupleSize == 4) {
                        Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<int>(), PyTuple_GET_ITEM(tuple, 3), &(frameStep));
                    } else {
                        frameStep = INT_MIN;
                    }
                    effects.push_back(writeNode);
                    firstFrames.push_back(firstFrame);
                    lastFrames.push_back(lastFrame);
                    frameSteps.push_back(frameStep);
                }

                cppSelf->render(effects,firstFrames,lastFrames, frameSteps);

                // End of code injection


            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_AppFunc_render_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.App.render");
        return {};
}

static PyObject* Sbk_Natron_Python_AppFunc_resetProject(PyObject* self)
{
    AppWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<AppWrapper *>(reinterpret_cast< ::Natron::Python::App *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_APP_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // resetProject()
            bool cppResult = cppSelf->resetProject();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_AppFunc_saveProject(PyObject* self, PyObject* pyArg)
{
    AppWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<AppWrapper *>(reinterpret_cast< ::Natron::Python::App *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_APP_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: App::saveProject(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // saveProject(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_AppFunc_saveProject_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // saveProject(QString)
            bool cppResult = cppSelf->saveProject(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_AppFunc_saveProject_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.App.saveProject");
        return {};
}

static PyObject* Sbk_Natron_Python_AppFunc_saveProjectAs(PyObject* self, PyObject* pyArg)
{
    AppWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<AppWrapper *>(reinterpret_cast< ::Natron::Python::App *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_APP_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: App::saveProjectAs(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // saveProjectAs(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_AppFunc_saveProjectAs_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // saveProjectAs(QString)
            bool cppResult = cppSelf->saveProjectAs(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_AppFunc_saveProjectAs_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.App.saveProjectAs");
        return {};
}

static PyObject* Sbk_Natron_Python_AppFunc_saveTempProject(PyObject* self, PyObject* pyArg)
{
    AppWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<AppWrapper *>(reinterpret_cast< ::Natron::Python::App *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_APP_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: App::saveTempProject(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // saveTempProject(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_AppFunc_saveTempProject_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // saveTempProject(QString)
            bool cppResult = cppSelf->saveTempProject(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_AppFunc_saveTempProject_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.App.saveTempProject");
        return {};
}

static PyObject* Sbk_Natron_Python_AppFunc_timelineGetLeftBound(PyObject* self)
{
    AppWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<AppWrapper *>(reinterpret_cast< ::Natron::Python::App *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_APP_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // timelineGetLeftBound()const
            int cppResult = const_cast<const ::AppWrapper*>(cppSelf)->timelineGetLeftBound();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_AppFunc_timelineGetRightBound(PyObject* self)
{
    AppWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<AppWrapper *>(reinterpret_cast< ::Natron::Python::App *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_APP_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // timelineGetRightBound()const
            int cppResult = const_cast<const ::AppWrapper*>(cppSelf)->timelineGetRightBound();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_AppFunc_timelineGetTime(PyObject* self)
{
    AppWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<AppWrapper *>(reinterpret_cast< ::Natron::Python::App *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_APP_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // timelineGetTime()const
            int cppResult = const_cast<const ::AppWrapper*>(cppSelf)->timelineGetTime();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_AppFunc_timelineGoTo(PyObject* self, PyObject* pyArg)
{
    AppWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<AppWrapper *>(reinterpret_cast< ::Natron::Python::App *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_APP_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: App::timelineGoTo(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // timelineGoTo(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_AppFunc_timelineGoTo_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // timelineGoTo(int)
            cppSelf->timelineGoTo(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_AppFunc_timelineGoTo_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.App.timelineGoTo");
        return {};
}

static PyObject* Sbk_Natron_Python_AppFunc_writeToScriptEditor(PyObject* self, PyObject* pyArg)
{
    AppWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<AppWrapper *>(reinterpret_cast< ::Natron::Python::App *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_APP_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: App::writeToScriptEditor(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // writeToScriptEditor(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_AppFunc_writeToScriptEditor_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // writeToScriptEditor(QString)
            cppSelf->writeToScriptEditor(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_AppFunc_writeToScriptEditor_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.App.writeToScriptEditor");
        return {};
}

static PyMethodDef Sbk_Natron_Python_App_methods[] = {
    {"addFormat", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_AppFunc_addFormat), METH_O},
    {"addProjectLayer", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_AppFunc_addProjectLayer), METH_O},
    {"closeProject", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_AppFunc_closeProject), METH_NOARGS},
    {"createNode", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_AppFunc_createNode), METH_VARARGS|METH_KEYWORDS},
    {"createReader", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_AppFunc_createReader), METH_VARARGS|METH_KEYWORDS},
    {"createWriter", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_AppFunc_createWriter), METH_VARARGS|METH_KEYWORDS},
    {"getAppID", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_AppFunc_getAppID), METH_NOARGS},
    {"getProjectParam", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_AppFunc_getProjectParam), METH_O},
    {"getViewIndex", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_AppFunc_getViewIndex), METH_O},
    {"getViewName", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_AppFunc_getViewName), METH_O},
    {"getViewNames", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_AppFunc_getViewNames), METH_NOARGS},
    {"loadProject", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_AppFunc_loadProject), METH_O},
    {"newProject", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_AppFunc_newProject), METH_NOARGS},
    {"redrawViewer", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_AppFunc_redrawViewer), METH_O},
    {"refreshViewer", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_AppFunc_refreshViewer), METH_VARARGS|METH_KEYWORDS},
    {"render", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_AppFunc_render), METH_VARARGS|METH_KEYWORDS},
    {"resetProject", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_AppFunc_resetProject), METH_NOARGS},
    {"saveProject", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_AppFunc_saveProject), METH_O},
    {"saveProjectAs", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_AppFunc_saveProjectAs), METH_O},
    {"saveTempProject", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_AppFunc_saveTempProject), METH_O},
    {"timelineGetLeftBound", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_AppFunc_timelineGetLeftBound), METH_NOARGS},
    {"timelineGetRightBound", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_AppFunc_timelineGetRightBound), METH_NOARGS},
    {"timelineGetTime", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_AppFunc_timelineGetTime), METH_NOARGS},
    {"timelineGoTo", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_AppFunc_timelineGoTo), METH_O},
    {"writeToScriptEditor", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_AppFunc_writeToScriptEditor), METH_O},

    {nullptr, nullptr} // Sentinel
};

} // extern "C"

static int Sbk_Natron_Python_App_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_Natron_Python_App_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_Natron_Python_App_Type = nullptr;
static SbkObjectType *Sbk_Natron_Python_App_TypeF(void)
{
    return _Sbk_Natron_Python_App_Type;
}

static PyType_Slot Sbk_Natron_Python_App_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_Natron_Python_App_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_Natron_Python_App_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_Natron_Python_App_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        nullptr},
    {Py_tp_new,         reinterpret_cast<void*>(SbkDummyNew /* PYSIDE-595: Prevent replacement of "0" with base->tp_new. */)},
    {0, nullptr}
};
static PyType_Spec Sbk_Natron_Python_App_spec = {
    "NatronEngine.Natron.Python.App",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Natron_Python_App_slots
};

} //extern "C"

static void* Sbk_Natron_Python_App_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::Natron::Python::Group >()))
        return dynamic_cast< ::Natron::Python::App*>(reinterpret_cast< ::Natron::Python::Group*>(cptr));
    return {};
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void App_PythonToCpp_App_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_Natron_Python_App_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_App_PythonToCpp_App_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_App_TypeF())))
        return App_PythonToCpp_App_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* App_PTR_CppToPython_App(const void* cppIn) {
    auto pyOut = reinterpret_cast<PyObject*>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::Natron::Python::App *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_Natron_Python_App_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *Natron_Python_App_SignatureStrings[] = {
    "NatronEngine.Natron.Python.App.addFormat(formatSpec:QString)",
    "NatronEngine.Natron.Python.App.addProjectLayer(layer:NatronEngine.Natron.Python.ImageLayer)",
    "NatronEngine.Natron.Python.App.closeProject()->bool",
    "NatronEngine.Natron.Python.App.createNode(pluginID:QString,majorVersion:int=-1,group:NatronEngine.Natron.Python.Group=0,props:QMap=NodeCreationPropertyMap())->NatronEngine.Natron.Python.Effect",
    "NatronEngine.Natron.Python.App.createReader(filename:QString,group:NatronEngine.Natron.Python.Group=0,props:QMap=NodeCreationPropertyMap())->NatronEngine.Natron.Python.Effect",
    "NatronEngine.Natron.Python.App.createWriter(filename:QString,group:NatronEngine.Natron.Python.Group=0,props:QMap=NodeCreationPropertyMap())->NatronEngine.Natron.Python.Effect",
    "NatronEngine.Natron.Python.App.getAppID()->int",
    "NatronEngine.Natron.Python.App.getProjectParam(name:QString)->NatronEngine.Natron.Python.Param",
    "NatronEngine.Natron.Python.App.getViewIndex(viewName:QString)->int",
    "NatronEngine.Natron.Python.App.getViewName(viewIndex:int)->QString",
    "NatronEngine.Natron.Python.App.getViewNames()->QList[QString]",
    "NatronEngine.Natron.Python.App.loadProject(filename:QString)->NatronEngine.Natron.Python.App",
    "NatronEngine.Natron.Python.App.newProject()->NatronEngine.Natron.Python.App",
    "NatronEngine.Natron.Python.App.redrawViewer(viewerNode:NatronEngine.Natron.Python.Effect)",
    "NatronEngine.Natron.Python.App.refreshViewer(viewerNode:NatronEngine.Natron.Python.Effect,useCache:bool=true)",
    "1:NatronEngine.Natron.Python.App.render(writeNode:NatronEngine.Natron.Python.Effect,firstFrame:int,lastFrame:int,frameStep:int=1)",
    "0:NatronEngine.Natron.Python.App.render(effects:QList[NatronEngine.Natron.Python.Effect],firstFrames:QList[int],lastFrames:QList[int],frameSteps:QList[int])",
    "NatronEngine.Natron.Python.App.resetProject()->bool",
    "NatronEngine.Natron.Python.App.saveProject(filename:QString)->bool",
    "NatronEngine.Natron.Python.App.saveProjectAs(filename:QString)->bool",
    "NatronEngine.Natron.Python.App.saveTempProject(filename:QString)->bool",
    "NatronEngine.Natron.Python.App.timelineGetLeftBound()->int",
    "NatronEngine.Natron.Python.App.timelineGetRightBound()->int",
    "NatronEngine.Natron.Python.App.timelineGetTime()->int",
    "NatronEngine.Natron.Python.App.timelineGoTo(frame:int)",
    "NatronEngine.Natron.Python.App.writeToScriptEditor(message:QString)",
    nullptr}; // Sentinel

void init_Natron_Python_App(PyObject* module)
{
    _Sbk_Natron_Python_App_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "App",
        "Natron::Python::App*",
        &Sbk_Natron_Python_App_spec,
        Natron_Python_App_SignatureStrings,
        &Shiboken::callCppDestructor< ::Natron::Python::App >,
        reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_GROUP_IDX]),
        0,
        0    );
    
    SbkNatronEngineTypes[SBK_NATRON_PYTHON_APP_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_App_TypeF());

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_Natron_Python_App_TypeF(),
        App_PythonToCpp_App_PTR,
        is_App_PythonToCpp_App_PTR_Convertible,
        App_PTR_CppToPython_App);

    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::App");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::App*");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::App&");
    Shiboken::Conversions::registerConverterName(converter, "Python::App");
    Shiboken::Conversions::registerConverterName(converter, "Python::App*");
    Shiboken::Conversions::registerConverterName(converter, "Python::App&");
    Shiboken::Conversions::registerConverterName(converter, "App");
    Shiboken::Conversions::registerConverterName(converter, "App*");
    Shiboken::Conversions::registerConverterName(converter, "App&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Natron::Python::App).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::AppWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_Natron_Python_App_TypeF(), &Sbk_Natron_Python_App_typeDiscovery);


    AppWrapper::pysideInitQtMetaTypes();
}
