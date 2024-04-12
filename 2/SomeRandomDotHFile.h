#pragma once
#include "Score.h"
void print(const Score& obj) {
	cout << "score : " << obj.score << " Label :  " << obj.label << " detail : " << obj.detail << " ID : " << obj.ID << endl;
}