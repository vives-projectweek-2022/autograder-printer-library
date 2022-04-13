#include "mbed.h"
#include "../lib/thermal-printer/AdafruitThermal.h"
#include "../lib/print_score.h"
#include <string> 

using namespace std;
using namespace printer;
using printer::ScorePrinter;


AdafruitThermal thermal_printer(PA_10, PA_9);
BufferedSerial pi(USBTX, USBRX);



int main() {
        printer::ScorePrinter scorePrinter(&thermal_printer, &pi);

        while(true){

                scorePrinter.print_characters();
                scorePrinter.clear_buffer();                
        }
}