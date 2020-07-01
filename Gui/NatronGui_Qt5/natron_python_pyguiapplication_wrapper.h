#ifndef SBK_PYGUIAPPLICATIONWRAPPER_H
#define SBK_PYGUIAPPLICATIONWRAPPER_H

#include <PyGlobalGui.h>

class PyGuiApplicationWrapper : public Natron::Python::PyGuiApplication
{
public:
    PyGuiApplicationWrapper();
    ~PyGuiApplicationWrapper();
    static void pysideInitQtMetaTypes();
};

#  ifndef SBK_PYCOREAPPLICATIONWRAPPER_H
#  define SBK_PYCOREAPPLICATIONWRAPPER_H

// Inherited base class:
class PyCoreApplicationWrapper : public Natron::Python::PyCoreApplication
{
public:
    PyCoreApplicationWrapper();
    ~PyCoreApplicationWrapper();
    static void pysideInitQtMetaTypes();
};

#  endif // SBK_PYCOREAPPLICATIONWRAPPER_H

#endif // SBK_PYGUIAPPLICATIONWRAPPER_H

