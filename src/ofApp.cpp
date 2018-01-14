#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    
    /* Okay, so, I want a sound file to trigger when a certain stanza is displayed on
        the screen. Each Draw cycle, a new word is drawn for each stanza. If the Stanza
        reaches its end, it fades away and a new one takes its place. Maybe every 30
        seconds, have a new sound file play.
     
        So, when a new, randomly selected stanza starts typing itself out, its
        corresponding sound file should be read aloud.
     
     Note: Each stanza and each sound file in their respective arrays should align
     perfectly, so if I can feed the correct stanza index to the sound filename index,
     then the correct stanza will play.
     
     But how do I get each stanza to start and stop at the correct time? and do I want
     them to be read one after another? Should there be time in between?
     
     Make a switch case thing so that random stanza indices are selected each time a stanza is finished being read, and will
     
     int stanzaToSpeak =  ofRandom(0, stanzas.size());
     
     switch
     case '0'
     {
     soundPlayer.load(soundTitles[randomStanzaIndex00];
     }
     
     Thought: what if I put the conversation between Aram and myself into this program?
     That way it would connect the two pieces.
     
     
     */
    
    ofBackground(0);
    ofSetFrameRate(60);
    
    ofTrueTypeFont::setGlobalDpi(96);
    font.load("SF-Pro-Display-Medium.otf", 11, true, 96);
    ofBuffer buffer = ofBufferFromFile("allpoetryformatted.txt");
    
    ofBuffer soundTitlesBuffer = ofBufferFromFile("soundTitles.txt");
    shouldSpeak = false;
    
    
    wordTime = 220;
    timeBetweenSpeech = 5000;
    nextSpeechTime = 0;
    numStanzasX = 6;
    numStanzasY = 4;
    gapX = ofGetWidth()/((numStanzasX - 2) * (numStanzasX + 1));
    gapY = ofGetHeight()/((numStanzasY - 1) * (numStanzasY + 1));
    
    maxStanzaWidth = (ofGetWidth()/(numStanzasX + 2));
    maxStanzaHeight = (ofGetHeight()/(numStanzasY + 2));
    
    
    
    // 00 ----- 00 ----- 00 ----- 00 ----- 00 ----- 00 ----- 00
    stanzaX00 = gapX - 24;
    stanzaY00 = gapY;
    transparency00 = 255;
    wordIndex00 = 0;
    
    // 01 ----- 01 ----- 01 ----- 01 ----- 01 ----- 01 ----- 01
    stanzaX01 = 2*gapX + maxStanzaWidth - 24;
    stanzaY01 = gapY;
    transparency01 = 255;
    wordIndex01 = 0;
    
    // 02 ----- 02 ----- 02 ----- 02 ----- 02 ----- 02 ----- 02
    stanzaX02 = 3*gapX + (2*maxStanzaWidth) - 24;
    stanzaY02 = gapY;
    transparency02 = 255;
    wordIndex02 = 0;
    
    // 03 ----- 03 ----- 03 ----- 03 ----- 03 ----- 03 ----- 03
    stanzaX03 = 4*gapX + (3*maxStanzaWidth) - 24;
    stanzaY03 = gapY;
    transparency03 = 255;
    wordIndex03 = 0;
    
    // 04 ----- 04 ----- 04 ----- 04 ----- 04 ----- 04 ----- 04
    stanzaX04 = 5*gapX + (4*maxStanzaWidth) - 24;
    stanzaY04 = gapY;
    transparency04 = 255;
    wordIndex04 = 0;
    
    // 05 ----- 05 ----- 05 ----- 05 ----- 05 ----- 05 ----- 05
    stanzaX05 = 6*gapX + (5*maxStanzaWidth) - 24;
    stanzaY05 = gapY;
    transparency05 = 255;
    wordIndex05 = 0;
    
    // 06 ----- 06 ----- 06 ----- 06 ----- 06 ----- 06 ----- 06
    stanzaX06 = gapX - 24;
    stanzaY06 = 2*gapY + maxStanzaHeight;
    transparency06 = 255;
    wordIndex06 = 0;
    
    // 07 ----- 07 ----- 07 ----- 07 ----- 07 ----- 07 ----- 07
    stanzaX07 = 2*gapX + maxStanzaWidth - 24;
    stanzaY07 = 2*gapY + maxStanzaHeight;
    transparency07 = 255;
    wordIndex07 = 0;
    
    // 08 ----- 08 ----- 08 ----- 08 ----- 08 ----- 08 ----- 08
    stanzaX08 = 3*gapX + (2*maxStanzaWidth) - 24;
    stanzaY08 = 2*gapY + maxStanzaHeight;
    transparency08 = 255;
    wordIndex08 = 0;
    
    // 09 ----- 09 ----- 09 ----- 09 ----- 09 ----- 09 ----- 09
    stanzaX09 = 4*gapX + (3*maxStanzaWidth) - 24;
    stanzaY09 = 2*gapY + maxStanzaHeight;
    transparency09 = 255;
    wordIndex09 = 0;
    
    // 10 ----- 10 ----- 10 ----- 10 ----- 10 ----- 10 ----- 10
    stanzaX10 = 5*gapX + (4*maxStanzaWidth) - 24;
    stanzaY10 = 2*gapY + maxStanzaHeight;
    transparency10 = 255;
    wordIndex10 = 0;
    
    // 11 ----- 11 ----- 11 ----- 11 ----- 11 ----- 11 ----- 11
    stanzaX11 = 6*gapX + (5*maxStanzaWidth) - 24;
    stanzaY11 = 2*gapY + maxStanzaHeight;
    transparency11 = 255;
    wordIndex11 = 0;
    
    // 12 ----- 12 ----- 12 ----- 12 ----- 12 ----- 12 ----- 12
    stanzaX12 = gapX - 24;
    stanzaY12 = 3*gapY + (2*maxStanzaHeight);
    transparency12 = 255;
    wordIndex12 = 0;
    
    // 13 ----- 13 ----- 13 ----- 13 ----- 13 ----- 13 ----- 13
    stanzaX13 = 2*gapX + maxStanzaWidth - 24;
    stanzaY13 = 3*gapY + (2*maxStanzaHeight);
    transparency13 = 255;
    wordIndex13 = 0;
    
    // 14 ----- 14 ----- 14 ----- 14 ----- 14 ----- 14 ----- 14
    stanzaX14 = 3*gapX + (2*maxStanzaWidth) - 24;
    stanzaY14 = 3*gapY + (2*maxStanzaHeight);
    transparency14 = 255;
    wordIndex14 = 0;
    
    // 15 ----- 15 ----- 15 ----- 15 ----- 15 ----- 15 ----- 15
    stanzaX15 = 4*gapX + (3*maxStanzaWidth) - 24;
    stanzaY15 = 3*gapY + (2*maxStanzaHeight);
    transparency15 = 255;
    wordIndex15 = 0;
    
    // 16 ----- 16 ----- 16 ----- 16 ----- 16 ----- 16 ----- 16
    stanzaX16 = 5*gapX + (4*maxStanzaWidth) - 24;
    stanzaY16 = 3*gapY + (2*maxStanzaHeight);
    transparency16 = 255;
    wordIndex16 = 0;
    
    // 17 ----- 17 ----- 17 ----- 17 ----- 17 ----- 17 ----- 17
    stanzaX17 = 6*gapX + (5*maxStanzaWidth) - 24;
    stanzaY17 = 3*gapY + (2*maxStanzaHeight);
    transparency17 = 255;
    wordIndex17 = 0;
    
    // 18 ----- 18 ----- 18 ----- 18 ----- 18 ----- 18 ----- 18
    stanzaX18 = gapX - 24;
    stanzaY18 = 4*gapY + (3*maxStanzaHeight);
    transparency18 = 255;
    wordIndex18 = 0;
    
    // 19 ----- 19 ----- 19 ----- 19 ----- 19 ----- 19 ----- 19
    stanzaX19 = 2*gapX + maxStanzaWidth - 24;
    stanzaY19 = 4*gapY + (3*maxStanzaHeight);
    transparency19 = 255;
    wordIndex19 = 0;
    
    // 20 ----- 20 ----- 20 ----- 20 ----- 20 ----- 20 ----- 20
    stanzaX20 = 3*gapX + (2*maxStanzaWidth) - 24;
    stanzaY20 = 4*gapY + (3*maxStanzaHeight);
    transparency20 = 255;
    wordIndex20 = 0;
    
    // 21 ----- 21 ----- 21 ----- 21 ----- 21 ----- 21 ----- 21
    stanzaX21 = 4*gapX + (3*maxStanzaWidth) - 24;
    stanzaY21 = 4*gapY + (3*maxStanzaHeight);
    transparency21 = 255;
    wordIndex21 = 0;
    
    // 22 ----- 22 ----- 22 ----- 22 ----- 22 ----- 22 ----- 22
    stanzaX22 = 5*gapX + (4*maxStanzaWidth) - 24;
    stanzaY22 = 4*gapY + (3*maxStanzaHeight);
    transparency22 = 255;
    wordIndex22 = 0;
    
    // 23 ----- 23 ----- 23 ----- 23 ----- 23 ----- 23 ----- 23
    stanzaX23 = 6*gapX + (5*maxStanzaWidth) - 24;
    stanzaY23 = 4*gapY + (3*maxStanzaHeight);
    transparency23 = 255;
    wordIndex23 = 0;
    
    
    if(buffer.size()) {
        
        for (ofBuffer::Line it = buffer.getLines().begin(), end = buffer.getLines().end(); it != end; ++it)
        {
            string line = *it;
            if(line.empty() == false) {
                inputText.push_back(line);
                
                /* each cell in the inputText vector is a line. So the whole
                 doc is broken up by each line in the text file */
            }
        }
    }
    
    if(soundTitlesBuffer.size()) {
        
        for(ofBuffer::Line titles = soundTitlesBuffer.getLines().begin(), end = soundTitlesBuffer.getLines().end(); titles != end; ++titles)
        {
            string titleLine = *titles;
            if(titleLine.empty() == false) {
                soundTitles.push_back(titleLine);
            }
        }
    }
    
    for(int i = 0; i < soundTitles.size(); i++)
    {
        cout << soundTitles[i] << endl;
    }
    
    /* Fill up a vector<vector<string> with each line of the inputText vector<string> */
    for(int i = 0; i < inputText.size(); i++)
    {
        std::vector<std::string> tokens = ofSplitString(inputText[i], " ", true, true);
        
        if (tokens.empty())
        {
            std::cout << "SCREEEEAAM" << std::endl;
        }
        else
        {
            stanzas.push_back(tokens);
        }
        
    }
    
    randomStanzaIndex00 = (int)ofRandom(0, stanzas.size());
    randomStanzaIndex01 = (int)ofRandom(0, stanzas.size());
    randomStanzaIndex02 = (int)ofRandom(0, stanzas.size());
    randomStanzaIndex03 = (int)ofRandom(0, stanzas.size());
    randomStanzaIndex04 = (int)ofRandom(0, stanzas.size());
    randomStanzaIndex05 = (int)ofRandom(0, stanzas.size());
    randomStanzaIndex06 = (int)ofRandom(0, stanzas.size());
    randomStanzaIndex07 = (int)ofRandom(0, stanzas.size());
    randomStanzaIndex08 = (int)ofRandom(0, stanzas.size());
    randomStanzaIndex09 = (int)ofRandom(0, stanzas.size());
    randomStanzaIndex10 = (int)ofRandom(0, stanzas.size());
    randomStanzaIndex11 = (int)ofRandom(0, stanzas.size());
    randomStanzaIndex12 = (int)ofRandom(0, stanzas.size());
    randomStanzaIndex13 = (int)ofRandom(0, stanzas.size());
    randomStanzaIndex14 = (int)ofRandom(0, stanzas.size());
    randomStanzaIndex15 = (int)ofRandom(0, stanzas.size());
    randomStanzaIndex16 = (int)ofRandom(0, stanzas.size());
    randomStanzaIndex17 = (int)ofRandom(0, stanzas.size());
    randomStanzaIndex18 = (int)ofRandom(0, stanzas.size());
    randomStanzaIndex19 = (int)ofRandom(0, stanzas.size());
    randomStanzaIndex20 = (int)ofRandom(0, stanzas.size());
    randomStanzaIndex21 = (int)ofRandom(0, stanzas.size());
    randomStanzaIndex22 = (int)ofRandom(0, stanzas.size());
    randomStanzaIndex23 = (int)ofRandom(0, stanzas.size());
    randomStanzaIndex24 = (int)ofRandom(0, stanzas.size());
    randomStanzaIndex25 = (int)ofRandom(0, stanzas.size());
    randomStanzaIndex26 = (int)ofRandom(0, stanzas.size());
    randomStanzaIndex27 = (int)ofRandom(0, stanzas.size());
    
    
    //For debugging, print out each line in the input text file
    //    for(int i = 0; i < stanzas.size(); i++)
    //    {
    //        for(int j = 0; j < stanzas[i].size(); j++)
    //        {
    //            cout << stanzas[i][j] + " ";
    //        }
    //        cout << "" << endl;
    //    }
}

//--------------------------------------------------------------
void ofApp::update()
{
    ofSoundUpdate();
}
//--------------------------------------------------------------
void ofApp::draw(){
    
    
    
    
    
    newSpeechTime = ofGetElapsedTimeMillis() - nextSpeechTime;


    if(newSpeechTime > timeBetweenSpeech)
    {
        shouldSpeak = true;
        nextSpeechTime = ofGetElapsedTimeMillis();
        gridToSpeak = (int)ofRandom(0, 24);
    }

    if(shouldSpeak)
    {
        if(gridToSpeak == 0)
        {
            soundPlayer.load(soundTitles[randomStanzaIndex00]);
            soundPlayer.play();
            shouldSpeak = false;
        }

        else if(gridToSpeak == 1)
        {
            soundPlayer.load(soundTitles[randomStanzaIndex01]);
            soundPlayer.play();
            shouldSpeak = false;
        }

        else if(gridToSpeak == 2)
        {
            soundPlayer.load(soundTitles[randomStanzaIndex02]);
            soundPlayer.play();
            shouldSpeak = false;
        }

        else if(gridToSpeak == 3)
        {
            soundPlayer.load(soundTitles[randomStanzaIndex03]);
            soundPlayer.play();
            shouldSpeak = false;
        }

        else if(gridToSpeak == 4)
        {
            soundPlayer.load(soundTitles[randomStanzaIndex04]);
            soundPlayer.play();
            shouldSpeak = false;
        }

        else if(gridToSpeak == 5)
        {
            soundPlayer.load(soundTitles[randomStanzaIndex05]);
            soundPlayer.play();
            shouldSpeak = false;
        }

        else if(gridToSpeak == 6)
        {
            soundPlayer.load(soundTitles[randomStanzaIndex06]);
            soundPlayer.play();
            shouldSpeak = false;
        }

        else if(gridToSpeak == 7)
        {
            soundPlayer.load(soundTitles[randomStanzaIndex07]);
            soundPlayer.play();
            shouldSpeak = false;
        }

        else if(gridToSpeak == 8)
        {
            soundPlayer.load(soundTitles[randomStanzaIndex08]);
            soundPlayer.play();
            shouldSpeak = false;
        }

        else if(gridToSpeak == 9)
        {
            soundPlayer.load(soundTitles[randomStanzaIndex09]);
            soundPlayer.play();
            shouldSpeak = false;
        }

        else if(gridToSpeak == 10)
        {
            soundPlayer.load(soundTitles[randomStanzaIndex10]);
            soundPlayer.play();
            shouldSpeak = false;
        }

        else if(gridToSpeak == 11)
        {
            soundPlayer.load(soundTitles[randomStanzaIndex11]);
            soundPlayer.play();
            shouldSpeak = false;
        }

        else if(gridToSpeak == 12)
        {
            soundPlayer.load(soundTitles[randomStanzaIndex12]);
            soundPlayer.play();
            shouldSpeak = false;
        }

        else if(gridToSpeak == 13)
        {
            soundPlayer.load(soundTitles[randomStanzaIndex13]);
            soundPlayer.play();
            shouldSpeak = false;
        }

        else if(gridToSpeak == 14)
        {
            soundPlayer.load(soundTitles[randomStanzaIndex14]);
            soundPlayer.play();
            shouldSpeak = false;
        }

        else if(gridToSpeak == 15)
        {
            soundPlayer.load(soundTitles[randomStanzaIndex15]);
            soundPlayer.play();
            shouldSpeak = false;
        }

        else if(gridToSpeak == 16)
        {
            soundPlayer.load(soundTitles[randomStanzaIndex16]);
            soundPlayer.play();
            shouldSpeak = false;
        }

        else if(gridToSpeak == 17)
        {
            soundPlayer.load(soundTitles[randomStanzaIndex17]);
            soundPlayer.play();
            shouldSpeak = false;
        }

        else if(gridToSpeak == 18)
        {
            soundPlayer.load(soundTitles[randomStanzaIndex18]);
            soundPlayer.play();
            shouldSpeak = false;
        }

        else if(gridToSpeak == 19)
        {
            soundPlayer.load(soundTitles[randomStanzaIndex19]);
            soundPlayer.play();
            shouldSpeak = false;
        }

        else if(gridToSpeak == 20)
        {
            soundPlayer.load(soundTitles[randomStanzaIndex20]);
            soundPlayer.play();
            shouldSpeak = false;
        }

        else if(gridToSpeak == 21)
        {
            soundPlayer.load(soundTitles[randomStanzaIndex21]);
            soundPlayer.play();
            shouldSpeak = false;
        }

        else if(gridToSpeak == 22)
        {
            soundPlayer.load(soundTitles[randomStanzaIndex22]);
            soundPlayer.play();
            shouldSpeak = false;
        }

        else
        {
            soundPlayer.load(soundTitles[randomStanzaIndex23]);
            soundPlayer.play();
            shouldSpeak = false;
        }
    }
    
    // 00 ----- 00 ----- 00 ----- 00 ----- 00 ----- 00 ----- 00
    
    // Constrain width of the text block
    
    
    // this is our timer for grabbing the next word
    float time00 = ofGetElapsedTimeMillis() - nextWordTime00;
    
    if(font.stringWidth(strSoFar00) + font.stringWidth(stanzas[randomStanzaIndex00][wordIndex00]) - 20 > maxStanzaWidth)
    {
        wholeLine00 += "\n";
        strSoFar00 = "";
    }
    
    // if it's been long enough, add another word to the stanza
    if(time00 > wordTime)
    {
        
        if(transparency00 == 255)
        {
            
            
            // Create proxy string used for keeping track of text block width
            strSoFar00 = strSoFar00 + " " + stanzas[randomStanzaIndex00][wordIndex00];
            
            // With each frame, add a new word to the string in the text block
            wholeLine00 = wholeLine00 + " " + stanzas[randomStanzaIndex00][wordIndex00];
            
            cout << wholeLine00 << endl;
            
            
            
        }
        // Once the full stanza has been written out, reset the text
        if(wordIndex00 > stanzas[randomStanzaIndex00].size()-2)
        {
            transparency00-=2;
            
            if(transparency00 < 0)
            {
                wordIndex00 = 0;
                randomStanzaIndex00 = (int)ofRandom(0, stanzas.size());
                wholeLine00 = "";
                strSoFar00 = "";
                transparency00 = 255;
            }
            
        } else {
            // Increment the stanza index so the next word may be added
            wordIndex00++;
            nextWordTime00 = ofGetElapsedTimeMillis();
        }
    }
    // Draw the text block
    ofSetColor(255, 255, 255, transparency00);
    font.drawString(wholeLine00, stanzaX00, stanzaY00);
    
    // 01 ----- 01 ----- 01 ----- 01 ----- 01 ----- 01 ----- 01
    
    if(font.stringWidth(strSoFar01) + font.stringWidth(stanzas[randomStanzaIndex01][wordIndex01]) - 20 > maxStanzaWidth)
    {
        wholeLine01 += "\n";
        strSoFar01 = "";
    }
    
    float time01 = ofGetElapsedTimeMillis() - nextWordTime01;
    
    if(time01 > wordTime)
    {
        if(transparency01 == 255)
        {
            strSoFar01 = strSoFar01 + " " + stanzas[randomStanzaIndex01][wordIndex01];
            
            wholeLine01 = wholeLine01 + " " + stanzas[randomStanzaIndex01][wordIndex01];
            
            cout << wholeLine01 << endl;
            
        }
        if(wordIndex01 > stanzas[randomStanzaIndex01].size()-2)
        {
            transparency01-=2;
            
            if(transparency01 < 0)
            {
                wordIndex01 = 0;
                randomStanzaIndex01 = (int)ofRandom(0, stanzas.size());
                wholeLine01 = "";
                strSoFar01 = "";
                transparency01 = 255;
                
            }
            
        } else {
            wordIndex01++;
            nextWordTime01 = ofGetElapsedTimeMillis();
        }
    }
    ofSetColor(255, 255, 255, transparency01);
    font.drawString(wholeLine01, stanzaX01, stanzaY01);
    
    
    // 02 ----- 02 ----- 02 ----- 02 ----- 02 ----- 02 ----- 02
    
    if(font.stringWidth(strSoFar02) + font.stringWidth(stanzas[randomStanzaIndex02][wordIndex02]) - 20 > maxStanzaWidth)
    {
        wholeLine02 += "\n";
        strSoFar02 = "";
    }
    
    float time02 = ofGetElapsedTimeMillis() - nextWordTime02;
    
    if(time02 > wordTime)
    {
        if(transparency02 == 255)
        {
            strSoFar02 = strSoFar02 + " " + stanzas[randomStanzaIndex02][wordIndex02];
            
            wholeLine02 = wholeLine02 + " " + stanzas[randomStanzaIndex02][wordIndex02];
            
            cout << wholeLine02 << endl;
            
        }
        if(wordIndex02 > stanzas[randomStanzaIndex02].size()-2)
        {
            transparency02-=2;
            
            if(transparency02 < 0)
            {
                wordIndex02 = 0;
                randomStanzaIndex02 = (int)ofRandom(0, stanzas.size());
                wholeLine02 = "";
                strSoFar02 = "";
                transparency02 = 255;
            }
            
        } else {
            wordIndex02++;
            nextWordTime02 = ofGetElapsedTimeMillis();
        }
    }
    ofSetColor(255, 255, 255, transparency02);
    font.drawString(wholeLine02, stanzaX02, stanzaY02);
    
    
    // 03 ----- 03 ----- 03 ----- 03 ----- 03 ----- 03 ----- 03
    
    if(font.stringWidth(strSoFar03) + font.stringWidth(stanzas[randomStanzaIndex03][wordIndex03]) - 20 > maxStanzaWidth)
    {
        wholeLine03 += "\n";
        strSoFar03 = "";
    }
    
    float time03 = ofGetElapsedTimeMillis() - nextWordTime03;
    
    if(time03 > wordTime)
    {
        if(transparency03 == 255)
        {
            strSoFar03 = strSoFar03 + " " + stanzas[randomStanzaIndex03][wordIndex03];
            
            wholeLine03 = wholeLine03 + " " + stanzas[randomStanzaIndex03][wordIndex03];
            
            cout << wholeLine03 << endl;
            
        }
        if(wordIndex03 > stanzas[randomStanzaIndex03].size()-2)
        {
            transparency03-=2;
            
            if(transparency03 < 0)
            {
                wordIndex03 = 0;
                randomStanzaIndex03 = (int)ofRandom(0, stanzas.size());
                wholeLine03 = "";
                strSoFar03 = "";
                transparency03 = 255;
            }
            
        } else {
            wordIndex03++;
            nextWordTime03 = ofGetElapsedTimeMillis();
        }
    }
    ofSetColor(255, 255, 255, transparency03);
    font.drawString(wholeLine03, stanzaX03, stanzaY03);
    
    
    // 04 ----- 04 ----- 04 ----- 04 ----- 04 ----- 04 ----- 04
    
    if(font.stringWidth(strSoFar04) + font.stringWidth(stanzas[randomStanzaIndex04][wordIndex04]) - 20 > maxStanzaWidth)
    {
        wholeLine04 += "\n";
        strSoFar04 = "";
    }
    
    float time04 = ofGetElapsedTimeMillis() - nextWordTime04;
    
    if(time04 > wordTime)
    {
        if(transparency04 == 255)
        {
            strSoFar04 = strSoFar04 + " " + stanzas[randomStanzaIndex04][wordIndex04];
            
            wholeLine04 = wholeLine04 + " " + stanzas[randomStanzaIndex04][wordIndex04];
            
            cout << wholeLine04 << endl;
            
        }
        if(wordIndex04 > stanzas[randomStanzaIndex04].size()-2)
        {
            transparency04-=2;
            
            if(transparency04 < 0)
            {
                wordIndex04 = 0;
                randomStanzaIndex04 = (int)ofRandom(0, stanzas.size());
                wholeLine04 = "";
                strSoFar04 = "";
                transparency04 = 255;
            }
            
        } else {
            wordIndex04++;
            nextWordTime04 = ofGetElapsedTimeMillis();
        }
    }
    ofSetColor(255, 255, 255, transparency04);
    font.drawString(wholeLine04, stanzaX04, stanzaY04);
    
    
    // 05 ----- 05 ----- 05 ----- 05 ----- 05 ----- 05 ----- 05
    
    if(font.stringWidth(strSoFar05) + font.stringWidth(stanzas[randomStanzaIndex05][wordIndex05]) - 20 > maxStanzaWidth)
    {
        wholeLine05 += "\n";
        strSoFar05 = "";
    }
    
    float time05 = ofGetElapsedTimeMillis() - nextWordTime05;
    
    if(time05 > wordTime)
    {
        if(transparency05 == 255)
        {
            strSoFar05 = strSoFar05 + " " + stanzas[randomStanzaIndex05][wordIndex05];
            
            wholeLine05 = wholeLine05 + " " + stanzas[randomStanzaIndex05][wordIndex05];
            
            cout << wholeLine05 << endl;
            
        }
        if(wordIndex05 > stanzas[randomStanzaIndex05].size()-2)
        {
            transparency05-=2;
            
            if(transparency05 < 0)
            {
                wordIndex05 = 0;
                randomStanzaIndex05 = (int)ofRandom(0, stanzas.size());
                wholeLine05 = "";
                strSoFar05 = "";
                transparency05 = 255;
            }
            
        } else {
            wordIndex05++;
            nextWordTime05 = ofGetElapsedTimeMillis();
        }
    }
    ofSetColor(255, 255, 255, transparency05);
    font.drawString(wholeLine05, stanzaX05, stanzaY05);
    
    
    // 06 ----- 06 ----- 06 ----- 06 ----- 06 ----- 06 ----- 06
    
    if(font.stringWidth(strSoFar06) + font.stringWidth(stanzas[randomStanzaIndex06][wordIndex06]) - 20 > maxStanzaWidth)
    {
        wholeLine06 += "\n";
        strSoFar06 = "";
    }
    
    float time06 = ofGetElapsedTimeMillis() - nextWordTime06;
    
    if(time06 > wordTime)
    {
        if(transparency06 == 255)
        {
            strSoFar06 = strSoFar06 + " " + stanzas[randomStanzaIndex06][wordIndex06];
            
            wholeLine06 = wholeLine06 + " " + stanzas[randomStanzaIndex06][wordIndex06];
            
            cout << wholeLine06 << endl;
            
        }
        if(wordIndex06 > stanzas[randomStanzaIndex06].size()-2)
        {
            transparency06-=2;
            
            if(transparency06 < 0)
            {
                wordIndex06 = 0;
                randomStanzaIndex06 = (int)ofRandom(0, stanzas.size());
                wholeLine06 = "";
                strSoFar06 = "";
                transparency06 = 255;
            }
            
        } else {
            wordIndex06++;
            nextWordTime06 = ofGetElapsedTimeMillis();
        }
    }
    ofSetColor(255, 255, 255, transparency06);
    font.drawString(wholeLine06, stanzaX06, stanzaY06);
    
    
    // 07 ----- 07 ----- 07 ----- 07 ----- 07 ----- 07 ----- 07
    
    if(font.stringWidth(strSoFar07) + font.stringWidth(stanzas[randomStanzaIndex07][wordIndex07]) - 20 > maxStanzaWidth)
    {
        wholeLine07 += "\n";
        strSoFar07 = "";
    }
    
    float time07 = ofGetElapsedTimeMillis() - nextWordTime07;
    
    if(time07 > wordTime)
    {
        if(transparency07 == 255)
        {
            strSoFar07 = strSoFar07 + " " + stanzas[randomStanzaIndex07][wordIndex07];
            
            wholeLine07 = wholeLine07 + " " + stanzas[randomStanzaIndex07][wordIndex07];
            
            cout << wholeLine07 << endl;
        }
        if(wordIndex07 > stanzas[randomStanzaIndex07].size()-2)
        {
            transparency07-=2;
            
            if(transparency07 < 0)
            {
                wordIndex07 = 0;
                randomStanzaIndex07 = (int)ofRandom(0, stanzas.size());
                wholeLine07 = "";
                strSoFar07 = "";
                transparency07 = 255;
            }
            
        } else {
            wordIndex07++;
            nextWordTime07 = ofGetElapsedTimeMillis();
        }
    }
    ofSetColor(255, 255, 255, transparency07);
    font.drawString(wholeLine07, stanzaX07, stanzaY07);
    
    
    // 08 ----- 08 ----- 08 ----- 08 ----- 08 ----- 08 ----- 08
    
    if(font.stringWidth(strSoFar08) + font.stringWidth(stanzas[randomStanzaIndex08][wordIndex08]) - 20 > maxStanzaWidth)
    {
        wholeLine08 += "\n";
        strSoFar08 = "";
    }
    
    float time08 = ofGetElapsedTimeMillis() - nextWordTime08;
    
    if(time08 > wordTime)
    {
        if(transparency08 == 255)
        {
            strSoFar08 = strSoFar08 + " " + stanzas[randomStanzaIndex08][wordIndex08];
            
            wholeLine08 = wholeLine08 + " " + stanzas[randomStanzaIndex08][wordIndex08];
            
            cout << wholeLine08 << endl;
            
        }
        if(wordIndex08 > stanzas[randomStanzaIndex08].size()-2)
        {
            transparency08-=2;
            
            if(transparency08 < 0)
            {
                wordIndex08 = 0;
                randomStanzaIndex08 = (int)ofRandom(0, stanzas.size());
                wholeLine08 = "";
                strSoFar08 = "";
                transparency08 = 255;
            }
            
        } else {
            wordIndex08++;
            nextWordTime08 = ofGetElapsedTimeMillis();
        }
    }
    ofSetColor(255, 255, 255, transparency08);
    font.drawString(wholeLine08, stanzaX08, stanzaY08);
    
    
    // 09 ----- 09 ----- 09 ----- 09 ----- 09 ----- 09 ----- 09
    
    if(font.stringWidth(strSoFar09) + font.stringWidth(stanzas[randomStanzaIndex09][wordIndex09]) - 20 > maxStanzaWidth)
    {
        wholeLine09 += "\n";
        strSoFar09 = "";
    }
    
    float time09 = ofGetElapsedTimeMillis() - nextWordTime09;
    
    if(time09 > wordTime)
    {
        if(transparency09 == 255)
        {
            strSoFar09 = strSoFar09 + " " + stanzas[randomStanzaIndex09][wordIndex09];
            
            wholeLine09 = wholeLine09 + " " + stanzas[randomStanzaIndex09][wordIndex09];
            
            cout << wholeLine09 << endl;
            
        }
        if(wordIndex09 > stanzas[randomStanzaIndex09].size()-2)
        {
            transparency09-=2;
            
            if(transparency09 < 0)
            {
                wordIndex09 = 0;
                randomStanzaIndex09 = (int)ofRandom(0, stanzas.size());
                wholeLine09 = "";
                strSoFar09 = "";
                transparency09 = 255;
            }
            
        } else {
            wordIndex09++;
            nextWordTime09 = ofGetElapsedTimeMillis();
        }
    }
    ofSetColor(255, 255, 255, transparency09);
    font.drawString(wholeLine09, stanzaX09, stanzaY09);
    
    
    // 10 ----- 10 ----- 10 ----- 10 ----- 10 ----- 10 ----- 10
    
    if(font.stringWidth(strSoFar10) + font.stringWidth(stanzas[randomStanzaIndex10][wordIndex10]) - 20 > maxStanzaWidth)
    {
        wholeLine10 += "\n";
        strSoFar10 = "";
    }
    
    float time10 = ofGetElapsedTimeMillis() - nextWordTime10;
    
    if(time10 > wordTime)
    {
        if(transparency10 == 255)
        {
            strSoFar10 = strSoFar10 + " " + stanzas[randomStanzaIndex10][wordIndex10];
            
            wholeLine10 = wholeLine10 + " " + stanzas[randomStanzaIndex10][wordIndex10];
            
            cout << wholeLine10 << endl;
            
        }
        if(wordIndex10 > stanzas[randomStanzaIndex10].size()-2)
        {
            transparency10-=2;
            
            if(transparency10 < 0)
            {
                wordIndex10 = 0;
                randomStanzaIndex10 = (int)ofRandom(0, stanzas.size());
                wholeLine10 = "";
                strSoFar10 = "";
                transparency10 = 255;
            }
            
        } else {
            wordIndex10++;
            nextWordTime10 = ofGetElapsedTimeMillis();
        }
    }
    ofSetColor(255, 255, 255, transparency10);
    font.drawString(wholeLine10, stanzaX10, stanzaY10);
    
    
    // 11 ----- 11 ----- 11 ----- 11 ----- 11 ----- 11 ----- 11
    
    if(font.stringWidth(strSoFar11) + font.stringWidth(stanzas[randomStanzaIndex11][wordIndex11]) - 20 > maxStanzaWidth)
    {
        wholeLine11 += "\n";
        strSoFar11 = "";
    }
    
    float time11 = ofGetElapsedTimeMillis() - nextWordTime11;
    
    if(time11 > wordTime)
    {
        if(transparency11 == 255)
        {
            strSoFar11 = strSoFar11 + " " + stanzas[randomStanzaIndex11][wordIndex11];
            
            wholeLine11 = wholeLine11 + " " + stanzas[randomStanzaIndex11][wordIndex11];
            
            cout << wholeLine11 << endl;
        }
        if(wordIndex11 > stanzas[randomStanzaIndex11].size()-2)
        {
            transparency11-=2;
            
            if(transparency11 < 0)
            {
                wordIndex11 = 0;
                randomStanzaIndex11 = (int)ofRandom(0, stanzas.size());
                wholeLine11 = "";
                strSoFar11 = "";
                transparency11 = 255;
            }
            
        } else {
            wordIndex11++;
            nextWordTime11 = ofGetElapsedTimeMillis();
        }
    }
    ofSetColor(255, 255, 255, transparency11);
    font.drawString(wholeLine11, stanzaX11, stanzaY11);
    
    
    // 12 ----- 12 ----- 12 ----- 12 ----- 12 ----- 12 ----- 12
    
    if(font.stringWidth(strSoFar12) + font.stringWidth(stanzas[randomStanzaIndex12][wordIndex12]) - 20 > maxStanzaWidth)
    {
        wholeLine12 += "\n";
        strSoFar12 = "";
    }
    
    float time12 = ofGetElapsedTimeMillis() - nextWordTime12;
    
    if(time12 > wordTime)
    {
        if(transparency12 == 255)
        {
            strSoFar12 = strSoFar12 + " " + stanzas[randomStanzaIndex12][wordIndex12];
            
            wholeLine12 = wholeLine12 + " " + stanzas[randomStanzaIndex12][wordIndex12];
            
            cout << wholeLine12 << endl;
        }
        if(wordIndex12 > stanzas[randomStanzaIndex12].size()-2)
        {
            transparency12-=2;
            
            if(transparency12 < 0)
            {
                wordIndex12 = 0;
                randomStanzaIndex12 = (int)ofRandom(0, stanzas.size());
                wholeLine12 = "";
                strSoFar12 = "";
                transparency12 = 255;
            }
            
        } else {
            wordIndex12++;
            nextWordTime12 = ofGetElapsedTimeMillis();
        }
    }
    ofSetColor(255, 255, 255, transparency12);
    font.drawString(wholeLine12, stanzaX12, stanzaY12);
    
    // 13 ----- 13 ----- 13 ----- 13 ----- 13 ----- 13 ----- 13
    
    if(font.stringWidth(strSoFar13) + font.stringWidth(stanzas[randomStanzaIndex13][wordIndex13]) - 20 > maxStanzaWidth)
    {
        wholeLine13 += "\n";
        strSoFar13 = "";
    }
    
    float time13 = ofGetElapsedTimeMillis() - nextWordTime13;
    
    if(time13 > wordTime)
    {
        if(transparency13 == 255)
        {
            strSoFar13 = strSoFar13 + " " + stanzas[randomStanzaIndex13][wordIndex13];
            
            wholeLine13 = wholeLine13 + " " + stanzas[randomStanzaIndex13][wordIndex13];
            cout << wholeLine13 << endl;
        }
        if(wordIndex13 > stanzas[randomStanzaIndex13].size()-2)
        {
            transparency13-=2;
            
            if(transparency13 < 0)
            {
                wordIndex13 = 0;
                randomStanzaIndex13 = (int)ofRandom(0, stanzas.size());
                wholeLine13 = "";
                strSoFar13 = "";
                transparency13 = 255;
            }
            
        } else {
            wordIndex13++;
            nextWordTime13 = ofGetElapsedTimeMillis();
        }
    }
    ofSetColor(255, 255, 255, transparency13);
    font.drawString(wholeLine13, stanzaX13, stanzaY13);
    
    
    // 14 ----- 14 ----- 14 ----- 14 ----- 14 ----- 14 ----- 14
    
    if(font.stringWidth(strSoFar14) + font.stringWidth(stanzas[randomStanzaIndex14][wordIndex14]) - 20 > maxStanzaWidth)
    {
        wholeLine14 += "\n";
        strSoFar14 = "";
    }
    
    float time14 = ofGetElapsedTimeMillis() - nextWordTime14;
    
    if(time14 > wordTime)
    {
        if(transparency14 == 255)
        {
            strSoFar14 = strSoFar14 + " " + stanzas[randomStanzaIndex14][wordIndex14];
            
            wholeLine14 = wholeLine14 + " " + stanzas[randomStanzaIndex14][wordIndex14];
            cout << wholeLine14 << endl;
        }
        if(wordIndex14 > stanzas[randomStanzaIndex14].size()-2)
        {
            transparency14-=2;
            
            if(transparency14 < 0)
            {
                wordIndex14 = 0;
                randomStanzaIndex14 = (int)ofRandom(0, stanzas.size());
                wholeLine14 = "";
                strSoFar14 = "";
                transparency14 = 255;
            }
            
        } else {
            wordIndex14++;
            nextWordTime14 = ofGetElapsedTimeMillis();
        }
    }
    ofSetColor(255, 255, 255, transparency14);
    font.drawString(wholeLine14, stanzaX14, stanzaY14);
    
    
    // 15 ----- 15 ----- 15 ----- 15 ----- 15 ----- 15 ----- 15
    
    if(font.stringWidth(strSoFar15) + font.stringWidth(stanzas[randomStanzaIndex15][wordIndex15]) - 20 > maxStanzaWidth)
    {
        wholeLine15 += "\n";
        strSoFar15 = "";
    }
    
    float time15 = ofGetElapsedTimeMillis() - nextWordTime15;
    
    if(time15 > wordTime)
    {
        if(transparency15 == 255)
        {
            strSoFar15 = strSoFar15 + " " + stanzas[randomStanzaIndex15][wordIndex15];
            
            wholeLine15 = wholeLine15 + " " + stanzas[randomStanzaIndex15][wordIndex15];
            cout << wholeLine15 << endl;
        }
        if(wordIndex15 > stanzas[randomStanzaIndex15].size()-2)
        {
            transparency15-=2;
            
            if(transparency15 < 0)
            {
                wordIndex15 = 0;
                randomStanzaIndex15 = (int)ofRandom(0, stanzas.size());
                wholeLine15 = "";
                strSoFar15 = "";
                transparency15 = 255;
            }
            
        } else {
            wordIndex15++;
            nextWordTime15 = ofGetElapsedTimeMillis();
        }
    }
    ofSetColor(255, 255, 255, transparency15);
    font.drawString(wholeLine15, stanzaX15, stanzaY15);
    
    
    // 16 ----- 16 ----- 16 ----- 16 ----- 16 ----- 16 ----- 16
    
    if(font.stringWidth(strSoFar16) + font.stringWidth(stanzas[randomStanzaIndex16][wordIndex16]) - 20 > maxStanzaWidth)
    {
        wholeLine16 += "\n";
        strSoFar16 = "";
    }
    
    float time16 = ofGetElapsedTimeMillis() - nextWordTime16;
    
    if(time16 > wordTime)
    {
        if(transparency16 == 255)
        {
            strSoFar16 = strSoFar16 + " " + stanzas[randomStanzaIndex16][wordIndex16];
            
            wholeLine16 = wholeLine16 + " " + stanzas[randomStanzaIndex16][wordIndex16];
            cout << wholeLine16 << endl;
        }
        if(wordIndex16 > stanzas[randomStanzaIndex16].size()-2)
        {
            transparency16-=2;
            
            if(transparency16 < 0)
            {
                wordIndex16 = 0;
                randomStanzaIndex16 = (int)ofRandom(0, stanzas.size());
                wholeLine16 = "";
                strSoFar16 = "";
                transparency16 = 255;
            }
            
        } else {
            wordIndex16++;
            nextWordTime16 = ofGetElapsedTimeMillis();
        }
    }
    ofSetColor(255, 255, 255, transparency16);
    font.drawString(wholeLine16, stanzaX16, stanzaY16);
    
    
    // 17 ----- 17 ----- 17 ----- 17 ----- 17 ----- 17 ----- 17
    
    if(font.stringWidth(strSoFar17) + font.stringWidth(stanzas[randomStanzaIndex17][wordIndex17]) - 20 > maxStanzaWidth)
    {
        wholeLine17 += "\n";
        strSoFar17 = "";
    }
    
    float time17 = ofGetElapsedTimeMillis() - nextWordTime17;
    
    if(time17 > wordTime)
    {
        if(transparency17 == 255)
        {
            strSoFar17 = strSoFar17 + " " + stanzas[randomStanzaIndex17][wordIndex17];
            
            wholeLine17 = wholeLine17 + " " + stanzas[randomStanzaIndex17][wordIndex17];
            cout << wholeLine17 << endl;
        }
        if(wordIndex17 > stanzas[randomStanzaIndex17].size()-2)
        {
            transparency17-=2;
            
            if(transparency17 < 0)
            {
                wordIndex17 = 0;
                randomStanzaIndex17 = (int)ofRandom(0, stanzas.size());
                wholeLine17 = "";
                strSoFar17 = "";
                transparency17 = 255;
            }
            
        } else {
            wordIndex17++;
            nextWordTime17 = ofGetElapsedTimeMillis();
        }
    }
    ofSetColor(255, 255, 255, transparency17);
    font.drawString(wholeLine17, stanzaX17, stanzaY17);
    
    // 18 ----- 18 ----- 18 ----- 18 ----- 18 ----- 18 ----- 18
    
    if(font.stringWidth(strSoFar18) + font.stringWidth(stanzas[randomStanzaIndex18][wordIndex18]) - 20 > maxStanzaWidth)
    {
        wholeLine18 += "\n";
        strSoFar18 = "";
    }
    
    float time18 = ofGetElapsedTimeMillis() - nextWordTime18;
    
    if(time18 > wordTime)
    {
        if(transparency18 == 255)
        {
            strSoFar18 = strSoFar18 + " " + stanzas[randomStanzaIndex18][wordIndex18];
            
            wholeLine18 = wholeLine18 + " " + stanzas[randomStanzaIndex18][wordIndex18];
            cout << wholeLine18 << endl;
        }
        if(wordIndex18 > stanzas[randomStanzaIndex18].size()-2)
        {
            transparency18-=2;
            
            if(transparency18 < 0)
            {
                wordIndex18 = 0;
                randomStanzaIndex18 = (int)ofRandom(0, stanzas.size());
                wholeLine18 = "";
                strSoFar18 = "";
                transparency18 = 255;
            }
            
        } else {
            wordIndex18++;
            nextWordTime18 = ofGetElapsedTimeMillis();
        }
    }
    ofSetColor(255, 255, 255, transparency18);
    font.drawString(wholeLine18, stanzaX18, stanzaY18);
    
    // 19 ----- 19 ----- 19 ----- 19 ----- 19 ----- 19 ----- 19
    
    if(font.stringWidth(strSoFar19) + font.stringWidth(stanzas[randomStanzaIndex19][wordIndex19]) - 20 > maxStanzaWidth)
    {
        wholeLine19 += "\n";
        strSoFar19 = "";
    }
    
    float time19 = ofGetElapsedTimeMillis() - nextWordTime19;
    
    if(time19 > wordTime)
    {
        if(transparency19 == 255)
        {
            strSoFar19 = strSoFar19 + " " + stanzas[randomStanzaIndex19][wordIndex19];
            
            wholeLine19 = wholeLine19 + " " + stanzas[randomStanzaIndex19][wordIndex19];
            cout << wholeLine19 << endl;
        }
        if(wordIndex19 > stanzas[randomStanzaIndex19].size()-2)
        {
            transparency19-=2;
            
            if(transparency19 < 0)
            {
                wordIndex19 = 0;
                randomStanzaIndex19 = (int)ofRandom(0, stanzas.size());
                wholeLine19 = "";
                strSoFar19 = "";
                transparency19 = 255;
            }
            
        } else {
            wordIndex19++;
            nextWordTime19 = ofGetElapsedTimeMillis();
        }
    }
    ofSetColor(255, 255, 255, transparency19);
    font.drawString(wholeLine19, stanzaX19, stanzaY19);
    
    // 20 ----- 20 ----- 20 ----- 20 ----- 20 ----- 20 ----- 20
    
    if(font.stringWidth(strSoFar20) + font.stringWidth(stanzas[randomStanzaIndex20][wordIndex20]) - 20 > maxStanzaWidth)
    {
        wholeLine20 += "\n";
        strSoFar20 = "";
    }
    
    float time20 = ofGetElapsedTimeMillis() - nextWordTime20;
    
    if(time20 > wordTime)
    {
        if(transparency20 == 255)
        {
            strSoFar20 = strSoFar20 + " " + stanzas[randomStanzaIndex20][wordIndex20];
            
            wholeLine20 = wholeLine20 + " " + stanzas[randomStanzaIndex20][wordIndex20];
            cout << wholeLine20 << endl;
        }
        if(wordIndex20 > stanzas[randomStanzaIndex20].size()-2)
        {
            transparency20-=2;
            
            if(transparency20 < 0)
            {
                wordIndex20 = 0;
                randomStanzaIndex20 = (int)ofRandom(0, stanzas.size());
                wholeLine20 = "";
                strSoFar20 = "";
                transparency20 = 255;
            }
            
        } else {
            wordIndex20++;
            nextWordTime20 = ofGetElapsedTimeMillis();
        }
    }
    ofSetColor(255, 255, 255, transparency20);
    font.drawString(wholeLine20, stanzaX20, stanzaY20);
    
    // 21 ----- 21 ----- 21 ----- 21 ----- 21 ----- 21 ----- 21
    
    if(font.stringWidth(strSoFar21) + font.stringWidth(stanzas[randomStanzaIndex21][wordIndex21]) - 20 > maxStanzaWidth)
    {
        wholeLine21 += "\n";
        strSoFar21 = "";
    }
    
    float time21 = ofGetElapsedTimeMillis() - nextWordTime21;
    
    if(time21 > wordTime)
    {
        if(transparency21 == 255)
        {
            strSoFar21 = strSoFar21 + " " + stanzas[randomStanzaIndex21][wordIndex21];
            
            wholeLine21 = wholeLine21 + " " + stanzas[randomStanzaIndex21][wordIndex21];
            cout << wholeLine21 << endl;
        }
        if(wordIndex21 > stanzas[randomStanzaIndex21].size()-2)
        {
            transparency21-=2;
            
            if(transparency21 < 0)
            {
                wordIndex21 = 0;
                randomStanzaIndex21 = (int)ofRandom(0, stanzas.size());
                wholeLine21 = "";
                strSoFar21 = "";
                transparency21 = 255;
            }
            
        } else {
            wordIndex21++;
            nextWordTime21 = ofGetElapsedTimeMillis();
        }
    }
    ofSetColor(255, 255, 255, transparency21);
    font.drawString(wholeLine21, stanzaX21, stanzaY21);
    
    // 22 ----- 22 ----- 22 ----- 22 ----- 22 ----- 22 ----- 22
    
    if(font.stringWidth(strSoFar22) + font.stringWidth(stanzas[randomStanzaIndex22][wordIndex22]) - 20 > maxStanzaWidth)
    {
        wholeLine22 += "\n";
        strSoFar22 = "";
    }
    
    float time22 = ofGetElapsedTimeMillis() - nextWordTime22;
    
    if(time22 > wordTime)
    {
        if(transparency22 == 255)
        {
            strSoFar22 = strSoFar22 + " " + stanzas[randomStanzaIndex22][wordIndex22];
            
            wholeLine22 = wholeLine22 + " " + stanzas[randomStanzaIndex22][wordIndex22];
            cout << wholeLine22 << endl;
        }
        if(wordIndex22 > stanzas[randomStanzaIndex22].size()-2)
        {
            transparency22-=2;
            
            if(transparency22 < 0)
            {
                wordIndex22 = 0;
                randomStanzaIndex22 = (int)ofRandom(0, stanzas.size());
                wholeLine22 = "";
                strSoFar22 = "";
                transparency22 = 255;
            }
            
        } else {
            wordIndex22++;
            nextWordTime22 = ofGetElapsedTimeMillis();
        }
    }
    ofSetColor(255, 255, 255, transparency22);
    font.drawString(wholeLine22, stanzaX22, stanzaY22);
    
    // 23 ----- 23 ----- 23 ----- 23 ----- 23 ----- 23 ----- 23
    
    if(font.stringWidth(strSoFar23) + font.stringWidth(stanzas[randomStanzaIndex23][wordIndex23]) - 20 > maxStanzaWidth)
    {
        wholeLine23 += "\n";
        strSoFar23 = "";
    }
    
    float time23 = ofGetElapsedTimeMillis() - nextWordTime23;
    
    if(time23 > wordTime)
    {
        if(transparency23 == 255)
        {
            strSoFar23 = strSoFar23 + " " + stanzas[randomStanzaIndex23][wordIndex23];
            
            wholeLine23 = wholeLine23 + " " + stanzas[randomStanzaIndex23][wordIndex23];
            cout << wholeLine23 << endl;
        }
        if(wordIndex23 > stanzas[randomStanzaIndex23].size()-2)
        {
            transparency23-=2;
            
            if(transparency23 < 0)
            {
                wordIndex23 = 0;
                randomStanzaIndex23 = (int)ofRandom(0, stanzas.size());
                wholeLine23 = "";
                strSoFar23 = "";
                transparency23 = 255;
            }
            
        } else {
            wordIndex23++;
            nextWordTime23 = ofGetElapsedTimeMillis();
        }
    }
    ofSetColor(255, 255, 255, transparency23);
    font.drawString(wholeLine23, stanzaX23, stanzaY23);
    
    
    
}

