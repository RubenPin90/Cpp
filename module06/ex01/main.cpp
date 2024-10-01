#include "Serializer.hpp"
#include "Data.hpp"

int main (int ac, char *av[]) {
	if (ac < 2 || ac > 4) {
		std::cerr << "False Usage: ./Serializer <Value> <Value2> <Value3>\n\n";
		return 1;
	}
	const char* str1 = (ac > 1) ? av[1] : "no data";
	const char* str2 = (ac > 2) ? av[2] : "no data";
	const char* str3 = (ac > 3) ? av[3] : "no data";
	std::cout << "Saving following data: " << str1 << ", " << str2 << ", " << str3 << std::endl;
	Data data((ac - 1), str1, str2, str3);
	uintptr_t serialized;
	Data* DataPtr;

	std::cout << "\nData saved under the following Address: " << &data << std::endl;
	serialized = Serializer::serialize(&data);
	std::cout << "Serialized Data: " << serialized << std::endl;
	DataPtr = Serializer::deserialize(serialized);
	std::cout << "Deserialized Data: " << DataPtr << std::endl;
	std::cout << "\n" << data;
	return 0;
}
