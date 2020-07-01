
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
#include "natrongui_python.h"

// main header
#include "natron_python_pytabwidget_wrapper.h"

// inner classes

// Extra includes
#include <PythonPanels.h>


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


// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_Natron_Python_PyTabWidgetFunc_appendTab(PyObject* self, PyObject* pyArg)
{
    ::Natron::Python::PyTabWidget* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::PyTabWidget *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYTABWIDGET_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: PyTabWidget::appendTab(Natron::Python::PyPanel*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYPANEL_IDX]), (pyArg)))) {
        overloadId = 0; // appendTab(Natron::Python::PyPanel*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyTabWidgetFunc_appendTab_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return {};
        ::Natron::Python::PyPanel* cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // appendTab(Natron::Python::PyPanel*)
            // Begin code injection

            bool cppResult = cppSelf->appendTab(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_PyTabWidgetFunc_appendTab_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.Natron.Python.PyTabWidget.appendTab");
        return {};
}

static PyObject* Sbk_Natron_Python_PyTabWidgetFunc_closeCurrentTab(PyObject* self)
{
    ::Natron::Python::PyTabWidget* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::PyTabWidget *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYTABWIDGET_IDX], reinterpret_cast<SbkObject *>(self)));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // closeCurrentTab()
            cppSelf->closeCurrentTab();
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_Natron_Python_PyTabWidgetFunc_closePane(PyObject* self)
{
    ::Natron::Python::PyTabWidget* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::PyTabWidget *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYTABWIDGET_IDX], reinterpret_cast<SbkObject *>(self)));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // closePane()
            cppSelf->closePane();
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_Natron_Python_PyTabWidgetFunc_closeTab(PyObject* self, PyObject* pyArg)
{
    ::Natron::Python::PyTabWidget* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::PyTabWidget *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYTABWIDGET_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: PyTabWidget::closeTab(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // closeTab(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyTabWidgetFunc_closeTab_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // closeTab(int)
            cppSelf->closeTab(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_PyTabWidgetFunc_closeTab_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.Natron.Python.PyTabWidget.closeTab");
        return {};
}

static PyObject* Sbk_Natron_Python_PyTabWidgetFunc_count(PyObject* self)
{
    ::Natron::Python::PyTabWidget* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::PyTabWidget *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYTABWIDGET_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // count()
            int cppResult = cppSelf->count();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_PyTabWidgetFunc_floatCurrentTab(PyObject* self)
{
    ::Natron::Python::PyTabWidget* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::PyTabWidget *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYTABWIDGET_IDX], reinterpret_cast<SbkObject *>(self)));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // floatCurrentTab()
            cppSelf->floatCurrentTab();
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_Natron_Python_PyTabWidgetFunc_floatPane(PyObject* self)
{
    ::Natron::Python::PyTabWidget* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::PyTabWidget *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYTABWIDGET_IDX], reinterpret_cast<SbkObject *>(self)));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // floatPane()
            cppSelf->floatPane();
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_Natron_Python_PyTabWidgetFunc_getCurrentIndex(PyObject* self)
{
    ::Natron::Python::PyTabWidget* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::PyTabWidget *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYTABWIDGET_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getCurrentIndex()const
            int cppResult = const_cast<const ::Natron::Python::PyTabWidget*>(cppSelf)->getCurrentIndex();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_PyTabWidgetFunc_getScriptName(PyObject* self)
{
    ::Natron::Python::PyTabWidget* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::PyTabWidget *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYTABWIDGET_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getScriptName()const
            QString cppResult = const_cast<const ::Natron::Python::PyTabWidget*>(cppSelf)->getScriptName();
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_PyTabWidgetFunc_getTabLabel(PyObject* self, PyObject* pyArg)
{
    ::Natron::Python::PyTabWidget* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::PyTabWidget *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYTABWIDGET_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: PyTabWidget::getTabLabel(int)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // getTabLabel(int)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyTabWidgetFunc_getTabLabel_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getTabLabel(int)const
            QString cppResult = const_cast<const ::Natron::Python::PyTabWidget*>(cppSelf)->getTabLabel(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_PyTabWidgetFunc_getTabLabel_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.Natron.Python.PyTabWidget.getTabLabel");
        return {};
}

static PyObject* Sbk_Natron_Python_PyTabWidgetFunc_insertTab(PyObject* self, PyObject* args)
{
    ::Natron::Python::PyTabWidget* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::PyTabWidget *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYTABWIDGET_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "insertTab", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: PyTabWidget::insertTab(int,Natron::Python::PyPanel*)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYPANEL_IDX]), (pyArgs[1])))) {
        overloadId = 0; // insertTab(int,Natron::Python::PyPanel*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyTabWidgetFunc_insertTab_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return {};
        ::Natron::Python::PyPanel* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // insertTab(int,Natron::Python::PyPanel*)
            // Begin code injection

            cppSelf->insertTab(cppArg0,cppArg1);

            // End of code injection


        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_PyTabWidgetFunc_insertTab_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.Natron.Python.PyTabWidget.insertTab");
        return {};
}

static PyObject* Sbk_Natron_Python_PyTabWidgetFunc_removeTab(PyObject* self, PyObject* pyArg)
{
    ::Natron::Python::PyTabWidget* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::PyTabWidget *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYTABWIDGET_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: PyTabWidget::removeTab(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // removeTab(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyTabWidgetFunc_removeTab_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // removeTab(int)
            cppSelf->removeTab(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_PyTabWidgetFunc_removeTab_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.Natron.Python.PyTabWidget.removeTab");
        return {};
}

static PyObject* Sbk_Natron_Python_PyTabWidgetFunc_setCurrentIndex(PyObject* self, PyObject* pyArg)
{
    ::Natron::Python::PyTabWidget* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::PyTabWidget *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYTABWIDGET_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: PyTabWidget::setCurrentIndex(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setCurrentIndex(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyTabWidgetFunc_setCurrentIndex_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCurrentIndex(int)
            cppSelf->setCurrentIndex(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_PyTabWidgetFunc_setCurrentIndex_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.Natron.Python.PyTabWidget.setCurrentIndex");
        return {};
}

static PyObject* Sbk_Natron_Python_PyTabWidgetFunc_setNextTabCurrent(PyObject* self)
{
    ::Natron::Python::PyTabWidget* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::PyTabWidget *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYTABWIDGET_IDX], reinterpret_cast<SbkObject *>(self)));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // setNextTabCurrent()
            cppSelf->setNextTabCurrent();
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_Natron_Python_PyTabWidgetFunc_splitHorizontally(PyObject* self)
{
    ::Natron::Python::PyTabWidget* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::PyTabWidget *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYTABWIDGET_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // splitHorizontally()
            Natron::Python::PyTabWidget * cppResult = cppSelf->splitHorizontally();
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYTABWIDGET_IDX]), cppResult);

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

static PyObject* Sbk_Natron_Python_PyTabWidgetFunc_splitVertically(PyObject* self)
{
    ::Natron::Python::PyTabWidget* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::Python::PyTabWidget *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYTABWIDGET_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // splitVertically()
            Natron::Python::PyTabWidget * cppResult = cppSelf->splitVertically();
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYTABWIDGET_IDX]), cppResult);

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

static PyMethodDef Sbk_Natron_Python_PyTabWidget_methods[] = {
    {"appendTab", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyTabWidgetFunc_appendTab), METH_O},
    {"closeCurrentTab", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyTabWidgetFunc_closeCurrentTab), METH_NOARGS},
    {"closePane", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyTabWidgetFunc_closePane), METH_NOARGS},
    {"closeTab", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyTabWidgetFunc_closeTab), METH_O},
    {"count", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyTabWidgetFunc_count), METH_NOARGS},
    {"floatCurrentTab", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyTabWidgetFunc_floatCurrentTab), METH_NOARGS},
    {"floatPane", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyTabWidgetFunc_floatPane), METH_NOARGS},
    {"getCurrentIndex", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyTabWidgetFunc_getCurrentIndex), METH_NOARGS},
    {"getScriptName", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyTabWidgetFunc_getScriptName), METH_NOARGS},
    {"getTabLabel", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyTabWidgetFunc_getTabLabel), METH_O},
    {"insertTab", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyTabWidgetFunc_insertTab), METH_VARARGS},
    {"removeTab", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyTabWidgetFunc_removeTab), METH_O},
    {"setCurrentIndex", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyTabWidgetFunc_setCurrentIndex), METH_O},
    {"setNextTabCurrent", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyTabWidgetFunc_setNextTabCurrent), METH_NOARGS},
    {"splitHorizontally", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyTabWidgetFunc_splitHorizontally), METH_NOARGS},
    {"splitVertically", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyTabWidgetFunc_splitVertically), METH_NOARGS},

    {nullptr, nullptr} // Sentinel
};

} // extern "C"

static int Sbk_Natron_Python_PyTabWidget_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_Natron_Python_PyTabWidget_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_Natron_Python_PyTabWidget_Type = nullptr;
static SbkObjectType *Sbk_Natron_Python_PyTabWidget_TypeF(void)
{
    return _Sbk_Natron_Python_PyTabWidget_Type;
}

static PyType_Slot Sbk_Natron_Python_PyTabWidget_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_Natron_Python_PyTabWidget_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_Natron_Python_PyTabWidget_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_Natron_Python_PyTabWidget_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        nullptr},
    {Py_tp_new,         reinterpret_cast<void*>(SbkDummyNew /* PYSIDE-595: Prevent replacement of "0" with base->tp_new. */)},
    {0, nullptr}
};
static PyType_Spec Sbk_Natron_Python_PyTabWidget_spec = {
    "NatronGui.Natron.Python.PyTabWidget",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Natron_Python_PyTabWidget_slots
};

} //extern "C"


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void PyTabWidget_PythonToCpp_PyTabWidget_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_Natron_Python_PyTabWidget_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_PyTabWidget_PythonToCpp_PyTabWidget_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_PyTabWidget_TypeF())))
        return PyTabWidget_PythonToCpp_PyTabWidget_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* PyTabWidget_PTR_CppToPython_PyTabWidget(const void* cppIn) {
    auto pyOut = reinterpret_cast<PyObject*>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::Natron::Python::PyTabWidget *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_Natron_Python_PyTabWidget_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *Natron_Python_PyTabWidget_SignatureStrings[] = {
    "NatronGui.Natron.Python.PyTabWidget.appendTab(tab:NatronGui.Natron.Python.PyPanel)->bool",
    "NatronGui.Natron.Python.PyTabWidget.closeCurrentTab()",
    "NatronGui.Natron.Python.PyTabWidget.closePane()",
    "NatronGui.Natron.Python.PyTabWidget.closeTab(index:int)",
    "NatronGui.Natron.Python.PyTabWidget.count()->int",
    "NatronGui.Natron.Python.PyTabWidget.floatCurrentTab()",
    "NatronGui.Natron.Python.PyTabWidget.floatPane()",
    "NatronGui.Natron.Python.PyTabWidget.getCurrentIndex()->int",
    "NatronGui.Natron.Python.PyTabWidget.getScriptName()->QString",
    "NatronGui.Natron.Python.PyTabWidget.getTabLabel(index:int)->QString",
    "NatronGui.Natron.Python.PyTabWidget.insertTab(index:int,tab:NatronGui.Natron.Python.PyPanel)",
    "NatronGui.Natron.Python.PyTabWidget.removeTab(index:int)",
    "NatronGui.Natron.Python.PyTabWidget.setCurrentIndex(index:int)",
    "NatronGui.Natron.Python.PyTabWidget.setNextTabCurrent()",
    "NatronGui.Natron.Python.PyTabWidget.splitHorizontally()->NatronGui.Natron.Python.PyTabWidget",
    "NatronGui.Natron.Python.PyTabWidget.splitVertically()->NatronGui.Natron.Python.PyTabWidget",
    nullptr}; // Sentinel

void init_Natron_Python_PyTabWidget(PyObject* module)
{
    _Sbk_Natron_Python_PyTabWidget_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "PyTabWidget",
        "Natron::Python::PyTabWidget*",
        &Sbk_Natron_Python_PyTabWidget_spec,
        Natron_Python_PyTabWidget_SignatureStrings,
        &Shiboken::callCppDestructor< ::Natron::Python::PyTabWidget >,
        0,
        0,
        0    );
    
    SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYTABWIDGET_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_PyTabWidget_TypeF());

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_Natron_Python_PyTabWidget_TypeF(),
        PyTabWidget_PythonToCpp_PyTabWidget_PTR,
        is_PyTabWidget_PythonToCpp_PyTabWidget_PTR_Convertible,
        PyTabWidget_PTR_CppToPython_PyTabWidget);

    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::PyTabWidget");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::PyTabWidget*");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::PyTabWidget&");
    Shiboken::Conversions::registerConverterName(converter, "Python::PyTabWidget");
    Shiboken::Conversions::registerConverterName(converter, "Python::PyTabWidget*");
    Shiboken::Conversions::registerConverterName(converter, "Python::PyTabWidget&");
    Shiboken::Conversions::registerConverterName(converter, "PyTabWidget");
    Shiboken::Conversions::registerConverterName(converter, "PyTabWidget*");
    Shiboken::Conversions::registerConverterName(converter, "PyTabWidget&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Natron::Python::PyTabWidget).name());



}
