// Task: Zipcode
// Tag: Class Operator
// Date: 02/09/2023

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
using namespace std;
class Letter
{
public:
   string name;
   string address;
   string province;
   string district;
   int zip;
   bool operator<(const Letter &other) const
   {
      //**Begin Insert**
      if (zip != other.zip) return zip < other.zip;
      if (address != other.address) return address < other.address;
      if (district != other.district) return district < other.district;
      if (province != other.province) return province < other.province;
      return name < other.name;
      //**End Insert**
   }
};
class ZipInfo
{
public:
   int zip;
   string province;
   string district;
};
void correctZipAndSortLetters(vector<ZipInfo> &zipinfo, vector<Letter> &letters)
{
   //**Begin Insert**
   map<string, int> zipmap;
   for (auto &z : zipinfo) zipmap[z.province + z.district] = z.zip;
   for (Letter &l : letters) {
      assert (zipmap.count(l.province + l.district) > 0);
      l.zip = zipmap[l.province + l.district];
   }
   sort(letters.begin(), letters.end());
   //**End Insert**
}
int main()
{
   int nzip;
   cin >> nzip;
   vector<ZipInfo> zipinfo;
   for (int i = 0; i < nzip; i++)
   {
      ZipInfo z;
      cin >> z.zip >> z.district >> z.province;
      zipinfo.push_back(z);
   }
   int n;
   cin >> n;
   vector<Letter> letters;
   for (int i = 0; i < n; i++)
   {
      Letter l;
      cin >> l.name >> l.address >> l.district >> l.province >> l.zip;
      letters.push_back(l);
   }
   correctZipAndSortLetters(zipinfo, letters);
   for (auto &l : letters)
   {
      cout << l.name << " " << l.address << " " << l.district << " " << l.province << " " << l.zip << endl;
   }
}