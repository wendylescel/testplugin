/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "Doc.h"
#include "Page1.h"
#include "Page2.h"

//==============================================================================
/**
*/
class TestGuiAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    TestGuiAudioProcessorEditor (TestGuiAudioProcessor&);
    ~TestGuiAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
	void setLook();
	

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
	
    TestGuiAudioProcessor& processor;
	
	Page1 p1;
	Page2 p2;
	Doc doc1;
	Image ilogo;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TestGuiAudioProcessorEditor)
};
