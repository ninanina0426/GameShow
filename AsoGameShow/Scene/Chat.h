#pragma once


class Chat
{
public:
	bool init(void);		//������
	bool Update(void);		//�X�V
	void Draw(void);		//�`��
	bool Release(void);		//�J��

	bool IsEnd;
private:
	int mImage[18];
	
	int mCnt;
	int x;
	
	
};

