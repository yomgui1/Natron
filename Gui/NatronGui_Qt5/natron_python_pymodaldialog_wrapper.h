#ifndef SBK_PYMODALDIALOGWRAPPER_H
#define SBK_PYMODALDIALOGWRAPPER_H

#include <PythonPanels.h>

class PyModalDialogWrapper : public Natron::Python::PyModalDialog
{
public:
    ~PyModalDialogWrapper();
    static void pysideInitQtMetaTypes();
};

#  ifndef SBK_USERPARAMHOLDERWRAPPER_H
#  define SBK_USERPARAMHOLDERWRAPPER_H

// Inherited base class:
class UserParamHolderWrapper : public Natron::Python::UserParamHolder
{
public:
    UserParamHolderWrapper();
    ~UserParamHolderWrapper();
    static void pysideInitQtMetaTypes();
};

#  endif // SBK_USERPARAMHOLDERWRAPPER_H

#endif // SBK_PYMODALDIALOGWRAPPER_H

