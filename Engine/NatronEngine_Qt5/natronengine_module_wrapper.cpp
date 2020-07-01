
#include <sbkpython.h>
#include "Global/Macros.h"
CLANG_DIAG_OFF(mismatched-tags)
GCC_DIAG_OFF(unused-parameter)
GCC_DIAG_OFF(missing-field-initializers)
GCC_DIAG_OFF(missing-declarations)
GCC_DIAG_OFF(uninitialized)
GCC_DIAG_UNUSED_LOCAL_TYPEDEFS_OFF
#include <shiboken.h> // produces many warnings
#include <algorithm>
#include <signature.h>
#ifndef QT_NO_VERSION_TAGGING
#  define QT_NO_VERSION_TAGGING
#endif
#include <QDebug>
#include <pyside.h>
#include <qapp_macro.h>
#include "natronengine_python.h"



// Extra includes

// Current module's type array.
PyTypeObject** SbkNatronEngineTypes = nullptr;
// Current module's PyObject pointer.
PyObject* SbkNatronEngineModuleObject = nullptr;
// Current module's converter array.
SbkConverter** SbkNatronEngineTypeConverters = nullptr;
void cleanTypesAttributes(void) {
    if (PY_VERSION_HEX >= 0x03000000 && PY_VERSION_HEX < 0x03060000)
        return; // PYSIDE-953: testbinding crashes in Python 3.5 when hasattr touches types!
    for (int i = 0, imax = SBK_NatronEngine_IDX_COUNT; i < imax; i++) {
        PyObject *pyType = reinterpret_cast<PyObject*>(SbkNatronEngineTypes[i]);
        if (pyType && PyObject_HasAttrString(pyType, "staticMetaObject"))
            PyObject_SetAttrString(pyType, "staticMetaObject", Py_None);
    }
}
// Global functions ------------------------------------------------------------

static PyMethodDef NatronEngine_methods[] = {
    {0} // Sentinel
};

// Classes initialization functions ------------------------------------------------------------
void init_Natron(PyObject* module);
void init_Natron_RectI(PyObject* module);
void init_Natron_RectD(PyObject* module);
void init_Natron_Python_UserParamHolder(PyObject* module);
void init_Natron_Python_StrokePoint(PyObject* module);
void init_Natron_Python_PyOverlayParamDesc(PyObject* module);
void init_Natron_Python_PyOverlayInteract(PyObject* module);
void init_Natron_Python_PyTransformOverlayInteract(PyObject* module);
void init_Natron_Python_PyPointOverlayInteract(PyObject* module);
void init_Natron_Python_PyCornerPinOverlayInteract(PyObject* module);
void init_Natron_Python_PyCoreApplication(PyObject* module);
void init_Natron_Python_Param(PyObject* module);
void init_Natron_Python_SeparatorParam(PyObject* module);
void init_Natron_Python_ParametricParam(PyObject* module);
void init_Natron_Python_PageParam(PyObject* module);
void init_Natron_Python_NodeCreationProperty(PyObject* module);
void init_Natron_Python_StringNodeCreationProperty(PyObject* module);
void init_Natron_Python_ItemsTable(PyObject* module);
void init_Natron_Python_Roto(PyObject* module);
void init_Natron_Python_Tracker(PyObject* module);
void init_Natron_Python_ItemBase(PyObject* module);
void init_Natron_Python_StrokeItem(PyObject* module);
void init_Natron_Python_Track(PyObject* module);
void init_Natron_Python_IntNodeCreationProperty(PyObject* module);
void init_Natron_Python_Int3DTuple(PyObject* module);
void init_Natron_Python_Int2DTuple(PyObject* module);
void init_Natron_Python_ImageLayer(PyObject* module);
void init_Natron_Python_GroupParam(PyObject* module);
void init_Natron_Python_Group(PyObject* module);
void init_Natron_Python_FloatNodeCreationProperty(PyObject* module);
void init_Natron_Python_ExprUtils(PyObject* module);
void init_Natron_Python_Effect(PyObject* module);
void init_Natron_Python_Double3DTuple(PyObject* module);
void init_Natron_Python_Double2DTuple(PyObject* module);
void init_Natron_Python_ColorTuple(PyObject* module);
void init_Natron_Python_ButtonParam(PyObject* module);
void init_Natron_Python_BoolNodeCreationProperty(PyObject* module);
void init_Natron_Python_BezierCurve(PyObject* module);
void init_Natron_Python_AppSettings(PyObject* module);
void init_Natron_Python_App(PyObject* module);
void init_Natron_Python_AnimatedParam(PyObject* module);
void init_Natron_Python_StringParamBase(PyObject* module);
void init_Natron_Python_StringParam(PyObject* module);
void init_Natron_Python_PathParam(PyObject* module);
void init_Natron_Python_FileParam(PyObject* module);
void init_Natron_Python_DoubleParam(PyObject* module);
void init_Natron_Python_Double2DParam(PyObject* module);
void init_Natron_Python_Double3DParam(PyObject* module);
void init_Natron_Python_IntParam(PyObject* module);
void init_Natron_Python_Int2DParam(PyObject* module);
void init_Natron_Python_Int3DParam(PyObject* module);
void init_Natron_Python_ColorParam(PyObject* module);
void init_Natron_Python_ChoiceParam(PyObject* module);
void init_Natron_Python_BooleanParam(PyObject* module);

// Required modules' type and converter arrays.
PyTypeObject** SbkPySide2_QtCoreTypes;
SbkConverter** SbkPySide2_QtCoreTypeConverters;

// Module initialization ------------------------------------------------------------

// Primitive Type converters.

// C++ to Python conversion for type 'std::size_t'.
static PyObject* std_size_t_CppToPython_std_size_t(const void* cppIn) {
    auto &cppInRef = *reinterpret_cast<::std::size_t*>(const_cast<void *>(cppIn));

                    return PyLong_FromSize_t(cppInRef);

}
// Python to C++ conversions for type 'std::size_t'.
static void PyLong_PythonToCpp_std_size_t(PyObject* pyIn, void* cppOut) {

    *reinterpret_cast<::std::size_t*>(cppOut) = std::size_t(PyLong_AsSsize_t(pyIn));

}
static PythonToCppFunc is_PyLong_PythonToCpp_std_size_t_Convertible(PyObject* pyIn) {
    if (PyLong_Check(pyIn))
        return PyLong_PythonToCpp_std_size_t;
    return {};
}


// Container Type converters.

// C++ to Python conversion for type 'const std::map<QString,Natron::Python::NodeCreationProperty* > &'.
static PyObject* conststd_map_QString_Natron_Python_NodeCreationPropertyPTR_REF_CppToPython_conststd_map_QString_Natron_Python_NodeCreationPropertyPTR_REF(const void* cppIn) {
    auto &cppInRef = *reinterpret_cast<::std::map<QString,Natron::Python::NodeCreationProperty* >*>(const_cast<void *>(cppIn));

                    // TEMPLATE - stdMapToPyDict - START
            PyObject* pyOut = PyDict_New();
            ::std::map<QString,Natron::Python::NodeCreationProperty* >::const_iterator it = cppInRef.begin();
            for (; it != cppInRef.end(); ++it) {
            ::QString key = it->first;
            ::Natron::Python::NodeCreationProperty* value = it->second;
            PyObject* pyKey = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &key);
            PyObject* pyValue = Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_NODECREATIONPROPERTY_IDX]), value);
            PyDict_SetItem(pyOut, pyKey, pyValue);
            Py_DECREF(pyKey);
            Py_DECREF(pyValue);
            }
            return pyOut;
    // TEMPLATE - stdMapToPyDict - END

}
static void conststd_map_QString_Natron_Python_NodeCreationPropertyPTR_REF_PythonToCpp_conststd_map_QString_Natron_Python_NodeCreationPropertyPTR_REF(PyObject* pyIn, void* cppOut) {
    auto &cppOutRef = *reinterpret_cast<::std::map<QString,Natron::Python::NodeCreationProperty* >*>(cppOut);

                    // TEMPLATE - pyDictToStdMap - START
        PyObject* key;
        PyObject* value;
        Py_ssize_t pos = 0;
        while (PyDict_Next(pyIn, &pos, &key, &value)) {
        ::QString cppKey;
        Shiboken::Conversions::pythonToCppCopy(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], key, &(cppKey));
        ::Natron::Python::NodeCreationProperty* cppValue{nullptr};
        Shiboken::Conversions::pythonToCppPointer(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_NODECREATIONPROPERTY_IDX]), value, &(cppValue));
        cppOutRef.insert(std::make_pair(cppKey, cppValue));
        }
    // TEMPLATE - pyDictToStdMap - END

}
static PythonToCppFunc is_conststd_map_QString_Natron_Python_NodeCreationPropertyPTR_REF_PythonToCpp_conststd_map_QString_Natron_Python_NodeCreationPropertyPTR_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleDictTypes(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], false, *PepType_SGTP(SbkNatronEngineTypes[SBK_NATRON_PYTHON_NODECREATIONPROPERTY_IDX])->converter, true, pyIn))
        return conststd_map_QString_Natron_Python_NodeCreationPropertyPTR_REF_PythonToCpp_conststd_map_QString_Natron_Python_NodeCreationPropertyPTR_REF;
    return {};
}

// C++ to Python conversion for type 'std::list<Natron::Python::Effect* >'.
static PyObject* std_list_Natron_Python_EffectPTR__CppToPython_std_list_Natron_Python_EffectPTR_(const void* cppIn) {
    auto &cppInRef = *reinterpret_cast<::std::list<Natron::Python::Effect* >*>(const_cast<void *>(cppIn));

                    // TEMPLATE - stdListToPyList - START
            PyObject* pyOut = PyList_New((int) cppInRef.size());
            ::std::list<Natron::Python::Effect* >::const_iterator it = cppInRef.begin();
            for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::Natron::Python::Effect* cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX]), cppItem));
            }
            return pyOut;
    // TEMPLATE - stdListToPyList - END

}
static void std_list_Natron_Python_EffectPTR__PythonToCpp_std_list_Natron_Python_EffectPTR_(PyObject* pyIn, void* cppOut) {
    auto &cppOutRef = *reinterpret_cast<::std::list<Natron::Python::Effect* >*>(cppOut);

                    // TEMPLATE - pyListToStdList - START
        for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::Natron::Python::Effect* cppItem{nullptr};
        Shiboken::Conversions::pythonToCppPointer(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX]), pyItem, &(cppItem));
        cppOutRef.push_back(cppItem);
        }
    // TEMPLATE - pyListToStdList - END

}
static PythonToCppFunc is_std_list_Natron_Python_EffectPTR__PythonToCpp_std_list_Natron_Python_EffectPTR__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbkNatronEngineTypes[SBK_NATRON_PYTHON_EFFECT_IDX], pyIn))
        return std_list_Natron_Python_EffectPTR__PythonToCpp_std_list_Natron_Python_EffectPTR_;
    return {};
}

// C++ to Python conversion for type 'std::list<QString >'.
static PyObject* std_list_QString__CppToPython_std_list_QString_(const void* cppIn) {
    auto &cppInRef = *reinterpret_cast<::std::list<QString >*>(const_cast<void *>(cppIn));

                    // TEMPLATE - stdListToPyList - START
            PyObject* pyOut = PyList_New((int) cppInRef.size());
            ::std::list<QString >::const_iterator it = cppInRef.begin();
            for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QString cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppItem));
            }
            return pyOut;
    // TEMPLATE - stdListToPyList - END

}
static void std_list_QString__PythonToCpp_std_list_QString_(PyObject* pyIn, void* cppOut) {
    auto &cppOutRef = *reinterpret_cast<::std::list<QString >*>(cppOut);

                    // TEMPLATE - pyListToStdList - START
        for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QString cppItem;
        Shiboken::Conversions::pythonToCppCopy(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], pyItem, &(cppItem));
        cppOutRef.push_back(cppItem);
        }
    // TEMPLATE - pyListToStdList - END

}
static PythonToCppFunc is_std_list_QString__PythonToCpp_std_list_QString__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], pyIn))
        return std_list_QString__PythonToCpp_std_list_QString_;
    return {};
}

// C++ to Python conversion for type 'const std::list<int > &'.
static PyObject* conststd_list_int_REF_CppToPython_conststd_list_int_REF(const void* cppIn) {
    auto &cppInRef = *reinterpret_cast<::std::list<int >*>(const_cast<void *>(cppIn));

                    // TEMPLATE - stdListToPyList - START
            PyObject* pyOut = PyList_New((int) cppInRef.size());
            ::std::list<int >::const_iterator it = cppInRef.begin();
            for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            int cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppItem));
            }
            return pyOut;
    // TEMPLATE - stdListToPyList - END

}
static void conststd_list_int_REF_PythonToCpp_conststd_list_int_REF(PyObject* pyIn, void* cppOut) {
    auto &cppOutRef = *reinterpret_cast<::std::list<int >*>(cppOut);

                    // TEMPLATE - pyListToStdList - START
        for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        int cppItem;
        Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyItem, &(cppItem));
        cppOutRef.push_back(cppItem);
        }
    // TEMPLATE - pyListToStdList - END

}
static PythonToCppFunc is_conststd_list_int_REF_PythonToCpp_conststd_list_int_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyIn))
        return conststd_list_int_REF_PythonToCpp_conststd_list_int_REF;
    return {};
}

// C++ to Python conversion for type 'std::list<Natron::Python::Param* >'.
static PyObject* std_list_Natron_Python_ParamPTR__CppToPython_std_list_Natron_Python_ParamPTR_(const void* cppIn) {
    auto &cppInRef = *reinterpret_cast<::std::list<Natron::Python::Param* >*>(const_cast<void *>(cppIn));

                    // TEMPLATE - stdListToPyList - START
            PyObject* pyOut = PyList_New((int) cppInRef.size());
            ::std::list<Natron::Python::Param* >::const_iterator it = cppInRef.begin();
            for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::Natron::Python::Param* cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX]), cppItem));
            }
            return pyOut;
    // TEMPLATE - stdListToPyList - END

}
static void std_list_Natron_Python_ParamPTR__PythonToCpp_std_list_Natron_Python_ParamPTR_(PyObject* pyIn, void* cppOut) {
    auto &cppOutRef = *reinterpret_cast<::std::list<Natron::Python::Param* >*>(cppOut);

                    // TEMPLATE - pyListToStdList - START
        for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::Natron::Python::Param* cppItem{nullptr};
        Shiboken::Conversions::pythonToCppPointer(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX]), pyItem, &(cppItem));
        cppOutRef.push_back(cppItem);
        }
    // TEMPLATE - pyListToStdList - END

}
static PythonToCppFunc is_std_list_Natron_Python_ParamPTR__PythonToCpp_std_list_Natron_Python_ParamPTR__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX], pyIn))
        return std_list_Natron_Python_ParamPTR__PythonToCpp_std_list_Natron_Python_ParamPTR_;
    return {};
}

// C++ to Python conversion for type 'std::list<Natron::Python::ItemBase* >'.
static PyObject* std_list_Natron_Python_ItemBasePTR__CppToPython_std_list_Natron_Python_ItemBasePTR_(const void* cppIn) {
    auto &cppInRef = *reinterpret_cast<::std::list<Natron::Python::ItemBase* >*>(const_cast<void *>(cppIn));

                    // TEMPLATE - stdListToPyList - START
            PyObject* pyOut = PyList_New((int) cppInRef.size());
            ::std::list<Natron::Python::ItemBase* >::const_iterator it = cppInRef.begin();
            for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::Natron::Python::ItemBase* cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ITEMBASE_IDX]), cppItem));
            }
            return pyOut;
    // TEMPLATE - stdListToPyList - END

}
static void std_list_Natron_Python_ItemBasePTR__PythonToCpp_std_list_Natron_Python_ItemBasePTR_(PyObject* pyIn, void* cppOut) {
    auto &cppOutRef = *reinterpret_cast<::std::list<Natron::Python::ItemBase* >*>(cppOut);

                    // TEMPLATE - pyListToStdList - START
        for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::Natron::Python::ItemBase* cppItem{nullptr};
        Shiboken::Conversions::pythonToCppPointer(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ITEMBASE_IDX]), pyItem, &(cppItem));
        cppOutRef.push_back(cppItem);
        }
    // TEMPLATE - pyListToStdList - END

}
static PythonToCppFunc is_std_list_Natron_Python_ItemBasePTR__PythonToCpp_std_list_Natron_Python_ItemBasePTR__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ITEMBASE_IDX], pyIn))
        return std_list_Natron_Python_ItemBasePTR__PythonToCpp_std_list_Natron_Python_ItemBasePTR_;
    return {};
}

// C++ to Python conversion for type 'const std::vector<bool > &'.
static PyObject* conststd_vector_bool_REF_CppToPython_conststd_vector_bool_REF(const void* cppIn) {
    auto &cppInRef = *reinterpret_cast<::std::vector<bool >*>(const_cast<void *>(cppIn));

                    // TEMPLATE - stdVectorToPyList - START
            ::std::vector<bool >::size_type vectorSize = cppInRef.size();
            PyObject* pyOut = PyList_New((int) vectorSize);
            for (::std::vector<bool >::size_type idx = 0; idx < vectorSize; ++idx) {
            bool cppItem(cppInRef[idx]);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppItem));
            }
            return pyOut;
    // TEMPLATE - stdVectorToPyList - END

}
static void conststd_vector_bool_REF_PythonToCpp_conststd_vector_bool_REF(PyObject* pyIn, void* cppOut) {
    auto &cppOutRef = *reinterpret_cast<::std::vector<bool >*>(cppOut);

                    // TEMPLATE - pySeqToStdVector - START
        int vectorSize = PySequence_Size(pyIn);
        cppOutRef.reserve(vectorSize);
        for (int idx = 0; idx < vectorSize; ++idx) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, idx));
        bool cppItem;
        Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyItem, &(cppItem));
        cppOutRef.push_back(cppItem);
        }
    // TEMPLATE - pySeqToStdVector - END

}
static PythonToCppFunc is_conststd_vector_bool_REF_PythonToCpp_conststd_vector_bool_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), pyIn))
        return conststd_vector_bool_REF_PythonToCpp_conststd_vector_bool_REF;
    return {};
}

// C++ to Python conversion for type 'std::pair<QString,QString >'.
static PyObject* std_pair_QString_QString__CppToPython_std_pair_QString_QString_(const void* cppIn) {
    auto &cppInRef = *reinterpret_cast<::std::pair<QString,QString >*>(const_cast<void *>(cppIn));

                    PyObject* pyOut = PyTuple_New(2);
                    PyTuple_SET_ITEM(pyOut, 0, Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppInRef.first));
                    PyTuple_SET_ITEM(pyOut, 1, Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppInRef.second));
                    return pyOut;

}
static void std_pair_QString_QString__PythonToCpp_std_pair_QString_QString_(PyObject* pyIn, void* cppOut) {
    auto &cppOutRef = *reinterpret_cast<::std::pair<QString,QString >*>(cppOut);

                    Shiboken::Conversions::pythonToCppCopy(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], PySequence_Fast_GET_ITEM(pyIn, 0), &(cppOutRef.first));
                    Shiboken::Conversions::pythonToCppCopy(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], PySequence_Fast_GET_ITEM(pyIn, 1), &(cppOutRef.second));

}
static PythonToCppFunc is_std_pair_QString_QString__PythonToCpp_std_pair_QString_QString__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertiblePairTypes(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], false, SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], false, pyIn))
        return std_pair_QString_QString__PythonToCpp_std_pair_QString_QString_;
    return {};
}

// C++ to Python conversion for type 'const std::list<std::pair< QString,QString > > &'.
static PyObject* conststd_list_std_pair_QString_QString__REF_CppToPython_conststd_list_std_pair_QString_QString__REF(const void* cppIn) {
    auto &cppInRef = *reinterpret_cast<::std::list<std::pair< QString,QString > >*>(const_cast<void *>(cppIn));

                    // TEMPLATE - stdListToPyList - START
            PyObject* pyOut = PyList_New((int) cppInRef.size());
            ::std::list<std::pair< QString,QString > >::const_iterator it = cppInRef.begin();
            for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::std::pair<QString,QString > cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_PAIR_QSTRING_QSTRING_IDX], &cppItem));
            }
            return pyOut;
    // TEMPLATE - stdListToPyList - END

}
static void conststd_list_std_pair_QString_QString__REF_PythonToCpp_conststd_list_std_pair_QString_QString__REF(PyObject* pyIn, void* cppOut) {
    auto &cppOutRef = *reinterpret_cast<::std::list<std::pair< QString,QString > >*>(cppOut);

                    // TEMPLATE - pyListToStdList - START
        for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::std::pair<QString,QString > cppItem;
        Shiboken::Conversions::pythonToCppCopy(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_PAIR_QSTRING_QSTRING_IDX], pyItem, &(cppItem));
        cppOutRef.push_back(cppItem);
        }
    // TEMPLATE - pyListToStdList - END

}
static PythonToCppFunc is_conststd_list_std_pair_QString_QString__REF_PythonToCpp_conststd_list_std_pair_QString_QString__REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_PAIR_QSTRING_QSTRING_IDX], pyIn))
        return conststd_list_std_pair_QString_QString__REF_PythonToCpp_conststd_list_std_pair_QString_QString__REF;
    return {};
}

// C++ to Python conversion for type 'std::list<Natron::Python::ItemsTable* >'.
static PyObject* std_list_Natron_Python_ItemsTablePTR__CppToPython_std_list_Natron_Python_ItemsTablePTR_(const void* cppIn) {
    auto &cppInRef = *reinterpret_cast<::std::list<Natron::Python::ItemsTable* >*>(const_cast<void *>(cppIn));

                    // TEMPLATE - stdListToPyList - START
            PyObject* pyOut = PyList_New((int) cppInRef.size());
            ::std::list<Natron::Python::ItemsTable* >::const_iterator it = cppInRef.begin();
            for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::Natron::Python::ItemsTable* cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ITEMSTABLE_IDX]), cppItem));
            }
            return pyOut;
    // TEMPLATE - stdListToPyList - END

}
static void std_list_Natron_Python_ItemsTablePTR__PythonToCpp_std_list_Natron_Python_ItemsTablePTR_(PyObject* pyIn, void* cppOut) {
    auto &cppOutRef = *reinterpret_cast<::std::list<Natron::Python::ItemsTable* >*>(cppOut);

                    // TEMPLATE - pyListToStdList - START
        for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::Natron::Python::ItemsTable* cppItem{nullptr};
        Shiboken::Conversions::pythonToCppPointer(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ITEMSTABLE_IDX]), pyItem, &(cppItem));
        cppOutRef.push_back(cppItem);
        }
    // TEMPLATE - pyListToStdList - END

}
static PythonToCppFunc is_std_list_Natron_Python_ItemsTablePTR__PythonToCpp_std_list_Natron_Python_ItemsTablePTR__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ITEMSTABLE_IDX], pyIn))
        return std_list_Natron_Python_ItemsTablePTR__PythonToCpp_std_list_Natron_Python_ItemsTablePTR_;
    return {};
}

// C++ to Python conversion for type 'std::list<Natron::Python::ImageLayer >'.
static PyObject* std_list_Natron_Python_ImageLayer__CppToPython_std_list_Natron_Python_ImageLayer_(const void* cppIn) {
    auto &cppInRef = *reinterpret_cast<::std::list<Natron::Python::ImageLayer >*>(const_cast<void *>(cppIn));

                    // TEMPLATE - stdListToPyList - START
            PyObject* pyOut = PyList_New((int) cppInRef.size());
            ::std::list<Natron::Python::ImageLayer >::const_iterator it = cppInRef.begin();
            for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::Natron::Python::ImageLayer cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_IMAGELAYER_IDX]), &cppItem));
            }
            return pyOut;
    // TEMPLATE - stdListToPyList - END

}
static void std_list_Natron_Python_ImageLayer__PythonToCpp_std_list_Natron_Python_ImageLayer_(PyObject* pyIn, void* cppOut) {
    auto &cppOutRef = *reinterpret_cast<::std::list<Natron::Python::ImageLayer >*>(cppOut);

                    // TEMPLATE - pyListToStdList - START
        for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::Natron::Python::ImageLayer cppItem = ::Natron::Python::ImageLayer(::QString(), ::QString(), ::QStringList());
        Shiboken::Conversions::pythonToCppCopy(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_IMAGELAYER_IDX]), pyItem, &(cppItem));
        cppOutRef.push_back(cppItem);
        }
    // TEMPLATE - pyListToStdList - END

}
static PythonToCppFunc is_std_list_Natron_Python_ImageLayer__PythonToCpp_std_list_Natron_Python_ImageLayer__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_IMAGELAYER_IDX]), pyIn))
        return std_list_Natron_Python_ImageLayer__PythonToCpp_std_list_Natron_Python_ImageLayer_;
    return {};
}

// C++ to Python conversion for type 'const std::map<QString,QString > &'.
static PyObject* conststd_map_QString_QString_REF_CppToPython_conststd_map_QString_QString_REF(const void* cppIn) {
    auto &cppInRef = *reinterpret_cast<::std::map<QString,QString >*>(const_cast<void *>(cppIn));

                    // TEMPLATE - stdMapToPyDict - START
            PyObject* pyOut = PyDict_New();
            ::std::map<QString,QString >::const_iterator it = cppInRef.begin();
            for (; it != cppInRef.end(); ++it) {
            ::QString key = it->first;
            ::QString value = it->second;
            PyObject* pyKey = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &key);
            PyObject* pyValue = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &value);
            PyDict_SetItem(pyOut, pyKey, pyValue);
            Py_DECREF(pyKey);
            Py_DECREF(pyValue);
            }
            return pyOut;
    // TEMPLATE - stdMapToPyDict - END

}
static void conststd_map_QString_QString_REF_PythonToCpp_conststd_map_QString_QString_REF(PyObject* pyIn, void* cppOut) {
    auto &cppOutRef = *reinterpret_cast<::std::map<QString,QString >*>(cppOut);

                    // TEMPLATE - pyDictToStdMap - START
        PyObject* key;
        PyObject* value;
        Py_ssize_t pos = 0;
        while (PyDict_Next(pyIn, &pos, &key, &value)) {
        ::QString cppKey;
        Shiboken::Conversions::pythonToCppCopy(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], key, &(cppKey));
        ::QString cppValue;
        Shiboken::Conversions::pythonToCppCopy(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], value, &(cppValue));
        cppOutRef.insert(std::make_pair(cppKey, cppValue));
        }
    // TEMPLATE - pyDictToStdMap - END

}
static PythonToCppFunc is_conststd_map_QString_QString_REF_PythonToCpp_conststd_map_QString_QString_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleDictTypes(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], false, SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], false, pyIn))
        return conststd_map_QString_QString_REF_PythonToCpp_conststd_map_QString_QString_REF;
    return {};
}

// C++ to Python conversion for type 'const std::vector<double > &'.
static PyObject* conststd_vector_double_REF_CppToPython_conststd_vector_double_REF(const void* cppIn) {
    auto &cppInRef = *reinterpret_cast<::std::vector<double >*>(const_cast<void *>(cppIn));

                    // TEMPLATE - stdVectorToPyList - START
            ::std::vector<double >::size_type vectorSize = cppInRef.size();
            PyObject* pyOut = PyList_New((int) vectorSize);
            for (::std::vector<double >::size_type idx = 0; idx < vectorSize; ++idx) {
            double cppItem(cppInRef[idx]);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<double>(), &cppItem));
            }
            return pyOut;
    // TEMPLATE - stdVectorToPyList - END

}
static void conststd_vector_double_REF_PythonToCpp_conststd_vector_double_REF(PyObject* pyIn, void* cppOut) {
    auto &cppOutRef = *reinterpret_cast<::std::vector<double >*>(cppOut);

                    // TEMPLATE - pySeqToStdVector - START
        int vectorSize = PySequence_Size(pyIn);
        cppOutRef.reserve(vectorSize);
        for (int idx = 0; idx < vectorSize; ++idx) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, idx));
        double cppItem;
        Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<double>(), pyItem, &(cppItem));
        cppOutRef.push_back(cppItem);
        }
    // TEMPLATE - pySeqToStdVector - END

}
static PythonToCppFunc is_conststd_vector_double_REF_PythonToCpp_conststd_vector_double_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(Shiboken::Conversions::PrimitiveTypeConverter<double>(), pyIn))
        return conststd_vector_double_REF_PythonToCpp_conststd_vector_double_REF;
    return {};
}

// C++ to Python conversion for type 'const std::vector<std::string > &'.
static PyObject* conststd_vector_std_string_REF_CppToPython_conststd_vector_std_string_REF(const void* cppIn) {
    auto &cppInRef = *reinterpret_cast<::std::vector<std::string >*>(const_cast<void *>(cppIn));

                    // TEMPLATE - stdVectorToPyList - START
            ::std::vector<std::string >::size_type vectorSize = cppInRef.size();
            PyObject* pyOut = PyList_New((int) vectorSize);
            for (::std::vector<std::string >::size_type idx = 0; idx < vectorSize; ++idx) {
            ::std::string cppItem(cppInRef[idx]);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), &cppItem));
            }
            return pyOut;
    // TEMPLATE - stdVectorToPyList - END

}
static void conststd_vector_std_string_REF_PythonToCpp_conststd_vector_std_string_REF(PyObject* pyIn, void* cppOut) {
    auto &cppOutRef = *reinterpret_cast<::std::vector<std::string >*>(cppOut);

                    // TEMPLATE - pySeqToStdVector - START
        int vectorSize = PySequence_Size(pyIn);
        cppOutRef.reserve(vectorSize);
        for (int idx = 0; idx < vectorSize; ++idx) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, idx));
        ::std::string cppItem;
        Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), pyItem, &(cppItem));
        cppOutRef.push_back(cppItem);
        }
    // TEMPLATE - pySeqToStdVector - END

}
static PythonToCppFunc is_conststd_vector_std_string_REF_PythonToCpp_conststd_vector_std_string_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), pyIn))
        return conststd_vector_std_string_REF_PythonToCpp_conststd_vector_std_string_REF;
    return {};
}

// C++ to Python conversion for type 'const std::vector<int > &'.
static PyObject* conststd_vector_int_REF_CppToPython_conststd_vector_int_REF(const void* cppIn) {
    auto &cppInRef = *reinterpret_cast<::std::vector<int >*>(const_cast<void *>(cppIn));

                    // TEMPLATE - stdVectorToPyList - START
            ::std::vector<int >::size_type vectorSize = cppInRef.size();
            PyObject* pyOut = PyList_New((int) vectorSize);
            for (::std::vector<int >::size_type idx = 0; idx < vectorSize; ++idx) {
            int cppItem(cppInRef[idx]);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppItem));
            }
            return pyOut;
    // TEMPLATE - stdVectorToPyList - END

}
static void conststd_vector_int_REF_PythonToCpp_conststd_vector_int_REF(PyObject* pyIn, void* cppOut) {
    auto &cppOutRef = *reinterpret_cast<::std::vector<int >*>(cppOut);

                    // TEMPLATE - pySeqToStdVector - START
        int vectorSize = PySequence_Size(pyIn);
        cppOutRef.reserve(vectorSize);
        for (int idx = 0; idx < vectorSize; ++idx) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, idx));
        int cppItem;
        Shiboken::Conversions::pythonToCppCopy(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyItem, &(cppItem));
        cppOutRef.push_back(cppItem);
        }
    // TEMPLATE - pySeqToStdVector - END

}
static PythonToCppFunc is_conststd_vector_int_REF_PythonToCpp_conststd_vector_int_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(Shiboken::Conversions::PrimitiveTypeConverter<int>(), pyIn))
        return conststd_vector_int_REF_PythonToCpp_conststd_vector_int_REF;
    return {};
}

// C++ to Python conversion for type 'std::list<Natron::RectI >'.
static PyObject* std_list_Natron_RectI__CppToPython_std_list_Natron_RectI_(const void* cppIn) {
    auto &cppInRef = *reinterpret_cast<::std::list<Natron::RectI >*>(const_cast<void *>(cppIn));

                    // TEMPLATE - stdListToPyList - START
            PyObject* pyOut = PyList_New((int) cppInRef.size());
            ::std::list<Natron::RectI >::const_iterator it = cppInRef.begin();
            for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::Natron::RectI cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX]), &cppItem));
            }
            return pyOut;
    // TEMPLATE - stdListToPyList - END

}
static void std_list_Natron_RectI__PythonToCpp_std_list_Natron_RectI_(PyObject* pyIn, void* cppOut) {
    auto &cppOutRef = *reinterpret_cast<::std::list<Natron::RectI >*>(cppOut);

                    // TEMPLATE - pyListToStdList - START
        for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::Natron::RectI cppItem;
        Shiboken::Conversions::pythonToCppCopy(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX]), pyItem, &(cppItem));
        cppOutRef.push_back(cppItem);
        }
    // TEMPLATE - pyListToStdList - END

}
static PythonToCppFunc is_std_list_Natron_RectI__PythonToCpp_std_list_Natron_RectI__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_RECTI_IDX]), pyIn))
        return std_list_Natron_RectI__PythonToCpp_std_list_Natron_RectI_;
    return {};
}

// C++ to Python conversion for type 'std::list<std::vector< std::string > > *'.
static PyObject* std_list_std_vector_std_string__PTR_CppToPython_std_list_std_vector_std_string__PTR(const void* cppIn) {
    auto &cppInRef = *reinterpret_cast<::std::list<std::vector< std::string > >*>(const_cast<void *>(cppIn));

                    // TEMPLATE - stdListToPyList - START
            PyObject* pyOut = PyList_New((int) cppInRef.size());
            ::std::list<std::vector< std::string > >::const_iterator it = cppInRef.begin();
            for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::std::vector<std::string > cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_VECTOR_STD_STRING_IDX], &cppItem));
            }
            return pyOut;
    // TEMPLATE - stdListToPyList - END

}
static void std_list_std_vector_std_string__PTR_PythonToCpp_std_list_std_vector_std_string__PTR(PyObject* pyIn, void* cppOut) {
    auto &cppOutRef = *reinterpret_cast<::std::list<std::vector< std::string > >*>(cppOut);

                    // TEMPLATE - pyListToStdList - START
        for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::std::vector<std::string > cppItem;
        Shiboken::Conversions::pythonToCppCopy(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_VECTOR_STD_STRING_IDX], pyItem, &(cppItem));
        cppOutRef.push_back(cppItem);
        }
    // TEMPLATE - pyListToStdList - END

}
static PythonToCppFunc is_std_list_std_vector_std_string__PTR_PythonToCpp_std_list_std_vector_std_string__PTR_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_VECTOR_STD_STRING_IDX], pyIn))
        return std_list_std_vector_std_string__PTR_PythonToCpp_std_list_std_vector_std_string__PTR;
    return {};
}

// C++ to Python conversion for type 'std::map<QString,Natron::Python::PyOverlayParamDesc >'.
static PyObject* std_map_QString_Natron_Python_PyOverlayParamDesc__CppToPython_std_map_QString_Natron_Python_PyOverlayParamDesc_(const void* cppIn) {
    auto &cppInRef = *reinterpret_cast<::std::map<QString,Natron::Python::PyOverlayParamDesc >*>(const_cast<void *>(cppIn));

                    // TEMPLATE - stdMapToPyDict - START
            PyObject* pyOut = PyDict_New();
            ::std::map<QString,Natron::Python::PyOverlayParamDesc >::const_iterator it = cppInRef.begin();
            for (; it != cppInRef.end(); ++it) {
            ::QString key = it->first;
            ::Natron::Python::PyOverlayParamDesc value = it->second;
            PyObject* pyKey = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &key);
            PyObject* pyValue = Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYOVERLAYPARAMDESC_IDX]), &value);
            PyDict_SetItem(pyOut, pyKey, pyValue);
            Py_DECREF(pyKey);
            Py_DECREF(pyValue);
            }
            return pyOut;
    // TEMPLATE - stdMapToPyDict - END

}
static void std_map_QString_Natron_Python_PyOverlayParamDesc__PythonToCpp_std_map_QString_Natron_Python_PyOverlayParamDesc_(PyObject* pyIn, void* cppOut) {
    auto &cppOutRef = *reinterpret_cast<::std::map<QString,Natron::Python::PyOverlayParamDesc >*>(cppOut);

                    // TEMPLATE - pyDictToStdMap - START
        PyObject* key;
        PyObject* value;
        Py_ssize_t pos = 0;
        while (PyDict_Next(pyIn, &pos, &key, &value)) {
        ::QString cppKey;
        Shiboken::Conversions::pythonToCppCopy(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], key, &(cppKey));
        ::Natron::Python::PyOverlayParamDesc cppValue;
        Shiboken::Conversions::pythonToCppCopy(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYOVERLAYPARAMDESC_IDX]), value, &(cppValue));
        cppOutRef.insert(std::make_pair(cppKey, cppValue));
        }
    // TEMPLATE - pyDictToStdMap - END

}
static PythonToCppFunc is_std_map_QString_Natron_Python_PyOverlayParamDesc__PythonToCpp_std_map_QString_Natron_Python_PyOverlayParamDesc__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleDictTypes(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], false, *PepType_SGTP(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PYOVERLAYPARAMDESC_IDX])->converter, false, pyIn))
        return std_map_QString_Natron_Python_PyOverlayParamDesc__PythonToCpp_std_map_QString_Natron_Python_PyOverlayParamDesc_;
    return {};
}

// C++ to Python conversion for type 'std::list<Natron::Python::StrokePoint >'.
static PyObject* std_list_Natron_Python_StrokePoint__CppToPython_std_list_Natron_Python_StrokePoint_(const void* cppIn) {
    auto &cppInRef = *reinterpret_cast<::std::list<Natron::Python::StrokePoint >*>(const_cast<void *>(cppIn));

                    // TEMPLATE - stdListToPyList - START
            PyObject* pyOut = PyList_New((int) cppInRef.size());
            ::std::list<Natron::Python::StrokePoint >::const_iterator it = cppInRef.begin();
            for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::Natron::Python::StrokePoint cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STROKEPOINT_IDX]), &cppItem));
            }
            return pyOut;
    // TEMPLATE - stdListToPyList - END

}
static void std_list_Natron_Python_StrokePoint__PythonToCpp_std_list_Natron_Python_StrokePoint_(PyObject* pyIn, void* cppOut) {
    auto &cppOutRef = *reinterpret_cast<::std::list<Natron::Python::StrokePoint >*>(cppOut);

                    // TEMPLATE - pyListToStdList - START
        for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::Natron::Python::StrokePoint cppItem;
        Shiboken::Conversions::pythonToCppCopy(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STROKEPOINT_IDX]), pyItem, &(cppItem));
        cppOutRef.push_back(cppItem);
        }
    // TEMPLATE - pyListToStdList - END

}
static PythonToCppFunc is_std_list_Natron_Python_StrokePoint__PythonToCpp_std_list_Natron_Python_StrokePoint__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STROKEPOINT_IDX]), pyIn))
        return std_list_Natron_Python_StrokePoint__PythonToCpp_std_list_Natron_Python_StrokePoint_;
    return {};
}

// C++ to Python conversion for type 'std::list<std::list< Natron::Python::StrokePoint > >'.
static PyObject* std_list_std_list_Natron_Python_StrokePoint___CppToPython_std_list_std_list_Natron_Python_StrokePoint__(const void* cppIn) {
    auto &cppInRef = *reinterpret_cast<::std::list<std::list< Natron::Python::StrokePoint > >*>(const_cast<void *>(cppIn));

                    // TEMPLATE - stdListToPyList - START
            PyObject* pyOut = PyList_New((int) cppInRef.size());
            ::std::list<std::list< Natron::Python::StrokePoint > >::const_iterator it = cppInRef.begin();
            for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::std::list<Natron::Python::StrokePoint > cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_NATRON_PYTHON_STROKEPOINT_IDX], &cppItem));
            }
            return pyOut;
    // TEMPLATE - stdListToPyList - END

}
static void std_list_std_list_Natron_Python_StrokePoint___PythonToCpp_std_list_std_list_Natron_Python_StrokePoint__(PyObject* pyIn, void* cppOut) {
    auto &cppOutRef = *reinterpret_cast<::std::list<std::list< Natron::Python::StrokePoint > >*>(cppOut);

                    // TEMPLATE - pyListToStdList - START
        for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::std::list<Natron::Python::StrokePoint > cppItem;
        Shiboken::Conversions::pythonToCppCopy(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_NATRON_PYTHON_STROKEPOINT_IDX], pyItem, &(cppItem));
        cppOutRef.push_back(cppItem);
        }
    // TEMPLATE - pyListToStdList - END

}
static PythonToCppFunc is_std_list_std_list_Natron_Python_StrokePoint___PythonToCpp_std_list_std_list_Natron_Python_StrokePoint___Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_NATRON_PYTHON_STROKEPOINT_IDX], pyIn))
        return std_list_std_list_Natron_Python_StrokePoint___PythonToCpp_std_list_std_list_Natron_Python_StrokePoint__;
    return {};
}

// C++ to Python conversion for type 'const std::list<Natron::Python::Track* > &'.
static PyObject* conststd_list_Natron_Python_TrackPTR_REF_CppToPython_conststd_list_Natron_Python_TrackPTR_REF(const void* cppIn) {
    auto &cppInRef = *reinterpret_cast<::std::list<Natron::Python::Track* >*>(const_cast<void *>(cppIn));

                    // TEMPLATE - stdListToPyList - START
            PyObject* pyOut = PyList_New((int) cppInRef.size());
            ::std::list<Natron::Python::Track* >::const_iterator it = cppInRef.begin();
            for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::Natron::Python::Track* cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::pointerToPython(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_TRACK_IDX]), cppItem));
            }
            return pyOut;
    // TEMPLATE - stdListToPyList - END

}
static void conststd_list_Natron_Python_TrackPTR_REF_PythonToCpp_conststd_list_Natron_Python_TrackPTR_REF(PyObject* pyIn, void* cppOut) {
    auto &cppOutRef = *reinterpret_cast<::std::list<Natron::Python::Track* >*>(cppOut);

                    // TEMPLATE - pyListToStdList - START
        for (int i = 0; i < PySequence_Size(pyIn); i++) {
        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::Natron::Python::Track* cppItem{nullptr};
        Shiboken::Conversions::pythonToCppPointer(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_TRACK_IDX]), pyItem, &(cppItem));
        cppOutRef.push_back(cppItem);
        }
    // TEMPLATE - pyListToStdList - END

}
static PythonToCppFunc is_conststd_list_Natron_Python_TrackPTR_REF_PythonToCpp_conststd_list_Natron_Python_TrackPTR_REF_Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::checkSequenceTypes(SbkNatronEngineTypes[SBK_NATRON_PYTHON_TRACK_IDX], pyIn))
        return conststd_list_Natron_Python_TrackPTR_REF_PythonToCpp_conststd_list_Natron_Python_TrackPTR_REF;
    return {};
}

// C++ to Python conversion for type 'QList<QVariant >'.
static PyObject* _QList_QVariant__CppToPython__QList_QVariant_(const void* cppIn) {
    auto &cppInRef = *reinterpret_cast<::QList<QVariant >*>(const_cast<void *>(cppIn));

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QVariant >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QVariant cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QVARIANT_IDX], &cppItem));
        }
        return pyOut;
    // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QVariant__PythonToCpp__QList_QVariant_(PyObject* pyIn, void* cppOut) {
    auto &cppOutRef = *reinterpret_cast<::QList<QVariant >*>(cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0, size = PySequence_Size(pyIn); i < size; i++) {

        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QVariant cppItem;
        Shiboken::Conversions::pythonToCppCopy(SbkPySide2_QtCoreTypeConverters[SBK_QVARIANT_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QVariant__PythonToCpp__QList_QVariant__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(SbkPySide2_QtCoreTypeConverters[SBK_QVARIANT_IDX], pyIn))
        return _QList_QVariant__PythonToCpp__QList_QVariant_;
    return {};
}

// C++ to Python conversion for type 'QList<QString >'.
static PyObject* _QList_QString__CppToPython__QList_QString_(const void* cppIn) {
    auto &cppInRef = *reinterpret_cast<::QList<QString >*>(const_cast<void *>(cppIn));

                // TEMPLATE - cpplist_to_pylist_conversion - START
        PyObject* pyOut = PyList_New((int) cppInRef.size());
        ::QList<QString >::const_iterator it = cppInRef.begin();
        for (int idx = 0; it != cppInRef.end(); ++it, ++idx) {
            ::QString cppItem(*it);
            PyList_SET_ITEM(pyOut, idx, Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppItem));
        }
        return pyOut;
    // TEMPLATE - cpplist_to_pylist_conversion - END

}
static void _QList_QString__PythonToCpp__QList_QString_(PyObject* pyIn, void* cppOut) {
    auto &cppOutRef = *reinterpret_cast<::QList<QString >*>(cppOut);

                // TEMPLATE - pyseq_to_cpplist_conversion - START
    for (int i = 0, size = PySequence_Size(pyIn); i < size; i++) {

        Shiboken::AutoDecRef pyItem(PySequence_GetItem(pyIn, i));
        ::QString cppItem;
        Shiboken::Conversions::pythonToCppCopy(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], pyItem, &(cppItem));
        cppOutRef << cppItem;
    }
    // TEMPLATE - pyseq_to_cpplist_conversion - END

}
static PythonToCppFunc is__QList_QString__PythonToCpp__QList_QString__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleSequenceTypes(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], pyIn))
        return _QList_QString__PythonToCpp__QList_QString_;
    return {};
}

// C++ to Python conversion for type 'QMap<QString,QVariant >'.
static PyObject* _QMap_QString_QVariant__CppToPython__QMap_QString_QVariant_(const void* cppIn) {
    auto &cppInRef = *reinterpret_cast<::QMap<QString,QVariant >*>(const_cast<void *>(cppIn));

                // TEMPLATE - cppmap_to_pymap_conversion - START
          PyObject *pyOut = PyDict_New();
          for (::QMap<QString,QVariant >::const_iterator it = cppInRef.begin(), end = cppInRef.end(); it != end; ++it) {
              ::QString key = it.key();
              ::QVariant value = it.value();
              PyObject *pyKey = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &key);
              PyObject *pyValue = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QVARIANT_IDX], &value);
              PyDict_SetItem(pyOut, pyKey, pyValue);
              Py_DECREF(pyKey);
              Py_DECREF(pyValue);
          }
          return pyOut;
    // TEMPLATE - cppmap_to_pymap_conversion - END

}
static void _QMap_QString_QVariant__PythonToCpp__QMap_QString_QVariant_(PyObject* pyIn, void* cppOut) {
    auto &cppOutRef = *reinterpret_cast<::QMap<QString,QVariant >*>(cppOut);

                // TEMPLATE - pydict_to_cppmap_conversion - START
      PyObject *key;
      PyObject *value;
      Py_ssize_t pos = 0;
      while (PyDict_Next(pyIn, &pos, &key, &value)) {
          ::QString cppKey;
        Shiboken::Conversions::pythonToCppCopy(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], key, &(cppKey));
          ::QVariant cppValue;
        Shiboken::Conversions::pythonToCppCopy(SbkPySide2_QtCoreTypeConverters[SBK_QVARIANT_IDX], value, &(cppValue));
          cppOutRef.insert(cppKey, cppValue);
      }
    // TEMPLATE - pydict_to_cppmap_conversion - END

}
static PythonToCppFunc is__QMap_QString_QVariant__PythonToCpp__QMap_QString_QVariant__Convertible(PyObject* pyIn) {
    if (Shiboken::Conversions::convertibleDictTypes(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], false, SbkPySide2_QtCoreTypeConverters[SBK_QVARIANT_IDX], false, pyIn))
        return _QMap_QString_QVariant__PythonToCpp__QMap_QString_QVariant_;
    return {};
}


#if defined _WIN32 || defined __CYGWIN__
    #define SBK_EXPORT_MODULE __declspec(dllexport)
#elif __GNUC__ >= 4
    #define SBK_EXPORT_MODULE __attribute__ ((visibility("default")))
#else
    #define SBK_EXPORT_MODULE
#endif

#ifdef IS_PY3K
static struct PyModuleDef moduledef = {
    /* m_base     */ PyModuleDef_HEAD_INIT,
    /* m_name     */ "NatronEngine",
    /* m_doc      */ nullptr,
    /* m_size     */ -1,
    /* m_methods  */ NatronEngine_methods,
    /* m_reload   */ nullptr,
    /* m_traverse */ nullptr,
    /* m_clear    */ nullptr,
    /* m_free     */ nullptr
};

#endif

// The signatures string for the global functions.
// Multiple signatures have their index "n:" in front.
static const char *NatronEngine_SignatureStrings[] = {
    nullptr}; // Sentinel

SBK_MODULE_INIT_FUNCTION_BEGIN(NatronEngine)
    {
        Shiboken::AutoDecRef requiredModule(Shiboken::Module::import("PySide2.QtCore"));
        if (requiredModule.isNull())
            return SBK_MODULE_INIT_ERROR;
        SbkPySide2_QtCoreTypes = Shiboken::Module::getTypes(requiredModule);
        SbkPySide2_QtCoreTypeConverters = Shiboken::Module::getTypeConverters(requiredModule);
    }

    // Create an array of wrapper types for the current module.
    static PyTypeObject* cppApi[SBK_NatronEngine_IDX_COUNT];
    SbkNatronEngineTypes = cppApi;

    // Create an array of primitive type converters for the current module.
    static SbkConverter* sbkConverters[SBK_NatronEngine_CONVERTERS_IDX_COUNT];
    SbkNatronEngineTypeConverters = sbkConverters;

#ifdef IS_PY3K
    PyObject* module = Shiboken::Module::create("NatronEngine", &moduledef);
#else
    PyObject* module = Shiboken::Module::create("NatronEngine", NatronEngine_methods);
#endif

    // Make module available from global scope
    SbkNatronEngineModuleObject = module;

    // Initialize classes in the type system
    init_Natron(module);
    init_Natron_RectI(reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_IDX])->tp_dict);
    init_Natron_RectD(reinterpret_cast<PyTypeObject *>(SbkNatronEngineTypes[SBK_NATRON_IDX])->tp_dict);
    init_Natron_Python_UserParamHolder(module);
    init_Natron_Python_StrokePoint(module);
    init_Natron_Python_PyOverlayParamDesc(module);
    init_Natron_Python_PyOverlayInteract(module);
    init_Natron_Python_PyTransformOverlayInteract(module);
    init_Natron_Python_PyPointOverlayInteract(module);
    init_Natron_Python_PyCornerPinOverlayInteract(module);
    init_Natron_Python_PyCoreApplication(module);
    init_Natron_Python_Param(module);
    init_Natron_Python_SeparatorParam(module);
    init_Natron_Python_ParametricParam(module);
    init_Natron_Python_PageParam(module);
    init_Natron_Python_NodeCreationProperty(module);
    init_Natron_Python_StringNodeCreationProperty(module);
    init_Natron_Python_ItemsTable(module);
    init_Natron_Python_Roto(module);
    init_Natron_Python_Tracker(module);
    init_Natron_Python_ItemBase(module);
    init_Natron_Python_StrokeItem(module);
    init_Natron_Python_Track(module);
    init_Natron_Python_IntNodeCreationProperty(module);
    init_Natron_Python_Int3DTuple(module);
    init_Natron_Python_Int2DTuple(module);
    init_Natron_Python_ImageLayer(module);
    init_Natron_Python_GroupParam(module);
    init_Natron_Python_Group(module);
    init_Natron_Python_FloatNodeCreationProperty(module);
    init_Natron_Python_ExprUtils(module);
    init_Natron_Python_Effect(module);
    init_Natron_Python_Double3DTuple(module);
    init_Natron_Python_Double2DTuple(module);
    init_Natron_Python_ColorTuple(module);
    init_Natron_Python_ButtonParam(module);
    init_Natron_Python_BoolNodeCreationProperty(module);
    init_Natron_Python_BezierCurve(module);
    init_Natron_Python_AppSettings(module);
    init_Natron_Python_App(module);
    init_Natron_Python_AnimatedParam(module);
    init_Natron_Python_StringParamBase(module);
    init_Natron_Python_StringParam(module);
    init_Natron_Python_PathParam(module);
    init_Natron_Python_FileParam(module);
    init_Natron_Python_DoubleParam(module);
    init_Natron_Python_Double2DParam(module);
    init_Natron_Python_Double3DParam(module);
    init_Natron_Python_IntParam(module);
    init_Natron_Python_Int2DParam(module);
    init_Natron_Python_Int3DParam(module);
    init_Natron_Python_ColorParam(module);
    init_Natron_Python_ChoiceParam(module);
    init_Natron_Python_BooleanParam(module);

    // Register converter for type 'NatronEngine.std::size_t'.
    SbkNatronEngineTypeConverters[SBK_STD_SIZE_T_IDX] = Shiboken::Conversions::createConverter(&PyLong_Type, std_size_t_CppToPython_std_size_t);
    Shiboken::Conversions::registerConverterName(SbkNatronEngineTypeConverters[SBK_STD_SIZE_T_IDX], "std::size_t");
    // Add user defined implicit conversions to type converter.
    Shiboken::Conversions::addPythonToCppValueConversion(SbkNatronEngineTypeConverters[SBK_STD_SIZE_T_IDX],
        PyLong_PythonToCpp_std_size_t,
        is_PyLong_PythonToCpp_std_size_t_Convertible);


    // Register converter for type 'const std::map<QString,Natron::Python::NodeCreationProperty*>&'.
    SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_MAP_QSTRING_NATRON_PYTHON_NODECREATIONPROPERTYPTR_IDX] = Shiboken::Conversions::createConverter(&PyDict_Type, conststd_map_QString_Natron_Python_NodeCreationPropertyPTR_REF_CppToPython_conststd_map_QString_Natron_Python_NodeCreationPropertyPTR_REF);
    Shiboken::Conversions::registerConverterName(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_MAP_QSTRING_NATRON_PYTHON_NODECREATIONPROPERTYPTR_IDX], "const std::map<QString,Natron::Python::NodeCreationProperty*>&");
    Shiboken::Conversions::registerConverterName(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_MAP_QSTRING_NATRON_PYTHON_NODECREATIONPROPERTYPTR_IDX], "std::map<QString,Natron::Python::NodeCreationProperty*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_MAP_QSTRING_NATRON_PYTHON_NODECREATIONPROPERTYPTR_IDX],
        conststd_map_QString_Natron_Python_NodeCreationPropertyPTR_REF_PythonToCpp_conststd_map_QString_Natron_Python_NodeCreationPropertyPTR_REF,
        is_conststd_map_QString_Natron_Python_NodeCreationPropertyPTR_REF_PythonToCpp_conststd_map_QString_Natron_Python_NodeCreationPropertyPTR_REF_Convertible);

    // Register converter for type 'std::list<Natron::Python::Effect*>'.
    SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_NATRON_PYTHON_EFFECTPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, std_list_Natron_Python_EffectPTR__CppToPython_std_list_Natron_Python_EffectPTR_);
    Shiboken::Conversions::registerConverterName(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_NATRON_PYTHON_EFFECTPTR_IDX], "std::list<Natron::Python::Effect*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_NATRON_PYTHON_EFFECTPTR_IDX],
        std_list_Natron_Python_EffectPTR__PythonToCpp_std_list_Natron_Python_EffectPTR_,
        is_std_list_Natron_Python_EffectPTR__PythonToCpp_std_list_Natron_Python_EffectPTR__Convertible);

    // Register converter for type 'std::list<QString>'.
    SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_QSTRING_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, std_list_QString__CppToPython_std_list_QString_);
    Shiboken::Conversions::registerConverterName(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_QSTRING_IDX], "std::list<QString>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_QSTRING_IDX],
        std_list_QString__PythonToCpp_std_list_QString_,
        is_std_list_QString__PythonToCpp_std_list_QString__Convertible);

    // Register converter for type 'const std::list<int>&'.
    SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_INT_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, conststd_list_int_REF_CppToPython_conststd_list_int_REF);
    Shiboken::Conversions::registerConverterName(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_INT_IDX], "const std::list<int>&");
    Shiboken::Conversions::registerConverterName(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_INT_IDX], "std::list<int>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_INT_IDX],
        conststd_list_int_REF_PythonToCpp_conststd_list_int_REF,
        is_conststd_list_int_REF_PythonToCpp_conststd_list_int_REF_Convertible);

    // Register converter for type 'std::list<Natron::Python::Param*>'.
    SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_NATRON_PYTHON_PARAMPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, std_list_Natron_Python_ParamPTR__CppToPython_std_list_Natron_Python_ParamPTR_);
    Shiboken::Conversions::registerConverterName(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_NATRON_PYTHON_PARAMPTR_IDX], "std::list<Natron::Python::Param*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_NATRON_PYTHON_PARAMPTR_IDX],
        std_list_Natron_Python_ParamPTR__PythonToCpp_std_list_Natron_Python_ParamPTR_,
        is_std_list_Natron_Python_ParamPTR__PythonToCpp_std_list_Natron_Python_ParamPTR__Convertible);

    // Register converter for type 'std::list<Natron::Python::ItemBase*>'.
    SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_NATRON_PYTHON_ITEMBASEPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, std_list_Natron_Python_ItemBasePTR__CppToPython_std_list_Natron_Python_ItemBasePTR_);
    Shiboken::Conversions::registerConverterName(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_NATRON_PYTHON_ITEMBASEPTR_IDX], "std::list<Natron::Python::ItemBase*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_NATRON_PYTHON_ITEMBASEPTR_IDX],
        std_list_Natron_Python_ItemBasePTR__PythonToCpp_std_list_Natron_Python_ItemBasePTR_,
        is_std_list_Natron_Python_ItemBasePTR__PythonToCpp_std_list_Natron_Python_ItemBasePTR__Convertible);

    // Register converter for type 'const std::vector<bool>&'.
    SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_VECTOR_BOOL_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, conststd_vector_bool_REF_CppToPython_conststd_vector_bool_REF);
    Shiboken::Conversions::registerConverterName(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_VECTOR_BOOL_IDX], "const std::vector<bool>&");
    Shiboken::Conversions::registerConverterName(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_VECTOR_BOOL_IDX], "std::vector<bool>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_VECTOR_BOOL_IDX],
        conststd_vector_bool_REF_PythonToCpp_conststd_vector_bool_REF,
        is_conststd_vector_bool_REF_PythonToCpp_conststd_vector_bool_REF_Convertible);

    // Register converter for type 'std::pair<QString,QString>'.
    SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_PAIR_QSTRING_QSTRING_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, std_pair_QString_QString__CppToPython_std_pair_QString_QString_);
    Shiboken::Conversions::registerConverterName(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_PAIR_QSTRING_QSTRING_IDX], "std::pair<QString,QString>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_PAIR_QSTRING_QSTRING_IDX],
        std_pair_QString_QString__PythonToCpp_std_pair_QString_QString_,
        is_std_pair_QString_QString__PythonToCpp_std_pair_QString_QString__Convertible);

    // Register converter for type 'const std::list<std::pair<QString,QString>>&'.
    SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_STD_PAIR_QSTRING_QSTRING_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, conststd_list_std_pair_QString_QString__REF_CppToPython_conststd_list_std_pair_QString_QString__REF);
    Shiboken::Conversions::registerConverterName(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_STD_PAIR_QSTRING_QSTRING_IDX], "const std::list<std::pair<QString,QString>>&");
    Shiboken::Conversions::registerConverterName(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_STD_PAIR_QSTRING_QSTRING_IDX], "std::list<std::pair<QString,QString>>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_STD_PAIR_QSTRING_QSTRING_IDX],
        conststd_list_std_pair_QString_QString__REF_PythonToCpp_conststd_list_std_pair_QString_QString__REF,
        is_conststd_list_std_pair_QString_QString__REF_PythonToCpp_conststd_list_std_pair_QString_QString__REF_Convertible);

    // Register converter for type 'std::list<Natron::Python::ItemsTable*>'.
    SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_NATRON_PYTHON_ITEMSTABLEPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, std_list_Natron_Python_ItemsTablePTR__CppToPython_std_list_Natron_Python_ItemsTablePTR_);
    Shiboken::Conversions::registerConverterName(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_NATRON_PYTHON_ITEMSTABLEPTR_IDX], "std::list<Natron::Python::ItemsTable*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_NATRON_PYTHON_ITEMSTABLEPTR_IDX],
        std_list_Natron_Python_ItemsTablePTR__PythonToCpp_std_list_Natron_Python_ItemsTablePTR_,
        is_std_list_Natron_Python_ItemsTablePTR__PythonToCpp_std_list_Natron_Python_ItemsTablePTR__Convertible);

    // Register converter for type 'std::list<Natron::Python::ImageLayer>'.
    SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_NATRON_PYTHON_IMAGELAYER_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, std_list_Natron_Python_ImageLayer__CppToPython_std_list_Natron_Python_ImageLayer_);
    Shiboken::Conversions::registerConverterName(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_NATRON_PYTHON_IMAGELAYER_IDX], "std::list<Natron::Python::ImageLayer>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_NATRON_PYTHON_IMAGELAYER_IDX],
        std_list_Natron_Python_ImageLayer__PythonToCpp_std_list_Natron_Python_ImageLayer_,
        is_std_list_Natron_Python_ImageLayer__PythonToCpp_std_list_Natron_Python_ImageLayer__Convertible);

    // Register converter for type 'const std::map<QString,QString>&'.
    SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_MAP_QSTRING_QSTRING_IDX] = Shiboken::Conversions::createConverter(&PyDict_Type, conststd_map_QString_QString_REF_CppToPython_conststd_map_QString_QString_REF);
    Shiboken::Conversions::registerConverterName(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_MAP_QSTRING_QSTRING_IDX], "const std::map<QString,QString>&");
    Shiboken::Conversions::registerConverterName(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_MAP_QSTRING_QSTRING_IDX], "std::map<QString,QString>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_MAP_QSTRING_QSTRING_IDX],
        conststd_map_QString_QString_REF_PythonToCpp_conststd_map_QString_QString_REF,
        is_conststd_map_QString_QString_REF_PythonToCpp_conststd_map_QString_QString_REF_Convertible);

    // Register converter for type 'const std::vector<double>&'.
    SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_VECTOR_DOUBLE_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, conststd_vector_double_REF_CppToPython_conststd_vector_double_REF);
    Shiboken::Conversions::registerConverterName(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_VECTOR_DOUBLE_IDX], "const std::vector<double>&");
    Shiboken::Conversions::registerConverterName(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_VECTOR_DOUBLE_IDX], "std::vector<double>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_VECTOR_DOUBLE_IDX],
        conststd_vector_double_REF_PythonToCpp_conststd_vector_double_REF,
        is_conststd_vector_double_REF_PythonToCpp_conststd_vector_double_REF_Convertible);

    // Register converter for type 'const std::vector<std::string>&'.
    SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_VECTOR_STD_STRING_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, conststd_vector_std_string_REF_CppToPython_conststd_vector_std_string_REF);
    Shiboken::Conversions::registerConverterName(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_VECTOR_STD_STRING_IDX], "const std::vector<std::string>&");
    Shiboken::Conversions::registerConverterName(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_VECTOR_STD_STRING_IDX], "std::vector<std::string>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_VECTOR_STD_STRING_IDX],
        conststd_vector_std_string_REF_PythonToCpp_conststd_vector_std_string_REF,
        is_conststd_vector_std_string_REF_PythonToCpp_conststd_vector_std_string_REF_Convertible);

    // Register converter for type 'const std::vector<int>&'.
    SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_VECTOR_INT_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, conststd_vector_int_REF_CppToPython_conststd_vector_int_REF);
    Shiboken::Conversions::registerConverterName(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_VECTOR_INT_IDX], "const std::vector<int>&");
    Shiboken::Conversions::registerConverterName(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_VECTOR_INT_IDX], "std::vector<int>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_VECTOR_INT_IDX],
        conststd_vector_int_REF_PythonToCpp_conststd_vector_int_REF,
        is_conststd_vector_int_REF_PythonToCpp_conststd_vector_int_REF_Convertible);

    // Register converter for type 'std::list<Natron::RectI>'.
    SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_NATRON_RECTI_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, std_list_Natron_RectI__CppToPython_std_list_Natron_RectI_);
    Shiboken::Conversions::registerConverterName(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_NATRON_RECTI_IDX], "std::list<Natron::RectI>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_NATRON_RECTI_IDX],
        std_list_Natron_RectI__PythonToCpp_std_list_Natron_RectI_,
        is_std_list_Natron_RectI__PythonToCpp_std_list_Natron_RectI__Convertible);

    // Register converter for type 'std::list<std::vector<std::string>>*'.
    SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_STD_VECTOR_STD_STRING_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, std_list_std_vector_std_string__PTR_CppToPython_std_list_std_vector_std_string__PTR);
    Shiboken::Conversions::registerConverterName(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_STD_VECTOR_STD_STRING_IDX], "std::list<std::vector<std::string>>*");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_STD_VECTOR_STD_STRING_IDX],
        std_list_std_vector_std_string__PTR_PythonToCpp_std_list_std_vector_std_string__PTR,
        is_std_list_std_vector_std_string__PTR_PythonToCpp_std_list_std_vector_std_string__PTR_Convertible);

    // Register converter for type 'std::map<QString,Natron::Python::PyOverlayParamDesc>'.
    SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_MAP_QSTRING_NATRON_PYTHON_PYOVERLAYPARAMDESC_IDX] = Shiboken::Conversions::createConverter(&PyDict_Type, std_map_QString_Natron_Python_PyOverlayParamDesc__CppToPython_std_map_QString_Natron_Python_PyOverlayParamDesc_);
    Shiboken::Conversions::registerConverterName(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_MAP_QSTRING_NATRON_PYTHON_PYOVERLAYPARAMDESC_IDX], "std::map<QString,Natron::Python::PyOverlayParamDesc>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_MAP_QSTRING_NATRON_PYTHON_PYOVERLAYPARAMDESC_IDX],
        std_map_QString_Natron_Python_PyOverlayParamDesc__PythonToCpp_std_map_QString_Natron_Python_PyOverlayParamDesc_,
        is_std_map_QString_Natron_Python_PyOverlayParamDesc__PythonToCpp_std_map_QString_Natron_Python_PyOverlayParamDesc__Convertible);

    // Register converter for type 'std::list<Natron::Python::StrokePoint>'.
    SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_NATRON_PYTHON_STROKEPOINT_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, std_list_Natron_Python_StrokePoint__CppToPython_std_list_Natron_Python_StrokePoint_);
    Shiboken::Conversions::registerConverterName(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_NATRON_PYTHON_STROKEPOINT_IDX], "std::list<Natron::Python::StrokePoint>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_NATRON_PYTHON_STROKEPOINT_IDX],
        std_list_Natron_Python_StrokePoint__PythonToCpp_std_list_Natron_Python_StrokePoint_,
        is_std_list_Natron_Python_StrokePoint__PythonToCpp_std_list_Natron_Python_StrokePoint__Convertible);

    // Register converter for type 'std::list<std::list<Natron::Python::StrokePoint>>'.
    SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_STD_LIST_NATRON_PYTHON_STROKEPOINT_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, std_list_std_list_Natron_Python_StrokePoint___CppToPython_std_list_std_list_Natron_Python_StrokePoint__);
    Shiboken::Conversions::registerConverterName(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_STD_LIST_NATRON_PYTHON_STROKEPOINT_IDX], "std::list<std::list<Natron::Python::StrokePoint>>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_STD_LIST_NATRON_PYTHON_STROKEPOINT_IDX],
        std_list_std_list_Natron_Python_StrokePoint___PythonToCpp_std_list_std_list_Natron_Python_StrokePoint__,
        is_std_list_std_list_Natron_Python_StrokePoint___PythonToCpp_std_list_std_list_Natron_Python_StrokePoint___Convertible);

    // Register converter for type 'const std::list<Natron::Python::Track*>&'.
    SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_NATRON_PYTHON_TRACKPTR_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, conststd_list_Natron_Python_TrackPTR_REF_CppToPython_conststd_list_Natron_Python_TrackPTR_REF);
    Shiboken::Conversions::registerConverterName(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_NATRON_PYTHON_TRACKPTR_IDX], "const std::list<Natron::Python::Track*>&");
    Shiboken::Conversions::registerConverterName(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_NATRON_PYTHON_TRACKPTR_IDX], "std::list<Natron::Python::Track*>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_STD_LIST_NATRON_PYTHON_TRACKPTR_IDX],
        conststd_list_Natron_Python_TrackPTR_REF_PythonToCpp_conststd_list_Natron_Python_TrackPTR_REF,
        is_conststd_list_Natron_Python_TrackPTR_REF_PythonToCpp_conststd_list_Natron_Python_TrackPTR_REF_Convertible);

    // Register converter for type 'QList<QVariant>'.
    SbkNatronEngineTypeConverters[SBK_NATRONENGINE_QLIST_QVARIANT_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QVariant__CppToPython__QList_QVariant_);
    Shiboken::Conversions::registerConverterName(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_QLIST_QVARIANT_IDX], "QList<QVariant>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_QLIST_QVARIANT_IDX],
        _QList_QVariant__PythonToCpp__QList_QVariant_,
        is__QList_QVariant__PythonToCpp__QList_QVariant__Convertible);

    // Register converter for type 'QList<QString>'.
    SbkNatronEngineTypeConverters[SBK_NATRONENGINE_QLIST_QSTRING_IDX] = Shiboken::Conversions::createConverter(&PyList_Type, _QList_QString__CppToPython__QList_QString_);
    Shiboken::Conversions::registerConverterName(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_QLIST_QSTRING_IDX], "QList<QString>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_QLIST_QSTRING_IDX],
        _QList_QString__PythonToCpp__QList_QString_,
        is__QList_QString__PythonToCpp__QList_QString__Convertible);

    // Register converter for type 'QMap<QString,QVariant>'.
    SbkNatronEngineTypeConverters[SBK_NATRONENGINE_QMAP_QSTRING_QVARIANT_IDX] = Shiboken::Conversions::createConverter(&PyDict_Type, _QMap_QString_QVariant__CppToPython__QMap_QString_QVariant_);
    Shiboken::Conversions::registerConverterName(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_QMAP_QSTRING_QVARIANT_IDX], "QMap<QString,QVariant>");
    Shiboken::Conversions::addPythonToCppValueConversion(SbkNatronEngineTypeConverters[SBK_NATRONENGINE_QMAP_QSTRING_QVARIANT_IDX],
        _QMap_QString_QVariant__PythonToCpp__QMap_QString_QVariant_,
        is__QMap_QString_QVariant__PythonToCpp__QMap_QString_QVariant__Convertible);

    // Register primitive types converters.
    Shiboken::Conversions::registerConverterName(Shiboken::Conversions::PrimitiveTypeConverter<unsigned short>(), "ushort");

    Shiboken::Module::registerTypes(module, SbkNatronEngineTypes);
    Shiboken::Module::registerTypeConverters(module, SbkNatronEngineTypeConverters);

    if (PyErr_Occurred()) {
        PyErr_Print();
        Py_FatalError("can't initialize module NatronEngine");
    }
    PySide::registerCleanupFunction(cleanTypesAttributes);

    FinishSignatureInitialization(module, NatronEngine_SignatureStrings);
    NotifyModuleForQApp(module);

SBK_MODULE_INIT_FUNCTION_END
