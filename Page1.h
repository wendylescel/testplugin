/*
  ==============================================================================

    Page1.h
    Created: 24 Oct 2018 1:25:07pm
    Author:  personnel

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class Page1    : public Component, public Button::Listener, public Slider::Listener
{
public:
    Page1();
    ~Page1();

    void paint (Graphics&) override;
    void resized() override;

	void buttonClicked(Button* button) override;// [2]
	void sliderValueChanged(Slider* slider) override;
	void styleMenuChanged();

	LookAndFeel_V4 look1;


private:
	TextButton checkTheTimeButton;
	Label timeLabel;
	Slider sl;
	Slider sl2;
	Slider sl3;
	Slider sl4;
	Slider sl5;

	//TableListBox tablelist;

	Label textLabel{ {}, "Style" };
	Font textFont{ Font("Arial",15.0f,Font::plain) };
	ComboBox styleMenu;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Page1)
};
