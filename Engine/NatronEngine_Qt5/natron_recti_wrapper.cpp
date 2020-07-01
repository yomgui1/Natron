
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
#include "natron_recti_wrapper.h"

// inner classes

// Extra includes
#include <RectI.h>


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

void RectIWrapper::pysideInitQtMetaTypes()
{
}

RectIWrapper::RectIWrapper() : Natron::RectI()
{
    // ... middle
}

RectIWrapper::RectIWrapper(int x1_, int y1_, int x2_, int y2_) : Natron::RectI(x1_, y1_, x2_, y2_)
{
    // ... middle
}

RectIWrapper::~RectIWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_Natron_RectI_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::Natron::RectI >()))
        return -1;

    ::RectIWrapper* cptr{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 2 || numArgs == 3)
        goto Sbk_Natron_RectI_Init_TypeError;

    if (!PyArg_UnpackTuple(args, "RectI", 0, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return -1;


    // Overloaded function decisor
    // 0: RectI::RectI()
    // 1: RectI::RectI(Natron::RectI)
    // 2: RectI::RectI(int,int,int,int)
    if (numArgs == 0) {
        overloadId = 0; // RectI()
    } else if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
        overloadId = 2; // RectI(int,int,int,int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX]), (pyArgs[0])))) {
        overloadId = 1; // RectI(Natron::RectI)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_RectI_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // RectI()
        {

            if (!PyErr_Occurred()) {
                // RectI()
                cptr = new ::RectIWrapper();
            }
            break;
        }
        case 1: // RectI(const Natron::RectI & b)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::Natron::RectI* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // RectI(Natron::RectI)
                cptr = new ::RectIWrapper(*cppArg0);
            }
            break;
        }
        case 2: // RectI(int x1_, int y1_, int x2_, int y2_)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // RectI(int,int,int,int)
                cptr = new ::RectIWrapper(cppArg0, cppArg1, cppArg2, cppArg3);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::Natron::RectI >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_Natron_RectI_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    if (Shiboken::BindingManager::instance().hasWrapper(cptr)) {
        Shiboken::BindingManager::instance().releaseWrapper(Shiboken::BindingManager::instance().retrieveWrapper(cptr));
    }
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_Natron_RectI_Init_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.RectI");
        return -1;
}

static PyObject* Sbk_Natron_RectIFunc_bottom(PyObject* self)
{
    ::Natron::RectI* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::RectI *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // bottom()const
            int cppResult = const_cast<const ::Natron::RectI*>(cppSelf)->bottom();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_RectIFunc_clear(PyObject* self)
{
    ::Natron::RectI* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::RectI *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX], reinterpret_cast<SbkObject *>(self)));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // clear()
            cppSelf->clear();
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_Natron_RectIFunc_contains(PyObject* self, PyObject* args)
{
    ::Natron::RectI* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::RectI *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "contains", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: RectI::contains(Natron::RectI)const
    // 1: RectI::contains(double,double)const
    // 2: RectI::contains(int,int)const
    if (numArgs == 2
        && PyFloat_Check(pyArgs[0]) && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))) {
        overloadId = 1; // contains(double,double)const
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 2; // contains(int,int)const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX]), (pyArgs[0])))) {
        overloadId = 0; // contains(Natron::RectI)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_RectIFunc_contains_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // contains(const Natron::RectI & other) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return {};
            ::Natron::RectI* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // contains(Natron::RectI)const
                bool cppResult = const_cast<const ::Natron::RectI*>(cppSelf)->contains(*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // contains(double x, double y) const
        {
            double cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            double cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // contains(double,double)const
                bool cppResult = const_cast<const ::Natron::RectI*>(cppSelf)->contains(cppArg0, cppArg1);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 2: // contains(int x, int y) const
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // contains(int,int)const
                bool cppResult = const_cast<const ::Natron::RectI*>(cppSelf)->contains(cppArg0, cppArg1);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_RectIFunc_contains_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.RectI.contains");
        return {};
}

static PyObject* Sbk_Natron_RectIFunc_height(PyObject* self)
{
    ::Natron::RectI* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::RectI *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // height()const
            int cppResult = const_cast<const ::Natron::RectI*>(cppSelf)->height();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_RectIFunc_intersect(PyObject* self, PyObject* args)
{
    ::Natron::RectI* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::RectI *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 3 || numArgs == 4)
        goto Sbk_Natron_RectIFunc_intersect_TypeError;

    if (!PyArg_UnpackTuple(args, "intersect", 2, 5, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return {};


    // Overloaded function decisor
    // 0: RectI::intersect(Natron::RectI,Natron::RectI*)const
    // 1: RectI::intersect(int,int,int,int,Natron::RectI*)const
    if (numArgs == 5
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX]), (pyArgs[4])))) {
        overloadId = 1; // intersect(int,int,int,int,Natron::RectI*)const
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX]), (pyArgs[1])))) {
        overloadId = 0; // intersect(Natron::RectI,Natron::RectI*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_RectIFunc_intersect_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // intersect(const Natron::RectI & r, Natron::RectI * intersection) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return {};
            ::Natron::RectI* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return {};
            ::Natron::RectI* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // intersect(Natron::RectI,Natron::RectI*)const
                bool cppResult = const_cast<const ::Natron::RectI*>(cppSelf)->intersect(*cppArg0, cppArg1);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // intersect(int x1_, int y1_, int x2_, int y2_, Natron::RectI * intersection) const
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            if (!Shiboken::Object::isValid(pyArgs[4]))
                return {};
            ::Natron::RectI* cppArg4;
            pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // intersect(int,int,int,int,Natron::RectI*)const
                bool cppResult = const_cast<const ::Natron::RectI*>(cppSelf)->intersect(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_RectIFunc_intersect_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.RectI.intersect");
        return {};
}

static PyObject* Sbk_Natron_RectIFunc_intersects(PyObject* self, PyObject* args)
{
    ::Natron::RectI* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::RectI *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 2 || numArgs == 3)
        goto Sbk_Natron_RectIFunc_intersects_TypeError;

    if (!PyArg_UnpackTuple(args, "intersects", 1, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return {};


    // Overloaded function decisor
    // 0: RectI::intersects(Natron::RectI)const
    // 1: RectI::intersects(int,int,int,int)const
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
        overloadId = 1; // intersects(int,int,int,int)const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX]), (pyArgs[0])))) {
        overloadId = 0; // intersects(Natron::RectI)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_RectIFunc_intersects_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // intersects(const Natron::RectI & r) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return {};
            ::Natron::RectI* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // intersects(Natron::RectI)const
                bool cppResult = const_cast<const ::Natron::RectI*>(cppSelf)->intersects(*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // intersects(int x1_, int y1_, int x2_, int y2_) const
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // intersects(int,int,int,int)const
                bool cppResult = const_cast<const ::Natron::RectI*>(cppSelf)->intersects(cppArg0, cppArg1, cppArg2, cppArg3);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_RectIFunc_intersects_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.RectI.intersects");
        return {};
}

static PyObject* Sbk_Natron_RectIFunc_isInfinite(PyObject* self)
{
    ::Natron::RectI* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::RectI *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isInfinite()const
            bool cppResult = const_cast<const ::Natron::RectI*>(cppSelf)->isInfinite();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_RectIFunc_isNull(PyObject* self)
{
    ::Natron::RectI* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::RectI *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isNull()const
            bool cppResult = const_cast<const ::Natron::RectI*>(cppSelf)->isNull();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_RectIFunc_left(PyObject* self)
{
    ::Natron::RectI* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::RectI *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // left()const
            int cppResult = const_cast<const ::Natron::RectI*>(cppSelf)->left();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_RectIFunc_merge(PyObject* self, PyObject* args)
{
    ::Natron::RectI* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::RectI *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 2 || numArgs == 3)
        goto Sbk_Natron_RectIFunc_merge_TypeError;

    if (!PyArg_UnpackTuple(args, "merge", 1, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return {};


    // Overloaded function decisor
    // 0: RectI::merge(Natron::RectI)
    // 1: RectI::merge(int,int,int,int)
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
        overloadId = 1; // merge(int,int,int,int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX]), (pyArgs[0])))) {
        overloadId = 0; // merge(Natron::RectI)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_RectIFunc_merge_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // merge(const Natron::RectI & box)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return {};
            ::Natron::RectI* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // merge(Natron::RectI)
                cppSelf->merge(*cppArg0);
            }
            break;
        }
        case 1: // merge(int x1_, int y1_, int x2_, int y2_)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // merge(int,int,int,int)
                cppSelf->merge(cppArg0, cppArg1, cppArg2, cppArg3);
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_RectIFunc_merge_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.RectI.merge");
        return {};
}

static PyObject* Sbk_Natron_RectIFunc_right(PyObject* self)
{
    ::Natron::RectI* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::RectI *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // right()const
            int cppResult = const_cast<const ::Natron::RectI*>(cppSelf)->right();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_RectIFunc_roundToTileSize(PyObject* self, PyObject* args)
{
    ::Natron::RectI* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::RectI *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "roundToTileSize", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: RectI::roundToTileSize(int,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // roundToTileSize(int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_RectIFunc_roundToTileSize_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // roundToTileSize(int,int)
            cppSelf->roundToTileSize(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_RectIFunc_roundToTileSize_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.RectI.roundToTileSize");
        return {};
}

static PyObject* Sbk_Natron_RectIFunc_set(PyObject* self, PyObject* args)
{
    ::Natron::RectI* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::RectI *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 2 || numArgs == 3)
        goto Sbk_Natron_RectIFunc_set_TypeError;

    if (!PyArg_UnpackTuple(args, "set", 1, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return {};


    // Overloaded function decisor
    // 0: RectI::set(Natron::RectI)
    // 1: RectI::set(int,int,int,int)
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[3])))) {
        overloadId = 1; // set(int,int,int,int)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX]), (pyArgs[0])))) {
        overloadId = 0; // set(Natron::RectI)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_RectIFunc_set_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // set(const Natron::RectI & b)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return {};
            ::Natron::RectI* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // set(Natron::RectI)
                cppSelf->set(*cppArg0);
            }
            break;
        }
        case 1: // set(int x1_, int y1_, int x2_, int y2_)
        {
            int cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            int cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            int cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            int cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // set(int,int,int,int)
                cppSelf->set(cppArg0, cppArg1, cppArg2, cppArg3);
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_RectIFunc_set_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.RectI.set");
        return {};
}

static PyObject* Sbk_Natron_RectIFunc_set_bottom(PyObject* self, PyObject* pyArg)
{
    ::Natron::RectI* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::RectI *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: RectI::set_bottom(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // set_bottom(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_RectIFunc_set_bottom_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // set_bottom(int)
            cppSelf->set_bottom(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_RectIFunc_set_bottom_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.RectI.set_bottom");
        return {};
}

static PyObject* Sbk_Natron_RectIFunc_set_left(PyObject* self, PyObject* pyArg)
{
    ::Natron::RectI* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::RectI *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: RectI::set_left(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // set_left(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_RectIFunc_set_left_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // set_left(int)
            cppSelf->set_left(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_RectIFunc_set_left_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.RectI.set_left");
        return {};
}

static PyObject* Sbk_Natron_RectIFunc_set_right(PyObject* self, PyObject* pyArg)
{
    ::Natron::RectI* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::RectI *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: RectI::set_right(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // set_right(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_RectIFunc_set_right_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // set_right(int)
            cppSelf->set_right(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_RectIFunc_set_right_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.RectI.set_right");
        return {};
}

static PyObject* Sbk_Natron_RectIFunc_set_top(PyObject* self, PyObject* pyArg)
{
    ::Natron::RectI* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::RectI *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: RectI::set_top(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // set_top(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_RectIFunc_set_top_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // set_top(int)
            cppSelf->set_top(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_RectIFunc_set_top_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.RectI.set_top");
        return {};
}

static PyObject* Sbk_Natron_RectIFunc_top(PyObject* self)
{
    ::Natron::RectI* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::RectI *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // top()const
            int cppResult = const_cast<const ::Natron::RectI*>(cppSelf)->top();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_RectIFunc_translate(PyObject* self, PyObject* args)
{
    ::Natron::RectI* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::RectI *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "translate", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: RectI::translate(int,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // translate(int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_RectIFunc_translate_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // translate(int,int)
            cppSelf->translate(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_RectIFunc_translate_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.RectI.translate");
        return {};
}

static PyObject* Sbk_Natron_RectIFunc_width(PyObject* self)
{
    ::Natron::RectI* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::RectI *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // width()const
            int cppResult = const_cast<const ::Natron::RectI*>(cppSelf)->width();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyMethodDef Sbk_Natron_RectI_methods[] = {
    {"bottom", reinterpret_cast<PyCFunction>(Sbk_Natron_RectIFunc_bottom), METH_NOARGS},
    {"clear", reinterpret_cast<PyCFunction>(Sbk_Natron_RectIFunc_clear), METH_NOARGS},
    {"contains", reinterpret_cast<PyCFunction>(Sbk_Natron_RectIFunc_contains), METH_VARARGS},
    {"height", reinterpret_cast<PyCFunction>(Sbk_Natron_RectIFunc_height), METH_NOARGS},
    {"intersect", reinterpret_cast<PyCFunction>(Sbk_Natron_RectIFunc_intersect), METH_VARARGS},
    {"intersects", reinterpret_cast<PyCFunction>(Sbk_Natron_RectIFunc_intersects), METH_VARARGS},
    {"isInfinite", reinterpret_cast<PyCFunction>(Sbk_Natron_RectIFunc_isInfinite), METH_NOARGS},
    {"isNull", reinterpret_cast<PyCFunction>(Sbk_Natron_RectIFunc_isNull), METH_NOARGS},
    {"left", reinterpret_cast<PyCFunction>(Sbk_Natron_RectIFunc_left), METH_NOARGS},
    {"merge", reinterpret_cast<PyCFunction>(Sbk_Natron_RectIFunc_merge), METH_VARARGS},
    {"right", reinterpret_cast<PyCFunction>(Sbk_Natron_RectIFunc_right), METH_NOARGS},
    {"roundToTileSize", reinterpret_cast<PyCFunction>(Sbk_Natron_RectIFunc_roundToTileSize), METH_VARARGS},
    {"set", reinterpret_cast<PyCFunction>(Sbk_Natron_RectIFunc_set), METH_VARARGS},
    {"set_bottom", reinterpret_cast<PyCFunction>(Sbk_Natron_RectIFunc_set_bottom), METH_O},
    {"set_left", reinterpret_cast<PyCFunction>(Sbk_Natron_RectIFunc_set_left), METH_O},
    {"set_right", reinterpret_cast<PyCFunction>(Sbk_Natron_RectIFunc_set_right), METH_O},
    {"set_top", reinterpret_cast<PyCFunction>(Sbk_Natron_RectIFunc_set_top), METH_O},
    {"top", reinterpret_cast<PyCFunction>(Sbk_Natron_RectIFunc_top), METH_NOARGS},
    {"translate", reinterpret_cast<PyCFunction>(Sbk_Natron_RectIFunc_translate), METH_VARARGS},
    {"width", reinterpret_cast<PyCFunction>(Sbk_Natron_RectIFunc_width), METH_NOARGS},

    {nullptr, nullptr} // Sentinel
};

static PyObject* Sbk_Natron_RectI_get_x1(PyObject* self, void*)
{
    ::Natron::RectI* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return nullptr;
    cppSelf = reinterpret_cast< ::Natron::RectI *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX], reinterpret_cast<SbkObject *>(self)));
    int cppOut_local = cppSelf->x1;
    PyObject* pyOut = {};
    pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppOut_local);
    return pyOut;
}
static int Sbk_Natron_RectI_set_x1(PyObject* self, PyObject* pyIn, void*)
{
    ::Natron::RectI* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = reinterpret_cast< ::Natron::RectI *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX], reinterpret_cast<SbkObject *>(self)));
    if (pyIn == nullptr) {
        PyErr_SetString(PyExc_TypeError, "'x1' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp{nullptr};
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'x1', 'int' or convertible type expected");
        return -1;
    }

    int cppOut_local = cppSelf->x1;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->x1 = cppOut_local;

    return 0;
}

static PyObject* Sbk_Natron_RectI_get_y1(PyObject* self, void*)
{
    ::Natron::RectI* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return nullptr;
    cppSelf = reinterpret_cast< ::Natron::RectI *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX], reinterpret_cast<SbkObject *>(self)));
    int cppOut_local = cppSelf->y1;
    PyObject* pyOut = {};
    pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppOut_local);
    return pyOut;
}
static int Sbk_Natron_RectI_set_y1(PyObject* self, PyObject* pyIn, void*)
{
    ::Natron::RectI* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = reinterpret_cast< ::Natron::RectI *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX], reinterpret_cast<SbkObject *>(self)));
    if (pyIn == nullptr) {
        PyErr_SetString(PyExc_TypeError, "'y1' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp{nullptr};
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'y1', 'int' or convertible type expected");
        return -1;
    }

    int cppOut_local = cppSelf->y1;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->y1 = cppOut_local;

    return 0;
}

static PyObject* Sbk_Natron_RectI_get_x2(PyObject* self, void*)
{
    ::Natron::RectI* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return nullptr;
    cppSelf = reinterpret_cast< ::Natron::RectI *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX], reinterpret_cast<SbkObject *>(self)));
    int cppOut_local = cppSelf->x2;
    PyObject* pyOut = {};
    pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppOut_local);
    return pyOut;
}
static int Sbk_Natron_RectI_set_x2(PyObject* self, PyObject* pyIn, void*)
{
    ::Natron::RectI* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = reinterpret_cast< ::Natron::RectI *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX], reinterpret_cast<SbkObject *>(self)));
    if (pyIn == nullptr) {
        PyErr_SetString(PyExc_TypeError, "'x2' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp{nullptr};
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'x2', 'int' or convertible type expected");
        return -1;
    }

    int cppOut_local = cppSelf->x2;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->x2 = cppOut_local;

    return 0;
}

static PyObject* Sbk_Natron_RectI_get_y2(PyObject* self, void*)
{
    ::Natron::RectI* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return nullptr;
    cppSelf = reinterpret_cast< ::Natron::RectI *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX], reinterpret_cast<SbkObject *>(self)));
    int cppOut_local = cppSelf->y2;
    PyObject* pyOut = {};
    pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppOut_local);
    return pyOut;
}
static int Sbk_Natron_RectI_set_y2(PyObject* self, PyObject* pyIn, void*)
{
    ::Natron::RectI* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = reinterpret_cast< ::Natron::RectI *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX], reinterpret_cast<SbkObject *>(self)));
    if (pyIn == nullptr) {
        PyErr_SetString(PyExc_TypeError, "'y2' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp{nullptr};
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'y2', 'int' or convertible type expected");
        return -1;
    }

    int cppOut_local = cppSelf->y2;
    pythonToCpp(pyIn, &cppOut_local);
    cppSelf->y2 = cppOut_local;

    return 0;
}

// Getters and Setters for RectI
static PyGetSetDef Sbk_Natron_RectI_getsetlist[] = {
    {const_cast<char*>("x1"), Sbk_Natron_RectI_get_x1, Sbk_Natron_RectI_set_x1},
    {const_cast<char*>("y1"), Sbk_Natron_RectI_get_y1, Sbk_Natron_RectI_set_y1},
    {const_cast<char*>("x2"), Sbk_Natron_RectI_get_x2, Sbk_Natron_RectI_set_x2},
    {const_cast<char*>("y2"), Sbk_Natron_RectI_get_y2, Sbk_Natron_RectI_set_y2},
    {nullptr} // Sentinel
};

} // extern "C"

static int Sbk_Natron_RectI_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_Natron_RectI_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_Natron_RectI_Type = nullptr;
static SbkObjectType *Sbk_Natron_RectI_TypeF(void)
{
    return _Sbk_Natron_RectI_Type;
}

static PyType_Slot Sbk_Natron_RectI_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_Natron_RectI_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_Natron_RectI_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_Natron_RectI_methods)},
    {Py_tp_getset,      reinterpret_cast<void*>(Sbk_Natron_RectI_getsetlist)},
    {Py_tp_init,        reinterpret_cast<void*>(Sbk_Natron_RectI_Init)},
    {Py_tp_new,         reinterpret_cast<void*>(SbkObjectTpNew)},
    {0, nullptr}
};
static PyType_Spec Sbk_Natron_RectI_spec = {
    "NatronEngine.Natron.RectI",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Natron_RectI_slots
};

} //extern "C"


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void RectI_PythonToCpp_RectI_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_Natron_RectI_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_RectI_PythonToCpp_RectI_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_Natron_RectI_TypeF())))
        return RectI_PythonToCpp_RectI_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* RectI_PTR_CppToPython_RectI(const void* cppIn) {
    auto pyOut = reinterpret_cast<PyObject*>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::Natron::RectI *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_Natron_RectI_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *Natron_RectI_SignatureStrings[] = {
    "2:NatronEngine.Natron.RectI()",
    "1:NatronEngine.Natron.RectI(b:NatronEngine.Natron.RectI)",
    "0:NatronEngine.Natron.RectI(x1_:int,y1_:int,x2_:int,y2_:int)",
    "NatronEngine.Natron.RectI.bottom()->int",
    "NatronEngine.Natron.RectI.clear()",
    "2:NatronEngine.Natron.RectI.contains(other:NatronEngine.Natron.RectI)->bool",
    "1:NatronEngine.Natron.RectI.contains(x:double,y:double)->bool",
    "0:NatronEngine.Natron.RectI.contains(x:int,y:int)->bool",
    "NatronEngine.Natron.RectI.height()->int",
    "1:NatronEngine.Natron.RectI.intersect(r:NatronEngine.Natron.RectI,intersection:NatronEngine.Natron.RectI)->bool",
    "0:NatronEngine.Natron.RectI.intersect(x1_:int,y1_:int,x2_:int,y2_:int,intersection:NatronEngine.Natron.RectI)->bool",
    "1:NatronEngine.Natron.RectI.intersects(r:NatronEngine.Natron.RectI)->bool",
    "0:NatronEngine.Natron.RectI.intersects(x1_:int,y1_:int,x2_:int,y2_:int)->bool",
    "NatronEngine.Natron.RectI.isInfinite()->bool",
    "NatronEngine.Natron.RectI.isNull()->bool",
    "NatronEngine.Natron.RectI.left()->int",
    "1:NatronEngine.Natron.RectI.merge(box:NatronEngine.Natron.RectI)",
    "0:NatronEngine.Natron.RectI.merge(x1_:int,y1_:int,x2_:int,y2_:int)",
    "NatronEngine.Natron.RectI.right()->int",
    "NatronEngine.Natron.RectI.roundToTileSize(tileSizeX:int,tileSizeY:int)",
    "1:NatronEngine.Natron.RectI.set(b:NatronEngine.Natron.RectI)",
    "0:NatronEngine.Natron.RectI.set(x1_:int,y1_:int,x2_:int,y2_:int)",
    "NatronEngine.Natron.RectI.set_bottom(v:int)",
    "NatronEngine.Natron.RectI.set_left(v:int)",
    "NatronEngine.Natron.RectI.set_right(v:int)",
    "NatronEngine.Natron.RectI.set_top(v:int)",
    "NatronEngine.Natron.RectI.top()->int",
    "NatronEngine.Natron.RectI.translate(dx:int,dy:int)",
    "NatronEngine.Natron.RectI.width()->int",
    nullptr}; // Sentinel

void init_Natron_RectI(PyObject* enclosingClass)
{
    _Sbk_Natron_RectI_Type = Shiboken::ObjectType::introduceWrapperType(
        enclosingClass,
        "RectI",
        "Natron::RectI*",
        &Sbk_Natron_RectI_spec,
        Natron_RectI_SignatureStrings,
        &Shiboken::callCppDestructor< ::Natron::RectI >,
        0,
        0,
        Shiboken::ObjectType::WrapperFlags::InnerClass    );
    
    SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_Natron_RectI_TypeF());

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_Natron_RectI_TypeF(),
        RectI_PythonToCpp_RectI_PTR,
        is_RectI_PythonToCpp_RectI_PTR_Convertible,
        RectI_PTR_CppToPython_RectI);

    Shiboken::Conversions::registerConverterName(converter, "Natron::RectI");
    Shiboken::Conversions::registerConverterName(converter, "Natron::RectI*");
    Shiboken::Conversions::registerConverterName(converter, "Natron::RectI&");
    Shiboken::Conversions::registerConverterName(converter, "RectI");
    Shiboken::Conversions::registerConverterName(converter, "RectI*");
    Shiboken::Conversions::registerConverterName(converter, "RectI&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Natron::RectI).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::RectIWrapper).name());



    RectIWrapper::pysideInitQtMetaTypes();
}
