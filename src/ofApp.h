#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void keyPressed();
    
    //--------------------------------------------------------------
    
    ofTrueTypeFont font;
    vector<string> inputText; // The whole text doc
    vector<vector<string> > stanzas; // a vector that contains each stanza
    vector<string> soundTitles;
    vector<ofSoundPlayer> speechArray;
    string speechNumberStr;
    ofSoundPlayer soundPlayer;
    int nextSpeechTime;
    int timeBetweenSpeech;
    
    bool shouldSpeak; //if true, the stanza will be spoken
    
    int gridToSpeak; // Random number, determines which grid to speak
    int numStanzasX; // Number of across
    int numStanzasY; // Number of stanzas down
    int gapX; // Space between each stanza
    int gapY; // Space above and below each stanza
    int maxStanzaWidth; // Max width of each stanza
    int maxStanzaHeight; // Max height of each stanza
    int wordTime; // Amount of time between displaying each word
    
    float newSpeechTime;
    
    
    // 00 ----- 00 ----- 00 ----- 00 ----- 00 ----- 00 ----- 00
    int stanzaX00; // X location of the 00 text block
    int stanzaY00; // Y location of the 00 text block
    int transparency00; // Transparency of the 00 text block
    int wordIndex00; // keeps track of each word in a stanza
    int randomStanzaIndex00; // used to select a random stanza
    float nextWordTime00; // Time before next word is displayed
    
    string wholeLine00; // The stanza to be displayed word by word
    string strSoFar00; // Proxy string measures text block width
    
    
    // 01 ----- 01 ----- 01 ----- 01 ----- 01 ----- 01 ----- 01
    int stanzaX01;
    int stanzaY01;
    int transparency01;
    int wordIndex01;
    int randomStanzaIndex01;
    float nextWordTime01;
    
    string wholeLine01;
    string strSoFar01;
    
    // 02 ----- 02 ----- 02 ----- 02 ----- 02 ----- 02 ----- 02
    int stanzaX02;
    int stanzaY02;
    int transparency02;
    int wordIndex02;
    int randomStanzaIndex02;
    float nextWordTime02;
    
    string wholeLine02;
    string strSoFar02;
    
    // 03 ----- 03 ----- 03 ----- 03 ----- 03 ----- 03 ----- 03
    int stanzaX03;
    int stanzaY03;
    int transparency03;
    int wordIndex03;
    int randomStanzaIndex03;
    float nextWordTime03;
    
    string wholeLine03;
    string strSoFar03;
    
    // 04 ----- 04 ----- 04 ----- 04 ----- 04 ----- 04 ----- 04
    int stanzaX04;
    int stanzaY04;
    int transparency04;
    int wordIndex04;
    int randomStanzaIndex04;
    float nextWordTime04;
    
    string wholeLine04;
    string strSoFar04;
    
    // 05 ----- 05 ----- 05 ----- 05 ----- 05 ----- 05 ----- 05
    int stanzaX05;
    int stanzaY05;
    int transparency05;
    int wordIndex05;
    int randomStanzaIndex05;
    float nextWordTime05;
    
    string wholeLine05;
    string strSoFar05;
    
    // 06 ----- 06 ----- 06 ----- 06 ----- 06 ----- 06 ----- 06
    int stanzaX06;
    int stanzaY06;
    int transparency06;
    int wordIndex06;
    int randomStanzaIndex06;
    float nextWordTime06;
    
    string wholeLine06;
    string strSoFar06;
    
    // 07 ----- 07 ----- 07 ----- 07 ----- 07 ----- 07 ----- 07
    int stanzaX07;
    int stanzaY07;
    int transparency07;
    int wordIndex07;
    int randomStanzaIndex07;
    float nextWordTime07;
    
    string wholeLine07;
    string strSoFar07;
    
    // 08 ----- 08 ----- 08 ----- 08 ----- 08 ----- 08 ----- 08
    int stanzaX08;
    int stanzaY08;
    int transparency08;
    int wordIndex08;
    int randomStanzaIndex08;
    float nextWordTime08;
    
    string wholeLine08;
    string strSoFar08;
    
    // 09 ----- 09 ----- 09 ----- 09 ----- 09 ----- 09 ----- 09
    int stanzaX09;
    int stanzaY09;
    int transparency09;
    int wordIndex09;
    int randomStanzaIndex09;
    float nextWordTime09;
    
    string wholeLine09;
    string strSoFar09;
    
    // 10 ----- 10 ----- 10 ----- 10 ----- 10 ----- 10 ----- 10
    int stanzaX10;
    int stanzaY10;
    int transparency10;
    int wordIndex10;
    int randomStanzaIndex10;
    float nextWordTime10;
    
    string wholeLine10;
    string strSoFar10;
    
    // 11 ----- 11 ----- 11 ----- 11 ----- 11 ----- 11 ----- 11
    int stanzaX11;
    int stanzaY11;
    int transparency11;
    int wordIndex11;
    int randomStanzaIndex11;
    float nextWordTime11;
    
    string wholeLine11;
    string strSoFar11;
    
    // 12 ----- 12 ----- 12 ----- 12 ----- 12 ----- 12 ----- 12
    int stanzaX12;
    int stanzaY12;
    int transparency12;
    int wordIndex12;
    int randomStanzaIndex12;
    float nextWordTime12;
    
    string wholeLine12;
    string strSoFar12;
    
    // 13 ----- 13 ----- 13 ----- 13 ----- 13 ----- 13 ----- 13
    int stanzaX13;
    int stanzaY13;
    int transparency13;
    int wordIndex13;
    int randomStanzaIndex13;
    float nextWordTime13;
    
    string wholeLine13;
    string strSoFar13;
    
    // 14 ----- 14 ----- 14 ----- 14 ----- 14 ----- 14 ----- 14
    int stanzaX14;
    int stanzaY14;
    int transparency14;
    int wordIndex14;
    int randomStanzaIndex14;
    float nextWordTime14;
    
    string wholeLine14;
    string strSoFar14;
    
    // 15 ----- 15 ----- 15 ----- 15 ----- 15 ----- 15 ----- 15
    int stanzaX15;
    int stanzaY15;
    int transparency15;
    int wordIndex15;
    int randomStanzaIndex15;
    float nextWordTime15;
    
    string wholeLine15;
    string strSoFar15;
    
    // 16 ----- 16 ----- 16 ----- 16 ----- 16 ----- 16 ----- 16
    int stanzaX16;
    int stanzaY16;
    int transparency16;
    int wordIndex16;
    int randomStanzaIndex16;
    float nextWordTime16;
    
    string wholeLine16;
    string strSoFar16;
    
    // 17 ----- 17 ----- 17 ----- 17 ----- 17 ----- 17 ----- 17
    int stanzaX17;
    int stanzaY17;
    int transparency17;
    int wordIndex17;
    int randomStanzaIndex17;
    float nextWordTime17;
    
    string wholeLine17;
    string strSoFar17;
    
    // 18 ----- 18 ----- 18 ----- 18 ----- 18 ----- 18 ----- 18
    int stanzaX18;
    int stanzaY18;
    int transparency18;
    int wordIndex18;
    int randomStanzaIndex18;
    float nextWordTime18;
    
    string wholeLine18;
    string strSoFar18;
    
    // 19 ----- 19 ----- 19 ----- 19 ----- 19 ----- 19 ----- 19
    int stanzaX19;
    int stanzaY19;
    int transparency19;
    int wordIndex19;
    int randomStanzaIndex19;
    float nextWordTime19;
    
    string wholeLine19;
    string strSoFar19;
    
    // 20 ----- 20 ----- 20 ----- 20 ----- 20 ----- 20 ----- 20
    int stanzaX20;
    int stanzaY20;
    int transparency20;
    int wordIndex20;
    int randomStanzaIndex20;
    float nextWordTime20;
    
    string wholeLine20;
    string strSoFar20;
    
    // 21 ----- 21 ----- 21 ----- 21 ----- 21 ----- 21 ----- 21
    int stanzaX21;
    int stanzaY21;
    int transparency21;
    int wordIndex21;
    int randomStanzaIndex21;
    float nextWordTime21;
    
    string wholeLine21;
    string strSoFar21;
    
    // 22 ----- 22 ----- 22 ----- 22 ----- 22 ----- 22 ----- 22
    int stanzaX22;
    int stanzaY22;
    int transparency22;
    int wordIndex22;
    int randomStanzaIndex22;
    float nextWordTime22;
    
    string wholeLine22;
    string strSoFar22;
    
    // 23 ----- 23 ----- 23 ----- 23 ----- 23 ----- 23 ----- 23
    int stanzaX23;
    int stanzaY23;
    int transparency23;
    int wordIndex23;
    int randomStanzaIndex23;
    float nextWordTime23;
    
    string wholeLine23;
    string strSoFar23;
    
    // 24 ----- 24 ----- 24 ----- 24 ----- 24 ----- 24 ----- 24
    int stanzaX24;
    int stanzaY24;
    int transparency24;
    int wordIndex24;
    int randomStanzaIndex24;
    float nextWordTime24;
    
    string wholeLine24;
    string strSoFar24;
    
    // 25 ----- 25 ----- 25 ----- 25 ----- 25 ----- 25 ----- 25
    int stanzaX25;
    int stanzaY25;
    int transparency25;
    int wordIndex25;
    int randomStanzaIndex25;
    float nextWordTime25;
    
    string wholeLine25;
    string strSoFar25;
    
    // 26 ----- 26 ----- 26 ----- 26 ----- 26 ----- 26 ----- 26
    int stanzaX26;
    int stanzaY26;
    int transparency26;
    int wordIndex26;
    int randomStanzaIndex26;
    float nextWordTime26;
    
    string wholeLine26;
    string strSoFar26;
    
    
    int stanzaX27;
    int stanzaY27;
    int transparency27;
    int wordIndex27;
    int randomStanzaIndex27;
    float nextWordTime27;
    
    string wholeLine27;
    string strSoFar27;
    
    //---------------------------------------------------------//
    
    
    
    
    
    
    
    
    
    
    /* So basically, I need to create a dynamically generating grid of
     poetic stanzas. Since this will be projected, it will be nice
     and big. Projecting it in the classroom in 1080p...
     
     So let's do a grid of 7x5 stanzas. Basically, 35 distinct
     randomly generating cells.
     
     If there's 7x5, the width of each stanza should be around
     
     1/7 the width of the window, with a little bit of space in
     between each.
     
     So in that case, the width of each should be 1/8, where the space
     in between each should 1/64 the width of the window
     (because 6 gaps + margins right?)
     
     The height of each should 1/6, so the space between each should
     be 1/42 the height of the window
     
     Also, does this mean we're going to need 35 versions of each
     of the above variables? I fucking think so. Damn.
     
     And so you also want to play a sound file, right?
     
     To play a sound file that corresponds to one of the
     stanzas on the grid, I'll have to create 35 switch
     cases that correspond to each
     
     We also want to get each one to fade away, and
     not just disappear
     
     we also want each one to appear at a different
     time (which should happen on its own given
     the different stanza lengths*/
};

