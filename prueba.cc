// erasing from list
#include <iostream>
#include <list>
#include <string>
using namespace std;
// Example program

int main()
{
  
  string s = "Desktop/prog";
  cout << s << endl;
  /*int posini = s.find ('/');
  int posfin = s.rfind ('/');
  if (s [0] != '/') cout << "puto genio\n";
  cout << posini << endl << posfin <<endl;
  //s.erase((s.rfind ('/')), (s.end()));
  int last = s.length();
  cout << "hey "<< last  <<endl;
  s.erase (posfin,last);
  cout << "string: "<<s<<endl;
  if (s [0] != '/') cout << "puto genio\n";

  cout << s << endl;
  string path = "/path";
  s += path;
  cout << s<<endl;
  s.erase(0,1);
  cout << s<< endl;
  int pos = s.find('/');
  cout << pos << "  ";
  string dir = s.substr(0, pos);
  cout << "substraido: "<<dir << "    " << s<< endl;
  s.erase(0,pos+1);
  cout << s << endl;
   pos = s.find('/');
  cout << pos << "  ";
*/
  s+= '/';
  string dir="dirdada";
  s+= dir;
  cout << s << endl;
  return 0;
}


/*
int main ()
{
  std::list<int> mylist;
  std::list<int>::iterator it1,it2;

  // set some values:
  for (int i=1; i<10; ++i) mylist.push_back(i*10);

  
  std::cout << "before erase, mylist contains:";
  for (it1=mylist.begin(); it1!=mylist.end(); ++it1)
    std::cout << ' ' << *it1;
  std::cout << '\n';

  
  std::cout << "let's erase: "<<std::endl;

 // for (it1=mylist.begin(); it1!=mylist.end(); it1=mylist.erase (it1)) ;
  mylist.erase (next(mylist.begin()), mylist.end());
  std::cout << "erase ended: "<<std::endl;
  std::cout << "after erase, mylist contains:";
  for (it1=mylist.begin(); it1!=mylist.end(); ++it1)
    std::cout << ' ' << *it1;
  std::cout << '\n';

  return 0;
}*/