#ifndef SBK_PYCOREAPPLICATIONWRAPPER_H
#define SBK_PYCOREAPPLICATIONWRAPPER_H

#include <PyGlobalFunctions.h>

class PyCoreApplicationWrapper : public Natron::Python::PyCoreApplication
{
public:
    PyCoreApplicationWrapper();
    ~PyCoreApplicationWrapper();
    static void pysideInitQtMetaTypes();
};

#endif // SBK_PYCOREAPPLICATIONWRAPPER_H

