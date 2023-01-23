#include "oP.h"
#include "SceneMgr.h"
#include "DxLib.h"


static int GameOver;    //�摜�n���h���i�[�p�ϐ�


//������
void oP_Initialize() {

    GameOver = LoadGraph("�摜/GameOver.png");    //�摜�̃��[�h
}

//�I������
void oP_Finalize() {

    DeleteGraph(GameOver);    //�摜�̉��

}

//�X�V
void oP_Update() {

    if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Esc�L�[��������Ă�����
        SceneMgr_ChangeScene(eScene_title);//�V�[�������j���[�ɕύX
    }
}

//�`��
void oP_Draw() {
    DrawBox(0, 0, 640, 480, GetColor(255, 0, 0), TRUE);   // �l�p�`��`��(�h��Ԃ�)
    //SetFontSize(30);                             //�T�C�Y��64�ɕύX
    //SetFontThickness(8);                         //������8�ɕύX
    DrawString(310, 200, "1P", GetColor(255, 255, 255));
    DrawString(305, 250, "WIN", GetColor(255, 255, 255));

}