#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

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
int main(int argc, char *argv[])
{
	unordered_set<string> dict;
	dict.insert("hot");
	dict.insert("dot");
	dict.insert("dog");
	dict.insert("lot");
	dict.insert("log");
	
	/*dict.insert("hot");
	dict.insert("dog");
	dict.insert("dot");*/
	cout<<ladderLength("hit", "cog", dict);
	//cout<<ladderLength("hot", "dog", dict);
	getchar(); 
   return 0;
}