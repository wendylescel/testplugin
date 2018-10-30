/*
  ==============================================================================

    Page1.cpp
    Created: 24 Oct 2018 1:25:07pm
    Author:  personnel

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Page1.h"

//==============================================================================
Page1::Page1()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

	setName("Page1");

	//Sliders
	sl.setLookAndFeel(&look1);
	sl.setSliderStyle(Slider::Rotary);
	sl.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 30);
	sl.setRange(0, 50, 1);
	sl.setValue(0);
	sl.addListener(this);
	addAndMakeVisible(sl);

	sl2.setLookAndFeel(&look1);
	sl2.setSliderStyle(Slider::LinearHorizontal);
	sl2.setRange(0, 50, 1);
	sl2.setValue(0);
	sl2.addListener(this);
	addAndMakeVisible(sl2);

	sl3.setLookAndFeel(&look1);
	sl3.setSliderStyle(Slider::LinearHorizontal);
	sl3.setRange(0, 50, 1);
	sl3.setValue(0);
	sl3.addListener(this);
	addAndMakeVisible(sl3);

	sl4.setLookAndFeel(&look1);
	sl4.setSliderStyle(Slider::LinearBarVertical);
	sl4.setRange(0, 50, 1);
	sl4.setValue(0);
	sl4.addListener(this);
	addAndMakeVisible(sl4);

	sl5.setLookAndFeel(&look1);
	sl5.setSliderStyle(Slider::LinearVertical);
	sl5.setTextBoxStyle(Slider::TextBoxRight, false, 30, 30);
	sl5.setRange(0, 10, 1);
	sl5.setValue(0);
	sl5.addListener(this);
	addAndMakeVisible(sl5);

	//Combo-Box
	styleMenu.addItem("Normal", 1);
	styleMenu.addItem("Bold", 2);
	styleMenu.addItem("Italique", 3);
	styleMenu.addItem("Underligned", 4);
	styleMenu.setSelectedId(0);
	styleMenu.setLookAndFeel(&look1);
	styleMenu.setScrollWheelEnabled(true);
	styleMenu.setTextWhenNothingSelected("Select");
	styleMenu.onChange = [this] { styleMenuChanged(); };
	addAndMakeVisible(styleMenu);

	//Test changement écriture combo-box
	textLabel.setFont(textFont);
	addAndMakeVisible(textLabel);


	//Bouton + fonction écriture time
	checkTheTimeButton.setLookAndFeel(&look1);
	checkTheTimeButton.setButtonText("What time is it ?");
	checkTheTimeButton.addListener(this);
	addAndMakeVisible(checkTheTimeButton);
	timeLabel.setLookAndFeel(&look1);
	timeLabel.setJustificationType(Justification::centred);
	addAndMakeVisible(timeLabel);
}

Page1::~Page1()
{
	checkTheTimeButton.removeListener(this);
	sl.removeListener(this);
	sl2.removeListener(this);
	sl3.removeListener(this);
	sl4.removeListener(this);
	sl5.removeListener(this);
}

void Page1::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (getLookAndFeel().findColour(ResizableWindow::backgroundColourId));   // clear the background
	
    g.setFont (14.0f);
    g.drawText ("Page1", getLocalBounds(),
                Justification::centredBottom, true);   // draw some placeholder text
}

void Page1::resized()
{
	auto area = getBounds();
	auto sliderarea = area.removeFromTop(100);

	//Sliders
	sl.setBounds(sliderarea.removeFromLeft(100));
	sl2.setBounds(sliderarea.removeFromLeft(200));
	sl3.setBounds(sliderarea.removeFromLeft(200));
	sl4.setBounds(sliderarea.removeFromLeft(50));
	sl5.setBounds(sliderarea.removeFromLeft(50));

	//ComboBox
	auto area3 = area.removeFromTop(30);
	area3 = area.removeFromTop(40);
	styleMenu.setBounds(area3.removeFromLeft(100));
	textLabel.setBounds(area3.removeFromLeft(150));

	//Bouton time
	checkTheTimeButton.setBounds(area3.removeFromLeft(100));
	timeLabel.setBounds(area3.removeFromLeft(150));

}

void Page1::buttonClicked(Button* button) // [2]
{
	if (button == &checkTheTimeButton)                                                      // [3]
	{
		auto currentTime = Time::getCurrentTime();                                          // [4]
		auto includeDate = false;
		auto includeTime = true;
		auto currentTimeString = currentTime.toString(includeDate, includeTime);           // [5]
		timeLabel.setText(currentTimeString, dontSendNotification);                        // [6]
	}
}

void Page1::sliderValueChanged(Slider* slider) {
	if (slider == &sl) {
		sl.setValue(round(sl.getValue()), dontSendNotification);
	}
	else if (slider == &sl2) {
		sl2.setValue(sl2.getValue(), dontSendNotification);
	}
	else if (slider == &sl3) {
		sl3.setValue(sl3.getValue(), dontSendNotification);
	}
	else if (slider == &sl4) {
		sl4.setValue(sl4.getValue(), dontSendNotification);
	}
	else if (slider == &sl5) {
		sl5.setValue(sl5.getValue(), dontSendNotification);
	}
}


void Page1::styleMenuChanged()
{
	switch (styleMenu.getSelectedId())
	{
	case 1: textFont.setStyleFlags(Font::plain);  break;
	case 2: textFont.setStyleFlags(Font::bold);   break;
	case 3: textFont.setStyleFlags(Font::italic); break;
	case 4: textFont.setStyleFlags(Font::underlined); break;
	}
	textLabel.setFont(textFont);
}

