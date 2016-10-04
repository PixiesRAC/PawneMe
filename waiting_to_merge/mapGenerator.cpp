#include <sstream>
#include <fstream>
#include "mapGenerator.hh"

#include <iostream>

mapGenerator::mapGenerator(std::string const &pathMap, std::string const &pathKey, std::string const &pathIV) : _pathMap(pathMap), _pathKey(pathKey), _pathIV(pathIV) 
{
  std::cout << this->_pathMap << " " << this->_pathKey << " " << this->_pathIV << std::endl;
} 

mapGenerator::~mapGenerator() {}


std::string       mapGenerator::getFromFile()
{
  std::string     line = "";
  std::string     res = "";
  int             a = 0;
  int             b = 0;

  std::ifstream infile(this->_pathMap);
  while (std::getline(infile, line))
    {
      std::istringstream iss(line);
      if (!(iss >> a >> b)) 
	{ 
	  break ;
	  /**
	   * \Throw exception
	   *
	   */
	}
      std::cout << line << std::endl;
      res = res + line;
    }
  std::cout << "res : {" << res << "}" << std::endl;
  return (res);
}

std::string       mapGenerator::decrypt()
{
  this->getFromFile();
  return ("LOL");
}


int              main(int ac, char **av)
{
  mapGenerator   *test = new mapGenerator(av[1], "w", "e");
  
  test->decrypt();
  return (1);
}
