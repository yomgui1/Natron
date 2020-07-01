
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

#include "app_wrapper.h"

// Extra includes
NATRON_NAMESPACE_USING NATRON_PYTHON_NAMESPACE_USING
#include <PyAppInstance.h>
#include <PyNode.h>
#include <PyNodeGroup.h>
#include <PyParameter.h>
#include <list>
#include <map>


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
static PyObject* Sbk_AppFunc_addFormat(PyObject* self, PyObject* pyArg)
{
    AppWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (AppWrapper*)((::App*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_APP_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: addFormat(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // addFormat(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_AppFunc_addFormat_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // addFormat(QString)
            cppSelf->addFormat(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_AppFunc_addFormat_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.App.addFormat", overloads);
        return 0;
}

static PyObject* Sbk_AppFunc_addProjectLayer(PyObject* self, PyObject* pyArg)
{
    AppWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (AppWrapper*)((::App*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_APP_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: addProjectLayer(ImageLayer)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppReferenceConvertible((SbkObjectType*)SbkNatronEngineTypes[SBK_IMAGELAYER_IDX], (pyArg)))) {
        overloadId = 0; // addProjectLayer(ImageLayer)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_AppFunc_addProjectLayer_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::ImageLayer cppArg0_local = ::ImageLayer(::QString(), ::QString(), ::QStringList());
        ::ImageLayer* cppArg0 = &cppArg0_local;
        if (Shiboken::Conversions::isImplicitConversion((SbkObjectType*)SbkNatronEngineTypes[SBK_IMAGELAYER_IDX], pythonToCpp))
            pythonToCpp(pyArg, &cppArg0_local);
        else
            pythonToCpp(pyArg, &cppArg0);


        if (!PyErr_Occurred()) {
            // addProjectLayer(ImageLayer)
            cppSelf->addProjectLayer(*cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_AppFunc_addProjectLayer_TypeError:
        const char* overloads[] = {"NatronEngine.ImageLayer", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.App.addProjectLayer", overloads);
        return 0;
}

static PyObject* Sbk_AppFunc_closeProject(PyObject* self)
{
    AppWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (AppWrapper*)((::App*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_APP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

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
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_AppFunc_createNode(PyObject* self, PyObject* args, PyObject* kwds)
{
    AppWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (AppWrapper*)((::App*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_APP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.App.createNode(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.App.createNode(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOOO:createNode", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: createNode(QString,int,Group*,std::map<QString,NodeCreationProperty*>)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // createNode(QString,int,Group*,std::map<QString,NodeCreationProperty*>)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // createNode(QString,int,Group*,std::map<QString,NodeCreationProperty*>)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkNatronEngineTypes[SBK_GROUP_IDX], (pyArgs[2])))) {
                if (numArgs == 3) {
                    overloadId = 0; // createNode(QString,int,Group*,std::map<QString,NodeCreationProperty*>)const
                } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_MAP_QSTRING_NODECREATIONPROPERTYPTR_IDX], (pyArgs[3])))) {
                    overloadId = 0; // createNode(QString,int,Group*,std::map<QString,NodeCreationProperty*>)const
                }
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_AppFunc_createNode_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "majorVersion");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.App.createNode(): got multiple values for keyword argument 'majorVersion'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1]))))
                    goto Sbk_AppFunc_createNode_TypeError;
            }
            value = PyDict_GetItemString(kwds, "group");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.App.createNode(): got multiple values for keyword argument 'group'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkNatronEngineTypes[SBK_GROUP_IDX], (pyArgs[2]))))
                    goto Sbk_AppFunc_createNode_TypeError;
            }
            value = PyDict_GetItemString(kwds, "props");
            if (value && pyArgs[3]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.App.createNode(): got multiple values for keyword argument 'props'.");
                return 0;
            } else if (value) {
                pyArgs[3] = value;
                if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_MAP_QSTRING_NODECREATIONPROPERTYPTR_IDX], (pyArgs[3]))))
                    goto Sbk_AppFunc_createNode_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1 = -1;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        if (!Shiboken::Object::isValid(pyArgs[2]))
            return 0;
        ::Group* cppArg2 = 0;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);
        ::std::map<QString, NodeCreationProperty * > cppArg3;
        if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

        if (!PyErr_Occurred()) {
            // createNode(QString,int,Group*,std::map<QString,NodeCreationProperty*>)const
            // Begin code injection

            Effect * cppResult = cppSelf->createNode(cppArg0,cppArg1,cppArg2, cppArg3);
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkNatronEngineTypes[SBK_EFFECT_IDX], cppResult);

            // End of code injection



            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_AppFunc_createNode_TypeError:
        const char* overloads[] = {"unicode, int = -1, NatronEngine.Group = None, dict = NodeCreationPropertyMap()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.App.createNode", overloads);
        return 0;
}

static PyObject* Sbk_AppFunc_createReader(PyObject* self, PyObject* args, PyObject* kwds)
{
    AppWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (AppWrapper*)((::App*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_APP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.App.createReader(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.App.createReader(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:createReader", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: createReader(QString,Group*,std::map<QString,NodeCreationProperty*>)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // createReader(QString,Group*,std::map<QString,NodeCreationProperty*>)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkNatronEngineTypes[SBK_GROUP_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // createReader(QString,Group*,std::map<QString,NodeCreationProperty*>)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_MAP_QSTRING_NODECREATIONPROPERTYPTR_IDX], (pyArgs[2])))) {
                overloadId = 0; // createReader(QString,Group*,std::map<QString,NodeCreationProperty*>)const
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_AppFunc_createReader_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "group");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.App.createReader(): got multiple values for keyword argument 'group'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkNatronEngineTypes[SBK_GROUP_IDX], (pyArgs[1]))))
                    goto Sbk_AppFunc_createReader_TypeError;
            }
            value = PyDict_GetItemString(kwds, "props");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.App.createReader(): got multiple values for keyword argument 'props'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_MAP_QSTRING_NODECREATIONPROPERTYPTR_IDX], (pyArgs[2]))))
                    goto Sbk_AppFunc_createReader_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::Group* cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        ::std::map<QString, NodeCreationProperty * > cppArg2;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // createReader(QString,Group*,std::map<QString,NodeCreationProperty*>)const
            // Begin code injection

            Effect * cppResult = cppSelf->createReader(cppArg0,cppArg1, cppArg2);
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkNatronEngineTypes[SBK_EFFECT_IDX], cppResult);

            // End of code injection



            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_AppFunc_createReader_TypeError:
        const char* overloads[] = {"unicode, NatronEngine.Group = None, dict = NodeCreationPropertyMap()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.App.createReader", overloads);
        return 0;
}

static PyObject* Sbk_AppFunc_createWriter(PyObject* self, PyObject* args, PyObject* kwds)
{
    AppWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (AppWrapper*)((::App*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_APP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 3) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.App.createWriter(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.App.createWriter(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OOO:createWriter", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return 0;


    // Overloaded function decisor
    // 0: createWriter(QString,Group*,std::map<QString,NodeCreationProperty*>)const
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // createWriter(QString,Group*,std::map<QString,NodeCreationProperty*>)const
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkNatronEngineTypes[SBK_GROUP_IDX], (pyArgs[1])))) {
            if (numArgs == 2) {
                overloadId = 0; // createWriter(QString,Group*,std::map<QString,NodeCreationProperty*>)const
            } else if ((pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_MAP_QSTRING_NODECREATIONPROPERTYPTR_IDX], (pyArgs[2])))) {
                overloadId = 0; // createWriter(QString,Group*,std::map<QString,NodeCreationProperty*>)const
            }
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_AppFunc_createWriter_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "group");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.App.createWriter(): got multiple values for keyword argument 'group'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkNatronEngineTypes[SBK_GROUP_IDX], (pyArgs[1]))))
                    goto Sbk_AppFunc_createWriter_TypeError;
            }
            value = PyDict_GetItemString(kwds, "props");
            if (value && pyArgs[2]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.App.createWriter(): got multiple values for keyword argument 'props'.");
                return 0;
            } else if (value) {
                pyArgs[2] = value;
                if (!(pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_MAP_QSTRING_NODECREATIONPROPERTYPTR_IDX], (pyArgs[2]))))
                    goto Sbk_AppFunc_createWriter_TypeError;
            }
        }
        ::QString cppArg0 = ::QString();
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return 0;
        ::Group* cppArg1 = 0;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);
        ::std::map<QString, NodeCreationProperty * > cppArg2;
        if (pythonToCpp[2]) pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // createWriter(QString,Group*,std::map<QString,NodeCreationProperty*>)const
            // Begin code injection

            Effect * cppResult = cppSelf->createWriter(cppArg0,cppArg1, cppArg2);
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkNatronEngineTypes[SBK_EFFECT_IDX], cppResult);

            // End of code injection



            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_AppFunc_createWriter_TypeError:
        const char* overloads[] = {"unicode, NatronEngine.Group = None, dict = NodeCreationPropertyMap()", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.App.createWriter", overloads);
        return 0;
}

static PyObject* Sbk_AppFunc_getAppID(PyObject* self)
{
    AppWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (AppWrapper*)((::App*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_APP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

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
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_AppFunc_getProjectParam(PyObject* self, PyObject* pyArg)
{
    AppWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (AppWrapper*)((::App*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_APP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: getProjectParam(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // getProjectParam(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_AppFunc_getProjectParam_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getProjectParam(QString)const
            Param * cppResult = const_cast<const ::AppWrapper*>(cppSelf)->getProjectParam(cppArg0);
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkNatronEngineTypes[SBK_PARAM_IDX], cppResult);

            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_AppFunc_getProjectParam_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.App.getProjectParam", overloads);
        return 0;
}

static PyObject* Sbk_AppFunc_getViewIndex(PyObject* self, PyObject* pyArg)
{
    AppWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (AppWrapper*)((::App*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_APP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: getViewIndex(QString)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // getViewIndex(QString)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_AppFunc_getViewIndex_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getViewIndex(QString)const
            int cppResult = const_cast<const ::AppWrapper*>(cppSelf)->getViewIndex(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_AppFunc_getViewIndex_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.App.getViewIndex", overloads);
        return 0;
}

static PyObject* Sbk_AppFunc_getViewName(PyObject* self, PyObject* pyArg)
{
    AppWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (AppWrapper*)((::App*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_APP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: getViewName(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // getViewName(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_AppFunc_getViewName_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getViewName(int)const
            QString cppResult = const_cast<const ::AppWrapper*>(cppSelf)->getViewName(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_AppFunc_getViewName_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.App.getViewName", overloads);
        return 0;
}

static PyObject* Sbk_AppFunc_getViewNames(PyObject* self)
{
    AppWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (AppWrapper*)((::App*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_APP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

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
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_AppFunc_loadProject(PyObject* self, PyObject* pyArg)
{
    AppWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (AppWrapper*)((::App*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_APP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: loadProject(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // loadProject(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_AppFunc_loadProject_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // loadProject(QString)
            // Begin code injection

            App * cppResult = cppSelf->loadProject(cppArg0);
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkNatronEngineTypes[SBK_APP_IDX], cppResult);

            // End of code injection



            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_AppFunc_loadProject_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.App.loadProject", overloads);
        return 0;
}

static PyObject* Sbk_AppFunc_newProject(PyObject* self)
{
    AppWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (AppWrapper*)((::App*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_APP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // newProject()
            // Begin code injection

            App * cppResult = cppSelf->newProject();
            pyResult = Shiboken::Conversions::pointerToPython((SbkObjectType*)SbkNatronEngineTypes[SBK_APP_IDX], cppResult);

            // End of code injection



            // Ownership transferences.
            Shiboken::Object::getOwnership(pyResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_AppFunc_redrawViewer(PyObject* self, PyObject* pyArg)
{
    AppWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (AppWrapper*)((::App*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_APP_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: redrawViewer(Effect*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkNatronEngineTypes[SBK_EFFECT_IDX], (pyArg)))) {
        overloadId = 0; // redrawViewer(Effect*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_AppFunc_redrawViewer_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return 0;
        ::Effect* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // redrawViewer(Effect*)
            cppSelf->redrawViewer(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_AppFunc_redrawViewer_TypeError:
        const char* overloads[] = {"NatronEngine.Effect", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.App.redrawViewer", overloads);
        return 0;
}

static PyObject* Sbk_AppFunc_refreshViewer(PyObject* self, PyObject* args, PyObject* kwds)
{
    AppWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (AppWrapper*)((::App*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_APP_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 2) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.App.refreshViewer(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.App.refreshViewer(): not enough arguments");
        return 0;
    }

    if (!PyArg_ParseTuple(args, "|OO:refreshViewer", &(pyArgs[0]), &(pyArgs[1])))
        return 0;


    // Overloaded function decisor
    // 0: refreshViewer(Effect*,bool)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkNatronEngineTypes[SBK_EFFECT_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // refreshViewer(Effect*,bool)
        } else if ((pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1])))) {
            overloadId = 0; // refreshViewer(Effect*,bool)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_AppFunc_refreshViewer_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject* value = PyDict_GetItemString(kwds, "useCache");
            if (value && pyArgs[1]) {
                PyErr_SetString(PyExc_TypeError, "NatronEngine.App.refreshViewer(): got multiple values for keyword argument 'useCache'.");
                return 0;
            } else if (value) {
                pyArgs[1] = value;
                if (!(pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[1]))))
                    goto Sbk_AppFunc_refreshViewer_TypeError;
            }
        }
        if (!Shiboken::Object::isValid(pyArgs[0]))
            return 0;
        ::Effect* cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        bool cppArg1 = true;
        if (pythonToCpp[1]) pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // refreshViewer(Effect*,bool)
            cppSelf->refreshViewer(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_AppFunc_refreshViewer_TypeError:
        const char* overloads[] = {"NatronEngine.Effect, bool = true", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.App.refreshViewer", overloads);
        return 0;
}

static PyObject* Sbk_AppFunc_render(PyObject* self, PyObject* args, PyObject* kwds)
{
    AppWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (AppWrapper*)((::App*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_APP_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { 0, 0, 0, 0 };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 4) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.App.render(): too many arguments");
        return 0;
    } else if (numArgs < 1) {
        PyErr_SetString(PyExc_TypeError, "NatronEngine.App.render(): not enough arguments");
        return 0;
    } else if (numArgs == 2)
        goto Sbk_AppFunc_render_TypeError;

    if (!PyArg_ParseTuple(args, "|OOOO:render", &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return 0;


    // Overloaded function decisor
    // 0: render(Effect*,int,int,int)
    // 1: render(std::list<Effect*>,std::list<int>,std::list<int>,std::list<int>)
    if (numArgs >= 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppPointerConvertible((SbkObjectType*)SbkNatronEngineTypes[SBK_EFFECT_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        if (numArgs == 3) {
            overloadId = 0; // render(Effect*,int,int,int)
        } else if ((pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
            overloadId = 0; // render(Effect*,int,int,int)
        }
    } else if (numArgs == 1
        && PyList_Check(pyArgs[0])) {
        overloadId = 1; // render(std::list<Effect*>,std::list<int>,std::list<int>,std::list<int>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_AppFunc_render_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // render(Effect * writeNode, int firstFrame, int lastFrame, int frameStep)
        {
            if (kwds) {
                PyObject* value = PyDict_GetItemString(kwds, "frameStep");
                if (value && pyArgs[3]) {
                    PyErr_SetString(PyExc_TypeError, "NatronEngine.App.render(): got multiple values for keyword argument 'frameStep'.");
                    return 0;
                } else if (value) {
                    pyArgs[3] = value;
                    if (!(pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3]))))
                        goto Sbk_AppFunc_render_TypeError;
                }
            }
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return 0;
            ::Effect* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3 = 1;
            if (pythonToCpp[3]) pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // render(Effect*,int,int,int)
                cppSelf->render(cppArg0, cppArg1, cppArg2, cppArg3);
            }
            break;
        }
        case 1: // render(const std::list<Effect * > & effects, const std::list<int > & firstFrames, const std::list<int > & lastFrames, const std::list<int > & frameSteps)
        {

            if (!PyErr_Occurred()) {
                // render(std::list<Effect*>,std::list<int>,std::list<int>,std::list<int>)
                // Begin code injection

                if (!PyList_Check(pyArgs[1-1])) {
                    PyErr_SetString(PyExc_TypeError, "tasks must be a list of tuple objects.");
                    return 0;
                }
                std::list<Effect*> effects;

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
                    ::Effect* writeNode = ((::Effect*)0);
                    Shiboken::Conversions::pythonToCppPointer((SbkObjectType*)SbkNatronEngineTypes[SBK_EFFECT_IDX], PyTuple_GET_ITEM(tuple, 0), &(writeNode));
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
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_AppFunc_render_TypeError:
        const char* overloads[] = {"NatronEngine.Effect, int, int, int = 1", "list, list, list, list", 0};
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.App.render", overloads);
        return 0;
}

static PyObject* Sbk_AppFunc_resetProject(PyObject* self)
{
    AppWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (AppWrapper*)((::App*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_APP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

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
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_AppFunc_saveProject(PyObject* self, PyObject* pyArg)
{
    AppWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (AppWrapper*)((::App*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_APP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: saveProject(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // saveProject(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_AppFunc_saveProject_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // saveProject(QString)
            bool cppResult = cppSelf->saveProject(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_AppFunc_saveProject_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.App.saveProject", overloads);
        return 0;
}

static PyObject* Sbk_AppFunc_saveProjectAs(PyObject* self, PyObject* pyArg)
{
    AppWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (AppWrapper*)((::App*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_APP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: saveProjectAs(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // saveProjectAs(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_AppFunc_saveProjectAs_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // saveProjectAs(QString)
            bool cppResult = cppSelf->saveProjectAs(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_AppFunc_saveProjectAs_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.App.saveProjectAs", overloads);
        return 0;
}

static PyObject* Sbk_AppFunc_saveTempProject(PyObject* self, PyObject* pyArg)
{
    AppWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (AppWrapper*)((::App*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_APP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: saveTempProject(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // saveTempProject(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_AppFunc_saveTempProject_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // saveTempProject(QString)
            bool cppResult = cppSelf->saveTempProject(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_AppFunc_saveTempProject_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.App.saveTempProject", overloads);
        return 0;
}

static PyObject* Sbk_AppFunc_timelineGetLeftBound(PyObject* self)
{
    AppWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (AppWrapper*)((::App*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_APP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

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
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_AppFunc_timelineGetRightBound(PyObject* self)
{
    AppWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (AppWrapper*)((::App*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_APP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

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
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_AppFunc_timelineGetTime(PyObject* self)
{
    AppWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (AppWrapper*)((::App*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_APP_IDX], (SbkObject*)self));
    PyObject* pyResult = 0;

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
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_AppFunc_timelineGoTo(PyObject* self, PyObject* pyArg)
{
    AppWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (AppWrapper*)((::App*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_APP_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: timelineGoTo(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // timelineGoTo(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_AppFunc_timelineGoTo_TypeError;

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
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_AppFunc_timelineGoTo_TypeError:
        const char* overloads[] = {"int", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.App.timelineGoTo", overloads);
        return 0;
}

static PyObject* Sbk_AppFunc_writeToScriptEditor(PyObject* self, PyObject* pyArg)
{
    AppWrapper* cppSelf = 0;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = (AppWrapper*)((::App*)Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_APP_IDX], (SbkObject*)self));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: writeToScriptEditor(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // writeToScriptEditor(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_AppFunc_writeToScriptEditor_TypeError;

    // Call function/method
    {
        ::QString cppArg0 = ::QString();
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // writeToScriptEditor(QString)
            cppSelf->writeToScriptEditor(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_AppFunc_writeToScriptEditor_TypeError:
        const char* overloads[] = {"unicode", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.App.writeToScriptEditor", overloads);
        return 0;
}

static PyMethodDef Sbk_App_methods[] = {
    {"addFormat", (PyCFunction)Sbk_AppFunc_addFormat, METH_O},
    {"addProjectLayer", (PyCFunction)Sbk_AppFunc_addProjectLayer, METH_O},
    {"closeProject", (PyCFunction)Sbk_AppFunc_closeProject, METH_NOARGS},
    {"createNode", (PyCFunction)Sbk_AppFunc_createNode, METH_VARARGS|METH_KEYWORDS},
    {"createReader", (PyCFunction)Sbk_AppFunc_createReader, METH_VARARGS|METH_KEYWORDS},
    {"createWriter", (PyCFunction)Sbk_AppFunc_createWriter, METH_VARARGS|METH_KEYWORDS},
    {"getAppID", (PyCFunction)Sbk_AppFunc_getAppID, METH_NOARGS},
    {"getProjectParam", (PyCFunction)Sbk_AppFunc_getProjectParam, METH_O},
    {"getViewIndex", (PyCFunction)Sbk_AppFunc_getViewIndex, METH_O},
    {"getViewName", (PyCFunction)Sbk_AppFunc_getViewName, METH_O},
    {"getViewNames", (PyCFunction)Sbk_AppFunc_getViewNames, METH_NOARGS},
    {"loadProject", (PyCFunction)Sbk_AppFunc_loadProject, METH_O},
    {"newProject", (PyCFunction)Sbk_AppFunc_newProject, METH_NOARGS},
    {"redrawViewer", (PyCFunction)Sbk_AppFunc_redrawViewer, METH_O},
    {"refreshViewer", (PyCFunction)Sbk_AppFunc_refreshViewer, METH_VARARGS|METH_KEYWORDS},
    {"render", (PyCFunction)Sbk_AppFunc_render, METH_VARARGS|METH_KEYWORDS},
    {"resetProject", (PyCFunction)Sbk_AppFunc_resetProject, METH_NOARGS},
    {"saveProject", (PyCFunction)Sbk_AppFunc_saveProject, METH_O},
    {"saveProjectAs", (PyCFunction)Sbk_AppFunc_saveProjectAs, METH_O},
    {"saveTempProject", (PyCFunction)Sbk_AppFunc_saveTempProject, METH_O},
    {"timelineGetLeftBound", (PyCFunction)Sbk_AppFunc_timelineGetLeftBound, METH_NOARGS},
    {"timelineGetRightBound", (PyCFunction)Sbk_AppFunc_timelineGetRightBound, METH_NOARGS},
    {"timelineGetTime", (PyCFunction)Sbk_AppFunc_timelineGetTime, METH_NOARGS},
    {"timelineGoTo", (PyCFunction)Sbk_AppFunc_timelineGoTo, METH_O},
    {"writeToScriptEditor", (PyCFunction)Sbk_AppFunc_writeToScriptEditor, METH_O},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_App_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_App_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_App_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "NatronEngine.App",
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
    /*tp_traverse*/         Sbk_App_traverse,
    /*tp_clear*/            Sbk_App_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_App_methods,
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

static void* Sbk_App_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::Group >()))
        return dynamic_cast< ::App*>(reinterpret_cast< ::Group*>(cptr));
    return 0;
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void App_PythonToCpp_App_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(&Sbk_App_Type, pyIn, cppOut);
}
static PythonToCppFunc is_App_PythonToCpp_App_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, (PyTypeObject*)&Sbk_App_Type))
        return App_PythonToCpp_App_PTR;
    return 0;
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* App_PTR_CppToPython_App(const void* cppIn) {
    PyObject* pyOut = (PyObject*)Shiboken::BindingManager::instance().retrieveWrapper(cppIn);
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    const char* typeName = typeid(*((::App*)cppIn)).name();
    return Shiboken::Object::newObject(&Sbk_App_Type, const_cast<void*>(cppIn), false, false, typeName);
}

void init_App(PyObject* module)
{
    SbkNatronEngineTypes[SBK_APP_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_App_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "App", "App*",
        &Sbk_App_Type, &Shiboken::callCppDestructor< ::App >, (SbkObjectType*)SbkNatronEngineTypes[SBK_GROUP_IDX])) {
        return;
    }

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(&Sbk_App_Type,
        App_PythonToCpp_App_PTR,
        is_App_PythonToCpp_App_PTR_Convertible,
        App_PTR_CppToPython_App);

    Shiboken::Conversions::registerConverterName(converter, "App");
    Shiboken::Conversions::registerConverterName(converter, "App*");
    Shiboken::Conversions::registerConverterName(converter, "App&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::App).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::AppWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(&Sbk_App_Type, &Sbk_App_typeDiscovery);


    AppWrapper::pysideInitQtMetaTypes();
}
