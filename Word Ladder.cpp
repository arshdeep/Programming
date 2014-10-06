#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <unordered_set>
using namespace std;

/*Approach 1 : DFS with queue*/
int ladderLength(string start, string end, unordered_set<string> &dict) {
	if (dict.size() == 0) return 0;
    
	queue<string> frontQueue;
	queue<int> backQueue;
    
	frontQueue.push(start);
	backQueue.push(1);
    
	while(!frontQueue.empty())
	{
		string str = frontQueue.front();
		frontQueue.pop();
		int len = backQueue.front();
		backQueue.pop();
		if (str.compare(end) == 0) return len;
		for (int i = 0; i < str.length(); ++i)
		{
			for (char j = 'a'; j <= 'z'; ++j)
			{
				string temp = str;
				temp[i] = j;
				if (temp.compare(end) == 0) return len+1;
                
				if (dict.find(temp) != dict.end())
				{
					backQueue.push(len+1);
					frontQueue.push(temp);
					dict.erase(dict.find(temp));
				}
			}
		}
	}
	return 0;
}

vector<string> getPossibleStrings(string str, unordered_set<string> &dict)
{
	int len = str.length();
	vector<string> vect;
	for (int i = 0; i < len; ++i)
	{
		string temp = str;
		for (char j = 'a'; j <= 'z'; ++j)
		{
			string temp = str;
			temp[i] = j;
            
			if (temp.compare(str) != 0 && dict.find(temp) != dict.end())
			{
				vect.push_back(temp);
			}
		}
	}
	return vect;
}

int ladderLength2(string start, string end, unordered_set<string> &dict) {
	if (dict.size() == 0) return 0;
	if (start.compare(end) == 0) return 1;
	struct node
	{
		string value;
		int level;
		node(string str, int l) {value = str; level = l;}
	};
	queue<node> startQueue;
	queue<node> endQueue;
	map<string, bool> startMap;
	startMap[start] = true;
    
	map<string, int> endMap;
	endMap[end] = true;
    
	int sLevel = 1, rLevel = 1;
	node temp = node(start, 1);
	startQueue.push(temp);
	temp = node(end, 1);
	endQueue.push(temp);
    
	while (!startQueue.empty() && !endQueue.empty())
	{
		if (startQueue.size() < endQueue.size())
		{
	            while (!startQueue.empty() && sLevel == startQueue.front().level) {
	                node temp = startQueue.front();
	                vector<string> vect = getPossibleStrings(temp.value, dict);
	                for (auto id = vect.begin(); id != vect.end(); ++id)
	                {
	                    if (!startMap[*id])
	                    {
	                        startMap[*id] = true;
	                        if (endMap.find(*id) != endMap.end()) {
	                            return startQueue.front().level + endQueue.back().level;
	                        }
	                        temp = node(*id, sLevel + 1);
	                        startQueue.push(temp);
	                    }
	                }
	                startQueue.pop();
	            }
	            sLevel++;
		}
		else
		{
	            while (!endQueue.empty() && rLevel == endQueue.front().level) {
	                node temp = endQueue.front();
	                vector<string> vect = getPossibleStrings(temp.value, dict);
	                for (auto id = vect.begin(); id != vect.end(); ++id)
	                {
	                    if (!endMap[*id])
	                    {
	                        endMap[*id] = true;
	                        if (startMap.find(*id) != startMap.end()) {
	                            return startQueue.back().level + endQueue.front().level;
	                        }
	                        temp = node(*id, rLevel + 1);
	                        endQueue.push(temp);
	                    }
	                }
	                endQueue.pop();
	            }
	            rLevel++;
		}
	}
	return 0;
}
int main(int argc, char *argv[])
{
	unordered_set<string> dict;
	dict.insert("hot");
	dict.insert("dot");
	dict.insert("dog");
	dict.insert("lot");
	dict.insert("log");
	cout<<ladderLength2("hit", "cog", dict)<<endl;
	dict.empty();
	dict.insert("hot");
	dict.insert("dog");
	dict.insert("dot");
	//"kiss", "tusk", ["miss","dusk","kiss","musk","tusk","diss","disk","sang","ties","muss"]
	
	cout<<ladderLength2("hot", "dog", dict)<<endl;
	dict.empty();
	dict.insert("misss");
	dict.insert("dusk");
	dict.insert("kiss");
	dict.insert("musk");
	dict.insert("tusk");
	dict.insert("diss");
	dict.insert("disk");
	dict.insert("sang");
	dict.insert("ties");
	dict.insert("muss");
	cout<<ladderLength2("kiss", "tusk", dict)<<endl;
	cout<<ladderLength("kiss", "tusk", dict)<<endl;
	dict.empty();
    
	/*dict.insert("a");
	dict.insert("b");
	dict.insert("c");
	cout<<ladderLength2("a", "c", dict);
	dict.empty();
    */
	getchar(); 
    return 0;
}
