#include "print_score.h"

namespace printer
{
    ScorePrinter::ScorePrinter(AdafruitThermal * printer, BufferedSerial * pi) {
        this->printer = printer;
        this->pi = pi;
        this->serial_file = fdopen(pi,"r+");

        printer->begin();
        ThisThread::sleep_for(chrono::milliseconds(200));
        printer->setDefault();
        ThisThread::sleep_for(chrono::milliseconds(200));
    }
    
    void ScorePrinter::print_characters(void){
        int buffer_length = sizeof(this->buffer)/sizeof(this->buffer[0]);
        char input = 0;
        int index = 0;
        while(true){
            input = getc(this->serial_file);
            if (input == '\n'){
                break;
            }
            this->buffer[index] = input;
            index++;
        }
        // index = 0;
        for (int i = index+1; i < buffer_length ; i++){
            this->buffer[i] = 0;
        }
        index = 0;
        printf("***%s***", this->buffer);
        char * OutputText = this->buffer;               
        printer->print(OutputText);
        this->clear_buffer();
    }

    void ScorePrinter::clear_buffer(void){
        
        int buffer_length = sizeof(this->buffer)/sizeof(this->buffer[0]);
        for (int i = 0; i < buffer_length ; i++){
            this->buffer[i] = 0;
        }
    }
};
