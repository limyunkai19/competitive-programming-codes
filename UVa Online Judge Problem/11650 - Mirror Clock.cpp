#include <iostream>
using namespace std;

int main() {
	int t, hour, minute;
	char x, y;
	cin >> t;
	while(t--){
		cin >> x >> y;
		hour = 10*(x-'0') + (y-'0');
		cin >> x;
		cin >> x >> y;
		minute = 10*(x-'0') + (y-'0');
		if(minute == 0){
			if(hour == 12){
				cout << "12:00" << endl;
				continue;
			}
			hour = 12-hour;
			cout << (char)(hour/10 + '0') << (char)(hour%10 + '0') << ":00" << endl;
		}
		else{
			if(hour == 12){
				hour = 11;
			}
			else if(hour == 11){
				hour = 12;
			}
			else{
				hour = 12-hour-1;
			}
			minute = 60-minute;
			cout << (char)(hour/10 + '0') << (char)(hour%10 + '0') << ':'
				<< (char)(minute/10 + '0') << (char)(minute%10 + '0') << endl;
		}
		
	}
	return 0;
}