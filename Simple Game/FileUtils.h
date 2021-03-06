#pragma once

#include <iostream>
#include <fstream>

namespace engine {
	
	class FileUtils {
	public:
		static std::string read_file(const char* filePath) {
			FILE* file = fopen(filePath, "rt");

			if (file == NULL) {
				std::cout << "File " << filePath << " does not exist!" << std::endl;
#ifdef DEBUG
				system("PAUSE");
#endif // DEBUG

				return std::string();
			}

			fseek(file, 0, SEEK_END);
			unsigned long length = ftell(file);
			char* data = new char[length + 1];

			memset(data, 0, length + 1);
			fseek(file, 0, SEEK_SET);

			fread(data, 1, length, file);
			fclose(file);

			std::string result(data);

			delete[] data;
			return result;
		}
	};
}
