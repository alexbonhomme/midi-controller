#include <Control_Surface.h>

// Instantiate a hardware MIDI interface with Serial as its UART
HardwareSerialMIDI_Interface midi{Serial};

// If the jog wheels or other encoders are too slow in your software, increase
// this value.
// (It will be multiplied with the actual speed of the encoder, as the name
// implies.) Default is 1.
const int speedMultiplier = 5;

CCPotentiometer potentiometers[]{
    // potars
    {A0, MIDI_CC::General_Purpose_Controller_1},
    {A1, MIDI_CC::General_Purpose_Controller_2},
    {A2, MIDI_CC::General_Purpose_Controller_3},
    {A3, MIDI_CC::General_Purpose_Controller_4},

    // fader
    {A4, {MIDI_CC::Channel_Volume, Channel_1}},
};

CCRotaryEncoder encoders[]{
    {
        {4, 3},
        {MIDI_CC::Pan, Channel_1},
        speedMultiplier,
    },
    {
        {7, 6},
        {MIDI_CC::Pan, Channel_2},
        speedMultiplier,
    },
    {
        {10, 9},
        {MIDI_CC::Pan, Channel_3},
        speedMultiplier,
    },
    {
        {13, 12},
        {MIDI_CC::Pan, Channel_4},
        speedMultiplier,
    },
};

CCButtonLatching encoderSwitches[]{
    {
        2,
        MCU::MUTE_1,
    },
    {
        5,
        MCU::MUTE_2,
    },
    {
        8,
        MCU::MUTE_3,
    },
    {
        11,
        MCU::MUTE_4,
    },
};

void setup()
{
  Control_Surface.begin();
}

void loop()
{
  Control_Surface.loop();
}