//If you reverse the word "emirp" you will have the word "prime".
//That idea is related with the purpose of this kata: 
//we should select all the primes that when reversed are a different prime(so palindromic primes should be discarded).
//
//For example : 13, 17 are prime numbers and the reversed respectively 
//are 31, 71 which are also primes, so 13 and 17 are "emirps".But primes 757, 787, 797 
//are palindromic primes, meaning that the reversed number is the same as the original, 
//so they are not considered as "emirps" and should be discarded.
//
//The emirps sequence is registered in OEIS as A006567
//
//Your task
//Create a function that receives one argument n, as an upper limit, and the return the following array :
//
//	[number_of_emirps_below_n, largest_emirp_below_n, sum_of_emirps_below_n]
//
//Examples
//find_emirp(10)
//[0, 0, 0] ''' no emirps below 10 '''
//
//find_emirp(50)
//[4, 37, 98] ''' there are 4 emirps below 50: 13, 17, 31, 37; largest = 37; sum = 98 '''
//
//find_emirp(100)
//[8, 97, 418] ''' there are 8 emirps below 100: 13, 17, 31, 37, 71, 73, 79, 97; largest = 97; sum = 418 '''

#include<set>
#include <array>
#include <cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>

std::set<unsigned> primes;

std::array<int, 3> findEmirp(const int n) {
	int N = 1000000;
	std::vector<bool> a(N + 1, true);
	for (int i = 2; i * i < N + 1; i++) {
		if (a[i]) {
			for (int j = i * i; j < N + 1; j += i) {
				a[j] = false;
			}
		}
	}
	for (int i = 2; i < N; i++) {
		if (a[i]) primes.insert(i);
	}
	std::set<int> emirps;
	int sum = 0;
	for (int i = 2; i < n; i++) {
		if (primes.count(i) && !emirps.count(i)) {
			std::string str = std::to_string(i);
			std::string istr = str;
			std::reverse(str.begin(), str.end());
			if (str != istr && primes.count(std::stoi(str))) {
				emirps.insert(i);
				sum += i;
			}
		}
	}
	std::vector<int> vec(emirps.begin(), emirps.end());
	int size = vec.size();
	int largest = vec.empty() ? 0 : vec[vec.size() - 1];
	std::array<int, 3> arr{ size, largest, sum };
	return arr;
}