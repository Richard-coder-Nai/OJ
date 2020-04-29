#include <iostream>

using namespace std;

int nums1[100005];
int nums2[100005];

int main(void) {
	int n1, n2, target;
	cin>>n1>>n2>>target;
	for(int i=0; i<n1; i++) scanf("%d", &nums1[i]);
	for(int i=0; i<n2; i++) scanf("%d", &nums2[i]);

	for(int i=0; i<n1; i++) {
		int j = n2-1;
		while(j>=0 && target<=nums1[i]+nums2[j]) {
			if(target==nums1[i]+nums2[j]) {
				cout<<i<<" "<<j<<endl;
				return 0;
			}
			j--;
		}
	}
}
