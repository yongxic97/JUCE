/*
  ==============================================================================

   This file is part of the JUCE 7 technical preview.
   Copyright (c) 2022 - Raw Material Software Limited

   You may use this code under the terms of the GPL v3
   (see www.gnu.org/licenses).

   For the technical preview this file cannot be licensed commercially.

   JUCE IS PROVIDED "AS IS" WITHOUT ANY WARRANTY, AND ALL WARRANTIES, WHETHER
   EXPRESSED OR IMPLIED, INCLUDING MERCHANTABILITY AND FITNESS FOR PURPOSE, ARE
   DISCLAIMED.

  ==============================================================================
*/

#pragma once

#include "../jucer_JucerDocument.h"

//==============================================================================
class ButtonDocument   : public JucerDocument
{
public:
    ButtonDocument (SourceCodeDocument* cpp);
    ~ButtonDocument();

    //==============================================================================
    String getTypeName() const;

    JucerDocument* createCopy();
    Component* createTestComponent (const bool alwaysFillBackground);

    int getNumPaintRoutines() const;
    StringArray getPaintRoutineNames() const;
    PaintRoutine* getPaintRoutine (const int index) const;

    void setStatePaintRoutineEnabled (const int index, bool b);
    bool isStatePaintRoutineEnabled (const int index) const;

    int chooseBestEnabledPaintRoutine (int paintRoutineWanted) const;

    ComponentLayout* getComponentLayout() const                 { return nullptr; }

    void addExtraClassProperties (PropertyPanel&);

    //==============================================================================
    std::unique_ptr<XmlElement> createXml() const;
    bool loadFromXml (const XmlElement&);

    void fillInGeneratedCode (GeneratedCode& code) const;
    void fillInPaintCode (GeneratedCode& code) const;

    void getOptionalMethods (StringArray& baseClasses,
                             StringArray& returnValues,
                             StringArray& methods,
                             StringArray& initialContents) const;

    //==============================================================================
    std::unique_ptr<PaintRoutine> paintRoutines[7];
    bool paintStatesEnabled [7];
};
