

#ifndef SBK_NATRONENGINE_PYTHON_H
#define SBK_NATRONENGINE_PYTHON_H

#include <sbkpython.h>
#include <conversions.h>
#include <sbkenum.h>
#include <basewrapper.h>
#include <bindingmanager.h>
#include <memory>

#include <pysidesignal.h>
// Module Includes
CLANG_DIAG_OFF(deprecated)
CLANG_DIAG_OFF(uninitialized)
CLANG_DIAG_OFF(keyword-macro)
#include <pyside_qtcore_python.h> // produces warnings
CLANG_DIAG_ON(deprecated)
CLANG_DIAG_ON(uninitialized)
CLANG_DIAG_ON(keyword-macro)

// Binded library includes
#include "Global/Enums.h"
#include "Engine/RectD.h"
#include "Engine/RectI.h"
#include "Engine/PyExprUtils.h"
#include "Engine/PyTracker.h"
#include "Engine/PyParameter.h"
#include "Engine/PyRoto.h"
#include "Engine/PyGlobalFunctions.h"
#include "Engine/PyAppInstance.h"
#include "Engine/PyNodeGroup.h"
#include "Engine/PyNode.h"
// Conversion Includes - Primitive Types
#include <QString>
#include <signalmanager.h>
#include <typeresolver.h>
#include <QtConcurrentFilter>
#include <QStringList>
#include <qabstractitemmodel.h>

// Conversion Includes - Container Types
#include <QList>
#include <QMap>
#include <QStack>
#include <QMultiMap>
#include <map>
#include <QVector>
#include <QPair>
#include <pysideconversions.h>
#include <QSet>
#include <vector>
#include <QQueue>
#include <map>
#include <utility>
#include <list>
#include <QLinkedList>
#include <set>

// Type indices
#define SBK_Natron_IDX                                     30
#define SBK_Natron_STATUSENUM_IDX                          41
#define SBK_Natron_STANDARDBUTTONENUM_IDX                  40
#define SBK_QFLAGS_Natron_STANDARDBUTTONENUM__IDX          52
#define SBK_Natron_KEYFRAMETYPEENUM_IDX                    35
#define SBK_Natron_PIXMAPENUM_IDX                          38
#define SBK_Natron_VALUECHANGEDREASONENUM_IDX              42
#define SBK_Natron_ANIMATIONLEVELENUM_IDX                  31
#define SBK_Natron_IMAGEPREMULTIPLICATIONENUM_IDX          34
#define SBK_Natron_VIEWERCOMPOSITINGOPERATORENUM_IDX       44
#define SBK_Natron_VIEWERCOLORSPACEENUM_IDX                43
#define SBK_Natron_IMAGEBITDEPTHENUM_IDX                   33
#define SBK_Natron_ORIENTATIONENUM_IDX                     37
#define SBK_Natron_PLAYBACKMODEENUM_IDX                    39
#define SBK_Natron_DISPLAYCHANNELSENUM_IDX                 32
#define SBK_Natron_MERGINGFUNCTIONENUM_IDX                 36
#define SBK_RECTD_IDX                                                53
#define SBK_RECTI_IDX                                                54
#define SBK_NODECREATIONPROPERTY_IDX                                 45
#define SBK_BOOLNODECREATIONPROPERTY_IDX                             4
#define SBK_INTNODECREATIONPROPERTY_IDX                              26
#define SBK_APPSETTINGS_IDX                                          2
#define SBK_GROUP_IDX                                                19
#define SBK_PYCOREAPPLICATION_IDX                                    51
#define SBK_EXPRUTILS_IDX                                            16
#define SBK_COLORTUPLE_IDX                                           9
#define SBK_DOUBLE3DTUPLE_IDX                                        13
#define SBK_DOUBLE2DTUPLE_IDX                                        11
#define SBK_INT3DTUPLE_IDX                                           25
#define SBK_INT2DTUPLE_IDX                                           23
#define SBK_PARAM_IDX                                                48
#define SBK_GROUPPARAM_IDX                                           20
#define SBK_SEPARATORPARAM_IDX                                       56
#define SBK_BUTTONPARAM_IDX                                          6
#define SBK_ANIMATEDPARAM_IDX                                        0
#define SBK_DOUBLEPARAM_IDX                                          14
#define SBK_DOUBLE2DPARAM_IDX                                        10
#define SBK_DOUBLE3DPARAM_IDX                                        12
#define SBK_INTPARAM_IDX                                             27
#define SBK_INT2DPARAM_IDX                                           22
#define SBK_INT3DPARAM_IDX                                           24
#define SBK_STRINGPARAMBASE_IDX                                      60
#define SBK_PATHPARAM_IDX                                            50
#define SBK_OUTPUTFILEPARAM_IDX                                      46
#define SBK_FILEPARAM_IDX                                            17
#define SBK_STRINGPARAM_IDX                                          58
#define SBK_STRINGPARAM_TYPEENUM_IDX                                 59
#define SBK_BOOLEANPARAM_IDX                                         5
#define SBK_CHOICEPARAM_IDX                                          7
#define SBK_COLORPARAM_IDX                                           8
#define SBK_PARAMETRICPARAM_IDX                                      49
#define SBK_PAGEPARAM_IDX                                            47
#define SBK_APP_IDX                                                  1
#define SBK_STRINGNODECREATIONPROPERTY_IDX                           57
#define SBK_FLOATNODECREATIONPROPERTY_IDX                            18
#define SBK_USERPARAMHOLDER_IDX                                      63
#define SBK_EFFECT_IDX                                               15
#define SBK_IMAGELAYER_IDX                                           21
#define SBK_TRACKER_IDX                                              62
#define SBK_TRACK_IDX                                                61
#define SBK_ROTO_IDX                                                 55
#define SBK_ITEMBASE_IDX                                             28
#define SBK_BEZIERCURVE_IDX                                          3
#define SBK_LAYER_IDX                                                29
#define SBK_NatronEngine_IDX_COUNT                                   64

// This variable stores all Python types exported by this module.
extern PyTypeObject** SbkNatronEngineTypes;

// This variable stores all type converters exported by this module.
extern SbkConverter** SbkNatronEngineTypeConverters;

// Converter indices
#define SBK_STD_SIZE_T_IDX                                           0
#define SBK_NATRONENGINE_STD_VECTOR_RECTI_IDX                        1 // std::vector<RectI >
#define SBK_NATRONENGINE_STD_VECTOR_BOOL_IDX                         2 // const std::vector<bool > &
#define SBK_NATRONENGINE_STD_VECTOR_INT_IDX                          3 // const std::vector<int > &
#define SBK_NATRONENGINE_STD_LIST_PARAMPTR_IDX                       4 // std::list<Param * >
#define SBK_NATRONENGINE_STD_LIST_EFFECTPTR_IDX                      5 // std::list<Effect * >
#define SBK_NATRONENGINE_STD_VECTOR_DOUBLE_IDX                       6 // const std::vector<double > &
#define SBK_NATRONENGINE_STD_VECTOR_STD_STRING_IDX                   7 // std::vector<std::string >
#define SBK_NATRONENGINE_STD_LIST_STD_VECTOR_STD_STRING_IDX          8 // std::list<std::vector<std::string > > *
#define SBK_NATRONENGINE_STD_PAIR_QSTRING_QSTRING_IDX                9 // std::pair<QString, QString >
#define SBK_NATRONENGINE_STD_LIST_STD_PAIR_QSTRING_QSTRING_IDX       10 // const std::list<std::pair<QString, QString > > &
#define SBK_NATRONENGINE_STD_MAP_QSTRING_NODECREATIONPROPERTYPTR_IDX 11 // const std::map<QString, NodeCreationProperty * > &
#define SBK_NATRONENGINE_STD_LIST_QSTRING_IDX                        12 // std::list<QString >
#define SBK_NATRONENGINE_STD_LIST_INT_IDX                            13 // const std::list<int > &
#define SBK_NATRONENGINE_STD_LIST_IMAGELAYER_IDX                     14 // std::list<ImageLayer >
#define SBK_NATRONENGINE_STD_LIST_TRACKPTR_IDX                       15 // std::list<Track * > *
#define SBK_NATRONENGINE_STD_LIST_DOUBLE_IDX                         16 // std::list<double > *
#define SBK_NATRONENGINE_STD_LIST_ITEMBASEPTR_IDX                    17 // std::list<ItemBase * >
#define SBK_NATRONENGINE_QLIST_QVARIANT_IDX                          18 // QList<QVariant >
#define SBK_NATRONENGINE_QLIST_QSTRING_IDX                           19 // QList<QString >
#define SBK_NATRONENGINE_QMAP_QSTRING_QVARIANT_IDX                   20 // QMap<QString, QVariant >
#define SBK_NatronEngine_CONVERTERS_IDX_COUNT                        21

// Macros for type check

namespace Shiboken
{

// PyType functions, to get the PyObjectType for a type T
template<> inline PyTypeObject* SbkType<Natron::StatusEnum >() { return SbkNatronEngineTypes[SBK_Natron_STATUSENUM_IDX]; }
template<> inline PyTypeObject* SbkType<Natron::StandardButtonEnum >() { return SbkNatronEngineTypes[SBK_Natron_STANDARDBUTTONENUM_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFlags<Natron::StandardButtonEnum> >() { return SbkNatronEngineTypes[SBK_QFLAGS_Natron_STANDARDBUTTONENUM__IDX]; }
template<> inline PyTypeObject* SbkType<Natron::KeyframeTypeEnum >() { return SbkNatronEngineTypes[SBK_Natron_KEYFRAMETYPEENUM_IDX]; }
template<> inline PyTypeObject* SbkType<Natron::PixmapEnum >() { return SbkNatronEngineTypes[SBK_Natron_PIXMAPENUM_IDX]; }
template<> inline PyTypeObject* SbkType<Natron::ValueChangedReasonEnum >() { return SbkNatronEngineTypes[SBK_Natron_VALUECHANGEDREASONENUM_IDX]; }
template<> inline PyTypeObject* SbkType<Natron::AnimationLevelEnum >() { return SbkNatronEngineTypes[SBK_Natron_ANIMATIONLEVELENUM_IDX]; }
template<> inline PyTypeObject* SbkType<Natron::ImagePremultiplicationEnum >() { return SbkNatronEngineTypes[SBK_Natron_IMAGEPREMULTIPLICATIONENUM_IDX]; }
template<> inline PyTypeObject* SbkType<Natron::ViewerCompositingOperatorEnum >() { return SbkNatronEngineTypes[SBK_Natron_VIEWERCOMPOSITINGOPERATORENUM_IDX]; }
template<> inline PyTypeObject* SbkType<Natron::ViewerColorSpaceEnum >() { return SbkNatronEngineTypes[SBK_Natron_VIEWERCOLORSPACEENUM_IDX]; }
template<> inline PyTypeObject* SbkType<Natron::ImageBitDepthEnum >() { return SbkNatronEngineTypes[SBK_Natron_IMAGEBITDEPTHENUM_IDX]; }
template<> inline PyTypeObject* SbkType<Natron::OrientationEnum >() { return SbkNatronEngineTypes[SBK_Natron_ORIENTATIONENUM_IDX]; }
template<> inline PyTypeObject* SbkType<Natron::PlaybackModeEnum >() { return SbkNatronEngineTypes[SBK_Natron_PLAYBACKMODEENUM_IDX]; }
template<> inline PyTypeObject* SbkType<Natron::DisplayChannelsEnum >() { return SbkNatronEngineTypes[SBK_Natron_DISPLAYCHANNELSENUM_IDX]; }
template<> inline PyTypeObject* SbkType<Natron::MergingFunctionEnum >() { return SbkNatronEngineTypes[SBK_Natron_MERGINGFUNCTIONENUM_IDX]; }
template<> inline PyTypeObject* SbkType<Natron::RectD >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_RECTD_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::RectI >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_RECTI_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::NodeCreationProperty >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_NODECREATIONPROPERTY_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::BoolNodeCreationProperty >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_BOOLNODECREATIONPROPERTY_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::IntNodeCreationProperty >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_INTNODECREATIONPROPERTY_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::AppSettings >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_APPSETTINGS_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::Group >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_GROUP_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::PyCoreApplication >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_PYCOREAPPLICATION_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::ExprUtils >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_EXPRUTILS_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::ColorTuple >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_COLORTUPLE_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::Double3DTuple >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_DOUBLE3DTUPLE_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::Double2DTuple >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_DOUBLE2DTUPLE_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::Int3DTuple >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_INT3DTUPLE_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::Int2DTuple >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_INT2DTUPLE_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::Param >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_PARAM_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::GroupParam >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_GROUPPARAM_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::SeparatorParam >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_SEPARATORPARAM_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::ButtonParam >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_BUTTONPARAM_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::AnimatedParam >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_ANIMATEDPARAM_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::DoubleParam >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_DOUBLEPARAM_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::Double2DParam >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_DOUBLE2DPARAM_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::Double3DParam >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_DOUBLE3DPARAM_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::IntParam >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_INTPARAM_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::Int2DParam >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_INT2DPARAM_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::Int3DParam >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_INT3DPARAM_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::StringParamBase >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_STRINGPARAMBASE_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::PathParam >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_PATHPARAM_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::OutputFileParam >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_OUTPUTFILEPARAM_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::FileParam >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_FILEPARAM_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::StringParam::TypeEnum >() { return SbkNatronEngineTypes[SBK_STRINGPARAM_TYPEENUM_IDX]; }
template<> inline PyTypeObject* SbkType<Natron::Python::StringParam >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_STRINGPARAM_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::BooleanParam >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_BOOLEANPARAM_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::ChoiceParam >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_CHOICEPARAM_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::ColorParam >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_COLORPARAM_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::ParametricParam >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_PARAMETRICPARAM_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::PageParam >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_PAGEPARAM_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::App >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_APP_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::StringNodeCreationProperty >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_STRINGNODECREATIONPROPERTY_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::FloatNodeCreationProperty >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_FLOATNODECREATIONPROPERTY_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::UserParamHolder >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_USERPARAMHOLDER_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::Effect >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_EFFECT_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::ImageLayer >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_IMAGELAYER_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::Tracker >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_TRACKER_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::Track >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_TRACK_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::Roto >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_ROTO_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::ItemBase >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_ITEMBASE_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::BezierCurve >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_BEZIERCURVE_IDX]); }
template<> inline PyTypeObject* SbkType<Natron::Python::Layer >() { return reinterpret_cast<PyTypeObject*>(SbkNatronEngineTypes[SBK_LAYER_IDX]); }

} // namespace Shiboken

#endif // SBK_NATRONENGINE_PYTHON_H

