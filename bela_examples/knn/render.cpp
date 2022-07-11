// Based on https://github.com/mzed/ofxRapidLib/tree/main/example-objectClassification

#include <Bela.h>
#include "rapidLib.h"

std::vector<rapidLib::trainingExample> myData;
std::vector<double> trainingInput;
std::vector<double> trainingOutput;
std::vector<double> inputVec;

rapidLib::classification myKnn;
rapidLib::trainingExample tempExample;

int examples = 10;
int recordingState = 2;
int result;

bool setup(BelaContext *context, void *userData)
{
    tempExample.input = { 0.5, 0.3, 0.4 };
    tempExample.output = { double(1) };
    myData.push_back(tempExample);

    tempExample.input = { 1.6, 1.7, 1.8 };
    tempExample.output = { double(2) };
    myData.push_back(tempExample);

    tempExample.input = { 2.3, 2.4, 2.5 };
    tempExample.output = { double(3) };
    myData.push_back(tempExample);
    
    if (myData.size() > 0)
        myKnn.train(myData);
    
    inputVec = { 0.34, 0.45, 0.54 };
    result = myKnn.run(inputVec)[0];
    rt_printf("Input: { %2f, %2f, %2f }\n", inputVec[0], inputVec[1], inputVec[2]);
    rt_printf("Output: %i\n", result);

    inputVec = { 1.34, 1.45, 1.54 };
    result = myKnn.run(inputVec)[0];
    rt_printf("Input: { %2f, %2f, %2f }\n", inputVec[0], inputVec[1], inputVec[2]);
    rt_printf("Output: %i\n", result);

    inputVec = { 2.34, 2.45, 2.54 };
    result = myKnn.run(inputVec)[0];
    rt_printf("Input: { %2f, %2f, %2f }\n", inputVec[0], inputVec[1], inputVec[2]);
    rt_printf("Output: %i\n", result);

	return true;
}
void render(BelaContext *context, void *userData){}
void cleanup(BelaContext *context, void *userData){}