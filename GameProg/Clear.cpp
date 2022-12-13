#include "Clear.h"
#include "SceneMgr.h"
#include "DxLib.h"

static int GameClear;    //�摜�n���h���i�[�p�ϐ�

//������
void Clear_Initialize() {
    GameClear = LoadGraph("�摜/GameClear.png");    //�摜�̃��[�h
}

//�I������
void Clear_Finalize() {
    DeleteGraph(GameClear);    //�摜�̉��
}

//�X�V
void Clear_Update() {
    if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Esc�L�[��������Ă�����
        SceneMgr_ChangeScene(eScene_title);//�V�[�������j���[�ɕύX
    }
}

//�`��
void Clear_Draw() {
    DrawString(0, 20, "Esc �^�C�g��", GetColor(255, 255, 255));
    DrawString(0, 0, "�N���A��ʂł�", GetColor(255, 255, 255));

}