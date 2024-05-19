#include "pch.h"
#include "C:\Users\DELL\Desktop\algds2024-main\7\lab 2\Header.h"

TEST(insert, Test1) {

	Node *root = NULL;
	insert(&root, 2, 30);
	insert(&root, 1, 20);
	insert(&root, 3, 10);
	
	char testStr[STRING_LENGTH] = "";
	getStrRepr(root, testStr);

	EXPECT_STREQ("(2,30,(1,20,-,-),(3,10,-,-))", testStr);

}

TEST(splitRoot, Test2) {

	Node* root = NULL;
	insert(&root, 5, 10);
	insert(&root, 2, 20);
	insert(&root, 8, 15);

	Node* right = NULL; Node* left = NULL;
	split(root, 5, &left, &right);

	char testStr1[STRING_LENGTH] = "";
	getStrRepr(right, testStr1);
	EXPECT_STREQ("(8,15,-,-)", testStr1);

	char testStr2[STRING_LENGTH] = "";
	getStrRepr(left, testStr2);
	EXPECT_STREQ("(2,20,-,(5,10,-,-))", testStr2);

}

TEST(mergeNoLeft, Test3) {

	Node* rootR = NULL;
	insert(&rootR, 2, 30);
	insert(&rootR, 1, 20);
	insert(&rootR, 3, 10);

	Node* rootL = NULL;
	Node* root = NULL;

	char testStr[STRING_LENGTH] = "";

	root = merge(rootL, rootR);
	getStrRepr(root, testStr);

	EXPECT_STREQ("(2,30,(1,20,-,-),(3,10,-,-))", testStr);

}

TEST(mergeNoRight, Test4) {

	Node* rootL = NULL;
	insert(&rootL, 2, 30);
	insert(&rootL, 1, 20);
	insert(&rootL, 3, 10);

	Node* rootR = NULL;
	Node* root = NULL;

	char testStr[STRING_LENGTH] = "";

	root = merge(rootL, rootR);
	getStrRepr(root, testStr);

	EXPECT_STREQ("(2,30,(1,20,-,-),(3,10,-,-))", testStr);
}

TEST(merge, Test5) {
	Node* rootL = NULL;
	insert(&rootL, 2, 2);
	insert(&rootL, 1, 1);

	Node* rootR = NULL;
	insert(&rootR, 6, 10);
	insert(&rootR, 5, 20);

	Node* root = NULL;
	root = merge(rootL, rootR);

	char testStr[STRING_LENGTH] = "";
	getStrRepr(root, testStr);

	EXPECT_STREQ("(2,2,(1,1,-,-),(5,20,-,(6,10,-,-)))", testStr);

}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}