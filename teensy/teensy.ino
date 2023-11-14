#include <Control_Surface.h>

USBMIDI_Interface midi;

// TODO : MIDI Serial + USB version
// Instantiate a hardware MIDI interface with Serial as its UART
// HardwareSerialMIDI_Interface midi {Serial};

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
    {A4, MIDI_CC::General_Purpose_Controller_5},
    {A5, MIDI_CC::General_Purpose_Controller_6},
    {A6, MIDI_CC::General_Purpose_Controller_7},
    {A7, MIDI_CC::General_Purpose_Controller_8},

    // fader
    {A8, {MIDI_CC::Effect_Control_1, Channel_1}},
};

CCRotaryEncoder encoders[]{
    {
        {1, 0},
        {MIDI_CC::Pan, Channel_1},
        speedMultiplier,
    },
    {
        {3, 2},
        {MIDI_CC::Pan, Channel_2},
        speedMultiplier,
    },
    {
        {5, 4},
        {MIDI_CC::Pan, Channel_3},
        speedMultiplier,
    },
    {
        {7, 6},
        {MIDI_CC::Pan, Channel_4},
        speedMultiplier,
    },
};

CCButtonLatching encoderSwitches[]{
    {
        9,
        MCU::MUTE_1,
    },
    {
        10,
        MCU::MUTE_2,
    },
    {
        A9,
        MCU::MUTE_3,
    },
    {
        A10,
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
