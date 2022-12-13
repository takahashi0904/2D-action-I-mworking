#include "Over.h"
#include "SceneMgr.h"
#include "DxLib.h"


static int GameOver;    //�摜�n���h���i�[�p�ϐ�


//������
void Over_Initialize() {

    GameOver = LoadGraph("�摜/GameOver.png");    //�摜�̃��[�h
}

//�I������
void Over_Finalize() {

    DeleteGraph(GameOver);    //�摜�̉��

}

//�X�V
void Over_Update() {

    if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Esc�L�[��������Ă�����
        SceneMgr_ChangeScene(eScene_title);//�V�[�������j���[�ɕύX
    }
}

//�`��
void Over_Draw() {
    DrawString(0, 20, "�Q�[���I�[�o�[��ʂł��B", GetColor(255, 255, 255));
    DrawString(0, 40, "Esc �^�C�g��", GetColor(255, 255, 255));

}