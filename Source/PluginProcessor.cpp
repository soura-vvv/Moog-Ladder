/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
//#include "PluginEditor.h"

//==============================================================================
MoogVibeAudioProcessor::MoogVibeAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
    : foleys::MagicProcessor(BusesProperties()
#if ! JucePlugin_IsMidiEffect
#if ! JucePlugin_IsSynth
        .withInput("Input", juce::AudioChannelSet::stereo(), true)
#endif
        .withOutput("Output", juce::AudioChannelSet::stereo(), true)
#endif
    ), parameters(*this, nullptr, juce::Identifier("MoogVibe"), {
        std::make_unique<juce::AudioParameterFloat>("cutoffFrequency","Cutoff Frequency",100,18000,1000),
        std::make_unique<juce::AudioParameterFloat>("resonance","Resonance",0.01f,0.55f,0.5f),
        std::make_unique<juce::AudioParameterFloat>("bassComp","Bass Compensation",0,12,0),
        std::make_unique<juce::AudioParameterBool>("antiAliasing","Anti-Aliasing",false),
        std::make_unique<juce::AudioParameterFloat>("gain","Gain",-24,24,0),
         })
#endif
{
    magicState.setGuiValueTree(BinaryData::MoogVibe_xml, BinaryData::MoogVibe_xmlSize);
    cutoffFrequency = parameters.getRawParameterValue("cutoffFrequency");
    resonance = parameters.getRawParameterValue("resonance");
    bassComp = parameters.getRawParameterValue("bassComp");
    antiAliasing = parameters.getRawParameterValue("antiAliasing");
    gain = parameters.getRawParameterValue("gain");


    //magicState.createAssetFilesMenu()

    FOLEYS_SET_SOURCE_PATH(__FILE__);
}
//245, 190, 141
//#f5be8d
//#BF712B
//#F4F2F1

//#F4B46D
MoogVibeAudioProcessor::~MoogVibeAudioProcessor()
{
}

//==============================================================================
const juce::String MoogVibeAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool MoogVibeAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool MoogVibeAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool MoogVibeAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double MoogVibeAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int MoogVibeAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int MoogVibeAudioProcessor::getCurrentProgram()
{
    return 0;
}

void MoogVibeAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String MoogVibeAudioProcessor::getProgramName (int index)
{
    return {};
}

void MoogVibeAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void MoogVibeAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    moogVA.prepareToPlay(sampleRate, samplesPerBlock, getNumInputChannels());
}

void MoogVibeAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool MoogVibeAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void MoogVibeAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());


    moogVA.processBlock(buffer, *cutoffFrequency, *resonance,*bassComp,*antiAliasing);

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
    //for (int channel = 0; channel < totalNumInputChannels; ++channel)
    //{
    //    auto* channelData = buffer.getWritePointer (channel);

    //    // ..do something to the data...
    //}
    buffer.applyGain(juce::Decibels::decibelsToGain<float>(*gain));
    //juce::Decibels::decibelsToGain()
}

//==============================================================================
//bool MoogVibeAudioProcessor::hasEditor() const
//{
//    return true; // (change this to false if you choose to not supply an editor)
//}
//
//juce::AudioProcessorEditor* MoogVibeAudioProcessor::createEditor()
//{
//    //return new MoogVibeAudioProcessorEditor (*this);
//    return new juce::GenericAudioProcessorEditor(*this);
//}

//==============================================================================
void MoogVibeAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void MoogVibeAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new MoogVibeAudioProcessor();
}
