
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
#include "natron_python_pycornerpinoverlayinteract_wrapper.h"

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

void PyCornerPinOverlayInteractWrapper::pysideInitQtMetaTypes()
{
}

PyCornerPinOverlayInteractWrapper::PyCornerPinOverlayInteractWrapper() : Natron::Python::PyCornerPinOverlayInteract()
{
    // ... middle
}

std::map<QString,Natron::Python::PyOverlayParamDesc > PyCornerPinOverlayInteractWrapper::describeParameters() const
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PyCornerPinOverlayInteract.describeParameters", "map", Py_TYPE(pyResult)->tp_name);
        return {};
    }
    ::std::map<QString,Natron::Python::PyOverlayParamDesc > cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

void PyCornerPinOverlayInteractWrapper::draw(double time, const Natron::Python::Double2DTuple & renderScale, QString view)
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

void PyCornerPinOverlayInteractWrapper::fetchParameters(const std::map<QString,QString > & params)
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

bool PyCornerPinOverlayInteractWrapper::focusGained(double time, const Natron::Python::Double2DTuple & renderScale, const QString & view)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PyCornerPinOverlayInteract.focusGained", "bool", Py_TYPE(pyResult)->tp_name);
        return false;
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool PyCornerPinOverlayInteractWrapper::focusLost(double time, const Natron::Python::Double2DTuple & renderScale, const QString & view)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PyCornerPinOverlayInteract.focusLost", "bool", Py_TYPE(pyResult)->tp_name);
        return false;
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool PyCornerPinOverlayInteractWrapper::keyDown(double time, const Natron::Python::Double2DTuple & renderScale, const QString & view, Qt::Key key, const QFlags<Qt::KeyboardModifier> & modifiers)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PyCornerPinOverlayInteract.keyDown", "bool", Py_TYPE(pyResult)->tp_name);
        return false;
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool PyCornerPinOverlayInteractWrapper::keyRepeat(double time, const Natron::Python::Double2DTuple & renderScale, const QString & view, Qt::Key key, const QFlags<Qt::KeyboardModifier> & modifiers)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PyCornerPinOverlayInteract.keyRepeat", "bool", Py_TYPE(pyResult)->tp_name);
        return false;
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool PyCornerPinOverlayInteractWrapper::keyUp(double time, const Natron::Python::Double2DTuple & renderScale, const QString & view, Qt::Key key, const QFlags<Qt::KeyboardModifier> & modifiers)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PyCornerPinOverlayInteract.keyUp", "bool", Py_TYPE(pyResult)->tp_name);
        return false;
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool PyCornerPinOverlayInteractWrapper::penDoubleClicked(double time, const Natron::Python::Double2DTuple & renderScale, const QString & view, const Natron::Python::Double2DTuple & viewportPos, const Natron::Python::Double2DTuple & pos)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PyCornerPinOverlayInteract.penDoubleClicked", "bool", Py_TYPE(pyResult)->tp_name);
        return false;
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool PyCornerPinOverlayInteractWrapper::penDown(double time, const Natron::Python::Double2DTuple & renderScale, const QString & view, const Natron::Python::Double2DTuple & viewportPos, const Natron::Python::Double2DTuple & pos, double pressure, double timestamp, Natron::PenType pen)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PyCornerPinOverlayInteract.penDown", "bool", Py_TYPE(pyResult)->tp_name);
        return false;
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool PyCornerPinOverlayInteractWrapper::penMotion(double time, const Natron::Python::Double2DTuple & renderScale, const QString & view, const Natron::Python::Double2DTuple & viewportPos, const Natron::Python::Double2DTuple & pos, double pressure, double timestamp)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PyCornerPinOverlayInteract.penMotion", "bool", Py_TYPE(pyResult)->tp_name);
        return false;
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

bool PyCornerPinOverlayInteractWrapper::penUp(double time, const Natron::Python::Double2DTuple & renderScale, const QString & view, const Natron::Python::Double2DTuple & viewportPos, const Natron::Python::Double2DTuple & pos, double pressure, double timestamp)
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
        Shiboken::warning(PyExc_RuntimeWarning, 2, "Invalid return value in function %s, expected %s, got %s.", "PyCornerPinOverlayInteract.penUp", "bool", Py_TYPE(pyResult)->tp_name);
        return false;
    }
    bool cppResult;
    pythonToCpp(pyResult, &cppResult);
    return cppResult;
}

PyCornerPinOverlayInteractWrapper::~PyCornerPinOverlayInteractWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_Natron_Python_PyCornerPinOverlayInteract_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::Natron::Python::PyCornerPinOverlayInteract >()))
        return -1;

    ::PyCornerPinOverlayInteractWrapper* cptr{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // PyCornerPinOverlayInteract()
            cptr = new ::PyCornerPinOverlayInteractWrapper();
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::Natron::Python::PyCornerPinOverlayInteract >(), cptr)) {
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

static PyMethodDef Sbk_Natron_Python_PyCornerPinOverlayInteract_methods[] = {

    {nullptr, nullptr} // Sentinel
};

} // extern "C"

static int Sbk_Natron_Python_PyCornerPinOverlayInteract_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_Natron_Python_PyCornerPinOverlayInteract_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_Natron_Python_PyCornerPinOverlayInteract_Type = nullptr;
static SbkObjectType *Sbk_Natron_Python_PyCornerPinOverlayInteract_TypeF(void)
{
    return _Sbk_Natron_Python_PyCornerPinOverlayInteract_Type;
}

static PyType_Slot Sbk_Natron_Python_PyCornerPinOverlayInteract_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_Natron_Python_PyCornerPinOverlayInteract_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_Natron_Python_PyCornerPinOverlayInteract_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_Natron_Python_PyCornerPinOverlayInteract_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        reinterpret_cast<void*>(Sbk_Natron_Python_PyCornerPinOverlayInteract_Init)},
    {Py_tp_new,         reinterpret_cast<void*>(SbkObjectTpNew)},
    {0, nullptr}
};
static PyType_Spec Sbk_Natron_Python_PyCornerPinOverlayInteract_spec = {
    "NatronEngine.Natron.Python.PyCornerPinOverlayInteract",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Natron_Python_PyCornerPinOverlayInteract_slots
};

} //extern "C"

static void* Sbk_Natron_Python_PyCornerPinOverlayInteract_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType< ::Natron::Python::PyOverlayInteract >()))
        return dynamic_cast< ::Natron::Python::PyCornerPinOverlayInteract*>(reinterpret_cast< ::Natron::Python::PyOverlayInteract*>(cptr));
    return {};
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void PyCornerPinOverlayInteract_PythonToCpp_PyCornerPinOverlayInteract_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_Natron_Python_PyCornerPinOverlayInteract_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_PyCornerPinOverlayInteract_PythonToCpp_PyCornerPinOverlayInteract_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_PyCornerPinOverlayInteract_TypeF())))
        return PyCornerPinOverlayInteract_PythonToCpp_PyCornerPinOverlayInteract_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* PyCornerPinOverlayInteract_PTR_CppToPython_PyCornerPinOverlayInteract(const void* cppIn) {
    auto pyOut = reinterpret_cast<PyObject*>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::Natron::Python::PyCornerPinOverlayInteract *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_Natron_Python_PyCornerPinOverlayInteract_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *Natron_Python_PyCornerPinOverlayInteract_SignatureStrings[] = {
    "NatronEngine.Natron.Python.PyCornerPinOverlayInteract()",
    nullptr}; // Sentinel

void init_Natron_Python_PyCornerPinOverlayInteract(PyObject* module)
{
    _Sbk_Natron_Python_PyCornerPinOverlayInteract_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "PyCornerPinOverlayInteract",
        "Natron::Python::PyCornerPinOverlayInteract*",
        &Sbk_Natron_Python_PyCornerPinOverlayInteract_spec,
        Natron_Python_PyCornerPinOverlayInteract_SignatureStrings,
        &Shiboken::callCppDestructor< ::Natron::Python::PyCornerPinOverlayInteract >,
        reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYOVERLAYINTERACT_IDX]),
        0,
        0    );
    
    SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYCORNERPINOVERLAYINTERACT_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_Natron_Python_PyCornerPinOverlayInteract_TypeF());

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_Natron_Python_PyCornerPinOverlayInteract_TypeF(),
        PyCornerPinOverlayInteract_PythonToCpp_PyCornerPinOverlayInteract_PTR,
        is_PyCornerPinOverlayInteract_PythonToCpp_PyCornerPinOverlayInteract_PTR_Convertible,
        PyCornerPinOverlayInteract_PTR_CppToPython_PyCornerPinOverlayInteract);

    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::PyCornerPinOverlayInteract");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::PyCornerPinOverlayInteract*");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::PyCornerPinOverlayInteract&");
    Shiboken::Conversions::registerConverterName(converter, "Python::PyCornerPinOverlayInteract");
    Shiboken::Conversions::registerConverterName(converter, "Python::PyCornerPinOverlayInteract*");
    Shiboken::Conversions::registerConverterName(converter, "Python::PyCornerPinOverlayInteract&");
    Shiboken::Conversions::registerConverterName(converter, "PyCornerPinOverlayInteract");
    Shiboken::Conversions::registerConverterName(converter, "PyCornerPinOverlayInteract*");
    Shiboken::Conversions::registerConverterName(converter, "PyCornerPinOverlayInteract&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Natron::Python::PyCornerPinOverlayInteract).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::PyCornerPinOverlayInteractWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_Natron_Python_PyCornerPinOverlayInteract_TypeF(), &Sbk_Natron_Python_PyCornerPinOverlayInteract_typeDiscovery);


    PyCornerPinOverlayInteractWrapper::pysideInitQtMetaTypes();
}
