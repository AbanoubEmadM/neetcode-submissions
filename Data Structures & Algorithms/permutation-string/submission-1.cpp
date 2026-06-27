class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		unordered_map<char, int> main, sec;
		int l = 0, r = s1.size() - 1;
		int n = s2.size() - 1;

		for (int i = 0; i <= r; i++){
			main[s1[i]]++;
			if (s1.find(s2[i]) != string::npos) sec[s2[i]]++;
		}

		while (r < n + 1) {
			if (main == sec) return true;
			if (s1.find(s2[l]) != string::npos) sec[s2[l]]--;
			l++;
			r++;
			if (s1.find(s2[r]) != string::npos) sec[s2[r]]++;
			
		}
		return false;
	}
};
