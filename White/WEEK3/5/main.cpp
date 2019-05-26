#include <iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class SortedStrings {
public:
  void AddString(const string& s) {
    vs.push_back(s);
  }

  vector<string> GetSortedStrings() {
    sort(begin(vs),end(vs));
    return vs;
  }

private:
  vector<string> vs;
};

void PrintSortedStrings(SortedStrings& strings) {
  for (const string& s : strings.GetSortedStrings()) {
    cout << s << " ";
  }
  cout << endl;
}

int main() {
  SortedStrings strings;

  strings.AddString("first");
  strings.AddString("third");
  strings.AddString("second");
  PrintSortedStrings(strings);

  strings.AddString("second");
  PrintSortedStrings(strings);

  return 0;
}
