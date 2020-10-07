#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

//view Ÿ��
typedef int viewType;
//ī�װ� Ÿ��
typedef int categoryType;
//���̵� Ÿ��
typedef int idType;
//Ÿ��Ʋ Ÿ��
typedef string titleType;

class CContent
{
private:
	idType m_nId;
	categoryType m_nCategory;
	titleType m_strTitle;
	viewType m_nViews;
public:
	//�⺻������
	CContent();
	//�Ű������� �ִ� ������
	CContent(idType m_nId, categoryType m_nCategory, titleType m_strTitle, viewType m_nViews);
	//get�Լ� , ī�װ� ����
	categoryType getCContent();
	//set�Լ�
	void setCContent(idType inputID, categoryType inputCategory, titleType inputTitle, viewType inputViews);
	//show �Լ�
	void showCContent();

	//������ �����ε�
	bool operator < (const CContent& other)const;
	bool operator > (const CContent& other)const;
	bool operator == (const CContent& other)const;
	
};

