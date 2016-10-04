#ifndef MAPGENERATOR_HH_
# define MAPGENERATOR_HH_

# include <string>

class                 mapGenerator
{
private:
  std::string const   &_pathMap;
  std::string const   &_pathKey;
  std::string const   &_pathIV;

  std::string         _cMap;
  std::string         _cKey;
  std::string         _cIV;

  std::string    getFromFile();

public:
  mapGenerator(std::string const &pathMap, std::string const &pathKey, std::string const &pathIV);
  ~mapGenerator();

  std::string    decrypt();
  /** 
  ** \faire le return de map
  ** -
  */
};

#endif /* !MAPGENERATOR.hh */
