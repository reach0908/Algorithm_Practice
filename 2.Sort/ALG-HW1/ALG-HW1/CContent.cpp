#include "CContent.h"

CContent::CContent()
	:m_nId(-1), m_nCategory(-1), m_strTitle(""), m_nViews(0) {}

CContent::CContent(idType inputID, categoryType inputCategory, titleType inputTitle, viewType inputViews)
	:m_nId(inputID), m_nCategory(inputCategory), m_strTitle(inputTitle), m_nViews(inputViews) {}

categoryType CContent::getCContent() {
	return this->m_nCategory;
};

void CContent::setCContent(idType inputID, categoryType inputCategory, titleType inputTitle, viewType inputViews) {
	this->m_nId = inputID;
	this->m_nCategory = inputCategory;
	this->m_strTitle = inputTitle;
	this->m_nViews = inputViews;
}
//selsort , 연산자 오버로딩 이용

//show 함수
void CContent::showCContent() {
	cout << "Title :" << this->m_strTitle << " " << "Views :" << this->m_nViews << endl;
}
bool CContent::operator < (const CContent& other)const {
	return this->m_nViews < other.m_nViews;
}
bool CContent::operator > (const CContent& other)const {
	return this->m_nViews > other.m_nViews;
}
bool CContent::operator == (const CContent& other)const {
	return this->m_nViews == other.m_nViews;
}