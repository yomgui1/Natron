
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

#include "natron_namespace_wrapper.h"

// Extra includes
NATRON_NAMESPACE_USING NATRON_PYTHON_NAMESPACE_USING



// Target ---------------------------------------------------------

extern "C" {
static PyObject* Sbk_NATRON_NAMESPACEFunc_isFailureRetCode(PyObject* self, PyObject* pyArg)
{
    PyObject* pyResult = 0;
    int overloadId = -1;
    PythonToCppFunc pythonToCpp;
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: isFailureRetCode(NATRON_NAMESPACE::ActionRetCodeEnum)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SBK_CONVERTER(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ACTIONRETCODEENUM_IDX]), (pyArg)))) {
        overloadId = 0; // isFailureRetCode(NATRON_NAMESPACE::ActionRetCodeEnum)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_NATRON_NAMESPACEFunc_isFailureRetCode_TypeError;

    // Call function/method
    {
        ::NATRON_NAMESPACE::ActionRetCodeEnum cppArg0 = ((::NATRON_NAMESPACE::ActionRetCodeEnum)0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // isFailureRetCode(NATRON_NAMESPACE::ActionRetCodeEnum)
            bool cppResult = ::NATRON_NAMESPACE::isFailureRetCode(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_NATRON_NAMESPACEFunc_isFailureRetCode_TypeError:
        const char* overloads[] = {"NatronEngine.Natron.ActionRetCodeEnum", 0};
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.isFailureRetCode", overloads);
        return 0;
}

static PyMethodDef Sbk_NATRON_NAMESPACE_methods[] = {
    {"isFailureRetCode", (PyCFunction)Sbk_NATRON_NAMESPACEFunc_isFailureRetCode, METH_O|METH_STATIC},

    {0} // Sentinel
};

} // extern "C"

static int Sbk_NATRON_NAMESPACE_traverse(PyObject* self, visitproc visit, void* arg)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_traverse(self, visit, arg);
}
static int Sbk_NATRON_NAMESPACE_clear(PyObject* self)
{
    return reinterpret_cast<PyTypeObject*>(&SbkObject_Type)->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_NATRON_NAMESPACE_Type = { { {
    PyVarObject_HEAD_INIT(&SbkObjectType_Type, 0)
    /*tp_name*/             "NatronEngine.Natron",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          0,
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
    /*tp_traverse*/         Sbk_NATRON_NAMESPACE_traverse,
    /*tp_clear*/            Sbk_NATRON_NAMESPACE_clear,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_NATRON_NAMESPACE_methods,
    /*tp_members*/          0,
    /*tp_getset*/           0,
    /*tp_base*/             reinterpret_cast<PyTypeObject*>(&SbkObject_Type),
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

PyObject* SbkNatronEngine_NATRON_NAMESPACE_StandardButtonEnum___and__(PyObject* self, PyObject* pyArg)
{
    ::NATRON_NAMESPACE::StandardButtons cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::NATRON_NAMESPACE::StandardButtons)PyLong_AsLong(self);
    cppArg = (NATRON_NAMESPACE::StandardButtons)PyLong_AsLong(pyArg);
#else
    cppSelf = (::NATRON_NAMESPACE::StandardButtons)PyInt_AsLong(self);
    cppArg = (NATRON_NAMESPACE::StandardButtons)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_NAMESPACE_STANDARDBUTTONENUM__IDX]), &cppResult);
}

PyObject* SbkNatronEngine_NATRON_NAMESPACE_StandardButtonEnum___or__(PyObject* self, PyObject* pyArg)
{
    ::NATRON_NAMESPACE::StandardButtons cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::NATRON_NAMESPACE::StandardButtons)PyLong_AsLong(self);
    cppArg = (NATRON_NAMESPACE::StandardButtons)PyLong_AsLong(pyArg);
#else
    cppSelf = (::NATRON_NAMESPACE::StandardButtons)PyInt_AsLong(self);
    cppArg = (NATRON_NAMESPACE::StandardButtons)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_NAMESPACE_STANDARDBUTTONENUM__IDX]), &cppResult);
}

PyObject* SbkNatronEngine_NATRON_NAMESPACE_StandardButtonEnum___xor__(PyObject* self, PyObject* pyArg)
{
    ::NATRON_NAMESPACE::StandardButtons cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = (::NATRON_NAMESPACE::StandardButtons)PyLong_AsLong(self);
    cppArg = (NATRON_NAMESPACE::StandardButtons)PyLong_AsLong(pyArg);
#else
    cppSelf = (::NATRON_NAMESPACE::StandardButtons)PyInt_AsLong(self);
    cppArg = (NATRON_NAMESPACE::StandardButtons)PyInt_AsLong(pyArg);
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_NAMESPACE_STANDARDBUTTONENUM__IDX]), &cppResult);
}

PyObject* SbkNatronEngine_NATRON_NAMESPACE_StandardButtonEnum___invert__(PyObject* self, PyObject* pyArg)
{
    ::NATRON_NAMESPACE::StandardButtons cppSelf;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_NAMESPACE_STANDARDBUTTONENUM__IDX]), self, &cppSelf);
    ::NATRON_NAMESPACE::StandardButtons cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(SBK_CONVERTER(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_NAMESPACE_STANDARDBUTTONENUM__IDX]), &cppResult);
}

static PyObject* SbkNatronEngine_NATRON_NAMESPACE_StandardButtonEnum_long(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_NAMESPACE_STANDARDBUTTONENUM__IDX]), self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkNatronEngine_NATRON_NAMESPACE_StandardButtonEnum__nonzero(PyObject* self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(SBK_CONVERTER(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_NAMESPACE_STANDARDBUTTONENUM__IDX]), self, &val);
    return val != 0;
}

static PyNumberMethods SbkNatronEngine_NATRON_NAMESPACE_StandardButtonEnum_as_number = {
    /*nb_add*/                  0,
    /*nb_subtract*/             0,
    /*nb_multiply*/             0,
    #ifndef IS_PY3K
    /* nb_divide */             0,
    #endif
    /*nb_remainder*/            0,
    /*nb_divmod*/               0,
    /*nb_power*/                0,
    /*nb_negative*/             0,
    /*nb_positive*/             0,
    /*nb_absolute*/             0,
    /*nb_nonzero*/              SbkNatronEngine_NATRON_NAMESPACE_StandardButtonEnum__nonzero,
    /*nb_invert*/               (unaryfunc)SbkNatronEngine_NATRON_NAMESPACE_StandardButtonEnum___invert__,
    /*nb_lshift*/               0,
    /*nb_rshift*/               0,
    /*nb_and*/                  (binaryfunc)SbkNatronEngine_NATRON_NAMESPACE_StandardButtonEnum___and__,
    /*nb_xor*/                  (binaryfunc)SbkNatronEngine_NATRON_NAMESPACE_StandardButtonEnum___xor__,
    /*nb_or*/                   (binaryfunc)SbkNatronEngine_NATRON_NAMESPACE_StandardButtonEnum___or__,
    #ifndef IS_PY3K
    /* nb_coerce */             0,
    #endif
    /*nb_int*/                  SbkNatronEngine_NATRON_NAMESPACE_StandardButtonEnum_long,
    #ifdef IS_PY3K
    /*nb_reserved*/             0,
    /*nb_float*/                0,
    #else
    /*nb_long*/                 SbkNatronEngine_NATRON_NAMESPACE_StandardButtonEnum_long,
    /*nb_float*/                0,
    /*nb_oct*/                  0,
    /*nb_hex*/                  0,
    #endif
    /*nb_inplace_add*/          0,
    /*nb_inplace_subtract*/     0,
    /*nb_inplace_multiply*/     0,
    #ifndef IS_PY3K
    /*nb_inplace_divide*/       0,
    #endif
    /*nb_inplace_remainder*/    0,
    /*nb_inplace_power*/        0,
    /*nb_inplace_lshift*/       0,
    /*nb_inplace_rshift*/       0,
    /*nb_inplace_and*/          0,
    /*nb_inplace_xor*/          0,
    /*nb_inplace_or*/           0,
    /*nb_floor_divide*/         0,
    /*nb_true_divide*/          0,
    /*nb_inplace_floor_divide*/ 0,
    /*nb_inplace_true_divide*/  0,
    /*nb_index*/                0
};



// Type conversion functions.

// Python to C++ enum conversion.
static void NATRON_NAMESPACE_ActionRetCodeEnum_PythonToCpp_NATRON_NAMESPACE_ActionRetCodeEnum(PyObject* pyIn, void* cppOut) {
    *((::NATRON_NAMESPACE::ActionRetCodeEnum*)cppOut) = (::NATRON_NAMESPACE::ActionRetCodeEnum) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_NATRON_NAMESPACE_ActionRetCodeEnum_PythonToCpp_NATRON_NAMESPACE_ActionRetCodeEnum_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ACTIONRETCODEENUM_IDX]))
        return NATRON_NAMESPACE_ActionRetCodeEnum_PythonToCpp_NATRON_NAMESPACE_ActionRetCodeEnum;
    return 0;
}
static PyObject* NATRON_NAMESPACE_ActionRetCodeEnum_CppToPython_NATRON_NAMESPACE_ActionRetCodeEnum(const void* cppIn) {
    int castCppIn = *((::NATRON_NAMESPACE::ActionRetCodeEnum*)cppIn);
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ACTIONRETCODEENUM_IDX], castCppIn);

}

static void NATRON_NAMESPACE_StandardButtonEnum_PythonToCpp_NATRON_NAMESPACE_StandardButtonEnum(PyObject* pyIn, void* cppOut) {
    *((::NATRON_NAMESPACE::StandardButtonEnum*)cppOut) = (::NATRON_NAMESPACE::StandardButtonEnum) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_NATRON_NAMESPACE_StandardButtonEnum_PythonToCpp_NATRON_NAMESPACE_StandardButtonEnum_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_STANDARDBUTTONENUM_IDX]))
        return NATRON_NAMESPACE_StandardButtonEnum_PythonToCpp_NATRON_NAMESPACE_StandardButtonEnum;
    return 0;
}
static PyObject* NATRON_NAMESPACE_StandardButtonEnum_CppToPython_NATRON_NAMESPACE_StandardButtonEnum(const void* cppIn) {
    int castCppIn = *((::NATRON_NAMESPACE::StandardButtonEnum*)cppIn);
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_STANDARDBUTTONENUM_IDX], castCppIn);

}

static void QFlags_NATRON_NAMESPACE_StandardButtonEnum__PythonToCpp_QFlags_NATRON_NAMESPACE_StandardButtonEnum_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<NATRON_NAMESPACE::StandardButtonEnum>*)cppOut) = ::QFlags<NATRON_NAMESPACE::StandardButtonEnum>(QFlag(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject*>(pyIn))));

}
static PythonToCppFunc is_QFlags_NATRON_NAMESPACE_StandardButtonEnum__PythonToCpp_QFlags_NATRON_NAMESPACE_StandardButtonEnum__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_QFLAGS_NATRON_NAMESPACE_STANDARDBUTTONENUM__IDX]))
        return QFlags_NATRON_NAMESPACE_StandardButtonEnum__PythonToCpp_QFlags_NATRON_NAMESPACE_StandardButtonEnum_;
    return 0;
}
static PyObject* QFlags_NATRON_NAMESPACE_StandardButtonEnum__CppToPython_QFlags_NATRON_NAMESPACE_StandardButtonEnum_(const void* cppIn) {
    int castCppIn = *((::QFlags<NATRON_NAMESPACE::StandardButtonEnum>*)cppIn);
    return reinterpret_cast<PyObject*>(PySide::QFlags::newObject(castCppIn, SbkNatronEngineTypes[SBK_QFLAGS_NATRON_NAMESPACE_STANDARDBUTTONENUM__IDX]));

}

static void NATRON_NAMESPACE_StandardButtonEnum_PythonToCpp_QFlags_NATRON_NAMESPACE_StandardButtonEnum_(PyObject* pyIn, void* cppOut) {
    *((::QFlags<NATRON_NAMESPACE::StandardButtonEnum>*)cppOut) = ::QFlags<NATRON_NAMESPACE::StandardButtonEnum>(QFlag(Shiboken::Enum::getValue(pyIn)));

}
static PythonToCppFunc is_NATRON_NAMESPACE_StandardButtonEnum_PythonToCpp_QFlags_NATRON_NAMESPACE_StandardButtonEnum__Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_STANDARDBUTTONENUM_IDX]))
        return NATRON_NAMESPACE_StandardButtonEnum_PythonToCpp_QFlags_NATRON_NAMESPACE_StandardButtonEnum_;
    return 0;
}
static void number_PythonToCpp_QFlags_NATRON_NAMESPACE_StandardButtonEnum_(PyObject* pyIn, void* cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *((::QFlags<NATRON_NAMESPACE::StandardButtonEnum>*)cppOut) = ::QFlags<NATRON_NAMESPACE::StandardButtonEnum>(QFlag(PyLong_AsLong(pyLong.object())));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_NATRON_NAMESPACE_StandardButtonEnum__Convertible(PyObject* pyIn) {
    if (PyNumber_Check(pyIn))
        return number_PythonToCpp_QFlags_NATRON_NAMESPACE_StandardButtonEnum_;
    return 0;
}
static void NATRON_NAMESPACE_KeyframeTypeEnum_PythonToCpp_NATRON_NAMESPACE_KeyframeTypeEnum(PyObject* pyIn, void* cppOut) {
    *((::NATRON_NAMESPACE::KeyframeTypeEnum*)cppOut) = (::NATRON_NAMESPACE::KeyframeTypeEnum) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_NATRON_NAMESPACE_KeyframeTypeEnum_PythonToCpp_NATRON_NAMESPACE_KeyframeTypeEnum_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_KEYFRAMETYPEENUM_IDX]))
        return NATRON_NAMESPACE_KeyframeTypeEnum_PythonToCpp_NATRON_NAMESPACE_KeyframeTypeEnum;
    return 0;
}
static PyObject* NATRON_NAMESPACE_KeyframeTypeEnum_CppToPython_NATRON_NAMESPACE_KeyframeTypeEnum(const void* cppIn) {
    int castCppIn = *((::NATRON_NAMESPACE::KeyframeTypeEnum*)cppIn);
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_KEYFRAMETYPEENUM_IDX], castCppIn);

}

static void NATRON_NAMESPACE_PixmapEnum_PythonToCpp_NATRON_NAMESPACE_PixmapEnum(PyObject* pyIn, void* cppOut) {
    *((::NATRON_NAMESPACE::PixmapEnum*)cppOut) = (::NATRON_NAMESPACE::PixmapEnum) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_NATRON_NAMESPACE_PixmapEnum_PythonToCpp_NATRON_NAMESPACE_PixmapEnum_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX]))
        return NATRON_NAMESPACE_PixmapEnum_PythonToCpp_NATRON_NAMESPACE_PixmapEnum;
    return 0;
}
static PyObject* NATRON_NAMESPACE_PixmapEnum_CppToPython_NATRON_NAMESPACE_PixmapEnum(const void* cppIn) {
    int castCppIn = *((::NATRON_NAMESPACE::PixmapEnum*)cppIn);
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX], castCppIn);

}

static void NATRON_NAMESPACE_ViewerContextLayoutTypeEnum_PythonToCpp_NATRON_NAMESPACE_ViewerContextLayoutTypeEnum(PyObject* pyIn, void* cppOut) {
    *((::NATRON_NAMESPACE::ViewerContextLayoutTypeEnum*)cppOut) = (::NATRON_NAMESPACE::ViewerContextLayoutTypeEnum) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_NATRON_NAMESPACE_ViewerContextLayoutTypeEnum_PythonToCpp_NATRON_NAMESPACE_ViewerContextLayoutTypeEnum_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_VIEWERCONTEXTLAYOUTTYPEENUM_IDX]))
        return NATRON_NAMESPACE_ViewerContextLayoutTypeEnum_PythonToCpp_NATRON_NAMESPACE_ViewerContextLayoutTypeEnum;
    return 0;
}
static PyObject* NATRON_NAMESPACE_ViewerContextLayoutTypeEnum_CppToPython_NATRON_NAMESPACE_ViewerContextLayoutTypeEnum(const void* cppIn) {
    int castCppIn = *((::NATRON_NAMESPACE::ViewerContextLayoutTypeEnum*)cppIn);
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_VIEWERCONTEXTLAYOUTTYPEENUM_IDX], castCppIn);

}

static void NATRON_NAMESPACE_AnimationLevelEnum_PythonToCpp_NATRON_NAMESPACE_AnimationLevelEnum(PyObject* pyIn, void* cppOut) {
    *((::NATRON_NAMESPACE::AnimationLevelEnum*)cppOut) = (::NATRON_NAMESPACE::AnimationLevelEnum) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_NATRON_NAMESPACE_AnimationLevelEnum_PythonToCpp_NATRON_NAMESPACE_AnimationLevelEnum_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ANIMATIONLEVELENUM_IDX]))
        return NATRON_NAMESPACE_AnimationLevelEnum_PythonToCpp_NATRON_NAMESPACE_AnimationLevelEnum;
    return 0;
}
static PyObject* NATRON_NAMESPACE_AnimationLevelEnum_CppToPython_NATRON_NAMESPACE_AnimationLevelEnum(const void* cppIn) {
    int castCppIn = *((::NATRON_NAMESPACE::AnimationLevelEnum*)cppIn);
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ANIMATIONLEVELENUM_IDX], castCppIn);

}

static void NATRON_NAMESPACE_ImagePremultiplicationEnum_PythonToCpp_NATRON_NAMESPACE_ImagePremultiplicationEnum(PyObject* pyIn, void* cppOut) {
    *((::NATRON_NAMESPACE::ImagePremultiplicationEnum*)cppOut) = (::NATRON_NAMESPACE::ImagePremultiplicationEnum) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_NATRON_NAMESPACE_ImagePremultiplicationEnum_PythonToCpp_NATRON_NAMESPACE_ImagePremultiplicationEnum_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_IMAGEPREMULTIPLICATIONENUM_IDX]))
        return NATRON_NAMESPACE_ImagePremultiplicationEnum_PythonToCpp_NATRON_NAMESPACE_ImagePremultiplicationEnum;
    return 0;
}
static PyObject* NATRON_NAMESPACE_ImagePremultiplicationEnum_CppToPython_NATRON_NAMESPACE_ImagePremultiplicationEnum(const void* cppIn) {
    int castCppIn = *((::NATRON_NAMESPACE::ImagePremultiplicationEnum*)cppIn);
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_IMAGEPREMULTIPLICATIONENUM_IDX], castCppIn);

}

static void NATRON_NAMESPACE_ImageBitDepthEnum_PythonToCpp_NATRON_NAMESPACE_ImageBitDepthEnum(PyObject* pyIn, void* cppOut) {
    *((::NATRON_NAMESPACE::ImageBitDepthEnum*)cppOut) = (::NATRON_NAMESPACE::ImageBitDepthEnum) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_NATRON_NAMESPACE_ImageBitDepthEnum_PythonToCpp_NATRON_NAMESPACE_ImageBitDepthEnum_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_IMAGEBITDEPTHENUM_IDX]))
        return NATRON_NAMESPACE_ImageBitDepthEnum_PythonToCpp_NATRON_NAMESPACE_ImageBitDepthEnum;
    return 0;
}
static PyObject* NATRON_NAMESPACE_ImageBitDepthEnum_CppToPython_NATRON_NAMESPACE_ImageBitDepthEnum(const void* cppIn) {
    int castCppIn = *((::NATRON_NAMESPACE::ImageBitDepthEnum*)cppIn);
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_IMAGEBITDEPTHENUM_IDX], castCppIn);

}

static void NATRON_NAMESPACE_OrientationEnum_PythonToCpp_NATRON_NAMESPACE_OrientationEnum(PyObject* pyIn, void* cppOut) {
    *((::NATRON_NAMESPACE::OrientationEnum*)cppOut) = (::NATRON_NAMESPACE::OrientationEnum) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_NATRON_NAMESPACE_OrientationEnum_PythonToCpp_NATRON_NAMESPACE_OrientationEnum_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ORIENTATIONENUM_IDX]))
        return NATRON_NAMESPACE_OrientationEnum_PythonToCpp_NATRON_NAMESPACE_OrientationEnum;
    return 0;
}
static PyObject* NATRON_NAMESPACE_OrientationEnum_CppToPython_NATRON_NAMESPACE_OrientationEnum(const void* cppIn) {
    int castCppIn = *((::NATRON_NAMESPACE::OrientationEnum*)cppIn);
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ORIENTATIONENUM_IDX], castCppIn);

}

static void NATRON_NAMESPACE_RotoStrokeType_PythonToCpp_NATRON_NAMESPACE_RotoStrokeType(PyObject* pyIn, void* cppOut) {
    *((::NATRON_NAMESPACE::RotoStrokeType*)cppOut) = (::NATRON_NAMESPACE::RotoStrokeType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_NATRON_NAMESPACE_RotoStrokeType_PythonToCpp_NATRON_NAMESPACE_RotoStrokeType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ROTOSTROKETYPE_IDX]))
        return NATRON_NAMESPACE_RotoStrokeType_PythonToCpp_NATRON_NAMESPACE_RotoStrokeType;
    return 0;
}
static PyObject* NATRON_NAMESPACE_RotoStrokeType_CppToPython_NATRON_NAMESPACE_RotoStrokeType(const void* cppIn) {
    int castCppIn = *((::NATRON_NAMESPACE::RotoStrokeType*)cppIn);
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ROTOSTROKETYPE_IDX], castCppIn);

}

static void NATRON_NAMESPACE_PenType_PythonToCpp_NATRON_NAMESPACE_PenType(PyObject* pyIn, void* cppOut) {
    *((::NATRON_NAMESPACE::PenType*)cppOut) = (::NATRON_NAMESPACE::PenType) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_NATRON_NAMESPACE_PenType_PythonToCpp_NATRON_NAMESPACE_PenType_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PENTYPE_IDX]))
        return NATRON_NAMESPACE_PenType_PythonToCpp_NATRON_NAMESPACE_PenType;
    return 0;
}
static PyObject* NATRON_NAMESPACE_PenType_CppToPython_NATRON_NAMESPACE_PenType(const void* cppIn) {
    int castCppIn = *((::NATRON_NAMESPACE::PenType*)cppIn);
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PENTYPE_IDX], castCppIn);

}

static void NATRON_NAMESPACE_MergingFunctionEnum_PythonToCpp_NATRON_NAMESPACE_MergingFunctionEnum(PyObject* pyIn, void* cppOut) {
    *((::NATRON_NAMESPACE::MergingFunctionEnum*)cppOut) = (::NATRON_NAMESPACE::MergingFunctionEnum) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_NATRON_NAMESPACE_MergingFunctionEnum_PythonToCpp_NATRON_NAMESPACE_MergingFunctionEnum_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX]))
        return NATRON_NAMESPACE_MergingFunctionEnum_PythonToCpp_NATRON_NAMESPACE_MergingFunctionEnum;
    return 0;
}
static PyObject* NATRON_NAMESPACE_MergingFunctionEnum_CppToPython_NATRON_NAMESPACE_MergingFunctionEnum(const void* cppIn) {
    int castCppIn = *((::NATRON_NAMESPACE::MergingFunctionEnum*)cppIn);
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX], castCppIn);

}

static void NATRON_NAMESPACE_TableChangeReasonEnum_PythonToCpp_NATRON_NAMESPACE_TableChangeReasonEnum(PyObject* pyIn, void* cppOut) {
    *((::NATRON_NAMESPACE::TableChangeReasonEnum*)cppOut) = (::NATRON_NAMESPACE::TableChangeReasonEnum) Shiboken::Enum::getValue(pyIn);

}
static PythonToCppFunc is_NATRON_NAMESPACE_TableChangeReasonEnum_PythonToCpp_NATRON_NAMESPACE_TableChangeReasonEnum_Convertible(PyObject* pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_TABLECHANGEREASONENUM_IDX]))
        return NATRON_NAMESPACE_TableChangeReasonEnum_PythonToCpp_NATRON_NAMESPACE_TableChangeReasonEnum;
    return 0;
}
static PyObject* NATRON_NAMESPACE_TableChangeReasonEnum_CppToPython_NATRON_NAMESPACE_TableChangeReasonEnum(const void* cppIn) {
    int castCppIn = *((::NATRON_NAMESPACE::TableChangeReasonEnum*)cppIn);
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_TABLECHANGEREASONENUM_IDX], castCppIn);

}

void init_NATRON_NAMESPACE(PyObject* module)
{
    SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_NATRON_NAMESPACE_Type);

    if (!Shiboken::ObjectType::introduceWrapperType(module, "Natron", "Natron",
        &Sbk_NATRON_NAMESPACE_Type)) {
        return;
    }


    // Initialization of enums.

    // Initialization of enum 'ActionRetCodeEnum'.
    SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ACTIONRETCODEENUM_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_NATRON_NAMESPACE_Type,
        "ActionRetCodeEnum",
        "NatronEngine.Natron.ActionRetCodeEnum",
        "Natron::ActionRetCodeEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ACTIONRETCODEENUM_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ACTIONRETCODEENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eActionStatusOK", (long) NATRON_NAMESPACE::eActionStatusOK))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ACTIONRETCODEENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eActionStatusFailed", (long) NATRON_NAMESPACE::eActionStatusFailed))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ACTIONRETCODEENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eActionStatusInputDisconnected", (long) NATRON_NAMESPACE::eActionStatusInputDisconnected))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ACTIONRETCODEENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eActionStatusAborted", (long) NATRON_NAMESPACE::eActionStatusAborted))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ACTIONRETCODEENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eActionStatusOutOfMemory", (long) NATRON_NAMESPACE::eActionStatusOutOfMemory))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ACTIONRETCODEENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eActionStatusReplyDefault", (long) NATRON_NAMESPACE::eActionStatusReplyDefault))
        return ;
    // Register converter for enum 'NATRON_NAMESPACE::ActionRetCodeEnum'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ACTIONRETCODEENUM_IDX],
            NATRON_NAMESPACE_ActionRetCodeEnum_CppToPython_NATRON_NAMESPACE_ActionRetCodeEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            NATRON_NAMESPACE_ActionRetCodeEnum_PythonToCpp_NATRON_NAMESPACE_ActionRetCodeEnum,
            is_NATRON_NAMESPACE_ActionRetCodeEnum_PythonToCpp_NATRON_NAMESPACE_ActionRetCodeEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ACTIONRETCODEENUM_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ACTIONRETCODEENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::ActionRetCodeEnum");
        Shiboken::Conversions::registerConverterName(converter, "ActionRetCodeEnum");
    }
    // End of 'ActionRetCodeEnum' enum.

    // Initialization of enum 'StandardButtonEnum'.
    SbkNatronEngineTypes[SBK_QFLAGS_NATRON_NAMESPACE_STANDARDBUTTONENUM__IDX] = PySide::QFlags::create("StandardButtons", &SbkNatronEngine_NATRON_NAMESPACE_StandardButtonEnum_as_number);
    SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_STANDARDBUTTONENUM_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_NATRON_NAMESPACE_Type,
        "StandardButtonEnum",
        "NatronEngine.Natron.StandardButtonEnum",
        "Natron::StandardButtonEnum",
        SbkNatronEngineTypes[SBK_QFLAGS_NATRON_NAMESPACE_STANDARDBUTTONENUM__IDX]);
    if (!SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_STANDARDBUTTONENUM_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_STANDARDBUTTONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eStandardButtonNoButton", (long) NATRON_NAMESPACE::eStandardButtonNoButton))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_STANDARDBUTTONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eStandardButtonEscape", (long) NATRON_NAMESPACE::eStandardButtonEscape))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_STANDARDBUTTONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eStandardButtonOk", (long) NATRON_NAMESPACE::eStandardButtonOk))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_STANDARDBUTTONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eStandardButtonSave", (long) NATRON_NAMESPACE::eStandardButtonSave))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_STANDARDBUTTONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eStandardButtonSaveAll", (long) NATRON_NAMESPACE::eStandardButtonSaveAll))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_STANDARDBUTTONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eStandardButtonOpen", (long) NATRON_NAMESPACE::eStandardButtonOpen))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_STANDARDBUTTONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eStandardButtonYes", (long) NATRON_NAMESPACE::eStandardButtonYes))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_STANDARDBUTTONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eStandardButtonYesToAll", (long) NATRON_NAMESPACE::eStandardButtonYesToAll))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_STANDARDBUTTONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eStandardButtonNo", (long) NATRON_NAMESPACE::eStandardButtonNo))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_STANDARDBUTTONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eStandardButtonNoToAll", (long) NATRON_NAMESPACE::eStandardButtonNoToAll))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_STANDARDBUTTONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eStandardButtonAbort", (long) NATRON_NAMESPACE::eStandardButtonAbort))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_STANDARDBUTTONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eStandardButtonRetry", (long) NATRON_NAMESPACE::eStandardButtonRetry))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_STANDARDBUTTONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eStandardButtonIgnore", (long) NATRON_NAMESPACE::eStandardButtonIgnore))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_STANDARDBUTTONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eStandardButtonClose", (long) NATRON_NAMESPACE::eStandardButtonClose))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_STANDARDBUTTONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eStandardButtonCancel", (long) NATRON_NAMESPACE::eStandardButtonCancel))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_STANDARDBUTTONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eStandardButtonDiscard", (long) NATRON_NAMESPACE::eStandardButtonDiscard))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_STANDARDBUTTONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eStandardButtonHelp", (long) NATRON_NAMESPACE::eStandardButtonHelp))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_STANDARDBUTTONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eStandardButtonApply", (long) NATRON_NAMESPACE::eStandardButtonApply))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_STANDARDBUTTONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eStandardButtonReset", (long) NATRON_NAMESPACE::eStandardButtonReset))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_STANDARDBUTTONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eStandardButtonRestoreDefaults", (long) NATRON_NAMESPACE::eStandardButtonRestoreDefaults))
        return ;
    // Register converter for enum 'NATRON_NAMESPACE::StandardButtonEnum'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_STANDARDBUTTONENUM_IDX],
            NATRON_NAMESPACE_StandardButtonEnum_CppToPython_NATRON_NAMESPACE_StandardButtonEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            NATRON_NAMESPACE_StandardButtonEnum_PythonToCpp_NATRON_NAMESPACE_StandardButtonEnum,
            is_NATRON_NAMESPACE_StandardButtonEnum_PythonToCpp_NATRON_NAMESPACE_StandardButtonEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_STANDARDBUTTONENUM_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_STANDARDBUTTONENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::StandardButtonEnum");
        Shiboken::Conversions::registerConverterName(converter, "StandardButtonEnum");
    }
    // Register converter for flag 'QFlags<NATRON_NAMESPACE::StandardButtonEnum>'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_NAMESPACE_STANDARDBUTTONENUM__IDX],
            QFlags_NATRON_NAMESPACE_StandardButtonEnum__CppToPython_QFlags_NATRON_NAMESPACE_StandardButtonEnum_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            NATRON_NAMESPACE_StandardButtonEnum_PythonToCpp_QFlags_NATRON_NAMESPACE_StandardButtonEnum_,
            is_NATRON_NAMESPACE_StandardButtonEnum_PythonToCpp_QFlags_NATRON_NAMESPACE_StandardButtonEnum__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_NATRON_NAMESPACE_StandardButtonEnum__PythonToCpp_QFlags_NATRON_NAMESPACE_StandardButtonEnum_,
            is_QFlags_NATRON_NAMESPACE_StandardButtonEnum__PythonToCpp_QFlags_NATRON_NAMESPACE_StandardButtonEnum__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_NATRON_NAMESPACE_StandardButtonEnum_,
            is_number_PythonToCpp_QFlags_NATRON_NAMESPACE_StandardButtonEnum__Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_NAMESPACE_STANDARDBUTTONENUM__IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_NAMESPACE_STANDARDBUTTONENUM__IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "QFlags<QFlags<NATRON_NAMESPACE::StandardButtonEnum>");
        Shiboken::Conversions::registerConverterName(converter, "QFlags<StandardButtonEnum>");
    }
    // End of 'StandardButtonEnum' enum/flags.

    // Initialization of enum 'KeyframeTypeEnum'.
    SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_KEYFRAMETYPEENUM_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_NATRON_NAMESPACE_Type,
        "KeyframeTypeEnum",
        "NatronEngine.Natron.KeyframeTypeEnum",
        "Natron::KeyframeTypeEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_KEYFRAMETYPEENUM_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_KEYFRAMETYPEENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eKeyframeTypeConstant", (long) NATRON_NAMESPACE::eKeyframeTypeConstant))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_KEYFRAMETYPEENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eKeyframeTypeLinear", (long) NATRON_NAMESPACE::eKeyframeTypeLinear))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_KEYFRAMETYPEENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eKeyframeTypeSmooth", (long) NATRON_NAMESPACE::eKeyframeTypeSmooth))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_KEYFRAMETYPEENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eKeyframeTypeCatmullRom", (long) NATRON_NAMESPACE::eKeyframeTypeCatmullRom))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_KEYFRAMETYPEENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eKeyframeTypeCubic", (long) NATRON_NAMESPACE::eKeyframeTypeCubic))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_KEYFRAMETYPEENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eKeyframeTypeHorizontal", (long) NATRON_NAMESPACE::eKeyframeTypeHorizontal))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_KEYFRAMETYPEENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eKeyframeTypeFree", (long) NATRON_NAMESPACE::eKeyframeTypeFree))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_KEYFRAMETYPEENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eKeyframeTypeBroken", (long) NATRON_NAMESPACE::eKeyframeTypeBroken))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_KEYFRAMETYPEENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eKeyframeTypeNone", (long) NATRON_NAMESPACE::eKeyframeTypeNone))
        return ;
    // Register converter for enum 'NATRON_NAMESPACE::KeyframeTypeEnum'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_KEYFRAMETYPEENUM_IDX],
            NATRON_NAMESPACE_KeyframeTypeEnum_CppToPython_NATRON_NAMESPACE_KeyframeTypeEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            NATRON_NAMESPACE_KeyframeTypeEnum_PythonToCpp_NATRON_NAMESPACE_KeyframeTypeEnum,
            is_NATRON_NAMESPACE_KeyframeTypeEnum_PythonToCpp_NATRON_NAMESPACE_KeyframeTypeEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_KEYFRAMETYPEENUM_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_KEYFRAMETYPEENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::KeyframeTypeEnum");
        Shiboken::Conversions::registerConverterName(converter, "KeyframeTypeEnum");
    }
    // End of 'KeyframeTypeEnum' enum.

    // Initialization of enum 'PixmapEnum'.
    SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_NATRON_NAMESPACE_Type,
        "PixmapEnum",
        "NatronEngine.Natron.PixmapEnum",
        "Natron::PixmapEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_PLAYER_PREVIOUS", (long) NATRON_NAMESPACE::NATRON_PIXMAP_PLAYER_PREVIOUS))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_PLAYER_FIRST_FRAME", (long) NATRON_NAMESPACE::NATRON_PIXMAP_PLAYER_FIRST_FRAME))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_PLAYER_NEXT", (long) NATRON_NAMESPACE::NATRON_PIXMAP_PLAYER_NEXT))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_PLAYER_LAST_FRAME", (long) NATRON_NAMESPACE::NATRON_PIXMAP_PLAYER_LAST_FRAME))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_PLAYER_NEXT_INCR", (long) NATRON_NAMESPACE::NATRON_PIXMAP_PLAYER_NEXT_INCR))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_PLAYER_NEXT_KEY", (long) NATRON_NAMESPACE::NATRON_PIXMAP_PLAYER_NEXT_KEY))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_PLAYER_PREVIOUS_INCR", (long) NATRON_NAMESPACE::NATRON_PIXMAP_PLAYER_PREVIOUS_INCR))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_PLAYER_PREVIOUS_KEY", (long) NATRON_NAMESPACE::NATRON_PIXMAP_PLAYER_PREVIOUS_KEY))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_PLAYER_REWIND_ENABLED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_PLAYER_REWIND_ENABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_PLAYER_REWIND_DISABLED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_PLAYER_REWIND_DISABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_PLAYER_PLAY_ENABLED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_PLAYER_PLAY_ENABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_PLAYER_PLAY_DISABLED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_PLAYER_PLAY_DISABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_PLAYER_STOP_DISABLED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_PLAYER_STOP_DISABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_PLAYER_STOP_ENABLED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_PLAYER_STOP_ENABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_PLAYER_PAUSE_DISABLED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_PLAYER_PAUSE_DISABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_PLAYER_PAUSE_ENABLED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_PLAYER_PAUSE_ENABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_PLAYER_LOOP_MODE", (long) NATRON_NAMESPACE::NATRON_PIXMAP_PLAYER_LOOP_MODE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_PLAYER_BOUNCE", (long) NATRON_NAMESPACE::NATRON_PIXMAP_PLAYER_BOUNCE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_PLAYER_PLAY_ONCE", (long) NATRON_NAMESPACE::NATRON_PIXMAP_PLAYER_PLAY_ONCE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_PLAYER_TIMELINE_IN", (long) NATRON_NAMESPACE::NATRON_PIXMAP_PLAYER_TIMELINE_IN))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_PLAYER_TIMELINE_OUT", (long) NATRON_NAMESPACE::NATRON_PIXMAP_PLAYER_TIMELINE_OUT))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_MAXIMIZE_WIDGET", (long) NATRON_NAMESPACE::NATRON_PIXMAP_MAXIMIZE_WIDGET))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_MINIMIZE_WIDGET", (long) NATRON_NAMESPACE::NATRON_PIXMAP_MINIMIZE_WIDGET))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_CLOSE_WIDGET", (long) NATRON_NAMESPACE::NATRON_PIXMAP_CLOSE_WIDGET))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_HELP_WIDGET", (long) NATRON_NAMESPACE::NATRON_PIXMAP_HELP_WIDGET))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_CLOSE_PANEL", (long) NATRON_NAMESPACE::NATRON_PIXMAP_CLOSE_PANEL))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_HIDE_UNMODIFIED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_HIDE_UNMODIFIED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_UNHIDE_UNMODIFIED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_UNHIDE_UNMODIFIED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_GROUPBOX_FOLDED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_GROUPBOX_FOLDED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_GROUPBOX_UNFOLDED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_GROUPBOX_UNFOLDED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_UNDO", (long) NATRON_NAMESPACE::NATRON_PIXMAP_UNDO))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_REDO", (long) NATRON_NAMESPACE::NATRON_PIXMAP_REDO))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_UNDO_GRAYSCALE", (long) NATRON_NAMESPACE::NATRON_PIXMAP_UNDO_GRAYSCALE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_REDO_GRAYSCALE", (long) NATRON_NAMESPACE::NATRON_PIXMAP_REDO_GRAYSCALE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_RESTORE_DEFAULTS_ENABLED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_RESTORE_DEFAULTS_ENABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_RESTORE_DEFAULTS_DISABLED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_RESTORE_DEFAULTS_DISABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_TAB_WIDGET_LAYOUT_BUTTON", (long) NATRON_NAMESPACE::NATRON_PIXMAP_TAB_WIDGET_LAYOUT_BUTTON))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_TAB_WIDGET_LAYOUT_BUTTON_ANCHOR", (long) NATRON_NAMESPACE::NATRON_PIXMAP_TAB_WIDGET_LAYOUT_BUTTON_ANCHOR))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_TAB_WIDGET_SPLIT_HORIZONTALLY", (long) NATRON_NAMESPACE::NATRON_PIXMAP_TAB_WIDGET_SPLIT_HORIZONTALLY))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_TAB_WIDGET_SPLIT_VERTICALLY", (long) NATRON_NAMESPACE::NATRON_PIXMAP_TAB_WIDGET_SPLIT_VERTICALLY))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_VIEWER_CENTER", (long) NATRON_NAMESPACE::NATRON_PIXMAP_VIEWER_CENTER))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_VIEWER_CLIP_TO_PROJECT_ENABLED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_VIEWER_CLIP_TO_PROJECT_ENABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_VIEWER_CLIP_TO_PROJECT_DISABLED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_VIEWER_CLIP_TO_PROJECT_DISABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_VIEWER_FULL_FRAME_ON", (long) NATRON_NAMESPACE::NATRON_PIXMAP_VIEWER_FULL_FRAME_ON))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_VIEWER_FULL_FRAME_OFF", (long) NATRON_NAMESPACE::NATRON_PIXMAP_VIEWER_FULL_FRAME_OFF))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_VIEWER_REFRESH", (long) NATRON_NAMESPACE::NATRON_PIXMAP_VIEWER_REFRESH))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_VIEWER_REFRESH_ACTIVE", (long) NATRON_NAMESPACE::NATRON_PIXMAP_VIEWER_REFRESH_ACTIVE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_VIEWER_ROI_ENABLED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_VIEWER_ROI_ENABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_VIEWER_ROI_DISABLED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_VIEWER_ROI_DISABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_VIEWER_RENDER_SCALE", (long) NATRON_NAMESPACE::NATRON_PIXMAP_VIEWER_RENDER_SCALE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_VIEWER_RENDER_SCALE_CHECKED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_VIEWER_RENDER_SCALE_CHECKED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_VIEWER_AUTOCONTRAST_ENABLED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_VIEWER_AUTOCONTRAST_ENABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_VIEWER_AUTOCONTRAST_DISABLED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_VIEWER_AUTOCONTRAST_DISABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_OPEN_FILE", (long) NATRON_NAMESPACE::NATRON_PIXMAP_OPEN_FILE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_COLORWHEEL", (long) NATRON_NAMESPACE::NATRON_PIXMAP_COLORWHEEL))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_OVERLAY", (long) NATRON_NAMESPACE::NATRON_PIXMAP_OVERLAY))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_ROTO_MERGE", (long) NATRON_NAMESPACE::NATRON_PIXMAP_ROTO_MERGE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_COLOR_PICKER", (long) NATRON_NAMESPACE::NATRON_PIXMAP_COLOR_PICKER))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_IO_GROUPING", (long) NATRON_NAMESPACE::NATRON_PIXMAP_IO_GROUPING))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_3D_GROUPING", (long) NATRON_NAMESPACE::NATRON_PIXMAP_3D_GROUPING))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_CHANNEL_GROUPING", (long) NATRON_NAMESPACE::NATRON_PIXMAP_CHANNEL_GROUPING))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_MERGE_GROUPING", (long) NATRON_NAMESPACE::NATRON_PIXMAP_MERGE_GROUPING))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_COLOR_GROUPING", (long) NATRON_NAMESPACE::NATRON_PIXMAP_COLOR_GROUPING))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_TRANSFORM_GROUPING", (long) NATRON_NAMESPACE::NATRON_PIXMAP_TRANSFORM_GROUPING))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_DEEP_GROUPING", (long) NATRON_NAMESPACE::NATRON_PIXMAP_DEEP_GROUPING))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_FILTER_GROUPING", (long) NATRON_NAMESPACE::NATRON_PIXMAP_FILTER_GROUPING))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_MULTIVIEW_GROUPING", (long) NATRON_NAMESPACE::NATRON_PIXMAP_MULTIVIEW_GROUPING))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_TOOLSETS_GROUPING", (long) NATRON_NAMESPACE::NATRON_PIXMAP_TOOLSETS_GROUPING))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_MISC_GROUPING", (long) NATRON_NAMESPACE::NATRON_PIXMAP_MISC_GROUPING))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_OPEN_EFFECTS_GROUPING", (long) NATRON_NAMESPACE::NATRON_PIXMAP_OPEN_EFFECTS_GROUPING))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_TIME_GROUPING", (long) NATRON_NAMESPACE::NATRON_PIXMAP_TIME_GROUPING))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_PAINT_GROUPING", (long) NATRON_NAMESPACE::NATRON_PIXMAP_PAINT_GROUPING))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_KEYER_GROUPING", (long) NATRON_NAMESPACE::NATRON_PIXMAP_KEYER_GROUPING))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_OTHER_PLUGINS", (long) NATRON_NAMESPACE::NATRON_PIXMAP_OTHER_PLUGINS))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_READ_IMAGE", (long) NATRON_NAMESPACE::NATRON_PIXMAP_READ_IMAGE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_WRITE_IMAGE", (long) NATRON_NAMESPACE::NATRON_PIXMAP_WRITE_IMAGE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_COMBOBOX", (long) NATRON_NAMESPACE::NATRON_PIXMAP_COMBOBOX))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_COMBOBOX_PRESSED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_COMBOBOX_PRESSED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_ADD_KEYFRAME", (long) NATRON_NAMESPACE::NATRON_PIXMAP_ADD_KEYFRAME))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_REMOVE_KEYFRAME", (long) NATRON_NAMESPACE::NATRON_PIXMAP_REMOVE_KEYFRAME))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_INVERTED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_INVERTED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_UNINVERTED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_UNINVERTED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_VISIBLE", (long) NATRON_NAMESPACE::NATRON_PIXMAP_VISIBLE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_UNVISIBLE", (long) NATRON_NAMESPACE::NATRON_PIXMAP_UNVISIBLE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_LOCKED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_LOCKED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_UNLOCKED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_UNLOCKED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_LAYER", (long) NATRON_NAMESPACE::NATRON_PIXMAP_LAYER))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_BEZIER", (long) NATRON_NAMESPACE::NATRON_PIXMAP_BEZIER))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_PENCIL", (long) NATRON_NAMESPACE::NATRON_PIXMAP_PENCIL))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_CURVE", (long) NATRON_NAMESPACE::NATRON_PIXMAP_CURVE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_BEZIER_32", (long) NATRON_NAMESPACE::NATRON_PIXMAP_BEZIER_32))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_ELLIPSE", (long) NATRON_NAMESPACE::NATRON_PIXMAP_ELLIPSE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_RECTANGLE", (long) NATRON_NAMESPACE::NATRON_PIXMAP_RECTANGLE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_ADD_POINTS", (long) NATRON_NAMESPACE::NATRON_PIXMAP_ADD_POINTS))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_REMOVE_POINTS", (long) NATRON_NAMESPACE::NATRON_PIXMAP_REMOVE_POINTS))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_CUSP_POINTS", (long) NATRON_NAMESPACE::NATRON_PIXMAP_CUSP_POINTS))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_SMOOTH_POINTS", (long) NATRON_NAMESPACE::NATRON_PIXMAP_SMOOTH_POINTS))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_REMOVE_FEATHER", (long) NATRON_NAMESPACE::NATRON_PIXMAP_REMOVE_FEATHER))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_OPEN_CLOSE_CURVE", (long) NATRON_NAMESPACE::NATRON_PIXMAP_OPEN_CLOSE_CURVE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_SELECT_ALL", (long) NATRON_NAMESPACE::NATRON_PIXMAP_SELECT_ALL))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_SELECT_POINTS", (long) NATRON_NAMESPACE::NATRON_PIXMAP_SELECT_POINTS))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_SELECT_FEATHER", (long) NATRON_NAMESPACE::NATRON_PIXMAP_SELECT_FEATHER))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_SELECT_CURVES", (long) NATRON_NAMESPACE::NATRON_PIXMAP_SELECT_CURVES))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_AUTO_KEYING_ENABLED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_AUTO_KEYING_ENABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_AUTO_KEYING_DISABLED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_AUTO_KEYING_DISABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_STICKY_SELECTION_ENABLED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_STICKY_SELECTION_ENABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_STICKY_SELECTION_DISABLED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_STICKY_SELECTION_DISABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_FEATHER_LINK_ENABLED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_FEATHER_LINK_ENABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_FEATHER_LINK_DISABLED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_FEATHER_LINK_DISABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_FEATHER_VISIBLE", (long) NATRON_NAMESPACE::NATRON_PIXMAP_FEATHER_VISIBLE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_FEATHER_UNVISIBLE", (long) NATRON_NAMESPACE::NATRON_PIXMAP_FEATHER_UNVISIBLE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_RIPPLE_EDIT_ENABLED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_RIPPLE_EDIT_ENABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_RIPPLE_EDIT_DISABLED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_RIPPLE_EDIT_DISABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_ROTOPAINT_BLUR", (long) NATRON_NAMESPACE::NATRON_PIXMAP_ROTOPAINT_BLUR))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_ROTOPAINT_BUILDUP_ENABLED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_ROTOPAINT_BUILDUP_ENABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_ROTOPAINT_BUILDUP_DISABLED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_ROTOPAINT_BUILDUP_DISABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_ROTOPAINT_BURN", (long) NATRON_NAMESPACE::NATRON_PIXMAP_ROTOPAINT_BURN))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_ROTOPAINT_CLONE", (long) NATRON_NAMESPACE::NATRON_PIXMAP_ROTOPAINT_CLONE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_ROTOPAINT_DODGE", (long) NATRON_NAMESPACE::NATRON_PIXMAP_ROTOPAINT_DODGE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_ROTOPAINT_ERASER", (long) NATRON_NAMESPACE::NATRON_PIXMAP_ROTOPAINT_ERASER))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_ROTOPAINT_PRESSURE_ENABLED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_ROTOPAINT_PRESSURE_ENABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_ROTOPAINT_PRESSURE_DISABLED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_ROTOPAINT_PRESSURE_DISABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_ROTOPAINT_REVEAL", (long) NATRON_NAMESPACE::NATRON_PIXMAP_ROTOPAINT_REVEAL))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_ROTOPAINT_SHARPEN", (long) NATRON_NAMESPACE::NATRON_PIXMAP_ROTOPAINT_SHARPEN))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_ROTOPAINT_SMEAR", (long) NATRON_NAMESPACE::NATRON_PIXMAP_ROTOPAINT_SMEAR))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_ROTOPAINT_SOLID", (long) NATRON_NAMESPACE::NATRON_PIXMAP_ROTOPAINT_SOLID))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_BOLD_CHECKED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_BOLD_CHECKED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_BOLD_UNCHECKED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_BOLD_UNCHECKED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_ITALIC_CHECKED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_ITALIC_CHECKED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_ITALIC_UNCHECKED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_ITALIC_UNCHECKED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_CLEAR_ALL_ANIMATION", (long) NATRON_NAMESPACE::NATRON_PIXMAP_CLEAR_ALL_ANIMATION))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_CLEAR_BACKWARD_ANIMATION", (long) NATRON_NAMESPACE::NATRON_PIXMAP_CLEAR_BACKWARD_ANIMATION))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_CLEAR_FORWARD_ANIMATION", (long) NATRON_NAMESPACE::NATRON_PIXMAP_CLEAR_FORWARD_ANIMATION))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_UPDATE_VIEWER_ENABLED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_UPDATE_VIEWER_ENABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_UPDATE_VIEWER_DISABLED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_UPDATE_VIEWER_DISABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_ADD_TRACK", (long) NATRON_NAMESPACE::NATRON_PIXMAP_ADD_TRACK))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_ADD_USER_KEY", (long) NATRON_NAMESPACE::NATRON_PIXMAP_ADD_USER_KEY))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_REMOVE_USER_KEY", (long) NATRON_NAMESPACE::NATRON_PIXMAP_REMOVE_USER_KEY))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_SHOW_TRACK_ERROR", (long) NATRON_NAMESPACE::NATRON_PIXMAP_SHOW_TRACK_ERROR))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_HIDE_TRACK_ERROR", (long) NATRON_NAMESPACE::NATRON_PIXMAP_HIDE_TRACK_ERROR))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_RESET_TRACK_OFFSET", (long) NATRON_NAMESPACE::NATRON_PIXMAP_RESET_TRACK_OFFSET))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_CREATE_USER_KEY_ON_MOVE_ON", (long) NATRON_NAMESPACE::NATRON_PIXMAP_CREATE_USER_KEY_ON_MOVE_ON))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_CREATE_USER_KEY_ON_MOVE_OFF", (long) NATRON_NAMESPACE::NATRON_PIXMAP_CREATE_USER_KEY_ON_MOVE_OFF))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_RESET_USER_KEYS", (long) NATRON_NAMESPACE::NATRON_PIXMAP_RESET_USER_KEYS))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_CENTER_VIEWER_ON_TRACK", (long) NATRON_NAMESPACE::NATRON_PIXMAP_CENTER_VIEWER_ON_TRACK))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_TRACK_BACKWARD_ON", (long) NATRON_NAMESPACE::NATRON_PIXMAP_TRACK_BACKWARD_ON))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_TRACK_BACKWARD_OFF", (long) NATRON_NAMESPACE::NATRON_PIXMAP_TRACK_BACKWARD_OFF))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_TRACK_FORWARD_ON", (long) NATRON_NAMESPACE::NATRON_PIXMAP_TRACK_FORWARD_ON))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_TRACK_FORWARD_OFF", (long) NATRON_NAMESPACE::NATRON_PIXMAP_TRACK_FORWARD_OFF))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_TRACK_PREVIOUS", (long) NATRON_NAMESPACE::NATRON_PIXMAP_TRACK_PREVIOUS))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_TRACK_NEXT", (long) NATRON_NAMESPACE::NATRON_PIXMAP_TRACK_NEXT))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_TRACK_RANGE", (long) NATRON_NAMESPACE::NATRON_PIXMAP_TRACK_RANGE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_TRACK_ALL_KEYS", (long) NATRON_NAMESPACE::NATRON_PIXMAP_TRACK_ALL_KEYS))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_TRACK_CURRENT_KEY", (long) NATRON_NAMESPACE::NATRON_PIXMAP_TRACK_CURRENT_KEY))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_NEXT_USER_KEY", (long) NATRON_NAMESPACE::NATRON_PIXMAP_NEXT_USER_KEY))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_PREV_USER_KEY", (long) NATRON_NAMESPACE::NATRON_PIXMAP_PREV_USER_KEY))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_ENTER_GROUP", (long) NATRON_NAMESPACE::NATRON_PIXMAP_ENTER_GROUP))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_SETTINGS", (long) NATRON_NAMESPACE::NATRON_PIXMAP_SETTINGS))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_FREEZE_ENABLED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_FREEZE_ENABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_FREEZE_DISABLED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_FREEZE_DISABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_CURVE_EDITOR", (long) NATRON_NAMESPACE::NATRON_PIXMAP_CURVE_EDITOR))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_DOPE_SHEET", (long) NATRON_NAMESPACE::NATRON_PIXMAP_DOPE_SHEET))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_NODE_GRAPH", (long) NATRON_NAMESPACE::NATRON_PIXMAP_NODE_GRAPH))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_PROGRESS_PANEL", (long) NATRON_NAMESPACE::NATRON_PIXMAP_PROGRESS_PANEL))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_SCRIPT_EDITOR", (long) NATRON_NAMESPACE::NATRON_PIXMAP_SCRIPT_EDITOR))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_PROPERTIES_PANEL", (long) NATRON_NAMESPACE::NATRON_PIXMAP_PROPERTIES_PANEL))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_ANIMATION_MODULE", (long) NATRON_NAMESPACE::NATRON_PIXMAP_ANIMATION_MODULE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_VIEWER_PANEL", (long) NATRON_NAMESPACE::NATRON_PIXMAP_VIEWER_PANEL))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_VIEWER_ICON", (long) NATRON_NAMESPACE::NATRON_PIXMAP_VIEWER_ICON))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_VIEWER_CHECKERBOARD_ENABLED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_VIEWER_CHECKERBOARD_ENABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_VIEWER_CHECKERBOARD_DISABLED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_VIEWER_CHECKERBOARD_DISABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_VIEWER_ZEBRA_ENABLED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_VIEWER_ZEBRA_ENABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_VIEWER_ZEBRA_DISABLED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_VIEWER_ZEBRA_DISABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_VIEWER_GAMMA_ENABLED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_VIEWER_GAMMA_ENABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_VIEWER_GAMMA_DISABLED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_VIEWER_GAMMA_DISABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_VIEWER_GAIN_ENABLED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_VIEWER_GAIN_ENABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_VIEWER_GAIN_DISABLED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_VIEWER_GAIN_DISABLED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_SCRIPT_CLEAR_OUTPUT", (long) NATRON_NAMESPACE::NATRON_PIXMAP_SCRIPT_CLEAR_OUTPUT))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_SCRIPT_EXEC_SCRIPT", (long) NATRON_NAMESPACE::NATRON_PIXMAP_SCRIPT_EXEC_SCRIPT))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_SCRIPT_LOAD_EXEC_SCRIPT", (long) NATRON_NAMESPACE::NATRON_PIXMAP_SCRIPT_LOAD_EXEC_SCRIPT))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_SCRIPT_LOAD_SCRIPT", (long) NATRON_NAMESPACE::NATRON_PIXMAP_SCRIPT_LOAD_SCRIPT))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_SCRIPT_NEXT_SCRIPT", (long) NATRON_NAMESPACE::NATRON_PIXMAP_SCRIPT_NEXT_SCRIPT))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_SCRIPT_OUTPUT_PANE_ACTIVATED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_SCRIPT_OUTPUT_PANE_ACTIVATED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_SCRIPT_OUTPUT_PANE_DEACTIVATED", (long) NATRON_NAMESPACE::NATRON_PIXMAP_SCRIPT_OUTPUT_PANE_DEACTIVATED))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_SCRIPT_PREVIOUS_SCRIPT", (long) NATRON_NAMESPACE::NATRON_PIXMAP_SCRIPT_PREVIOUS_SCRIPT))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_SCRIPT_SAVE_SCRIPT", (long) NATRON_NAMESPACE::NATRON_PIXMAP_SCRIPT_SAVE_SCRIPT))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_MERGE_ATOP", (long) NATRON_NAMESPACE::NATRON_PIXMAP_MERGE_ATOP))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_MERGE_AVERAGE", (long) NATRON_NAMESPACE::NATRON_PIXMAP_MERGE_AVERAGE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_MERGE_COLOR", (long) NATRON_NAMESPACE::NATRON_PIXMAP_MERGE_COLOR))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_MERGE_COLOR_BURN", (long) NATRON_NAMESPACE::NATRON_PIXMAP_MERGE_COLOR_BURN))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_MERGE_COLOR_DODGE", (long) NATRON_NAMESPACE::NATRON_PIXMAP_MERGE_COLOR_DODGE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_MERGE_CONJOINT_OVER", (long) NATRON_NAMESPACE::NATRON_PIXMAP_MERGE_CONJOINT_OVER))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_MERGE_COPY", (long) NATRON_NAMESPACE::NATRON_PIXMAP_MERGE_COPY))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_MERGE_DIFFERENCE", (long) NATRON_NAMESPACE::NATRON_PIXMAP_MERGE_DIFFERENCE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_MERGE_DISJOINT_OVER", (long) NATRON_NAMESPACE::NATRON_PIXMAP_MERGE_DISJOINT_OVER))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_MERGE_DIVIDE", (long) NATRON_NAMESPACE::NATRON_PIXMAP_MERGE_DIVIDE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_MERGE_EXCLUSION", (long) NATRON_NAMESPACE::NATRON_PIXMAP_MERGE_EXCLUSION))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_MERGE_FREEZE", (long) NATRON_NAMESPACE::NATRON_PIXMAP_MERGE_FREEZE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_MERGE_FROM", (long) NATRON_NAMESPACE::NATRON_PIXMAP_MERGE_FROM))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_MERGE_GEOMETRIC", (long) NATRON_NAMESPACE::NATRON_PIXMAP_MERGE_GEOMETRIC))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_MERGE_GRAIN_EXTRACT", (long) NATRON_NAMESPACE::NATRON_PIXMAP_MERGE_GRAIN_EXTRACT))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_MERGE_GRAIN_MERGE", (long) NATRON_NAMESPACE::NATRON_PIXMAP_MERGE_GRAIN_MERGE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_MERGE_HARD_LIGHT", (long) NATRON_NAMESPACE::NATRON_PIXMAP_MERGE_HARD_LIGHT))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_MERGE_HUE", (long) NATRON_NAMESPACE::NATRON_PIXMAP_MERGE_HUE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_MERGE_HYPOT", (long) NATRON_NAMESPACE::NATRON_PIXMAP_MERGE_HYPOT))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_MERGE_IN", (long) NATRON_NAMESPACE::NATRON_PIXMAP_MERGE_IN))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_MERGE_LUMINOSITY", (long) NATRON_NAMESPACE::NATRON_PIXMAP_MERGE_LUMINOSITY))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_MERGE_MASK", (long) NATRON_NAMESPACE::NATRON_PIXMAP_MERGE_MASK))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_MERGE_MATTE", (long) NATRON_NAMESPACE::NATRON_PIXMAP_MERGE_MATTE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_MERGE_MAX", (long) NATRON_NAMESPACE::NATRON_PIXMAP_MERGE_MAX))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_MERGE_MIN", (long) NATRON_NAMESPACE::NATRON_PIXMAP_MERGE_MIN))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_MERGE_MINUS", (long) NATRON_NAMESPACE::NATRON_PIXMAP_MERGE_MINUS))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_MERGE_MULTIPLY", (long) NATRON_NAMESPACE::NATRON_PIXMAP_MERGE_MULTIPLY))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_MERGE_OUT", (long) NATRON_NAMESPACE::NATRON_PIXMAP_MERGE_OUT))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_MERGE_OVER", (long) NATRON_NAMESPACE::NATRON_PIXMAP_MERGE_OVER))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_MERGE_OVERLAY", (long) NATRON_NAMESPACE::NATRON_PIXMAP_MERGE_OVERLAY))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_MERGE_PINLIGHT", (long) NATRON_NAMESPACE::NATRON_PIXMAP_MERGE_PINLIGHT))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_MERGE_PLUS", (long) NATRON_NAMESPACE::NATRON_PIXMAP_MERGE_PLUS))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_MERGE_REFLECT", (long) NATRON_NAMESPACE::NATRON_PIXMAP_MERGE_REFLECT))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_MERGE_SATURATION", (long) NATRON_NAMESPACE::NATRON_PIXMAP_MERGE_SATURATION))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_MERGE_SCREEN", (long) NATRON_NAMESPACE::NATRON_PIXMAP_MERGE_SCREEN))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_MERGE_SOFT_LIGHT", (long) NATRON_NAMESPACE::NATRON_PIXMAP_MERGE_SOFT_LIGHT))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_MERGE_STENCIL", (long) NATRON_NAMESPACE::NATRON_PIXMAP_MERGE_STENCIL))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_MERGE_UNDER", (long) NATRON_NAMESPACE::NATRON_PIXMAP_MERGE_UNDER))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_MERGE_XOR", (long) NATRON_NAMESPACE::NATRON_PIXMAP_MERGE_XOR))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_ROTO_NODE_ICON", (long) NATRON_NAMESPACE::NATRON_PIXMAP_ROTO_NODE_ICON))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_LINK_CURSOR", (long) NATRON_NAMESPACE::NATRON_PIXMAP_LINK_CURSOR))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_LINK_MULT_CURSOR", (long) NATRON_NAMESPACE::NATRON_PIXMAP_LINK_MULT_CURSOR))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_APP_ICON", (long) NATRON_NAMESPACE::NATRON_PIXMAP_APP_ICON))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_INTERP_LINEAR", (long) NATRON_NAMESPACE::NATRON_PIXMAP_INTERP_LINEAR))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_INTERP_CURVE", (long) NATRON_NAMESPACE::NATRON_PIXMAP_INTERP_CURVE))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_INTERP_CONSTANT", (long) NATRON_NAMESPACE::NATRON_PIXMAP_INTERP_CONSTANT))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_INTERP_BREAK", (long) NATRON_NAMESPACE::NATRON_PIXMAP_INTERP_BREAK))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_INTERP_CURVE_C", (long) NATRON_NAMESPACE::NATRON_PIXMAP_INTERP_CURVE_C))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_INTERP_CURVE_H", (long) NATRON_NAMESPACE::NATRON_PIXMAP_INTERP_CURVE_H))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_INTERP_CURVE_R", (long) NATRON_NAMESPACE::NATRON_PIXMAP_INTERP_CURVE_R))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "NATRON_PIXMAP_INTERP_CURVE_Z", (long) NATRON_NAMESPACE::NATRON_PIXMAP_INTERP_CURVE_Z))
        return ;
    // Register converter for enum 'NATRON_NAMESPACE::PixmapEnum'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX],
            NATRON_NAMESPACE_PixmapEnum_CppToPython_NATRON_NAMESPACE_PixmapEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            NATRON_NAMESPACE_PixmapEnum_PythonToCpp_NATRON_NAMESPACE_PixmapEnum,
            is_NATRON_NAMESPACE_PixmapEnum_PythonToCpp_NATRON_NAMESPACE_PixmapEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PIXMAPENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::PixmapEnum");
        Shiboken::Conversions::registerConverterName(converter, "PixmapEnum");
    }
    // End of 'PixmapEnum' enum.

    // Initialization of enum 'ViewerContextLayoutTypeEnum'.
    SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_VIEWERCONTEXTLAYOUTTYPEENUM_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_NATRON_NAMESPACE_Type,
        "ViewerContextLayoutTypeEnum",
        "NatronEngine.Natron.ViewerContextLayoutTypeEnum",
        "Natron::ViewerContextLayoutTypeEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_VIEWERCONTEXTLAYOUTTYPEENUM_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_VIEWERCONTEXTLAYOUTTYPEENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eViewerContextLayoutTypeSpacing", (long) NATRON_NAMESPACE::eViewerContextLayoutTypeSpacing))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_VIEWERCONTEXTLAYOUTTYPEENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eViewerContextLayoutTypeSeparator", (long) NATRON_NAMESPACE::eViewerContextLayoutTypeSeparator))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_VIEWERCONTEXTLAYOUTTYPEENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eViewerContextLayoutTypeStretchAfter", (long) NATRON_NAMESPACE::eViewerContextLayoutTypeStretchAfter))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_VIEWERCONTEXTLAYOUTTYPEENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eViewerContextLayoutTypeAddNewLine", (long) NATRON_NAMESPACE::eViewerContextLayoutTypeAddNewLine))
        return ;
    // Register converter for enum 'NATRON_NAMESPACE::ViewerContextLayoutTypeEnum'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_VIEWERCONTEXTLAYOUTTYPEENUM_IDX],
            NATRON_NAMESPACE_ViewerContextLayoutTypeEnum_CppToPython_NATRON_NAMESPACE_ViewerContextLayoutTypeEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            NATRON_NAMESPACE_ViewerContextLayoutTypeEnum_PythonToCpp_NATRON_NAMESPACE_ViewerContextLayoutTypeEnum,
            is_NATRON_NAMESPACE_ViewerContextLayoutTypeEnum_PythonToCpp_NATRON_NAMESPACE_ViewerContextLayoutTypeEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_VIEWERCONTEXTLAYOUTTYPEENUM_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_VIEWERCONTEXTLAYOUTTYPEENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::ViewerContextLayoutTypeEnum");
        Shiboken::Conversions::registerConverterName(converter, "ViewerContextLayoutTypeEnum");
    }
    // End of 'ViewerContextLayoutTypeEnum' enum.

    // Initialization of enum 'AnimationLevelEnum'.
    SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ANIMATIONLEVELENUM_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_NATRON_NAMESPACE_Type,
        "AnimationLevelEnum",
        "NatronEngine.Natron.AnimationLevelEnum",
        "Natron::AnimationLevelEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ANIMATIONLEVELENUM_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ANIMATIONLEVELENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eAnimationLevelNone", (long) NATRON_NAMESPACE::eAnimationLevelNone))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ANIMATIONLEVELENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eAnimationLevelInterpolatedValue", (long) NATRON_NAMESPACE::eAnimationLevelInterpolatedValue))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ANIMATIONLEVELENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eAnimationLevelOnKeyframe", (long) NATRON_NAMESPACE::eAnimationLevelOnKeyframe))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ANIMATIONLEVELENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eAnimationLevelExpression", (long) NATRON_NAMESPACE::eAnimationLevelExpression))
        return ;
    // Register converter for enum 'NATRON_NAMESPACE::AnimationLevelEnum'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ANIMATIONLEVELENUM_IDX],
            NATRON_NAMESPACE_AnimationLevelEnum_CppToPython_NATRON_NAMESPACE_AnimationLevelEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            NATRON_NAMESPACE_AnimationLevelEnum_PythonToCpp_NATRON_NAMESPACE_AnimationLevelEnum,
            is_NATRON_NAMESPACE_AnimationLevelEnum_PythonToCpp_NATRON_NAMESPACE_AnimationLevelEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ANIMATIONLEVELENUM_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ANIMATIONLEVELENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::AnimationLevelEnum");
        Shiboken::Conversions::registerConverterName(converter, "AnimationLevelEnum");
    }
    // End of 'AnimationLevelEnum' enum.

    // Initialization of enum 'ImagePremultiplicationEnum'.
    SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_IMAGEPREMULTIPLICATIONENUM_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_NATRON_NAMESPACE_Type,
        "ImagePremultiplicationEnum",
        "NatronEngine.Natron.ImagePremultiplicationEnum",
        "Natron::ImagePremultiplicationEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_IMAGEPREMULTIPLICATIONENUM_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_IMAGEPREMULTIPLICATIONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eImagePremultiplicationOpaque", (long) NATRON_NAMESPACE::eImagePremultiplicationOpaque))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_IMAGEPREMULTIPLICATIONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eImagePremultiplicationPremultiplied", (long) NATRON_NAMESPACE::eImagePremultiplicationPremultiplied))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_IMAGEPREMULTIPLICATIONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eImagePremultiplicationUnPremultiplied", (long) NATRON_NAMESPACE::eImagePremultiplicationUnPremultiplied))
        return ;
    // Register converter for enum 'NATRON_NAMESPACE::ImagePremultiplicationEnum'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_IMAGEPREMULTIPLICATIONENUM_IDX],
            NATRON_NAMESPACE_ImagePremultiplicationEnum_CppToPython_NATRON_NAMESPACE_ImagePremultiplicationEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            NATRON_NAMESPACE_ImagePremultiplicationEnum_PythonToCpp_NATRON_NAMESPACE_ImagePremultiplicationEnum,
            is_NATRON_NAMESPACE_ImagePremultiplicationEnum_PythonToCpp_NATRON_NAMESPACE_ImagePremultiplicationEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_IMAGEPREMULTIPLICATIONENUM_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_IMAGEPREMULTIPLICATIONENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::ImagePremultiplicationEnum");
        Shiboken::Conversions::registerConverterName(converter, "ImagePremultiplicationEnum");
    }
    // End of 'ImagePremultiplicationEnum' enum.

    // Initialization of enum 'ImageBitDepthEnum'.
    SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_IMAGEBITDEPTHENUM_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_NATRON_NAMESPACE_Type,
        "ImageBitDepthEnum",
        "NatronEngine.Natron.ImageBitDepthEnum",
        "Natron::ImageBitDepthEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_IMAGEBITDEPTHENUM_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_IMAGEBITDEPTHENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eImageBitDepthNone", (long) NATRON_NAMESPACE::eImageBitDepthNone))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_IMAGEBITDEPTHENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eImageBitDepthByte", (long) NATRON_NAMESPACE::eImageBitDepthByte))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_IMAGEBITDEPTHENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eImageBitDepthShort", (long) NATRON_NAMESPACE::eImageBitDepthShort))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_IMAGEBITDEPTHENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eImageBitDepthHalf", (long) NATRON_NAMESPACE::eImageBitDepthHalf))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_IMAGEBITDEPTHENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eImageBitDepthFloat", (long) NATRON_NAMESPACE::eImageBitDepthFloat))
        return ;
    // Register converter for enum 'NATRON_NAMESPACE::ImageBitDepthEnum'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_IMAGEBITDEPTHENUM_IDX],
            NATRON_NAMESPACE_ImageBitDepthEnum_CppToPython_NATRON_NAMESPACE_ImageBitDepthEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            NATRON_NAMESPACE_ImageBitDepthEnum_PythonToCpp_NATRON_NAMESPACE_ImageBitDepthEnum,
            is_NATRON_NAMESPACE_ImageBitDepthEnum_PythonToCpp_NATRON_NAMESPACE_ImageBitDepthEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_IMAGEBITDEPTHENUM_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_IMAGEBITDEPTHENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::ImageBitDepthEnum");
        Shiboken::Conversions::registerConverterName(converter, "ImageBitDepthEnum");
    }
    // End of 'ImageBitDepthEnum' enum.

    // Initialization of enum 'OrientationEnum'.
    SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ORIENTATIONENUM_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_NATRON_NAMESPACE_Type,
        "OrientationEnum",
        "NatronEngine.Natron.OrientationEnum",
        "Natron::OrientationEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ORIENTATIONENUM_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ORIENTATIONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eOrientationHorizontal", (long) NATRON_NAMESPACE::eOrientationHorizontal))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ORIENTATIONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eOrientationVertical", (long) NATRON_NAMESPACE::eOrientationVertical))
        return ;
    // Register converter for enum 'NATRON_NAMESPACE::OrientationEnum'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ORIENTATIONENUM_IDX],
            NATRON_NAMESPACE_OrientationEnum_CppToPython_NATRON_NAMESPACE_OrientationEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            NATRON_NAMESPACE_OrientationEnum_PythonToCpp_NATRON_NAMESPACE_OrientationEnum,
            is_NATRON_NAMESPACE_OrientationEnum_PythonToCpp_NATRON_NAMESPACE_OrientationEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ORIENTATIONENUM_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ORIENTATIONENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::OrientationEnum");
        Shiboken::Conversions::registerConverterName(converter, "OrientationEnum");
    }
    // End of 'OrientationEnum' enum.

    // Initialization of enum 'RotoStrokeType'.
    SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ROTOSTROKETYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_NATRON_NAMESPACE_Type,
        "RotoStrokeType",
        "NatronEngine.Natron.RotoStrokeType",
        "Natron::RotoStrokeType");
    if (!SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ROTOSTROKETYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ROTOSTROKETYPE_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eRotoStrokeTypeSolid", (long) NATRON_NAMESPACE::eRotoStrokeTypeSolid))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ROTOSTROKETYPE_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eRotoStrokeTypeEraser", (long) NATRON_NAMESPACE::eRotoStrokeTypeEraser))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ROTOSTROKETYPE_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eRotoStrokeTypeClone", (long) NATRON_NAMESPACE::eRotoStrokeTypeClone))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ROTOSTROKETYPE_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eRotoStrokeTypeReveal", (long) NATRON_NAMESPACE::eRotoStrokeTypeReveal))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ROTOSTROKETYPE_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eRotoStrokeTypeBlur", (long) NATRON_NAMESPACE::eRotoStrokeTypeBlur))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ROTOSTROKETYPE_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eRotoStrokeTypeSharpen", (long) NATRON_NAMESPACE::eRotoStrokeTypeSharpen))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ROTOSTROKETYPE_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eRotoStrokeTypeSmear", (long) NATRON_NAMESPACE::eRotoStrokeTypeSmear))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ROTOSTROKETYPE_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eRotoStrokeTypeDodge", (long) NATRON_NAMESPACE::eRotoStrokeTypeDodge))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ROTOSTROKETYPE_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eRotoStrokeTypeBurn", (long) NATRON_NAMESPACE::eRotoStrokeTypeBurn))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ROTOSTROKETYPE_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eRotoStrokeTypeComp", (long) NATRON_NAMESPACE::eRotoStrokeTypeComp))
        return ;
    // Register converter for enum 'NATRON_NAMESPACE::RotoStrokeType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ROTOSTROKETYPE_IDX],
            NATRON_NAMESPACE_RotoStrokeType_CppToPython_NATRON_NAMESPACE_RotoStrokeType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            NATRON_NAMESPACE_RotoStrokeType_PythonToCpp_NATRON_NAMESPACE_RotoStrokeType,
            is_NATRON_NAMESPACE_RotoStrokeType_PythonToCpp_NATRON_NAMESPACE_RotoStrokeType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ROTOSTROKETYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_ROTOSTROKETYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::RotoStrokeType");
        Shiboken::Conversions::registerConverterName(converter, "RotoStrokeType");
    }
    // End of 'RotoStrokeType' enum.

    // Initialization of enum 'PenType'.
    SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PENTYPE_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_NATRON_NAMESPACE_Type,
        "PenType",
        "NatronEngine.Natron.PenType",
        "Natron::PenType");
    if (!SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PENTYPE_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PENTYPE_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "ePenTypeLMB", (long) NATRON_NAMESPACE::ePenTypeLMB))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PENTYPE_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "ePenTypeMMB", (long) NATRON_NAMESPACE::ePenTypeMMB))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PENTYPE_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "ePenTypeRMB", (long) NATRON_NAMESPACE::ePenTypeRMB))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PENTYPE_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "ePenTypePen", (long) NATRON_NAMESPACE::ePenTypePen))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PENTYPE_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "ePenTypeCursor", (long) NATRON_NAMESPACE::ePenTypeCursor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PENTYPE_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "ePenTypeEraser", (long) NATRON_NAMESPACE::ePenTypeEraser))
        return ;
    // Register converter for enum 'NATRON_NAMESPACE::PenType'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PENTYPE_IDX],
            NATRON_NAMESPACE_PenType_CppToPython_NATRON_NAMESPACE_PenType);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            NATRON_NAMESPACE_PenType_PythonToCpp_NATRON_NAMESPACE_PenType,
            is_NATRON_NAMESPACE_PenType_PythonToCpp_NATRON_NAMESPACE_PenType_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PENTYPE_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_PENTYPE_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::PenType");
        Shiboken::Conversions::registerConverterName(converter, "PenType");
    }
    // End of 'PenType' enum.

    // Initialization of enum 'MergingFunctionEnum'.
    SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_NATRON_NAMESPACE_Type,
        "MergingFunctionEnum",
        "NatronEngine.Natron.MergingFunctionEnum",
        "Natron::MergingFunctionEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eMergeATop", (long) NATRON_NAMESPACE::eMergeATop))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eMergeAverage", (long) NATRON_NAMESPACE::eMergeAverage))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eMergeColor", (long) NATRON_NAMESPACE::eMergeColor))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eMergeColorBurn", (long) NATRON_NAMESPACE::eMergeColorBurn))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eMergeColorDodge", (long) NATRON_NAMESPACE::eMergeColorDodge))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eMergeConjointOver", (long) NATRON_NAMESPACE::eMergeConjointOver))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eMergeCopy", (long) NATRON_NAMESPACE::eMergeCopy))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eMergeDifference", (long) NATRON_NAMESPACE::eMergeDifference))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eMergeDisjointOver", (long) NATRON_NAMESPACE::eMergeDisjointOver))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eMergeDivide", (long) NATRON_NAMESPACE::eMergeDivide))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eMergeExclusion", (long) NATRON_NAMESPACE::eMergeExclusion))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eMergeFreeze", (long) NATRON_NAMESPACE::eMergeFreeze))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eMergeFrom", (long) NATRON_NAMESPACE::eMergeFrom))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eMergeGeometric", (long) NATRON_NAMESPACE::eMergeGeometric))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eMergeGrainExtract", (long) NATRON_NAMESPACE::eMergeGrainExtract))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eMergeGrainMerge", (long) NATRON_NAMESPACE::eMergeGrainMerge))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eMergeHardLight", (long) NATRON_NAMESPACE::eMergeHardLight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eMergeHue", (long) NATRON_NAMESPACE::eMergeHue))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eMergeHypot", (long) NATRON_NAMESPACE::eMergeHypot))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eMergeIn", (long) NATRON_NAMESPACE::eMergeIn))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eMergeLuminosity", (long) NATRON_NAMESPACE::eMergeLuminosity))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eMergeMask", (long) NATRON_NAMESPACE::eMergeMask))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eMergeMatte", (long) NATRON_NAMESPACE::eMergeMatte))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eMergeMax", (long) NATRON_NAMESPACE::eMergeMax))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eMergeMin", (long) NATRON_NAMESPACE::eMergeMin))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eMergeMinus", (long) NATRON_NAMESPACE::eMergeMinus))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eMergeMultiply", (long) NATRON_NAMESPACE::eMergeMultiply))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eMergeOut", (long) NATRON_NAMESPACE::eMergeOut))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eMergeOver", (long) NATRON_NAMESPACE::eMergeOver))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eMergeOverlay", (long) NATRON_NAMESPACE::eMergeOverlay))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eMergePinLight", (long) NATRON_NAMESPACE::eMergePinLight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eMergePlus", (long) NATRON_NAMESPACE::eMergePlus))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eMergeReflect", (long) NATRON_NAMESPACE::eMergeReflect))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eMergeSaturation", (long) NATRON_NAMESPACE::eMergeSaturation))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eMergeScreen", (long) NATRON_NAMESPACE::eMergeScreen))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eMergeSoftLight", (long) NATRON_NAMESPACE::eMergeSoftLight))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eMergeStencil", (long) NATRON_NAMESPACE::eMergeStencil))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eMergeUnder", (long) NATRON_NAMESPACE::eMergeUnder))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eMergeXOR", (long) NATRON_NAMESPACE::eMergeXOR))
        return ;
    // Register converter for enum 'NATRON_NAMESPACE::MergingFunctionEnum'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX],
            NATRON_NAMESPACE_MergingFunctionEnum_CppToPython_NATRON_NAMESPACE_MergingFunctionEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            NATRON_NAMESPACE_MergingFunctionEnum_PythonToCpp_NATRON_NAMESPACE_MergingFunctionEnum,
            is_NATRON_NAMESPACE_MergingFunctionEnum_PythonToCpp_NATRON_NAMESPACE_MergingFunctionEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_MERGINGFUNCTIONENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::MergingFunctionEnum");
        Shiboken::Conversions::registerConverterName(converter, "MergingFunctionEnum");
    }
    // End of 'MergingFunctionEnum' enum.

    // Initialization of enum 'TableChangeReasonEnum'.
    SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_TABLECHANGEREASONENUM_IDX] = Shiboken::Enum::createScopedEnum(&Sbk_NATRON_NAMESPACE_Type,
        "TableChangeReasonEnum",
        "NatronEngine.Natron.TableChangeReasonEnum",
        "Natron::TableChangeReasonEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_TABLECHANGEREASONENUM_IDX])
        return ;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_TABLECHANGEREASONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eTableChangeReasonInternal", (long) NATRON_NAMESPACE::eTableChangeReasonInternal))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_TABLECHANGEREASONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eTableChangeReasonViewer", (long) NATRON_NAMESPACE::eTableChangeReasonViewer))
        return ;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_TABLECHANGEREASONENUM_IDX],
        &Sbk_NATRON_NAMESPACE_Type, "eTableChangeReasonPanel", (long) NATRON_NAMESPACE::eTableChangeReasonPanel))
        return ;
    // Register converter for enum 'NATRON_NAMESPACE::TableChangeReasonEnum'.
    {
        SbkConverter* converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_TABLECHANGEREASONENUM_IDX],
            NATRON_NAMESPACE_TableChangeReasonEnum_CppToPython_NATRON_NAMESPACE_TableChangeReasonEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            NATRON_NAMESPACE_TableChangeReasonEnum_PythonToCpp_NATRON_NAMESPACE_TableChangeReasonEnum,
            is_NATRON_NAMESPACE_TableChangeReasonEnum_PythonToCpp_NATRON_NAMESPACE_TableChangeReasonEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_TABLECHANGEREASONENUM_IDX], converter);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_NAMESPACE_TABLECHANGEREASONENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::TableChangeReasonEnum");
        Shiboken::Conversions::registerConverterName(converter, "TableChangeReasonEnum");
    }
    // End of 'TableChangeReasonEnum' enum.


    qRegisterMetaType< ::NATRON_NAMESPACE::ActionRetCodeEnum >("Natron::ActionRetCodeEnum");
    qRegisterMetaType< ::NATRON_NAMESPACE::StandardButtonEnum >("Natron::StandardButtonEnum");
    qRegisterMetaType< ::NATRON_NAMESPACE::StandardButtons >("Natron::StandardButtons");
    qRegisterMetaType< ::NATRON_NAMESPACE::KeyframeTypeEnum >("Natron::KeyframeTypeEnum");
    qRegisterMetaType< ::NATRON_NAMESPACE::PixmapEnum >("Natron::PixmapEnum");
    qRegisterMetaType< ::NATRON_NAMESPACE::ViewerContextLayoutTypeEnum >("Natron::ViewerContextLayoutTypeEnum");
    qRegisterMetaType< ::NATRON_NAMESPACE::AnimationLevelEnum >("Natron::AnimationLevelEnum");
    qRegisterMetaType< ::NATRON_NAMESPACE::ImagePremultiplicationEnum >("Natron::ImagePremultiplicationEnum");
    qRegisterMetaType< ::NATRON_NAMESPACE::ImageBitDepthEnum >("Natron::ImageBitDepthEnum");
    qRegisterMetaType< ::NATRON_NAMESPACE::OrientationEnum >("Natron::OrientationEnum");
    qRegisterMetaType< ::NATRON_NAMESPACE::RotoStrokeType >("Natron::RotoStrokeType");
    qRegisterMetaType< ::NATRON_NAMESPACE::PenType >("Natron::PenType");
    qRegisterMetaType< ::NATRON_NAMESPACE::MergingFunctionEnum >("Natron::MergingFunctionEnum");
    qRegisterMetaType< ::NATRON_NAMESPACE::TableChangeReasonEnum >("Natron::TableChangeReasonEnum");
}
