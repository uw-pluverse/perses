#version 330
void MyFunction(in float inputValue, out int outputValue, inout float inAndOutValue)
{
    inputValue = 0.0;
    outputValue = int(inAndOutValue + inputValue);
    inAndOutValue = 3.0;

}

void main()
{
    float in1 = 10.5;
    int out1 = 5;
    float out2 = 10.0;
    MyFunction(in1, out1, out2);
}