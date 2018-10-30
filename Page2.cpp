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
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

	setName("Page2");
	
	//Ajout d'un slider
	slid1.setLookAndFeel(&look2);
	slid1.setValue(0);
	slid1.setSliderStyle(Slider::LinearHorizontal);
	slid1.setRange(0, 50, 1);
	slid1.addListener(this);
	addAndMakeVisible(slid1);

}

Page2::~Page2()
{
	slid1.removeListener(this);
}

void Page2::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

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

}

void Page2::sliderValueChanged(Slider* slider) {
	if (slider == &slid1) {
		slid1.setValue(round(slid1.getValue()), dontSendNotification);
	}
}
