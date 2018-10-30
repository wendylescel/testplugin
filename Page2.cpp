/*
  ==============================================================================

    Page2.cpp
    Created: 24 Oct 2018 2:39:14pm
    Author:  personnel

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Page2.h"

//==============================================================================
Page2::Page2()
{
 	setName("Page2");
	
	//Horizontal slider 
	slid1.setLookAndFeel(&look2);
	slid1.setValue(0);
	slid1.setSliderStyle(Slider::LinearHorizontal);
	slid1.setRange(0, 50, 1);
	slid1.addListener(this);
	addAndMakeVisible(slid1);

	//Button for new window
	addAndMakeVisible(but1);
	but1.setButtonText("New wd");
	but1.addListener(this);
}

Page2::~Page2()
{
	slid1.removeListener(this);
	but1.removeListener(this);
}

void Page2::paint (Graphics& g)
{
       g.fillAll (getLookAndFeel().findColour(ResizableWindow::backgroundColourId));   // clear the background

    g.setFont (14.0f);
    g.drawText ("Page2", getLocalBounds(),
                Justification::centredBottom, true);   // draw some placeholder text
}

void Page2::resized()
{
	auto area = getBounds();
	auto sliderarea = area.removeFromTop(100);
	slid1.setBounds(sliderarea.removeFromLeft(200));
	but1.setBounds(sliderarea.removeFromLeft(100));
}

void Page2::sliderValueChanged(Slider* slider) {
	if (slider == &slid1) {
		slid1.setValue(round(slid1.getValue()), dontSendNotification);
	}
}

void Page2::buttonClicked(Button* button) 
{
	if (button == &but1)                                                      
	{
		//open a new window
		
	}
}