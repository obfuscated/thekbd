#ifndef THEKBD_PRESSED_STATE_H__
#define THEKBD_PRESSED_STATE_H__

#include "libraries/common.h"


inline void print(bool released, int row, int column, int scanCode)
{
    Serial.print(released ? F("released: ") : F("pressed: "));
    Serial.print(column);
    Serial.print(F(" "));
    Serial.print(row);
    Serial.print(F(" scan code: "));
    Serial.println(scanCode);
}

struct PressedState
{
    PressedState()
    {}

    void init(const uint8_t *layoutTable)
    {
        currentTime = 0;
        this->layoutTable = layoutTable;
        hasChanges = false;

        memset(state, 0, sizeof(int8_t)*countof(state));
        memset(changeTime, 0, sizeof(unsigned long)*countof(state));
    }
    int8_t get(uint8_t row, uint8_t column) const { return state[row*2*countColumns+column]; }

    void setCurrentTime(unsigned long time) { currentTime=time; }

    void update(uint8_t row, uint8_t column, bool pressed)
    {
        const uint8_t index=row*2*countColumns+column;
        int8_t &currState=state[index];
        bool oldPressed=((currState&1)!=0);

        if (oldPressed==pressed)
        {
            bool changing=((currState&2)!=0);
            if (changing && timeDifference(currentTime, changeTime[index])>5)
            {
                currState=(pressed ? 1 : 0);
                stateChange(pressed, row, column);
            }
        }
        else
        {
            currState=(pressed ? 1 : 0)+2;
            changeTime[index]=currentTime;
        }
    }

    void stateChange(bool pressed, uint8_t row, uint8_t column)
    {
        uint8_t scanCode=pgm_read_byte(&layoutTable[row*2*countColumns+column]);
        print(!pressed, row, column, scanCode);
        if (scanCode>0)
        {
            if (pressed)
                Keyboard.press(scanCode);
            else
                Keyboard.release(scanCode);
            hasChanges=true;
        }
    }
    void sendReport()
    {
        if (hasChanges)
        {
            Keyboard.sendReport();
            hasChanges=false;
        }

    }
private:
    int8_t state[keysTotalNumber];
    unsigned long changeTime[keysTotalNumber];
    unsigned long currentTime;
    const uint8_t *layoutTable;
    bool hasChanges;
};


#endif // THEKBD_PRESSED_STATE_H__
