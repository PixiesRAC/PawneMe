#include <sstream>
#include <fstream>
#include "mapGenerator.hh"

#include <iostream>

mapGenerator::mapGenerator(std::string const &pathMap, std::string const &pathKey, std::string const &pathIV) : _pathMap(pathMap), _pathKey(pathKey), _pathIV(pathIV) 
{
  std::cout << this->_pathMap << " " << this->_pathKey << " " << this->_pathIV << std::endl;
} 

mapGenerator::~mapGenerator() {}


std::string       mapGenerator::getFromFile(std::string const fileName)
{
  std::string     line = "";
  std::string     res = "";
  std::ifstream   file(fileName);
 
  if (file.fail())
    {
      // throw exeption
      std::cerr << "Fail open " << fileName << std::endl;
    }
  while (std::getline(file, line))
    {
      res = res + line;
    }
  std::cout << "res : {" << res << "}" << std::endl;
  return (res);
}

std::string       mapGenerator::decrypt()
{
  this->_cMap = this->getFromFile(this->_pathMap);
  this->_cKey = this->getFromFile(this->_pathKey);
  this->_cIV = this->getFromFile(this->_pathIV);
  return ("LOL");
}


int              main(int ac, char **av)
{
  mapGenerator   *test = new mapGenerator(av[1], av[2], av[3]);
  
  test->decrypt();
  return (1);
}
