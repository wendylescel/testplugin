/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include <math.h>


//==============================================================================
TestGuiAudioProcessorEditor::TestGuiAudioProcessorEditor (TestGuiAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
	//Set the look and feel of the plugin
	setLook();
	
	//Doc1 : MultiDocumentPanel -> create files for each tab
	addAndMakeVisible(doc1);
	doc1.setLayoutMode(MultiDocumentPanel::LayoutMode::MaximisedWindowsWithTabs);
	doc1.addDocument(&p1, Colours::black, false); //Tab1
	doc1.addDocument(&p2, Colours::black, false); //Tab2
	doc1.setActiveDocument(&p1);	//Default : Tab1 is active 
	doc1.setRepaintsOnMouseActivity(true);
	
	//Main window : resizable with the corner
	setResizable(true, true);
	setSize(800, 600);

	//logo NoiseMakers
	PNGImageFormat logo;
	File path("C:/Users/personnel/Desktop/INSA/5EII/PROJET INDUS/Juce/TestGUI/Source/Images/logo.png");
	ilogo=logo.loadFrom(path);
}

TestGuiAudioProcessorEditor::~TestGuiAudioProcessorEditor()
{

}

//==============================================================================
void TestGuiAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
   
	g.setColour(Colours::black);
	g.fillRect(0, 0, getWidth(), 30);
	g.setColour(Colours::red.withAlpha(0.5f));
	g.setOpacity(1.0f);
	g.drawImageAt(ilogo, 0, 0, false);
	

}

void TestGuiAudioProcessorEditor::resized()
{
	auto area = getBounds();
	auto area2 = area.removeFromTop(30);
	doc1.setBounds(area.removeFromTop(getBounds().getHeight()));	
}



void TestGuiAudioProcessorEditor::setLook() {

	//Black, royalblue and white are used
	p1.look1.setColour(Slider::rotarySliderFillColourId, Colours::royalblue);
	p1.look1.setColour(Slider::thumbColourId, Colours::royalblue);
	p1.look1.setColour(Slider::trackColourId, Colours::royalblue);
	p1.look1.setColour(Slider::textBoxOutlineColourId, getLookAndFeel().findColour(ResizableWindow::backgroundColourId));
	p1.look1.setColour(TabbedButtonBar::frontTextColourId, Colours::royalblue);
	p1.look1.setColour(TabbedButtonBar::frontOutlineColourId, Colours::white);
	p1.look1.setColour(TabbedButtonBar::tabTextColourId, Colours::white);
	p1.look1.setColour(Label::textColourId, Colours::royalblue);

	p2.look2.setColour(Slider::thumbColourId, Colours::royalblue);
	p2.look2.setColour(Slider::trackColourId, Colours::royalblue);
	p2.look2.setColour(Slider::textBoxOutlineColourId, getLookAndFeel().findColour(ResizableWindow::backgroundColourId));


	doc1.setBackgroundColour(Colours::black);
}
