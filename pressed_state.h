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

struct SingleLayerPressedState
{
    SingleLayerPressedState()
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

struct MultiLayerPressedState
{
    MultiLayerPressedState()
    {}

    void init(const uint8_t *layoutTable, int8_t numLayers)
    {
        this->numLayers = numLayers;
        activeLayer = 0;
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
        uint16_t index=uint16_t(activeLayer)*countRows*countColumns*2;
        index+=row*2*countColumns+column;
        uint8_t scanCode=pgm_read_byte(&layoutTable[index]);

        // It is assumed that layer keys don't change positions in different layers!
        if (scanCode>=KEY_LAYER_MIN && scanCode<=KEY_LAYER_MAX)
        {
            // Switch the layer when the left/right layer switch button is released.
            if (!pressed && (scanCode==KEY_LAYER_SWITCH_LEFT || scanCode==KEY_LAYER_SWITCH_RIGHT))
            {
                activeLayer = (activeLayer + 1) % numLayers;

                for (int8_t &keyState : state)
                    keyState = 0;

                Keyboard.releaseAll();

                Serial.print(F("Switching to layer: "));
                Serial.print(activeLayer);
                Serial.println(F(" all state is reset"));

                hasChanges=true;
            }
            return;
        }

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

    int8_t getAcitveLayer() const { return activeLayer; }
private:
    int8_t state[keysTotalNumber];
    unsigned long changeTime[keysTotalNumber];
    unsigned long currentTime;
    const uint8_t *layoutTable;
    int8_t numLayers;
    int8_t activeLayer;
    bool hasChanges;
};


#endif // THEKBD_PRESSED_STATE_H__
