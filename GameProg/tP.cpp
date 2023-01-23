#include "tP.h"
#include "SceneMgr.h"
#include "DxLib.h"

static int GameClear;    //�摜�n���h���i�[�p�ϐ�

//������
void tP_Initialize() {
    GameClear = LoadGraph("�摜/GameClear.png");    //�摜�̃��[�h
}

//�I������
void tP_Finalize() {
    DeleteGraph(GameClear);    //�摜�̉��
}

//�X�V
void tP_Update() {
    if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Esc�L�[��������Ă�����
        SceneMgr_ChangeScene(eScene_title);//�V�[�������j���[�ɕύX
    }
}

//�`
void tP_Draw() {
    DrawBox(0, 0, 640, 480, GetColor(0, 0, 255), TRUE);   // �l�p�`��`��(�h��Ԃ�)
    //SetFontSize(30);                             //�T�C�Y��64�ɕύX
    //SetFontThickness(8);                         //������8�ɕύX
    DrawString(310, 200, "2P", GetColor(255, 255, 255));
    DrawString(305, 250, "WIN", GetColor(255, 255, 255));

}