#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ruta.h"

using namespace std;

int main()
{
	Directorio raiz("");
	Ruta ruta(raiz);

	for (bool done=false; !done; )
	{
		string         line,arg;
		vector<string> cmd;

		cout << "~> " << flush;

		getline(cin,line);
		istringstream iss(line);
		while(getline(iss,arg,' ')) cmd.push_back(arg);

		if (cin.eof())
		{
			done = true;
			continue;
		}
		if (cmd.size()<1)
			continue;

		try
		{
			if (cmd[0]=="pwd")
			{
				cout << ruta.pwd() << endl;
			}
			if (cmd[0]=="ls")
			{
				ruta.ls();
			}
			if (cmd[0]=="cd")
			{
				ruta.cd(cmd.at(1));
			}
			if (cmd[0]=="stat")
			{
				if (cmd.size()>1)
					ruta.stat(cmd.at(1));
				else
					ruta.stat(".");
			}
			if (cmd[0]=="vim")
			{
				ruta.vim(cmd.at(1),atoi(cmd.at(2).c_str()));
			}
			if (cmd[0]=="mkdir")
			{
				ruta.mkdir(cmd.at(1));
			}
			if (cmd[0]=="ln")
			{
				ruta.ln(cmd.at(1),cmd.at(2));
			}
			if (cmd[0]=="rm")
			{
				ruta.rm(cmd.at(1));
			}
			if (cmd[0]=="exit")
			{
				done = true;
			}
		}
		catch (arbol_ficheros_error& e)
		{
			cerr << e.what() << endl;
		}
		catch (out_of_range& e)
		{
			cerr << e.what() << endl;
		}
	}
	cout << endl;

	return 0;
}
