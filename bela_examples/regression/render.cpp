#include <Bela.h>
#include "rapidLib.h"

rapidLib::regression mtofRegression;
std::vector<rapidLib::trainingExample> myData;
rapidLib::trainingExample tempExample;
int inputMIDINote = 60;

bool setup(BelaContext *context, void *userData)
{
    tempExample.input = { 48 };
    tempExample.output = { 130.81 };
    myData.push_back(tempExample);
    
    tempExample.input = { 54 };
    tempExample.output = { 185.00 };
    myData.push_back(tempExample);
    
    tempExample.input = { 60 };
    tempExample.output = { 261.63 };
    myData.push_back(tempExample);
    
    tempExample.input = { 66 };
    tempExample.output = { 369.994 };
    myData.push_back(tempExample);
    
    tempExample.input = { 72 };
    tempExample.output = { 523.25 };
    myData.push_back(tempExample);
    
    mtofRegression.train(myData);
    
    std::vector<double> inputVec = { double(inputMIDINote) };
    double freqHz = mtofRegression.run(inputVec)[0];
    rt_printf("MIDI Note %i is %2fHz\n", inputMIDINote, freqHz);

	return true;
}
void render(BelaContext *context, void *userData){}
void cleanup(BelaContext *context, void *userData){}