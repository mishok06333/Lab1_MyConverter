#include <iostream>
#include <string>
#include <Windows.h>


int main(int argc, char* argv[]) {

    //dll import
	HINSTANCE load;
	load = LoadLibrary(L"MyConverter.dll");
	typedef double (*convert) (double, std::string, std::string);
	convert Convert;
	Convert = (convert)GetProcAddress(load, "convert");

    double num;
    std::string origin_unit, res_unit;
    int args_count = 0;

    size_t i;
    for (i = 1; i < argc; ++i) {

        //processing key --help
        if ((!strcmp(argv[i], "--help"))) {
            std::cout << "This util convert value from one unit of measurement to another.\nRequired arguments:\n\"--value\" - float number.\n\"--origin-unit\" - unit of measurement of origin value.\n\"--result-unit\" - unit of measurement of resulting value.\nValid values for unit of measurements: \"meter\", \"inch\", \"km\", \"cm\", \"mile\", \"feet\".";
            FreeLibrary(load);
            exit(0);
        }

        //processing key --value
        if ((!strcmp(argv[i], "--value")) && (i + 1 < argc)) {
            num = std::stof(argv[i + 1]);
            args_count++;
        }

        //processing key --origin-unit
        if ((!strcmp(argv[i], "--origin-unit")) && (i + 1 < argc)) {
            origin_unit = argv[i + 1];
            args_count++;
        }

        //processing key --result-unit
        if ((!strcmp(argv[i], "--result-unit")) && (i + 1 < argc)) {
            res_unit = argv[i + 1];
            args_count++;
        }
    }

    if (args_count == 3) {

        //calling function from lib
        double res = Convert(num, origin_unit, res_unit);
        if (res == -0) {
            std::cout << "Incorrect values for arguments. Start with argument \"--help\" to see required arguments.";
        }
        else {
            std::cout << res;
        }
    }
    else {
        std::cout << "This util convert value from one unit of measurement to another.\nRequired arguments:\n\"--value\" - float number.\n\"--origin-unit\" - unit of measurement of origin value.\n\"--result-unit\" - unit of measurement of resulting value.\nValid values for unit of measurements: \"meter\", \"inch\", \"km\", \"cm\", \"mile\", \"feet\".";
    }
    FreeLibrary(load);
    return 0;
}