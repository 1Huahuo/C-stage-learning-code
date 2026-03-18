#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_BOOKS 10

/*
请定义一个Book书籍结构体类型来存储一本书的信息，以及Genre这个书籍类别枚举类型。

现在给定你一个Book结构体对象数组的数据，一共十本书：
#define MAX_BOOKS 10
Book books[MAX_BOOKS] = {
	{1, "三体", "刘慈欣", SCIENCE_FICTION},
	{2, "红楼梦", "曹雪芹", LITERATURE},
	{3, "中国通史", "吕思勉", HISTORY},
	{4, "时间简史", "史蒂芬·霍金", TECHNOLOGY},
	{5, "围城", "钱钟书", LITERATURE},
	{6, "傲慢与偏见", "简·奥斯汀", LITERATURE},
	{7, "呼啸山庄", "艾米莉·勃朗特", LITERATURE},
	{8, "活着", "余华", LITERATURE},
	{9, "明朝那些事儿", "当年明月", HISTORY},
	{10, "乌合之众", "古斯塔夫·勒庞", OTHER}
};
请实现以下功能：
1.程序启动，即打印所有书籍的信息。
2.根据用户输入的书籍类别编号，查找并输出该类别的所有书籍信息。
*/

//书籍类别的枚举类型包含以下类别：
//科幻（SCIENCE_FICTION）
//文学（LITERATURE）
//历史（HISTORY）
//科技（TECHNOLOGY）
//其他（OTHER）
typedef enum Genre {
	SCIENCE_FICTION = 1,
	LITERATURE,
	HISTORY,
	TECHNOLOGY,
	OTHER
}Genre; // 即Genre = enum Genre

// 字符二维数组
char Genre_trans[5][5] = { "科幻", "文学", "历史", "科技", "其他" };
// 或者采用：
// 将书籍类别的枚举值转换成中文表示的类别
const char* get_genre_name(Genre genre) {
	switch (genre) {
	case SCIENCE_FICTION: return "科幻";
	case LITERATURE: return "文学";
	case HISTORY: return "历史";
	case TECHNOLOGY: return "科技";
	case OTHER: return "其他";
	default: return "未知";
	}
}

//编写一个程序，管理图书馆中的书籍信息。每本书籍的信息包含以下内容：
//书籍编号（整型）
//书籍名称（字符串）
//书籍作者（字符串）
//书籍类别（枚举类型）
typedef struct book_info {
	int num;
	char name[20];
	char author[20];
	enum Genre class; // 本质int
}Book; // 48个字节

// 1.程序启动，即打印所有书籍的信息。
void library_program_open(Book books[MAX_BOOKS]) {
	for (int i = 0; i < MAX_BOOKS; i++) {
		printf("编号：%d，书名：%s，作者：%s，类别：%s\n",
			books[i].num, books[i].name, books[i].author, Genre_trans[books[i].class - 1]);
	} // Genre从1开始      Genre_trans 从0,开始
}

// 2.根据用户输入的书籍类别编号，查找并输出该类别的所有书籍信息。
void library_find_class_genre(Book books[MAX_BOOKS], int genre) {
	printf("类别为 %s 的书籍有：\n", Genre_trans[genre]);
	for (int i = 0; i < MAX_BOOKS; i++)
		if (books[i].class == genre + 1)
			printf("编号：%d，书名：%s，作者：%s\n",
				books[i].num, books[i].name, books[i].author);
}

// 一个中文占两个char型空间
int main(void) {
	//char str[8 + 1] = "时间简史";
	//printf("%s\n", str);
	//enum Genre a = OTHER;
	//printf("%d\n", sizeof(a));

	Book books[MAX_BOOKS] = {
	{1, "三体", "刘慈欣", SCIENCE_FICTION},
	{2, "红楼梦", "曹雪芹", LITERATURE},
	{3, "中国通史", "吕思勉", HISTORY},
	{4, "时间简史", "史蒂芬·霍金", TECHNOLOGY},
	{5, "围城", "钱钟书", LITERATURE},
	{6, "傲慢与偏见", "简·奥斯汀", LITERATURE},
	{7, "呼啸山庄", "艾米莉·勃朗特", LITERATURE},
	{8, "活着", "余华", LITERATURE},
	{9, "明朝那些事儿", "当年明月", HISTORY},
	{10, "乌合之众", "古斯塔夫·勒庞", OTHER}
	};

	// program open
	library_program_open(books);

	int genre_num = 0;
	printf("\n请输入书籍类别编号（0：科幻，1：文学，2：历史，3：科技，4：其他）：");
	scanf("%d", &genre_num);
	library_find_class_genre(books, genre_num);

	return 0;
}