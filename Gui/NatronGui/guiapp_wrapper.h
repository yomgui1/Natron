#ifndef SBK_GUIAPPWRAPPER_H
#define SBK_GUIAPPWRAPPER_H

#include <shiboken.h>

#include <PyGuiApp.h>

namespace Natron { namespace Python {
class GuiAppWrapper : public GuiApp
{
public:
    virtual ~GuiAppWrapper();
    static void pysideInitQtMetaTypes();
};
} }

#endif // SBK_GUIAPPWRAPPER_H

