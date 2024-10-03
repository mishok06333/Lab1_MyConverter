#include<string>

extern "C" __declspec(dllexport) double convert(double num, std::string a, std::string b) {
	if (a == "inch") {
		if (b == "cm") { return num * 2.54; }
		else if (b == "meter") { return num * 0.0254; }
		else if (b == "km") { return num * 0.000025; }
		else if (b == "feet") { return num * 0.083333; }
		else if (b == "mile") { return num * 0.000016; }
	}
	else if (a == "cm") {
		if (b == "inch") { return num * 0.393701; }
		else if (b == "meter") { return num * 0.01; }
		else if (b == "km") { return num * 0.00001; }
		else if (b == "feet") { return num * 0.032808; }
		else if (b == "mile") { return num * 0.000006; }
	}
	else if (a == "meter") {
		if (b == "inch") { return num * 39.37; }
		else if (b == "cm") { return num * 100; }
		else if (b == "km") { return num * 0.001; }
		else if (b == "feet") { return num * 3.28; }
		else if (b == "mile") { return num * 0.000621; }
	}
	else if (a == "km") {
		if (b == "inch") { return num * 39370.08; }
		else if (b == "cm") { return num * 100000; }
		else if (b == "meter") { return num * 1000; }
		else if (b == "feet") { return num * 3280.84; }
		else if (b == "mile") { return num * 0.621371; }
	}
	else if (a == "feet") {
		if (b == "inch") { return num * 12; }
		else if (b == "cm") { return num * 30.48; }
		else if (b == "meter") { return num * 0.3048; }
		else if (b == "km") { return num * 0.000305; }
		else if (b == "mile") { return num * 0.000189; }
	}
	else if (a == "mile") {
		if (b == "inch") { return num * 63360; }
		else if (b == "cm") { return num * 160934.4; }
		else if (b == "meter") { return num * 1609.34; }
		else if (b == "km") { return num * 1.61; }
		else if (b == "feet") { return num * 5280; }
	}
	else { return -0; };
	return 0;
}