#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"



//������
void Menu_Initialize() {

}

//�I������
void Menu_Finalize() {


}

//�X�V
void Menu_Update() {

    if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Esc�L�[��������Ă�����
        SceneMgr_ChangeScene(eScene_title);//�V�[�������j���[�ɕύX
    }
    if (CheckHitKey(KEY_INPUT_G) != 0) { //Esc�L�[��������Ă�����
        SceneMgr_ChangeScene(eScene_Game);//�V�[�������j���[�ɕύX
    }

}
//�`��
void Menu_Draw() {

    DrawString(0, 0, "���j���[��ʂł��B�B", GetColor(255, 255, 255));
    DrawString(400, 460, "G �ŃQ�[�����n�܂�܂��B", GetColor(255, 255,255));


}