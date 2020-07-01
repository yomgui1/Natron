
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
#include "natron_rectd_wrapper.h"

// inner classes

// Extra includes
#include <RectD.h>


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

void RectDWrapper::pysideInitQtMetaTypes()
{
}

RectDWrapper::RectDWrapper() : Natron::RectD()
{
    // ... middle
}

RectDWrapper::RectDWrapper(double l, double b, double r, double t) : Natron::RectD(l, b, r, t)
{
    // ... middle
}

RectDWrapper::~RectDWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_Natron_RectD_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType< ::Natron::RectD >()))
        return -1;

    ::RectDWrapper* cptr{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 2 || numArgs == 3)
        goto Sbk_Natron_RectD_Init_TypeError;

    if (!PyArg_UnpackTuple(args, "RectD", 0, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return -1;


    // Overloaded function decisor
    // 0: RectD::RectD()
    // 1: RectD::RectD(Natron::RectD)
    // 2: RectD::RectD(double,double,double,double)
    if (numArgs == 0) {
        overloadId = 0; // RectD()
    } else if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[3])))) {
        overloadId = 2; // RectD(double,double,double,double)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX]), (pyArgs[0])))) {
        overloadId = 1; // RectD(Natron::RectD)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_RectD_Init_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // RectD()
        {

            if (!PyErr_Occurred()) {
                // RectD()
                cptr = new ::RectDWrapper();
            }
            break;
        }
        case 1: // RectD(const Natron::RectD & b)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return -1;
            ::Natron::RectD* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // RectD(Natron::RectD)
                cptr = new ::RectDWrapper(*cppArg0);
            }
            break;
        }
        case 2: // RectD(double l, double b, double r, double t)
        {
            double cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            double cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            double cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            double cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // RectD(double,double,double,double)
                cptr = new ::RectDWrapper(cppArg0, cppArg1, cppArg2, cppArg3);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType< ::Natron::RectD >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_Natron_RectD_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    if (Shiboken::BindingManager::instance().hasWrapper(cptr)) {
        Shiboken::BindingManager::instance().releaseWrapper(Shiboken::BindingManager::instance().retrieveWrapper(cptr));
    }
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_Natron_RectD_Init_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.RectD");
        return -1;
}

static PyObject* Sbk_Natron_RectDFunc_addPadding(PyObject* self, PyObject* args)
{
    ::Natron::RectD* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::RectD *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "addPadding", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: RectD::addPadding(double,double)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))) {
        overloadId = 0; // addPadding(double,double)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_RectDFunc_addPadding_TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        double cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // addPadding(double,double)
            cppSelf->addPadding(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_RectDFunc_addPadding_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.RectD.addPadding");
        return {};
}

static PyObject* Sbk_Natron_RectDFunc_addPaddingPercentage(PyObject* self, PyObject* args)
{
    ::Natron::RectD* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::RectD *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "addPaddingPercentage", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: RectD::addPaddingPercentage(double,double)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))) {
        overloadId = 0; // addPaddingPercentage(double,double)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_RectDFunc_addPaddingPercentage_TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        double cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // addPaddingPercentage(double,double)
            cppSelf->addPaddingPercentage(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_RectDFunc_addPaddingPercentage_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.RectD.addPaddingPercentage");
        return {};
}

static PyObject* Sbk_Natron_RectDFunc_area(PyObject* self)
{
    ::Natron::RectD* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::RectD *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // area()const
            double cppResult = const_cast<const ::Natron::RectD*>(cppSelf)->area();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_RectDFunc_bottom(PyObject* self)
{
    ::Natron::RectD* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::RectD *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // bottom()const
            double cppResult = const_cast<const ::Natron::RectD*>(cppSelf)->bottom();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_RectDFunc_clear(PyObject* self)
{
    ::Natron::RectD* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::RectD *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX], reinterpret_cast<SbkObject *>(self)));

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

static PyObject* Sbk_Natron_RectDFunc_contains(PyObject* self, PyObject* args)
{
    ::Natron::RectD* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::RectD *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX], reinterpret_cast<SbkObject *>(self)));
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
    // 0: RectD::contains(Natron::RectD)const
    // 1: RectD::contains(double,double)const
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))) {
        overloadId = 1; // contains(double,double)const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX]), (pyArgs[0])))) {
        overloadId = 0; // contains(Natron::RectD)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_RectDFunc_contains_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // contains(const Natron::RectD & other) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return {};
            ::Natron::RectD* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // contains(Natron::RectD)const
                bool cppResult = const_cast<const ::Natron::RectD*>(cppSelf)->contains(*cppArg0);
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
                bool cppResult = const_cast<const ::Natron::RectD*>(cppSelf)->contains(cppArg0, cppArg1);
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

    Sbk_Natron_RectDFunc_contains_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.RectD.contains");
        return {};
}

static PyObject* Sbk_Natron_RectDFunc_height(PyObject* self)
{
    ::Natron::RectD* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::RectD *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // height()const
            double cppResult = const_cast<const ::Natron::RectD*>(cppSelf)->height();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_RectDFunc_intersect(PyObject* self, PyObject* args)
{
    ::Natron::RectD* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::RectD *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 3 || numArgs == 4)
        goto Sbk_Natron_RectDFunc_intersect_TypeError;

    if (!PyArg_UnpackTuple(args, "intersect", 2, 5, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3]), &(pyArgs[4])))
        return {};


    // Overloaded function decisor
    // 0: RectD::intersect(Natron::RectD,Natron::RectD*)const
    // 1: RectD::intersect(double,double,double,double,Natron::RectD*)const
    if (numArgs == 5
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[3])))
        && (pythonToCpp[4] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX]), (pyArgs[4])))) {
        overloadId = 1; // intersect(double,double,double,double,Natron::RectD*)const
    } else if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX]), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX]), (pyArgs[1])))) {
        overloadId = 0; // intersect(Natron::RectD,Natron::RectD*)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_RectDFunc_intersect_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // intersect(const Natron::RectD & r, Natron::RectD * intersection) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return {};
            ::Natron::RectD* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            if (!Shiboken::Object::isValid(pyArgs[1]))
                return {};
            ::Natron::RectD* cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // intersect(Natron::RectD,Natron::RectD*)const
                bool cppResult = const_cast<const ::Natron::RectD*>(cppSelf)->intersect(*cppArg0, cppArg1);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // intersect(double l, double b, double r, double t, Natron::RectD * intersection) const
        {
            double cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            double cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            double cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            double cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);
            if (!Shiboken::Object::isValid(pyArgs[4]))
                return {};
            ::Natron::RectD* cppArg4;
            pythonToCpp[4](pyArgs[4], &cppArg4);

            if (!PyErr_Occurred()) {
                // intersect(double,double,double,double,Natron::RectD*)const
                bool cppResult = const_cast<const ::Natron::RectD*>(cppSelf)->intersect(cppArg0, cppArg1, cppArg2, cppArg3, cppArg4);
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

    Sbk_Natron_RectDFunc_intersect_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.RectD.intersect");
        return {};
}

static PyObject* Sbk_Natron_RectDFunc_intersects(PyObject* self, PyObject* args)
{
    ::Natron::RectD* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::RectD *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 2 || numArgs == 3)
        goto Sbk_Natron_RectDFunc_intersects_TypeError;

    if (!PyArg_UnpackTuple(args, "intersects", 1, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return {};


    // Overloaded function decisor
    // 0: RectD::intersects(Natron::RectD)const
    // 1: RectD::intersects(double,double,double,double)const
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[3])))) {
        overloadId = 1; // intersects(double,double,double,double)const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX]), (pyArgs[0])))) {
        overloadId = 0; // intersects(Natron::RectD)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_RectDFunc_intersects_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // intersects(const Natron::RectD & r) const
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return {};
            ::Natron::RectD* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // intersects(Natron::RectD)const
                bool cppResult = const_cast<const ::Natron::RectD*>(cppSelf)->intersects(*cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
            }
            break;
        }
        case 1: // intersects(double l, double b, double r, double t) const
        {
            double cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            double cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            double cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            double cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // intersects(double,double,double,double)const
                bool cppResult = const_cast<const ::Natron::RectD*>(cppSelf)->intersects(cppArg0, cppArg1, cppArg2, cppArg3);
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

    Sbk_Natron_RectDFunc_intersects_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.RectD.intersects");
        return {};
}

static PyObject* Sbk_Natron_RectDFunc_isInfinite(PyObject* self)
{
    ::Natron::RectD* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::RectD *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isInfinite()const
            bool cppResult = const_cast<const ::Natron::RectD*>(cppSelf)->isInfinite();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_RectDFunc_isNull(PyObject* self)
{
    ::Natron::RectD* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::RectD *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isNull()const
            bool cppResult = const_cast<const ::Natron::RectD*>(cppSelf)->isNull();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_RectDFunc_left(PyObject* self)
{
    ::Natron::RectD* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::RectD *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // left()const
            double cppResult = const_cast<const ::Natron::RectD*>(cppSelf)->left();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_RectDFunc_merge(PyObject* self, PyObject* args)
{
    ::Natron::RectD* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::RectD *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 2 || numArgs == 3)
        goto Sbk_Natron_RectDFunc_merge_TypeError;

    if (!PyArg_UnpackTuple(args, "merge", 1, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return {};


    // Overloaded function decisor
    // 0: RectD::merge(Natron::RectD)
    // 1: RectD::merge(double,double,double,double)
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[3])))) {
        overloadId = 1; // merge(double,double,double,double)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX]), (pyArgs[0])))) {
        overloadId = 0; // merge(Natron::RectD)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_RectDFunc_merge_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // merge(const Natron::RectD & box)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return {};
            ::Natron::RectD* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // merge(Natron::RectD)
                cppSelf->merge(*cppArg0);
            }
            break;
        }
        case 1: // merge(double l, double b, double r, double t)
        {
            double cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            double cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            double cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            double cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // merge(double,double,double,double)
                cppSelf->merge(cppArg0, cppArg1, cppArg2, cppArg3);
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_RectDFunc_merge_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.RectD.merge");
        return {};
}

static PyObject* Sbk_Natron_RectDFunc_right(PyObject* self)
{
    ::Natron::RectD* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::RectD *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // right()const
            double cppResult = const_cast<const ::Natron::RectD*>(cppSelf)->right();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_RectDFunc_set(PyObject* self, PyObject* args)
{
    ::Natron::RectD* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::RectD *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject* pyArgs[] = {0, 0, 0, 0};

    // invalid argument lengths
    if (numArgs == 2 || numArgs == 3)
        goto Sbk_Natron_RectDFunc_set_TypeError;

    if (!PyArg_UnpackTuple(args, "set", 1, 4, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2]), &(pyArgs[3])))
        return {};


    // Overloaded function decisor
    // 0: RectD::set(Natron::RectD)
    // 1: RectD::set(double,double,double,double)
    if (numArgs == 4
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[2])))
        && (pythonToCpp[3] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[3])))) {
        overloadId = 1; // set(double,double,double,double)
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppReferenceConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX]), (pyArgs[0])))) {
        overloadId = 0; // set(Natron::RectD)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_RectDFunc_set_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // set(const Natron::RectD & b)
        {
            if (!Shiboken::Object::isValid(pyArgs[0]))
                return {};
            ::Natron::RectD* cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // set(Natron::RectD)
                cppSelf->set(*cppArg0);
            }
            break;
        }
        case 1: // set(double l, double b, double r, double t)
        {
            double cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            double cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);
            double cppArg2;
            pythonToCpp[2](pyArgs[2], &cppArg2);
            double cppArg3;
            pythonToCpp[3](pyArgs[3], &cppArg3);

            if (!PyErr_Occurred()) {
                // set(double,double,double,double)
                cppSelf->set(cppArg0, cppArg1, cppArg2, cppArg3);
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_RectDFunc_set_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.RectD.set");
        return {};
}

static PyObject* Sbk_Natron_RectDFunc_set_bottom(PyObject* self, PyObject* pyArg)
{
    ::Natron::RectD* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::RectD *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: RectD::set_bottom(double)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArg)))) {
        overloadId = 0; // set_bottom(double)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_RectDFunc_set_bottom_TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // set_bottom(double)
            cppSelf->set_bottom(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_RectDFunc_set_bottom_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.RectD.set_bottom");
        return {};
}

static PyObject* Sbk_Natron_RectDFunc_set_left(PyObject* self, PyObject* pyArg)
{
    ::Natron::RectD* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::RectD *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: RectD::set_left(double)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArg)))) {
        overloadId = 0; // set_left(double)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_RectDFunc_set_left_TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // set_left(double)
            cppSelf->set_left(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_RectDFunc_set_left_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.RectD.set_left");
        return {};
}

static PyObject* Sbk_Natron_RectDFunc_set_right(PyObject* self, PyObject* pyArg)
{
    ::Natron::RectD* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::RectD *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: RectD::set_right(double)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArg)))) {
        overloadId = 0; // set_right(double)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_RectDFunc_set_right_TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // set_right(double)
            cppSelf->set_right(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_RectDFunc_set_right_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.RectD.set_right");
        return {};
}

static PyObject* Sbk_Natron_RectDFunc_set_top(PyObject* self, PyObject* pyArg)
{
    ::Natron::RectD* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::RectD *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX], reinterpret_cast<SbkObject *>(self)));
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: RectD::set_top(double)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArg)))) {
        overloadId = 0; // set_top(double)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_RectDFunc_set_top_TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // set_top(double)
            cppSelf->set_top(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_RectDFunc_set_top_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.RectD.set_top");
        return {};
}

static PyObject* Sbk_Natron_RectDFunc_setupInfinity(PyObject* self)
{
    ::Natron::RectD* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::RectD *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX], reinterpret_cast<SbkObject *>(self)));

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // setupInfinity()
            cppSelf->setupInfinity();
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_Natron_RectDFunc_top(PyObject* self)
{
    ::Natron::RectD* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::RectD *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // top()const
            double cppResult = const_cast<const ::Natron::RectD*>(cppSelf)->top();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject* Sbk_Natron_RectDFunc_translate(PyObject* self, PyObject* args)
{
    ::Natron::RectD* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::RectD *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX], reinterpret_cast<SbkObject *>(self)));
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
    // 0: RectD::translate(int,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // translate(int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_RectDFunc_translate_TypeError;

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

    Sbk_Natron_RectDFunc_translate_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.RectD.translate");
        return {};
}

static PyObject* Sbk_Natron_RectDFunc_width(PyObject* self)
{
    ::Natron::RectD* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return {};
    cppSelf = reinterpret_cast< ::Natron::RectD *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // width()const
            double cppResult = const_cast<const ::Natron::RectD*>(cppSelf)->width();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyMethodDef Sbk_Natron_RectD_methods[] = {
    {"addPadding", reinterpret_cast<PyCFunction>(Sbk_Natron_RectDFunc_addPadding), METH_VARARGS},
    {"addPaddingPercentage", reinterpret_cast<PyCFunction>(Sbk_Natron_RectDFunc_addPaddingPercentage), METH_VARARGS},
    {"area", reinterpret_cast<PyCFunction>(Sbk_Natron_RectDFunc_area), METH_NOARGS},
    {"bottom", reinterpret_cast<PyCFunction>(Sbk_Natron_RectDFunc_bottom), METH_NOARGS},
    {"clear", reinterpret_cast<PyCFunction>(Sbk_Natron_RectDFunc_clear), METH_NOARGS},
    {"contains", reinterpret_cast<PyCFunction>(Sbk_Natron_RectDFunc_contains), METH_VARARGS},
    {"height", reinterpret_cast<PyCFunction>(Sbk_Natron_RectDFunc_height), METH_NOARGS},
    {"intersect", reinterpret_cast<PyCFunction>(Sbk_Natron_RectDFunc_intersect), METH_VARARGS},
    {"intersects", reinterpret_cast<PyCFunction>(Sbk_Natron_RectDFunc_intersects), METH_VARARGS},
    {"isInfinite", reinterpret_cast<PyCFunction>(Sbk_Natron_RectDFunc_isInfinite), METH_NOARGS},
    {"isNull", reinterpret_cast<PyCFunction>(Sbk_Natron_RectDFunc_isNull), METH_NOARGS},
    {"left", reinterpret_cast<PyCFunction>(Sbk_Natron_RectDFunc_left), METH_NOARGS},
    {"merge", reinterpret_cast<PyCFunction>(Sbk_Natron_RectDFunc_merge), METH_VARARGS},
    {"right", reinterpret_cast<PyCFunction>(Sbk_Natron_RectDFunc_right), METH_NOARGS},
    {"set", reinterpret_cast<PyCFunction>(Sbk_Natron_RectDFunc_set), METH_VARARGS},
    {"set_bottom", reinterpret_cast<PyCFunction>(Sbk_Natron_RectDFunc_set_bottom), METH_O},
    {"set_left", reinterpret_cast<PyCFunction>(Sbk_Natron_RectDFunc_set_left), METH_O},
    {"set_right", reinterpret_cast<PyCFunction>(Sbk_Natron_RectDFunc_set_right), METH_O},
    {"set_top", reinterpret_cast<PyCFunction>(Sbk_Natron_RectDFunc_set_top), METH_O},
    {"setupInfinity", reinterpret_cast<PyCFunction>(Sbk_Natron_RectDFunc_setupInfinity), METH_NOARGS},
    {"top", reinterpret_cast<PyCFunction>(Sbk_Natron_RectDFunc_top), METH_NOARGS},
    {"translate", reinterpret_cast<PyCFunction>(Sbk_Natron_RectDFunc_translate), METH_VARARGS},
    {"width", reinterpret_cast<PyCFunction>(Sbk_Natron_RectDFunc_width), METH_NOARGS},

    {nullptr, nullptr} // Sentinel
};

static PyObject* Sbk_Natron_RectD_get_x1(PyObject* self, void*)
{
    ::Natron::RectD* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return nullptr;
    cppSelf = reinterpret_cast< ::Natron::RectD *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyOut = {};
    pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppSelf->x1);
    return pyOut;
}
static int Sbk_Natron_RectD_set_x1(PyObject* self, PyObject* pyIn, void*)
{
    ::Natron::RectD* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = reinterpret_cast< ::Natron::RectD *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX], reinterpret_cast<SbkObject *>(self)));
    if (pyIn == nullptr) {
        PyErr_SetString(PyExc_TypeError, "'x1' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp{nullptr};
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'x1', 'double' or convertible type expected");
        return -1;
    }

    double& cppOut_ptr = cppSelf->x1;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_Natron_RectD_get_y1(PyObject* self, void*)
{
    ::Natron::RectD* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return nullptr;
    cppSelf = reinterpret_cast< ::Natron::RectD *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyOut = {};
    pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppSelf->y1);
    return pyOut;
}
static int Sbk_Natron_RectD_set_y1(PyObject* self, PyObject* pyIn, void*)
{
    ::Natron::RectD* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = reinterpret_cast< ::Natron::RectD *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX], reinterpret_cast<SbkObject *>(self)));
    if (pyIn == nullptr) {
        PyErr_SetString(PyExc_TypeError, "'y1' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp{nullptr};
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'y1', 'double' or convertible type expected");
        return -1;
    }

    double& cppOut_ptr = cppSelf->y1;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_Natron_RectD_get_x2(PyObject* self, void*)
{
    ::Natron::RectD* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return nullptr;
    cppSelf = reinterpret_cast< ::Natron::RectD *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyOut = {};
    pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppSelf->x2);
    return pyOut;
}
static int Sbk_Natron_RectD_set_x2(PyObject* self, PyObject* pyIn, void*)
{
    ::Natron::RectD* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = reinterpret_cast< ::Natron::RectD *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX], reinterpret_cast<SbkObject *>(self)));
    if (pyIn == nullptr) {
        PyErr_SetString(PyExc_TypeError, "'x2' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp{nullptr};
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'x2', 'double' or convertible type expected");
        return -1;
    }

    double& cppOut_ptr = cppSelf->x2;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

static PyObject* Sbk_Natron_RectD_get_y2(PyObject* self, void*)
{
    ::Natron::RectD* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return nullptr;
    cppSelf = reinterpret_cast< ::Natron::RectD *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX], reinterpret_cast<SbkObject *>(self)));
    PyObject* pyOut = {};
    pyOut = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppSelf->y2);
    return pyOut;
}
static int Sbk_Natron_RectD_set_y2(PyObject* self, PyObject* pyIn, void*)
{
    ::Natron::RectD* cppSelf = nullptr;
    SBK_UNUSED(cppSelf)
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = reinterpret_cast< ::Natron::RectD *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX], reinterpret_cast<SbkObject *>(self)));
    if (pyIn == nullptr) {
        PyErr_SetString(PyExc_TypeError, "'y2' may not be deleted");
        return -1;
    }
    PythonToCppFunc pythonToCpp{nullptr};
    if (!(pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyIn)))) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'y2', 'double' or convertible type expected");
        return -1;
    }

    double& cppOut_ptr = cppSelf->y2;
    pythonToCpp(pyIn, &cppOut_ptr);

    return 0;
}

// Getters and Setters for RectD
static PyGetSetDef Sbk_Natron_RectD_getsetlist[] = {
    {const_cast<char*>("x1"), Sbk_Natron_RectD_get_x1, Sbk_Natron_RectD_set_x1},
    {const_cast<char*>("y1"), Sbk_Natron_RectD_get_y1, Sbk_Natron_RectD_set_y1},
    {const_cast<char*>("x2"), Sbk_Natron_RectD_get_x2, Sbk_Natron_RectD_set_x2},
    {const_cast<char*>("y2"), Sbk_Natron_RectD_get_y2, Sbk_Natron_RectD_set_y2},
    {nullptr} // Sentinel
};

} // extern "C"

static int Sbk_Natron_RectD_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_Natron_RectD_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_Natron_RectD_Type = nullptr;
static SbkObjectType *Sbk_Natron_RectD_TypeF(void)
{
    return _Sbk_Natron_RectD_Type;
}

static PyType_Slot Sbk_Natron_RectD_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void*>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void*>(Sbk_Natron_RectD_traverse)},
    {Py_tp_clear,       reinterpret_cast<void*>(Sbk_Natron_RectD_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void*>(Sbk_Natron_RectD_methods)},
    {Py_tp_getset,      reinterpret_cast<void*>(Sbk_Natron_RectD_getsetlist)},
    {Py_tp_init,        reinterpret_cast<void*>(Sbk_Natron_RectD_Init)},
    {Py_tp_new,         reinterpret_cast<void*>(SbkObjectTpNew)},
    {0, nullptr}
};
static PyType_Spec Sbk_Natron_RectD_spec = {
    "NatronEngine.Natron.RectD",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Natron_RectD_slots
};

} //extern "C"


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void RectD_PythonToCpp_RectD_PTR(PyObject* pyIn, void* cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_Natron_RectD_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_RectD_PythonToCpp_RectD_PTR_Convertible(PyObject* pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject*>(Sbk_Natron_RectD_TypeF())))
        return RectD_PythonToCpp_RectD_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject* RectD_PTR_CppToPython_RectD(const void* cppIn) {
    auto pyOut = reinterpret_cast<PyObject*>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::Natron::RectD *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_Natron_RectD_TypeF(), const_cast<void*>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *Natron_RectD_SignatureStrings[] = {
    "2:NatronEngine.Natron.RectD()",
    "1:NatronEngine.Natron.RectD(b:NatronEngine.Natron.RectD)",
    "0:NatronEngine.Natron.RectD(l:double,b:double,r:double,t:double)",
    "NatronEngine.Natron.RectD.addPadding(x:double,y:double)",
    "NatronEngine.Natron.RectD.addPaddingPercentage(xPercent:double,yPercent:double)",
    "NatronEngine.Natron.RectD.area()->double",
    "NatronEngine.Natron.RectD.bottom()->double",
    "NatronEngine.Natron.RectD.clear()",
    "1:NatronEngine.Natron.RectD.contains(other:NatronEngine.Natron.RectD)->bool",
    "0:NatronEngine.Natron.RectD.contains(x:double,y:double)->bool",
    "NatronEngine.Natron.RectD.height()->double",
    "1:NatronEngine.Natron.RectD.intersect(r:NatronEngine.Natron.RectD,intersection:NatronEngine.Natron.RectD)->bool",
    "0:NatronEngine.Natron.RectD.intersect(l:double,b:double,r:double,t:double,intersection:NatronEngine.Natron.RectD)->bool",
    "1:NatronEngine.Natron.RectD.intersects(r:NatronEngine.Natron.RectD)->bool",
    "0:NatronEngine.Natron.RectD.intersects(l:double,b:double,r:double,t:double)->bool",
    "NatronEngine.Natron.RectD.isInfinite()->bool",
    "NatronEngine.Natron.RectD.isNull()->bool",
    "NatronEngine.Natron.RectD.left()->double",
    "1:NatronEngine.Natron.RectD.merge(box:NatronEngine.Natron.RectD)",
    "0:NatronEngine.Natron.RectD.merge(l:double,b:double,r:double,t:double)",
    "NatronEngine.Natron.RectD.right()->double",
    "1:NatronEngine.Natron.RectD.set(b:NatronEngine.Natron.RectD)",
    "0:NatronEngine.Natron.RectD.set(l:double,b:double,r:double,t:double)",
    "NatronEngine.Natron.RectD.set_bottom(v:double)",
    "NatronEngine.Natron.RectD.set_left(v:double)",
    "NatronEngine.Natron.RectD.set_right(v:double)",
    "NatronEngine.Natron.RectD.set_top(v:double)",
    "NatronEngine.Natron.RectD.setupInfinity()",
    "NatronEngine.Natron.RectD.top()->double",
    "NatronEngine.Natron.RectD.translate(dx:int,dy:int)",
    "NatronEngine.Natron.RectD.width()->double",
    nullptr}; // Sentinel

void init_Natron_RectD(PyObject* enclosingClass)
{
    _Sbk_Natron_RectD_Type = Shiboken::ObjectType::introduceWrapperType(
        enclosingClass,
        "RectD",
        "Natron::RectD*",
        &Sbk_Natron_RectD_spec,
        Natron_RectD_SignatureStrings,
        &Shiboken::callCppDestructor< ::Natron::RectD >,
        0,
        0,
        Shiboken::ObjectType::WrapperFlags::InnerClass    );
    
    SbkNatronEngineTypes[SBK_NATRON_RECTD_IDX]
        = reinterpret_cast<PyTypeObject*>(Sbk_Natron_RectD_TypeF());

    // Register Converter
    SbkConverter* converter = Shiboken::Conversions::createConverter(Sbk_Natron_RectD_TypeF(),
        RectD_PythonToCpp_RectD_PTR,
        is_RectD_PythonToCpp_RectD_PTR_Convertible,
        RectD_PTR_CppToPython_RectD);

    Shiboken::Conversions::registerConverterName(converter, "Natron::RectD");
    Shiboken::Conversions::registerConverterName(converter, "Natron::RectD*");
    Shiboken::Conversions::registerConverterName(converter, "Natron::RectD&");
    Shiboken::Conversions::registerConverterName(converter, "RectD");
    Shiboken::Conversions::registerConverterName(converter, "RectD*");
    Shiboken::Conversions::registerConverterName(converter, "RectD&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Natron::RectD).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::RectDWrapper).name());



    RectDWrapper::pysideInitQtMetaTypes();
}
