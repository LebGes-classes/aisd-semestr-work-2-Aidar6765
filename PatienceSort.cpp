#include <vector>
#include <iostream>

using namespace std;

void patienceSort(vector<int>& array) {
	vector<vector<int>> stacks;
	
	for (int i = 0; i < array.size(); i++) {
		bool flag = false;
		int j = 0;
		while (j < stacks.size() && flag == false) {
			if (array[i] <= stacks[j][stacks[j].size() - 1]) {
				stacks[j].push_back(array[i]);
				flag = true;
			}
			j = j + 1;
		}
		
		if (flag == false) {
			std::vector<int> v1;
			v1.push_back(array[i]);
			stacks.push_back(v1);
		
		}

	}


	for (int i = 0; i < array.size(); i++) {
		
		int min = INT_MAX;
		int deleteStack = 0;
		for (int j = 0; j < stacks.size(); j++) {
			if (stacks[j][stacks[j].size() - 1] < min) {
				min = stacks[j][stacks[j].size() - 1];
				deleteStack = j;
			}
		}
		array[i] = min;
		stacks[deleteStack].pop_back();
		if (stacks[deleteStack].empty()) {
			stacks.erase(stacks.begin() + deleteStack);
		}
		
		
	}
}


int main() {
	std::vector<int> v1 = {10,23,12,5,6,2,11,23,75,53,76,27,45,3, 4,4, 23, 54,6, 100};
	patienceSort(v1);
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << " ";
	}
	


}
