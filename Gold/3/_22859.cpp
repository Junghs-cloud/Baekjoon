#include <iostream>
#include <regex>
#include <string>
using namespace std;
string titlePrefix = "div title=\"";

string getTitle(string str)
{
	string title = str.erase(0, titlePrefix.length() + 1);
	title = title.substr(0, title.length() - 2);
	return title;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	getline(cin, str);
	regex divRegex("<div title=\"[a-zA-Z0-9_ ]+\">");
	regex pRegex("<p>");
	regex tagRegex("<[a-zA-Z0-9 ]+>|</[a-zA-Z0-9 ]+>");
	regex blank("[ ]+");
	std::smatch divMatch;
	std::smatch pMatch;
	while (std::regex_search(str, divMatch, divRegex))
	{
		string title = getTitle(divMatch.str());
		cout << "title : " << title << "\n";
		str = divMatch.suffix();
		int index = str.find("</div>");
		string div = str.substr(0, index);
		while (std::regex_search(div, pMatch, pRegex))
		{
			int pIndex = div.find("</p>");
			string pStr = div.substr(0, pIndex);
			string noTagStr = regex_replace(pStr, tagRegex, "");
			string removeBlank = regex_replace(noTagStr, blank, " ");
			cout << removeBlank << "\n";
			div = div.erase(0, pStr.length()+4);
		}
	}
	return 0;
}