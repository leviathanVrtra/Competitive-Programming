int digits[4];
int digits_c[10];
 
typedef struct {
	int strike;
	int ball;
} Result;
 
extern Result query(int guess[]);
 
void initialize(int arr[]) {
	for (int count = 0; count < 10; ++count) digits_c[count] = 0;
	for (int idx = 0; idx < 4; ++idx) {
		digits[idx] = arr[idx];
		digits_c[digits[idx]]++;
	}
}
 
bool isValid(int guess[]) {
	int guess_c[10];
 
	for (int count = 0; count < 10; ++count) guess_c[count] = 0;
	for (int idx = 0; idx < 4; ++idx) {
		if (guess[idx] < 0 || guess[idx] >= 10 || guess_c[guess[idx]] > 0) return false;
		guess_c[guess[idx]]++;
	}
	return true;
}
 
Result queryLcl(int guess[]) {
	Result result;
 
	if (!isValid(guess)) {
		result.strike = -1;
		result.ball = -1;
		return result;
	}
 
	result.strike = 0;
	result.ball = 0;
 
	for (int idx = 0; idx < 4; ++idx)
	if (guess[idx] == digits[idx])
		result.strike++;
	else if (digits_c[guess[idx]] > 0)
		result.ball++;
 
	return result;
}
 
void createArr(int arr[]) {
	int c, x;
	x = arr[3] + 1;
	arr[3] = x % 10;
	c = x / 10;
	for (int i = 2; i >= 0; i--) {
		x = arr[i] + c;
		arr[i] = x % 10;
		c = x / 10;
	}
}
 
void IgnoreNumber(int arr[], Result ret) {
	int brr[4];
	for (int i = 0; i < 4; i++) brr[i] = arr[i];
	createArr(brr);
	Result res = queryLcl(brr);
 
	while ((ret.strike != res.strike || ret.ball != res.ball || res.strike == -1 || res.ball == -1)) {
		createArr(brr);
		res = queryLcl(brr);
	}
	for (int i = 0; i < 4; i++) arr[i] = brr[i];
}
 
void doUserImplementation(int guess[]) {
	int arr[4] = { 0, 1, 2, 3 };
	int i = 0;
	while (i++ <= 9753) {
		initialize(arr);
		Result ret = query(arr);
		if (ret.strike == 4) {
			break;
		}
		IgnoreNumber(arr, ret);
	}
	for (int i = 0; i < 4; i++) guess[i] = arr[i];
}