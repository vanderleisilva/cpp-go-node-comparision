#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono>

unsigned long long factorial(unsigned int n)
{
  if (n == 0 || n == 1)
  {
    return 1;
  }
  else
  {
    return n * factorial(n - 1);
  }
}

void createFileWithLines(int lines, const std::string &fileName)
{
  auto startTime = std::chrono::high_resolution_clock::now();

  std::ofstream file(fileName);

  if (file.is_open())
  {
    for (int i = 1; i <= lines; i++)
    {
      std::stringstream line;
      // line << "line " << i << std::endl;
      line << "factorial  of " << i << " is " << factorial(i) << std::endl;
      file << line.str();
    }

    file.close();

    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();

    std::cout << "File " << fileName << " created successfully with " << lines << " lines." << std::endl;
    std::cout << "Time taken: " << duration << " milliseconds" << std::endl;
  }
  else
  {
    std::cout << "Error creating file: " << fileName << std::endl;
  }
}

int main(int argc, char **argv)
{
  if (argc < 3)
  {
    std::cout << "Usage: ./program <lines> <fileName>" << std::endl;
    return 1;
  }

  int lines = std::stoi(argv[1]);
  std::string fileName = argv[2];
  createFileWithLines(lines, fileName);

  return 0;
}
