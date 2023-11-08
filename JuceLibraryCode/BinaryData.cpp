/* ==================================== JUCER_BINARY_RESOURCE ====================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

#include <cstring>

namespace BinaryData
{

//================== MoogVibe.xml ==================
static const unsigned char temp_binary_data_0[] =
"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n"
"\r\n"
"<magic>\r\n"
"  <Styles>\r\n"
"    <Style name=\"default\">\r\n"
"      <Nodes/>\r\n"
"      <Classes>\r\n"
"        <plot-view border=\"2\" background-color=\"black\" border-color=\"silver\" display=\"contents\"/>\r\n"
"        <nomargin margin=\"0\" padding=\"0\" border=\"0\"/>\r\n"
"        <group margin=\"5\" padding=\"5\" border=\"2\" flex-direction=\"column\"/>\r\n"
"        <transparent background-color=\"transparentblack\"/>\r\n"
"      </Classes>\r\n"
"      <Types>\r\n"
"        <Slider border=\"0\" slider-textbox=\"textbox-below\"/>\r\n"
"        <ToggleButton border=\"0\" max-height=\"50\" caption-size=\"0\" text=\"Active\"/>\r\n"
"        <TextButton border=\"0\" max-height=\"50\" caption-size=\"0\"/>\r\n"
"        <ComboBox border=\"0\" max-height=\"50\" caption-size=\"0\"/>\r\n"
"        <Plot border=\"0\" margin=\"0\" padding=\"0\" background-color=\"00000000\"\r\n"
"              radius=\"0\"/>\r\n"
"        <XYDragComponent border=\"0\" margin=\"0\" padding=\"0\" background-color=\"00000000\"\r\n"
"                         radius=\"0\"/>\r\n"
"      </Types>\r\n"
"      <Palettes>\r\n"
"        <default/>\r\n"
"      </Palettes>\r\n"
"    </Style>\r\n"
"  </Styles>\r\n"
"  <View id=\"root\" resizable=\"1\" resize-corner=\"1\" background-color=\"FF622500\"\r\n"
"        flex-direction=\"column\" border=\"0\" radius=\"0\" border-color=\"FFDB4545\"\r\n"
"        margin=\"0\" padding=\"0\" width=\"380\" height=\"380\">\r\n"
"    <View flex-direction=\"column\" border=\"2\" border-color=\"FFF4B46D\" radius=\"20\"\r\n"
"          background-color=\"FF622500\">\r\n"
"      <Label text=\"MoogVibe\" justification=\"centred\" font-size=\"24\" background-color=\"FF622500\"\r\n"
"             margin=\"0\" padding=\"0\" border=\"0\" lookAndFeel=\"FoleysFinest\"\r\n"
"             title=\"\" label-background=\"FF622500\" flex-shrink=\"1\" flex-grow=\"2\"/>\r\n"
"      <View margin=\"0\" padding=\"0\" border=\"0\" background-color=\"FF622500\"\r\n"
"            flex-grow=\"8\">\r\n"
"        <Slider caption=\"Cutoff Frequency\" parameter=\"cutoffFrequency\" background-color=\"FF622500\"\r\n"
"                lookAndFeel=\"FoleysFinest\" slider-type=\"rotary-horizontal-vertical\"\r\n"
"                slider-textbox=\"textbox-below\" rotary-fill=\"FFF5BE8D\" slider-background=\"FFFF1919\"\r\n"
"                slider-thumb=\"FFFF0909\" slider-track=\"FFFF0000\" rotary-outline=\"FFBF712B\"\r\n"
"                tab-color=\"\" border-color=\"FFF4B46D\" border=\"2\" radius=\"20\"/>\r\n"
"        <Slider caption=\"Resonance\" parameter=\"resonance\" border=\"2\" border-color=\"FFF4B46D\"\r\n"
"                radius=\"20\" background-color=\"FF622500\" slider-type=\"rotary-horizontal-vertical\"\r\n"
"                rotary-fill=\"FFF5BE8D\" rotary-outline=\"FFBF712B\" slider-text=\"\"/>\r\n"
"      </View>\r\n"
"      <View class=\"parameters nomargin\" background-color=\"FF622500\" flex-grow=\"8\">\r\n"
"        <Slider caption=\"Bass Compensation\" parameter=\"bassComp\" border=\"2\" radius=\"20\"\r\n"
"                border-color=\"FFF4B46D\" background-color=\"FF622500\" slider-type=\"rotary-horizontal-vertical\"\r\n"
"                rotary-fill=\"FFF5BE8D\" rotary-outline=\"FFBF712B\"/>\r\n"
"        <Slider caption=\"Gain\" parameter=\"gain\" rotary-outline=\"FFBF712B\" rotary-fill=\"FFF5BE8D\"\r\n"
"                slider-type=\"rotary-horizontal-vertical\" background-color=\"FF622500\"\r\n"
"                border-color=\"FFF4B46D\" border=\"2\" radius=\"20\"/>\r\n"
"      </View>\r\n"
"    </View>\r\n"
"  </View>\r\n"
"</magic>\r\n";

const char* MoogVibe_xml = (const char*) temp_binary_data_0;


const char* getNamedResource (const char* resourceNameUTF8, int& numBytes);
const char* getNamedResource (const char* resourceNameUTF8, int& numBytes)
{
    unsigned int hash = 0;

    if (resourceNameUTF8 != nullptr)
        while (*resourceNameUTF8 != 0)
            hash = 31 * hash + (unsigned int) *resourceNameUTF8++;

    switch (hash)
    {
        case 0xb80387c8:  numBytes = 3146; return MoogVibe_xml;
        default: break;
    }

    numBytes = 0;
    return nullptr;
}

const char* namedResourceList[] =
{
    "MoogVibe_xml"
};

const char* originalFilenames[] =
{
    "MoogVibe.xml"
};

const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8);
const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8)
{
    for (unsigned int i = 0; i < (sizeof (namedResourceList) / sizeof (namedResourceList[0])); ++i)
        if (strcmp (namedResourceList[i], resourceNameUTF8) == 0)
            return originalFilenames[i];

    return nullptr;
}

}
