/* ***** BEGIN LICENSE BLOCK *****
 * This file is part of Natron <https://natrongithub.github.io/>,
 * Copyright (C) 2013-2018 INRIA and Alexandre Gauthier-Foichat
 *
 * Natron is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Natron is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Natron.  If not, see <http://www.gnu.org/licenses/gpl-2.0.html>
 * ***** END LICENSE BLOCK ***** */

// ***** BEGIN PYTHON BLOCK *****
// from <https://docs.python.org/3/c-api/intro.html#include-files>:
// "Since Python may define some pre-processor definitions which affect the standard headers on some systems, you must include Python.h before any standard headers are included."
#include <Python.h>
// ***** END PYTHON BLOCK *****

#include "KnobGuiFactory.h"

#include <stdexcept>

#if !defined(Q_MOC_RUN) && !defined(SBK_RUN)
#include <boost/scoped_ptr.hpp>
#endif

#include "Engine/AppManager.h"
#include "Engine/LibraryBinary.h"

#include "Engine/Knob.h"
#include "Engine/KnobTypes.h"
#include "Engine/KnobFile.h"

#include "Gui/KnobGui.h"
#include "Gui/KnobGuiFile.h"
#include "Gui/KnobGuiValue.h"
#include "Gui/KnobGuiBool.h"
#include "Gui/KnobGuiButton.h"
#include "Gui/KnobGuiChoice.h"
#include "Gui/KnobGuiSeparator.h"
#include "Gui/KnobGuiGroup.h"
#include "Gui/KnobGuiColor.h"
#include "Gui/KnobGuiString.h"
#include "Gui/KnobGuiBool.h"
#include "Gui/KnobGuiParametric.h"
#include "Gui/DockablePanel.h"
#include "Gui/KnobGuiKeyFrameMarkers.h"

NATRON_NAMESPACE_ENTER
using std::make_pair;
using std::pair;


/*Class inheriting KnobGui, must have a function named BuildKnobGui with the following signature.
   This function should in turn call a specific class-based static function with the appropriate param.*/
typedef KnobGuiWidgets *(*KnobGuiBuilder)(const KnobGuiPtr& knob, ViewIdx view);

KnobGuiFactory::KnobGuiFactory()
{
    loadBultinKnobs();
}

template<typename K, typename KG>
static auto
knobGuiFactoryEntry()
{
    std::string stub;
    KnobHelperPtr knob( K::create(KnobHolderPtr(), stub, 1) );
    std::map<std::string, void (*)()> functions {
        make_pair("BuildKnobGui", ( void (*)() ) & KG::BuildKnobGui)
    };
    return make_pair(knob->typeName(), std::make_unique<LibraryBinary>(functions));
}

void
KnobGuiFactory::loadBultinKnobs()
{
    _loadedKnobs.insert( knobGuiFactoryEntry<KnobFile, KnobGuiFile>() );
    _loadedKnobs.insert( knobGuiFactoryEntry<KnobInt, KnobGuiInt>() );
    _loadedKnobs.insert( knobGuiFactoryEntry<KnobDouble, KnobGuiDouble>() );
    _loadedKnobs.insert( knobGuiFactoryEntry<KnobBool, KnobGuiBool>() );
    _loadedKnobs.insert( knobGuiFactoryEntry<KnobButton, KnobGuiButton>() );
    _loadedKnobs.insert( knobGuiFactoryEntry<KnobChoice, KnobGuiChoice>() );
    _loadedKnobs.insert( knobGuiFactoryEntry<KnobSeparator, KnobGuiSeparator>() );
    _loadedKnobs.insert( knobGuiFactoryEntry<KnobGroup, KnobGuiGroup>() );
    _loadedKnobs.insert( knobGuiFactoryEntry<KnobColor, KnobGuiColor>() );
    _loadedKnobs.insert( knobGuiFactoryEntry<KnobString, KnobGuiString>() );
    _loadedKnobs.insert( knobGuiFactoryEntry<KnobBool, KnobGuiBool>() );
    _loadedKnobs.insert( knobGuiFactoryEntry<KnobParametric, KnobGuiParametric>() );
    _loadedKnobs.insert( knobGuiFactoryEntry<KnobPath, KnobGuiPath>() );
    _loadedKnobs.insert( knobGuiFactoryEntry<KnobLayers, KnobGuiLayers>() );
    _loadedKnobs.insert( knobGuiFactoryEntry<KnobKeyFrameMarkers, KnobGuiKeyFrameMarkers>() );
}

KnobGuiWidgets *
KnobGuiFactory::createGuiForKnob(const KnobGuiPtr& knob, ViewIdx view) const
{
    assert(knob);
    auto it = _loadedKnobs.find( knob->getKnob()->typeName() );
    if ( it == _loadedKnobs.end() ) {
        return nullptr;
    }

    auto guiBuilderFunc = it->second->findFunction<KnobGuiBuilder>("BuildKnobGui");
    if (!guiBuilderFunc.first) {
        return nullptr;
    }

    return (guiBuilderFunc.second)(knob, view);
}

NATRON_NAMESPACE_EXIT
