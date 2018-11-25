#include "calcutils.h"
#include <map>
#include <string>
#include <vector>

/**
 * @author Anderson Grajales Alzate
 * @author Stiven Ramírez Arango
 * @version 22/11/2016
 */

using namespace std;

/**
 * Variables que se usa para las variables de ambiente,
 * prefijos y contador de líneas.
 */

map<string, int> vars;
vector<string> ass;
string PREFIX = "CALCVAR_";
string CALCP = ".calc";
int lc = 1;
