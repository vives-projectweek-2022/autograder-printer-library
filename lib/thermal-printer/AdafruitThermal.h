/*************************************************** 
  This is a library for the Adafruit Thermal Printer
  
  Pick one up at --> http://www.adafruit.com/products/597
  These printers use TTL serial to communicate, 2 pins are required

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  MIT license, all text above must be included in any redistribution
 ****************************************************/

// Ported to mbed by Ashley Mills
// Documentation by Andrew Ross - NOTE: printBitmap not ported, nothing tested 

#pragma once

#include "mbed.h"

#define UPC_A 0
#define UPC_E 1
#define EAN13 2
#define EAN8  3
#define CODE39 4
#define I25   5
#define CODEBAR 6
#define CODE93 7
#define CODE128 8
#define CODE11  9
#define MSI 10

#define delay(a) ThisThread::sleep_for(a/1000)

//**************************************************************************
// \class AdafruitThermal AdafruitThermal.h
// \brief This is the main class. It should be used like this : AdafruitThermal printer(p9,p10);
/**
Example:
* @code
* // Print a char array onto the thermal paper
* #include "mbed.h"
* #include "AdafruitThermal.h"
*
* AdafruitThermal printer(p9,p10);
*
* int main() {
*     printer.begin();
*     char *Text_Out = "Hello World!\n";
*     printer.print(Text_Out);
* }
* @endcode
*/

class AdafruitThermal {
  public:

  AdafruitThermal(PinName RX_Pin, PinName TX_Pin);  // constructor
    void begin(int heatTime=255);
    void reset();
    
    // General Commands *******************************************************************************
    
    /** Sets Default settings on printer*/
    void setDefault();
    void test();
    void testPage();

    /** Basic function for all printing. Prints character to stream
    * @param char to print (see AdafruitThermal.h)
    */
    size_t write(uint8_t c);
    
    void normal();
    
    /** Inverses the printer color space*/
    void inverseOn();
    
    /** Turns off inverse*/
    void inverseOff();
    void upsideDownOn();
    void upsideDownOff();
    void doubleHeightOn();
    void doubleHeightOff();
    void doubleWidthOn();
    void doubleWidthOff();
    void boldOn();
    void boldOff();
    void underlineOn(uint8_t weight=1);
    void underlineOff();
    void strikeOn();
    void strikeOff();

    /** Allows you to left, right or center justify your text
    * @param string containing L, R, or C for alignment
    */
    void justify(char value);
    void feed(uint8_t x = 1);
    void feedRows(uint8_t);
    void flush();
    void online();
    void offline();
    void sleep();
    void sleepAfter(uint8_t seconds);
    void wake();
    
    /** Main function to print information
    * @param array of chars which is parsed by the write function
    */
    void print(char *string);

    void setCharSpacing(int spacing);
    void setSize(char value);
    void setLineHeight(int val = 32);

    void printBarcode(char * text, uint8_t type);
    void setBarcodeHeight(int val);

    // not ported
    //void printBitmap(int w, int h, const uint8_t *bitmap);
    //void printBitmap(int w, int h, Stream *stream);
    //void printBitmap(Stream *stream);

    // ??
    void tab();

  protected:
    BufferedSerial * _printer;
    bool linefeedneeded;

    // little helpers to make code easier to read&use
    void writeBytes(uint8_t a);
    void writeBytes(uint8_t a, uint8_t b);
    void writeBytes(uint8_t a, uint8_t b, uint8_t c);
    void writeBytes(uint8_t a, uint8_t b, uint8_t c, uint8_t d);

    int printMode;
    void writePrintMode();
    void setPrintMode(uint8_t mask);
    void unsetPrintMode(uint8_t mask);

    PinName _RX_Pin;
    PinName _TX_Pin;

  private:
    void printer_writer(uint8_t a);
};
