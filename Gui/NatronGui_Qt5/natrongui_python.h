

#ifndef SBK_NATRONGUI_PYTHON_H
#define SBK_NATRONGUI_PYTHON_H

#include <sbkpython.h>
#include <sbkconverter.h>
// Module Includes
#include <pyside2_qtgui_python.h>
#include <pyside2_qtcore_python.h>
#include <natronengine_python.h>

// Binded library includes
#include <PythonPanels.h>
#include <PyGlobalGui.h>
#include <PyGuiApp.h>
// Conversion Includes - Primitive Types
#include <qabstractitemmodel.h>
#include <QString>
#include <QStringList>
#include <signalmanager.h>

// Conversion Includes - Container Types
#include <pysideqflags.h>
#include <QLinkedList>
#include <QList>
#include <QMap>
#include <QMultiMap>
#include <QPair>
#include <QQueue>
#include <QSet>
#include <QStack>
#include <QVector>
#include <list>
#include <map>
#include <map>
#include <utility>
#include <set>
#include <vector>

// Type indices
enum : int {
    SBK_NATRON_PYTHON_GUIAPP_IDX                             = 0,
    SBK_NATRON_PYTHON_PYGUIAPPLICATION_IDX                   = 1,
    SBK_NATRON_PYTHON_PYMODALDIALOG_IDX                      = 2,
    SBK_NATRON_PYTHON_PYPANEL_IDX                            = 3,
    SBK_NATRON_PYTHON_PYTABWIDGET_IDX                        = 4,
    SBK_NatronGui_IDX_COUNT                                  = 5
};
// This variable stores all Python types exported by this module.
extern PyTypeObject** SbkNatronGuiTypes;

// This variable stores the Python module object exported by this module.
extern PyObject* SbkNatronGuiModuleObject;

// This variable stores all type converters exported by this module.
extern SbkConverter** SbkNatronGuiTypeConverters;

// Converter indices
enum : int {
    SBK_NATRONGUI_STD_MAP_QSTRING_NATRON_PYTHON_NODECREATIONPROPERTYPTR_IDX = 0, // const std::map<QString,Natron::Python::NodeCreationProperty* > &
    SBK_NATRONGUI_STD_LIST_NATRON_PYTHON_EFFECTPTR_IDX       = 1, // std::list<Natron::Python::Effect* >
    SBK_NATRONGUI_STD_LIST_QSTRING_IDX                       = 2, // std::list<QString >
    SBK_NATRONGUI_STD_LIST_INT_IDX                           = 3, // const std::list<int > &
    SBK_NATRONGUI_STD_LIST_NATRON_PYTHON_PARAMPTR_IDX        = 4, // std::list<Natron::Python::Param* >
    SBK_NATRONGUI_QLIST_QVARIANT_IDX                         = 5, // QList<QVariant >
    SBK_NATRONGUI_QLIST_QSTRING_IDX                          = 6, // QList<QString >
    SBK_NATRONGUI_QMAP_QSTRING_QVARIANT_IDX                  = 7, // QMap<QString,QVariant >
    SBK_NatronGui_CONVERTERS_IDX_COUNT                       = 8
};
// Macros for type check

namespace Shiboken
{

// PyType functions, to get the PyObjectType for a type T
template<> inline PyTypeObject* SbkType< ::Natron::Python::GuiApp >() { return reinterpret_cast<PyTypeObject*>(SbkNatronGuiTypes[SBK_NATRON_PYTHON_GUIAPP_IDX]); }
template<> inline PyTypeObject* SbkType< ::Natron::Python::PyGuiApplication >() { return reinterpret_cast<PyTypeObject*>(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYGUIAPPLICATION_IDX]); }
template<> inline PyTypeObject* SbkType< ::Natron::Python::PyModalDialog >() { return reinterpret_cast<PyTypeObject*>(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYMODALDIALOG_IDX]); }
template<> inline PyTypeObject* SbkType< ::Natron::Python::PyPanel >() { return reinterpret_cast<PyTypeObject*>(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYPANEL_IDX]); }
template<> inline PyTypeObject* SbkType< ::Natron::Python::PyTabWidget >() { return reinterpret_cast<PyTypeObject*>(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYTABWIDGET_IDX]); }

} // namespace Shiboken

#endif // SBK_NATRONGUI_PYTHON_H

