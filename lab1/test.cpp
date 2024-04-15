#include "pch.h"
#include "C:\Users\DELL\Desktop\algds2024-main\lab1\дин прогр\дин прогр\Header.h"

TEST(Test, Test1) {

	int n = 10;
	int k = 1;
	int** dp = (int**)malloc((n + 1) * sizeof(int*));
	for (int i = 0; i < n + 1; i++) {
		dp[i] = (int*)malloc((k + 1) * sizeof(int));
	}
	ASSERT_EQ((countNumbers(n, k, dp)), 10);
}


TEST(Test, Test2) {

	int n = 0;
	int k = 1;
	int** dp = (int**)malloc((n + 1) * sizeof(int*));
	for (int i = 0; i < n + 1; i++) {
		dp[i] = (int*)malloc((k + 1) * sizeof(int));
	}
	ASSERT_EQ((countNumbers(n, k, dp)), 0);
}

TEST(Test, Test3) {

	int n = 100;
	int k = 1;
	int** dp = (int**)malloc((n + 1) * sizeof(int*));
	for (int i = 0; i < n + 1; i++) {
		dp[i] = (int*)malloc((k + 1) * sizeof(int));
	}
	ASSERT_EQ((countNumbers(n, k, dp)), 100);
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}