/*
  ==============================================================================

    Page2.h
    Created: 24 Oct 2018 2:39:14pm
    Author:  personnel

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class Page2    : public Component, public Slider::Listener, public Button::Listener
{
public:
    Page2();
    ~Page2();

    void paint (Graphics&) override;
    void resized() override;
	void sliderValueChanged(Slider* slider) override;
	void buttonClicked(Button* button) override;
	LookAndFeel_V4 look2;

private:
	Slider slid1;
	TextButton but1;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Page2)
};
