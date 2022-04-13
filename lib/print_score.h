# pragma once
#include "mbed.h"
#include "./thermal-printer/AdafruitThermal.h"
#include <string>

using namespace std;

namespace printer {
    class ScorePrinter{

        public:
            ScorePrinter(AdafruitThermal * printer, BufferedSerial * pi);
            void print_characters(void);
            void clear_buffer(void);

        private:
            AdafruitThermal * printer = nullptr;
            BufferedSerial * pi = nullptr;
            FILE* serial_file = nullptr;
            char buffer[20] = {};
    };

};
