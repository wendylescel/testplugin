/*
  ==============================================================================

    Doc.h
    Created: 24 Oct 2018 2:06:55pm
    Author:  personnel

  ==============================================================================
*/
#include "../JuceLibraryCode/JuceHeader.h"

class Doc : public MultiDocumentPanel {
public:
	Doc() : MultiDocumentPanel()
	{
		setVisible(true);
	}
	
	bool 	tryToCloseDocument(Component *component) {
		return true;
	}

	

protected:
	LookAndFeel_V4 look;




};

#pragma once
