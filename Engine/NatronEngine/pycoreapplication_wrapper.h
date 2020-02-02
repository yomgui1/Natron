#ifndef SBK_PYCOREAPPLICATIONWRAPPER_H
#define SBK_PYCOREAPPLICATIONWRAPPER_H

#include <shiboken.h>

#include <PyGlobalFunctions.h>

namespace Natron { namespace Python {
class PyCoreApplicationWrapper : public PyCoreApplication
{
public:
    PyCoreApplicationWrapper();
    virtual ~PyCoreApplicationWrapper();
    static void pysideInitQtMetaTypes();
};
} }

#endif // SBK_PYCOREAPPLICATIONWRAPPER_H

