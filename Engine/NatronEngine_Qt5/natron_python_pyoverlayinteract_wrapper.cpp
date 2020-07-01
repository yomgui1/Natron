
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
#include "natron_python_pyoverlayinteract_wrapper.h"

// inner classes

// Extra includes
#include <PyNode.h>
#include <PyOverlayInteract.h>
#include <PyParameter.h>
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

void PyOverlayInteractWrapper::pysideInitQtMetaTypes()
{
}

PyOverlayInteractWrapper::PyOverlayInteractWrapper() : Natron::Python::PyOverlayInteract()
{
    // ... middle
}

std::map<QString,Natron::Python::PyOverlayParamDesc > PyOverlayInteractWrapper::describeParameters() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return {};
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "describeParameters"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::Natron::Python::PyOverlayInteract::describeParameters();
    }

    Shiboken::AutoDecRef pyArgs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return {};
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_MAP_QSTRING_NATRON_PYTHON_PYOVERLAYPARAMDESC_IDX], pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PyOverlayInteract.describeParameters", "map", Py_TYPE(pyResult)->tp_name);
        return {};
    }
    ::std::map<QString,Natron::Python::PyOverlayParamDesc > cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void PyOverlayInteractWrapper::draw(double time, const Natron::Python::Double2DTuple & renderScale, QString view)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "draw"));
    if (pyOverride.isNull()) {
        gil.release();
        this->::Natron::Python::PyOverlayInteract::draw(time, renderScale, view);
        return;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(dNN)",
        time,
        Shiboken::Conversions::referenceToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLE2DTUPLE_IDX]), &renderScale),
        Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &view)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return;
    }
}

void PyOverlayInteractWrapper::fetchParameters(const std::map<QString,QString > & params)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "fetchParameters"));
    if (pyOverride.isNull()) {
        gil.release();
        this->::Natron::Python::PyOverlayInteract::fetchParameters(params);
        return;
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(N)",
        Shiboken::Conversions::copyToPython(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_MAP_QSTRING_QSTRING_IDX], &params)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return;
    }
}

bool PyOverlayInteractWrapper::focusGained(double time, const Natron::Python::Double2DTuple & renderScale, const QString & view)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return false;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "focusGained"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::Natron::Python::PyOverlayInteract::focusGained(time, renderScale, view);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(dNN)",
        time,
        Shiboken::Conversions::referenceToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLE2DTUPLE_IDX]), &renderScale),
        Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &view)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return false;
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PyOverlayInteract.focusGained", "bool", Py_TYPE(pyResult)->tp_name);
        return false;
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool PyOverlayInteractWrapper::focusLost(double time, const Natron::Python::Double2DTuple & renderScale, const QString & view)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return false;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "focusLost"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::Natron::Python::PyOverlayInteract::focusLost(time, renderScale, view);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(dNN)",
        time,
        Shiboken::Conversions::referenceToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLE2DTUPLE_IDX]), &renderScale),
        Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &view)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return false;
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PyOverlayInteract.focusLost", "bool", Py_TYPE(pyResult)->tp_name);
        return false;
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool PyOverlayInteractWrapper::keyDown(double time, const Natron::Python::Double2DTuple & renderScale, const QString & view, Qt::Key key, const QFlags<Qt::KeyboardModifier> & modifiers)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return false;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "keyDown"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::Natron::Python::PyOverlayInteract::keyDown(time, renderScale, view, key, modifiers);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(dNNNN)",
        time,
        Shiboken::Conversions::referenceToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLE2DTUPLE_IDX]), &renderScale),
        Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &view),
        Shiboken::Conversions::copyToPython(*PepType_SGTP(SbkPySide2_QtCoreTypes[SBK_QT_KEY_IDX])->converter, &key),
        Shiboken::Conversions::copyToPython(*PepType_SGTP(SbkPySide2_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER_IDX])->converter, &modifiers)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return false;
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PyOverlayInteract.keyDown", "bool", Py_TYPE(pyResult)->tp_name);
        return false;
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool PyOverlayInteractWrapper::keyRepeat(double time, const Natron::Python::Double2DTuple & renderScale, const QString & view, Qt::Key key, const QFlags<Qt::KeyboardModifier> & modifiers)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return false;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "keyRepeat"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::Natron::Python::PyOverlayInteract::keyRepeat(time, renderScale, view, key, modifiers);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(dNNNN)",
        time,
        Shiboken::Conversions::referenceToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLE2DTUPLE_IDX]), &renderScale),
        Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &view),
        Shiboken::Conversions::copyToPython(*PepType_SGTP(SbkPySide2_QtCoreTypes[SBK_QT_KEY_IDX])->converter, &key),
        Shiboken::Conversions::copyToPython(*PepType_SGTP(SbkPySide2_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER_IDX])->converter, &modifiers)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return false;
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PyOverlayInteract.keyRepeat", "bool", Py_TYPE(pyResult)->tp_name);
        return false;
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool PyOverlayInteractWrapper::keyUp(double time, const Natron::Python::Double2DTuple & renderScale, const QString & view, Qt::Key key, const QFlags<Qt::KeyboardModifier> & modifiers)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return false;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "keyUp"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::Natron::Python::PyOverlayInteract::keyUp(time, renderScale, view, key, modifiers);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(dNNNN)",
        time,
        Shiboken::Conversions::referenceToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLE2DTUPLE_IDX]), &renderScale),
        Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &view),
        Shiboken::Conversions::copyToPython(*PepType_SGTP(SbkPySide2_QtCoreTypes[SBK_QT_KEY_IDX])->converter, &key),
        Shiboken::Conversions::copyToPython(*PepType_SGTP(SbkPySide2_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER_IDX])->converter, &modifiers)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return false;
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PyOverlayInteract.keyUp", "bool", Py_TYPE(pyResult)->tp_name);
        return false;
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool PyOverlayInteractWrapper::penDoubleClicked(double time, const Natron::Python::Double2DTuple & renderScale, const QString & view, const Natron::Python::Double2DTuple & viewportPos, const Natron::Python::Double2DTuple & pos)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return false;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "penDoubleClicked"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::Natron::Python::PyOverlayInteract::penDoubleClicked(time, renderScale, view, viewportPos, pos);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(dNNNN)",
        time,
        Shiboken::Conversions::referenceToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLE2DTUPLE_IDX]), &renderScale),
        Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &view),
        Shiboken::Conversions::referenceToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLE2DTUPLE_IDX]), &viewportPos),
        Shiboken::Conversions::referenceToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLE2DTUPLE_IDX]), &pos)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return false;
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PyOverlayInteract.penDoubleClicked", "bool", Py_TYPE(pyResult)->tp_name);
        return false;
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool PyOverlayInteractWrapper::penDown(double time, const Natron::Python::Double2DTuple & renderScale, const QString & view, const Natron::Python::Double2DTuple & viewportPos, const Natron::Python::Double2DTuple & pos, double pressure, double timestamp, Natron::PenType pen)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return false;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "penDown"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::Natron::Python::PyOverlayInteract::penDown(time, renderScale, view, viewportPos, pos, pressure, timestamp, pen);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(dNNNNddN)",
        time,
        Shiboken::Conversions::referenceToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLE2DTUPLE_IDX]), &renderScale),
        Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &view),
        Shiboken::Conversions::referenceToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLE2DTUPLE_IDX]), &viewportPos),
        Shiboken::Conversions::referenceToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLE2DTUPLE_IDX]), &pos),
        pressure,
        timestamp,
        Shiboken::Conversions::copyToPython(*PepType_SGTP(SbkNatronEngineTypes[SBK_NATRON_PENTYPE_IDX])->converter, &pen)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return false;
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PyOverlayInteract.penDown", "bool", Py_TYPE(pyResult)->tp_name);
        return false;
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool PyOverlayInteractWrapper::penMotion(double time, const Natron::Python::Double2DTuple & renderScale, const QString & view, const Natron::Python::Double2DTuple & viewportPos, const Natron::Python::Double2DTuple & pos, double pressure, double timestamp)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return false;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "penMotion"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::Natron::Python::PyOverlayInteract::penMotion(time, renderScale, view, viewportPos, pos, pressure, timestamp);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(dNNNNdd)",
        time,
        Shiboken::Conversions::referenceToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLE2DTUPLE_IDX]), &renderScale),
        Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &view),
        Shiboken::Conversions::referenceToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLE2DTUPLE_IDX]), &viewportPos),
        Shiboken::Conversions::referenceToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLE2DTUPLE_IDX]), &pos),
        pressure,
        timestamp
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return false;
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PyOverlayInteract.penMotion", "bool", Py_TYPE(pyResult)->tp_name);
        return false;
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool PyOverlayInteractWrapper::penUp(double time, const Natron::Python::Double2DTuple & renderScale, const QString & view, const Natron::Python::Double2DTuple & viewportPos, const Natron::Python::Double2DTuple & pos, double pressure, double timestamp)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return false;
    Shiboken::AutoDecRef pyOverride(Shiboken::BindingManager::instance().getOverride(this, "penUp"));
    if (pyOverride.isNull()) {
        gil.release();
        return this->::Natron::Python::PyOverlayInteract::penUp(time, renderScale, view, viewportPos, pos, pressure, timestamp);
    }

    Shiboken::AutoDecRef pyArgs(Py_BuildValue("(dNNNNdd)",
        time,
        Shiboken::Conversions::referenceToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLE2DTUPLE_IDX]), &renderScale),
        Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &view),
        Shiboken::Conversions::referenceToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLE2DTUPLE_IDX]), &viewportPos),
        Shiboken::Conversions::referenceToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLE2DTUPLE_IDX]), &pos),
        pressure,
        timestamp
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(pyOverride, pyArgs, nullptr));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return false;
    }
    // Check return type
    PythonToCppFunc pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyResult);
    if (!pythonToCpp) {
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PyOverlayInteract.penUp", "bool", Py_TYPE(pyResult)->tp_name);
        return false;
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

PyOverlayInteractWrapper::~PyOverlayInteractWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_Natron_Python_PyOverlayInteract_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::Natron::Python::PyOverlayInteract >()))
        return -1;

    ::PyOverlayInteractWrapper* cptr{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // PyOverlayInteract()
            cptr = new ::PyOverlayInteractWrapper();
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::Natron::Python::PyOverlayInteract >(), cptr)) {
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

static PyObject* Sbk_Natron_Python_PyOverlayInteractFunc_describeParameters(PyObject* self)
{
    PyOverlayInteractWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<PyOverlayInteractWrapper *>(reinterpret_cast< ::Natron::Python::PyOverlayInteract *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYOVERLAYINTERACT_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // describeParameters()const
            std::map<QString,Natron::Python::PyOverlayParamDesc > cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? const_cast<const ::PyOverlayInteractWrapper*>(cppSelf)->::Natron::Python::PyOverlayInteract::describeParameters() : const_cast<const ::PyOverlayInteractWrapper*>(cppSelf)->describeParameters();
            pyResult = Shiboken::Conversions::copyToPython(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_MAP_QSTRING_NATRON_PYTHON_PYOVERLAYPARAMDESC_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_PyOverlayInteractFunc_draw(PyObject* self, PyObject* args)
{
    PyOverlayInteractWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<PyOverlayInteractWrapper *>(reinterpret_cast< ::Natron::Python::PyOverlayInteract *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYOVERLAYINTERACT_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "draw", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return {};


    // Overloaded function decisor
    // 0: PyOverlayInteract::draw(double,Natron::Python::Double2DTuple,QString)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLE2DTUPLE_IDX]), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
        overloadId = 0; // draw(double,Natron::Python::Double2DTuple,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyOverlayInteractFunc_draw_TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return {};
        ::Natron::Python::Double2DTuple* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QString cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // draw(double,Natron::Python::Double2DTuple,QString)
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::Natron::Python::PyOverlayInteract::draw(cppArg0, *cppArg1, cppArg2) : cppSelf->draw(cppArg0, *cppArg1, cppArg2);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_PyOverlayInteractFunc_draw_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.PyOverlayInteract.draw");
        return {};
}

static PyObject* Sbk_Natron_Python_PyOverlayInteractFunc_fetchParameter(PyObject* self, PyObject* args)
{
    PyOverlayInteractWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<PyOverlayInteractWrapper *>(reinterpret_cast< ::Natron::Python::PyOverlayInteract *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYOVERLAYINTERACT_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "fetchParameter", 5, 5, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return {};


    // Overloaded function decisor
    // 0: PyOverlayInteract::fetchParameter(std::map<QString,QString>,QString,QString,int,bool)const
    if (numArgs == 5
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_MAP_QSTRING_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[4])))) {
        overloadId = 0; // fetchParameter(std::map<QString,QString>,QString,QString,int,bool)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyOverlayInteractFunc_fetchParameter_TypeError;

    // Call function/method
    {
        ::std::map<QString,QString > cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        ::QString cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QString cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        int cppArg3;
        pythonToCpp[3](pyArgs[3], &cppArg3);
        bool cppArg4;
        pythonToCpp[4](pyArgs[4], &cppArg4);

        if (!PyErr_Occurred()) {
            // fetchParameter(std::map<QString,QString>,QString,QString,int,bool)const
            Natron::Python::Param * cppResult = static_cast<::PyOverlayInteractWrapper*>(cppSelf)->PyOverlayInteractWrapper::fetchParameter_protected(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
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

    Sbk_Natron_Python_PyOverlayInteractFunc_fetchParameter_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.PyOverlayInteract.fetchParameter");
        return {};
}

static PyObject* Sbk_Natron_Python_PyOverlayInteractFunc_fetchParameters(PyObject* self, PyObject* pyArg)
{
    PyOverlayInteractWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<PyOverlayInteractWrapper *>(reinterpret_cast< ::Natron::Python::PyOverlayInteract *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYOVERLAYINTERACT_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: PyOverlayInteract::fetchParameters(std::map<QString,QString>)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_MAP_QSTRING_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // fetchParameters(std::map<QString,QString>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyOverlayInteractFunc_fetchParameters_TypeError;

    // Call function/method
    {
        ::std::map<QString,QString > cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // fetchParameters(std::map<QString,QString>)
            Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::Natron::Python::PyOverlayInteract::fetchParameters(cppArg0) : cppSelf->fetchParameters(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_PyOverlayInteractFunc_fetchParameters_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.PyOverlayInteract.fetchParameters");
        return {};
}

static PyObject* Sbk_Natron_Python_PyOverlayInteractFunc_focusGained(PyObject* self, PyObject* args)
{
    PyOverlayInteractWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<PyOverlayInteractWrapper *>(reinterpret_cast< ::Natron::Python::PyOverlayInteract *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYOVERLAYINTERACT_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "focusGained", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return {};


    // Overloaded function decisor
    // 0: PyOverlayInteract::focusGained(double,Natron::Python::Double2DTuple,QString)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLE2DTUPLE_IDX]), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
        overloadId = 0; // focusGained(double,Natron::Python::Double2DTuple,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyOverlayInteractFunc_focusGained_TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return {};
        ::Natron::Python::Double2DTuple* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QString cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // focusGained(double,Natron::Python::Double2DTuple,QString)
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::Natron::Python::PyOverlayInteract::focusGained(cppArg0, *cppArg1, cppArg2) : cppSelf->focusGained(cppArg0, *cppArg1, cppArg2);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_PyOverlayInteractFunc_focusGained_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.PyOverlayInteract.focusGained");
        return {};
}

static PyObject* Sbk_Natron_Python_PyOverlayInteractFunc_focusLost(PyObject* self, PyObject* args)
{
    PyOverlayInteractWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<PyOverlayInteractWrapper *>(reinterpret_cast< ::Natron::Python::PyOverlayInteract *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYOVERLAYINTERACT_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "focusLost", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return {};


    // Overloaded function decisor
    // 0: PyOverlayInteract::focusLost(double,Natron::Python::Double2DTuple,QString)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLE2DTUPLE_IDX]), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))) {
        overloadId = 0; // focusLost(double,Natron::Python::Double2DTuple,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyOverlayInteractFunc_focusLost_TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return {};
        ::Natron::Python::Double2DTuple* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QString cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // focusLost(double,Natron::Python::Double2DTuple,QString)
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::Natron::Python::PyOverlayInteract::focusLost(cppArg0, *cppArg1, cppArg2) : cppSelf->focusLost(cppArg0, *cppArg1, cppArg2);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_PyOverlayInteractFunc_focusLost_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.PyOverlayInteract.focusLost");
        return {};
}

static PyObject* Sbk_Natron_Python_PyOverlayInteractFunc_getColorPicker(PyObject* self)
{
    PyOverlayInteractWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<PyOverlayInteractWrapper *>(reinterpret_cast< ::Natron::Python::PyOverlayInteract *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYOVERLAYINTERACT_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getColorPicker()const
            Natron::Python::ColorTuple* cppResult = new Natron::Python::ColorTuple(const_cast<const ::PyOverlayInteractWrapper*>(cppSelf)->getColorPicker());
            pyResult = Shiboken::Object::newObject(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_COLORTUPLE_IDX]), cppResult, true, true);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_PyOverlayInteractFunc_getHoldingEffect(PyObject* self)
{
    PyOverlayInteractWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<PyOverlayInteractWrapper *>(reinterpret_cast< ::Natron::Python::PyOverlayInteract *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYOVERLAYINTERACT_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getHoldingEffect()const
            Natron::Python::Effect * cppResult = const_cast<const ::PyOverlayInteractWrapper*>(cppSelf)->getHoldingEffect();
            pyResult = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX]), cppResult);

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

static PyObject* Sbk_Natron_Python_PyOverlayInteractFunc_getPixelScale(PyObject* self)
{
    PyOverlayInteractWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<PyOverlayInteractWrapper *>(reinterpret_cast< ::Natron::Python::PyOverlayInteract *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYOVERLAYINTERACT_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getPixelScale()const
            Natron::Python::Double2DTuple* cppResult = new Natron::Python::Double2DTuple(const_cast<const ::PyOverlayInteractWrapper*>(cppSelf)->getPixelScale());
            pyResult = Shiboken::Object::newObject(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLE2DTUPLE_IDX]), cppResult, true, true);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_PyOverlayInteractFunc_getSuggestedColor(PyObject* self)
{
    PyOverlayInteractWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<PyOverlayInteractWrapper *>(reinterpret_cast< ::Natron::Python::PyOverlayInteract *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYOVERLAYINTERACT_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getSuggestedColor(Natron::Python::ColorTuple*)const
            // Begin code injection

            Natron::Python::ColorTuple ret;
            bool ok = cppSelf->getSuggestedColor(&ret);
            PyObject* pyret = PyTuple_New(5);
            PyTuple_SET_ITEM(pyret, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &ok));
            PyTuple_SET_ITEM(pyret, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret.r));
            PyTuple_SET_ITEM(pyret, 2, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret.g));
            PyTuple_SET_ITEM(pyret, 3, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret.b));
            PyTuple_SET_ITEM(pyret, 4, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &ret.a));
            return pyret;

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_PyOverlayInteractFunc_getViewportSize(PyObject* self)
{
    PyOverlayInteractWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<PyOverlayInteractWrapper *>(reinterpret_cast< ::Natron::Python::PyOverlayInteract *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYOVERLAYINTERACT_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getViewportSize()const
            Natron::Python::Int2DTuple* cppResult = new Natron::Python::Int2DTuple(const_cast<const ::PyOverlayInteractWrapper*>(cppSelf)->getViewportSize());
            pyResult = Shiboken::Object::newObject(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_INT2DTUPLE_IDX]), cppResult, true, true);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_PyOverlayInteractFunc_initInternalInteract(PyObject* self)
{
    PyOverlayInteractWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<PyOverlayInteractWrapper *>(reinterpret_cast< ::Natron::Python::PyOverlayInteract *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYOVERLAYINTERACT_IDX], reinterpret_cast<SbkObject *>(self))));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // initInternalInteract()
            static_cast<::PyOverlayInteractWrapper*>(cppSelf)->PyOverlayInteractWrapper::initInternalInteract_protected();
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_Natron_Python_PyOverlayInteractFunc_isColorPickerRequired(PyObject* self)
{
    PyOverlayInteractWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<PyOverlayInteractWrapper *>(reinterpret_cast< ::Natron::Python::PyOverlayInteract *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYOVERLAYINTERACT_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isColorPickerRequired()const
            bool cppResult = const_cast<const ::PyOverlayInteractWrapper*>(cppSelf)->isColorPickerRequired();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_PyOverlayInteractFunc_isColorPickerValid(PyObject* self)
{
    PyOverlayInteractWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<PyOverlayInteractWrapper *>(reinterpret_cast< ::Natron::Python::PyOverlayInteract *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYOVERLAYINTERACT_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isColorPickerValid()const
            bool cppResult = const_cast<const ::PyOverlayInteractWrapper*>(cppSelf)->isColorPickerValid();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_Python_PyOverlayInteractFunc_keyDown(PyObject* self, PyObject* args)
{
    PyOverlayInteractWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<PyOverlayInteractWrapper *>(reinterpret_cast< ::Natron::Python::PyOverlayInteract *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYOVERLAYINTERACT_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "keyDown", 5, 5, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return {};


    // Overloaded function decisor
    // 0: PyOverlayInteract::keyDown(double,Natron::Python::Double2DTuple,QString,Qt::Key,QFlags<Qt::KeyboardModifier>)
    if (numArgs == 5
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLE2DTUPLE_IDX]), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(*PepType_SGTP(SbkPySide2_QtCoreTypes[SBK_QT_KEY_IDX])->converter, (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(*PepType_SGTP(SbkPySide2_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER_IDX])->converter, (pyArgs[4])))) {
        overloadId = 0; // keyDown(double,Natron::Python::Double2DTuple,QString,Qt::Key,QFlags<Qt::KeyboardModifier>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyOverlayInteractFunc_keyDown_TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return {};
        ::Natron::Python::Double2DTuple* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QString cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        ::Qt::Key cppArg3 = static_cast< ::Qt::Key>(0);
        pythonToCpp[3](pyArgs[3], &cppArg3);
        ::QFlags<Qt::KeyboardModifier> cppArg4 = QFlags<Qt::KeyboardModifier>(0);
        pythonToCpp[4](pyArgs[4], &cppArg4);

        if (!PyErr_Occurred()) {
            // keyDown(double,Natron::Python::Double2DTuple,QString,Qt::Key,QFlags<Qt::KeyboardModifier>)
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::Natron::Python::PyOverlayInteract::keyDown(cppArg0, *cppArg1, cppArg2, cppArg3, cppArg4) : cppSelf->keyDown(cppArg0, *cppArg1, cppArg2, cppArg3, cppArg4);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_PyOverlayInteractFunc_keyDown_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.PyOverlayInteract.keyDown");
        return {};
}

static PyObject* Sbk_Natron_Python_PyOverlayInteractFunc_keyRepeat(PyObject* self, PyObject* args)
{
    PyOverlayInteractWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<PyOverlayInteractWrapper *>(reinterpret_cast< ::Natron::Python::PyOverlayInteract *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYOVERLAYINTERACT_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "keyRepeat", 5, 5, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return {};


    // Overloaded function decisor
    // 0: PyOverlayInteract::keyRepeat(double,Natron::Python::Double2DTuple,QString,Qt::Key,QFlags<Qt::KeyboardModifier>)
    if (numArgs == 5
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLE2DTUPLE_IDX]), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(*PepType_SGTP(SbkPySide2_QtCoreTypes[SBK_QT_KEY_IDX])->converter, (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(*PepType_SGTP(SbkPySide2_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER_IDX])->converter, (pyArgs[4])))) {
        overloadId = 0; // keyRepeat(double,Natron::Python::Double2DTuple,QString,Qt::Key,QFlags<Qt::KeyboardModifier>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyOverlayInteractFunc_keyRepeat_TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return {};
        ::Natron::Python::Double2DTuple* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QString cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        ::Qt::Key cppArg3 = static_cast< ::Qt::Key>(0);
        pythonToCpp[3](pyArgs[3], &cppArg3);
        ::QFlags<Qt::KeyboardModifier> cppArg4 = QFlags<Qt::KeyboardModifier>(0);
        pythonToCpp[4](pyArgs[4], &cppArg4);

        if (!PyErr_Occurred()) {
            // keyRepeat(double,Natron::Python::Double2DTuple,QString,Qt::Key,QFlags<Qt::KeyboardModifier>)
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::Natron::Python::PyOverlayInteract::keyRepeat(cppArg0, *cppArg1, cppArg2, cppArg3, cppArg4) : cppSelf->keyRepeat(cppArg0, *cppArg1, cppArg2, cppArg3, cppArg4);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_PyOverlayInteractFunc_keyRepeat_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.PyOverlayInteract.keyRepeat");
        return {};
}

static PyObject* Sbk_Natron_Python_PyOverlayInteractFunc_keyUp(PyObject* self, PyObject* args)
{
    PyOverlayInteractWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<PyOverlayInteractWrapper *>(reinterpret_cast< ::Natron::Python::PyOverlayInteract *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYOVERLAYINTERACT_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "keyUp", 5, 5, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return {};


    // Overloaded function decisor
    // 0: PyOverlayInteract::keyUp(double,Natron::Python::Double2DTuple,QString,Qt::Key,QFlags<Qt::KeyboardModifier>)
    if (numArgs == 5
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLE2DTUPLE_IDX]), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(*PepType_SGTP(SbkPySide2_QtCoreTypes[SBK_QT_KEY_IDX])->converter, (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(*PepType_SGTP(SbkPySide2_QtCoreTypes[SBK_QFLAGS_QT_KEYBOARDMODIFIER_IDX])->converter, (pyArgs[4])))) {
        overloadId = 0; // keyUp(double,Natron::Python::Double2DTuple,QString,Qt::Key,QFlags<Qt::KeyboardModifier>)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyOverlayInteractFunc_keyUp_TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return {};
        ::Natron::Python::Double2DTuple* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QString cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        ::Qt::Key cppArg3 = static_cast< ::Qt::Key>(0);
        pythonToCpp[3](pyArgs[3], &cppArg3);
        ::QFlags<Qt::KeyboardModifier> cppArg4 = QFlags<Qt::KeyboardModifier>(0);
        pythonToCpp[4](pyArgs[4], &cppArg4);

        if (!PyErr_Occurred()) {
            // keyUp(double,Natron::Python::Double2DTuple,QString,Qt::Key,QFlags<Qt::KeyboardModifier>)
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::Natron::Python::PyOverlayInteract::keyUp(cppArg0, *cppArg1, cppArg2, cppArg3, cppArg4) : cppSelf->keyUp(cppArg0, *cppArg1, cppArg2, cppArg3, cppArg4);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_PyOverlayInteractFunc_keyUp_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.PyOverlayInteract.keyUp");
        return {};
}

static PyObject* Sbk_Natron_Python_PyOverlayInteractFunc_penDoubleClicked(PyObject* self, PyObject* args)
{
    PyOverlayInteractWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<PyOverlayInteractWrapper *>(reinterpret_cast< ::Natron::Python::PyOverlayInteract *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYOVERLAYINTERACT_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "penDoubleClicked", 5, 5, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return {};


    // Overloaded function decisor
    // 0: PyOverlayInteract::penDoubleClicked(double,Natron::Python::Double2DTuple,QString,Natron::Python::Double2DTuple,Natron::Python::Double2DTuple)
    if (numArgs == 5
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLE2DTUPLE_IDX]), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLE2DTUPLE_IDX]), (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLE2DTUPLE_IDX]), (pyArgs[4])))) {
        overloadId = 0; // penDoubleClicked(double,Natron::Python::Double2DTuple,QString,Natron::Python::Double2DTuple,Natron::Python::Double2DTuple)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyOverlayInteractFunc_penDoubleClicked_TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return {};
        ::Natron::Python::Double2DTuple* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QString cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        if (!Shiboken::Object::isValid(pyArgs[3]))
            return {};
        ::Natron::Python::Double2DTuple* cppArg3;
        pythonToCpp[3](pyArgs[3], &cppArg3);
        if (!Shiboken::Object::isValid(pyArgs[4]))
            return {};
        ::Natron::Python::Double2DTuple* cppArg4;
        pythonToCpp[4](pyArgs[4], &cppArg4);

        if (!PyErr_Occurred()) {
            // penDoubleClicked(double,Natron::Python::Double2DTuple,QString,Natron::Python::Double2DTuple,Natron::Python::Double2DTuple)
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::Natron::Python::PyOverlayInteract::penDoubleClicked(cppArg0, *cppArg1, cppArg2, *cppArg3, *cppArg4) : cppSelf->penDoubleClicked(cppArg0, *cppArg1, cppArg2, *cppArg3, *cppArg4);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_PyOverlayInteractFunc_penDoubleClicked_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.PyOverlayInteract.penDoubleClicked");
        return {};
}

static PyObject* Sbk_Natron_Python_PyOverlayInteractFunc_penDown(PyObject* self, PyObject* args)
{
    PyOverlayInteractWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<PyOverlayInteractWrapper *>(reinterpret_cast< ::Natron::Python::PyOverlayInteract *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYOVERLAYINTERACT_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "penDown", 8, 8, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5]), &(pyArgs[6]), &(pyArgs[7])))
        return {};


    // Overloaded function decisor
    // 0: PyOverlayInteract::penDown(double,Natron::Python::Double2DTuple,QString,Natron::Python::Double2DTuple,Natron::Python::Double2DTuple,double,double,Natron::PenType)
    if (numArgs == 8
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLE2DTUPLE_IDX]), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLE2DTUPLE_IDX]), (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLE2DTUPLE_IDX]), (pyArgs[4])))
        && (pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[5])))
        && (pythonToCpp[6] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[6])))
        && (pythonToCpp[7] = Shiboken::Conversions::isPythonToCppConvertible(*PepType_SGTP(SbkNatronEngineTypes[SBK_NATRON_PENTYPE_IDX])->converter, (pyArgs[7])))) {
        overloadId = 0; // penDown(double,Natron::Python::Double2DTuple,QString,Natron::Python::Double2DTuple,Natron::Python::Double2DTuple,double,double,Natron::PenType)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyOverlayInteractFunc_penDown_TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return {};
        ::Natron::Python::Double2DTuple* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QString cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        if (!Shiboken::Object::isValid(pyArgs[3]))
            return {};
        ::Natron::Python::Double2DTuple* cppArg3;
        pythonToCpp[3](pyArgs[3], &cppArg3);
        if (!Shiboken::Object::isValid(pyArgs[4]))
            return {};
        ::Natron::Python::Double2DTuple* cppArg4;
        pythonToCpp[4](pyArgs[4], &cppArg4);
        double cppArg5;
        pythonToCpp[5](pyArgs[5], &cppArg5);
        double cppArg6;
        pythonToCpp[6](pyArgs[6], &cppArg6);
        ::Natron::PenType cppArg7{Natron::ePenTypeLMB};
        pythonToCpp[7](pyArgs[7], &cppArg7);

        if (!PyErr_Occurred()) {
            // penDown(double,Natron::Python::Double2DTuple,QString,Natron::Python::Double2DTuple,Natron::Python::Double2DTuple,double,double,Natron::PenType)
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::Natron::Python::PyOverlayInteract::penDown(cppArg0, *cppArg1, cppArg2, *cppArg3, *cppArg4, cppArg5, cppArg6, cppArg7) : cppSelf->penDown(cppArg0, *cppArg1, cppArg2, *cppArg3, *cppArg4, cppArg5, cppArg6, cppArg7);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_PyOverlayInteractFunc_penDown_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.PyOverlayInteract.penDown");
        return {};
}

static PyObject* Sbk_Natron_Python_PyOverlayInteractFunc_penMotion(PyObject* self, PyObject* args)
{
    PyOverlayInteractWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<PyOverlayInteractWrapper *>(reinterpret_cast< ::Natron::Python::PyOverlayInteract *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYOVERLAYINTERACT_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "penMotion", 7, 7, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5]), &(pyArgs[6])))
        return {};


    // Overloaded function decisor
    // 0: PyOverlayInteract::penMotion(double,Natron::Python::Double2DTuple,QString,Natron::Python::Double2DTuple,Natron::Python::Double2DTuple,double,double)
    if (numArgs == 7
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLE2DTUPLE_IDX]), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLE2DTUPLE_IDX]), (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLE2DTUPLE_IDX]), (pyArgs[4])))
        && (pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[5])))
        && (pythonToCpp[6] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[6])))) {
        overloadId = 0; // penMotion(double,Natron::Python::Double2DTuple,QString,Natron::Python::Double2DTuple,Natron::Python::Double2DTuple,double,double)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyOverlayInteractFunc_penMotion_TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return {};
        ::Natron::Python::Double2DTuple* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QString cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        if (!Shiboken::Object::isValid(pyArgs[3]))
            return {};
        ::Natron::Python::Double2DTuple* cppArg3;
        pythonToCpp[3](pyArgs[3], &cppArg3);
        if (!Shiboken::Object::isValid(pyArgs[4]))
            return {};
        ::Natron::Python::Double2DTuple* cppArg4;
        pythonToCpp[4](pyArgs[4], &cppArg4);
        double cppArg5;
        pythonToCpp[5](pyArgs[5], &cppArg5);
        double cppArg6;
        pythonToCpp[6](pyArgs[6], &cppArg6);

        if (!PyErr_Occurred()) {
            // penMotion(double,Natron::Python::Double2DTuple,QString,Natron::Python::Double2DTuple,Natron::Python::Double2DTuple,double,double)
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::Natron::Python::PyOverlayInteract::penMotion(cppArg0, *cppArg1, cppArg2, *cppArg3, *cppArg4, cppArg5, cppArg6) : cppSelf->penMotion(cppArg0, *cppArg1, cppArg2, *cppArg3, *cppArg4, cppArg5, cppArg6);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_PyOverlayInteractFunc_penMotion_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.PyOverlayInteract.penMotion");
        return {};
}

static PyObject* Sbk_Natron_Python_PyOverlayInteractFunc_penUp(PyObject* self, PyObject* args)
{
    PyOverlayInteractWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<PyOverlayInteractWrapper *>(reinterpret_cast< ::Natron::Python::PyOverlayInteract *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYOVERLAYINTERACT_IDX], reinterpret_cast<SbkObject *>(self))));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "penUp", 7, 7, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5]), &(pyArgs[6])))
        return {};


    // Overloaded function decisor
    // 0: PyOverlayInteract::penUp(double,Natron::Python::Double2DTuple,QString,Natron::Python::Double2DTuple,Natron::Python::Double2DTuple,double,double)
    if (numArgs == 7
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLE2DTUPLE_IDX]), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLE2DTUPLE_IDX]), (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_DOUBLE2DTUPLE_IDX]), (pyArgs[4])))
        && (pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[5])))
        && (pythonToCpp[6] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[6])))) {
        overloadId = 0; // penUp(double,Natron::Python::Double2DTuple,QString,Natron::Python::Double2DTuple,Natron::Python::Double2DTuple,double,double)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyOverlayInteractFunc_penUp_TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return {};
        ::Natron::Python::Double2DTuple* cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QString cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        if (!Shiboken::Object::isValid(pyArgs[3]))
            return {};
        ::Natron::Python::Double2DTuple* cppArg3;
        pythonToCpp[3](pyArgs[3], &cppArg3);
        if (!Shiboken::Object::isValid(pyArgs[4]))
            return {};
        ::Natron::Python::Double2DTuple* cppArg4;
        pythonToCpp[4](pyArgs[4], &cppArg4);
        double cppArg5;
        pythonToCpp[5](pyArgs[5], &cppArg5);
        double cppArg6;
        pythonToCpp[6](pyArgs[6], &cppArg6);

        if (!PyErr_Occurred()) {
            // penUp(double,Natron::Python::Double2DTuple,QString,Natron::Python::Double2DTuple,Natron::Python::Double2DTuple,double,double)
            bool cppResult = Shiboken::Object::hasCppWrapper(reinterpret_cast<SbkObject*>(self)) ? cppSelf->::Natron::Python::PyOverlayInteract::penUp(cppArg0, *cppArg1, cppArg2, *cppArg3, *cppArg4, cppArg5, cppArg6) : cppSelf->penUp(cppArg0, *cppArg1, cppArg2, *cppArg3, *cppArg4, cppArg5, cppArg6);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_PyOverlayInteractFunc_penUp_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.PyOverlayInteract.penUp");
        return {};
}

static PyObject* Sbk_Natron_Python_PyOverlayInteractFunc_redraw(PyObject* self)
{
    PyOverlayInteractWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<PyOverlayInteractWrapper *>(reinterpret_cast< ::Natron::Python::PyOverlayInteract *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYOVERLAYINTERACT_IDX], reinterpret_cast<SbkObject *>(self))));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // redraw()
            cppSelf->redraw();
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_Natron_Python_PyOverlayInteractFunc_renderText(PyObject* self, PyObject* args)
{
    PyOverlayInteractWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<PyOverlayInteractWrapper *>(reinterpret_cast< ::Natron::Python::PyOverlayInteract *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYOVERLAYINTERACT_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0, 0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "renderText", 7, 7, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4]), &(pyArgs[5]), &(pyArgs[6])))
        return {};


    // Overloaded function decisor
    // 0: PyOverlayInteract::renderText(double,double,QString,double,double,double,double)
    if (numArgs == 7
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[4])))
        && (pythonToCpp[5] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[5])))
        && (pythonToCpp[6] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[6])))) {
        overloadId = 0; // renderText(double,double,QString,double,double,double,double)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyOverlayInteractFunc_renderText_TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        double cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        ::QString cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);
        double cppArg3;
        pythonToCpp[3](pyArgs[3], &cppArg3);
        double cppArg4;
        pythonToCpp[4](pyArgs[4], &cppArg4);
        double cppArg5;
        pythonToCpp[5](pyArgs[5], &cppArg5);
        double cppArg6;
        pythonToCpp[6](pyArgs[6], &cppArg6);

        if (!PyErr_Occurred()) {
            // renderText(double,double,QString,double,double,double,double)
            cppSelf->renderText(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4, cppArg5, cppArg6);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_PyOverlayInteractFunc_renderText_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.PyOverlayInteract.renderText");
        return {};
}

static PyObject* Sbk_Natron_Python_PyOverlayInteractFunc_setColorPickerEnabled(PyObject* self, PyObject* pyArg)
{
    PyOverlayInteractWrapper* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = static_cast<PyOverlayInteractWrapper *>(reinterpret_cast< ::Natron::Python::PyOverlayInteract *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYOVERLAYINTERACT_IDX], reinterpret_cast<SbkObject *>(self))));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: PyOverlayInteract::setColorPickerEnabled(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setColorPickerEnabled(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyOverlayInteractFunc_setColorPickerEnabled_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setColorPickerEnabled(bool)
            cppSelf->setColorPickerEnabled(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_PyOverlayInteractFunc_setColorPickerEnabled_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.PyOverlayInteract.setColorPickerEnabled");
        return {};
}

static PyMethodDef Sbk_Natron_Python_PyOverlayInteract_methods[] = {
    {"describeParameters", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyOverlayInteractFunc_describeParameters), METH_NOARGS},
    {"draw", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyOverlayInteractFunc_draw), METH_VARARGS},
    {"fetchParameter", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyOverlayInteractFunc_fetchParameter), METH_VARARGS},
    {"fetchParameters", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyOverlayInteractFunc_fetchParameters), METH_O},
    {"focusGained", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyOverlayInteractFunc_focusGained), METH_VARARGS},
    {"focusLost", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyOverlayInteractFunc_focusLost), METH_VARARGS},
    {"getColorPicker", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyOverlayInteractFunc_getColorPicker), METH_NOARGS},
    {"getHoldingEffect", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyOverlayInteractFunc_getHoldingEffect), METH_NOARGS},
    {"getPixelScale", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyOverlayInteractFunc_getPixelScale), METH_NOARGS},
    {"getSuggestedColor", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyOverlayInteractFunc_getSuggestedColor), METH_NOARGS},
    {"getViewportSize", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyOverlayInteractFunc_getViewportSize), METH_NOARGS},
    {"initInternalInteract", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyOverlayInteractFunc_initInternalInteract), METH_NOARGS},
    {"isColorPickerRequired", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyOverlayInteractFunc_isColorPickerRequired), METH_NOARGS},
    {"isColorPickerValid", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyOverlayInteractFunc_isColorPickerValid), METH_NOARGS},
    {"keyDown", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyOverlayInteractFunc_keyDown), METH_VARARGS},
    {"keyRepeat", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyOverlayInteractFunc_keyRepeat), METH_VARARGS},
    {"keyUp", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyOverlayInteractFunc_keyUp), METH_VARARGS},
    {"penDoubleClicked", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyOverlayInteractFunc_penDoubleClicked), METH_VARARGS},
    {"penDown", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyOverlayInteractFunc_penDown), METH_VARARGS},
    {"penMotion", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyOverlayInteractFunc_penMotion), METH_VARARGS},
    {"penUp", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyOverlayInteractFunc_penUp), METH_VARARGS},
    {"redraw", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyOverlayInteractFunc_redraw), METH_NOARGS},
    {"renderText", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyOverlayInteractFunc_renderText), METH_VARARGS},
    {"setColorPickerEnabled", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyOverlayInteractFunc_setColorPickerEnabled), METH_O},

    {nullptr, nullptr} // Sentinel
};

} // extern "C"

static int Sbk_Natron_Python_PyOverlayInteract_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_Natron_Python_PyOverlayInteract_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_Natron_Python_PyOverlayInteract_Type = nullptr;
static SbkObjectType *Sbk_Natron_Python_PyOverlayInteract_TypeF(void)
{
    return _Sbk_Natron_Python_PyOverlayInteract_Type;
}

static PyType_Slot Sbk_Natron_Python_PyOverlayInteract_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_Natron_Python_PyOverlayInteract_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_Natron_Python_PyOverlayInteract_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_Natron_Python_PyOverlayInteract_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        reinterpret_cast<void*>(Sbk_Natron_Python_PyOverlayInteract_Init)},
    {Py_tp_new,         reinterpret_cast<void*>(SbkObjectTpNew)},
    {0, nullptr}
};
static PyType_Spec Sbk_Natron_Python_PyOverlayInteract_spec = {
    "NatronEngine.Natron.Python.PyOverlayInteract",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Natron_Python_PyOverlayInteract_slots
};

} //extern "C"


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void PyOverlayInteract_PythonToCpp_PyOverlayInteract_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_Natron_Python_PyOverlayInteract_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_PyOverlayInteract_PythonToCpp_PyOverlayInteract_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_PyOverlayInteract_TypeF())))
        return PyOverlayInteract_PythonToCpp_PyOverlayInteract_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* PyOverlayInteract_PTR_CppToPython_PyOverlayInteract(const void* cppIn) {
    auto pyOut = reinterpret_cast<PyObject*>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::Natron::Python::PyOverlayInteract *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_Natron_Python_PyOverlayInteract_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *Natron_Python_PyOverlayInteract_SignatureStrings[] = {
    "NatronEngine.Natron.Python.PyOverlayInteract()",
    "NatronEngine.Natron.Python.PyOverlayInteract.describeParameters()->QMap",
    "NatronEngine.Natron.Python.PyOverlayInteract.draw(time:double,renderScale:NatronEngine.Natron.Python.Double2DTuple,view:QString)",
    "NatronEngine.Natron.Python.PyOverlayInteract.fetchParameter(params:QMap,role:QString,type:QString,nDims:int,optional:bool)->NatronEngine.Natron.Python.Param",
    "NatronEngine.Natron.Python.PyOverlayInteract.fetchParameters(params:QMap)",
    "NatronEngine.Natron.Python.PyOverlayInteract.focusGained(time:double,renderScale:NatronEngine.Natron.Python.Double2DTuple,view:QString)->bool",
    "NatronEngine.Natron.Python.PyOverlayInteract.focusLost(time:double,renderScale:NatronEngine.Natron.Python.Double2DTuple,view:QString)->bool",
    "NatronEngine.Natron.Python.PyOverlayInteract.getColorPicker()->NatronEngine.Natron.Python.ColorTuple",
    "NatronEngine.Natron.Python.PyOverlayInteract.getHoldingEffect()->NatronEngine.Natron.Python.Effect",
    "NatronEngine.Natron.Python.PyOverlayInteract.getPixelScale()->NatronEngine.Natron.Python.Double2DTuple",
    "NatronEngine.Natron.Python.PyOverlayInteract.getSuggestedColor(color:NatronEngine.Natron.Python.ColorTuple)->bool",
    "NatronEngine.Natron.Python.PyOverlayInteract.getViewportSize()->NatronEngine.Natron.Python.Int2DTuple",
    "NatronEngine.Natron.Python.PyOverlayInteract.initInternalInteract()",
    "NatronEngine.Natron.Python.PyOverlayInteract.isColorPickerRequired()->bool",
    "NatronEngine.Natron.Python.PyOverlayInteract.isColorPickerValid()->bool",
    "NatronEngine.Natron.Python.PyOverlayInteract.keyDown(time:double,renderScale:NatronEngine.Natron.Python.Double2DTuple,view:QString,key:PySide2.QtCore.Qt.Key,modifiers:PySide2.QtCore.Qt.KeyboardModifiers)->bool",
    "NatronEngine.Natron.Python.PyOverlayInteract.keyRepeat(time:double,renderScale:NatronEngine.Natron.Python.Double2DTuple,view:QString,key:PySide2.QtCore.Qt.Key,modifiers:PySide2.QtCore.Qt.KeyboardModifiers)->bool",
    "NatronEngine.Natron.Python.PyOverlayInteract.keyUp(time:double,renderScale:NatronEngine.Natron.Python.Double2DTuple,view:QString,key:PySide2.QtCore.Qt.Key,modifiers:PySide2.QtCore.Qt.KeyboardModifiers)->bool",
    "NatronEngine.Natron.Python.PyOverlayInteract.penDoubleClicked(time:double,renderScale:NatronEngine.Natron.Python.Double2DTuple,view:QString,viewportPos:NatronEngine.Natron.Python.Double2DTuple,pos:NatronEngine.Natron.Python.Double2DTuple)->bool",
    "NatronEngine.Natron.Python.PyOverlayInteract.penDown(time:double,renderScale:NatronEngine.Natron.Python.Double2DTuple,view:QString,viewportPos:NatronEngine.Natron.Python.Double2DTuple,pos:NatronEngine.Natron.Python.Double2DTuple,pressure:double,timestamp:double,pen:NatronEngine.Natron.PenType)->bool",
    "NatronEngine.Natron.Python.PyOverlayInteract.penMotion(time:double,renderScale:NatronEngine.Natron.Python.Double2DTuple,view:QString,viewportPos:NatronEngine.Natron.Python.Double2DTuple,pos:NatronEngine.Natron.Python.Double2DTuple,pressure:double,timestamp:double)->bool",
    "NatronEngine.Natron.Python.PyOverlayInteract.penUp(time:double,renderScale:NatronEngine.Natron.Python.Double2DTuple,view:QString,viewportPos:NatronEngine.Natron.Python.Double2DTuple,pos:NatronEngine.Natron.Python.Double2DTuple,pressure:double,timestamp:double)->bool",
    "NatronEngine.Natron.Python.PyOverlayInteract.redraw()",
    "NatronEngine.Natron.Python.PyOverlayInteract.renderText(x:double,y:double,string:QString,r:double,g:double,b:double,a:double)",
    "NatronEngine.Natron.Python.PyOverlayInteract.setColorPickerEnabled(enabled:bool)",
    nullptr}; // Sentinel

void init_Natron_Python_PyOverlayInteract(PyObject* module)
{
    _Sbk_Natron_Python_PyOverlayInteract_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "PyOverlayInteract",
        "Natron::Python::PyOverlayInteract*",
        &Sbk_Natron_Python_PyOverlayInteract_spec,
        Natron_Python_PyOverlayInteract_SignatureStrings,
        &Shiboken::callCppDestructor< ::Natron::Python::PyOverlayInteract >,
        0,
        0,
        0    );
    
    SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYOVERLAYINTERACT_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_PyOverlayInteract_TypeF());

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_Natron_Python_PyOverlayInteract_TypeF(),
        PyOverlayInteract_PythonToCpp_PyOverlayInteract_PTR,
        is_PyOverlayInteract_PythonToCpp_PyOverlayInteract_PTR_Convertible,
        PyOverlayInteract_PTR_CppToPython_PyOverlayInteract);

    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::PyOverlayInteract");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::PyOverlayInteract*");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::PyOverlayInteract&");
    Shiboken::Conversions::registerConverterName(converter, "Python::PyOverlayInteract");
    Shiboken::Conversions::registerConverterName(converter, "Python::PyOverlayInteract*");
    Shiboken::Conversions::registerConverterName(converter, "Python::PyOverlayInteract&");
    Shiboken::Conversions::registerConverterName(converter, "PyOverlayInteract");
    Shiboken::Conversions::registerConverterName(converter, "PyOverlayInteract*");
    Shiboken::Conversions::registerConverterName(converter, "PyOverlayInteract&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Natron::Python::PyOverlayInteract).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::PyOverlayInteractWrapper).name());



    PyOverlayInteractWrapper::pysideInitQtMetaTypes();
}
