#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

//view 타입
typedef int viewType;
//카테고리 타입
typedef int categoryType;
//아이디 타입
typedef int idType;
//타이틀 타입
typedef string titleType;

class CContent
{
private:
	idType m_nId;
	categoryType m_nCategory;
	titleType m_strTitle;
	viewType m_nViews;
public:
	//기본생성자
	CContent();
	//매개변수가 있는 생성자
	CContent(idType m_nId, categoryType m_nCategory, titleType m_strTitle, viewType m_nViews);
	//get함수 , 카테고리 리턴
	categoryType getCContent();
	//set함수
	void setCContent(idType inputID, categoryType inputCategory, titleType inputTitle, viewType inputViews);
	//show 함수
	void showCContent();

	//연산자 오버로딩
	bool operator < (const CContent& other)const;
	bool operator > (const CContent& other)const;
	bool operator == (const CContent& other)const;
	
};

